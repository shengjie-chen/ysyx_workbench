module DpiPmem(
  input clk,
  input [63:0] pc,
  input [63:0] raddr,
  input [63:0] waddr,
  input [7:0] wmask,
  output [63:0] rdata,
  input [63:0] wdata,
  input r_pmem,w_pmem
);

import "DPI-C" function void pmem_read_dpi(
  input longint raddr, output longint rdata, input longint pc);
import "DPI-C" function void pmem_write_dpi(
  input longint waddr, input longint wdata, input byte wmask, input longint pc);

reg [63:0] rdata_t;

always @(*) begin
  if(r_pmem == 1'b1)
    pmem_read_dpi(raddr, rdata_t, pc);
  else
    rdata_t = 64'd0;
end

always @(posedge clk) begin
  if(w_pmem == 1'b1)
    pmem_write_dpi(waddr, wdata, wmask, pc);
end

assign rdata = rdata_t;

endmodule