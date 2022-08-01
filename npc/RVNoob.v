module IDU(
  input  [31:0] io_inst,
  output        io_add_en,
  output        io_wen,
  output [4:0]  io_rd,
  output        io_ren1,
  output [4:0]  io_rs1,
  output [63:0] io_imm
);
  wire [6:0] opcode = io_inst[6:0]; // @[IDU.scala 20:20]
  wire [2:0] fun3 = io_inst[14:12]; // @[IDU.scala 21:20]
  wire [5:0] io_imm_lo_lo_lo = {io_inst[31],io_inst[31],io_inst[31],io_inst[31],io_inst[31],io_inst[31]}; // @[IDU.scala 26:63]
  wire [12:0] io_imm_lo_lo = {io_inst[31],io_inst[31],io_inst[31],io_inst[31],io_inst[31],io_inst[31],io_inst[31],
    io_imm_lo_lo_lo}; // @[IDU.scala 26:63]
  wire [25:0] io_imm_lo = {io_inst[31],io_inst[31],io_inst[31],io_inst[31],io_inst[31],io_inst[31],io_inst[31],
    io_imm_lo_lo_lo,io_imm_lo_lo}; // @[IDU.scala 26:63]
  wire [51:0] io_imm_hi_1 = {io_inst[31],io_inst[31],io_inst[31],io_inst[31],io_inst[31],io_inst[31],io_inst[31],
    io_imm_lo_lo_lo,io_imm_lo_lo,io_imm_lo}; // @[IDU.scala 26:63]
  wire [11:0] io_imm_lo_1 = io_inst[31:20]; // @[IDU.scala 26:74]
  wire  _io_add_en_T = opcode == 7'h13; // @[IDU.scala 28:27]
  wire  _io_add_en_T_1 = fun3 == 3'h0; // @[IDU.scala 28:54]
  assign io_add_en = opcode == 7'h13 & fun3 == 3'h0; // @[IDU.scala 28:19]
  assign io_wen = _io_add_en_T & _io_add_en_T_1; // @[IDU.scala 29:19]
  assign io_rd = io_inst[11:7]; // @[IDU.scala 23:20]
  assign io_ren1 = _io_add_en_T & _io_add_en_T_1; // @[IDU.scala 30:19]
  assign io_rs1 = io_inst[19:15]; // @[IDU.scala 24:20]
  assign io_imm = {io_imm_hi_1,io_imm_lo_1}; // @[Cat.scala 30:58]
endmodule
module RegisterFile(
  input         clock,
  input         io_wen,
  input  [63:0] io_wdata,
  input  [4:0]  io_waddr,
  input         io_ren1,
  output [63:0] io_rdata1,
  input  [4:0]  io_raddr1
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [63:0] _RAND_1;
  reg [63:0] _RAND_2;
  reg [63:0] _RAND_3;
  reg [63:0] _RAND_4;
  reg [63:0] _RAND_5;
  reg [63:0] _RAND_6;
  reg [63:0] _RAND_7;
  reg [63:0] _RAND_8;
  reg [63:0] _RAND_9;
  reg [63:0] _RAND_10;
  reg [63:0] _RAND_11;
  reg [63:0] _RAND_12;
  reg [63:0] _RAND_13;
  reg [63:0] _RAND_14;
  reg [63:0] _RAND_15;
  reg [63:0] _RAND_16;
  reg [63:0] _RAND_17;
  reg [63:0] _RAND_18;
  reg [63:0] _RAND_19;
  reg [63:0] _RAND_20;
  reg [63:0] _RAND_21;
  reg [63:0] _RAND_22;
  reg [63:0] _RAND_23;
  reg [63:0] _RAND_24;
  reg [63:0] _RAND_25;
  reg [63:0] _RAND_26;
  reg [63:0] _RAND_27;
  reg [63:0] _RAND_28;
  reg [63:0] _RAND_29;
  reg [63:0] _RAND_30;
  reg [63:0] _RAND_31;
`endif // RANDOMIZE_REG_INIT
  reg [63:0] rf_0; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_1; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_2; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_3; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_4; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_5; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_6; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_7; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_8; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_9; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_10; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_11; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_12; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_13; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_14; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_15; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_16; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_17; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_18; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_19; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_20; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_21; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_22; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_23; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_24; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_25; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_26; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_27; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_28; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_29; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_30; // @[RegisterFile.scala 22:15]
  reg [63:0] rf_31; // @[RegisterFile.scala 22:15]
  wire [63:0] _GEN_1 = 5'h1 == io_raddr1 ? rf_1 : rf_0; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_2 = 5'h2 == io_raddr1 ? rf_2 : _GEN_1; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_3 = 5'h3 == io_raddr1 ? rf_3 : _GEN_2; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_4 = 5'h4 == io_raddr1 ? rf_4 : _GEN_3; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_5 = 5'h5 == io_raddr1 ? rf_5 : _GEN_4; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_6 = 5'h6 == io_raddr1 ? rf_6 : _GEN_5; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_7 = 5'h7 == io_raddr1 ? rf_7 : _GEN_6; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_8 = 5'h8 == io_raddr1 ? rf_8 : _GEN_7; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_9 = 5'h9 == io_raddr1 ? rf_9 : _GEN_8; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_10 = 5'ha == io_raddr1 ? rf_10 : _GEN_9; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_11 = 5'hb == io_raddr1 ? rf_11 : _GEN_10; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_12 = 5'hc == io_raddr1 ? rf_12 : _GEN_11; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_13 = 5'hd == io_raddr1 ? rf_13 : _GEN_12; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_14 = 5'he == io_raddr1 ? rf_14 : _GEN_13; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_15 = 5'hf == io_raddr1 ? rf_15 : _GEN_14; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_16 = 5'h10 == io_raddr1 ? rf_16 : _GEN_15; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_17 = 5'h11 == io_raddr1 ? rf_17 : _GEN_16; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_18 = 5'h12 == io_raddr1 ? rf_18 : _GEN_17; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_19 = 5'h13 == io_raddr1 ? rf_19 : _GEN_18; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_20 = 5'h14 == io_raddr1 ? rf_20 : _GEN_19; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_21 = 5'h15 == io_raddr1 ? rf_21 : _GEN_20; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_22 = 5'h16 == io_raddr1 ? rf_22 : _GEN_21; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_23 = 5'h17 == io_raddr1 ? rf_23 : _GEN_22; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_24 = 5'h18 == io_raddr1 ? rf_24 : _GEN_23; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_25 = 5'h19 == io_raddr1 ? rf_25 : _GEN_24; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_26 = 5'h1a == io_raddr1 ? rf_26 : _GEN_25; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_27 = 5'h1b == io_raddr1 ? rf_27 : _GEN_26; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_28 = 5'h1c == io_raddr1 ? rf_28 : _GEN_27; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_29 = 5'h1d == io_raddr1 ? rf_29 : _GEN_28; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] _GEN_30 = 5'h1e == io_raddr1 ? rf_30 : _GEN_29; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  wire [63:0] rdata1 = 5'h1f == io_raddr1 ? rf_31 : _GEN_30; // @[RegisterFile.scala 28:13 RegisterFile.scala 28:13]
  assign io_rdata1 = io_ren1 ? rdata1 : 64'h0; // @[RegisterFile.scala 30:19]
  always @(posedge clock) begin
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h0 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_0 <= io_wdata; // @[RegisterFile.scala 35:18]
      end else begin
        rf_0 <= 64'h0; // @[RegisterFile.scala 23:9]
      end
    end else begin
      rf_0 <= 64'h0; // @[RegisterFile.scala 23:9]
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h1 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_1 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h2 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_2 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h3 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_3 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h4 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_4 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h5 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_5 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h6 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_6 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h7 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_7 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h8 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_8 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h9 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_9 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'ha == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_10 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'hb == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_11 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'hc == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_12 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'hd == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_13 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'he == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_14 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'hf == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_15 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h10 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_16 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h11 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_17 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h12 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_18 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h13 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_19 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h14 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_20 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h15 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_21 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h16 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_22 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h17 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_23 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h18 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_24 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h19 == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_25 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h1a == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_26 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h1b == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_27 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h1c == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_28 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h1d == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_29 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h1e == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_30 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
    if (io_wen) begin // @[RegisterFile.scala 34:16]
      if (5'h1f == io_waddr) begin // @[RegisterFile.scala 35:18]
        rf_31 <= io_wdata; // @[RegisterFile.scala 35:18]
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {2{`RANDOM}};
  rf_0 = _RAND_0[63:0];
  _RAND_1 = {2{`RANDOM}};
  rf_1 = _RAND_1[63:0];
  _RAND_2 = {2{`RANDOM}};
  rf_2 = _RAND_2[63:0];
  _RAND_3 = {2{`RANDOM}};
  rf_3 = _RAND_3[63:0];
  _RAND_4 = {2{`RANDOM}};
  rf_4 = _RAND_4[63:0];
  _RAND_5 = {2{`RANDOM}};
  rf_5 = _RAND_5[63:0];
  _RAND_6 = {2{`RANDOM}};
  rf_6 = _RAND_6[63:0];
  _RAND_7 = {2{`RANDOM}};
  rf_7 = _RAND_7[63:0];
  _RAND_8 = {2{`RANDOM}};
  rf_8 = _RAND_8[63:0];
  _RAND_9 = {2{`RANDOM}};
  rf_9 = _RAND_9[63:0];
  _RAND_10 = {2{`RANDOM}};
  rf_10 = _RAND_10[63:0];
  _RAND_11 = {2{`RANDOM}};
  rf_11 = _RAND_11[63:0];
  _RAND_12 = {2{`RANDOM}};
  rf_12 = _RAND_12[63:0];
  _RAND_13 = {2{`RANDOM}};
  rf_13 = _RAND_13[63:0];
  _RAND_14 = {2{`RANDOM}};
  rf_14 = _RAND_14[63:0];
  _RAND_15 = {2{`RANDOM}};
  rf_15 = _RAND_15[63:0];
  _RAND_16 = {2{`RANDOM}};
  rf_16 = _RAND_16[63:0];
  _RAND_17 = {2{`RANDOM}};
  rf_17 = _RAND_17[63:0];
  _RAND_18 = {2{`RANDOM}};
  rf_18 = _RAND_18[63:0];
  _RAND_19 = {2{`RANDOM}};
  rf_19 = _RAND_19[63:0];
  _RAND_20 = {2{`RANDOM}};
  rf_20 = _RAND_20[63:0];
  _RAND_21 = {2{`RANDOM}};
  rf_21 = _RAND_21[63:0];
  _RAND_22 = {2{`RANDOM}};
  rf_22 = _RAND_22[63:0];
  _RAND_23 = {2{`RANDOM}};
  rf_23 = _RAND_23[63:0];
  _RAND_24 = {2{`RANDOM}};
  rf_24 = _RAND_24[63:0];
  _RAND_25 = {2{`RANDOM}};
  rf_25 = _RAND_25[63:0];
  _RAND_26 = {2{`RANDOM}};
  rf_26 = _RAND_26[63:0];
  _RAND_27 = {2{`RANDOM}};
  rf_27 = _RAND_27[63:0];
  _RAND_28 = {2{`RANDOM}};
  rf_28 = _RAND_28[63:0];
  _RAND_29 = {2{`RANDOM}};
  rf_29 = _RAND_29[63:0];
  _RAND_30 = {2{`RANDOM}};
  rf_30 = _RAND_30[63:0];
  _RAND_31 = {2{`RANDOM}};
  rf_31 = _RAND_31[63:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module EXE(
  input  [63:0] io_src1,
  input  [63:0] io_src2,
  input         io_add_en,
  output [63:0] io_result
);
  wire [63:0] _io_result_T_1 = io_src1 + io_src2; // @[EXE.scala 12:39]
  assign io_result = io_add_en ? _io_result_T_1 : 64'h0; // @[EXE.scala 12:19]
endmodule
module RVNoob(
  input         clock,
  input         reset,
  output [63:0] io_pc,
  input  [31:0] io_inst,
  output [63:0] io_res
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  wire [31:0] idu_io_inst; // @[RVNoob.scala 15:19]
  wire  idu_io_add_en; // @[RVNoob.scala 15:19]
  wire  idu_io_wen; // @[RVNoob.scala 15:19]
  wire [4:0] idu_io_rd; // @[RVNoob.scala 15:19]
  wire  idu_io_ren1; // @[RVNoob.scala 15:19]
  wire [4:0] idu_io_rs1; // @[RVNoob.scala 15:19]
  wire [63:0] idu_io_imm; // @[RVNoob.scala 15:19]
  wire  rf_clock; // @[RVNoob.scala 16:19]
  wire  rf_io_wen; // @[RVNoob.scala 16:19]
  wire [63:0] rf_io_wdata; // @[RVNoob.scala 16:19]
  wire [4:0] rf_io_waddr; // @[RVNoob.scala 16:19]
  wire  rf_io_ren1; // @[RVNoob.scala 16:19]
  wire [63:0] rf_io_rdata1; // @[RVNoob.scala 16:19]
  wire [4:0] rf_io_raddr1; // @[RVNoob.scala 16:19]
  wire [63:0] exe_io_src1; // @[RVNoob.scala 17:19]
  wire [63:0] exe_io_src2; // @[RVNoob.scala 17:19]
  wire  exe_io_add_en; // @[RVNoob.scala 17:19]
  wire [63:0] exe_io_result; // @[RVNoob.scala 17:19]
  reg [63:0] pc; // @[RVNoob.scala 9:21]
  wire [63:0] snpc = pc + 64'h4; // @[RVNoob.scala 11:15]
  IDU idu ( // @[RVNoob.scala 15:19]
    .io_inst(idu_io_inst),
    .io_add_en(idu_io_add_en),
    .io_wen(idu_io_wen),
    .io_rd(idu_io_rd),
    .io_ren1(idu_io_ren1),
    .io_rs1(idu_io_rs1),
    .io_imm(idu_io_imm)
  );
  RegisterFile rf ( // @[RVNoob.scala 16:19]
    .clock(rf_clock),
    .io_wen(rf_io_wen),
    .io_wdata(rf_io_wdata),
    .io_waddr(rf_io_waddr),
    .io_ren1(rf_io_ren1),
    .io_rdata1(rf_io_rdata1),
    .io_raddr1(rf_io_raddr1)
  );
  EXE exe ( // @[RVNoob.scala 17:19]
    .io_src1(exe_io_src1),
    .io_src2(exe_io_src2),
    .io_add_en(exe_io_add_en),
    .io_result(exe_io_result)
  );
  assign io_pc = pc; // @[RVNoob.scala 13:9]
  assign io_res = exe_io_result; // @[RVNoob.scala 33:10]
  assign idu_io_inst = io_inst; // @[RVNoob.scala 19:15]
  assign rf_clock = clock;
  assign rf_io_wen = idu_io_wen; // @[RVNoob.scala 21:13]
  assign rf_io_wdata = exe_io_result; // @[RVNoob.scala 22:15]
  assign rf_io_waddr = idu_io_rd; // @[RVNoob.scala 23:15]
  assign rf_io_ren1 = idu_io_ren1; // @[RVNoob.scala 24:14]
  assign rf_io_raddr1 = idu_io_rs1; // @[RVNoob.scala 26:16]
  assign exe_io_src1 = rf_io_rdata1; // @[RVNoob.scala 29:15]
  assign exe_io_src2 = idu_io_imm; // @[RVNoob.scala 30:15]
  assign exe_io_add_en = idu_io_add_en; // @[RVNoob.scala 31:17]
  always @(posedge clock) begin
    if (reset) begin // @[RVNoob.scala 9:21]
      pc <= 64'h80000000; // @[RVNoob.scala 9:21]
    end else begin
      pc <= snpc; // @[RVNoob.scala 12:9]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {2{`RANDOM}};
  pc = _RAND_0[63:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
