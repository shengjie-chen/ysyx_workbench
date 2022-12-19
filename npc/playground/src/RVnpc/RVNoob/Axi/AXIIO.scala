package RVnpc.RVNoob.Axi

import chisel3._
import chisel3.util._

class AXIIO extends Bundle {
  // >>>>>>>>>>>>>> AW <<<<<<<<<<<<<<
  val awready = Input(Bool())
  val awvalid = Output(Bool())
  val awaddr  = Output(UInt(32.W))
  val awid    = Output(UInt(4.W))
  val awlen   = Output(UInt(8.W))
  val awsize  = Output(UInt(3.W))
  val awburst = Output(UInt(2.W))
  // >>>>>>>>>>>>>> W <<<<<<<<<<<<<<
  val wready = Input(Bool())
  val wvalid = Output(Bool())
  val wdata  = Output(UInt(64.W))
  val wstrb  = Output(UInt(8.W))
  val wlast  = Output(Bool())
  // >>>>>>>>>>>>>> B <<<<<<<<<<<<<<
  val bready = Output(Bool())
  val bvalid = Input(Bool())
  val bresp  = Input(UInt(2.W))
  val bid    = Input(UInt(4.W))
  // >>>>>>>>>>>>>> AR <<<<<<<<<<<<<<
  val arready = Input(Bool())
  val arvalid = Output(Bool())
  val araddr  = Output(UInt(32.W))
  val arid    = Output(UInt(4.W))
  val arlen   = Output(UInt(8.W))
  val arsize  = Output(UInt(3.W))
  val arburst = Output(UInt(2.W))
  // >>>>>>>>>>>>>> R <<<<<<<<<<<<<<
  val rready = Input(Bool())
  val rvalid = Output(Bool())
  val rdata  = Output(UInt(64.W))
  val rstrb  = Output(UInt(8.W))
  val rlast  = Output(Bool())
}
