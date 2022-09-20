package RVnpc.RVNoob

import chisel3._
import chisel3.util._

class CSR extends Module with RVNoobConfig{
val io = IO(new Bundle{
  val pc = Input(UInt(xlen.W))
  val mcause = Input(UInt(xlen.W))
  val zimm = Input(UInt(5.W))
  val rdata1 = Input(UInt(xlen.W))
  val dest_rdata = Input(UInt(xlen.W))
  val csr_ctrl = Input(new CsrCtrlIO)

  val csr_rdata = Output(UInt(xlen.W))
  val mtvec = Output(UInt(xlen.W))
  val mepc = Output(UInt(xlen.W))
})

  val mstatus = Reg(UInt(xlen.W))
  val mtvec = Reg(UInt(xlen.W))
  val mepc = Reg(UInt(xlen.W))
  val mcause = Reg(UInt(xlen.W))




  io.csr_rdata :=
    io.mtvec := Mux(io.csr_ctrl.ecall,mtvec,0.U)
  io.mepc := Mux(io.csr_ctrl.mret,mepc,0.U)

}
