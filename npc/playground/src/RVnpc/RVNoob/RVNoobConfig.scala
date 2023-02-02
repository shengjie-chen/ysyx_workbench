package RVnpc.RVNoob

import chisel3._
import chisel3.util._

trait RVNoobConfig {
  val alu_op_w   = 5 //alu_op_width
  val jdg_op_w   = 4 //judge_op_width
  val jdgl_op_w  = 3 //judge_load_op_width
  val xlen       = 64
  val inst_w     = 32
  val gpr_addr_w = 5

  val tapeout: Boolean = false
  val ysyxid = "ysyx_22040495"
  def getClassName: String = this.getClass.toString.split("\\.").last
}

trait ALU_op {
  //  val sNone :: sOne1 :: sTwo1s :: Nil = Enum(3)
  val op_x = 0.U
  // + -
  val op_add = 1.U // 00001
  val op_sub = 3.U // 00011
  // shift
  val op_sll = 2.U // 00010 left_shift
  val op_srl = 4.U // 00100 right_shift_logical
  val op_sra = 5.U // 00101 right_shift_arithmetic
  // shift w
  val op_srlw = 9.U // 01001
  val op_sraw = 10.U // 01010
  val op_sllw = 11.U // 01011
  // mul
  val op_mul    = 8.U  // 01000
  val op_mulw   = 12.U // 01100
  val op_mulh   = 13.U // 01101
  val op_mulhs  = 14.U // 01110
  val op_mulhsu = 15.U // 01111
  //  div
  val op_div   = 16.U // 10000
  val op_divs  = 17.U // 10001
  val op_divsw = 18.U // 10010
  val op_divw  = 19.U // 10011
  // rem
  val op_rem   = 20.U // 10100
  val op_rems  = 21.U // 10101
  val op_remsw = 22.U // 10110
  val op_remw  = 23.U // 10111
  // logic
  val op_xor = 6.U  // 00110
  val op_or  = 7.U  // 00111 csr
  val op_and = 24.U // 11000
  // csr
  val op_andinv = 25.U // 11001

}

trait Judge_op {
  //    val jop_x :: sOne1 :: sTwo1s :: Nil = Enum(3)

  val jop_x = 0.U
  // B
  val jop_beq  = 1.U
  val jop_bne  = 3.U
  val jop_blt  = 2.U
  val jop_bltu = 6.U
  val jop_bge  = 7.U
  val jop_bgeu = 5.U
  // set
  val jop_slt  = 4.U
  val jop_sltu = 12.U
  // sext
  val jop_sextw = 13.U // 截取32位做符号位拓展
  // val jop_sexthw = 7.U
  // val jop_sextb  = 8.U
  // uext
  // val jop_uextw  = 9.U
  // val jop_uexthw = 10.U
  // val jop_uextb  = 11.U

}

trait Judge_Load_op {
  //    val jop_x :: sOne1 :: sTwo1s :: Nil = Enum(3)

  val jlop_x = 0.U
  // sext
  val jlop_sextw  = 1.U
  val jlop_sexthw = 2.U
  val jlop_sextb  = 3.U
  // uext
  val jlop_uextw  = 4.U
  val jlop_uexthw = 5.U
  val jlop_uextb  = 6.U

}

trait Csr_op {
  //    val jop_x :: sOne1 :: sTwo1s :: Nil = Enum(3)

  val csr_x = 0.U

  val csr_rw  = 2.U
  val csr_rwi = 3.U

  val csr_rs  = 4.U
  val csr_rsi = 5.U

  val csr_rc  = 6.U
  val csr_rci = 7.U

}

trait IDU_op extends ALU_op with Judge_op with Csr_op with Judge_Load_op

trait ext_function {
  def sext_64(inst_p: UInt): UInt = {
    Cat(sext(inst_p, inst_p.getWidth), inst_p)
  }

  // 取部分指令inst_p,将最高位符号位扩展，扩展的位数根据低比特有效值有多少位valid_bit决定
  // 返回扩展出来的部分
  //sext(io.inst(31, 20), 12) 代表inst信号的部分中31bit为符号位，返回52bit(64-12)的全0或全1
  def sext(inst_p: UInt, valid_bit: Int, left_shift: Int = 0): UInt =
    VecInit(Seq.fill(64 - valid_bit - left_shift)(inst_p(inst_p.getWidth - 1))).asUInt()

  def uext_64(inst_p: UInt): UInt = {
    Cat(uext(inst_p, inst_p.getWidth), inst_p)
  }

  def uext(inst_p: UInt, valid_bit: Int, left_shift: Int = 0): UInt =
    VecInit(Seq.fill(64 - valid_bit - left_shift)(0.B)).asUInt()

}
