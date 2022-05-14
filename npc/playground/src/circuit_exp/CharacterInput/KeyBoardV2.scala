package circuit_exp.CharacterInput
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

class KeyBoardV2 extends Module {
  val io = IO(new Bundle {
    val ps2_clk = Input(Bool())
    val ps2_data = Input(Bool())
    val data = Output(UInt(8.W))
    val mem_write_en = Output(Bool())

  })
  val u0 = Module(new ps2_keyboard)
// ps2_keyboard
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
  // ready negedge detect
  val ready_r = Reg(UInt(3.W))
  ready_r := Cat(ready_r(1,0),u0.io.ready)
  val ready_negedge = ready_r(2) & ~ready_r(1)

  val release = RegInit(0.B)//when find data = F0 set 1; and when ready negedge set 0
  val no_press = RegInit(0.B)
  when(data2 === 0xF0.U && data1 =/= 0xF0.U){
    cnt := cnt + 1.U
    release := 1.B
  }
  when(release && ready_negedge){
    release := 0.B
    no_press := 1.B
  }.elsewhen(no_press && ready_negedge){
    no_press := 0.B
  }
  val cnt_vec = VecInit((0 to 100) map (i => (i/10*16+i%10).asUInt()))
  val cnt_r = RegInit(0.U(8.W))
  cnt_r := cnt_vec(cnt)


  when(u0.io.ready){
    data0 := keycode2ascii
  }

  // key code to ascii rom
  val keycode2ascii = MuxCase(0.U(8.W),Array(
    //a - z
    (u0.io.data === 0x1c.U) -> 97.U,
    (u0.io.data === 0x32.U) -> 98.U,
    (u0.io.data === 0x21.U) -> 99.U,
    (u0.io.data === 0x23.U) -> 100.U,
    (u0.io.data === 0x24.U) -> 101.U,
    (u0.io.data === 0x2b.U) -> 102.U,
    (u0.io.data === 0x34.U) -> 103.U,
    (u0.io.data === 0x33.U) -> 104.U,
    (u0.io.data === 0x43.U) -> 105.U,
    (u0.io.data === 0x3b.U) -> 106.U,
    (u0.io.data === 0x42.U) -> 107.U,
    (u0.io.data === 0x4b.U) -> 108.U,
    (u0.io.data === 0x3a.U) -> 109.U,
    (u0.io.data === 0x31.U) -> 110.U,
    (u0.io.data === 0x44.U) -> 111.U,
    (u0.io.data === 0x4d.U) -> 112.U,
    (u0.io.data === 0x15.U) -> 113.U,
    (u0.io.data === 0x2d.U) -> 114.U,
    (u0.io.data === 0x1b.U) -> 115.U,
    (u0.io.data === 0x2c.U) -> 116.U,
    (u0.io.data === 0x3c.U) -> 117.U,
    (u0.io.data === 0x2a.U) -> 118.U,
    (u0.io.data === 0x1d.U) -> 119.U,
    (u0.io.data === 0x22.U) -> 120.U,
    (u0.io.data === 0x35.U) -> 121.U,
    (u0.io.data === 0x1a.U) -> 122.U,
    // all Numeric keypad
    (u0.io.data === 0x70.U) -> 48.U,//0
    (u0.io.data === 0x69.U) -> 49.U,//1
    (u0.io.data === 0x72.U) -> 50.U,//2
    (u0.io.data === 0x7a.U) -> 51.U,//3
    (u0.io.data === 0x6b.U) -> 52.U,//4
    (u0.io.data === 0x73.U) -> 53.U,//5
    (u0.io.data === 0x74.U) -> 54.U,//6
    (u0.io.data === 0x6c.U) -> 55.U,//7
    (u0.io.data === 0x75.U) -> 56.U,//8
    (u0.io.data === 0x7d.U) -> 57.U,//9
    //
    (u0.io.data === 0x5a.U) -> 13.U,//enter
    (u0.io.data === 0x66.U) -> 8.U,//backspace
    (u0.io.data === 0x29.U) -> 32.U,//space
//    (io.data === 0x5a.U) -> 13.U,//enter
//    (io.data === 0x5a.U) -> 13.U,//enter
//    (io.data === 0x5a.U) -> 13.U,//enter


  ))

  io.data := data1

  // no_press posedge detect
  val no_press_r = Reg(UInt(3.W))
  no_press_r := Cat(no_press_r(1,0),no_press)
  val no_press_posedge = !no_press_r(2) & no_press_r(1)
  io.mem_write_en := no_press_posedge

}