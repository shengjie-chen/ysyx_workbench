package RVnpc.RVNoob
import RVnpc.RVNoob.Axi._
import chisel3._
import chisel3.util._

class Clint extends Module with RVNoobConfig {

  val io = IO(new Bundle() {
    val rctrl          = new AxiReadCtrlIO
    val wctrl          = new AxiWriteCtrlIO
    val time_interrupt = Output(Bool())
    val mstatus_mie    = Input(Bool())
    val mie_mtie       = Input(Bool())
    val id_reg_pc      = Input(Bool())
  })

  val mtime    = RegInit(UInt(64.W), 0.U)
  val mtimecmp = RegInit(UInt(64.W), 0.U)
  mtime := mtime + 1.U

  val time_interrupt = Wire(Bool())
  time_interrupt    := mtime >= mtimecmp && io.mstatus_mie && io.mie_mtie
  val time_interrupt_reg = RegInit(0.B)
  when(time_interrupt && (io.id_reg_pc === 0.U)){
    time_interrupt_reg := 1.B
  }.elsewhen(io.id_reg_pc =/= 0.U){
    time_interrupt_reg := 0.B
  }
  io.time_interrupt := (time_interrupt && !RegNext(time_interrupt)) || ((io.id_reg_pc === 0.U) && time_interrupt_reg)

  io.rctrl.data      := 0.U
  io.rctrl.handshake := 0.B
  when(io.rctrl.en) {
    when(io.rctrl.addr >= 0x02000000.U && io.rctrl.addr < 0x02000008.U) {
      io.rctrl.data      := mtime
      io.rctrl.handshake := 1.B
    }.elsewhen(io.rctrl.addr >= 0x02000008.U && io.rctrl.addr < 0x02000010.U) {
      io.rctrl.data      := mtimecmp
      io.rctrl.handshake := 1.B
    }
  }

  io.wctrl.whandshake := 0.B
  io.wctrl.bhandshake := 0.B
  val strb = Wire(UInt(64.W))
  strb := FillInterleaved(8, io.wctrl.strb)
  when(io.wctrl.en) {
    when(io.wctrl.addr >= 0x02000000.U && io.wctrl.addr < 0x02000008.U) {
      mtime               := io.wctrl.data & strb | mtime & (~strb).asUInt()
      io.wctrl.whandshake := 1.B
      io.wctrl.bhandshake := 1.B
    }.elsewhen(io.wctrl.addr >= 0x02000008.U && io.wctrl.addr < 0x02000010.U) {
      mtimecmp            := io.wctrl.data & strb | mtime & (~mtimecmp).asUInt()
      io.wctrl.whandshake := 1.B
      io.wctrl.bhandshake := 1.B
    }
  }
}
