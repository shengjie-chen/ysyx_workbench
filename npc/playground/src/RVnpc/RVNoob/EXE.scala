package RVnpc.RVNoob

import chisel3._
import chisel3.util.Cat

class EXE extends Module {
  val io = IO(new Bundle {
    val src1 = Input(UInt(64.W))
    val src2 = Input(UInt(64.W))
    val imm = Input(UInt(64.W))

    val pc   = Input(UInt(64.W))
    val snpc = Input(UInt(64.W))

    val gp_out = Output(UInt(64.W))
    val dnpc = Output(UInt(64.W))
    //control
    val add_en       = Input(Bool())
    val alu_src1_mux = Input(Bool())
    val alu_src2_mux = Input(Bool())
    val exe_out_mux  = Input(Bool())
    val dnpc_mux     = Input(Bool())
    val dnpc_0b0     = Input(Bool())
  })
  val alu_src1 = Wire(UInt(64.W))
  val alu_src2 = Wire(UInt(64.W))
  val alu_out  = Wire(UInt(64.W))
  alu_src1 := Mux(io.alu_src1_mux, io.src1, io.pc)
  alu_src2 := Mux(io.alu_src2_mux, io.src2, io.imm)
  alu_out  := Mux(io.add_en, alu_src1 + alu_src2, 0.U)

  io.dnpc := Mux(io.dnpc_mux,Cat(alu_out(63, 1), Mux(io.dnpc_0b0,0.U(1.W),alu_out(0))),alu_src2)
  io.gp_out := Mux(io.exe_out_mux, io.snpc, alu_out)
}
