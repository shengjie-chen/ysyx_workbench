package RVnpc.RVNoob

import chisel3._
import chisel3.util._
class RVNoob extends Module {
  val io = IO(new Bundle {
    val pc     = Output(UInt(64.W))
    val inst   = Input(UInt(32.W))
    val ebreak = Output(Bool())
//    override val prefix
  })
  val pc          = RegInit(0x80000000L.U(64.W)) //2147483648
  val snpc        = Wire(UInt(64.W))
  val dnpc        = Wire(UInt(64.W))
  val npc_add_res = Wire(UInt(64.W))

  val id_reg = IDreg(pc,io.inst,snpc)
  val idu = Module(new IDU)
  val rf  = Module(new RegisterFile)
  val csr = Module(new CSR)

  val ex_reg = EXreg(
    id_reg.out.pc,id_reg.out.inst,id_reg.out.snpc,
    rf.io.rdata1,rf.io.rdata2,idu.io.imm,
    idu.io.exe_ctrl,idu.io.pmem_ctrl,idu.io.rfwb_ctrl,idu.io.dnpc_jalr,idu.io.pc_mux)
  val exe = Module(new EXE)

  val mem_reg = MEMreg(ex_reg.out.pc,ex_reg.out.inst,dnpc,ex_reg.out.src2,
    exe.io.mem_addr,exe.io.gp_out,exe.io.B_en,ex_reg.out.pmem_ctrl,ex_reg.out.rfwb_ctrl)
  val datam = Module(new DATAM)
  val judge_load = Module(new JudgeLoad)

  val wb_reg = WBreg(mem_reg.out.pc,mem_reg.out.inst,
    mem_reg.out.alu_res,judge_load.io.load_data,mem_reg.out.pmem_ctrl.r_pmem,mem_reg.out.rfwb_ctrl)

  npc_add_res := Mux(idu.io.dnpc_jalr, rf.io.rdata1, pc) + idu.io.imm
  snpc        := pc + 4.U
  dnpc := Mux(
    (idu.io.csr_ctrl.ecall || idu.io.csr_ctrl.mret),
    csr.io.csr_dnpc,
    Mux(idu.io.dnpc_jalr, Cat(npc_add_res(63, 1), 0.U(1.W)), npc_add_res)
  )
  pc    := Mux(idu.io.pc_mux || exe.io.B_en, dnpc, snpc)
  io.pc := pc
  val dpi_npc = Module(new DpiNpc)
  dpi_npc.io.npc <> Mux(idu.io.pc_mux || exe.io.B_en, dnpc, snpc)

  // ID Inst Decode  id_reg
  idu.io.inst := id_reg.out.inst

  rf.io.ren1 <> idu.io.ren1
  rf.io.ren2 <> idu.io.ren2
  rf.io.rs1 <> idu.io.rs1
  rf.io.rs2 <> idu.io.rs2
  rf.io.csr_rdata <> csr.io.csr_rdata
  rf.io.csr_en <> idu.io.csr_ctrl.csr_en

  csr.io.csr_ctrl <> idu.io.csr_ctrl
  csr.io.pc <> pc
  csr.io.csr_addr <> idu.io.imm(11, 0)
  csr.io.mcause <> 11.U
  csr.io.zimm <> idu.io.rs1
  csr.io.rdata1 <> rf.io.rdata1
  csr.io.dest_rdata <> rf.io.dest_rdata

  // EXE ex_reg

  exe.io.src1 <> ex_reg.out.src1
  exe.io.src2 <> ex_reg.out.src2
  exe.io.imm <> ex_reg.out.imm
  exe.io.pc <> ex_reg.out.pc
  exe.io.snpc <> ex_reg.out.snpc
  exe.io.ctrl <> ex_reg.out.exe_ctrl

  // MEM mem_reg

  datam.io.pmem_ctrl <> mem_reg.out.pmem_ctrl
  datam.io.wdata <> mem_reg.out.src2
  datam.io.data_addr <> mem_reg.out.mem_addr

  judge_load.io.judge_load_op <> mem_reg.out.pmem_ctrl.judge_load_op
  judge_load.io.mem_data <> datam.io.rdata

  // WB wb_reg
  rf.io.wdata <> Mux(idu.io.pmem_ctrl.r_pmem,judge_load.io.load_data,exe.io.gp_out)
  rf.io.rfwb_ctrl <> wb_reg.out.rfwb_ctrl

  val U_ebreak = Module(new Ebreak)
  U_ebreak.io.clk <> clock
  U_ebreak.io.inst <> io.inst
  U_ebreak.io.a0 <> rf.io.a0
  U_ebreak.io.ebreak <> io.ebreak
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
