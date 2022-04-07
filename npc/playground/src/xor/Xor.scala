import chisel3._

class Xor extends RawModule {
  val io = IO(new Bundle {
    val a = Input(UInt(1.W))
    val b = Input(UInt(1.W))
    val f = Output(UInt(1.W))
  })
  io.f := io.a ^ io.b
}
