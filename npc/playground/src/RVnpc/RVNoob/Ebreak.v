//import "DPI-C" function int add (input int a, input int b);
import "DPI-C" function void npc_ebreak();
module Ebreak(
    input clk,
    input [31:0] inst,
    input [63:0] a0,
    output reg ebreak
);

//initial begin
//    $display("%x + %x = %x", 1, 2, add(1,2));
//end

always@(posedge clk) begin
    if(inst == 32'b0000000_00001_00000_000_00000_11100_11) begin
        ebreak = 1;
        if(a0 == 0) begin
            $display("!!!!  HIT GOOD TRAP !!!!");
        end else begin
            $display("!!!!  HIT BAD TRAP !!!!");
        end
        npc_ebreak();
        // $finish;
    end
    else begin
        ebreak = 0;
    end
end

endmodule
