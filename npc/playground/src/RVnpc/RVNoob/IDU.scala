package RVnpc.RVNoob

import chisel3._
import chisel3.util._

class IDU extends Module with ALU_op with Judge_op with function with RVNoobConfig {
  val io = IO(new Bundle {
    val inst = Input(UInt(inst_w.W))
    val imm = Output(UInt(xlen.W))
    // gpr
    val wen = Output(Bool())
    val rd = Output(UInt(5.W))
    val ren1 = Output(Bool())
    val ren2 = Output(Bool())
    val rs1 = Output(UInt(5.W))
    val rs2 = Output(UInt(5.W))
    // control
    val exe_ctrl = Output(new EXECtrlIO)
    val dnpc_jalr = Output(Bool())
    val pc_mux = Output(Bool())
  })
  val dpi_inst = Module(new DpiInst)
  dpi_inst.io.inst <> io.inst

  val opcode = Wire(UInt(7.W))
  val fun3 = Wire(UInt(3.W))
  val fun7 = Wire(UInt(7.W))
  opcode := io.inst(6, 0)
  fun3 := io.inst(14, 12)
  fun7 := io.inst(31, 25)

  io.rd := io.inst(11, 7)
  io.rs1 := io.inst(19, 15)
  io.rs2 := io.inst(24, 20)

  //  val rvi_lui   = Map("type"->"U","cond"->(opcode === "b0110111".U))

  // inst
  // rv32i
  val rvi_lui = opcode === "b0110111".U
  val rvi_auipc = opcode === "b0010111".U
  val rvi_jal = opcode === "b1101111".U
  val rvi_jalr = opcode === "b1100111".U && fun3 === "b000".U
  val rvi_beq = opcode === "b1100011".U && fun3 === "b000".U
  val rvi_bne = opcode === "b1100011".U && fun3 === "b001".U
  val rvi_blt = opcode === "b1100011".U && fun3 === "b100".U
  val rvi_bge = opcode === "b1100011".U && fun3 === "b101".U
  val rvi_bltu = opcode === "b1100011".U && fun3 === "b110".U
  val rvi_bgeu = opcode === "b1100011".U && fun3 === "b111".U
  //    val rvi_lb    = opcode === "b0000011".U && fun3 === "b000".U
  //    val rvi_lh    = opcode === "b0000011".U && fun3 === "b001".U
  //    val rvi_lw    = opcode === "b0000011".U && fun3 === "b010".U
  //    val rvi_lbu   = opcode === "b0000011".U && fun3 === "b100".U
  //    val rvi_lhu   = opcode === "b0000011".U && fun3 === "b101".U
  //    val rvi_sb    = opcode === "b0100011".U && fun3 === "b000".U
  //    val rvi_sh    = opcode === "b0100011".U && fun3 === "b001".U
  //    val rvi_sw    = opcode === "b0100011".U && fun3 === "b010".U
  val rvi_addi = opcode === "b0010011".U && fun3 === "b000".U
  val rvi_slti = opcode === "b0010011".U && fun3 === "b010".U
  val rvi_sltiu = opcode === "b0010011".U && fun3 === "b011".U
  val rvi_xori = opcode === "b0010011".U && fun3 === "b100".U
  val rvi_ori = opcode === "b0010011".U && fun3 === "b110".U
  val rvi_andi = opcode === "b0010011".U && fun3 === "b111".U
  val rvi_add = opcode === "0110011".U && fun3 === "b000".U && fun7 === "b0000000".U
  val rvi_sub = opcode === "0110011".U && fun3 === "b000".U && fun7 === "b0100000".U
  val rvi_sll = opcode === "0110011".U && fun3 === "b001".U && fun7 === "b0000000".U
  val rvi_slt = opcode === "0110011".U && fun3 === "b010".U && fun7 === "b0000000".U
  val rvi_sltu = opcode === "0110011".U && fun3 === "b011".U && fun7 === "b0000000".U
  val rvi_xor = opcode === "0110011".U && fun3 === "b100".U && fun7 === "b0000000".U
  val rvi_srl = opcode === "0110011".U && fun3 === "b101".U && fun7 === "b0000000".U
  val rvi_sra = opcode === "0110011".U && fun3 === "b101".U && fun7 === "b0100000".U
  val rvi_or = opcode === "0110011".U && fun3 === "b110".U && fun7 === "b0000000".U
  val rvi_and = opcode === "0110011".U && fun3 === "b111".U && fun7 === "b0000000".U
  // rv64i
  //  val rvi_lwu   = opcode === "b0000011".U && fun3 === "b110".U
  //  val rvi_ld    = opcode === "b0000011".U && fun3 === "b011".U
  //  val rvi_sd    = opcode === "b0100011".U && fun3 === "b011".U
  val rvi_slli = opcode === "0010011".U && fun3 === "b001".U && fun7(6, 1) === "b000000".U
  val rvi_srli = opcode === "0010011".U && fun3 === "b101".U && fun7(6, 1) === "b000000".U
  val rvi_srai = opcode === "0010011".U && fun3 === "b101".U && fun7(6, 1) === "b010000".U
  val rvi_addiw = opcode === "0011011".U && fun3 === "b000".U
  val rvi_slliw = opcode === "0011011".U && fun3 === "b001".U && fun7 === "b0000000".U
  val rvi_srliw = opcode === "0011011".U && fun3 === "b101".U && fun7 === "b0000000".U
  val rvi_sraiw = opcode === "0011011".U && fun3 === "b101".U && fun7 === "b0100000".U
  val rvi_addw = opcode === "0111011".U && fun3 === "b000".U && fun7 === "b0000000".U
  val rvi_subw = opcode === "0111011".U && fun3 === "b000".U && fun7 === "b0100000".U
  val rvi_sllw = opcode === "0111011".U && fun3 === "b001".U && fun7 === "b0000000".U
  val rvi_srlw = opcode === "0111011".U && fun3 === "b101".U && fun7 === "b0000000".U
  val rvi_sraw = opcode === "0111011".U && fun3 === "b101".U && fun7 === "b0100000".U
  // rv32M
  val rvm_mul = opcode === "0110011".U && fun3 === "b000".U && fun7 === "b0000001".U
  val rvm_mulh = opcode === "0110011".U && fun3 === "b001".U && fun7 === "b0000001".U
  val rvm_mulhsu = opcode === "0110011".U && fun3 === "b010".U && fun7 === "b0000001".U
  val rvm_mulhu = opcode === "0110011".U && fun3 === "b011".U && fun7 === "b0000001".U
  val rvm_div = opcode === "0110011".U && fun3 === "b100".U && fun7 === "b0000001".U
  val rvm_divu = opcode === "0110011".U && fun3 === "b101".U && fun7 === "b0000001".U
  val rvm_rem = opcode === "0110011".U && fun3 === "b110".U && fun7 === "b0000001".U
  val rvm_remu = opcode === "0110011".U && fun3 === "b111".U && fun7 === "b0000001".U
  // rv64M
  val rvm_mulw = opcode === "0111011".U && fun3 === "b000".U && fun7 === "b0000001".U
  val rvm_divw = opcode === "0111011".U && fun3 === "b100".U && fun7 === "b0000001".U
  val rvm_divuw = opcode === "0111011".U && fun3 === "b100".U && fun7 === "b0000001".U
  val rvm_remw = opcode === "0111011".U && fun3 === "b110".U && fun7 === "b0000001".U
  val rvm_remuw = opcode === "0111011".U && fun3 === "b110".U && fun7 === "b0000001".U

  // inst type
  val type_I =
    rvi_jalr || rvi_addi || rvi_slti || rvi_sltiu || rvi_xori || rvi_ori || rvi_andi || rvi_slli || rvi_srli || rvi_srai || rvi_addiw || rvi_slliw || rvi_srliw || rvi_sraiw // TYPE_I addi
  val type_U = rvi_lui || rvi_auipc // TYPE_U auipc
  val type_S = 0.B // TYPE_S
  val type_J = rvi_jal // TYPE_J
  val type_R =
    rvi_add || rvi_sub || rvi_sll || rvi_slt || rvi_sltu || rvi_xor || rvi_srl || rvi_sra || rvi_or || rvi_and || rvi_addw || rvi_subw || rvi_sllw || rvi_srlw || rvi_sraw || rvm_mul || rvm_mulh || rvm_mulhsu || rvm_mulhu || rvm_div || rvm_divu || rvm_rem || rvm_remu || rvm_mulw || rvm_divw || rvm_divuw || rvm_remw || rvm_remuw // TYPE_R
  val type_B =
    rvi_beq || rvi_bne || rvi_blt || rvi_bge || rvi_bltu || rvi_bgeu // TYPE_B

  // imm
  val immI = Wire(UInt(64.W))
  val immU = Wire(UInt(64.W))
  val immS = Wire(UInt(64.W))
  val immJ = Wire(UInt(64.W))
  val immB = Wire(UInt(64.W))

  immI := Cat(sext(io.inst(31, 20), 12), io.inst(31, 20))
  immU := Cat(sext(io.inst(31, 12), 20, 12), io.inst(31, 12), 0.U(12.W))
  immS := Cat(sext(io.inst(31, 25), 12), io.inst(31, 25), io.inst(11, 7))
  immJ := Cat(sext(io.inst(31).asUInt(), 21), io.inst(31), io.inst(19, 12), io.inst(20), io.inst(30, 21), 0.U(1.W))
  immB := Cat(sext(io.inst(31).asUInt(), 13), io.inst(31), io.inst(7), io.inst(30, 25), io.inst(11, 8), 0.U(1.W))
  io.imm := Mux1H(
    Seq(
      type_I -> immI,
      type_U -> immU,
      type_S -> immS,
      type_J -> immJ,
      type_B -> immB
    )
  )

  // control
  // ALU的功能控制
  io.exe_ctrl.alu_op := MuxCase(
    op_x,
    Array(
      (rvi_auipc || rvi_addi || rvi_add || rvi_addiw || rvi_addw) -> op_add,
      (rvi_beq || rvi_bne || rvi_blt || rvi_bge || rvi_bltu || rvi_bgeu || rvi_slti || rvi_sltiu || rvi_sub || rvi_slt || rvi_sltu || rvi_subw) -> op_sub,
      (rvi_sll || rvi_slli) -> op_sll,
      (rvi_srl || rvi_srli) -> op_srl,
      (rvi_sra || rvi_srai) -> op_sra,
      (rvi_xori || rvi_xor) -> op_xor,
      (rvi_ori || rvi_or) -> op_or,
      (rvi_andi || rvi_and) -> op_and,
      (rvm_mul || rvm_mulw) -> op_mul,
      (rvm_divu) -> op_div,
      (rvm_remu) -> op_rem,
      (rvm_mulhu) -> op_mulh,
      (rvm_mulh) -> op_mulhs,
      (rvm_mulhsu) -> op_mulhsu,
      (rvm_div) -> op_divs,
      (rvm_divw) -> op_divsw,
      (rvm_divuw) -> op_divw,
      (rvm_rem) -> op_rems,
      (rvm_remw) -> op_remsw,
      (rvm_remuw) -> op_remw,
      (rvi_srliw || rvi_srlw) -> op_srlw,
      (rvi_sraiw || rvi_sraw) -> op_sraw,
      (rvi_slliw || rvi_sllw) -> op_sllw
    )
  )
  io.exe_ctrl.exe_out_mux := rvi_lui || rvi_jal || rvi_jalr
  io.exe_ctrl.dir_out_mux := rvi_lui
  val jpg_slt = rvi_slti || rvi_sltiu || rvi_slt || rvi_sltu
  val jpg_sextw =
    rvi_addiw || rvi_slliw || rvi_srliw || rvi_sraiw || rvi_addw || rvi_subw || rvi_sllw || rvi_srlw || rvi_sraw || rvm_mulw || rvm_divw || rvm_divuw || rvm_remw || rvm_remuw
  io.exe_ctrl.judge_mux := jpg_slt || jpg_sextw
  io.exe_ctrl.judge_op := MuxCase(jop_x,
    Array(
      rvi_beq -> jop_beq,
      rvi_bne -> jop_bne,
      (rvi_blt || rvi_bltu) -> jop_blt,
      (rvi_bge || rvi_bgeu) -> jop_bge,
      jpg_slt -> jop_slt,
      jpg_sextw -> jop_sextw
    ))

  io.pc_mux := rvi_jal || rvi_jalr // 出现pc=的指令
  io.dnpc_jalr := rvi_jalr

  // 是否写寄存器文件
  io.wen := type_R || type_I || type_J || type_U
  io.ren1 := type_I || type_R || type_S || type_B
  io.ren2 := type_S || type_R || type_B
  io.exe_ctrl.alu_src1_mux := type_U
  io.exe_ctrl.alu_src2_mux := type_I

  // control check
  //  assert(!(io.dnpc_0b0 && !io.dnpc_mux), "dnpc_0b0->dnpc_mux dependence error!\n")
  //  assert(!(io.dnpc_mux && !io.pc_mux), "dnpc_mux->pc_mux dependence error!\n")

}

class DpiInst extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
  })
  setInline(
    "DpiInst.v",
    """
      |//import "DPI-C" function void set_inst_ptr(input logic [31:0] a);
      |import "DPI-C" function void inst_change(input logic [31:0] a);
      |module DpiInst(input [31:0] inst);
      |
      | //initial set_inst_ptr(inst);
      |
      | always @* inst_change(inst);
      |
      |endmodule
            """.stripMargin
  )

}
