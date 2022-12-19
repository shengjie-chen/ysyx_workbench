package RVnpc.RVNoob

import RVnpc.RVNoob.Axi.AXIIO
import RVnpc.RVNoob.Cache.{CacheSramIO, DCache, JudgeLoad}
import RVnpc.RVNoob.Pipeline.{EXreg, IDreg, MEMreg, PipelineCtrl, WBreg}
import chisel3._
import chisel3.util.{Cat, HasBlackBoxInline, MuxLookup, RegEnable, ShiftRegister}

class RVNoobCore extends Module with ext_function with RVNoobConfig {
  val io = IO(new Bundle {
    val pc      = Output(UInt(64.W))
    val ebreak  = Output(Bool())
    val diff_en = Output(Bool())
    val diff_pc = Output(UInt(64.W))

    val interrupt = Input(Bool())
    // >>>>>>>>>>>>>> AXI <<<<<<<<<<<<<<
    //    val master = new AXIIO
    val slave = Flipped(new AXIIO)
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
  io.slave.rready  := 0.B

  // ********************************** Instance **********************************
  // >>>>>>>>>>>>>> IF inst Fetch <<<<<<<<<<<<<<
  val dnpc_en = Wire(Bool())
  val npc     = Wire(UInt(64.W))
  dontTouch(npc)
  val pc_en  = Wire(Bool())
  val pc     = RegEnable(npc, 0x80000000L.U(64.W), pc_en) //2147483648
  val snpc   = Wire(UInt(64.W))
  val icache = DCache(true)
  //  val icache = Module(new ICache)

  // >>>>>>>>>>>>>> ID Inst Decode  id_reg <<<<<<<<<<<<<<
  val ppl_ctrl   = Module(new PipelineCtrl)
  val id_reg     = IDreg(pc, icache.io.rdata, snpc, ppl_ctrl.io.id_reg_ctrl.en)
  val idu        = Module(new IDU)
  val rf         = Module(new RegisterFile)
  val csr        = Module(new CSR)
  val cache_miss = Wire(Bool())

  // >>>>>>>>>>>>>> EXE ex_reg <<<<<<<<<<<<<<
  val dnpc        = Wire(UInt(64.W))
  val npc_add_res = Wire(UInt(64.W))
  val ex_reg: EXreg = EXreg(
    id_reg.out.pc,
    id_reg.out.inst,
    id_reg.out.snpc,
    Mux(idu.io.id_csr_ctrl.zimm_en, uext_64(idu.io.id_rf_ctrl.rs1), rf.io.rdata1),
    Mux(idu.io.id_csr_ctrl.csr_ren, csr.io.csr_rdata, rf.io.rdata2),
    idu.io.imm,
    csr.io.csr_dnpc,
    idu.io.exe_ctrl,
    idu.io.mem_ctrl,
    idu.io.wb_rf_ctrl,
    idu.io.wb_csr_ctrl,
    idu.io.dnpc_ctrl,
    ppl_ctrl.io.ex_reg_ctrl.en
  )
  val exe      = Module(new EXE)
  val exe_src1 = Wire(UInt(xlen.W))
  val exe_src2 = Wire(UInt(xlen.W))

  // >>>>>>>>>>>>>> MEM mem_reg <<<<<<<<<<<<<<
  val mem_reg: MEMreg = MEMreg(
    ex_reg.out.pc,
    ex_reg.out.inst,
    exe_src2,
    exe.io.mem_addr,
    exe.io.gp_out,
    exe.io.B_en,
    ex_reg.out.dnpc_ctrl.pc_mux,
    ex_reg.out.mem_ctrl,
    ex_reg.out.wb_rf_ctrl,
    ex_reg.out.wb_csr_ctrl,
    ppl_ctrl.io.mem_reg_ctrl.en
  )
  val dcache = Module(new DCache)

  // >>>>>>>>>>>>>> WB wb_reg <<<<<<<<<<<<<<
  val wb_reg = WBreg(
    mem_reg.out.pc,
    mem_reg.out.inst,
    mem_reg.out.src2,
    mem_reg.out.alu_res,
    dcache.io.rdata,
    mem_reg.out.mem_ctrl,
    mem_reg.out.wb_rf_ctrl,
    mem_reg.out.wb_csr_ctrl,
    ppl_ctrl.io.wb_reg_ctrl.en
  )
  val judge_load    = Module(new JudgeLoad)
  val not_csr_wdata = Wire(UInt(xlen.W))
  val U_ebreak      = Ebreak(clock, wb_reg.out.inst, ShiftRegister(rf.io.a0, 3, 1.B), io.ebreak)

  // ********************************** Connect and Logic **********************************
  // >>>>>>>>>>>>>> IF inst Fetch <<<<<<<<<<<<<<
  snpc    := pc + 4.U
  dnpc_en := ex_reg.out.dnpc_ctrl.pc_mux || exe.io.B_en
  pc_en   := ppl_ctrl.io.pc_en
  npc     := Mux(dnpc_en, dnpc, snpc)
  io.pc   := pc
  val dpi_npc = Module(new DpiNpc) // use to get npc in sim.c
  dpi_npc.io.npc <> npc

  icache.io.addr    <> pc
  icache.io.ren     <> !reset.asBool()
  icache.io.pc      <> pc
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
  ppl_ctrl.io.miss            <> cache_miss

  id_reg.reset <> (ppl_ctrl.io.id_reg_ctrl.flush || reset.asBool())

  idu.io.inst <> id_reg.out.inst

  rf.io.id_rf_ctrl <> idu.io.id_rf_ctrl

  csr.io.id_csr_ctrl <> idu.io.id_csr_ctrl

  // >>>>>>>>>>>>>> EXE ex_reg <<<<<<<<<<<<<<
  ex_reg.reset <> (ppl_ctrl.io.ex_reg_ctrl.flush || reset.asBool())

  dnpc := Mux(
    ex_reg.out.dnpc_ctrl.dnpc_csr,
    ex_reg.out.csr_dnpc,
    Mux(ex_reg.out.dnpc_ctrl.dnpc_jalr, Cat(npc_add_res(63, 1), 0.U(1.W)), npc_add_res)
  )

  npc_add_res := ex_reg.out.imm +
    Mux(ex_reg.out.dnpc_ctrl.dnpc_jalr, exe_src1, ex_reg.out.pc)

  exe_src1 := MuxLookup(
    ppl_ctrl.io.forward1,
    ex_reg.out.src1,
    Array(1.U -> not_csr_wdata, 2.U -> mem_reg.out.alu_res)
  )
  exe_src2 := MuxLookup(
    ppl_ctrl.io.forward2,
    ex_reg.out.src2,
    Array(1.U -> not_csr_wdata, 2.U -> mem_reg.out.alu_res)
  )

  exe.io.src1 <> exe_src1
  exe.io.src2 <> exe_src2

  exe.io.imm  <> ex_reg.out.imm
  exe.io.pc   <> ex_reg.out.pc
  exe.io.snpc <> ex_reg.out.snpc
  exe.io.ctrl <> ex_reg.out.exe_ctrl

  // >>>>>>>>>>>>>> MEM mem_reg <<<<<<<<<<<<<<
  mem_reg.reset <> (ppl_ctrl.io.mem_reg_ctrl.flush || reset.asBool())

  dcache.io.addr  <> mem_reg.out.mem_addr
  dcache.io.wdata <> mem_reg.out.src2

  dcache.io.ren        <> mem_reg.out.mem_ctrl.r_pmem
  dcache.io.wen        <> mem_reg.out.mem_ctrl.w_pmem
  dcache.io.zero_ex_op <> mem_reg.out.mem_ctrl.zero_ex_op
  dcache.io.valid      <> mem_reg.out.valid

  dcache.io.pc <> mem_reg.out.pc

  dcache.io.sram(0) <> io.sram4
  dcache.io.sram(1) <> io.sram5
  dcache.io.sram(2) <> io.sram6
  dcache.io.sram(3) <> io.sram7

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
  csr.io.mcause      <> 11.U
  csr.io.csr_wdata   <> wb_reg.out.alu_res

  // ********************************** Difftest **********************************
  val cache_miss_last_next = !cache_miss && RegNext(cache_miss)
  val cache_miss_first     = cache_miss && !RegNext(cache_miss)

  val diff_pc = Reg(UInt(64.W))

  // wb 写完成的周期
  //    io.diff_en := (RegNext(wb_reg.out.valid) || RegNext(cache_miss_last_next)) &&
  //    (ShiftRegister(wb_reg.out.inst, 1, 1.B) =/= 0.U) && (!cache_miss || cache_miss_first)
  io.diff_en := RegNext(wb_reg.out.valid)
  io.diff_pc := diff_pc
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

  //    when(wb_reg.out.pc =/= 0.U) {
  //      io.diff_pc := wb_reg.out.pc
  //    }.elsewhen(ShiftRegister(dnpc_en, 3, 1.B)) {
  //      io.diff_pc := ShiftRegister(pc, 2, 1.B)
  //    }.elsewhen(mem_reg.out.pc =/= 0.U) {
  //      io.diff_pc := mem_reg.out.pc
  //    }.otherwise {
  //      io.diff_pc := ex_reg.out.pc
  //    }
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
    core.io.slave.rvalid  := DontCare
    core.io.slave.rdata   := DontCare
    core.io.slave.rstrb   := DontCare
    core.io.slave.rlast   := DontCare

    core
  }
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
