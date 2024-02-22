package RVnpc.RVNoob
import RVnpc.RVNoob.Axi._
import chisel3._
import chisel3.util._

class Clint extends Module with RVNoobConfig {

  val io = IO(new Bundle() {
    val rctrl          = new AxiReadCtrlIO
    val wctrl          = new AxiWriteCtrlIO
    val time_interrupt = Output(Bool())

    val mstatus_mie = Input(Bool())
    val mie_mtie    = Input(Bool())

    val id_reg_pc         = Input(UInt(addr_w.W))
    val mem_B_en          = Input(Bool())
    val ex_is_branch_inst = Input(Bool())
    val ex_csr_wen        = Input(Bool())
    val mem_csr_wen       = Input(Bool())
    val miss              = Input(Bool())
  })
  /* 0000 msip hart 0
   * 0004 msip hart 1
   * 4000 mtimecmp hart 0 lo
   * 4004 mtimecmp hart 0 hi
   * 4008 mtimecmp hart 1 lo
   * 400c mtimecmp hart 1 hi
   * bff8 mtime lo
   * bffc mtime hi
   */

  val mtime    = RegInit(UInt(64.W), 0.U)
  val mtimecmp = RegInit(UInt(64.W), 0.U)
  mtime := mtime + 1.U

  val time_intr_state     = Wire(Bool())
  val time_intr           = Wire(Bool())
  val time_intr_condition = Wire(Bool())
  time_intr_state := (mtime >= mtimecmp) && io.mstatus_mie && io.mie_mtie
  time_intr       := riseEdge(time_intr_state)
  val ex_mem_not_write_csr = !(io.ex_csr_wen || io.mem_csr_wen)
  time_intr_condition := (io.id_reg_pc =/= 0.U) && !(io.ex_is_branch_inst || io.mem_B_en) && ex_mem_not_write_csr

  val time_intr_reg = RegInit(0.B)
  when(time_intr && (!time_intr_condition || io.miss)) {
    time_intr_reg := 1.B
  }.elsewhen(time_intr_condition && !io.miss) {
    time_intr_reg := 0.B
  }
  io.time_interrupt := ((time_intr || time_intr_reg) && time_intr_condition)

  io.rctrl.data      := 0.U
  io.rctrl.handshake := 0.B
  when(io.rctrl.en) {
    when(io.rctrl.addr >= 0x0200bff8.U && io.rctrl.addr < 0x0200c000.U) {
      io.rctrl.data      := mtime
      io.rctrl.handshake := 1.B
    }.elsewhen(io.rctrl.addr >= 0x02004000.U && io.rctrl.addr < 0x02004010.U) {
      io.rctrl.data      := mtimecmp
      io.rctrl.handshake := 1.B
    }
  }

  io.wctrl.whandshake := 0.B
  io.wctrl.bhandshake := 0.B
  val strb = Wire(UInt(64.W))
  strb := FillInterleaved(8, io.wctrl.strb)
  when(io.wctrl.en) {
    when(io.wctrl.addr >= 0x0200bff8.U && io.wctrl.addr < 0x0200c000.U) {
      mtime               := io.wctrl.data & strb | mtime & (~strb).asUInt()
      io.wctrl.whandshake := 1.B
      io.wctrl.bhandshake := 1.B
    }.elsewhen(io.wctrl.addr >= 0x02004000.U && io.wctrl.addr < 0x02004010.U) {
      mtimecmp            := io.wctrl.data & strb | mtime & (~mtimecmp).asUInt()
      io.wctrl.whandshake := 1.B
      io.wctrl.bhandshake := 1.B
    }
  }

  override def desiredName = if (tapeout) ysyxid + "_" + getClassName else getClassName
}
