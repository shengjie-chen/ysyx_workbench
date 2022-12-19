package RVnpc.RVNoob.Pipeline

import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

trait IDregSignal extends RVNoobConfig {
  val snpc = UInt(xlen.W)
}

class IDregOutIO extends PipelineOutIO with IDregSignal {}

class IDregInIO extends PipelineInIO with IDregSignal {
//  val snpc_en = Bool()
}

//class CombRegEnable() extends Module{
//  val io = IO(new Bundle{
//    val in =
//  })
//}

class IDreg extends MultiIOModule with RVNoobConfig {
  val in  = IO(Input(new IDregInIO))
  val out = IO(Output(new IDregOutIO))
  dontTouch(in)
  dontTouch(out)

  out.pc   := RegEnable(in.pc, 0.U, in.reg_en)
  out.snpc := RegEnable(in.snpc, 0.U, in.reg_en)

  val reset_t  = RegNext(reset.asBool())
  val reg_en_t = RegNext(in.reg_en.asBool())
  val inst_t   = RegNext(out.inst)
  out.inst := Mux(reset_t, 0.U, Mux(reg_en_t, in.inst, inst_t))

  out.valid := PipelineValid(reset.asBool(), in.reg_en) && (out.inst =/= 0.U)
}

object IDreg {
  def apply(pc: UInt, inst: UInt, snpc: UInt, reg_en: Bool): IDreg = {
    val id_reg = Module(new IDreg)
    id_reg.in.pc   <> pc
    id_reg.in.inst <> inst
    id_reg.in.snpc <> snpc

    id_reg.in.reg_en <> reg_en

    id_reg
  }

}
