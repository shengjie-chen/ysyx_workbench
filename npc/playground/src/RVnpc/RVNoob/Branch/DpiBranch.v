import "DPI-C" function void find_id_branch_error();
import "DPI-C" function void find_exe_branch_error();
import "DPI-C" function void find_mem_branch_error();
import "DPI-C" function void br_change(
input logic [2:0] br_type, input logic pre_taken, input logic [31:0] pre_target, input logic true_taken, input logic [31:0] true_target);


module DpiBranch(
    input           clk,
    input           br_valid,
    input [2:0]     br_type,
    input           pre_taken,
    input [31:0]    pre_target,
    input           true_taken,
    input [31:0]    true_target,
    input           id_error,
    input           exe_error,
    input           mem_error
    );
always@(posedge clk) begin
    if(br_valid == 1'b1) begin
        br_change(br_type, pre_taken, pre_target, true_taken, true_target);
    end

    if(id_error == 1'b1) begin
        find_id_branch_error();
    end

    if(exe_error == 1'b1) begin
        find_exe_branch_error();
    end

    if(mem_error == 1'b1) begin
        find_mem_branch_error();
    end
end
endmodule