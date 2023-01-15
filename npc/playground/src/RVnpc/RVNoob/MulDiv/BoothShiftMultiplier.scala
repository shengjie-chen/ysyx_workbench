package RVnpc.RVNoob.MulDiv

import RVnpc.RVNoob.RVNoobConfig
import chisel3._
import chisel3.util._

class BoothShiftMultiplier extends Module with RVNoobConfig {
  val io = IO(new Bundle() {
    val mul_valid    = Input(Bool())
    val flush        = Input(Bool())
    val mulw         = Input(Bool())
    val mul_signed   = Input(UInt(2.W))
    val multiplicand = Input(UInt(xlen.W))
    val multiplier   = Input(UInt(xlen.W))

    val mul_ready    = Output(Bool())
    val out_valid    = Output(Bool())
    val result_hi    = Output(UInt(xlen.W))
    val result_lo    = Output(UInt(xlen.W))
  })

  val multiplier    = Reg(UInt(67.W))
  val multiplicand  = Reg(UInt(128.W))
  val result        = Reg(UInt(128.W))
  val cnt           = Reg(UInt(6.W))
  val multing_state = RegInit(0.B)
  val booth         = Module(new BoothTransform)

  booth.io.multiplicand <> multiplicand
  booth.io.low_3b       <> multiplier(2, 0)

  when(io.flush) {
    multiplier   := 0.U
    multiplicand := 0.U
    result       := 0.U
  }.elsewhen(io.mul_valid) {
    result := 0.U
    when(io.mul_signed === 0.U) {
      multiplier   := 0.U ## io.multiplier ## 0.B
      multiplicand := 0.U ## io.multiplicand
    }.elsewhen(io.mul_signed === 2.U) {
      multiplier   := 0.U ## io.multiplier ## 0.B
      multiplicand := VecInit(Seq.fill(64)(io.multiplicand.head(1))).asUInt() ## io.multiplicand
    }.elsewhen(io.mul_signed === 3.U) {
      multiplier   := VecInit(Seq.fill(2)(io.multiplier.head(1))).asUInt() ## io.multiplier ## 0.B
      multiplicand := VecInit(Seq.fill(64)(io.multiplicand.head(1))).asUInt() ## io.multiplicand
    }

  }.elsewhen(multing_state) {
    multiplier   := multiplier >> 2
    multiplicand := multiplicand << 2
    result       := result + booth.io.part_product
  }

  when(io.flush) {
    multing_state := 0.B
  }.elsewhen(io.mul_valid) {
    multing_state := 1.B
  }.elsewhen(multing_state && (io.mulw && cnt === 31.U || !io.mulw && cnt === 32.U)) {
    multing_state := 0.B
  }

  when(io.mul_valid) {
    cnt := 0.U
  }.elsewhen(multing_state) {
    cnt := cnt + 1.U
  }

  io.mul_ready := !multing_state
  io.out_valid := !multing_state && RegNext(multing_state)
  io.result_hi := result(127, 64)
  io.result_lo := result(63, 0)

}

object BoothShiftMultiplierGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/test"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new BoothShiftMultiplier()))
    )
}