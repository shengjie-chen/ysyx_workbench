package RVnpc.RVNoob

import chisel3._
import chisel3.util._

class IDU extends Module {
  val io = IO(new Bundle {
    val inst   = Input(UInt(32.W))
    val add_en = Output(Bool())
    val wen    = Output(Bool())
    val rd     = Output(UInt(5.W))
    val ren1   = Output(Bool())
    val ren2   = Output(Bool())
    val rs1    = Output(UInt(5.W))
    val rs2    = Output(UInt(5.W))
    val imm    = Output(UInt(64.W))
  })
  val opcode = Wire(UInt(7.W))
  val fun3   = Wire(UInt(3.W))
  opcode := io.inst(6, 0)
  fun3   := io.inst(14, 12)

  io.rd  := io.inst(11, 7)
  io.rs1 := io.inst(19, 15)
  io.rs2 := io.inst(24, 20)
  io.imm := Cat(VecInit(Seq.fill(64 - 12)(io.inst(31))).asUInt(), io.inst(31, 20))

  io.add_en := Mux(opcode === "b0010011".U, Mux(fun3 === "b000".U, 1.B, 0.B), 0.B)
  io.wen    := Mux(opcode === "b0010011".U, Mux(fun3 === "b000".U, 1.B, 0.B), 0.B)
  io.ren1   := Mux(opcode === "b0010011".U, Mux(fun3 === "b000".U, 1.B, 0.B), 0.B)
  io.ren2   := Mux(opcode === "b0010011".U, Mux(fun3 === "b000".U, 0.B, 0.B), 0.B)

}
