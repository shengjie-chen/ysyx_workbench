package RVnpc.RVNoob

import chisel3._
import chisel3.util._
import Pipeline._

class RVNoob(pipeline: Boolean = true) extends Module with ext_function with RVNoobConfig {
  val io = IO(new Bundle {
    val pc      = Output(UInt(64.W))
    val inst    = Input(UInt(32.W))
    val ebreak  = Output(Bool())
    val diff_en = Output(Bool())
    val diff_pc = Output(UInt(64.W))
    //    override val prefix
  })

  val pipelineBypass: Boolean = !pipeline

  // ********************************** Instance **********************************
  // >>>>>>>>>>>>>> IF inst Fetch <<<<<<<<<<<<<<
  val dnpc_en = Wire(Bool())
  val npc     = Wire(UInt(64.W))
  dontTouch(npc)
  val pc_en = Wire(Bool())
  val pc    = RegEnable(npc, 0x80000000L.U(64.W), pc_en) //2147483648
  val snpc  = Wire(UInt(64.W))

  // >>>>>>>>>>>>>> ID Inst Decode  id_reg <<<<<<<<<<<<<<
  val hazard = Module(new HazardDetect)
  val id_reg = IDreg(pc, io.inst, snpc, hazard.io.id_reg_ctrl.en, pipelineBypass)
  val idu    = Module(new IDU)
  val rf     = Module(new RegisterFile)
  val csr    = Module(new CSR)

  // >>>>>>>>>>>>>> EXE ex_reg <<<<<<<<<<<<<<
  val dnpc_t      = Wire(UInt(64.W))
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
    hazard.io.ex_reg_ctrl.en,
    pipelineBypass
  )
  val exe = Module(new EXE)

  // >>>>>>>>>>>>>> MEM mem_reg <<<<<<<<<<<<<<
  val mem_reg: MEMreg = MEMreg(
    ex_reg.out.pc,
    ex_reg.out.inst,
    dnpc_t,
    ex_reg.out.src2,
    exe.io.mem_addr,
    exe.io.gp_out,
    exe.io.B_en,
    ex_reg.out.dnpc_ctrl.pc_mux,
    ex_reg.out.mem_ctrl,
    ex_reg.out.wb_rf_ctrl,
    ex_reg.out.wb_csr_ctrl,
    hazard.io.mem_reg_ctrl.en,
    pipelineBypass
  )
  val datam      = Module(new DATAM)
  val judge_load = Module(new JudgeLoad)

  // >>>>>>>>>>>>>> WB wb_reg <<<<<<<<<<<<<<
  val wb_reg = WBreg(
    mem_reg.out.pc,
    mem_reg.out.inst,
    mem_reg.out.src2,
    mem_reg.out.alu_res,
    judge_load.io.load_data,
    mem_reg.out.mem_ctrl.r_pmem,
    mem_reg.out.wb_rf_ctrl,
    mem_reg.out.wb_csr_ctrl,
    hazard.io.wb_reg_ctrl.en,
    pipelineBypass
  )
  val not_csr_wdata = Wire(UInt(xlen.W))
  val U_ebreak      = Ebreak(clock, wb_reg.out.inst, ShiftRegister(rf.io.a0, 3, 1.B), io.ebreak)

  // ********************************** Connect and Logic **********************************
  // >>>>>>>>>>>>>> IF inst Fetch <<<<<<<<<<<<<<
  snpc    := pc + 4.U
  dnpc_en := mem_reg.out.pc_mux || mem_reg.out.B_en
  pc_en   := hazard.io.pc_en
  npc     := Mux(dnpc_en, mem_reg.out.dnpc, snpc)
  io.pc   := pc
  val dpi_npc = Module(new DpiNpc) // use to get npc in sim.c
  dpi_npc.io.npc <> npc

  // >>>>>>>>>>>>>> ID Inst Decode  id_reg <<<<<<<<<<<<<<

  hazard.io.idu_rf          <> idu.io.id_rf_ctrl
  hazard.io.idu_csr         <> idu.io.id_csr_ctrl
  hazard.io.ex_reg_rf       <> ex_reg.out.wb_rf_ctrl
  hazard.io.ex_reg_csr      <> ex_reg.out.wb_csr_ctrl
  hazard.io.ex_reg_mem_ctrl <> ex_reg.out.mem_ctrl
  hazard.io.mem_reg_rf      <> mem_reg.out.wb_rf_ctrl
  hazard.io.mem_reg_csr     <> mem_reg.out.wb_csr_ctrl
  hazard.io.dnpc_en         <> dnpc_en

  id_reg.reset <> hazard.io.id_reg_ctrl.flush

  idu.io.inst <> id_reg.out.inst

  rf.io.id_rf_ctrl <> idu.io.id_rf_ctrl

  csr.io.id_csr_ctrl <> idu.io.id_csr_ctrl

  // >>>>>>>>>>>>>> EXE ex_reg <<<<<<<<<<<<<<
  ex_reg.reset <> hazard.io.ex_reg_ctrl.flush

  dnpc_t := Mux(
    ex_reg.out.dnpc_ctrl.dnpc_csr,
    ex_reg.out.csr_dnpc,
    Mux(ex_reg.out.dnpc_ctrl.dnpc_jalr, Cat(npc_add_res(63, 1), 0.U(1.W)), npc_add_res)
  )

  npc_add_res := ex_reg.out.imm +
    Mux(ex_reg.out.dnpc_ctrl.dnpc_jalr, ex_reg.out.src1, ex_reg.out.pc)

  if (pipeline) {
    exe.io.src1 <> MuxLookup(
      hazard.io.forward1,
      ex_reg.out.src1,
      Array(1.U -> not_csr_wdata, 2.U -> mem_reg.out.alu_res)
    )
    exe.io.src2 <> MuxLookup(
      hazard.io.forward2,
      ex_reg.out.src2,
      Array(1.U -> not_csr_wdata, 2.U -> mem_reg.out.alu_res)
    )
  } else {
    exe.io.src1 <> ex_reg.out.src1
    exe.io.src2 <> ex_reg.out.src2
  }
  exe.io.imm  <> ex_reg.out.imm
  exe.io.pc   <> ex_reg.out.pc
  exe.io.snpc <> ex_reg.out.snpc
  exe.io.ctrl <> ex_reg.out.exe_ctrl

  // >>>>>>>>>>>>>> MEM mem_reg <<<<<<<<<<<<<<
  mem_reg.reset <> hazard.io.mem_reg_ctrl.flush

  datam.io.mem_ctrl  <> mem_reg.out.mem_ctrl
  datam.io.wdata     <> mem_reg.out.src2
  datam.io.data_addr <> mem_reg.out.mem_addr

  judge_load.io.judge_load_op <> mem_reg.out.mem_ctrl.judge_load_op
  judge_load.io.mem_data      <> datam.io.rdata

  // >>>>>>>>>>>>>> WB wb_reg <<<<<<<<<<<<<<
  wb_reg.reset  <> hazard.io.wb_reg_ctrl.flush
  not_csr_wdata := Mux(wb_reg.out.r_pmem, wb_reg.out.mem_data, wb_reg.out.alu_res)
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
  if (pipeline) {
    // wb 写完成的周期
    io.diff_en := ShiftRegister(wb_reg.in.reg_en, 2, 1.B) && (ShiftRegister(wb_reg.out.inst, 1, 1.B) =/= 0.U)
    when(ShiftRegister(mem_reg.out.pc, 1, 1.B) =/= 0.U) {
      io.diff_pc := ShiftRegister(mem_reg.out.pc, 1, 1.B)
    }.elsewhen(ShiftRegister(dnpc_en, 2, 1.B)) {
      io.diff_pc := ShiftRegister(pc, 1, 1.B)
    }.otherwise {
      io.diff_pc := ShiftRegister(id_reg.out.pc, 1, 1.B)
    }
  }
}

object RVNoobGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(args, Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new RVNoob())))
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
