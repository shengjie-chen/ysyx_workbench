package RVnpc.RVNoob.Axi

import RVnpc.RVNoob.RVNoobConfig
import chisel3._
import chisel3.util._

class AxiIO extends Bundle {
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
  val rready = Output(Bool())
  val rvalid = Input(Bool())
  val rresp  = Input(UInt(2.W))
  val rdata  = Input(UInt(64.W))
  val rlast  = Input(Bool())
  val rid    = Input(UInt(4.W))
}

class AxiWriteCtrlIO extends Bundle {
  val en         = Input(Bool())
  val id         = Input(UInt(4.W))
  val size       = Input(UInt(3.W))
  val wbuf_ready = Input(Bool())

  val burst      = Input(UInt(2.W)) // 0 - fix, 1 - incr
  val addr       = Input(UInt(32.W))
  val len        = Input(UInt(8.W))
  val data       = Input(UInt(64.W))
  val strb       = Input(UInt(8.W))

  val whandshake = Output(Bool())
  val bhandshake = Output(Bool())
}

class AxiReadCtrlIO extends Bundle {
  val en    = Input(Bool())
  val id    = Input(UInt(4.W))
  val addr  = Input(UInt(32.W))
  val size  = Input(UInt(3.W))

  val burst = Input(UInt(2.W))
  val len   = Input(UInt(8.W))

  val data      = Output(UInt(64.W))
  val handshake = Output(Bool())
}
