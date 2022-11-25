package RVnpc.RVNoob.Cache

import RVnpc.RVNoob.{DpiPmem, RVNoobConfig}
import chisel3._
import chisel3.util._
import scala.math.pow

class DCache(
  val addrWidth:     Int = 32,
  val cacheSize:     Int = 4 * pow(2, 10).toInt,
  val cacheLineSize: Int = 32,
  val ways:          Int = 4,
  val axiDataWidth:  Int = 64,
  val missDelay:     Int = 4)
    extends Module
    with RVNoobConfig {

  //
  val cacheLineNum:   Int = cacheSize / cacheLineSize // 128
  val sets:           Int = cacheLineNum / ways // 32
  val wordNumPerLine: Int = cacheLineSize / (inst_w / 8) // 8
  // Width
  val byteOffsetWidth: Int = 2
  //  println(s"ways = $ways")
  //  println(s"cacheSize = $cacheSize")
  //  println(s"cacheLineNum = $cacheLineNum")
  val wordOffsetWidth: Int = log2Ceil(wordNumPerLine) // 3
  val indexWidth:      Int = log2Ceil(sets) //log2Ceil(sets) //5
  val tagWidth:        Int = addrWidth - indexWidth - wordOffsetWidth - byteOffsetWidth // 22
  val io = IO(new Bundle {
    val addr       = Input(UInt(addrWidth.W))
    val wdata      = Input(UInt(xlen.W))
    val ren        = Input(Bool())
    val wen        = Input(Bool())
    val zero_ex_op = Input(UInt(2.W))
    val valid      = Input(Bool())

    val miss  = Output(Bool())
    val rdata = Output(UInt(xlen.W))
  })
  //  println(s"sets = $sets")
  // 主要mem
  val tag_arrays = Reg(Vec(ways, Vec(sets, new TagArrays(tagWidth))))
  val data_arrays = Reg(Vec(ways, Vec(sets, Vec(wordNumPerLine, UInt(32.W)))))
  // mmio 控制信号
  val inpmem = (io.addr >= 0x80000000L.U) && (io.addr < 0x88000000L.U)
  //  dontTouch(tag_arrays)
  //  dontTouch(data_arrays)
  //    when(reset.asBool()){
  //      for (i <- 0 until ways){
  //        for(j <- 0 until sets){
  //        }
  //      }
  //    }
  val mmio_read  = !inpmem && io.ren
  val mmio_write = !inpmem && io.wen
  // 地址分段
  val addr_tag   = io.addr(addrWidth - 1, addrWidth - tagWidth)
  val addr_index = io.addr(addrWidth - tagWidth - 1, addrWidth - tagWidth - indexWidth)
  val addr_wordoffset =
    io.addr(addrWidth - tagWidth - indexWidth - 1, addrWidth - tagWidth - indexWidth - wordOffsetWidth)
  val addr_byteoffset = io.addr(byteOffsetWidth - 1, 0)
  // 命中信号
  val hit     = Wire(Vec(ways, Bool()))
  val hit_way = OHToUInt(hit)
  //  dontTouch(hit)
  hit := 0.B.asTypeOf(hit)
  when(io.ren || io.wen) {
    for (w <- 0 until ways) {
      hit(w) := (tag_arrays(w)(addr_index).tag === addr_tag) && tag_arrays(w)(addr_index).valid
    }
  }
  // 缺失信号与缺失周期计数
  val miss           = Wire(Bool())
  val miss_delay_cnt = RegInit(0.U(log2Ceil(missDelay).W))
  miss    := hit.asUInt() === 0.U && (io.ren || io.wen) && inpmem
  io.miss := miss
  // dpi_pmem 控制信号
  // read solution : read miss; write miss; mmio read
  val pmem_raddr = Wire(UInt(addrWidth.W))
  when(miss) {
    when(miss_delay_cnt === (missDelay - 1).U) {
      miss_delay_cnt := 0.U
    }.otherwise {
      miss_delay_cnt := miss_delay_cnt + 1.U
    }
  }
  val pmem_rdata = Wire(UInt(xlen.W))
  // write solution : replace dirty; mmio write
  // 替换算法 最早输入数据被替换
  val waysWidth = log2Ceil(ways)
  when(mmio_read) {
    pmem_raddr := io.addr & (~0x7.U(addrWidth.W)).asUInt()
  }.otherwise {
    pmem_raddr := Cat(addr_tag, addr_index, miss_delay_cnt(1, 0), 0.U((byteOffsetWidth + 1).W))
  }
  val replace_way   = Reg(Vec(sets, UInt(waysWidth.W)))
  val replace_dirty = tag_arrays(replace_way(addr_index))(addr_index).dirty_bit && miss
  // data and tag replace
  val wordNumPerBurst = axiDataWidth / 32
  //  val replace_way     = RegInit(VecInit(Seq.fill(sets)(0.U(waysWidth.W))))
  when(reset.asBool()) {
    for (i <- 0 until sets) {
      replace_way(i) := 0.U
    }
  }
  // write pmem
  val shift = Wire(UInt(3.W))
  when(miss) {
    for (i <- 0 until wordNumPerBurst) {
      data_arrays(replace_way(addr_index))(addr_index)(
        miss_delay_cnt * wordNumPerBurst.U + i.U
      ) := pmem_rdata(i * 32 + 31, i * 32)
    }
    when(miss_delay_cnt === (missDelay - 1).U) {
      tag_arrays(replace_way(addr_index))(addr_index).valid     := 1.B
      tag_arrays(replace_way(addr_index))(addr_index).tag       := addr_tag
      tag_arrays(replace_way(addr_index))(addr_index).dirty_bit := 0.B

      replace_way(addr_index) := replace_way(addr_index) + 1.U
    }
  }
  val pmem_waddr = Wire(UInt(addrWidth.W))
  val pmem_wdata = Wire(UInt(xlen.W))
  val pmem_wmask = Wire(UInt(8.W))
  val dpi_pmem   = Module(new DpiPmem)
  when(mmio_write && io.valid) {
    pmem_waddr := io.addr & (~0x7.U(addrWidth.W)).asUInt()
    shift      := io.addr
    pmem_wdata := (io.wdata << (shift * 8.U))
    pmem_wmask := MuxCase(
      "b11111111".U,
      Array(
        (io.zero_ex_op === 3.U) -> "b11111111".U, // write double word
        (io.zero_ex_op === 2.U) -> ("b1111".U << shift), // write word
        (io.zero_ex_op === 1.U) -> ("b11".U << shift), // write half word
        (io.zero_ex_op === 0.U) -> ("b1".U << shift) // write byte
      )
    )
  }.otherwise {
    pmem_waddr := Cat(
      tag_arrays(replace_way(addr_index))(addr_index).tag,
      addr_index,
      miss_delay_cnt(1, 0),
      0.U((byteOffsetWidth + 1).W)
    )
    shift := 0.U
    pmem_wdata := Cat(
      data_arrays(replace_way(addr_index))(addr_index)(miss_delay_cnt * wordNumPerBurst.U + 1.U),
      data_arrays(replace_way(addr_index))(addr_index)(miss_delay_cnt * wordNumPerBurst.U)
    )
    pmem_wmask := "b11111111".U
  }

  dpi_pmem.io.clk    <> clock
  dpi_pmem.io.raddr  <> pmem_raddr
  dpi_pmem.io.waddr  <> pmem_waddr
  dpi_pmem.io.wmask  <> pmem_wmask
  dpi_pmem.io.rdata  <> pmem_rdata
  dpi_pmem.io.wdata  <> pmem_wdata
  dpi_pmem.io.r_pmem <> (miss || mmio_read)
  dpi_pmem.io.w_pmem <> ((mmio_write && io.valid) || replace_dirty)

  // hit read
  when(inpmem) {
    //    io.rdata := (rdata >> (shift * 8.U))
    io.rdata := data_arrays(hit_way)(addr_index)(addr_wordoffset)
  }.otherwise {
    io.rdata := pmem_rdata
  }
  // hit write
  when(!miss && io.wen) {
    val data_temp = Wire(Vec(4, UInt()))
    for (i <- 0 to 3) {
      data_temp(i) := data_arrays(hit_way)(addr_index)(addr_wordoffset)(i * 8 + 7, i * 8)
    }
    when(io.zero_ex_op === 3.U) {
      data_arrays(hit_way)(addr_index)(addr_wordoffset)       := io.wdata(31, 0)
      data_arrays(hit_way)(addr_index)(addr_wordoffset + 1.U) := io.wdata(63, 32)
    }.elsewhen(io.zero_ex_op === 2.U) {
      data_arrays(hit_way)(addr_index)(addr_wordoffset) := io.wdata(31, 0)
    }.elsewhen(io.zero_ex_op === 1.U) {
      data_temp(addr_byteoffset)                        := io.wdata(7, 0)
      data_temp(addr_byteoffset + 1.U)                  := io.wdata(15, 8)
      data_arrays(hit_way)(addr_index)(addr_wordoffset) := Cat(data_temp(3), data_temp(2), data_temp(1), data_temp(0))
    }.otherwise {
      data_temp(addr_byteoffset)                        := io.wdata(7, 0)
      data_arrays(hit_way)(addr_index)(addr_wordoffset) := Cat(data_temp(3), data_temp(2), data_temp(1), data_temp(0))
    }
    tag_arrays(hit_way)(addr_index).dirty_bit := 1.B
  }

}

object DCacheGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/test"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new DCache()))
    )
}
