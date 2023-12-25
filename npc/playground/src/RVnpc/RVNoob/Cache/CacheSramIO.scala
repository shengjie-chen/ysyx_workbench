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

class BramIO(cacheSize: Int) extends Bundle {
  val en    = Output(Bool())
  val wr    = Output(Bool()) //0:W 1:R
  val addr  = Output(UInt(log2Ceil(cacheSize / (128 / 8)).W)) // 8
  val wdata = Output(UInt(8.W))
  val rdata = Input(UInt(8.W))
}
