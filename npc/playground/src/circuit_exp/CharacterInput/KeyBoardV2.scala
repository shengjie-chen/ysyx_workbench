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
    data0 := u0.io.data
  }

  io.data := data1

  // no_press posedge detect
  val no_press_r = Reg(UInt(3.W))
  no_press_r := Cat(no_press_r(1,0),no_press)
  val no_press_posedge = ~no_press_r(2) & no_press_r(1)
  io.mem_write_en := no_press_posedge

}