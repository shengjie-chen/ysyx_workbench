package RVnpc.RVNoob.Pipeline

import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

trait WBregSignal extends RVNoobConfig {
  val src2        = UInt(xlen.W)
  val alu_res     = UInt(xlen.W)
  val mem_data    = UInt(xlen.W)
  val mem_ctrl    = new MemCtrlIO
  val wb_rf_ctrl  = new WbRfCtrlIO
  val wb_csr_ctrl = new WbCsrCtrlIO

}

class WBregOutIO extends PipelineOutIO with WBregSignal {}

class WBregInIO extends PipelineInIO with WBregSignal {
//  val src2_en     = Bool()
//  val alu_res_en  = Bool()
//  val mem_data_en = Bool()
//  val r_pmem_en   = Bool()
//
//  val wb_rf_ctrl_en  = Bool()
//  val wb_csr_ctrl_en = Bool()

}

class WBreg(bypass: Boolean = false) extends MultiIOModule with RVNoobConfig {
  val in  = IO(Input(new WBregInIO))
  val out = IO(Output(new WBregOutIO))
  dontTouch(in)
  dontTouch(out)

  if (bypass) {
    out.pc          := in.pc
    out.inst        := in.inst
    out.src2        := in.src2
    out.alu_res     := in.alu_res
    out.mem_data    := in.mem_data
    out.mem_ctrl    := in.mem_ctrl
    out.wb_rf_ctrl  := in.wb_rf_ctrl
    out.wb_csr_ctrl := in.wb_csr_ctrl

//    out.valid := 1.B
  } else {
    val reset_t = RegNext(reset.asBool())
    out.pc          := RegEnable(in.pc, 0.U, in.reg_en)
    out.inst        := RegEnable(in.inst, 0.U, in.reg_en)
    out.src2        := RegEnable(in.src2, 0.U, in.reg_en)
    out.alu_res     := RegEnable(in.alu_res, 0.U, in.reg_en)
    out.mem_data    := Mux(reset_t, 0.U, Mux(in.reg_en,in.mem_data,RegNext(out.mem_data)))
    out.mem_ctrl    := RegEnable(in.mem_ctrl, 0.U.asTypeOf(new MemCtrlIO), in.reg_en)
    out.wb_rf_ctrl  := RegEnable(in.wb_rf_ctrl, 0.U.asTypeOf(new WbRfCtrlIO), in.reg_en)
    out.wb_csr_ctrl := RegEnable(in.wb_csr_ctrl, 0.U.asTypeOf(new WbCsrCtrlIO), in.reg_en)

    out.valid := PipelineValid(reset.asBool(), in.reg_en) && (out.inst =/= 0.U)

  }
}

object WBreg {
  def apply(
    pc:          UInt,
    inst:        UInt,
    src2:        UInt,
    alu_res:     UInt,
    mem_data:    UInt,
    mem_ctrl:    MemCtrlIO,
    wb_rf_ctrl:  WbRfCtrlIO,
    wb_csr_ctrl: WbCsrCtrlIO,
    reg_en:      Bool,
    bypass:      Boolean = false
  ): WBreg = {
    val wb_reg = Module(new WBreg(bypass))
    wb_reg.in.pc          <> pc
    wb_reg.in.inst        <> inst
    wb_reg.in.src2        <> src2
    wb_reg.in.alu_res     <> alu_res
    wb_reg.in.mem_data    <> mem_data
    wb_reg.in.mem_ctrl    <> mem_ctrl
    wb_reg.in.wb_rf_ctrl  <> wb_rf_ctrl
    wb_reg.in.wb_csr_ctrl <> wb_csr_ctrl

    wb_reg.in.reg_en <> reg_en

    wb_reg
  }
}
