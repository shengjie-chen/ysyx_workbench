package RVnpc.RVNoob.Cache

import RVnpc.RVNoob.Axi.{AxiReadCtrlIO, AxiWriteCtrlIO}
import RVnpc.RVNoob.{dualEdge, fallEdge, riseEdge, RVNoobConfig}
import chisel3._
import chisel3.util._

import scala.math.pow

class TagArrays(tagWidth: Int) extends Bundle {
  val dirty_bit = Bool()
  val valid     = Bool()
  val tag       = UInt(tagWidth.W)
}

class DCache(
  val isICache:      Boolean = false,
  val deviceId:      Int     = 0,
  val cacheSize:     Int     = (4 * pow(2, 10)).toInt,
  val cacheLineSize: Int     = 32,
  val ways:          Int     = 4
//  val axiDataWidth:  Int     = 64,
//  val missDelay:     Int     = 4
) extends Module
    with RVNoobConfig {
  val cacheLineNum:    Int = cacheSize / cacheLineSize // 128
  val sets:            Int = cacheLineNum / ways // 32
  val byteOffsetWidth: Int = log2Ceil(cacheLineSize) // 5
  val indexWidth:      Int = log2Ceil(sets) //log2Ceil(sets) // 5
  val tagWidth:        Int = inst_w - indexWidth - byteOffsetWidth // 22
  //  println(s"ways = $ways")
  //  println(s"cacheSize = $cacheSize")
  //  println(s"cacheLineNum = $cacheLineNum")
  val io = IO(new Bundle {
    val addr       = Input(UInt(inst_w.W))
    val ren        = Input(Bool())
    val wen        = Input(Bool())
    val wdata      = Input(UInt(xlen.W))
    val zero_ex_op = Input(UInt(2.W))
    val fencei     = Input(Bool())
    val in_valid   = Input(Bool())

    val miss       = Output(Bool())
    val rdata      = Output(if (isICache) UInt(inst_w.W) else UInt(xlen.W))
    val out_rvalid = Output(Bool())

    val sram      = Vec(4, new CacheSramIO)
    val axi_rctrl = Flipped(new AxiReadCtrlIO)
    val axi_wctrl = Flipped(new AxiWriteCtrlIO)
  })
//  dontTouch(io.fencei)
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
  //  val pmem_read_ok_addr = Wire(UInt(inst_w.W))
  val pmem_write_ok     = Wire(Bool())
  val pmem_writeback_ok = Wire(Bool())
  // ********************************** Main Signal Define **********************************
  // >>>>>>>>>>>>>> fencei 控制信号 <<<<<<<<<<<<<<
  val fencei_ok    = Wire(Bool())
  val fencei_valid = io.fencei && io.in_valid && !fencei_ok
  val fencei_reg   = RegInit(0.B)
  val fencei_state = fencei_reg || fencei_valid
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
//  if (tapeout && !isICache) {
//    dontTouch(fencei_state)
//    dontTouch(io.fencei)
//  }
  val inpmem =
    if (tapeout) (io.addr >= 0x80000000L.U)
    else (io.addr >= 0x80000000L.U) && (io.addr < 0x88000000L.U)
  val inpmem_op = (io.ren || io.wen) && inpmem
  // >>>>>>>>>>>>>> mmio read 控制信号 <<<<<<<<<<<<<<
  val mmio_read_valid     = !inpmem && io.ren && io.in_valid
  val mmio_read_reg       = RegInit(0.B)
  val mmio_read           = mmio_read_valid || mmio_read_reg
  val mmio_read_ready_reg = RegInit(0.B)
  val mmio_read_ready     = Wire(Bool())
  when(pmem_read_ok) {
    mmio_read_reg := 0.B
  }.elsewhen(mmio_read_valid) {
    mmio_read_reg := 1.B
  }
  when(pmem_read_ok && mmio_read_reg) {
    mmio_read_ready_reg := 1.B
  }.elsewhen(io.in_valid) {
    mmio_read_ready_reg := 0.B
  }
  mmio_read_ready := mmio_read_ready_reg && !io.in_valid
  // >>>>>>>>>>>>>> mmio write 控制信号 <<<<<<<<<<<<<<
  val mmio_write_valid = !inpmem && io.wen && io.in_valid
  val mmio_write_reg   = RegInit(0.B)
  val mmio_write       = mmio_write_valid || mmio_write_reg
  when(pmem_writeback_ok) {
    mmio_write_reg := 0.B
  }.elsewhen(mmio_write_valid) {
    mmio_write_reg := 1.B
  }
  // >>>>>>>>>>>>>> 地址分段 <<<<<<<<<<<<<<
  val addr_tag     = io.addr(inst_w - 1, inst_w - tagWidth)
  val addr_index   = Mux(fencei_state, fencei_set, io.addr(inst_w - tagWidth - 1, inst_w - tagWidth - indexWidth))
  val addr_offset  = io.addr(byteOffsetWidth - 1, 0)
  val addr_index_r = RegNext(addr_index)
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
//  val wordNumPerBurst = axiDataWidth / 32
  val PLRU_bits = RegInit(VecInit(Seq.fill(sets)(VecInit(0.B, 0.B, 0.B)))) //sets, UInt(waysWidth.W)))

  val sRE0 :: sRE1 :: sRE2 :: sRE3 :: sRE4 :: sRE5 :: Nil = Enum(6)

  val replace_fsm_state = RegInit(sRE0)
  val into_re_or_al     = inpmem_miss || (fencei_state && !fencei_ok) // into replace or allocate
  val into_re_or_al_r   = RegNext(into_re_or_al, 0.B)
  val replace_state     = Wire(Bool())
  val into_replace_r    = Wire(Bool())
  val replace_way       = Wire(UInt(waysWidth.W))
  val replace_way_r     = RegNext(replace_way)
  val replace_dirty     = tag_arrays(replace_way_r)(addr_index_r).dirty_bit
  val replace_tag       = Wire(UInt(tagWidth.W))
  into_replace_r := replace_fsm_state === sRE0 && into_re_or_al_r && replace_dirty
  replace_tag    := tag_arrays(replace_way_r)(addr_index_r).tag
  if (!tapeout) {
    dontTouch(replace_tag)
  }

  val replace_buffer = RegInit(Vec(4, UInt(64.W)), 0.B.asTypeOf(Vec(4, UInt(64.W))))
  val replace_addr   = RegInit(UInt(inst_w.W), 0.U)
  // >>>>>>>>>>>>>> Allocate信号 <<<<<<<<<<<<<<
  val allocate_state = Wire(Bool())
  val allocate_reg   = RegInit(0.B)
  val allocate_cnt   = RegInit(0.U(2.W))
  val into_allocate_r = !replace_dirty &&
    (RegNext(inpmem_miss && io.in_valid) || RegNext(pmem_writeback_ok && !fencei_state && replace_state))

  // ********************************** Data Array / Single Port RAM x 4 **********************************
  // >>>>>>>>>>>>>> Input Logic <<<<<<<<<<<<<<
  // CEN
  data_cen := 0.B.asTypeOf(data_cen)
  when(inpmem_op && hit) {
    data_cen := hit_oh
  }.elsewhen(into_replace_r || replace_fsm_state === sRE1) { // replace
    data_cen(replace_way_r) := 1.B
  }.elsewhen(allocate_state && pmem_read_ok) { // allocate
    data_cen(replace_way_r) := 1.B
  }
  // WEN
  data_wen := allocate_state || (hit && io.wen)
  // BWEN
  val data_shift = (Mux(allocate_state, Mux(allocate_cnt(0), 8.U, 0.U), addr_offset(3, 0)) << 3).asUInt()
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
    Mux(replace_dirty, Cat(addr_index_r, replace_fsm_state === sRE1), Cat(addr_index_r, allocate_cnt(1))),
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
  when(replace_fsm_state === sRE5 && pmem_writeback_ok) {
    tag_arrays(replace_way_r)(addr_index_r).dirty_bit := 0.B
  }
  when(inpmem_op && hit && io.wen) {
    tag_arrays(hit_way)(addr_index).dirty_bit := 1.B
  }
  when(allocate_cnt === 3.U && pmem_read_ok) {
    tag_arrays(replace_way_r)(addr_index_r).valid := 1.B
    tag_arrays(replace_way_r)(addr_index_r).tag   := addr_tag
  }

  // ********************************** DPI PMEM / AXI **********************************
  // >>>>>>>>>>>>>> Input Logic <<<<<<<<<<<<<<
  // Read signal
  pmem_rdata      := RegEnable((io.axi_rctrl.data >> (pmem_shift * 8.U)), 0.U, pmem_read_ok)
  io.axi_rctrl.en := into_allocate_r || mmio_read_valid
  io.axi_rctrl.id := deviceId.U
  when(mmio_read) {
    io.axi_rctrl.size  := io.zero_ex_op
    io.axi_rctrl.addr  := io.addr
    io.axi_rctrl.burst := 0.U
    io.axi_rctrl.len   := 0.U
  }.otherwise {
    io.axi_rctrl.size  := 3.U
    io.axi_rctrl.addr  := io.addr & (~0x1f.U(inst_w.W)).asUInt()
    io.axi_rctrl.burst := 1.U
    io.axi_rctrl.len   := 3.U
  }

  // Write signal
  val replace_axi_write = replace_fsm_state === sRE1
  io.axi_wctrl.en := mmio_write_valid || riseEdge(replace_axi_write)
  io.axi_wctrl.id := deviceId.U
  val wbuf_ready = RegInit(0.B)
  when(mmio_write_valid || into_replace_r) {
    wbuf_ready := 1.B
  }.elsewhen(pmem_write_ok) {
    wbuf_ready := 0.B
  }
  io.axi_wctrl.wbuf_ready := wbuf_ready || mmio_write_valid
  when(mmio_write) {
    io.axi_wctrl.size  := io.zero_ex_op
    io.axi_wctrl.burst := 0.U
    io.axi_wctrl.addr  := io.addr
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
    io.axi_wctrl.size  := 3.U
    io.axi_wctrl.burst := 1.U
    io.axi_wctrl.addr  := replace_addr
    io.axi_wctrl.len   := 3.U
    io.axi_wctrl.data := MuxCase(
      0.U,
      Array(
        (replace_fsm_state === sRE2) -> replace_buffer(0),
        (replace_fsm_state === sRE3) -> replace_buffer(1),
        (replace_fsm_state === sRE4) -> replace_buffer(2),
        (replace_fsm_state === sRE5) -> replace_buffer(3)
      )
    )
    io.axi_wctrl.strb := "b11111111".U
  }

  // Other
  when(mmio_read || mmio_write) {
    pmem_shift := io.addr(2, 0)
  }.otherwise {
    pmem_shift := 0.U
  }
  pmem_read_ok      := io.axi_rctrl.handshake
  pmem_write_ok     := io.axi_wctrl.whandshake
  pmem_writeback_ok := io.axi_wctrl.bhandshake
  // ********************************** Replace信号 **********************************
  switch(replace_fsm_state) {
    is(sRE0) {
      when(replace_dirty && into_re_or_al_r) {
        replace_fsm_state := sRE1
      }
    }
    is(sRE1) {
        replace_fsm_state := sRE2
    }
    is(sRE2) {
      when(pmem_write_ok) {
        replace_fsm_state := sRE3
      }
    }
    is(sRE3) {
      when(pmem_write_ok) {
        replace_fsm_state := sRE4
      }
    }
    is(sRE4) {
      when(pmem_write_ok) {
        replace_fsm_state := sRE5
      }
    }
    is(sRE5) {
      when(pmem_writeback_ok) {
        replace_fsm_state := sRE0
      }
    }
  }

  when(inpmem_op && hit) {
    PLRU_bits(addr_index)(0) := hit_oh.asUInt()(1, 0).orR
    when(hit_oh.asUInt()(1, 0).orR) {
      PLRU_bits(addr_index)(1) := hit_oh.asUInt()(0)
    }.otherwise {
      PLRU_bits(addr_index)(2) := hit_oh.asUInt()(2)
    }
  }
  replace_state := into_replace_r || replace_fsm_state =/= sRE0
  replace_way := Mux(
    fencei_state,
    fencei_way,
    Cat(
      PLRU_bits(addr_index)(0),
      Mux(PLRU_bits(addr_index)(0), PLRU_bits(addr_index)(2), PLRU_bits(addr_index)(1))
    )
  )

  when(replace_state) {
    replace_addr := Cat(replace_tag, addr_index_r, 0.U(5.W))
  }
  when(replace_fsm_state === sRE1) {
    replace_buffer(0) := io.sram(replace_way_r).rdata(63, 0)
    replace_buffer(1) := io.sram(replace_way_r).rdata(127, 64)
  }.elsewhen(riseEdge(replace_fsm_state === sRE2)) {
    replace_buffer(2) := io.sram(replace_way_r).rdata(63, 0)
    replace_buffer(3) := io.sram(replace_way_r).rdata(127, 64)
  }

  // ********************************** Allocate信号 **********************************
  allocate_state := into_allocate_r || allocate_reg
  when(into_allocate_r) {
    allocate_reg := 1.B
  }.elsewhen(allocate_cnt === 3.U && pmem_read_ok) {
    allocate_reg := 0.B
  }
  when(allocate_state && pmem_read_ok) {
    allocate_cnt := allocate_cnt + 1.U
  }

  // ********************************** Output **********************************
  io.miss       := inpmem_miss || mmio_read || mmio_write || fencei_state
  io.out_rvalid := (hit && inpmem && io.ren) || mmio_read_ready

  when(RegNext(inpmem, 0.B)) {
    io.rdata := (io.sram(RegNext(hit_way, 0.U)).rdata >> RegNext(data_shift, 0.U))
  }.otherwise {
    io.rdata := pmem_rdata
  }

  // ********************************** Software PMU **********************************
  if (!tapeout && spmu_en) {
//    val write_valid_posedge = io.wen && !RegNext(io.wen, 0.B)
//    val read_valid_posedge  = io.ren && !RegNext(io.ren, 0.B)
    val dpi_cache_cnt = if (isICache) Module(new DpiICacheCnt) else Module(new DpiDCacheCnt)
    dpi_cache_cnt.io.clk   := clock
    dpi_cache_cnt.io.valid := io.in_valid && (io.wen || io.ren) && inpmem
    dpi_cache_cnt.io.miss  := inpmem_miss
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

class DpiDCacheCnt extends BlackBox {
  val io = IO(new Bundle {
    val clk   = Input(Clock())
    val valid = Input(Bool())
    val miss  = Input(Bool())
  })
}

class DpiICacheCnt extends BlackBox {
  val io = IO(new Bundle {
    val clk   = Input(Clock())
    val valid = Input(Bool())
    val miss  = Input(Bool())
  })
}

object DCache extends RVNoobConfig {
  def apply(isICache: Boolean, deviceId: Int = 0, sizeInKB: Double = 4): DCache = {
    val cacheSize: Int = (sizeInKB * pow(2, 10)).toInt
    val cache = Module(new DCache(isICache = isICache, deviceId = deviceId, cacheSize = cacheSize))
    if (isICache) {
      cache.io.wdata      := 0.U
      cache.io.wen        := 0.B
      cache.io.zero_ex_op := 2.U
//      cache.io.in_valid      := 1.B
      cache.io.fencei := 0.B
    } else {
      if (simplify_design) {
        cache.io.fencei := 0.B
      }
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
