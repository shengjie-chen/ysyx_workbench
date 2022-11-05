package RVnpc.RVNoob.Pipeline

import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

class PipelineIO extends Bundle with RVNoobConfig {
  val pc   = UInt(xlen.W)
  val inst = UInt(inst_w.W)
//  val valid = Bool()
}

class PipelineInIO extends PipelineIO {
//  val pc_en = Bool()
//  val inst_en = Bool()
  val reg_en = Bool()
}

class PipelineOutIO extends PipelineIO {}
