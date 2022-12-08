package RVnpc.RVNoob.Pipeline

import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

class PipelineIO extends Bundle with RVNoobConfig {
  val pc   = UInt(xlen.W)
  val inst = UInt(inst_w.W)
  val valid = Bool()
}

class PipelineInIO extends PipelineIO {
//  val pc_en = Bool()
//  val inst_en = Bool()
  val reg_en = Bool()
}

class PipelineOutIO extends PipelineIO {
}

//TODO
// need to optimization, can delete one state
/**
 *  for pipeline reg, if reg_en=0 or reset, next clock valid is 0
 */
class PipelineValid extends Module {
  val io = IO(new Bundle {
    val reg_en = Input(Bool())
    val valid  = Output(Bool())
  })

  val sValid :: sInvalid :: sDelay :: Nil = Enum(3)
  val state                               = RegInit(sInvalid)

  io.valid := state === sValid

  switch(state) {
    is(sValid) {
      when(!io.reg_en) {
        state := sDelay
      }
    }
    is(sDelay) {
      when(io.reg_en) {
        state := sValid
      }.otherwise {
        state := sInvalid
      }
    }
    is(sInvalid) {
      when(io.reg_en) {
        state := sValid
      }
    }
  }

}

object PipelineValid {
  def apply(
    flush:  Bool,
    reg_en: Bool
  ): Bool = {
    val ppl_valid = Module(new PipelineValid)
    ppl_valid.reset     <> flush
    ppl_valid.io.reg_en <> reg_en
    ppl_valid.io.valid
  }
}
