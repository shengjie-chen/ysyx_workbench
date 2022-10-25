package RVnpc.RVNoob

import chisel3._
import chisel3.util._

class PipelineIO extends Bundle with RVNoobConfig {
  val pc = UInt(xlen.W)
  val inst = UInt(inst_w.W)
}

class PipelineInIO extends PipelineIO {
  val pc_en = Bool()
  val inst_en = Bool()
}

class PipelineOutIO extends PipelineIO {
  val valid = Bool()
}

trait IDregSignal extends RVNoobConfig {
  val snpc = UInt(xlen.W)
}

class IDregOutIO extends PipelineOutIO with IDregSignal {}

class IDregInIO extends PipelineInIO with IDregSignal {
  val snpc_en = Bool()
}

class IDreg extends MultiIOModule with RVNoobConfig {
  val in = IO(Input(new IDregInIO))
  val out = IO(Output(new IDregOutIO))

  out.pc := RegEnable(in.pc, in.pc_en)
  out.inst := RegEnable(in.inst, in.inst_en)
  out.snpc := RegEnable(in.snpc, in.snpc_en)

}

object IDreg {
  def apply(pc: UInt, inst: UInt, snpc: UInt): IDreg = {
    val id_reg = Module(new IDreg)
    id_reg.in.pc <> pc
    id_reg.in.inst <> inst
    id_reg.in.snpc <> snpc

    id_reg.in.pc_en <> 1.B
    id_reg.in.inst_en <> 1.B
    id_reg.in.snpc_en <> 1.B

    id_reg
  }
}

trait EXregSignal extends RVNoobConfig {
  val src1 = UInt(xlen.W)
  val src2 = UInt(xlen.W)
  val imm = UInt(xlen.W)
  val exe_ctrl = new EXECtrlIO
  val pmem_ctrl = new MemCtrlIO
  val rfwb_ctrl = new WBCtrlIO
  val dnpc_jalr = Bool()
  val pc_mux = Bool()
}

class EXregInIO extends IDregInIO with EXregSignal {
  val src1_en = Bool()
  val src2_en = Bool()
  val imm_en = Bool()
  val exe_ctrl_en = Bool()
  val pmem_ctrl_en = Bool()
  val rfwb_ctrl_en = Bool()
  val dnpc_jalr_en = Bool()
  val pc_mux_en = Bool()
}

class EXregOutIO extends IDregOutIO with EXregSignal {}

class EXreg extends MultiIOModule with RVNoobConfig {
  val in = IO(Input(new EXregInIO))
  val out = IO(Output(new EXregOutIO))

  out.pc := RegEnable(in.pc, in.pc_en)
  out.inst := RegEnable(in.inst, in.inst_en)
  out.snpc := RegEnable(in.snpc, in.snpc_en)
  out.src1 := RegEnable(in.src1, in.src1_en)
  out.src2 := RegEnable(in.src2, in.src2_en)
  out.imm := RegEnable(in.imm, in.imm_en)
  out.exe_ctrl := RegEnable(in.exe_ctrl, in.exe_ctrl_en)
  out.pmem_ctrl := RegEnable(in.pmem_ctrl, in.pmem_ctrl_en)
  out.rfwb_ctrl := RegEnable(in.rfwb_ctrl, in.rfwb_ctrl_en)
  out.dnpc_jalr := RegEnable(in.dnpc_jalr, in.dnpc_jalr_en)
  out.pc_mux := RegEnable(in.pc_mux, in.pc_mux_en)

}

object EXreg {
  def apply(
             pc: UInt,
             inst: UInt,
             snpc: UInt,
             src1: UInt,
             src2: UInt,
             imm: UInt,
             exe_ctrl: EXECtrlIO,
             pmem_ctrl: MemCtrlIO,
             rfwb_ctrl: WBCtrlIO,
             dnpc_jalr: Bool,
             pc_mux: Bool
           ): EXreg = {
    val ex_reg = Module(new EXreg)
    ex_reg.in.pc <> pc
    ex_reg.in.inst <> inst
    ex_reg.in.snpc <> snpc
    ex_reg.in.src1 <> src1
    ex_reg.in.src2 <> src2
    ex_reg.in.imm <> imm
    ex_reg.in.exe_ctrl <> exe_ctrl
    ex_reg.in.pmem_ctrl <> pmem_ctrl
    ex_reg.in.rfwb_ctrl <> rfwb_ctrl
    ex_reg.in.dnpc_jalr <> dnpc_jalr
    ex_reg.in.pc_mux <> pc_mux

    ex_reg.in.pc_en <> 1.B
    ex_reg.in.inst_en <> 1.B
    ex_reg.in.snpc_en <> 1.B
    ex_reg.in.src1_en <> 1.B
    ex_reg.in.src2_en <> 1.B
    ex_reg.in.imm_en <> 1.B
    ex_reg.in.exe_ctrl_en <> 1.B
    ex_reg.in.pmem_ctrl_en <> 1.B
    ex_reg.in.rfwb_ctrl_en <> 1.B
    ex_reg.in.dnpc_jalr_en <> 1.B
    ex_reg.in.pc_mux_en <> 1.B

    ex_reg
  }
}

trait MEMregSignal extends RVNoobConfig {
  val dnpc = UInt(xlen.W)
  val src2 = UInt(xlen.W)
  val mem_addr = UInt(xlen.W)
  val alu_res = UInt(xlen.W)
  val B_en = UInt(xlen.W)
  val pmem_ctrl = new MemCtrlIO
  val rfwb_ctrl = new WBCtrlIO

}

class MEMregOutIO extends PipelineOutIO with MEMregSignal {}

class MEMregInIO extends PipelineInIO with MEMregSignal {
  val dnpc_en = Bool()
  val src2_en = Bool()
  val mem_addr_en = Bool()
  val alu_res_en = Bool()
  val B_en_en = Bool()
  val pmem_ctrl_en = Bool()
  val rfwb_ctrl_en = Bool()

}

class MEMreg extends MultiIOModule with RVNoobConfig {
  val in = IO(Input(new MEMregInIO))
  val out = IO(Output(new MEMregOutIO))

  out.pc := RegEnable(in.pc, in.pc_en)
  out.inst := RegEnable(in.inst, in.inst_en)
  out.dnpc := RegEnable(in.dnpc, in.dnpc_en)
  out.src2 := RegEnable(in.src2, in.src2_en)
  out.mem_addr := RegEnable(in.mem_addr, in.mem_addr_en)
  out.alu_res := RegEnable(in.alu_res, in.alu_res_en)
  out.rfwb_ctrl := RegEnable(in.rfwb_ctrl, in.rfwb_ctrl_en)
  out.B_en := RegEnable(in.B_en, in.B_en_en)
  out.pmem_ctrl := RegEnable(in.pmem_ctrl, in.pmem_ctrl_en)

}

object MEMreg {
  def apply(
             pc: UInt,
             inst: UInt,
             dnpc: UInt,
             src2: UInt,
             mem_addr: UInt,
             alu_res: UInt,
             B_en: Bool,
             pmem_ctrl: MemCtrlIO, rfwb_ctrl: WBCtrlIO
           ): MEMreg = {
    val mem_reg = Module(new MEMreg)
    mem_reg.in.pc <> pc
    mem_reg.in.inst <> inst
    mem_reg.in.dnpc <> dnpc
    mem_reg.in.src2 <> src2
    mem_reg.in.mem_addr <> mem_addr
    mem_reg.in.alu_res <> alu_res
    mem_reg.in.B_en <> B_en
    mem_reg.in.pmem_ctrl <> pmem_ctrl
    mem_reg.in.rfwb_ctrl <> rfwb_ctrl

    mem_reg.in.pc_en <> 1.B
    mem_reg.in.inst_en <> 1.B
    mem_reg.in.dnpc_en <> 1.B
    mem_reg.in.src2_en <> 1.B
    mem_reg.in.mem_addr_en <> 1.B
    mem_reg.in.alu_res_en <> 1.B
    mem_reg.in.B_en_en <> 1.B
    mem_reg.in.pmem_ctrl_en <> 1.B
    mem_reg.in.rfwb_ctrl_en <> 1.B

    mem_reg
  }
}

trait WBregSignal extends RVNoobConfig {
  val alu_res = UInt(xlen.W)
  val mem_data = UInt(xlen.W)
  val r_pmem = Bool()
  val rfwb_ctrl = new WBCtrlIO

}

class WBregOutIO extends PipelineOutIO with WBregSignal {}

class WBregInIO extends PipelineInIO with WBregSignal {
  val alu_res_en = Bool()
  val mem_data_en = Bool()
  val r_pmem_en = Bool()
  val rfwb_ctrl_en = Bool()

}

class WBreg extends MultiIOModule with RVNoobConfig {
  val in = IO(Input(new WBregInIO))
  val out = IO(Output(new WBregOutIO))

  out.pc := RegEnable(in.pc, in.pc_en)
  out.inst := RegEnable(in.inst, in.inst_en)
  out.alu_res := RegEnable(in.alu_res, in.alu_res_en)
  out.mem_data := RegEnable(in.mem_data, in.mem_data_en)
  out.r_pmem := RegEnable(in.r_pmem, in.r_pmem_en)
  out.rfwb_ctrl := RegEnable(in.rfwb_ctrl, in.rfwb_ctrl_en)

}

object WBreg {
  def apply(pc: UInt, inst: UInt, alu_res: UInt, mem_data: UInt, r_pmem: UInt, rfwb_ctrl: WBCtrlIO): WBreg = {
    val wb_reg = Module(new WBreg)
    wb_reg.in.pc <> pc
    wb_reg.in.inst <> inst
    wb_reg.in.alu_res <> alu_res
    wb_reg.in.mem_data <> mem_data
    wb_reg.in.r_pmem <> r_pmem
    wb_reg.in.rfwb_ctrl <> rfwb_ctrl

    wb_reg.in.pc_en <> 1.B
    wb_reg.in.inst_en <> 1.B
    wb_reg.in.alu_res_en <> 1.B
    wb_reg.in.mem_data_en <> 1.B
    wb_reg.in.r_pmem_en <> 1.B
    wb_reg.in.rfwb_ctrl_en <> 1.B


    wb_reg
  }
}
