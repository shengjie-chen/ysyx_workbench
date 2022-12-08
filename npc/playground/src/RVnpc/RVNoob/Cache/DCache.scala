package RVnpc.RVNoob.Cache

import RVnpc.RVNoob.RVNoobConfig
import chisel3._
import chisel3.util._
import scala.math.pow

class TagArrays(tagWidth: Int) extends Bundle {
  val dirty_bit = Bool()
  val valid     = Bool()
  val tag       = UInt(tagWidth.W)
}

class DCache(
  val addrWidth:     Int = 32,
  val cacheSize:     Int = 4 * pow(2, 10).toInt,
  val cacheLineSize: Int = 32,
  val ways:          Int = 4,
  val axiDataWidth:  Int = 64,
  val missDelay:     Int = 4)
    extends Module
    with RVNoobConfig {
  val cacheLineNum:    Int = cacheSize / cacheLineSize // 128
  val sets:            Int = cacheLineNum / ways // 32
  val byteOffsetWidth: Int = log2Ceil(cacheLineSize) // 5
  val indexWidth:      Int = log2Ceil(sets) //log2Ceil(sets) // 5
  val tagWidth:        Int = addrWidth - indexWidth - byteOffsetWidth // 22
  //  println(s"ways = $ways")
  //  println(s"cacheSize = $cacheSize")
  //  println(s"cacheLineNum = $cacheLineNum")
  val io = IO(new Bundle {
    val pc = Input(UInt(addrWidth.W))

    val addr = Input(UInt(addrWidth.W))
    val ren  = Input(Bool())

    val wen        = Input(Bool())
    val wdata      = Input(UInt(xlen.W))
    val zero_ex_op = Input(UInt(2.W))
    val valid      = Input(Bool())

    val miss  = Output(Bool())
    val rdata = Output(UInt(xlen.W))
  })
  // ********************************** Main Mem Define **********************************
  // >>>>>>>>>>>>>> data array <<<<<<<<<<<<<<
  val data_arrays = VecInit(Seq.fill(4)(Module(new S011HD1P_X32Y2D128_BW).io))

  val data_cen   = Wire(Vec(4, Bool()))
  val data_wen   = Wire(Bool())
  val data_bwen  = Wire(UInt(128.W))
  val data_addr  = Wire(UInt(6.W))
  val data_wdata = Wire(UInt(128.W))
  // >>>>>>>>>>>>>> tag array <<<<<<<<<<<<<<
  val tag_arrays = Reg(Vec(ways, Vec(sets, new TagArrays(tagWidth))))
  // >>>>>>>>>>>>>> DPI PMEM / AXI <<<<<<<<<<<<<<
  val dpi_pmem = Module(new DpiPmem)

  val pmem_ren   = Wire(Bool())
  val pmem_raddr = Wire(UInt(addrWidth.W))
  val pmem_rdata = RegEnable(dpi_pmem.io.rdata, pmem_ren)

  val pmem_wen   = Wire(Bool())
  val pmem_waddr = Wire(UInt(addrWidth.W))
  val pmem_wdata = Wire(UInt(xlen.W))
  val pmem_wmask = Wire(UInt(8.W))

  val pmem_shift        = Wire(UInt(3.W))
  val pmem_read_ok      = Wire(Bool())
  val pmem_read_ok_addr = Wire(UInt(addrWidth.W))

  // ********************************** Main Signal Define **********************************
  // >>>>>>>>>>>>>> mmio 控制信号 <<<<<<<<<<<<<<
  val inpmem     = (io.addr >= 0x80000000L.U) && (io.addr < 0x88000000L.U)
  val inpmem_op  = (io.ren || io.wen) && inpmem
  val mmio_read  = !inpmem && io.ren
  val mmio_write = !inpmem && io.wen
  // >>>>>>>>>>>>>> 地址分段 <<<<<<<<<<<<<<
  val addr_tag    = io.addr(addrWidth - 1, addrWidth - tagWidth)
  val addr_index  = io.addr(addrWidth - tagWidth - 1, addrWidth - tagWidth - indexWidth)
  val addr_offset = io.addr(byteOffsetWidth - 1, 0)
  // >>>>>>>>>>>>>> 命中信号 <<<<<<<<<<<<<<
  val hit_oh  = Wire(Vec(ways, Bool()))
  val hit_way = OHToUInt(hit_oh)
  val hit     = hit_oh.asUInt().orR
  hit_oh := 0.B.asTypeOf(hit_oh)
  when(io.ren || io.wen) {
    for (w <- 0 until ways) {
      hit_oh(w) := (tag_arrays(w)(addr_index).tag === addr_tag) && tag_arrays(w)(addr_index).valid
    }
  }
  // >>>>>>>>>>>>>> 缺失信号 <<<<<<<<<<<<<<
  val miss = Wire(Bool())
  miss := !hit && inpmem_op
  // >>>>>>>>>>>>>> Replace信号 <<<<<<<<<<<<<<
  // 替换算法 LRU 最近最少使用 近似实现   Pseudo LRU
  val waysWidth = log2Ceil(ways)
//  println(s"waysWidth = $waysWidth")
  val wordNumPerBurst = axiDataWidth / 32
  val PLRU_bits       = RegInit(VecInit(Seq.fill(sets)(VecInit(0.B, 0.B, 0.B)))) //sets, UInt(waysWidth.W)))
  val replace_way     = Wire(UInt(waysWidth.W))

  val replace_dirty = tag_arrays(replace_way)(addr_index).dirty_bit
  val replace_tag   = Wire(UInt(tagWidth.W))
  replace_tag := tag_arrays(replace_way)(addr_index).tag
  dontTouch(replace_tag)

  val replace_buffer = Reg(Vec(2, UInt(64.W)))
  val replace_addr   = Reg(UInt(addrWidth.W))
  val replace_valid  = RegInit(0.B)
  val replace_cnt    = RegInit(0.U(2.W))
  // >>>>>>>>>>>>>> Allocate信号 <<<<<<<<<<<<<<
  val allocate_cnt = RegInit(0.U(3.W))

  // ********************************** Data Array / Single Port RAM x 4 **********************************
  // >>>>>>>>>>>>>> Input Logic <<<<<<<<<<<<<<
  // CEN
  data_cen := 0.B.asTypeOf(data_cen)
  when(inpmem_op) {
    when(hit) {
      data_cen := hit_oh
    }.otherwise {
      when(replace_dirty || (!replace_dirty && pmem_read_ok && allocate_cnt =/= 0.U)) {
        data_cen(replace_way) := 1.B
      }
    }
  }
  // WEN
  data_wen := (!replace_dirty && !hit) || (hit && io.wen)
  // BWEN
  val data_shift = (Mux(!replace_dirty && !hit, pmem_read_ok_addr(3, 0), addr_offset(3, 0)) << 3).asUInt()
  val bwen_temp  = Cat(0.U(64.W), 0xffffffffffffffffL.S(64.W).asUInt())
  data_bwen := MuxCase(
    0.U,
    Array(
      (io.zero_ex_op === 3.U || !hit) -> (bwen_temp << data_shift), // write double word
      (io.zero_ex_op === 2.U) -> (0xffffffffL.U(128.W) << data_shift), // write word
      (io.zero_ex_op === 1.U) -> (0xffffL.U(128.W) << data_shift), // write half word
      (io.zero_ex_op === 0.U) -> (0xffL.U(128.W) << data_shift) // write byte
    )
  )
  // A
  data_addr := Mux(
    !hit,
    Mux(replace_dirty, Cat(addr_index, replace_cnt(0)), pmem_read_ok_addr(9, 4)),
    Cat(addr_index, addr_offset(byteOffsetWidth - 1))
  )
  // D
  data_wdata := Mux(!hit, pmem_rdata << data_shift, io.wdata << data_shift)
  // >>>>>>>>>>>>>> Assign <<<<<<<<<<<<<<
  for (i <- 0 to 3) {
    data_arrays(i).CLK  <> clock
    data_arrays(i).CEN  := ~data_cen(i)
    data_arrays(i).WEN  := ~data_wen
    data_arrays(i).BWEN := ~data_bwen
    data_arrays(i).A    := data_addr
    data_arrays(i).D    := data_wdata
  }

  // ********************************** Tag Array **********************************
  when(replace_cnt === 2.U) {
    tag_arrays(replace_way)(addr_index).dirty_bit := 0.B
  }
  when(inpmem_op && hit && io.wen) {
    tag_arrays(hit_way)(addr_index).dirty_bit := 1.B
  }
  when(allocate_cnt === 4.U) {
    tag_arrays(replace_way)(addr_index).valid := 1.B
    tag_arrays(replace_way)(addr_index).tag   := addr_tag
  }

  // ********************************** DPI PMEM / AXI **********************************
  // >>>>>>>>>>>>>> Input Logic <<<<<<<<<<<<<<
  // Read signal
  when(mmio_read ) {
    pmem_raddr := io.addr & (~0x7.U(addrWidth.W)).asUInt()
  }.otherwise {
    pmem_raddr := Cat(addr_tag, addr_index, allocate_cnt(1, 0), 0.U((byteOffsetWidth - 2).W))
  }
  pmem_ren := ((miss && !replace_dirty && !allocate_cnt(2)) || (mmio_read && io.valid))
  // Write signal
  pmem_wen := (mmio_write && io.valid) || replace_valid
  when(mmio_write && io.valid) {
    pmem_waddr := io.addr & (~0x7.U(addrWidth.W)).asUInt()
    pmem_wdata := (io.wdata << (pmem_shift * 8.U))
    pmem_wmask := MuxCase(
      "b11111111".U,
      Array(
        (io.zero_ex_op === 3.U) -> "b11111111".U, // write double word
        (io.zero_ex_op === 2.U) -> ("b1111".U << pmem_shift), // write word
        (io.zero_ex_op === 1.U) -> ("b11".U << pmem_shift), // write half word
        (io.zero_ex_op === 0.U) -> ("b1".U << pmem_shift) // write byte
      )
    )
  }.otherwise {
    pmem_waddr := replace_addr
    pmem_wdata := Mux(
      replace_dirty,
      Mux(replace_cnt(0), data_arrays(replace_way).Q(63, 0), replace_buffer(1)),
      replace_buffer(allocate_cnt(0))
    )
    pmem_wmask := "b11111111".U
  }
  // Other
  pmem_shift := 0.U
  when((mmio_write || mmio_read) && io.valid) {
    pmem_shift := io.addr
  }
  pmem_read_ok      := RegNext(pmem_ren)
  pmem_read_ok_addr := RegNext(pmem_raddr)

  // >>>>>>>>>>>>>> Connect <<<<<<<<<<<<<<
  dpi_pmem.io.clk    <> clock
  dpi_pmem.io.r_pmem <> pmem_ren
  dpi_pmem.io.raddr  <> pmem_raddr
  dpi_pmem.io.w_pmem <> pmem_wen
  dpi_pmem.io.waddr  <> pmem_waddr
  dpi_pmem.io.wmask  <> pmem_wmask
  dpi_pmem.io.wdata  <> pmem_wdata
  dpi_pmem.io.pc     <> io.pc

  // ********************************** Replace信号 **********************************
  when(inpmem_op && hit) {
    PLRU_bits(addr_index)(0) := hit_oh.asUInt()(1, 0).orR
    when(hit_oh.asUInt()(1, 0).orR) {
      PLRU_bits(addr_index)(1) := hit_oh.asUInt()(0)
    }.otherwise {
      PLRU_bits(addr_index)(2) := hit_oh.asUInt()(2)
    }
  }
  replace_way := Cat(
    PLRU_bits(addr_index)(0),
    Mux(PLRU_bits(addr_index)(0), PLRU_bits(addr_index)(2), PLRU_bits(addr_index)(1))
  )
  when(miss && replace_dirty) {
    replace_cnt := replace_cnt + 1.U
    when(replace_cnt === 0.U) {
      replace_addr  := Cat(replace_tag, addr_index, 0.U(5.W))
      replace_valid := 1.B
    }.elsewhen(replace_cnt === 1.U) {
      replace_buffer(1) := data_arrays(replace_way).Q(127, 64)
      replace_addr      := replace_addr + 8.U
    }.elsewhen(replace_cnt === 2.U) {
      replace_addr      := replace_addr + 8.U
      replace_buffer(1) := data_arrays(replace_way).Q(127, 64)
      replace_buffer(0) := data_arrays(replace_way).Q(63, 0)
      replace_cnt       := 0.U
    }
  }
  when(miss && !replace_dirty) {
    when(allocate_cnt === 0.U) {
      when(replace_valid) {
        replace_addr := replace_addr + 8.U
      }
    }.elsewhen(allocate_cnt === 1.U) {
      when(replace_valid) {
        replace_valid := 0.B
      }
    }
  }

  // ********************************** Allocate信号 **********************************
  when(miss && !replace_dirty) {
    when(allocate_cnt === 0.U) {
      allocate_cnt := allocate_cnt + 1.U
    }.elsewhen(pmem_read_ok) {
      when(allocate_cnt === 4.U) {
        allocate_cnt := 0.U
      }.otherwise {
        allocate_cnt := allocate_cnt + 1.U
      }
    }
  }

  // ********************************** Output **********************************
  io.miss := miss

  when(RegNext(inpmem)) {
    io.rdata := (data_arrays(RegNext(hit_way)).Q >> RegNext(data_shift))
  }.otherwise {
    io.rdata := (pmem_rdata >> (RegNext(pmem_shift) * 8.U))
  }

}

class S011HD1P_X32Y2D128_BW extends BlackBox {
  val io = IO(new Bundle {
    val Q    = Output(UInt(128.W))
    val CLK  = Input(Clock())
    val CEN  = Input(Bool())
    val WEN  = Input(Bool())
    val BWEN = Input(UInt(128.W))
    val A    = Input(UInt(6.W))
    val D    = Input(UInt(128.W))
  })

}

//object S011HD1P_X32Y2D128_BW {
//  def apply(
//    clk:    Clock,
//    inst:   UInt,
//    a0:     UInt,
//    ebreak: Bool
//  ): S011HD1P_X32Y2D128_BW = {
//    val data = Module(new S011HD1P_X32Y2D128_BW)
//    data.io.clk    <> clk
//    data.io.inst   <> inst
//    data.io.a0     <> a0
//    data.io.ebreak <> ebreak
//    data
//  }
//}

object DCache {
  def apply(isICache: Boolean): DCache = {
    val cache = Module(new DCache)
    if (isICache) {
      cache.io.wdata      := 0.U
      cache.io.wen        := 0.B
      cache.io.zero_ex_op := 3.U
      cache.io.valid      := 1.B
    }
    cache
  }
}

object DCacheGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/test"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new DCache()))
    )
}
