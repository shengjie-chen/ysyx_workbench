package RVnpc.RVNoob.Axi

import RVnpc.RVNoob.RVNoobConfig
import chisel3._
import chisel3.util._

class AxiRegSlice extends Module with RVNoobConfig {
  val io = IO(new Bundle {
    val maxi = new AxiIO
    val saxi = Flipped(new AxiIO)
  })
  // >>>>>>>>>>>>>> AW <<<<<<<<<<<<<<
  io.maxi.awready <> io.saxi.awready
  io.maxi.awvalid <> io.saxi.awvalid
  io.maxi.awaddr  <> io.saxi.awaddr
  io.maxi.awid    <> io.saxi.awid
  io.maxi.awlen   <> io.saxi.awlen
  io.maxi.awsize  <> io.saxi.awsize
  io.maxi.awburst <> io.saxi.awburst

  // >>>>>>>>>>>>>> W <<<<<<<<<<<<<<
  val wvalid = Reg(Bool())
  val wdata  = Reg(UInt(64.W))
  val wstrb  = Reg(UInt(8.W))
  val wlast  = Reg(Bool())

  when(!wvalid || io.maxi.wready) {
    io.saxi.wready := 1.B
  }.otherwise {
    io.saxi.wready := 0.B
  }

  when(io.saxi.wvalid && (!wvalid || io.maxi.wready)) {
    wdata := io.saxi.wdata
    wstrb := io.saxi.wstrb
    wlast := io.saxi.wlast
  }

  when(!wvalid || io.maxi.wready) {
    wvalid := io.saxi.wvalid
  }

  io.maxi.wvalid := wvalid
  io.maxi.wdata  := wdata
  io.maxi.wstrb  := wstrb
  io.maxi.wlast  := wlast

  // >>>>>>>>>>>>>> B <<<<<<<<<<<<<<
  io.maxi.bready <> io.saxi.bready
  io.maxi.bvalid <> io.saxi.bvalid
  io.maxi.bresp  <> io.saxi.bresp
  io.maxi.bid    <> io.saxi.bid

  // >>>>>>>>>>>>>> AR <<<<<<<<<<<<<<
  io.maxi.arready <> io.saxi.arready
  io.maxi.arvalid <> io.saxi.arvalid
  io.maxi.araddr  <> io.saxi.araddr
  io.maxi.arid    <> io.saxi.arid
  io.maxi.arlen   <> io.saxi.arlen
  io.maxi.arsize  <> io.saxi.arsize
  io.maxi.arburst <> io.saxi.arburst

  // >>>>>>>>>>>>>> R <<<<<<<<<<<<<<
  val rvalid = Reg(Bool())
  val rresp  = Reg(UInt(2.W))
  val rdata  = Reg(UInt(64.W))
  val rlast  = Reg(Bool())
  val rid    = Reg(UInt(4.W))

  when(!rvalid || io.saxi.rready) {
    io.maxi.rready := 1.B
  }.otherwise {
    io.maxi.rready := 0.B
  }

  when(io.maxi.rvalid && (!rvalid || io.saxi.rready)) {
    rresp := io.maxi.rresp
    rdata := io.maxi.rdata
    rlast := io.maxi.rlast
    rid   := io.maxi.rid
  }

  when(!rvalid || io.saxi.rready) {
    rvalid := io.maxi.rvalid
  }

  io.saxi.rvalid := rvalid
  io.saxi.rresp  := rresp
  io.saxi.rdata  := rdata
  io.saxi.rlast  := rlast
  io.saxi.rid    := rid

}
