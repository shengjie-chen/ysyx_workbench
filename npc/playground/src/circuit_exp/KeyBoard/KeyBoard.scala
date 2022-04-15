package circuit_exp.KeyBoard

import chisel3._
import chisel3.util._

class ps2_keyboard extends BlackBox {
  val io = IO(new Bundle{
    val clk = Input(Clock())
    val clrn = Input(Bool())
    val ps2_clk = Input(Bool())
    val ps2_data = Input(Bool())
    val nextdata_n = Input(Bool())
    val data = Output(UInt(8.W))
    val ready = Output(Bool())
    val overflow = Output(Bool())
  })
}

class KeyBoard extends Module {
  val io = IO(new Bundle {
    val ps2_clk = Input(Bool())
    val ps2_data = Input(Bool())
    val data = Output(UInt(8.W))
    //current key code
    val seg0 = Output(UInt(8.W))
    val seg1 = Output(UInt(8.W))
    //corresponding ASCII
    val seg2 = Output(UInt(8.W))
    val seg3 = Output(UInt(8.W))
    //total number of keystrokes
    val seg4 = Output(UInt(8.W))
    val seg5 = Output(UInt(8.W))
  })
  val u0 = Module(new ps2_keyboard)

  u0.io.clk := clock
  u0.io.clrn := ~ reset.asBool()
  u0.io.ps2_clk := io.ps2_clk
  u0.io.ps2_data := io.ps2_data
  val nextdata_n = ShiftRegister(u0.io.ready,2)
  u0.io.nextdata_n := nextdata_n
  val data0 = Reg(UInt(8.W))
  val data1 = RegNext(data0)
  val data2 = RegNext(data1)
  val cnt = RegInit(0.U(8.W))
  when(data2 === 0xF0.U && data1 =/= 0xF0.U){
    cnt := cnt + 1.U
  }
  val cnt_vec = VecInit((0 to 100) map (i => (i/10*16+i%10).asUInt()))
  val cnt_r = RegInit(0.U(8.W))
  cnt_r := cnt_vec(cnt)

  when(u0.io.ready){
    data0 := u0.io.data
  }

  // key code to ascii rom
  val keycode2ascii = MuxCase(0.U(8.W),Array(
    (io.data === 0x1c.U) -> 97.U,
    (io.data === 0x32.U) -> 98.U,
    (io.data === 0x21.U) -> 99.U,
    (io.data === 0x23.U) -> 100.U,
    (io.data === 0x24.U) -> 101.U,
    (io.data === 0x2b.U) -> 102.U,
    (io.data === 0x34.U) -> 103.U,
    (io.data === 0x33.U) -> 104.U,
    (io.data === 0x43.U) -> 105.U,
    (io.data === 0x3b.U) -> 106.U,
    (io.data === 0x42.U) -> 107.U,
    (io.data === 0x4b.U) -> 108.U,
    (io.data === 0x3a.U) -> 109.U,
    (io.data === 0x31.U) -> 110.U,
    (io.data === 0x44.U) -> 111.U,
    (io.data === 0x4d.U) -> 112.U,
    (io.data === 0x15.U) -> 113.U,
    (io.data === 0x2d.U) -> 114.U,
    (io.data === 0x1b.U) -> 115.U,
    (io.data === 0x2c.U) -> 116.U,
    (io.data === 0x3c.U) -> 117.U,
    (io.data === 0x2a.U) -> 118.U,
    (io.data === 0x1d.U) -> 119.U,
    (io.data === 0x22.U) -> 120.U,
    (io.data === 0x35.U) -> 121.U,
    (io.data === 0x1a.U) -> 122.U,
    (io.data === 0x70.U) -> 48.U,
    (io.data === 0x69.U) -> 49.U,
    (io.data === 0x72.U) -> 50.U,
    (io.data === 0x7a.U) -> 51.U,
    (io.data === 0x6b.U) -> 52.U,
    (io.data === 0x73.U) -> 53.U,
    (io.data === 0x74.U) -> 54.U,
    (io.data === 0x6c.U) -> 55.U,
    (io.data === 0x75.U) -> 56.U,
    (io.data === 0x7d.U) -> 57.U
  ))

  io.data := data1


  io.seg0 := "b11111111".U
  io.seg1 := "b11111111".U
  io.seg2 := "b11111111".U
  io.seg3 := "b11111111".U
//
//  when(io.ps2_clk){
//    io.seg0 := "b11111111".U
//    io.seg1 := "b11111111".U
//    io.seg2 := "b11111111".U
//    io.seg3 := "b11111111".U
//  }.otherwise
//  {
//    io.seg0 := ~MuxLookup(io.data(3, 0), "b00000010".U, Array(
//      0.U -> "b11111100".U,
//      1.U -> "b01100000".U,
//      2.U -> "b11011010".U,
//      3.U -> "b11110010".U,
//      4.U -> "b01100110".U,
//      5.U -> "b10110110".U,
//      6.U -> "b10111110".U,
//      7.U -> "b11100000".U,
//      8.U -> "b11111110".U,
//      9.U -> "b11110110".U,
//      10.U -> "b11101110".U,
//      11.U -> "b00111110".U,
//      12.U -> "b10011100".U,
//      13.U -> "b01111010".U,
//      14.U -> "b10011110".U,
//      15.U -> "b10001110".U,
//    ))
//
//    io.seg1 := ~MuxLookup(io.data(7, 4), "b00000010".U, Array(
//      0.U -> "b11111100".U,
//      1.U -> "b01100000".U,
//      2.U -> "b11011010".U,
//      3.U -> "b11110010".U,
//      4.U -> "b01100110".U,
//      5.U -> "b10110110".U,
//      6.U -> "b10111110".U,
//      7.U -> "b11100000".U,
//      8.U -> "b11111110".U,
//      9.U -> "b11110110".U,
//      10.U -> "b11101110".U,
//      11.U -> "b00111110".U,
//      12.U -> "b10011100".U,
//      13.U -> "b01111010".U,
//      14.U -> "b10011110".U,
//      15.U -> "b10001110".U,
//    ))
//
//    io.seg2 := ~MuxLookup(keycode2ascii(3, 0), "b00000010".U, Array(
//      0.U -> "b11111100".U,
//      1.U -> "b01100000".U,
//      2.U -> "b11011010".U,
//      3.U -> "b11110010".U,
//      4.U -> "b01100110".U,
//      5.U -> "b10110110".U,
//      6.U -> "b10111110".U,
//      7.U -> "b11100000".U,
//      8.U -> "b11111110".U,
//      9.U -> "b11110110".U,
//      10.U -> "b11101110".U,
//      11.U -> "b00111110".U,
//      12.U -> "b10011100".U,
//      13.U -> "b01111010".U,
//      14.U -> "b10011110".U,
//      15.U -> "b10001110".U,
//    ))
//
//    io.seg3 := ~MuxLookup(keycode2ascii(7, 4), "b00000010".U, Array(
//      0.U -> "b11111100".U,
//      1.U -> "b01100000".U,
//      2.U -> "b11011010".U,
//      3.U -> "b11110010".U,
//      4.U -> "b01100110".U,
//      5.U -> "b10110110".U,
//      6.U -> "b10111110".U,
//      7.U -> "b11100000".U,
//      8.U -> "b11111110".U,
//      9.U -> "b11110110".U,
//      10.U -> "b11101110".U,
//      11.U -> "b00111110".U,
//      12.U -> "b10011100".U,
//      13.U -> "b01111010".U,
//      14.U -> "b10011110".U,
//      15.U -> "b10001110".U,
//    ))
//  }


  io.seg4 := ~ MuxLookup(cnt_r(3,0), "b00000010".U, Array(
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
  ))

  io.seg5 := ~ MuxLookup(cnt_r(7,4), "b00000010".U, Array(
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
  ))



}
