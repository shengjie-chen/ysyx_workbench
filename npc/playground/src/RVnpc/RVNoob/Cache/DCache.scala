package RVnpc.RVNoob.Cache

import RVnpc.RVNoob.Axi.{AxiReadCtrlIO, AxiWriteCtrlIO}
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
  val deviceId:      Int = 0,
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
    val addr = Input(UInt(addrWidth.W))
    val ren  = Input(Bool())

    val wen        = Input(Bool())
    val wdata      = Input(UInt(xlen.W))
    val zero_ex_op = Input(UInt(2.W))
    val fencei     = Input(Bool())
    val valid      = Input(Bool())

    val miss  = Output(Bool())
    val rdata = Output(UInt(xlen.W))

    val sram = Vec(4, new CacheSramIO)

    val axi_rctrl = Flipped(new AxiReadCtrlIO)
    val axi_wctrl = Flipped(new AxiWriteCtrlIO)
  })
  // ********************************** Main Mem Define **********************************
  // >>>>>>>>>>>>>> data array <<<<<<<<<<<<<<
  val data_cen   = Wire(Vec(4, Bool()))
  val data_wen   = Wire(Bool())
  val data_bwen  = Wire(UInt(128.W))
  val data_addr  = Wire(UInt(6.W))
  val data_wdata = Wire(UInt(128.W))
  // >>>>>>>>>>>>>> tag array <<<<<<<<<<<<<<
  val tag_arrays =
    RegInit(Vec(ways, Vec(sets, new TagArrays(tagWidth))), 0.B.asTypeOf(Vec(ways, Vec(sets, new TagArrays(tagWidth)))))
  // >>>>>>>>>>>>>> DPI PMEM / AXI <<<<<<<<<<<<<<
  val pmem_rdata   = Wire(UInt(xlen.W))
  val pmem_shift   = Wire(UInt(3.W))
  val pmem_read_ok = Wire(Bool())
  //  val pmem_read_ok_addr = Wire(UInt(addrWidth.W))
  val pmem_write_ok     = Wire(Bool())
  val pmem_writeback_ok = Wire(Bool())
  // ********************************** Main Signal Define **********************************
  // >>>>>>>>>>>>>> fencei 控制信号 <<<<<<<<<<<<<<
  val fencei_valid = io.fencei && io.valid && !fencei_ok
  val fencei_reg   = RegInit(0.B)
  val fencei_state = fencei_reg || fencei_valid
  val fencei_ok    = Wire(Bool())
  when(fencei_valid) {
    fencei_reg := 1.B
  }.elsewhen(fencei_state && fencei_ok) {
    fencei_reg := 0.B
  }
  val dirty_set = Wire(Vec(sets, Bool()))
  for (i <- 0 until sets) {
    dirty_set(i) := tag_arrays(0)(i).dirty_bit || tag_arrays(1)(i).dirty_bit ||
    tag_arrays(2)(i).dirty_bit || tag_arrays(3)(i).dirty_bit
  }
  fencei_ok := !dirty_set.asUInt().orR()
  val fencei_set = PriorityEncoder(dirty_set.asUInt())
  val fencei_way = PriorityEncoder(
    Seq(
      tag_arrays(0)(fencei_set).dirty_bit,
      tag_arrays(1)(fencei_set).dirty_bit,
      tag_arrays(2)(fencei_set).dirty_bit,
      tag_arrays(3)(fencei_set).dirty_bit
    )
  )

  // >>>>>>>>>>>>>> mmio 控制信号 <<<<<<<<<<<<<<
  val inpmem          = (io.addr >= 0x80000000L.U) && (io.addr < 0x88000000L.U)
  val inpmem_op       = (io.ren || io.wen) && inpmem
  val mmio_read_valid = !inpmem && io.ren && io.valid
  val mmio_read_reg   = RegInit(0.B)
  val mmio_read       = mmio_read_valid || mmio_read_reg
  when(mmio_read_valid) {
    mmio_read_reg := 1.B
  }.elsewhen(pmem_read_ok) {
    mmio_read_reg := 0.B
  }
  val mmio_write_valid = !inpmem && io.wen && io.valid
  val mmio_write_reg   = RegInit(0.B)
  val mmio_write       = mmio_write_valid || mmio_write_reg
  when(mmio_write_valid) {
    mmio_write_reg := 1.B
  }.elsewhen(pmem_writeback_ok) {
    mmio_write_reg := 0.B
  }
  // >>>>>>>>>>>>>> 地址分段 <<<<<<<<<<<<<<
  val addr_tag    = io.addr(addrWidth - 1, addrWidth - tagWidth)
  val addr_index  = Mux(fencei_state, fencei_set, io.addr(addrWidth - tagWidth - 1, addrWidth - tagWidth - indexWidth))
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
  val inpmem_miss = Wire(Bool())
  inpmem_miss := !hit && inpmem_op
  // >>>>>>>>>>>>>> Replace信号 <<<<<<<<<<<<<<
  // 替换算法 LRU 最近最少使用 近似实现   Pseudo LRU
  val waysWidth = log2Ceil(ways)
  //  println(s"waysWidth = $waysWidth")
  val wordNumPerBurst = axiDataWidth / 32
  val PLRU_bits       = RegInit(VecInit(Seq.fill(sets)(VecInit(0.B, 0.B, 0.B)))) //sets, UInt(waysWidth.W)))
  val replace_way     = Wire(UInt(waysWidth.W))
  val replace_dirty   = tag_arrays(replace_way)(addr_index).dirty_bit
  val replace_tag     = Wire(UInt(tagWidth.W))
  replace_tag := tag_arrays(replace_way)(addr_index).tag
  dontTouch(replace_tag)

  val replace_buffer = RegInit(Vec(4, UInt(64.W)), 0.B.asTypeOf(Vec(4, UInt(64.W))))
  val replace_addr   = RegInit(UInt(addrWidth.W), 0.U)
  val replace_cnt    = RegInit(0.U(3.W))
  // >>>>>>>>>>>>>> Allocate信号 <<<<<<<<<<<<<<
  val allocate_state = inpmem_miss && !replace_dirty
  val allocate_cnt   = RegInit(0.U(2.W))
  // ********************************** Data Array / Single Port RAM x 4 **********************************
  // >>>>>>>>>>>>>> Input Logic <<<<<<<<<<<<<<
  // CEN
  data_cen := 0.B.asTypeOf(data_cen)
  when(inpmem_op) {
    when(hit) {
      data_cen := hit_oh
    }.otherwise {
      when((replace_dirty && replace_cnt <= 1.U) || (!replace_dirty && pmem_read_ok)) {
        data_cen(replace_way) := 1.B
      }
    }
  }
  // WEN
  data_wen := (!replace_dirty && !hit) || (hit && io.wen)
  // BWEN
  val data_shift = (Mux(!replace_dirty && !hit, Mux(allocate_cnt(0), 8.U, 0.U), addr_offset(3, 0)) << 3).asUInt()
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
    Mux(replace_dirty, Cat(addr_index, replace_cnt(0)), Cat(addr_index, allocate_cnt(1))),
    Cat(addr_index, addr_offset(byteOffsetWidth - 1))
  )
  // D
  data_wdata := Mux(!hit, io.axi_rctrl.data << data_shift, io.wdata << data_shift)
  // >>>>>>>>>>>>>> Assign <<<<<<<<<<<<<<
  for (i <- 0 to 3) {
    io.sram(i).cen   := ~data_cen(i)
    io.sram(i).wen   := ~data_wen
    io.sram(i).wmask := ~data_bwen
    io.sram(i).addr  := data_addr
    io.sram(i).wdata := data_wdata
  }

  // ********************************** Tag Array **********************************
  when(replace_cnt === 6.U && pmem_writeback_ok) {
    tag_arrays(replace_way)(addr_index).dirty_bit := 0.B
  }
  when(inpmem_op && hit && io.wen) {
    tag_arrays(hit_way)(addr_index).dirty_bit := 1.B
  }
  when(allocate_cnt === 3.U && pmem_read_ok) {
    tag_arrays(replace_way)(addr_index).valid := 1.B
    tag_arrays(replace_way)(addr_index).tag   := addr_tag
  }

  // ********************************** DPI PMEM / AXI **********************************
  // >>>>>>>>>>>>>> Input Logic <<<<<<<<<<<<<<
  // Read signal
  pmem_rdata        := RegEnable((io.axi_rctrl.data >> (pmem_shift * 8.U)), 0.U, pmem_read_ok)
  io.axi_rctrl.en   := (allocate_state && !RegNext(allocate_state, 0.B)) || mmio_read_valid
  io.axi_rctrl.id   := deviceId.U
  io.axi_rctrl.size := 3.U
  when(mmio_read) {
    io.axi_rctrl.addr  := io.addr & (~0x7.U(addrWidth.W)).asUInt()
    io.axi_rctrl.burst := 0.U
    io.axi_rctrl.len   := 0.U
  }.otherwise {
    io.axi_rctrl.addr  := io.addr & (~0x1f.U(addrWidth.W)).asUInt()
    io.axi_rctrl.burst := 1.U
    io.axi_rctrl.len   := 3.U
  }

  // Write signal
  val replace_axi_write = replace_cnt === 3.U
  io.axi_wctrl.en   := mmio_write_valid || (replace_axi_write && !RegNext(replace_axi_write, 0.B))
  io.axi_wctrl.id   := deviceId.U
  io.axi_wctrl.size := 3.U
  val wbuf_ready = RegInit(0.B)
  when(mmio_write_valid || replace_cnt === 2.U) {
    wbuf_ready := 1.B
  }.elsewhen(pmem_write_ok) {
    wbuf_ready := 0.B
  }
  io.axi_wctrl.wbuf_ready := wbuf_ready
  when(mmio_write) {
    io.axi_wctrl.burst := 0.U
    io.axi_wctrl.addr  := io.addr & (~0x7.U(addrWidth.W)).asUInt()
    io.axi_wctrl.len   := 0.U
    io.axi_wctrl.data  := (io.wdata << (pmem_shift * 8.U))
    io.axi_wctrl.strb := MuxCase(
      "b11111111".U,
      Array(
        (io.zero_ex_op === 3.U) -> "b11111111".U, // write double word
        (io.zero_ex_op === 2.U) -> ("b1111".U << pmem_shift), // write word
        (io.zero_ex_op === 1.U) -> ("b11".U << pmem_shift), // write half word
        (io.zero_ex_op === 0.U) -> ("b1".U << pmem_shift) // write byte
      )
    )
  }.otherwise {
    io.axi_wctrl.burst := 1.U
    io.axi_wctrl.addr  := replace_addr
    io.axi_wctrl.len   := 3.U
    io.axi_wctrl.data := MuxCase(
      0.U,
      Array(
        (replace_cnt === 3.U) -> replace_buffer(0),
        (replace_cnt === 4.U) -> replace_buffer(1),
        (replace_cnt === 5.U) -> replace_buffer(2),
        (replace_cnt === 6.U) -> replace_buffer(3)
      )
    )
    io.axi_wctrl.strb := "b11111111".U
  }

  // Other
  when(mmio_read || mmio_write) {
    pmem_shift := io.addr
  }.otherwise {
    pmem_shift := 0.U
  }
  pmem_read_ok      := io.axi_rctrl.handshake
  pmem_write_ok     := io.axi_wctrl.whandshake
  pmem_writeback_ok := io.axi_wctrl.bhandshake
  // ********************************** Replace信号 **********************************
  when(inpmem_op && hit) {
    PLRU_bits(addr_index)(0) := hit_oh.asUInt()(1, 0).orR
    when(hit_oh.asUInt()(1, 0).orR) {
      PLRU_bits(addr_index)(1) := hit_oh.asUInt()(0)
    }.otherwise {
      PLRU_bits(addr_index)(2) := hit_oh.asUInt()(2)
    }
  }
  replace_way := Mux(
    fencei_state,
    fencei_way,
    Cat(
      PLRU_bits(addr_index)(0),
      Mux(PLRU_bits(addr_index)(0), PLRU_bits(addr_index)(2), PLRU_bits(addr_index)(1))
    )
  )
  when(inpmem_miss && replace_dirty) {
    replace_addr := Cat(replace_tag, addr_index, 0.U(5.W))
    when(replace_cnt < 3.U) {
      replace_cnt := replace_cnt + 1.U
      when(replace_cnt === 1.U) {
        replace_buffer(1) := io.sram(replace_way).rdata(127, 64)
        replace_buffer(0) := io.sram(replace_way).rdata(63, 0)
      }.elsewhen(replace_cnt === 2.U) {
        replace_buffer(3) := io.sram(replace_way).rdata(127, 64)
        replace_buffer(2) := io.sram(replace_way).rdata(63, 0)
      }
    }.elsewhen((replace_cnt >= 3.U && replace_cnt < 6.U) && pmem_write_ok) {
      replace_cnt := replace_cnt + 1.U
    }.elsewhen(replace_cnt === 6.U && pmem_writeback_ok) {
      replace_cnt := 0.U
    }
  }

  // ********************************** Allocate信号 **********************************
  when(allocate_state && pmem_read_ok) {
    allocate_cnt := allocate_cnt + 1.U
  }

  // ********************************** Output **********************************
  io.miss := inpmem_miss || mmio_read || mmio_write || fencei_state

  when(RegNext(inpmem, 0.B)) {
    io.rdata := (io.sram(RegNext(hit_way, 0.U)).rdata >> RegNext(data_shift, 0.U))
  }.otherwise {
    io.rdata := pmem_rdata
  }

  override def desiredName = if (tapeout) ysyxid + "_" + getClassName else getClassName

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

object DCache {
  def apply(isICache: Boolean, deviceId: Int = 0): DCache = {
    val cache = Module(new DCache(deviceId = deviceId))
    if (isICache) {
      cache.io.wdata      := 0.U
      cache.io.wen        := 0.B
      cache.io.zero_ex_op := 3.U
      cache.io.valid      := 1.B
      cache.io.fencei     := 0.B
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
