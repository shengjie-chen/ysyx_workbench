package circuit_exp.Multiplexer

import chisel3._
class Multiplexer extends RawModule {
  val io = IO(new Bundle {
    val X = Input(Vec(4,UInt(2.W)))
    val Y = Input(UInt(2.W))
    val F = Output(UInt(2.W))
  })
  io.F := io.X(io.Y)
}
