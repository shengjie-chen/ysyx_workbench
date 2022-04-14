package circuit_exp.LFSRegister
import chisel3._
import chisel3.util._
import chisel3.util.random.LFSR
class LFSRegister extends Module{
  val io = IO(new Bundle {
    val set = Input(Bool())
    val in = Input(UInt(8.W))
    val out = Output(UInt(8.W))
    val seg0 = Output(UInt(8.W))
    val seg1 = Output(UInt(8.W))

  })

//  val lfsr = VecInit(Seq.fill(9)(RegInit(0.U(1.W))))
//  val lfsr = RegInit(0.U(9.W))
//    val lfsr = VecInit(Seq.fill(9)(RegInit(0.U(1.W))))  !!!!!!RegInit outside
  val lfsr = RegInit(VecInit(0.U(1.W),0.U(1.W),0.U(1.W),0.U(1.W),0.U(1.W),0.U(1.W),0.U(1.W),0.U(1.W),0.U(1.W)))
  var x = 0

  lfsr(8) := lfsr(4) ^ lfsr(3) ^ lfsr(2) ^ lfsr(0)

  when(io.set){
    for(x <- 0 to 7){
      lfsr(x) := io.in(x)
    }
  }.otherwise{
    for(x <- 0 to 7){
      lfsr(x) := lfsr(x + 1)
    }
  }

  io.out := lfsr.asUInt()(7,0)

  io.seg0 := ~ MuxLookup(io.out(3,0), "b11111100".U, Array(
    0.U -> "b11111100".U,
    1.U -> "b01100000".U,
    2.U -> "b11011010".U,
    3.U -> "b11110010".U,
    4.U -> "b01100110".U,
    5.U -> "b10110110".U,
    6.U -> "b10111110".U,
    7.U -> "b11100000".U,
    8.U -> "b11111110".U,
    9.U -> "b11110110".U,
    10.U -> "b11101110".U,
    11.U -> "b00111110".U,
    12.U -> "b10011100".U,
    13.U -> "b01111010".U,
    14.U -> "b10011110".U,
    15.U -> "b10001110".U,
  ))

  io.seg1 := ~ MuxLookup(io.out(7,4), "b11111100".U, Array(
    0.U -> "b11111100".U,
    1.U -> "b01100000".U,
    2.U -> "b11011010".U,
    3.U -> "b11110010".U,
    4.U -> "b01100110".U,
    5.U -> "b10110110".U,
    6.U -> "b10111110".U,
    7.U -> "b11100000".U,
    8.U -> "b11111110".U,
    9.U -> "b11110110".U,
    10.U -> "b11101110".U,
    11.U -> "b00111100".U,
    12.U -> "b10011100".U,
    13.U -> "b01111010".U,
    14.U -> "b10011110".U,
    15.U -> "b10001110".U,
  ))

}
