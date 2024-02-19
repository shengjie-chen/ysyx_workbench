package RVnpc.RVNoob.Branch

import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

class RASArrays extends Bundle with RVNoobConfig {
  val addr = UInt(addr_w.W)
  val cnt  = UInt(log2Ceil(RASCntNum).W)
}

class RAS extends Module with RVNoobConfig {
  val io = IO(new Bundle {
    val push = Flipped(ValidIO(UInt(addr_w.W)))
    val pop  = Decoupled(UInt(addr_w.W))
  })

  val push_index = RegInit(0.U(log2Ceil(RASDepth).W))
  val pop_index  = Wire(push_index.cloneType) // push_index - 1
  val ras        = RegInit(Vec(RASDepth, new RASArrays), 0.B.asTypeOf(Vec(RASDepth, new RASArrays)))
  val valid_cnt  = RegInit(0.U(log2Ceil(RASDepth * RASCntNum).W))
  val base_index = RegInit(0.U(log2Ceil(RASDepth).W)) // oldest valid index

  pop_index    := rangeSub(push_index, RASDepth)
  io.pop.valid := valid_cnt =/= 0.U

  when(io.push.valid && !io.pop.ready) {
    when(ras(pop_index).addr === io.push.bits && ras(pop_index).cnt =/= (RASCntNum - 1).U) { // push the same addr
      ras(pop_index).cnt := rangeAdd(ras(pop_index).cnt, RASCntNum)
      valid_cnt          := valid_cnt + 1.U
    }.otherwise { // push in new entity
      ras(push_index).addr := io.push.bits
      ras(push_index).cnt  := 0.U
      push_index           := rangeAdd(push_index, RASDepth)
      when(push_index === base_index && valid_cnt >= RASDepth.U) { // oldest valid entity overwrite
        base_index := rangeAdd(base_index, RASDepth)
        valid_cnt  := valid_cnt - ras(base_index).cnt
      }.otherwise {
        valid_cnt := valid_cnt + 1.U
      }
    }
  }

  when(io.pop.ready && !io.push.valid && io.pop.valid) {
    when(ras(pop_index).cnt =/= 0.U) {
      ras(pop_index).cnt := ras(pop_index).cnt - 1.U
    }.otherwise {
      push_index := pop_index
    }
    valid_cnt := valid_cnt - 1.U
  }

  val pop_bits_reg = RegInit(0.U(addr_w.W))
  when(io.pop.ready) {
    pop_bits_reg := io.pop.bits
  }
  io.pop.bits := Mux(io.pop.ready, Mux(io.push.valid, io.push.bits, ras(pop_index).addr), pop_bits_reg)

  assert(io.push.valid && io.push.bits =/= 0.U, "RAS push 0")

  override def desiredName = if (tapeout) ysyxid + "_" + getClassName else getClassName

}

object RASGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/test"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new RAS()))
    )
}
