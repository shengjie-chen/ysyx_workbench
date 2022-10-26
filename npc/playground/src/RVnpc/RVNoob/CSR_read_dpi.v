import "DPI-C" function void set_csr_ptr(input logic [63:0] a []);
module CSR_read_dpi(
    input [63:0] csr_0 ,
    input [63:0] csr_1 ,
    input [63:0] csr_2 ,
    input [63:0] csr_3
);

wire [63:0] csr [3:0];
assign csr[0 ] = csr_0 ;
assign csr[1 ] = csr_1 ;
assign csr[2 ] = csr_2 ;
assign csr[3 ] = csr_3 ;

initial set_csr_ptr(csr);  // csr为csr寄存器的二维数组变量

endmodule
