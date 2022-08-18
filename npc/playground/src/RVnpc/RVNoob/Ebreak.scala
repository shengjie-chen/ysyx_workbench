package RVnpc.RVNoob
import chisel3._
class Ebreak extends BlackBox {
  val io = IO(new Bundle {
    val clk    = Input(Clock())
    val inst   = Input(UInt(32.W))
    val a0     = Input(UInt(64.W))
    val ebreak = Output(Bool())
  })

}
