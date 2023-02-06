package RVnpc.RVNoob.Pipeline

import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

trait IDregSignal extends RVNoobConfig {
  val pc   = UInt(addr_w.W)
  val inst = UInt(inst_w.W)

  val snpc = UInt(addr_w.W)
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
  if (!tapeout) {
    dontTouch(in)
    dontTouch(out)
  }

  out.pc   := RegEnable(in.pc, 0.U, in.reg_en)
  out.snpc := RegEnable(in.snpc, 0.U, in.reg_en)

  val reset_t  = RegNext(reset.asBool(), 0.B)
  val reg_en_t = RegNext(in.reg_en.asBool(), 0.B)
  val inst_t   = RegNext(out.inst, 0.U)
  out.inst := Mux(reset_t, 0.U, Mux(reg_en_t, in.inst, inst_t))

  out.valid := RegNext(in.reg_en, 0.B) && (out.inst =/= 0.U)

  override def desiredName = if (tapeout) ysyxid + "_" + getClassName else getClassName

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
