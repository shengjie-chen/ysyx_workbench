package RVnpc.RVNoob

import chisel3._
import chisel3.util.HasBlackBoxInline

import scala.math._

class RF_read(
  val ADDR_WIDTH: Int = 5,
  val DATA_WIDTH: Int = 64)
    extends BlackBox {
  val io = IO(new Bundle {
    val rf = Input(Vec(pow(2, ADDR_WIDTH).toInt, UInt(DATA_WIDTH.W)))
  })
}



class RegisterFile(
  val ADDR_WIDTH: Int = 5,
  val DATA_WIDTH: Int = 64)
    extends Module with RVNoobConfig {
  val io = IO(new Bundle {
    val wb_rf_ctrl = Input(new WbRfCtrlIO)
    val wdata  = Input(UInt(xlen.W))

    val id_rf_ctrl = Input(new IdRfCtrlIO)

    val rdata1 = Output(UInt(DATA_WIDTH.W))
    val rdata2 = Output(UInt(DATA_WIDTH.W))

    val a0     = Output(UInt(DATA_WIDTH.W))

  })
  // init reg
  val reg_num: Int = pow(2, ADDR_WIDTH).toInt
  val rf      = Reg(Vec(reg_num, UInt(DATA_WIDTH.W)))
  val rf_read = Module(new RF_read)
  rf_read.io.rf <> rf

  when(reset.asBool) {
    for (i <- 1 to 31) {
      rf(i) := i.U
    }
  }
  // read src1 and src2
  val rdata1 = Wire(UInt(DATA_WIDTH.W))
  val rdata2 = Wire(UInt(DATA_WIDTH.W))
  rdata1    := rf(io.id_rf_ctrl.rs1)
  rdata2    := rf(io.id_rf_ctrl.rs2)
  io.rdata1 := Mux(io.id_rf_ctrl.ren1, rdata1, 0.U)
  io.rdata2 := Mux(io.id_rf_ctrl.ren2, rdata2, 0.U)

  // write reg
  when(io.wb_rf_ctrl.wen) {
    rf(io.wb_rf_ctrl.rd) := io.wdata
  }

  io.a0 := rf(10)
  rf(0) := 0.U

}

object RegisterFileGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(args, Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new RegisterFile())))
}
