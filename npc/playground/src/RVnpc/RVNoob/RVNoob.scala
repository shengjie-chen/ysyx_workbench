package RVnpc.RVNoob

import chisel3._
import chisel3.util._
import Pipeline._
import RVnpc.RVNoob.Cache.{CacheSramIO, DCache, ICache, JudgeLoad, S011HD1P_X32Y2D128_BW}

class RVNoob extends Module with ext_function with RVNoobConfig {
  val io = IO(new Bundle {
    val pc      = Output(UInt(64.W))
    val ebreak  = Output(Bool())
    val diff_en = Output(Bool())
    val diff_pc = Output(UInt(64.W))
  })
  // >>>>>>>>>>>>>> RVNoobCore <<<<<<<<<<<<<<
  val core = Module(new RVNoobCore)
  // >>>>>>>>>>>>>> Inst Cache Sram <<<<<<<<<<<<<<
  val sram0 = Module(new S011HD1P_X32Y2D128_BW)
  val sram1 = Module(new S011HD1P_X32Y2D128_BW)
  val sram2 = Module(new S011HD1P_X32Y2D128_BW)
  val sram3 = Module(new S011HD1P_X32Y2D128_BW)
  // >>>>>>>>>>>>>> Data Cache Sram <<<<<<<<<<<<<<
  val sram4 = Module(new S011HD1P_X32Y2D128_BW)
  val sram5 = Module(new S011HD1P_X32Y2D128_BW)
  val sram6 = Module(new S011HD1P_X32Y2D128_BW)
  val sram7 = Module(new S011HD1P_X32Y2D128_BW)

  io.pc      <> core.io.pc
  io.ebreak  <> core.io.ebreak
  io.diff_en <> core.io.diff_en
  io.diff_pc <> core.io.diff_pc

  // >>>>>>>>>>>>>> Inst Cache Sram <<<<<<<<<<<<<<
  sram0.io.CLK  <> clock
  sram0.io.Q    <> core.io.sram0.rdata
  sram0.io.CEN  <> core.io.sram0.cen
  sram0.io.WEN  <> core.io.sram0.wen
  sram0.io.BWEN <> core.io.sram0.wmask
  sram0.io.A    <> core.io.sram0.addr
  sram0.io.D    <> core.io.sram0.wdata

  sram1.io.CLK  <> clock
  sram1.io.Q    <> core.io.sram1.rdata
  sram1.io.CEN  <> core.io.sram1.cen
  sram1.io.WEN  <> core.io.sram1.wen
  sram1.io.BWEN <> core.io.sram1.wmask
  sram1.io.A    <> core.io.sram1.addr
  sram1.io.D    <> core.io.sram1.wdata

  sram2.io.CLK  <> clock
  sram2.io.Q    <> core.io.sram2.rdata
  sram2.io.CEN  <> core.io.sram2.cen
  sram2.io.WEN  <> core.io.sram2.wen
  sram2.io.BWEN <> core.io.sram2.wmask
  sram2.io.A    <> core.io.sram2.addr
  sram2.io.D    <> core.io.sram2.wdata

  sram3.io.CLK  <> clock
  sram3.io.Q    <> core.io.sram3.rdata
  sram3.io.CEN  <> core.io.sram3.cen
  sram3.io.WEN  <> core.io.sram3.wen
  sram3.io.BWEN <> core.io.sram3.wmask
  sram3.io.A    <> core.io.sram3.addr
  sram3.io.D    <> core.io.sram3.wdata

  // >>>>>>>>>>>>>> Data Cache Sram <<<<<<<<<<<<<<
  sram4.io.CLK  <> clock
  sram4.io.Q    <> core.io.sram4.rdata
  sram4.io.CEN  <> core.io.sram4.cen
  sram4.io.WEN  <> core.io.sram4.wen
  sram4.io.BWEN <> core.io.sram4.wmask
  sram4.io.A    <> core.io.sram4.addr
  sram4.io.D    <> core.io.sram4.wdata

  sram5.io.CLK  <> clock
  sram5.io.Q    <> core.io.sram5.rdata
  sram5.io.CEN  <> core.io.sram5.cen
  sram5.io.WEN  <> core.io.sram5.wen
  sram5.io.BWEN <> core.io.sram5.wmask
  sram5.io.A    <> core.io.sram5.addr
  sram5.io.D    <> core.io.sram5.wdata

  sram6.io.CLK  <> clock
  sram6.io.Q    <> core.io.sram6.rdata
  sram6.io.CEN  <> core.io.sram6.cen
  sram6.io.WEN  <> core.io.sram6.wen
  sram6.io.BWEN <> core.io.sram6.wmask
  sram6.io.A    <> core.io.sram6.addr
  sram6.io.D    <> core.io.sram6.wdata

  sram7.io.CLK  <> clock
  sram7.io.Q    <> core.io.sram7.rdata
  sram7.io.CEN  <> core.io.sram7.cen
  sram7.io.WEN  <> core.io.sram7.wen
  sram7.io.BWEN <> core.io.sram7.wmask
  sram7.io.A    <> core.io.sram7.addr
  sram7.io.D    <> core.io.sram7.wdata
}

object RVNoobGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(args, Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new RVNoob())))
}
