package RVnpc.RVNoob.Cache

import chisel3._
import chisel3.util._

class CacheSramIO extends Bundle {
  val addr  = Output(UInt(6.W))
  val cen   = Output(Bool())
  val wen   = Output(Bool())
  val wmask = Output(UInt(128.W))
  val wdata = Output(UInt(128.W))
  val rdata = Input(UInt(128.W))
}
