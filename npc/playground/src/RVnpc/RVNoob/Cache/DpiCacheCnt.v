module DpiDCacheCnt(
    input clk,
    input valid,
    input miss
);
import "DPI-C" function void dcache_access(input logic miss);
always@(posedge clk) begin
    if(valid == 1'b1) begin
        dcache_access(miss);
    end
end

endmodule

module DpiICacheCnt(
    input clk,
    input valid,
    input miss
);
import "DPI-C" function void icache_access(input logic miss);
always@(posedge clk) begin
    if(valid == 1'b1) begin
        icache_access(miss);
    end
end

endmodule