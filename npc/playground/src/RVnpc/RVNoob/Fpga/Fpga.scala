package RVnpc.RVNoob.Fpga

import chisel3._
import chisel3.util._

//----------------------Single Port Ram----------------------//
//ram_style: distributed / block / ultra
class SPRAM(data_width: Int, depth: Int, ram_style: String)
  extends BlackBox(Map("DATA_WIDTH" -> data_width, "DEPTH" -> depth, "RAM_STYLE_VAL" -> ram_style))
    with HasBlackBoxPath {
  val io = IO(new Bundle {
    val CLK = Input(Clock())
    val CEN = Input(Bool())
    val WEN = Input(Bool()) //0:W 1:R
    val A   = Input(UInt(log2Ceil(depth).W))
    val D   = Input(UInt(data_width.W))
    val Q   = Output(UInt(data_width.W))
  })
//  addPath("./playground/src/RVnpc/RVNoob/Fpga/SPRAM.v")
}

object SPRAM {
  def apply(data_width: Int, depth: Int, ram_style: String) = Module(new SPRAM(data_width, depth, ram_style)).io
}

class SPRAM_WRAP(data_width: Int, depth: Int, ram_style: String, rd_unchange: Boolean = false) extends Module {
  val io = IO(new Bundle {
    val en    = Input(Bool())
    val wr    = Input(Bool()) //0:W 1:R
    val addr  = Input(UInt(log2Ceil(depth).W))
    val wdata = Input(UInt(data_width.W))
    val rdata = Output(UInt(data_width.W))
  })
  val spram     = Module(new SPRAM(data_width, depth, ram_style))
  val rd_en = if (rd_unchange) Some(RegNext(io.en && io.wr)) else None
  val rdata_reg = if (rd_unchange) Some(RegEnable(spram.io.Q, rd_en.get)) else None

  spram.io.CLK <> clock
  spram.io.CEN <> !io.en
  spram.io.WEN <> io.wr
  spram.io.A   <> io.addr
  spram.io.D   <> io.wdata
  if (rd_unchange) {
    Mux(!rd_en.get, rdata_reg.get, spram.io.Q) <> io.rdata
  } else {
    spram.io.Q <> io.rdata
  }
}