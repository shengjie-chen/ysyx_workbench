package RVnpc.RVNoob.Cache

import RVnpc.RVNoob.{DpiPmem, RVNoobConfig}
import chisel3._
import chisel3.util._
import scala.math.pow

class TagArrays(tagWidth: Int) extends Bundle {
  val dirty_bit = Bool()
  val valid     = Bool()
  val tag       = UInt(tagWidth.W)
}

class ICache(
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
  //  println(s"ways = $ways")
  //  println(s"cacheSize = $cacheSize")
  //  println(s"cacheLineNum = $cacheLineNum")

  // Width
  val byteOffsetWidth: Int = 2
  val wordOffsetWidth: Int = log2Ceil(wordNumPerLine) // 3
  val indexWidth:      Int = log2Ceil(sets) //log2Ceil(sets) //5
  val tagWidth:        Int = addrWidth - indexWidth - wordOffsetWidth - byteOffsetWidth // 22
  //  println(s"sets = $sets")

  val io = IO(new Bundle {
    val inst_addr = Input(UInt(addrWidth.W))
    val inst_ren  = Input(Bool())
    val miss      = Output(Bool())
    val inst_data = Output(UInt(inst_w.W))
  })
  assert(!io.inst_ren || (io.inst_addr >= 0x80000000L.U) && (io.inst_addr < 0x88000000L.U))

  val tag_arrays  = Reg(Vec(ways, Vec(sets, new TagArrays(tagWidth))))
  val data_arrays = Reg(Vec(ways, Vec(sets, Vec(wordNumPerLine, UInt(32.W)))))
//  dontTouch(tag_arrays)
//  dontTouch(data_arrays)

  //  when(reset.asBool()){
  //    for (i <- 0 to ways)
  //
  //  }

  val inst_addr_tag   = io.inst_addr(addrWidth - 1, addrWidth - tagWidth)
  val inst_addr_index = io.inst_addr(addrWidth - tagWidth - 1, addrWidth - tagWidth - indexWidth)
  val inst_addr_wordoffset =
    io.inst_addr(addrWidth - tagWidth - indexWidth - 1, addrWidth - tagWidth - indexWidth - wordOffsetWidth)

  val hit = Wire(Vec(ways, Bool()))
//  dontTouch(hit)
  hit := 0.B.asTypeOf(hit)
  when(io.inst_ren) {
    for (w <- 0 until ways) {
      hit(w) := (tag_arrays(w)(inst_addr_index).tag === inst_addr_tag) && tag_arrays(w)(inst_addr_index).valid
    }
  }
  val hit_way = OHToUInt(hit)
  io.inst_data := data_arrays(hit_way)(inst_addr_index)(inst_addr_wordoffset)

  val miss = Wire(Bool())
  miss    := hit.asUInt() === 0.U && io.inst_ren
  io.miss := miss
  val miss_delay_cnt = RegInit(0.U(log2Ceil(missDelay).W))
  when(miss) {
    when(miss_delay_cnt === (missDelay - 1).U) {
      miss_delay_cnt := 0.U
    }.otherwise {
      miss_delay_cnt := miss_delay_cnt + 1.U
    }
  }
  val pmem_raddr = Wire(UInt(addrWidth.W))
  val pmem_rdata = Wire(UInt(xlen.W))

  pmem_raddr := Cat(inst_addr_tag, inst_addr_index, miss_delay_cnt(1, 0), 0.U((byteOffsetWidth + 1).W))
  val dpi_pmem = Module(new DpiPmem)
  dpi_pmem.io.clk    <> clock
  dpi_pmem.io.raddr  <> pmem_raddr
  dpi_pmem.io.waddr  <> 0.U
  dpi_pmem.io.wmask  <> 0.U
  dpi_pmem.io.rdata  <> pmem_rdata
  dpi_pmem.io.wdata  <> 0.U
  dpi_pmem.io.r_pmem <> miss
  dpi_pmem.io.w_pmem <> 0.B

  // 替换算法 最早输入数据被替换
  val waysWidth   = log2Ceil(ways)
  val replace_way = Reg(Vec(sets, UInt(waysWidth.W)))
//  val replace_way     = RegInit(VecInit(Seq.fill(sets)(0.U(waysWidth.W))))
  when(reset.asBool()) {
    for (i <- 0 until sets) {
      replace_way(i) := 0.U
    }
  }
  val wordNumPerBurst = axiDataWidth / 32
  when(miss) {
    for (i <- 0 until wordNumPerBurst) {
      data_arrays(replace_way(inst_addr_index))(inst_addr_index)(
        miss_delay_cnt * wordNumPerBurst.U + i.U
      ) := pmem_rdata(i * 32 + 31, i * 32)
    }
    when(miss_delay_cnt === (missDelay - 1).U) {
      tag_arrays(replace_way(inst_addr_index))(inst_addr_index).valid := 1.B
      tag_arrays(replace_way(inst_addr_index))(inst_addr_index).tag   := inst_addr_tag
    }
  }

}

object ICacheGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/test"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new ICache()))
    )
}
