package RVnpc.RVNoob.Branch

import chisel3._

class DpiBranch extends BlackBox {
  val io = IO(new Bundle {
    val clk         = Input(Clock())
    val br_valid    = Input(Bool())
    val br_type     = Input(UInt(3.W))
    val pre_taken   = Input(Bool())
    val pre_target  = Input(UInt(32.W))
    val true_taken  = Input(Bool())
    val true_target = Input(UInt(32.W))
    val id_error    = Input(Bool())
    val exe_error   = Input(Bool())
    val mem_error   = Input(Bool())
  })
}
