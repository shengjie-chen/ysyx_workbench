package RVnpc.RVNoob

import chisel3._
class RVNoob extends Module {
  val io = IO(new Bundle {
    val pc     = Output(UInt(64.W))
    val inst   = Input(UInt(32.W))
    val res    = Output(UInt(64.W))
    val ebreak = Output(Bool())
//    override val prefix
  })
  val pc   = RegInit(0x80000000L.U(64.W)) //2147483648
  val snpc = Wire(UInt(64.W))

  val idu = Module(new IDU)
  val rf  = Module(new RegisterFile)
  val exe = Module(new EXE)

  snpc  := pc + 4.U
  pc    := Mux(idu.io.pc_mux, exe.io.dnpc, snpc)
  io.pc := pc

  idu.io.inst := io.inst

  rf.io.wen <> idu.io.wen
  rf.io.wdata <> exe.io.gp_out
  rf.io.waddr <> idu.io.rd
  rf.io.ren1 <> idu.io.ren1
  rf.io.ren2 <> idu.io.ren2
  rf.io.raddr1 <> idu.io.rs1
  rf.io.raddr2 <> idu.io.rs2

  exe.io.src1 <> rf.io.rdata1
  exe.io.src2 <> rf.io.rdata2
  exe.io.imm <> idu.io.imm
  exe.io.pc <> pc
  exe.io.snpc <> snpc
  exe.io.add_en <> idu.io.add_en
  exe.io.alu_src1_mux <> idu.io.alu_src1_mux
  exe.io.alu_src2_mux <> idu.io.alu_src2_mux
  exe.io.exe_out_mux <> idu.io.exe_out_mux
  exe.io.dnpc_mux <> idu.io.dnpc_mux
  exe.io.dnpc_0b0 <> idu.io.dnpc_0b0

  io.res <> exe.io.gp_out

  val U_ebreak = Module(new Ebreak)
  U_ebreak.io.inst <> io.inst
  U_ebreak.io.a0 <> rf.io.a0
  U_ebreak.io.ebreak <> io.ebreak
}

object RVNoobGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(args, Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new RVNoob())))
}
