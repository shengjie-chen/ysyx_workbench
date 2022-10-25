package RVnpc.RVNoob

import chisel3._
import chisel3.util._

trait AxiParameters {
  val AxiAddrWidth = 4
  val AxiDataWidth = 32
}

object AxiParameters extends AxiParameters { }

class Axi4LiteA extends Bundle with AxiParameters {
  val addr = Output(UInt(AxiAddrWidth.W))
}

class Axi4LiteW extends Bundle with AxiParameters {
  val data = Output(UInt(AxiDataWidth.W))
  val strb = Output(UInt((AxiDataWidth/8).W)) // 写掩码
}

class Axi4LiteB extends Bundle with AxiParameters {
  val resp = Output(UInt(2.W))
}

class Axi4LiteR extends Bundle with AxiParameters {
  val resp = Output(UInt(2.W))
  val data = Output(UInt(AxiDataWidth.W))
}

// Decoupled: 为接口包装一层valid 和 ready
// Flipped: 翻转端口列表的方向
class Axi4LiteIO extends Bundle {
  val aw = Decoupled(new Axi4LiteA)         // AXI4-Lite Write Address Channel Signals
  val w = Decoupled(new Axi4LiteW)          // AXI4-Lite Write Data Channel Signals
  val b = Flipped(Decoupled(new Axi4LiteB)) // AXI4-Lite Write Response Channel Signals
  val ar = Decoupled(new Axi4LiteA)         // AXI4-Lite Read Address Channel Signals
  val r = Flipped(Decoupled(new Axi4LiteR)) // AXI4-Lite Read Data Channel Signals
}