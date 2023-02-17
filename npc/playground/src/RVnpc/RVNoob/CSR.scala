package RVnpc.RVNoob

import chisel3._
import chisel3.util._
import scala.math._

class DpiCsrRead extends BlackBox with RVNoobConfig {
  val io = IO(new Bundle {
    val csr = Input(Vec(4, UInt(xlen.W)))
  })
}

class CSR extends Module with RVNoobConfig with Csr_op {
  val io = IO(new Bundle {
    val csr_rdata   = Output(UInt(xlen.W))
    val id_csr_ctrl = Input(new IdCsrCtrlIO)
    val csr_dnpc    = Output(UInt(addr_w.W))

    val pc          = Input(UInt(addr_w.W))
    val wb_csr_ctrl = Input(new WbCsrCtrlIO)
    val csr_wdata   = Input(UInt(xlen.W))

  })
  // 0 mstatus; 1 mtvec; 2 mepc; 3 mcause;
  val mstatus = RegInit(UInt(xlen.W), 0xa00001800L.U)
  val mtvec   = RegInit(UInt(xlen.W), 0.U)
  val mepc    = RegInit(UInt(inst_w.W), 0.U)
  val mcause  = RegInit(UInt(xlen.W), 0.U)

  val read_mstatus = Wire(UInt(xlen.W))
  val read_mtvec   = Wire(UInt(xlen.W))
  val read_mepc    = Wire(UInt(inst_w.W))
  val read_mcause  = Wire(UInt(xlen.W))

  if (!tapeout) {
    val DpiCsrRead = Module(new DpiCsrRead)
    DpiCsrRead.io.csr(0) <> mstatus
    DpiCsrRead.io.csr(1) <> mtvec
    DpiCsrRead.io.csr(2) <> mepc
    DpiCsrRead.io.csr(3) <> mcause
  }

  read_mstatus := mstatus
  read_mtvec   := mtvec
  read_mepc    := mepc
  read_mcause  := mcause
  when(io.wb_csr_ctrl.csr_wen) {
    switch(io.wb_csr_ctrl.csr_waddr) {
      is(0x300.U) {
        mstatus      := io.csr_wdata
        read_mstatus := io.csr_wdata
      }
      is(0x305.U) {
        mtvec      := io.csr_wdata
        read_mtvec := io.csr_wdata
      }
      is(0x341.U) {
        mepc      := io.csr_wdata
        read_mepc := io.csr_wdata
      }
      is(0x342.U) {
        mcause      := io.csr_wdata
        read_mcause := io.csr_wdata
      }
    }
  }.elsewhen(io.wb_csr_ctrl.ecall) {
    mstatus      := read_mstatus
    read_mstatus := mstatus(xlen - 1, 8) ## mstatus(3) ## mstatus(6, 4) ## 0.B ## mstatus(2, 0)
    mepc         := io.pc
    read_mepc    := io.pc
    mcause       := 11.U
    read_mcause  := 11.U
  }.elsewhen(io.wb_csr_ctrl.mret) {
    mstatus      := read_mstatus
    read_mstatus := mstatus(xlen - 1, 4) ## mstatus(7) ## mstatus(2, 0)
  }

  val csr_read = MuxCase(
    0.U,
    Array(
      (io.id_csr_ctrl.csr_raddr === 0x300.U) -> read_mstatus, // mstatus
      (io.id_csr_ctrl.csr_raddr === 0x305.U) -> read_mtvec, // mtvec
      (io.id_csr_ctrl.csr_raddr === 0x341.U) -> read_mepc, // mepc
      (io.id_csr_ctrl.csr_raddr === 0x342.U) -> read_mcause // mcause
    )
  )
  io.csr_rdata := Mux(io.id_csr_ctrl.csr_ren, csr_read, 0.U)
  io.csr_dnpc  := Mux(io.id_csr_ctrl.ecall, read_mtvec, read_mepc) // this 2 signal can mix

  override def desiredName = if (tapeout) ysyxid + "_" + getClassName else getClassName

}
