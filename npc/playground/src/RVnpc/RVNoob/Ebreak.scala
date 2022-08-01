package RVnpc.RVNoob
import chisel3._
class Ebreak extends BlackBox{
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
    val ebreak = Output(Bool())
  })

}
