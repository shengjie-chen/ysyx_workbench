import "DPI-C" function int add (input int a, input int b);

module Ebreak(
    input [31:0] inst,
    output reg ebreak
);

initial begin
    $display("%x + %x = %x", 1, 2, add(1,2));
endtask

always@* begin
    if(inst == 32'b0000000 00001 00000 000 00000 11100 11) begin
        ebreak = 1;
        $finish;
    end
    else begin
        ebreak = 0;
    end
end

endmodule
