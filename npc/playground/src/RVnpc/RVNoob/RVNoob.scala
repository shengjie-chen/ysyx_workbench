package RVnpc.RVNoob

import chisel3._
import chisel3.util._
class RVNoob extends Module {
  val io = IO(new Bundle {
    val pc     = Output(UInt(64.W))
    val inst   = Input(UInt(32.W))
    val res    = Output(UInt(64.W))
    val ebreak = Output(Bool())
//    override val prefix
  })
  val pc          = RegInit(0x80000000L.U(64.W)) //2147483648
  val snpc        = Wire(UInt(64.W))
  val dnpc        = Wire(UInt(64.W))
  val npc_add_res = Wire(UInt(64.W))

  val ifm = Module(new IFM)
  val idu = Module(new IDU)
  val rf  = Module(new RegisterFile)
  val exe = Module(new EXE)
  val csr = Module(new CSR)
  val judge_load = Module(new JudgeLoad)

  npc_add_res := Mux(idu.io.dnpc_jalr, rf.io.rdata1, pc) + idu.io.imm
  snpc        := pc + 4.U
  dnpc := Mux(
    (idu.io.csr_ctrl.ecall || idu.io.csr_ctrl.mret),
    Mux(idu.io.csr_ctrl.mret,csr.io.mepc,csr.io.mtvec),
    Mux(idu.io.dnpc_jalr, Cat(npc_add_res(63, 1), 0.U(1.W)), npc_add_res)
  )
  pc    := Mux(idu.io.pc_mux || exe.io.B_en, dnpc, snpc)
  io.pc := pc
  val dpi_npc = Module(new DpiNpc)
  dpi_npc.io.npc <> Mux(idu.io.pc_mux || exe.io.B_en, dnpc, snpc)

  ifm.io.pmem_ctrl <> idu.io.pmem_ctrl
  ifm.io.wdata <> rf.io.rdata2
  ifm.io.data_addr <> exe.io.mem_addr

  idu.io.inst := io.inst

  rf.io.wen <> idu.io.wen
  rf.io.wdata <> Mux(idu.io.pmem_ctrl.r_pmem,judge_load.io.load_data,exe.io.gp_out)
  rf.io.waddr <> idu.io.rd
  rf.io.ren1 <> idu.io.ren1
  rf.io.ren2 <> idu.io.ren2
  rf.io.raddr1 <> idu.io.rs1
  rf.io.raddr2 <> idu.io.rs2
  rf.io.csr_rdata <> csr.io.csr_rdata
  rf.io.csr_en <> idu.io.csr_ctrl.csr_en

  exe.io.src1 <> rf.io.rdata1
  exe.io.src2 <> rf.io.rdata2
  exe.io.imm <> idu.io.imm
  exe.io.pc <> pc
  exe.io.snpc <> snpc
  exe.io.ctrl <> idu.io.exe_ctrl

  csr.io.csr_ctrl <> idu.io.csr_ctrl
  csr.io.pc <> pc
  csr.io.csr_addr <> idu.io.imm(11, 0)
  csr.io.mcause <> 11.U
  csr.io.zimm <> idu.io.rs1
  csr.io.rdata1 <> rf.io.rdata1
  csr.io.dest_rdata <> rf.io.dest_rdata

  judge_load.io.judge_load_op <> idu.io.judge_load_op
  judge_load.io.mem_data <> ifm.io.rdata

  io.res <> exe.io.gp_out

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
