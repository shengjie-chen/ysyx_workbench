package RVnpc.RVNoob.Pipeline

import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

trait EXregSignal extends RVNoobConfig {
  val snpc     = UInt(xlen.W)
  val src1     = UInt(xlen.W)
  val src2     = UInt(xlen.W)
  val imm      = UInt(xlen.W)
  val csr_dnpc = UInt(xlen.W)

  val exe_ctrl    = new EXECtrlIO
  val mem_ctrl    = new MemCtrlIO
  val wb_rf_ctrl  = new WbRfCtrlIO
  val wb_csr_ctrl = new WbCsrCtrlIO
  val dnpc_ctrl   = new DnpcCtrlIO
}

class EXregInIO extends PipelineInIO with EXregSignal {
//  val snpc_en     = Bool()
//  val src1_en     = Bool()
//  val src2_en     = Bool()
//  val imm_en      = Bool()
//  val csr_dnpc_en = Bool()
//
//  val exe_ctrl_en    = Bool()
//  val mem_ctrl_en    = Bool()
//  val wb_rf_ctrl_en  = Bool()
//  val wb_csr_ctrl_en = Bool()
//  val dnpc_ctrl_en   = Bool()
}

class EXregOutIO extends PipelineOutIO with EXregSignal {}

class EXreg(bypass: Boolean = false) extends MultiIOModule with RVNoobConfig {
  val in  = IO(Input(new EXregInIO))
  val out = IO(Output(new EXregOutIO))
  dontTouch(in)
  dontTouch(out)

  if (bypass) {
    out.pc   := in.pc
    out.inst := in.inst

    out.snpc     := in.snpc
    out.src1     := in.src1
    out.src2     := in.src2
    out.imm      := in.imm
    out.csr_dnpc := in.csr_dnpc

    out.exe_ctrl    := in.exe_ctrl
    out.mem_ctrl    := in.mem_ctrl
    out.wb_rf_ctrl  := in.wb_rf_ctrl
    out.wb_csr_ctrl := in.wb_csr_ctrl
    out.dnpc_ctrl   := in.dnpc_ctrl

//    out.valid := 1.B

  } else {
    out.pc   := RegEnable(in.pc, 0.U, in.reg_en)
    out.inst := RegEnable(in.inst, 0.U, in.reg_en)

    out.snpc     := RegEnable(in.snpc, 0.U, in.reg_en)
    out.src1     := RegEnable(in.src1, 0.U, in.reg_en)
    out.src2     := RegEnable(in.src2, 0.U, in.reg_en)
    out.imm      := RegEnable(in.imm, 0.U, in.reg_en)
    out.csr_dnpc := RegEnable(in.csr_dnpc, 0.U, in.reg_en)

    out.exe_ctrl    := RegEnable(in.exe_ctrl, 0.U.asTypeOf(new EXECtrlIO), in.reg_en)
    out.mem_ctrl    := RegEnable(in.mem_ctrl, 0.U.asTypeOf(new MemCtrlIO), in.reg_en)
    out.wb_rf_ctrl  := RegEnable(in.wb_rf_ctrl, 0.U.asTypeOf(new WbRfCtrlIO), in.reg_en)
    out.wb_csr_ctrl := RegEnable(in.wb_csr_ctrl, 0.U.asTypeOf(new WbCsrCtrlIO), in.reg_en)
    out.dnpc_ctrl   := RegEnable(in.dnpc_ctrl, 0.U.asTypeOf(new DnpcCtrlIO), in.reg_en)
  }
}

object EXreg {
  def apply(
    pc:          UInt,
    inst:        UInt,
    snpc:        UInt,
    src1:        UInt,
    src2:        UInt,
    imm:         UInt,
    csr_dnpc:    UInt,
    exe_ctrl:    EXECtrlIO,
    mem_ctrl:    MemCtrlIO,
    wb_rf_ctrl:  WbRfCtrlIO,
    wb_csr_ctrl: WbCsrCtrlIO,
    dnpc_ctrl:   DnpcCtrlIO,
    reg_en:      Bool,
    bypass:      Boolean = false
  ): EXreg = {
    val ex_reg = Module(new EXreg(bypass))
    ex_reg.in.pc          <> pc
    ex_reg.in.inst        <> inst
    ex_reg.in.snpc        <> snpc
    ex_reg.in.src1        <> src1
    ex_reg.in.src2        <> src2
    ex_reg.in.imm         <> imm
    ex_reg.in.csr_dnpc    <> csr_dnpc
    ex_reg.in.exe_ctrl    <> exe_ctrl
    ex_reg.in.mem_ctrl    <> mem_ctrl
    ex_reg.in.wb_rf_ctrl  <> wb_rf_ctrl
    ex_reg.in.wb_csr_ctrl <> wb_csr_ctrl
    ex_reg.in.dnpc_ctrl   <> dnpc_ctrl

    ex_reg.in.reg_en <> reg_en

    ex_reg
  }
}
