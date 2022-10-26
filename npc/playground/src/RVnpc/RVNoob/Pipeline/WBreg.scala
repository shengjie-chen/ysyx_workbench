package RVnpc.RVNoob.Pipeline

import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

trait WBregSignal extends RVNoobConfig {
  val src2 = UInt(xlen.W)
  val alu_res   = UInt(xlen.W)
  val mem_data  = UInt(xlen.W)
  val r_pmem    = Bool()

  val wb_rf_ctrl = new WbRfCtrlIO
  val wb_csr_ctrl = new WbCsrCtrlIO

}

class WBregOutIO extends PipelineOutIO with WBregSignal {}

class WBregInIO extends PipelineInIO with WBregSignal {
  val src2_en = Bool()
  val alu_res_en   = Bool()
  val mem_data_en  = Bool()
  val r_pmem_en    = Bool()

  val wb_rf_ctrl_en = Bool()
  val wb_csr_ctrl_en = Bool()

}

class WBreg(bypass: Boolean = false) extends MultiIOModule with RVNoobConfig {
  val in  = IO(Input(new WBregInIO))
  val out = IO(Output(new WBregOutIO))

  if (bypass) {
    out.pc        := in.pc
    out.inst      := in.inst
    out.src2 := in.src2
    out.alu_res   := in.alu_res
    out.mem_data  := in.mem_data
    out.r_pmem    := in.r_pmem
    out.wb_rf_ctrl := in.wb_rf_ctrl
    out.wb_csr_ctrl := in.wb_csr_ctrl
  } else {
    out.pc        := RegEnable(in.pc, in.pc_en)
    out.inst      := RegEnable(in.inst, in.inst_en)
    out.src2 := RegEnable(in.src2 , in.src2_en)
    out.alu_res   := RegEnable(in.alu_res, in.alu_res_en)
    out.mem_data  := RegEnable(in.mem_data, in.mem_data_en)
    out.r_pmem    := RegEnable(in.r_pmem, in.r_pmem_en)
    out.wb_rf_ctrl := RegEnable(in.wb_rf_ctrl, in.wb_rf_ctrl_en)
    out.wb_csr_ctrl := RegEnable(in.wb_csr_ctrl, in.wb_csr_ctrl_en)
  }
}

object WBreg {
  def apply(
    pc:        UInt,
    inst:      UInt,
    src2:     UInt,
    alu_res:   UInt,
    mem_data:  UInt,
    r_pmem:    UInt,
    wb_rf_ctrl: WbRfCtrlIO,
    wb_csr_ctrl: WbCsrCtrlIO,
    bypass:    Boolean = false
  ): WBreg = {
    val wb_reg = Module(new WBreg(bypass))
    wb_reg.in.pc <> pc
    wb_reg.in.inst <> inst
    wb_reg.in.src2 <> src2
    wb_reg.in.alu_res <> alu_res
    wb_reg.in.mem_data <> mem_data
    wb_reg.in.r_pmem <> r_pmem
    wb_reg.in.wb_rf_ctrl <> wb_rf_ctrl
    wb_reg.in.wb_csr_ctrl <> wb_csr_ctrl

    wb_reg.in.pc_en <> 1.B
    wb_reg.in.inst_en <> 1.B
    wb_reg.in.src2_en <> 1.B
    wb_reg.in.alu_res_en <> 1.B
    wb_reg.in.mem_data_en <> 1.B
    wb_reg.in.r_pmem_en <> 1.B
    wb_reg.in.wb_rf_ctrl_en <> 1.B
    wb_reg.in.wb_csr_ctrl_en <> 1.B

    wb_reg
  }
}
