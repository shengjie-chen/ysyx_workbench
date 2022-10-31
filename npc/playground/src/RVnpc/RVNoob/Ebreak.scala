package RVnpc.RVNoob

import chisel3._

class Ebreak extends BlackBox {
  val io = IO(new Bundle {
    val clk = Input(Clock())
    val inst = Input(UInt(32.W))
    val a0 = Input(UInt(64.W))
    val ebreak = Output(Bool())
  })

}

object Ebreak {
  def apply(
             clk: Clock,
             inst: UInt,
             a0: UInt,
             ebreak: Bool
           ): Ebreak = {
    val u_ebreak = Module(new Ebreak)
    u_ebreak.io.clk <> clk
    u_ebreak.io.inst <> inst
    u_ebreak.io.a0 <> a0
    u_ebreak.io.ebreak <> ebreak
    u_ebreak
  }
}