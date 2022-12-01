package RVnpc.RVNoob.Cache
import chisel3._
class Port128test extends Module {
  val io = IO(new Bundle {
    val in   = Input(UInt(128.W))
    val out1 = Output(UInt(64.W))
    val out2 = Output(UInt(64.W))
  })
  val addr = Wire(UInt(128.W))
//  val addr_temp : BigInt= 0x0ffffffffffffffff
  //  addr := addr_temp.U(128.W)
  addr    := 0xffffffffffffffffL.S(64.W).asUInt()
//  addr    := 0x0fffffffffffffffL.asUInt()
  io.out1 := addr(63, 0)
  io.out2 := addr(127, 64)
}

object Port128testGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/test"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new Port128test()))
    )
}
