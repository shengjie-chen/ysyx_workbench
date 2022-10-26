package RVnpc.RVNoob

import chisel3._
import chisel3.util._

class CSR extends Module with RVNoobConfig with Csr_op {
  val io = IO(new Bundle {
    val csr_rdata   = Output(UInt(xlen.W))
    val id_csr_ctrl = Input(new IdCsrCtrlIO)
    val csr_dnpc    = Output(UInt(xlen.W))

    val pc          = Input(UInt(xlen.W))
    val mcause      = Input(UInt(xlen.W))
    val wb_csr_ctrl = Input(new WbCsrCtrlIO)
    val csr_wdata   = Input(UInt(xlen.W))

  })
  // 0 mstatus; 1 mtvec; 2 mepc; 3 mcause;
  //  val csr = Reg(Vec(4, UInt(xlen.W)))
  val csr = RegInit(Vec(4, UInt(xlen.W)),VecInit(0x80000000L.U,0.U,0.U,0.U))
  val csr_raddr = MuxCase(
    0.U,
    Array(
      (io.id_csr_ctrl.csr_raddr === 0x300.U) -> 0.U,
      (io.id_csr_ctrl.csr_raddr === 0x305.U) -> 1.U,
      (io.id_csr_ctrl.csr_raddr === 0x341.U) -> 2.U,
      (io.id_csr_ctrl.csr_raddr === 0x342.U) -> 3.U
    )
  )
  io.csr_rdata := Mux(io.id_csr_ctrl.csr_ren, csr(csr_raddr), 0.U)
  io.csr_dnpc  := Mux(io.id_csr_ctrl.ecall, csr(1), csr(2)) // this 2 signal can mix

  val csr_waddr = MuxCase(
    0.U,
    Array(
      (io.wb_csr_ctrl.csr_waddr === 0x300.U) -> 0.U,
      (io.wb_csr_ctrl.csr_waddr === 0x305.U) -> 1.U,
      (io.wb_csr_ctrl.csr_waddr === 0x341.U) -> 2.U,
      (io.wb_csr_ctrl.csr_waddr === 0x342.U) -> 3.U
    )
  )
  when(io.wb_csr_ctrl.csr_wen) {
    csr(csr_waddr) := io.csr_wdata
  }.elsewhen(io.wb_csr_ctrl.ecall) {
    csr(2) := io.pc
    csr(3) := io.mcause
  }
}
