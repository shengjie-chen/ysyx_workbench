import Chisel.MuxCase
import chisel3._
import chisel3.util.{MuxLookup, PriorityEncoder}

class PriorEncoder extends RawModule {
  val io = IO(new Bundle {
    val in = Input(UInt(8.W))
    val out = Output(UInt(3.W))
    val in_valid = Output(Bool())
    val seg = Output(UInt(8.W))
  })

  io.in_valid := io.in.orR()
  io.out := PriorityEncoder(io.in)
  when(io.in_valid){
    io.seg := MuxLookup(io.out, "b00111111".U, Array(
      0.U -> "b11111101".U,
      1.U -> "b11111101".U,
      2.U -> "b11111101".U,
      3.U -> "b11111101".U,
      4.U -> "b11111101".U,
      5.U -> "b11111101".U,
      6.U -> "b11111101".U,
      7.U -> "b11111101".U,
      0.U -> "b11111101".U
    ))
  }.otherwise{
    io.seg := "b00111111".U
  }


}