package RVnpc.RVNoob

import chisel3._
import chisel3.util._
import Pipeline._

class RVNoob extends Module with ext_function {
  val io = IO(new Bundle {
    val pc     = Output(UInt(64.W))
    val inst   = Input(UInt(32.W))
    val ebreak = Output(Bool())
    //    override val prefix
  })

  val pipelineBypass: Boolean = false

  // ********************************** Instance **********************************
  // >>>>>>>>>>>>>> IF inst Fetch <<<<<<<<<<<<<<
  val dnpc_en = Wire(Bool())
  val flush   = Wire(Bool())
  val npc     = Wire(UInt(64.W))
  val pc      = RegEnable(npc, 0x80000000L.U(64.W), hazard.io.pc_en) //2147483648
  val snpc    = Wire(UInt(64.W))

  // >>>>>>>>>>>>>> ID Inst Decode  id_reg <<<<<<<<<<<<<<
  val id_reg = IDreg(pc, io.inst, snpc, hazard.io.id_reg_ctrl.en, pipelineBypass)
  val idu    = Module(new IDU)
  val rf     = Module(new RegisterFile)
  val csr    = Module(new CSR)
  lazy val hazard: HazardDetect = HazardDetect(
    idu.io.id_rf_ctrl,
    idu.io.id_csr_ctrl,
    ex_reg.out.wb_rf_ctrl,
    ex_reg.out.wb_csr_ctrl,
    mem_reg.out.wb_rf_ctrl,
    mem_reg.out.wb_csr_ctrl,
    dnpc_en
  )

  // >>>>>>>>>>>>>> EXE ex_reg <<<<<<<<<<<<<<
  val dnpc_t      = Wire(UInt(64.W))
  val npc_add_res = Wire(UInt(64.W))
  lazy val ex_reg: EXreg = EXreg(
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
  lazy val mem_reg: MEMreg = MEMreg(
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

  // ********************************** Connect and Logic **********************************
  // >>>>>>>>>>>>>> IF inst Fetch <<<<<<<<<<<<<<
  snpc    := pc + 4.U
  dnpc_en := mem_reg.out.pc_mux || mem_reg.out.B_en
  flush   := dnpc_en
  npc     := Mux(dnpc_en, mem_reg.out.dnpc, snpc)
  pc      := npc
  io.pc   := pc
  val dpi_npc = Module(new DpiNpc) // use to get npc in sim.c
  dpi_npc.io.npc <> npc

  // >>>>>>>>>>>>>> ID Inst Decode  id_reg <<<<<<<<<<<<<<
  id_reg.reset <> hazard.io.id_reg_ctrl.flush

  idu.io.inst := id_reg.out.inst

  rf.io.id_rf_ctrl <> idu.io.id_rf_ctrl

  csr.io.id_csr_ctrl <> idu.io.id_csr_ctrl

  val U_ebreak = Module(new Ebreak)
  U_ebreak.io.clk <> clock
  U_ebreak.io.inst <> id_reg.out.inst
  U_ebreak.io.a0 <> rf.io.a0
  U_ebreak.io.ebreak <> io.ebreak

  // >>>>>>>>>>>>>> EXE ex_reg <<<<<<<<<<<<<<
  ex_reg.reset <> hazard.io.ex_reg_ctrl.flush

  dnpc_t := Mux(
    ex_reg.out.dnpc_ctrl.dnpc_csr,
    ex_reg.out.csr_dnpc,
    Mux(ex_reg.out.dnpc_ctrl.dnpc_jalr, Cat(npc_add_res(63, 1), 0.U(1.W)), npc_add_res)
  )

  npc_add_res := ex_reg.out.imm +
    Mux(ex_reg.out.dnpc_ctrl.dnpc_jalr, ex_reg.out.src1, ex_reg.out.pc)

  exe.io.src1 <> ex_reg.out.src1
  exe.io.src2 <> ex_reg.out.src2
  exe.io.imm <> ex_reg.out.imm
  exe.io.pc <> ex_reg.out.pc
  exe.io.snpc <> ex_reg.out.snpc
  exe.io.ctrl <> ex_reg.out.exe_ctrl

  // >>>>>>>>>>>>>> MEM mem_reg <<<<<<<<<<<<<<
  mem_reg.reset <> hazard.io.mem_reg_ctrl.flush

  datam.io.mem_ctrl <> mem_reg.out.mem_ctrl
  datam.io.wdata <> mem_reg.out.src2
  datam.io.data_addr <> mem_reg.out.mem_addr

  judge_load.io.judge_load_op <> mem_reg.out.mem_ctrl.judge_load_op
  judge_load.io.mem_data <> datam.io.rdata

  // >>>>>>>>>>>>>> WB wb_reg <<<<<<<<<<<<<<
  wb_reg.reset <> hazard.io.wb_reg_ctrl.flush
  rf.io.wdata <> Mux(
    wb_reg.out.wb_csr_ctrl.csr_wen,
    wb_reg.out.src2,
    Mux(wb_reg.out.r_pmem, wb_reg.out.mem_data, wb_reg.out.alu_res)
  )
  rf.io.wb_rf_ctrl <> wb_reg.out.wb_rf_ctrl

  csr.io.wb_csr_ctrl <> wb_reg.out.wb_csr_ctrl
  csr.io.pc <> wb_reg.out.pc
  csr.io.mcause <> 11.U
  csr.io.csr_wdata <> wb_reg.out.alu_res

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
