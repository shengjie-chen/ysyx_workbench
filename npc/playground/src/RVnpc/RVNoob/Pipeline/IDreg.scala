package RVnpc.RVNoob.Pipeline

import RVnpc.RVNoob.Branch._
import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

trait IDregSignal extends RVNoobConfig {
  val pc     = UInt(addr_w.W)
  val inst   = UInt(inst_w.W)
  val snpc   = UInt(addr_w.W)
  val br_pre = new branch_pre
}

class IDregOutIO extends PipelineOutIO with IDregSignal {}

class IDregInIO extends PipelineInIO with IDregSignal {}

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

  val reg_en_t = RegNext(in.reg_en.asBool(), 0.B)
  val inst_t   = RegNext(out.inst, 0.U)
  out.inst := Mux(reg_en_t, in.inst, inst_t)

  out.valid      := RegNext(in.reg_en && in.valid, 0.B)
  out.inst_valid := (out.inst =/= 0.U)

  out.br_pre := RegEnable(in.br_pre, 0.U.asTypeOf(new branch_pre), in.reg_en)

  override def desiredName = if (tapeout) ysyxid + "_" + getClassName else getClassName

}

//object IDreg {
//  def apply(
//    pc:     UInt,
//    inst:   UInt,
//    snpc:   UInt,
//    reg_en: Bool,
//    valid:  Bool,
//    br_pre: branch_pre
//  ): IDreg = {
//    val id_reg = Module(new IDreg)
//    id_reg.in.pc   <> pc
//    id_reg.in.inst <> inst
//    id_reg.in.snpc <> snpc
//
//    id_reg.in.reg_en <> reg_en
//    id_reg.in.valid  <> valid
//    id_reg.in.br_pre <> br_pre
//
//    id_reg
//  }
//}
