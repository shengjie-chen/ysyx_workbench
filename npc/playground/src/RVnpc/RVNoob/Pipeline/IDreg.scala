package RVnpc.RVNoob.Pipeline

import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

trait IDregSignal extends RVNoobConfig {
  val snpc = UInt(xlen.W)
}

class IDregOutIO extends PipelineOutIO with IDregSignal {}

class IDregInIO extends PipelineInIO with IDregSignal {
  val snpc_en = Bool()
}

class IDreg(bypass: Boolean = false) extends MultiIOModule with RVNoobConfig {
  val in  = IO(Input(new IDregInIO))
  val out = IO(Output(new IDregOutIO))
  if (bypass) {
    out.pc   := in.pc
    out.inst := in.inst
    out.snpc := in.snpc
  } else {
    out.pc   := RegEnable(in.pc, in.pc_en)
    out.inst := RegEnable(in.inst, in.inst_en)
    out.snpc := RegEnable(in.snpc, in.snpc_en)
  }
}

object IDreg {
  def apply(pc: UInt, inst: UInt, snpc: UInt, bypass: Boolean = false): IDreg = {
    val id_reg = Module(new IDreg(bypass))
    id_reg.in.pc <> pc
    id_reg.in.inst <> inst
    id_reg.in.snpc <> snpc

    id_reg.in.pc_en <> 1.B
    id_reg.in.inst_en <> 1.B
    id_reg.in.snpc_en <> 1.B

    id_reg
  }

}
