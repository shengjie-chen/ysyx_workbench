package RVnpc.RVNoob

import chisel3._
import chisel3.util._

class CSR extends Module with RVNoobConfig with Csr_op {
  val io = IO(new Bundle {
    val pc         = Input(UInt(xlen.W))
    val csr_addr   = Input(UInt(12.W))
    val mcause     = Input(UInt(xlen.W))
    val zimm       = Input(UInt(5.W))
    val rdata1     = Input(UInt(xlen.W))
    val dest_rdata = Input(UInt(xlen.W))
    val csr_ctrl   = Input(new CsrCtrlIO)

    val csr_rdata = Output(UInt(xlen.W))
    val mtvec     = Output(UInt(xlen.W))
    val mepc      = Output(UInt(xlen.W))
  })
  // 0 mstatus; 1 mtvec; 2 mepc; 3 mcause;
  val csr = Reg(Vec(4, UInt(xlen.W)))
  val csr_addr = MuxCase(
    0.U,
    Array(
      (io.csr_addr === 0x300.U) -> 0.U,
      (io.csr_addr === 0x305.U) -> 1.U,
      (io.csr_addr === 0x341.U) -> 2.U,
      (io.csr_addr === 0x342.U) -> 3.U
    )
  )
  val csr_wdata = MuxCase(
    0.U,
    Array(
      (io.csr_ctrl.csr === csr_rw) -> io.rdata1,
      (io.csr_ctrl.csr === csr_rwi) -> io.zimm,
      (io.csr_ctrl.csr === csr_rs) -> (csr(csr_addr) | io.rdata1),
      (io.csr_ctrl.csr === csr_rsi) -> (csr(csr_addr) | io.zimm),
      (io.csr_ctrl.csr === csr_rc) -> (csr(csr_addr) & (~io.rdata1).asUInt()),
      (io.csr_ctrl.csr === csr_rci) -> (csr(csr_addr) & (~io.zimm).asUInt())
    )
  )
  when(io.csr_ctrl.csr_en){
    csr(csr_addr) := csr_wdata
  }.elsewhen(io.csr_ctrl.ecall){
    csr(2) := io.pc
    csr(3) := io.mcause
  }


  io.csr_rdata := Mux(io.csr_ctrl.csr_en, csr(csr_addr), 0.U)
  io.mtvec     := Mux(io.csr_ctrl.ecall, csr(1), 0.U)
  io.mepc      := Mux(io.csr_ctrl.mret, csr(2), 0.U & 1.U)

}
