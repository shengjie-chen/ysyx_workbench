package RVnpc.RVNoob

import RVnpc.RVNoob.Axi.AxiSlaveMem
import RVnpc.RVNoob.Cache.S011HD1P_X32Y2D128_BW
import RVnpc.RVNoob.Fpga.SPRAM_WRAP
import chisel3._

import scala.math.pow

class RVNoob extends Module with ext_function with RVNoobConfig {
  val io = IO(new Bundle {
    val pc        = Output(UInt(addr_w.W))
    val ebreak    = Output(Bool())
    val diff_en   = Output(Bool())
    val diff_pc   = Output(UInt(addr_w.W))
    val diff_inst = Output(UInt(inst_w.W))
    val inst_cnt  = Output(UInt(xlen.W))
  })
  // >>>>>>>>>>>>>> RVNoobCore <<<<<<<<<<<<<<
  val core = RVNoobCore()
  // >>>>>>>>>>>>>> Inst Cache Sram <<<<<<<<<<<<<<
  val sram0 = if (!fpga) Some(Module(new S011HD1P_X32Y2D128_BW)) else None
  val sram1 = if (!fpga) Some(Module(new S011HD1P_X32Y2D128_BW)) else None
  val sram2 = if (!fpga) Some(Module(new S011HD1P_X32Y2D128_BW)) else None
  val sram3 = if (!fpga) Some(Module(new S011HD1P_X32Y2D128_BW)) else None
  // >>>>>>>>>>>>>> Data Cache Sram <<<<<<<<<<<<<<
  val sram4 = if (!fpga) Some(Module(new S011HD1P_X32Y2D128_BW)) else None
  val sram5 = if (!fpga) Some(Module(new S011HD1P_X32Y2D128_BW)) else None
  val sram6 = if (!fpga) Some(Module(new S011HD1P_X32Y2D128_BW)) else None
  val sram7 = if (!fpga) Some(Module(new S011HD1P_X32Y2D128_BW)) else None
  // >>>>>>>>>>>>>> FPGA Cache Bram <<<<<<<<<<<<<<
  val i_bram =
    if (fpga)
      Some(Seq.fill(16)(Module(new SPRAM_WRAP(8, (ICacheSize * pow(2, 10) / (128 / 8)).toInt, "block"))))
    else None
  val d_bram =
    if (fpga)
      Some(Seq.fill(16)(Module(new SPRAM_WRAP(8, (DCacheSize * pow(2, 10) / (128 / 8)).toInt, "block"))))
    else None
  // >>>>>>>>>>>>>> SAXI <<<<<<<<<<<<<<
  val axi_pmem = Module(new AxiSlaveMem)

  io.pc        <> core.io.pc.get
  io.ebreak    <> core.io.ebreak.get
  io.diff_en   <> core.io.diff_en.get
  io.diff_pc   <> core.io.diff_pc.get
  io.diff_inst <> core.io.diff_inst.get
  io.inst_cnt  <> core.io.inst_cnt.get

  if (!fpga) {
    // >>>>>>>>>>>>>> Inst Cache Sram <<<<<<<<<<<<<<
    sram0.get.io.CLK  <> clock
    sram0.get.io.Q    <> core.io.sram0.get.rdata
    sram0.get.io.CEN  <> core.io.sram0.get.cen
    sram0.get.io.WEN  <> core.io.sram0.get.wen
    sram0.get.io.BWEN <> core.io.sram0.get.wmask
    sram0.get.io.A    <> core.io.sram0.get.addr
    sram0.get.io.D    <> core.io.sram0.get.wdata

    sram1.get.io.CLK  <> clock
    sram1.get.io.Q    <> core.io.sram1.get.rdata
    sram1.get.io.CEN  <> core.io.sram1.get.cen
    sram1.get.io.WEN  <> core.io.sram1.get.wen
    sram1.get.io.BWEN <> core.io.sram1.get.wmask
    sram1.get.io.A    <> core.io.sram1.get.addr
    sram1.get.io.D    <> core.io.sram1.get.wdata

    sram2.get.io.CLK  <> clock
    sram2.get.io.Q    <> core.io.sram2.get.rdata
    sram2.get.io.CEN  <> core.io.sram2.get.cen
    sram2.get.io.WEN  <> core.io.sram2.get.wen
    sram2.get.io.BWEN <> core.io.sram2.get.wmask
    sram2.get.io.A    <> core.io.sram2.get.addr
    sram2.get.io.D    <> core.io.sram2.get.wdata

    sram3.get.io.CLK  <> clock
    sram3.get.io.Q    <> core.io.sram3.get.rdata
    sram3.get.io.CEN  <> core.io.sram3.get.cen
    sram3.get.io.WEN  <> core.io.sram3.get.wen
    sram3.get.io.BWEN <> core.io.sram3.get.wmask
    sram3.get.io.A    <> core.io.sram3.get.addr
    sram3.get.io.D    <> core.io.sram3.get.wdata

    // >>>>>>>>>>>>>> Data Cache Sram <<<<<<<<<<<<<<
    sram4.get.io.CLK  <> clock
    sram4.get.io.Q    <> core.io.sram4.get.rdata
    sram4.get.io.CEN  <> core.io.sram4.get.cen
    sram4.get.io.WEN  <> core.io.sram4.get.wen
    sram4.get.io.BWEN <> core.io.sram4.get.wmask
    sram4.get.io.A    <> core.io.sram4.get.addr
    sram4.get.io.D    <> core.io.sram4.get.wdata

    sram5.get.io.CLK  <> clock
    sram5.get.io.Q    <> core.io.sram5.get.rdata
    sram5.get.io.CEN  <> core.io.sram5.get.cen
    sram5.get.io.WEN  <> core.io.sram5.get.wen
    sram5.get.io.BWEN <> core.io.sram5.get.wmask
    sram5.get.io.A    <> core.io.sram5.get.addr
    sram5.get.io.D    <> core.io.sram5.get.wdata

    sram6.get.io.CLK  <> clock
    sram6.get.io.Q    <> core.io.sram6.get.rdata
    sram6.get.io.CEN  <> core.io.sram6.get.cen
    sram6.get.io.WEN  <> core.io.sram6.get.wen
    sram6.get.io.BWEN <> core.io.sram6.get.wmask
    sram6.get.io.A    <> core.io.sram6.get.addr
    sram6.get.io.D    <> core.io.sram6.get.wdata

    sram7.get.io.CLK  <> clock
    sram7.get.io.Q    <> core.io.sram7.get.rdata
    sram7.get.io.CEN  <> core.io.sram7.get.cen
    sram7.get.io.WEN  <> core.io.sram7.get.wen
    sram7.get.io.BWEN <> core.io.sram7.get.wmask
    sram7.get.io.A    <> core.io.sram7.get.addr
    sram7.get.io.D    <> core.io.sram7.get.wdata
  }
  // >>>>>>>>>>>>>> FPGA Cache Bram <<<<<<<<<<<<<<
  if (fpga) {
    for (i <- 0 to 15) {
      i_bram.get(i).io.en    <> core.io.i_bram.get(i).en
      i_bram.get(i).io.wr    <> core.io.i_bram.get(i).wr
      i_bram.get(i).io.addr  <> core.io.i_bram.get(i).addr
      i_bram.get(i).io.wdata <> core.io.i_bram.get(i).wdata
      i_bram.get(i).io.rdata <> core.io.i_bram.get(i).rdata
    }
    for (i <- 0 to 15) {
      d_bram.get(i).io.en    <> core.io.d_bram.get(i).en
      d_bram.get(i).io.wr    <> core.io.d_bram.get(i).wr
      d_bram.get(i).io.addr  <> core.io.d_bram.get(i).addr
      d_bram.get(i).io.wdata <> core.io.d_bram.get(i).wdata
      d_bram.get(i).io.rdata <> core.io.d_bram.get(i).rdata
    }
  }
  // >>>>>>>>>>>>>> SAXI <<<<<<<<<<<<<<
  axi_pmem.io.S_AXI_ACLK    <> clock
  axi_pmem.io.S_AXI_ARESETN <> !reset.asBool()
  axi_pmem.io.S_AXI_AWVALID <> core.io.master.awvalid
  axi_pmem.io.S_AXI_AWREADY <> core.io.master.awready
  axi_pmem.io.S_AXI_AWID    <> core.io.master.awid
  axi_pmem.io.S_AXI_AWADDR  <> core.io.master.awaddr
  axi_pmem.io.S_AXI_AWLEN   <> core.io.master.awlen
  axi_pmem.io.S_AXI_AWSIZE  <> core.io.master.awsize
  axi_pmem.io.S_AXI_AWBURST <> core.io.master.awburst
  axi_pmem.io.S_AXI_WVALID  <> core.io.master.wvalid
  axi_pmem.io.S_AXI_WREADY  <> core.io.master.wready
  axi_pmem.io.S_AXI_WDATA   <> core.io.master.wdata
  axi_pmem.io.S_AXI_WSTRB   <> core.io.master.wstrb
  axi_pmem.io.S_AXI_WLAST   <> core.io.master.wlast
  axi_pmem.io.S_AXI_BVALID  <> core.io.master.bvalid
  axi_pmem.io.S_AXI_BREADY  <> core.io.master.bready
  axi_pmem.io.S_AXI_BID     <> core.io.master.bid
  axi_pmem.io.S_AXI_BRESP   <> core.io.master.bresp
  axi_pmem.io.S_AXI_ARVALID <> core.io.master.arvalid
  axi_pmem.io.S_AXI_ARREADY <> core.io.master.arready
  axi_pmem.io.S_AXI_ARID    <> core.io.master.arid
  axi_pmem.io.S_AXI_ARADDR  <> core.io.master.araddr
  axi_pmem.io.S_AXI_ARLEN   <> core.io.master.arlen
  axi_pmem.io.S_AXI_ARSIZE  <> core.io.master.arsize
  axi_pmem.io.S_AXI_ARBURST <> core.io.master.arburst
  axi_pmem.io.S_AXI_RVALID  <> core.io.master.rvalid
  axi_pmem.io.S_AXI_RREADY  <> core.io.master.rready
  axi_pmem.io.S_AXI_RID     <> core.io.master.rid
  axi_pmem.io.S_AXI_RDATA   <> core.io.master.rdata
  axi_pmem.io.S_AXI_RRESP   <> core.io.master.rresp
  axi_pmem.io.S_AXI_RLAST   <> core.io.master.rlast

  axi_pmem.io.PC <> core.io.axi_pc.get

}

object RVNoobGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(args, Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new RVNoob())))
}
