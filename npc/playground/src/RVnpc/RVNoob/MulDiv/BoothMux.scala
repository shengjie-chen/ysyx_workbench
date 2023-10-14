package RVnpc.RVNoob.MulDiv
import chisel3._

class BoothMux extends Module {
  val io = IO(new Bundle() {
    val next_3bit  = Input(UInt(3.W))
    val shift_4bit = Output(Bool())
  })

  io.shift_4bit := io.next_3bit.andR() || !io.next_3bit.orR()
}
