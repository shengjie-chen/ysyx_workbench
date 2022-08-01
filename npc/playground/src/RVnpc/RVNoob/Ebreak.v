import "DPI-C" function int add (input int a, input int b);

module Ebreak(
    input [31:0] inst,
    output reg ebreak
);

initial begin
    $display("%x + %x = %x", 1, 2, add(1,2));
end

always@* begin
    if(inst == 32'b0000000_00001_00000_000_00000_11100_11) begin
        ebreak = 1;
        $finish;
    end
    else begin
        ebreak = 0;
    end
end

endmodule
