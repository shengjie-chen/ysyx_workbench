package RVnpc.RVNoob.Pipeline

import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

trait MEMregSignal extends RVNoobConfig {
  val dnpc     = UInt(xlen.W)
  val src2     = UInt(xlen.W)
  val mem_addr = UInt(xlen.W)
  val alu_res  = UInt(xlen.W)
  val B_en     = Bool()
  val pc_mux   = Bool()

  val mem_ctrl    = new MemCtrlIO
  val wb_rf_ctrl  = new WbRfCtrlIO
  val wb_csr_ctrl = new WbCsrCtrlIO

}

class MEMregOutIO extends PipelineOutIO with MEMregSignal {}

class MEMregInIO extends PipelineInIO with MEMregSignal {
  val dnpc_en     = Bool()
  val src2_en     = Bool()
  val mem_addr_en = Bool()
  val alu_res_en  = Bool()
  val B_en_en     = Bool()
  val pc_mux_en   = Bool()

  val mem_ctrl_en    = Bool()
  val wb_rf_ctrl_en  = Bool()
  val wb_csr_ctrl_en = Bool()

}

class MEMreg(bypass: Boolean = false) extends MultiIOModule with RVNoobConfig {
  val in  = IO(Input(new MEMregInIO))
  val out = IO(Output(new MEMregOutIO))
  if (bypass) {
    out.pc       := in.pc
    out.inst     := in.inst
    out.dnpc     := in.dnpc
    out.src2     := in.src2
    out.mem_addr := in.mem_addr
    out.alu_res  := in.alu_res
    out.B_en     := in.B_en
    out.pc_mux   := in.pc_mux

    out.mem_ctrl    := in.mem_ctrl
    out.wb_rf_ctrl  := in.wb_rf_ctrl
    out.wb_csr_ctrl := in.wb_csr_ctrl

  } else {
    out.pc       := RegEnable(in.pc, 0.U, in.pc_en)
    out.inst     := RegEnable(in.inst, 0.U, in.inst_en)
    out.dnpc     := RegEnable(in.dnpc, 0.U, in.dnpc_en)
    out.src2     := RegEnable(in.src2, 0.U, in.src2_en)
    out.mem_addr := RegEnable(in.mem_addr, 0.U, in.mem_addr_en)
    out.alu_res  := RegEnable(in.alu_res, 0.U, in.alu_res_en)
    out.B_en     := RegEnable(in.B_en, 0.B, in.B_en_en)
    out.pc_mux   := RegEnable(in.pc_mux, 0.B, in.pc_mux_en)

    out.mem_ctrl    := RegEnable(in.mem_ctrl, 0.U.asTypeOf(new MemCtrlIO), in.mem_ctrl_en)
    out.wb_rf_ctrl  := RegEnable(in.wb_rf_ctrl, 0.U.asTypeOf(new WbRfCtrlIO), in.wb_rf_ctrl_en)
    out.wb_csr_ctrl := RegEnable(in.wb_csr_ctrl, 0.U.asTypeOf(new WbCsrCtrlIO), in.wb_csr_ctrl_en)
  }

}

object MEMreg {
  def apply(
    pc:          UInt,
    inst:        UInt,
    dnpc:        UInt,
    src2:        UInt,
    mem_addr:    UInt,
    alu_res:     UInt,
    B_en:        Bool,
    pc_mux:      Bool,
    mem_ctrl:    MemCtrlIO,
    wb_rf_ctrl:  WbRfCtrlIO,
    wb_csr_ctrl: WbCsrCtrlIO,
    bypass:      Boolean = false
  ): MEMreg = {
    val mem_reg = Module(new MEMreg(bypass))
    mem_reg.in.pc <> pc
    mem_reg.in.inst <> inst
    mem_reg.in.dnpc <> dnpc
    mem_reg.in.src2 <> src2
    mem_reg.in.mem_addr <> mem_addr
    mem_reg.in.alu_res <> alu_res
    mem_reg.in.B_en <> B_en
    mem_reg.in.pc_mux <> pc_mux
    mem_reg.in.mem_ctrl <> mem_ctrl
    mem_reg.in.wb_rf_ctrl <> wb_rf_ctrl
    mem_reg.in.wb_csr_ctrl <> wb_csr_ctrl

    mem_reg.in.pc_en <> 1.B
    mem_reg.in.inst_en <> 1.B
    mem_reg.in.dnpc_en <> 1.B
    mem_reg.in.src2_en <> 1.B
    mem_reg.in.mem_addr_en <> 1.B
    mem_reg.in.alu_res_en <> 1.B
    mem_reg.in.B_en_en <> 1.B
    mem_reg.in.pc_mux_en <> 1.B
    mem_reg.in.mem_ctrl_en <> 1.B
    mem_reg.in.wb_rf_ctrl_en <> 1.B
    mem_reg.in.wb_csr_ctrl_en <> 1.B

    mem_reg
  }
}
