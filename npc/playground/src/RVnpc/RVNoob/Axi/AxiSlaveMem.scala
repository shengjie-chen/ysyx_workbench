package RVnpc.RVNoob.Axi

import chisel3._

class AxiSlaveMem extends BlackBox {
  val io = IO(new Bundle {
    val PC = Input(UInt(64.W))

    val S_AXI_ACLK    = Input(Clock())
    val S_AXI_ARESETN = Input(Bool())

    val S_AXI_AWVALID = Input(Bool())
    val S_AXI_AWREADY = Output(Bool())
    val S_AXI_AWID    = Input(UInt(4.W))
    val S_AXI_AWADDR  = Input(UInt(32.W))
    val S_AXI_AWLEN   = Input(UInt(8.W))
    val S_AXI_AWSIZE  = Input(UInt(3.W))
    val S_AXI_AWBURST = Input(UInt(2.W))

    val S_AXI_WVALID = Input(Bool())
    val S_AXI_WREADY = Output(Bool())
    val S_AXI_WDATA  = Input(UInt(64.W))
    val S_AXI_WSTRB  = Input(UInt(8.W))
    val S_AXI_WLAST  = Input(Bool())

    val S_AXI_BVALID = Output(Bool())
    val S_AXI_BREADY = Input(Bool())
    val S_AXI_BID    = Output(UInt(4.W))
    val S_AXI_BRESP  = Output(UInt(2.W))

    val S_AXI_ARVALID = Input(Bool())
    val S_AXI_ARREADY = Output(Bool())
    val S_AXI_ARID    = Input(UInt(4.W))
    val S_AXI_ARADDR  = Input(UInt(32.W))
    val S_AXI_ARLEN   = Input(UInt(8.W))
    val S_AXI_ARSIZE  = Input(UInt(3.W))
    val S_AXI_ARBURST = Input(UInt(2.W))

    val S_AXI_RVALID = Output(Bool())
    val S_AXI_RREADY = Input(Bool())
    val S_AXI_RID    = Output(UInt(4.W))
    val S_AXI_RDATA  = Output(UInt(64.W))
    val S_AXI_RRESP  = Output(UInt(2.W))
    val S_AXI_RLAST  = Output(Bool())

  })
}
