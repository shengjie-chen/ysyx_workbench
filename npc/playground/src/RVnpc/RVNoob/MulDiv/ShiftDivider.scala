package RVnpc.RVNoob.MulDiv

import RVnpc.RVNoob.RVNoobConfig
import chisel3._
import chisel3.util._

class ShiftDivider extends Module with RVNoobConfig {
  val io = IO(new Bundle() {
    val dividend   = Input(UInt(xlen.W))
    val divisor    = Input(UInt(xlen.W))
    val div_valid  = Input(Bool())
    val divw       = Input(Bool())
    val div_signed = Input(Bool())
    val flush      = Input(Bool())

    val div_ready = Output(Bool())
    val out_valid = Output(Bool())
    val quotient  = Output(UInt(xlen.W))
    val remainder = Output(UInt(xlen.W))
  })

  val divisor          = Reg(UInt(64.W))
  val result           = Reg(UInt(128.W))
  val remainder_signed = Reg(Bool())
  val quotient_signed  = Reg(Bool())
  val neg_divisor      = Wire(UInt(64.W))
  val neg_dividend     = Wire(UInt(64.W))
  val cnt              = Reg(UInt(6.W))
  val diving_state     = RegInit(0.B)
  val sub_res          = Wire(UInt(65.W))
  val sub_in1          = Wire(UInt(65.W))
  val sub_in2          = Wire(UInt(65.W))

  neg_divisor  := (~io.divisor).asUInt() + 1.U
  neg_dividend := (~io.dividend).asUInt() + 1.U
  sub_in1      := Mux(io.divw, result(63, 31).asUInt(), result(127, 63).asUInt())
  sub_in2      := (~(0.B ## divisor)).asUInt() + 1.U
  sub_res      := sub_in1 + sub_in2

  when(io.flush) {
    divisor          := 0.U
    result           := 0.U
    remainder_signed := 0.U
    quotient_signed  := 0.U
  }.elsewhen(io.div_valid) {
    quotient_signed  := 0.B
    remainder_signed := 0.B
    when(io.divw) {
      when(io.div_signed) {
        divisor          := 0.U(32.W) ## Mux(io.divisor(31), neg_divisor(31, 0), io.divisor(31, 0))
        result           := 0.U ## Mux(io.dividend(31), neg_dividend(31, 0), io.dividend(31, 0))
        quotient_signed  := io.divisor(31) ^ io.dividend(31)
        remainder_signed := io.dividend(31)
      }.otherwise {
        divisor := 0.U(32.W) ## io.divisor(31, 0)
        result  := 0.U ## io.dividend(31, 0)
      }
    }.otherwise {
      when(io.div_signed) {
        divisor          := Mux(io.divisor(63), neg_divisor, io.divisor)
        result           := 0.U ## Mux(io.dividend(63), neg_dividend, io.dividend)
        quotient_signed  := io.divisor(63) ^ io.dividend(63)
        remainder_signed := io.dividend(63)
      }.otherwise {
        divisor := io.divisor
        result  := io.dividend
      }
    }
  }.elsewhen(diving_state) { // result left shift
    when(sub_res(64)) {
      result := result(126, 0) ## 0.B
    }.otherwise {
      when(io.divw) {
        result := sub_res(31, 0) ## result(30, 0) ## 1.B
      }.otherwise {
        result := sub_res(63, 0) ## result(62, 0) ## 1.B
      }
    }
  }

  when(io.flush) {
    diving_state := 0.B
  }.elsewhen(io.div_valid) {
    diving_state := 1.B
  }.elsewhen(diving_state && ((!io.divw && cnt === 63.U) || (io.divw && cnt === 31.U))) {
    diving_state := 0.B
  }

  when(io.div_valid) {
    cnt := 0.U
  }.elsewhen(diving_state) {
    cnt := cnt + 1.U
  }

  io.div_ready := !diving_state
  io.out_valid := !diving_state && RegNext(diving_state)
  io.quotient := Mux(
    io.divw,
    Mux(quotient_signed, (~result(31, 0)).asUInt() + 1.U, result(31, 0)),
    Mux(quotient_signed, (~result(63, 0)).asUInt() + 1.U, result(63, 0))
  )
  io.remainder := Mux(
    io.divw,
    Mux(remainder_signed, (~result(63, 32)).asUInt() + 1.U, result(63, 32)),
    Mux(remainder_signed, (~result(127, 64)).asUInt() + 1.U, result(127, 64))
  )
}

object ShiftDividerGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/test"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new ShiftDivider()))
    )
}
