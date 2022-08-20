package RVnpc.RVNoob

import chisel3._
import chisel3.util._

class IDU extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
    val imm = Output(UInt(64.W))
    // gpr
    val wen = Output(Bool())
    val rd = Output(UInt(5.W))
    val ren1 = Output(Bool())
    val ren2 = Output(Bool())
    val rs1 = Output(UInt(5.W))
    val rs2 = Output(UInt(5.W))
    // control
    val add_en = Output(Bool())
    val alu_src1_mux = Output(Bool())
    val alu_src2_mux = Output(Bool())
    val exe_out_mux = Output(Bool())
    val dnpc_mux = Output(Bool())
    val pc_mux = Output(Bool())
    val dnpc_0b0 = Output(Bool())
  })
  val dpi_inst = Module(new DpiInst)
  dpi_inst.io.inst <> io.inst

  val opcode = Wire(UInt(7.W))
  val fun3 = Wire(UInt(3.W))
  opcode := io.inst(6, 0)
  fun3 := io.inst(14, 12)

  io.rd := io.inst(11, 7)
  io.rs1 := io.inst(19, 15)
  io.rs2 := io.inst(24, 20)

  // inst
  val rvi_addi = opcode === "b0010011".U && fun3 === "b000".U
  val rvi_auipc = opcode === "b0010111".U
  val rvi_lui = opcode === "b0110111".U
  val rvi_jal = opcode === "b1101111".U
  val rvi_jalr = opcode === "b1100111".U && fun3 === "b000".U

  val type_I = rvi_addi || rvi_jalr // TYPE_I addi
  val type_U = rvi_auipc || rvi_lui // TYPE_U auipc
  val type_S = 0.B // TYPE_S
  val type_J = rvi_jal // TYPE_J
  val type_R = 0.B // TYPE_R
  val type_B = 0.B // TYPE_B

  // imm
  val immI = Wire(UInt(64.W))
  val immU = Wire(UInt(64.W))
  val immS = Wire(UInt(64.W))
  val immJ = Wire(UInt(64.W))
  val immB = Wire(UInt(64.W))

  // 区部分指令inst_p,将最高位符号位扩展，扩展的位数根据低比特有效值有多少位valid_bit决定
  // 返回扩展出来的部分
  def sext(inst_p: UInt, valid_bit: Int, left_shift: Int = 0): UInt =
    VecInit(Seq.fill(64 - valid_bit - left_shift)(inst_p(inst_p.getWidth - 1))).asUInt()

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
  io.add_en := rvi_addi || rvi_auipc || rvi_jal || rvi_jalr
  io.wen := rvi_addi || rvi_auipc || rvi_lui || rvi_jal || rvi_jalr
  io.ren1 := type_I || type_R || type_S || type_B
  io.ren2 := type_S || type_R || type_B
  io.alu_src1_mux := type_I || type_R || type_S || type_B
  io.alu_src2_mux := type_S || type_R || type_B
  io.exe_out_mux := rvi_jal || rvi_jalr
  io.dnpc_mux := rvi_jalr || rvi_auipc || rvi_jal
  io.dnpc_0b0 := rvi_jalr
  io.pc_mux := rvi_jal || rvi_jalr // 出现pc=的指令
}

class DpiInst extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val inst = Input(UInt(32.W))
  })
  setInline("DpiInst.v",
    """
      |import "DPI-C" function void set_inst_ptr(input logic [31:0] a);
      |import "DPI-C" function void inst_change(input logic [31:0] a);
      |      |module DpiInst(input [31:0] inst);
      |
      | initial set_inst_ptr(inst);
      |
      | always @* inst_change(inst);
      |
      |endmodule
            """.stripMargin)

}
