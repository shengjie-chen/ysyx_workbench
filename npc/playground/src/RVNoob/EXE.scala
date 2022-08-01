package RVNoob
import chisel3._

class EXE extends Module {
  val io = IO(new Bundle {
    val src1   = Input(UInt(64.W))
    val src2   = Input(UInt(64.W))
    val add_en = Input(Bool())
    val result = Output(UInt(64.W))
  })

  io.result := Mux(io.add_en, io.src1 + io.src2, 0.U)
}
