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
  when(io.in(7)) {
    io.out := 7.U
  }.elsewhen(io.in(6)) {
    io.out := 6.U
  }.elsewhen(io.in(5)) {
    io.out := 5.U
  }.elsewhen(io.in(4)) {
    io.out := 4.U
  }.elsewhen(io.in(3)) {
    io.out := 3.U
  }.elsewhen(io.in(2)) {
    io.out := 2.U
  }.elsewhen(io.in(1)) {
    io.out := 1.U
  }.otherwise {
    io.out := 0.U
  }

  when(io.in_valid){
    io.seg := ~ MuxLookup(io.out, "b11111100".U, Array(
      0.U -> "b11111100".U,
      1.U -> "b01100000".U,
      2.U -> "b11011010".U,
      3.U -> "b11110010".U,
      4.U -> "b01100110".U,
      5.U -> "b10110110".U,
      6.U -> "b10111110".U,
      7.U -> "b11100000".U
    ))
  }.otherwise{
    io.seg := "b11111100".U
  }


}