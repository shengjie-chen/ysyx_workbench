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

class WBreg extends MultiIOModule with RVNoobConfig {
  val in  = IO(Input(new WBregInIO))
  val out = IO(Output(new WBregOutIO))
  if (!tapeout) {
    dontTouch(in)
    dontTouch(out)
  }

  out.pc          := RegEnable(in.pc, 0.U, in.reg_en)
  out.inst        := RegEnable(in.inst, 0.U, in.reg_en)
  out.src2        := RegEnable(in.src2, 0.U, in.reg_en)
  out.alu_res     := RegEnable(in.alu_res, 0.U, in.reg_en)
  out.mem_ctrl    := RegEnable(in.mem_ctrl, 0.U.asTypeOf(new MemCtrlIO), in.reg_en)
  out.wb_rf_ctrl  := RegEnable(in.wb_rf_ctrl, 0.U.asTypeOf(new WbRfCtrlIO), in.reg_en)
  out.wb_csr_ctrl := RegEnable(in.wb_csr_ctrl, 0.U.asTypeOf(new WbCsrCtrlIO), in.reg_en)

  val reset_t    = RegNext(reset.asBool(), 0.B)
  val reg_en_t   = RegNext(in.reg_en.asBool(), 0.B)
  val mem_data_t = RegNext(out.mem_data, 0.U)
  out.mem_data := Mux(reset_t, 0.U, Mux(reg_en_t, in.mem_data, mem_data_t))

  out.valid := PipelineValid(reset.asBool(), in.reg_en) && (out.inst =/= 0.U)

  if (!tapeout) {
    val dpi_wb = Module(new DpiWb)
    dpi_wb.io.valid := out.valid
    dpi_wb.io.pc    := out.pc
    dpi_wb.io.inst  := out.inst
  }

  override def desiredName = if (tapeout) ysyxid + "_" + getClassName else getClassName

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
    reg_en:      Bool
  ): WBreg = {
    val wb_reg = Module(new WBreg)
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

class DpiWb extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val valid = Input(Bool())
    val pc    = Input(UInt(64.W))
    val inst  = Input(UInt(32.W))
  })
  setInline(
    "DpiWb.v",
    """
      |import "DPI-C" function void wb_change(input logic v, input logic [63:0] p, input logic [31:0] i);
      |module DpiWb(input valid, input [63:0] pc, input [31:0] inst);
      |
      | always @* wb_change(valid, pc, inst);
      |
      |endmodule
            """.stripMargin
  )
}
