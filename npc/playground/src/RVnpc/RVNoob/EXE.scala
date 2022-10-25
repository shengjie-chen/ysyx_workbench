package RVnpc.RVNoob

import chisel3._
import chisel3.util.{Cat, HasBlackBoxInline, MuxCase}
import firrtl.transforms.BlackBoxInlineAnno

class EXE extends Module with RVNoobConfig {
  val io = IO(new Bundle {
    val src1     = Input(UInt(xlen.W))
    val src2     = Input(UInt(xlen.W))
    val imm      = Input(UInt(xlen.W))
    val mem_addr = Output(UInt(xlen.W))

    val pc   = Input(UInt(xlen.W))
    val snpc = Input(UInt(xlen.W))

    val gp_out = Output(UInt(xlen.W))
    //control
    val ctrl = Input(new EXECtrlIO)
    val B_en = Output(Bool())

  })
  val alu_src1 = Wire(UInt(xlen.W))
  val alu_src2 = Wire(UInt(xlen.W))
  val alu_out  = Wire(UInt(xlen.W))
  alu_src1 := Mux(io.ctrl.alu_src1_mux, io.pc, io.src1)
  alu_src2 := Mux(io.ctrl.alu_src2_mux, io.imm, io.src2)

  val alu = Module(new ALU)
  alu.io.src1 <> alu_src1
  alu.io.src2 <> alu_src2
  alu.io.result <> alu_out
  alu.io.mem_addr <> io.mem_addr

  alu.io.ctrl.judge_mux <> io.ctrl.judge_mux
  alu.io.ctrl.judge_op <> io.ctrl.judge_op
  alu.io.ctrl.alu_op <> io.ctrl.alu_op

  alu.io.B_en <> io.B_en

  val dir_out = Mux(io.ctrl.dir_out_mux, Mux(io.ctrl.src1_bypass,io.src1,io.imm), io.snpc)
  io.gp_out := Mux(io.ctrl.exe_out_mux, dir_out, alu_out)
}

class ALU extends Module with ALU_op with ext_function with RVNoobConfig with Judge_op {
  val io = IO(new Bundle {
    val src1     = Input(UInt(xlen.W))
    val src2     = Input(UInt(xlen.W))
    val ctrl     = Input(new ALUCtrlIO)
    val result   = Output(UInt(xlen.W))
    val B_en     = Output(Bool())
    val mem_addr = Output(UInt(xlen.W))
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
  val andinv = io.ctrl.alu_op === op_andinv

  val alu_src1 = Wire(UInt(xlen.W))
  val alu_src2 = Wire(UInt(xlen.W))
  val add_res  = Wire(UInt((xlen + 1).W))

  // 这里巨大优化空间，但等到后面再说
  alu_src1    := io.src1
  alu_src2    := Mux(sub, ((~io.src2).asUInt() + 1.U), io.src2)
  add_res     := alu_src1 +& alu_src2
  io.mem_addr := add_res(63, 0)

//  // alu type
//  val alu_base = add || sub || sll || srl || sra || xor || or || and
//  val alu_m    = mul || div || rem
//  val alu_mh   = mulh || mulhs || mulhsu
//  val alu_div  = divs
  val alu_res = Wire(UInt(xlen.W))

  val alu_div_res = Wire(UInt(xlen.W))
  alu_div_res := Mux(
    div || divs,
    Mux(div, (alu_src1 / alu_src2), (alu_src1.asSInt() / alu_src2.asSInt()).asUInt()),
    Mux(divw, (alu_src1(31, 0) / alu_src2(31, 0)), (alu_src1(31, 0).asSInt() / alu_src2(31, 0).asSInt()).asUInt())
  )

  val alu_mul_res = Wire(UInt(xlen.W))
  alu_mul_res := Mux(
    mulhsu || mulhs,
    Mux(
      mulhsu,
      ((alu_src1.asSInt() * alu_src2)(127, 64).asUInt()),
      ((alu_src1.asSInt() * alu_src2.asSInt())(127, 64)).asUInt()
    ),
    Mux(mulh, ((alu_src1 * alu_src2)(127, 64)), (alu_src1 * alu_src2))
  )

  val alu_rem_res = Wire(UInt(xlen.W))
  alu_rem_res := Mux(
    remw || remsw,
    Mux(remw, (alu_src1(31, 0) % alu_src2(31, 0)), (alu_src1(31, 0).asSInt() % alu_src2(31, 0).asSInt()).asUInt()),
    Mux(rems, (alu_src1.asSInt() % alu_src2.asSInt()).asUInt(), (alu_src1 % alu_src2))
  )

  alu_res := MuxCase(
    0.U,
    Array(
      (add || sub) -> add_res(63, 0),
      sll -> (alu_src1 << alu_src2(5, 0)),
      srl -> (alu_src1 >> alu_src2(5, 0)),
      sra -> (alu_src1.asSInt() >> alu_src2(5, 0)).asUInt(),
      xor -> (alu_src1 ^ alu_src2),
      or -> (alu_src1 | alu_src2),
      and -> (alu_src1 & alu_src2),
      (mul || mulh || mulhs || mulhsu) -> alu_mul_res,
      (div || divs || divw || divsw) -> alu_div_res,
      (rem || rems || remw || remsw) -> alu_rem_res,
      srlw -> (alu_src1(31, 0) >> alu_src2(4, 0)),
      sraw -> (alu_src1(31, 0).asSInt() >> alu_src2(4, 0)).asUInt(),
      sllw -> (alu_src1 << alu_src2(4, 0)),
      andinv -> (alu_src2 & (~alu_src1).asUInt())
      //      mul -> (alu_src1 * alu_src2),
//        div -> (alu_src1 / alu_src2),
//      rem -> (alu_src1 % alu_src2),
//      mulh -> ((alu_src1 * alu_src2)(127, 64)),
//      mulhs -> ((alu_src1.asSInt() * alu_src2.asSInt())(127, 64)).asUInt(),
//      mulhsu -> ((alu_src1.asSInt() * alu_src2)(127, 64).asUInt()),
//        divs -> (alu_src1.asSInt() / alu_src2.asSInt()).asUInt(),
//        divsw -> (alu_src1(31, 0).asSInt() / alu_src2(31, 0).asSInt()).asUInt(),
//        divw -> (alu_src1(31, 0) / alu_src2(31, 0)),
//      rems -> (alu_src1.asSInt() % alu_src2.asSInt()).asUInt(),
//      remsw -> (alu_src1(31, 0).asSInt() % alu_src2(31, 0).asSInt()).asUInt(),
//      remw -> (alu_src1(31, 0) % alu_src2(31, 0)),
    )
  )
  val u_less = (io.ctrl.judge_op === jop_sltu) || (io.ctrl.judge_op === jop_bgeu) || (io.ctrl.judge_op === jop_bltu)
  val less = Wire(Bool())
  when(u_less) {
    less := Mux(io.src2===0.U,add_res(64),!add_res(64))
  }.otherwise {
    when(io.src1(63) && !io.src2(63)) { // s1- s2+  -
      less := 1.B
    }.elsewhen(!io.src1(63) && io.src2(63)) {// s1+ s2- +
      less := 0.B
    }.otherwise {
      less := add_res(63)
    }
  }
//      when(io.src1(63) && !io.src2(63)) {
//        less := 1.B
//      }.elsewhen(!io.src1(63) && io.src2(63)) {
//        less := 0.B
//      }.otherwise {
//        less := add_res(63)
//      }

  val judge = Module(new Judge)
  judge.io.less <> less
  judge.io.old_res <> alu_res
  judge.io.judge_op <> io.ctrl.judge_op
  judge.io.B_en <> io.B_en

  io.result := Mux(io.ctrl.judge_mux, judge.io.new_res, alu_res)

}

class Judge extends Module with RVNoobConfig with Judge_op with ext_function {
  val io = IO(new Bundle {
    val less     = Input(Bool())
    val old_res  = Input(UInt(64.W))
    val judge_op = Input(UInt(jdg_op_w.W))
    val new_res  = Output(UInt(64.W))
    val B_en     = Output(Bool())
  })
  val zero = io.old_res === 0.U
  io.B_en := MuxCase(
    0.B,
    Array(
      (io.judge_op === jop_beq) -> zero,
      (io.judge_op === jop_bne) -> !zero,
      ((io.judge_op === jop_blt) || (io.judge_op === jop_bltu)) -> io.less,
      ((io.judge_op === jop_bge) || (io.judge_op === jop_bgeu)) -> !io.less//(!io.less || zero)
    )
  )

  io.new_res := MuxCase(
    io.old_res,
    Array(
      ((io.judge_op === jop_slt) || (io.judge_op === jop_sltu)) -> io.less.asUInt(),
//      (io.judge_op === jop_slt) -> io.less.asUInt(),
//      (io.judge_op === jop_sltu) -> ((!io.less)&&(!zero)).asUInt(),
      (io.judge_op === jop_sextw) -> sext_64(io.old_res(31, 0))
      // ,
      // (io.judge_op === jop_sexthw) -> sext_64(io.old_res(15, 0)),
      // (io.judge_op === jop_sextb) -> sext_64(io.old_res(7, 0)),
      // (io.judge_op === jop_uextw) -> uext_64(io.old_res(31, 0)),
      // (io.judge_op === jop_uexthw) -> uext_64(io.old_res(15, 0)),
      // (io.judge_op === jop_uextb) -> uext_64(io.old_res(7, 0))
    )
  )

}

//class Div extends BlackBox with HasBlackBoxInline with RVNoobConfig {
//  val io = IO(new Bundle{
//    val div = Input(Bool())
//    val divs = Input(Bool())
//    val divv = Input(Bool())
//    val divvw = Input(Bool())
//    val alu_src1 = Input(UInt(xlen.W))
//    val alu_src2 = Input(UInt(xlen.W))
//    val alu_div_res = Output(UInt(xlen.W))
//  })
//  setInline(
//    "Div.v",
//    """
//      |module Div(input [31:0] inst);
//      |
//      | //initial set_inst_ptr(inst);
//      |
//      | always @* inst_change(inst);
//      |
//      |endmodule
//            """.stripMargin
//  )
//
//  //  alu_div_res := Mux(
//  //    div || divs,
//  //    Mux(div, (alu_src1 / alu_src2), (alu_src1.asSInt() / alu_src2.asSInt()).asUInt()),
//  //    Mux(divw, (alu_src1(31, 0) / alu_src2(31, 0)), (alu_src1(31, 0).asSInt() / alu_src2(31, 0).asSInt()).asUInt())
//  //  )
//}

object EXEGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "/home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new EXE()))
    )
}
