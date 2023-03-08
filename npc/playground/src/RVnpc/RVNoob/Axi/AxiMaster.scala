package RVnpc.RVNoob.Axi

import RVnpc.RVNoob.RVNoobConfig
import chisel3._
import chisel3.util._

class AxiMaster extends Module with RVNoobConfig {
  val io = IO(new Bundle {
    val maxi  = new AxiIO
    val rctrl = new AxiReadCtrlIO
    val wctrl = new AxiWriteCtrlIO
    val busy  = Output(Bool())
  })

  val rready = 1.B
  val bready = 1.B

  //--------------------
  //Write Address Channel
  //--------------------
  //  val start_single_burst_write == io.wctrl.en
  val awid               = RegEnable(io.wctrl.id, 0.U, io.wctrl.en)
  val awaddr             = RegEnable(io.wctrl.addr, 0.U, io.wctrl.en)
  val awlen              = RegEnable(io.wctrl.len, 0.U, io.wctrl.en)
  val awsize             = RegEnable(io.wctrl.size, 0.U, io.wctrl.en)
  val awburst            = RegEnable(io.wctrl.burst, 0.U, io.wctrl.en)
  val awvalid            = RegInit(0.B)
  val busrt_write_active = RegInit(0.B)

  when(io.wctrl.en && !awvalid) {
    awvalid := 1.B
  }.elsewhen(io.maxi.awready && awvalid) {
    awvalid := 0.B
  }
  when(io.wctrl.en) {
    busrt_write_active := 1.B
  }.elsewhen(io.maxi.bvalid && bready) {
    busrt_write_active := 0.B
  }

  io.maxi.awvalid <> awvalid
  io.maxi.awaddr  <> awaddr
  io.maxi.awid    <> awid
  io.maxi.awlen   <> awlen
  io.maxi.awsize  <> awsize
  io.maxi.awburst <> awburst

  //--------------------
  //Write Data Channel
  //--------------------
  val wvalid      = RegInit(0.B)
  val wlast       = RegInit(0.B)
  val write_index = RegInit(0.U(2.W))

  when(io.wctrl.wbuf_ready && !wvalid) {
    wvalid := 1.B
  }.elsewhen(io.wctrl.whandshake && wlast) {
    wvalid := 0.B
  }
  when(
    (write_index === (awlen - 1.U) && (awlen >= 1.U) && io.wctrl.whandshake) || ((io.wctrl.len === 0.U) && io.wctrl.en)
  ) {
    wlast := 1.B
  }.elsewhen(io.wctrl.whandshake) {
    wlast := 0.B
  }
  when(io.wctrl.en) {
    write_index := 0.U
  }.elsewhen(io.wctrl.whandshake && write_index =/= awlen) {
    write_index := write_index + 1.U
  }

  io.maxi.wdata       := io.wctrl.data // TODO
  io.maxi.wstrb       := io.wctrl.strb // TODO
  io.maxi.wvalid      := wvalid
  io.maxi.wlast       := wlast
  io.wctrl.whandshake := io.maxi.wready && io.maxi.wvalid

  //----------------------------
  //Write Response (B) Channel
  //----------------------------
  io.maxi.bready      := bready
  io.wctrl.bhandshake := bready && io.maxi.bvalid

  //----------------------------
  //Read Address Channel
  //----------------------------
  val arid              = RegEnable(io.rctrl.id, 0.U, io.rctrl.en)
  val araddr            = RegEnable(io.rctrl.addr, 0.U, io.rctrl.en)
  val arlen             = RegEnable(io.rctrl.len, 0.U, io.rctrl.en)
  val arsize            = RegEnable(io.rctrl.size, 0.U, io.rctrl.en)
  val arburst           = RegEnable(io.rctrl.burst, 0.U, io.rctrl.en)
  val arvalid           = RegInit(0.B)
  val busrt_read_active = RegInit(0.B)

  when(!arvalid && io.rctrl.en) {
    arvalid := 1.B
  }.elsewhen(arvalid && io.maxi.arready) {
    arvalid := 0.B
  }
  when(io.rctrl.en) {
    busrt_read_active := 1.B
  }.elsewhen(io.maxi.rvalid && rready && io.maxi.rlast) {
    busrt_read_active := 0.B
  }
  io.maxi.arvalid <> arvalid
  io.maxi.araddr  <> araddr
  io.maxi.arid    <> arid
  io.maxi.arlen   <> arlen
  io.maxi.arsize  <> arsize
  io.maxi.arburst <> arburst

  //--------------------------------
  //Read Data (and Response) Channel
  //--------------------------------
  val read_index = RegInit(0.U(2.W))
  when(io.rctrl.en) {
    read_index := 0.U
  }.elsewhen(io.rctrl.handshake && read_index =/= arlen) {
    read_index := read_index + 1.U
  }
  io.maxi.rready     := rready
  io.rctrl.handshake := rready && io.maxi.rvalid
  io.rctrl.data      := io.maxi.rdata
  io.busy            := busrt_read_active || busrt_write_active

  override def desiredName = if (tapeout) ysyxid + "_" + getClassName else getClassName
}
