package RVnpc.RVNoob

import RVnpc.RVNoob.Axi._
import RVnpc.RVNoob.Cache._
import RVnpc.RVNoob.Pipeline._
import chisel3._
import chisel3.util.BitPat.dontCare
import chisel3.util._

class RVNoobCore extends Module with ext_function with RVNoobConfig {
  val io = IO(new Bundle {
    val pc       = if (!tapeout) Some(Output(UInt(addr_w.W))) else None
    val ebreak   = if (!tapeout) Some(Output(Bool())) else None
    val diff_en  = if (!tapeout) Some(Output(Bool())) else None
    val diff_pc  = if (!tapeout) Some(Output(UInt(addr_w.W))) else None
    val axi_pc   = if (!tapeout) Some(Output(UInt(addr_w.W))) else None
    val inst_cnt = if (!tapeout) Some(Output(UInt(xlen.W))) else None

    val interrupt = Input(Bool())
    // >>>>>>>>>>>>>> AXI <<<<<<<<<<<<<<
    val master = new AxiIO
    val slave  = Flipped(new AxiIO)
    // >>>>>>>>>>>>>> Inst Cache Sram <<<<<<<<<<<<<<
    val sram0 = new CacheSramIO
    val sram1 = new CacheSramIO
    val sram2 = new CacheSramIO
    val sram3 = new CacheSramIO
    // >>>>>>>>>>>>>> Data Cache Sram <<<<<<<<<<<<<<
    val sram4 = new CacheSramIO
    val sram5 = new CacheSramIO
    val sram6 = new CacheSramIO
    val sram7 = new CacheSramIO

  })
  /* **********************************
   * 没有实现io_interrupt和Core顶层AXI4 slave口，将这些接口输出置零，输入悬空
   * ********************************* */
  dontTouch(io.interrupt)
  //  dontTouch(io.master)
  dontTouch(io.slave)
  io.slave.awready := 0.B
  io.slave.wready  := 0.B
  io.slave.bvalid  := 0.B
  io.slave.bresp   := 0.U
  io.slave.bid     := 0.U
  io.slave.arready := 0.B
  io.slave.rvalid  := 0.B
  io.slave.rresp   := 0.U
  io.slave.rdata   := 0.U
  io.slave.rlast   := 0.B
  io.slave.rid     := 0.U

  // ********************************** Instance **********************************
  // >>>>>>>>>>>>>> IF inst Fetch <<<<<<<<<<<<<<
  val dnpc_en = Wire(Bool())
  val dnpc    = Wire(UInt(addr_w.W))
  val snpc    = Wire(UInt(addr_w.W))
  val npc     = Wire(UInt(addr_w.W))
  if (!tapeout) { dontTouch(npc) }
  val pc_en = Wire(Bool())
  val pc =
    if (tapeout) RegEnable(npc, 0x30000000L.U(addr_w.W), pc_en)
    else RegEnable(npc, 0x80000000L.U(addr_w.W), pc_en) //2147483648

  // >>>>>>>>>>>>>> ID Inst Decode  id_reg <<<<<<<<<<<<<<
  val ppl_ctrl = Module(new PipelineCtrl)
  val icache   = DCache(isICache = true)
  //  val icache = Module(new ICache)
  val id_reg = IDreg(
    pc     = pc,
    inst   = icache.io.rdata,
    snpc   = snpc,
    reg_en = ppl_ctrl.io.id_reg_ctrl.en,
    valid  = icache.io.out_rvalid
  )
  val idu        = Module(new IDU)
  val rf         = Module(new RegisterFile)
  val csr        = Module(new CSR)
  val cache_miss = Wire(Bool())

  // >>>>>>>>>>>>>> EXE ex_reg <<<<<<<<<<<<<<
  val npc_add_res = Wire(UInt(addr_w.W))
  val ex_reg: EXreg = EXreg(
    pc          = id_reg.out.pc,
    inst        = id_reg.out.inst,
    snpc        = id_reg.out.snpc,
    src1        = Mux(idu.io.id_csr_ctrl.zimm_en, uext_64(idu.io.id_rf_ctrl.rs1), rf.io.rdata1),
    src2        = Mux(idu.io.id_csr_ctrl.csr_ren, csr.io.csr_rdata, rf.io.rdata2),
    imm         = idu.io.imm,
    csr_dnpc    = csr.io.csr_dnpc,
    exe_ctrl    = idu.io.exe_ctrl,
    mem_ctrl    = idu.io.mem_ctrl,
    wb_rf_ctrl  = idu.io.wb_rf_ctrl,
    wb_csr_ctrl = idu.io.wb_csr_ctrl,
    dnpc_ctrl   = idu.io.dnpc_ctrl,
    reg_en      = ppl_ctrl.io.ex_reg_ctrl.en,
    valid       = id_reg.out.inst_valid
  )
  val exe = Module(new EXE)
//  val exe_src1 = Wire(UInt(xlen.W))
  val exe_src2 = Wire(UInt(xlen.W))

  // >>>>>>>>>>>>>> MEM mem_reg <<<<<<<<<<<<<<
  val mem_reg: MEMreg = MEMreg(
    pc          = ex_reg.out.pc,
    inst        = ex_reg.out.inst,
    src2        = exe_src2,
    mem_addr    = exe.io.mem_addr,
    alu_res     = exe.io.gp_out,
    B_en        = exe.io.B_en,
    pc_mux      = ex_reg.out.dnpc_ctrl.pc_mux,
    mem_ctrl    = ex_reg.out.mem_ctrl,
    wb_rf_ctrl  = ex_reg.out.wb_rf_ctrl,
    wb_csr_ctrl = ex_reg.out.wb_csr_ctrl,
    reg_en      = ppl_ctrl.io.mem_reg_ctrl.en,
    valid       = ex_reg.out.inst_valid
  )
  val dcache       = DCache(isICache = false, deviceId = 1)
  val maxi         = Module(new AxiMaster)
  val axi_crossbar = Module(new AxiCrossBar)
  val clint        = Module(new Clint)

  // >>>>>>>>>>>>>> WB wb_reg <<<<<<<<<<<<<<
  val wb_reg = WBreg(
    pc          = mem_reg.out.pc,
    inst        = mem_reg.out.inst,
    src2        = mem_reg.out.src2,
    alu_res     = mem_reg.out.alu_res,
    mem_data    = dcache.io.rdata,
    mem_ctrl    = mem_reg.out.mem_ctrl,
    wb_rf_ctrl  = mem_reg.out.wb_rf_ctrl,
    wb_csr_ctrl = mem_reg.out.wb_csr_ctrl,
    reg_en      = ppl_ctrl.io.wb_reg_ctrl.en,
    valid       = mem_reg.out.inst_valid
  )
  val judge_load    = Module(new JudgeLoad)
  val not_csr_wdata = Wire(UInt(xlen.W))

  // ********************************** Connect and Logic **********************************
  // >>>>>>>>>>>>>> IF inst Fetch <<<<<<<<<<<<<<
  snpc    := pc + 4.U
  dnpc_en := ex_reg.out.dnpc_ctrl.pc_mux || exe.io.B_en
  pc_en   := ppl_ctrl.io.pc_en
  npc     := Mux(dnpc_en, dnpc, snpc)
  if (!tapeout) {
    io.pc.get := pc
    val dpi_npc = Module(new DpiNpc) // use to get npc in sim.c
    dpi_npc.io.npc <> npc
    if (spmu_en) {
      val dpi_branch_error = Module(new DpiBranchError)
      dpi_branch_error.io.clk   <> clock
      dpi_branch_error.io.valid <> dnpc_en
    }
  }

  icache.io.addr     <> pc
  icache.io.ren      <> !reset.asBool()
  icache.io.in_valid <> (RegNext(pc_en, 0.B) || (RegNext(reset.asBool(), 1.B) && !reset.asBool()))

  icache.io.sram(0) <> io.sram0
  icache.io.sram(1) <> io.sram1
  icache.io.sram(2) <> io.sram2
  icache.io.sram(3) <> io.sram3

  // >>>>>>>>>>>>>> ID Inst Decode  id_reg <<<<<<<<<<<<<<
  cache_miss := icache.io.miss || dcache.io.miss

  ppl_ctrl.io.idu_rf          <> idu.io.id_rf_ctrl
  ppl_ctrl.io.idu_csr         <> idu.io.id_csr_ctrl
  ppl_ctrl.io.ex_reg_rf       <> ex_reg.out.wb_rf_ctrl
  ppl_ctrl.io.ex_reg_csr      <> ex_reg.out.wb_csr_ctrl
  ppl_ctrl.io.ex_reg_mem_ctrl <> ex_reg.out.mem_ctrl
  ppl_ctrl.io.mem_reg_rf      <> mem_reg.out.wb_rf_ctrl
  ppl_ctrl.io.mem_reg_csr     <> mem_reg.out.wb_csr_ctrl
  ppl_ctrl.io.dnpc_en         <> dnpc_en
  ppl_ctrl.io.miss            <> (cache_miss || exe.io.waiting)

  id_reg.reset <> (ppl_ctrl.io.id_reg_ctrl.flush || reset.asBool())

  idu.io.inst <> id_reg.out.inst
  idu.io.intr <> clint.io.time_interrupt
  if (!tapeout && spmu_en) {
    idu.io.valid.get <> id_reg.out.inst_valid
  }

  rf.io.id_rf_ctrl <> idu.io.id_rf_ctrl

  csr.io.id_csr_ctrl <> idu.io.id_csr_ctrl

  // >>>>>>>>>>>>>> EXE ex_reg <<<<<<<<<<<<<<
  ex_reg.reset <> (ppl_ctrl.io.ex_reg_ctrl.flush || reset.asBool())

  dnpc := Mux(
    ex_reg.out.dnpc_ctrl.dnpc_csr,
    ex_reg.out.csr_dnpc,
    Mux(ex_reg.out.dnpc_ctrl.dnpc_jalr, Cat(npc_add_res(addr_w - 1, 1), 0.U(1.W)), npc_add_res)
  )

  npc_add_res := ex_reg.out.imm(addr_w - 1, 0) +
    Mux(ex_reg.out.dnpc_ctrl.dnpc_jalr, exe.io.src1(addr_w - 1, 0), ex_reg.out.pc)

  exe.io.src1 := MuxLookup(
    ppl_ctrl.io.forward1,
    ex_reg.out.src1,
    Array(1.U -> not_csr_wdata, 2.U -> mem_reg.out.alu_res)
  )
  exe_src2 := MuxLookup(
    ppl_ctrl.io.forward2,
    ex_reg.out.src2,
    Array(1.U -> not_csr_wdata, 2.U -> mem_reg.out.alu_res)
  )

  exe.io.src2 <> exe_src2

  exe.io.imm   <> ex_reg.out.imm
  exe.io.pc    <> ex_reg.out.pc
  exe.io.snpc  <> ex_reg.out.snpc
  exe.io.ctrl  <> ex_reg.out.exe_ctrl
  exe.io.valid <> ex_reg.out.valid

  // >>>>>>>>>>>>>> MEM mem_reg <<<<<<<<<<<<<<
  mem_reg.reset <> (ppl_ctrl.io.mem_reg_ctrl.flush || reset.asBool())

  dcache.io.addr       <> mem_reg.out.mem_addr
  dcache.io.ren        <> mem_reg.out.mem_ctrl.r_pmem
  dcache.io.wen        <> mem_reg.out.mem_ctrl.w_pmem
  dcache.io.wdata      <> mem_reg.out.src2
  dcache.io.zero_ex_op <> mem_reg.out.mem_ctrl.zero_ex_op
  if (!simplify_design) {
    dcache.io.fencei <> mem_reg.out.mem_ctrl.fencei
  }
  dcache.io.in_valid <> mem_reg.out.valid

  dcache.io.sram(0) <> io.sram4
  dcache.io.sram(1) <> io.sram5
  dcache.io.sram(2) <> io.sram6
  dcache.io.sram(3) <> io.sram7

  if (simplify_design) {
    axi_crossbar.in2.rctrl <> dcache.io.axi_rctrl
    axi_crossbar.in2.wctrl <> dcache.io.axi_wctrl

    dontCare(clint.io.wctrl)
    dontCare(clint.io.rctrl)
    dontCare(clint.io.mstatus_mie)
    dontCare(clint.io.mie_mtie)
    dontCare(clint.io.id_reg_pc)
    dontCare(clint.io.ex_csr_hazard)
    dontCare(clint.io.dnpc_en)
    dontCare(clint.io.cache_miss)
  } else {
    def axictrl_connect_zero(rctrl: AxiReadCtrlIO, wctrl: AxiWriteCtrlIO): Unit = {
      wctrl.en         := 0.U.asTypeOf(wctrl.en)
      wctrl.id         := 0.U.asTypeOf(wctrl.id)
      wctrl.size       := 0.U.asTypeOf(wctrl.size)
      wctrl.wbuf_ready := 0.U.asTypeOf(wctrl.wbuf_ready)
      wctrl.burst      := 0.U.asTypeOf(wctrl.burst)
      wctrl.addr       := 0.U.asTypeOf(wctrl.addr)
      wctrl.len        := 0.U.asTypeOf(wctrl.len)
      wctrl.data       := 0.U.asTypeOf(wctrl.data)
      wctrl.strb       := 0.U.asTypeOf(wctrl.strb)

      rctrl.en    := 0.U.asTypeOf(rctrl.en)
      rctrl.id    := 0.U.asTypeOf(rctrl.id)
      rctrl.size  := 0.U.asTypeOf(rctrl.size)
      rctrl.addr  := 0.U.asTypeOf(rctrl.addr)
      rctrl.burst := 0.U.asTypeOf(rctrl.burst)
      rctrl.len   := 0.U.asTypeOf(rctrl.len)
    }
    when(
      (dcache.io.axi_rctrl.addr(31, 28) === 0.U && dcache.io.axi_rctrl.en) ||
        (dcache.io.axi_wctrl.addr(31, 28) === 0.U && dcache.io.axi_wctrl.en)
    ) {
      clint.io.wctrl <> dcache.io.axi_wctrl
      clint.io.rctrl <> dcache.io.axi_rctrl
      axictrl_connect_zero(axi_crossbar.in2.rctrl, axi_crossbar.in2.wctrl)
    }.otherwise {
      axi_crossbar.in2.rctrl <> dcache.io.axi_rctrl
      axi_crossbar.in2.wctrl <> dcache.io.axi_wctrl
      axictrl_connect_zero(clint.io.rctrl, clint.io.wctrl)
    }

    clint.io.mstatus_mie   <> csr.io.mstatus_mie
    clint.io.mie_mtie      <> csr.io.mie_mtie
    clint.io.id_reg_pc     <> id_reg.out.pc
    clint.io.ex_csr_hazard <> ppl_ctrl.io.ex_csr_hazard
    clint.io.dnpc_en       <> dnpc_en
    clint.io.cache_miss    <> cache_miss
  }
  axi_crossbar.in1.rctrl <> icache.io.axi_rctrl
  axi_crossbar.in1.wctrl <> icache.io.axi_wctrl
  axi_crossbar.in1.pc    <> pc
  axi_crossbar.in2.pc    <> mem_reg.out.pc
  axi_crossbar.maxi.busy <> maxi.io.busy

  maxi.io.rctrl <> axi_crossbar.maxi.rctrl
  maxi.io.wctrl <> axi_crossbar.maxi.wctrl
  maxi.io.maxi  <> io.master

  if (!tapeout) {
    io.axi_pc.get <> axi_crossbar.maxi.pc
  }

  // >>>>>>>>>>>>>> WB wb_reg <<<<<<<<<<<<<<
  wb_reg.reset                <> (ppl_ctrl.io.wb_reg_ctrl.flush || reset.asBool())
  judge_load.io.judge_load_op <> wb_reg.out.mem_ctrl.judge_load_op
  judge_load.io.mem_data      <> wb_reg.out.mem_data
  not_csr_wdata               := Mux(wb_reg.out.mem_ctrl.r_pmem, judge_load.io.load_data, wb_reg.out.alu_res)
  rf.io.wdata <> Mux(
    wb_reg.out.wb_csr_ctrl.csr_wen,
    wb_reg.out.src2,
    not_csr_wdata
  )
  rf.io.wb_rf_ctrl <> wb_reg.out.wb_rf_ctrl

  csr.io.wb_csr_ctrl <> wb_reg.out.wb_csr_ctrl
  csr.io.pc          <> wb_reg.out.pc
  csr.io.csr_wdata   <> wb_reg.out.alu_res
  csr.io.wb_valid    <> wb_reg.out.valid

  // ********************************** other !tapeout **********************************
  if (!tapeout) {
    // >>>>>>>>>>>>>> ebreak <<<<<<<<<<<<<<
    val U_ebreak = DpiEbreak(clock, wb_reg.out.inst, ShiftRegister(rf.io.a0, 3, 1.B), io.ebreak.get)

    // >>>>>>>>>>>>>> ipc <<<<<<<<<<<<<<
    val inst_cnt = RegInit(0.U(xlen.W))
    inst_cnt        := inst_cnt + wb_reg.out.inst_valid.asUInt()
    io.inst_cnt.get := inst_cnt

    // >>>>>>>>>>>>>> Difftest <<<<<<<<<<<<<<
    val cache_miss_last_next = !cache_miss && RegNext(cache_miss)
    val cache_miss_first     = cache_miss && !RegNext(cache_miss)

    val diff_pc = RegInit(UInt(addr_w.W), 0x80000000L.U)

    // wb 写完成的周期
    //    io.diff_en := (RegNext(wb_reg.out.valid) || RegNext(cache_miss_last_next)) &&
    //    (ShiftRegister(wb_reg.out.inst, 1, 1.B) =/= 0.U) && (!cache_miss || cache_miss_first)
    io.diff_en.get := RegNext(wb_reg.out.valid)
    io.diff_pc.get := diff_pc
    when(wb_reg.out.valid) {
      when(mem_reg.out.valid) {
        diff_pc := mem_reg.out.pc
      }.elsewhen(ex_reg.out.valid) {
        diff_pc := ex_reg.out.pc
      }.elsewhen(id_reg.out.valid) {
        diff_pc := id_reg.out.pc
      }.otherwise {
        diff_pc := pc
      }
    }
  }

  override def desiredName = if (tapeout) ysyxid else getClassName

}

object RVNoobCore {
  def apply(): RVNoobCore = {
    val core = Module(new RVNoobCore)

    /* **********************************
     * 没有实现io_interrupt和Core顶层AXI4 slave口，将这些接口输出置零，输入悬空
     * ********************************* */
    core.io.interrupt := DontCare

    core.io.slave.awvalid := DontCare
    core.io.slave.awaddr  := DontCare
    core.io.slave.awid    := DontCare
    core.io.slave.awlen   := DontCare
    core.io.slave.awsize  := DontCare
    core.io.slave.awburst := DontCare
    core.io.slave.wvalid  := DontCare
    core.io.slave.wdata   := DontCare
    core.io.slave.wstrb   := DontCare
    core.io.slave.wlast   := DontCare
    core.io.slave.bready  := DontCare
    core.io.slave.arvalid := DontCare
    core.io.slave.araddr  := DontCare
    core.io.slave.arid    := DontCare
    core.io.slave.arlen   := DontCare
    core.io.slave.arsize  := DontCare
    core.io.slave.arburst := DontCare
    core.io.slave.rready  := DontCare

    core
  }
}

object RVNoobCoreGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/soc"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new RVNoobCore))
    )
}

class DpiNpc extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val npc = Input(UInt(64.W))
  })
  setInline(
    "DpiNpc.v",
    """
      |import "DPI-C" function void npc_change(input logic [63:0] a);
      |module DpiNpc(input [63:0] npc);
      |
      | always @* npc_change(npc);
      |
      |endmodule
            """.stripMargin
  )
}

class DpiBranchError extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val clk   = Input(Clock())
    val valid = Input(Bool())
  })
  setInline(
    "DpiBranchError.v",
    """
      |import "DPI-C" function void find_branch_error();
      |module DpiBranchError(input clk, input valid);
      |
      |always@(posedge clk) begin
      |    if(valid == 1'b1) begin
      |        find_branch_error();
      |    end
      |end
      |
      |endmodule
            """.stripMargin
  )
}
