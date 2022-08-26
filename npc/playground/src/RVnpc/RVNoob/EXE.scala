package RVnpc.RVNoob

import chisel3._
import chisel3.util.{Cat, MuxCase}

class EXE extends Module {
  val io = IO(new Bundle {
    val src1 = Input(UInt(64.W))
    val src2 = Input(UInt(64.W))
    val imm  = Input(UInt(64.W))

    val pc   = Input(UInt(64.W))
    val snpc = Input(UInt(64.W))

    val gp_out = Output(UInt(64.W))
    //control
    val ctrl = Input(new EXECtrlIO)
    val B_en = Output(Bool())

  })
  val alu_src1 = Wire(UInt(64.W))
  val alu_src2 = Wire(UInt(64.W))
  val alu_out  = Wire(UInt(64.W))
  alu_src1 := Mux(io.ctrl.alu_src1_mux, io.pc, io.src1)
  alu_src2 := Mux(io.ctrl.alu_src2_mux, io.imm, io.src2)

  val alu = Module(new ALU)
  alu.io.src1 <> alu_src1
  alu.io.src2 <> alu_src2
  alu.io.result <> alu_out
  alu.io.ctrl <> io.ctrl
  alu.io.B_en <> io.B_en

  val dir_out = Mux(io.ctrl.dir_out_mux, io.imm, io.snpc)
  io.gp_out := Mux(io.ctrl.exe_out_mux, dir_out, alu_out)
}

class ALU extends Module with ALU_op with function with RVNoobConfig {
  val io = IO(new Bundle {
    val src1   = Input(UInt(xlen.W))
    val src2   = Input(UInt(xlen.W))
    val ctrl   = Input(new ALUCtrlIO)
    val result = Output(UInt(xlen.W))
    val B_en   = Output(Bool())
  })
  val add = io.ctrl.alu_op === op_add
  val sub = io.ctrl.alu_op === op_sub
  val sll = io.ctrl.alu_op === op_sll //left_shift
  val srl = io.ctrl.alu_op === op_srl // right_shift_logical
  val sra = io.ctrl.alu_op === op_sra // right_shift_arithmetic
  val xor = io.ctrl.alu_op === op_xor
  val or  = io.ctrl.alu_op === op_or
  val and = io.ctrl.alu_op === op_and
  val mul = io.ctrl.alu_op === op_mul
  val div = io.ctrl.alu_op === op_div
  val rem = io.ctrl.alu_op === op_rem

  val mulh   = io.ctrl.alu_op === op_mulh
  val mulhs  = io.ctrl.alu_op === op_mulhs
  val mulhsu = io.ctrl.alu_op === op_mulhsu
  val divs   = io.ctrl.alu_op === op_divs
  val divsw  = io.ctrl.alu_op === op_divsw
  val divw   = io.ctrl.alu_op === op_divw
  val rems   = io.ctrl.alu_op === op_rems
  val remsw  = io.ctrl.alu_op === op_remsw
  val remw   = io.ctrl.alu_op === op_remw
  val srlw   = io.ctrl.alu_op === op_srlw
  val sraw   = io.ctrl.alu_op === op_sraw
  val sllw   = io.ctrl.alu_op === op_sllw

  val alu_src1 = Wire(UInt(64.W))
  val alu_src2 = Wire(UInt(64.W))
  val add_res  = Wire(UInt(65.W))

  // 这里巨大优化空间，但等到后面再说
  alu_src1 := io.src1
  alu_src2 := MuxCase(
    io.src2,
    Array(
      sub -> ((~io.src2).asUInt() + 1.U),
      (sll || srl || sra) -> io.src2(5, 0),
      (sllw || srlw || sraw) -> io.src2(4, 0)
    )
  )
  add_res := alu_src1 +& alu_src2

  val alu_res = Wire(UInt(64.W))
  alu_res :=
    MuxCase(
      0.U,
      Array(
        (add && sub) -> add_res(63, 0),
        sll -> (alu_src1 << alu_src2),
        srl -> (alu_src1 >> alu_src2),
        sra -> (alu_src1.asSInt() >> alu_src2).asUInt(),
        xor -> (alu_src1 ^ alu_src2),
        or -> (alu_src1 | alu_src2),
        and -> (alu_src1 & alu_src2),
        mul -> (alu_src1 * alu_src2),
        div -> (alu_src1 / alu_src2),
        rem -> (alu_src1 % alu_src2),
        mulh -> ((alu_src1 * alu_src2)(127, 64)),
        mulhs -> ((alu_src1.asSInt() * alu_src2.asSInt())(127, 64)).asUInt(),
        mulhsu -> ((alu_src1.asSInt() * alu_src2)(127, 64).asUInt()),
        divs -> (alu_src1.asSInt() / alu_src2.asSInt()).asUInt(),
        divsw -> (alu_src1(31, 0).asSInt() / alu_src2(31, 0).asSInt()).asUInt(),
        divw -> (alu_src1(31, 0) / alu_src2(31, 0)),
        rems -> (alu_src1.asSInt() % alu_src2.asSInt()).asUInt(),
        remsw -> (alu_src1(31, 0).asSInt() % alu_src2(31, 0).asSInt()),
        remw -> (alu_src1(31, 0) % alu_src2(31, 0)),
        srlw -> (alu_src1(31, 0) >> alu_src2),
        sraw -> (alu_src1(31, 0).asSInt() >> alu_src2).asUInt(),
        sllw -> (alu_src1 << alu_src2)
      )
    )

  val judge = Module(new Judge)
  judge.io.alu_res <> Mux((add && sub), add_res, alu_res)
  judge.io.judge_op <> io.ctrl.judge_op
  judge.io.B_en <> io.B_en

  io.result := Mux(io.ctrl.judge_mux, judge.io.new_res, alu_res)

}

class Judge extends Module with RVNoobConfig with Judge_op with function {
  val io = IO(new Bundle {
    val alu_res  = Input(UInt(65.W))
    val judge_op = Input(UInt(jdg_op_w.W))
    val new_res  = Output(UInt(64.W))
    val B_en     = Output(Bool())
  })
  val zero = io.alu_res(63, 0) === 0.U
  io.B_en := MuxCase(
    0.B,
    Array(
      (io.judge_op === jop_beq) -> zero,
      (io.judge_op === jop_bne) -> !zero,
      (io.judge_op === jop_blt) -> io.alu_res(64),
      (io.judge_op === jop_bge) -> (!io.alu_res(64) || zero)
    )
  )

  io.new_res := MuxCase(
    0.U,
    Array(
      (io.judge_op === jop_slt) -> io.alu_res(64).asUInt(),
      (io.judge_op === jop_sextw) -> Cat(sext(io.alu_res(31, 0), 32), io.alu_res(31, 0))
    )
  )

}

class ALUCtrlIO extends Bundle with RVNoobConfig {
  val judge_mux = Bool()
  val judge_op  = UInt(jdg_op_w.W)
  val alu_op    = UInt(alu_op_w.W)
}

class EXECtrlIO extends ALUCtrlIO with RVNoobConfig {
  val alu_src1_mux = Bool()
  val alu_src2_mux = Bool()
  val exe_out_mux  = Bool()
  val dir_out_mux  = Bool()

}

object EXEGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "/home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new EXE()))
    )
}
