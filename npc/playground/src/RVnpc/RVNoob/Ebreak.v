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


  //  alu_div_res := Mux(
  //    div || divs,
  //    Mux(div, (alu_src1 / alu_src2), (alu_src1.asSInt() / alu_src2.asSInt()).asUInt()),
  //    Mux(divw, (alu_src1(31, 0) / alu_src2(31, 0)), (alu_src1(31, 0).asSInt() / alu_src2(31, 0).asSInt()).asUInt())
  //  )
// module Div(input div ,    divs ,                 divv ,                 divvw,
// input [63:0] alu_src1,
// input [63:0] alu_src2,
// output [63:0] alu_div_res
// );
//
// assign alu_div_res = div || divs ?
// (div ? )
//
// endmodule
