package RVnpc.RVNoob
import RVnpc.RVNoob.Axi._
import chisel3._
import chisel3.util._

class Clint extends Module with RVNoobConfig {

  val io = IO(new Bundle() {
    val rctrl          = new AxiReadCtrlIO
    val wctrl          = new AxiWriteCtrlIO
    val time_interrupt = Output(Bool())
  })

  val mtime    = RegInit(UInt(64.W), 0.U)
  val mtimecmp = RegInit(UInt(64.W), 0x100000.U)

  io.time_interrupt := mtime >= mtimecmp

  io.rctrl.data      := 0.U
  io.rctrl.handshake := 0.B
  when(io.rctrl.en) {
    when(io.rctrl.addr >= 0x02000000.U || io.rctrl.addr < 0x02000008.U) {
      io.rctrl.data      := mtime
      io.rctrl.handshake := 1.B
    }.elsewhen(io.rctrl.addr >= 0x02000008.U || io.rctrl.addr < 0x02000010.U) {
      io.rctrl.data      := mtimecmp
      io.rctrl.handshake := 1.B
    }
  }

  io.wctrl.whandshake := 0.B
  io.wctrl.bhandshake := 0.B
  when(io.wctrl.en) {
    when(io.wctrl.addr >= 0x02000000.U || io.wctrl.addr < 0x02000008.U) {
      mtime               := io.wctrl.data & io.wctrl.strb
      io.wctrl.whandshake := 1.B
      io.wctrl.bhandshake := 1.B
    }.elsewhen(io.rctrl.addr >= 0x02000008.U || io.rctrl.addr < 0x02000010.U) {
      mtimecmp            := io.wctrl.data & io.wctrl.strb
      io.wctrl.whandshake := 1.B
      io.wctrl.bhandshake := 1.B
    }
  }
}