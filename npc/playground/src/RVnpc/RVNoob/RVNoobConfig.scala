package RVnpc.RVNoob

import chisel3._

trait RVNoobConfig {
  val alu_op_width = 5 //alu_op_width
  val judge_op_width = 3 //judge_op_width

}

trait ALU_op {
  val op_x = 0.U
  // + -
  val op_add = 1.U
  val op_sub = 2.U
  // shift
  val op_sll = 3.U //left_shift
  val op_srl = 4.U // right_shift_logical
  val op_sra = 5.U // right_shift_arithmetic
  // logic
  val op_xor = 6.U
  val op_or = 7.U
  val op_and = 8.U
  //x / %
  val op_mul = 9.U
  val op_div = 10.U
  val op_rem = 11.U
  // mulh
  val op_mulh = 12.U
  val op_mulhs = 13.U
  val op_mulhsu = 14.U
  //  div
  val op_divs = 15.U
  val op_divsw = 16.U
  val op_divw = 17.U
  // rem
  val op_rems = 18.U
  val op_remsw = 19.U
  val op_remw = 20.U
  // shift w
  val op_srlw = 21.U
  val op_sraw = 22.U
  val op_sllw = 23.U

}

trait Judge_op {
  val jop_x = 0.U
  // B
  val jop_beq = 1.U
  val jop_bne = 2.U
  val jop_blt = 3.U
  val jop_bge = 4.U
  // set
  val jop_slt = 5.U
  // sextw
  val jop_sextw = 6.U
}

trait function {
  // 取部分指令inst_p,将最高位符号位扩展，扩展的位数根据低比特有效值有多少位valid_bit决定
  // 返回扩展出来的部分
  //sext(io.inst(31, 20), 12) 代表inst信号的部分中31bit为符号位，返回52bit(64-12)的全0或全1
  def sext(inst_p: UInt, valid_bit: Int, left_shift: Int = 0): UInt =
    VecInit(Seq.fill(64 - valid_bit - left_shift)(inst_p(inst_p.getWidth - 1))).asUInt()
}
