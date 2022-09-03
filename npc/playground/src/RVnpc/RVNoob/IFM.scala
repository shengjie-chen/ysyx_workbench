package RVnpc.RVNoob
import chisel3._
import chisel3.util.{HasBlackBoxInline, MuxCase}
class IFM extends Module with RVNoobConfig {
  val io = IO(new Bundle {
//    val inst_addr = Input(UInt(xlen.W))
//    val inst = Output(UInt(inst_w.W))
    val data_addr = Input(UInt(xlen.W))
    val wdata     = Input(UInt(xlen.W))
    val rdata     = Output(UInt(xlen.W))
    val pmem_ctrl = Input(new PmemCtrlIO)
  })

  val daddr = io.data_addr & (~0x7.U(64.W)).asUInt()
  val shift = Wire(UInt(3.W))
  val rdata = Wire(UInt(xlen.W))
  val wdata = Wire(UInt(xlen.W))
  val wmask = Wire(UInt(8.W))
  // assert
  when(io.pmem_ctrl.r_pmem || io.pmem_ctrl.w_pmem) {
    when(io.pmem_ctrl.zero_ex_op === 3.U) {
      assert(shift === 0.U)
    }.elsewhen(io.pmem_ctrl.zero_ex_op === 2.U){
      assert(shift <= 4.U)
    }.elsewhen(io.pmem_ctrl.zero_ex_op === 1.U){
      assert(shift <= 6.U)
    }.otherwise{
      assert(shift < 8.U)
    }
  }
  val dpi_pmem = Module(new DpiPmem)
  dpi_pmem.io.raddr <> daddr
  dpi_pmem.io.waddr <> daddr
  dpi_pmem.io.wmask <> wmask
  dpi_pmem.io.rdata <> rdata
  dpi_pmem.io.wdata <> wdata
  dpi_pmem.io.r_pmem <> io.pmem_ctrl.r_pmem
  dpi_pmem.io.w_pmem <> io.pmem_ctrl.w_pmem

  shift :=  io.data_addr
  io.rdata := (rdata >> (shift * 8.U))
  wdata    := (io.wdata << (shift * 8.U))
  wmask := MuxCase(
    "b11111111".U,
    Array(
      (io.pmem_ctrl.zero_ex_op === 3.U) -> "b11111111".U,
      (io.pmem_ctrl.zero_ex_op === 2.U) -> ("b1111".U << shift),
      (io.pmem_ctrl.zero_ex_op === 1.U) -> ("b11".U << shift),
      (io.pmem_ctrl.zero_ex_op === 0.U) -> ("b1".U << shift)
    )
  )
}

class DpiPmem extends BlackBox with HasBlackBoxInline with RVNoobConfig {
  val io = IO(new Bundle {
    val raddr = Input(UInt(xlen.W))
    val waddr = Input(UInt(xlen.W))
    val wmask = Input(UInt((xlen / 8).W))
    val rdata = Output(UInt(xlen.W))
    val wdata = Input(UInt(xlen.W))
    val r_pmem = Input(Bool())
    val w_pmem = Input(Bool())
  })
  setInline(
    "DpiPmem.v",
    """
      |module DpiPmem(
      |input [63:0] raddr,
      |input [63:0] waddr,
      |input [7:0] wmask,
      |output [63:0] rdata,
      |input [63:0] wdata,
      |input r_pmem,w_pmem
      |);
      |
      |import "DPI-C" function void pmem_read_dpi(
      |  input longint raddr, output longint rdata);
      |import "DPI-C" function void pmem_write_dpi(
      |  input longint waddr, input longint wdata, input byte wmask);
      |reg [63:0] rdata_t;
      |
      |always @(r_pmem) begin
      |  if(r_pmem == 1'b1)
      |    pmem_read_dpi(raddr, rdata_t);
      |  else
      |    rdata_t = 64'd0;
      |end
      |
      |always @(w_pmem) begin
      |  if(w_pmem == 1'b1)
      |    pmem_write_dpi(waddr, wdata, wmask);
      |end
      |
      |assign rdata = rdata_t;
      |
      |endmodule
            """.stripMargin
  )
}
