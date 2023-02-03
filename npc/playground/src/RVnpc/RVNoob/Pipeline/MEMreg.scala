package RVnpc.RVNoob.Pipeline

import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

trait MEMregSignal extends RVNoobConfig {
  val src2     = UInt(xlen.W)
  val mem_addr = UInt(xlen.W)
  val alu_res  = UInt(xlen.W)

  val mem_ctrl    = new MemCtrlIO
  val wb_rf_ctrl  = new WbRfCtrlIO
  val wb_csr_ctrl = new WbCsrCtrlIO

}

class MEMregOutIO extends PipelineOutIO with MEMregSignal {}

class MEMregInIO extends PipelineInIO with MEMregSignal {
//  val dnpc_en     = Bool()
//  val src2_en     = Bool()
//  val mem_addr_en = Bool()
//  val alu_res_en  = Bool()
//  val B_en_en     = Bool()
//  val pc_mux_en   = Bool()
//
//  val mem_ctrl_en    = Bool()
//  val wb_rf_ctrl_en  = Bool()
//  val wb_csr_ctrl_en = Bool()

}

class MEMreg extends MultiIOModule with RVNoobConfig {
  val in  = IO(Input(new MEMregInIO))
  val out = IO(Output(new MEMregOutIO))
  if (!tapeout) {
    dontTouch(in)
    dontTouch(out)
  }

  out.pc       := RegEnable(in.pc, 0.U, in.reg_en)
  out.inst     := RegEnable(in.inst, 0.U, in.reg_en)
  out.src2     := RegEnable(in.src2, 0.U, in.reg_en)
  out.mem_addr := RegEnable(in.mem_addr, 0.U, in.reg_en)
  out.alu_res  := RegEnable(in.alu_res, 0.U, in.reg_en)

  out.mem_ctrl    := RegEnable(in.mem_ctrl, 0.U.asTypeOf(new MemCtrlIO), in.reg_en)
  out.wb_rf_ctrl  := RegEnable(in.wb_rf_ctrl, 0.U.asTypeOf(new WbRfCtrlIO), in.reg_en)
  out.wb_csr_ctrl := RegEnable(in.wb_csr_ctrl, 0.U.asTypeOf(new WbCsrCtrlIO), in.reg_en)

  // 逻辑应该是等价的，不知道为什么前者运行时出问题
  if (tapeout) { out.valid := RegNext(in.reg_en, 0.B) && (out.inst =/= 0.U) }
  else { out.valid := PipelineValid(reset.asBool(), in.reg_en) && (out.inst =/= 0.U) }

  if (!tapeout) {
    val dpi_mem_pc = Module(new DpiMemPc)
    dpi_mem_pc.io.pc := out.pc
  }

  override def desiredName = if (tapeout) ysyxid + "_" + getClassName else getClassName

}

object MEMreg {
  def apply(
    pc:          UInt,
    inst:        UInt,
    src2:        UInt,
    mem_addr:    UInt,
    alu_res:     UInt,
    B_en:        Bool,
    pc_mux:      Bool,
    mem_ctrl:    MemCtrlIO,
    wb_rf_ctrl:  WbRfCtrlIO,
    wb_csr_ctrl: WbCsrCtrlIO,
    reg_en:      Bool
  ): MEMreg = {
    val mem_reg = Module(new MEMreg)
    mem_reg.in.pc          <> pc
    mem_reg.in.inst        <> inst
    mem_reg.in.src2        <> src2
    mem_reg.in.mem_addr    <> mem_addr
    mem_reg.in.alu_res     <> alu_res
    mem_reg.in.mem_ctrl    <> mem_ctrl
    mem_reg.in.wb_rf_ctrl  <> wb_rf_ctrl
    mem_reg.in.wb_csr_ctrl <> wb_csr_ctrl

    mem_reg.in.reg_en <> reg_en

    mem_reg
  }
}

class DpiMemPc extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val pc = Input(UInt(64.W))
  })
  setInline(
    "DpiMemPc.v",
    """
      |import "DPI-C" function void mem_pc_change(input logic [63:0] a);
      |module DpiMemPc(input [63:0] pc);
      |
      | always @* mem_pc_change(pc);
      |
      |endmodule
            """.stripMargin
  )
}
