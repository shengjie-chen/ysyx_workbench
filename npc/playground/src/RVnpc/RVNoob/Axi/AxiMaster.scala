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

  //--------------------
  //Write Address Channel
  //--------------------
  //  val start_single_burst_write == io.wctrl.en
  val awid               = RegEnable(io.wctrl.id, io.wctrl.en)
  val awaddr             = RegEnable(io.wctrl.addr, io.wctrl.en)
  val awlen              = RegEnable(io.wctrl.len, io.wctrl.en)
  val awsize             = RegEnable(io.wctrl.size, io.wctrl.en)
  val awburst            = RegEnable(Cat(0.U(1.W), io.wctrl.burst), io.wctrl.en)
  val awvalid            = RegInit(0.B)
  val busrt_write_active = RegInit(0.B)

  when(io.wctrl.en && !awvalid) {
    awvalid := 1.B
  }.elsewhen(io.maxi.awready && awvalid) {
    awvalid := 0.B
  }
  when(io.wctrl.en) {
    busrt_write_active := 1.B
  }.elsewhen(io.maxi.bvalid && io.maxi.bready) {
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
    (write_index === (awlen - 1.U) && (awlen >= 1.U) && io.wctrl.whandshake) || (awlen === 0.U) && busrt_write_active && !io.wctrl.whandshake
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
  val bready = RegInit(0.B)
  when(io.maxi.bvalid && !bready) {
    bready := 1.B
  }.elsewhen(bready) {
    bready := 0.B
  }
  io.maxi.bready      := bready
  io.wctrl.bhandshake := io.maxi.bready && io.maxi.bvalid

  //----------------------------
  //Read Address Channel
  //----------------------------
  val arid              = RegEnable(io.rctrl.id, io.rctrl.en)
  val araddr            = RegEnable(io.rctrl.addr, io.rctrl.en)
  val arlen             = RegEnable(io.rctrl.len, io.rctrl.en)
  val arsize            = RegEnable(io.rctrl.size, io.rctrl.en)
  val arburst           = RegEnable(Cat(0.U(1.W), io.rctrl.burst), io.rctrl.en)
  val arvalid           = RegInit(0.B)
  val busrt_read_active = RegInit(0.B)

  when(!arvalid && io.rctrl.en) {
    arvalid := 1.B
  }.elsewhen(arvalid && io.maxi.arready) {
    arvalid := 0.B
  }
  when(io.rctrl.en) {
    busrt_read_active := 1.B
  }.elsewhen(io.maxi.rvalid && io.maxi.rready && io.maxi.rlast) {
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
  val rready     = RegInit(0.B)
  val read_index = RegInit(0.U(2.W))
  when(io.maxi.rvalid) {
    when(io.maxi.rlast && rready) {
      rready := 0.B
    }.otherwise {
      rready := 1.B
    }
  }
  when(io.rctrl.en) {
    read_index := 0.U
  }.elsewhen(io.rctrl.handshake && read_index =/= arlen) {
    read_index := read_index + 1.U
  }
  io.maxi.rready     := rready
  io.rctrl.handshake := io.maxi.rready && io.maxi.rvalid
  io.rctrl.data      := io.maxi.rdata
  io.busy            := busrt_read_active || busrt_write_active
}
