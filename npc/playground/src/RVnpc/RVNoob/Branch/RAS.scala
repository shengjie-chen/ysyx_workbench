//package RVnpc.RVNoob.Branch
//
//import RVnpc.RVNoob._
//import chisel3._
//import chisel3.util._
//import scala.math.pow
//
//class RASArrays extends Bundle with RVNoobConfig {
//  val addr = UInt(addr_w.W)
//  val cnt  = UInt(log2Ceil(RASCntNum).W)
//}
//
//class RAS extends Module with RVNoobConfig {
//  val io = IO(new Bundle {
//    val push = Flipped(ValidIO(UInt(addr_w.W)))
//    val pop  = Decoupled(UInt(addr_w.W))
//  })
//
//  val push_index = RegInit(0.U(log2Ceil(RASDepth).W))
//  val pop_index  = Wire(push_index.cloneType) // push_index - 1
//  val ras        = RegInit(Vec(RASDepth, new RASArrays), 0.B.asTypeOf(Vec(RASDepth, new RASArrays)))
//  val pop_valid = RegInit(0.B)
//  pop_index := rangeSub(push_index, RASDepth)
//  when(io.push.valid){
//    pop_valid := 1.B
//  }
//  io.pop.valid := pop_valid
//
//  when(io.push.valid && !io.pop.ready) {
//    when(ras(pop_index).addr === io.push.bits && ras(pop_index).cnt =/= (RASCntNum - 1).U) { // push the same addr
//      ras(pop_index).cnt := rangeAdd(ras(pop_index).cnt, RASCntNum)
//    }.otherwise {
//      ras(push_index).addr := io.push.bits
//      ras(push_index).cnt  := 0.U
//      push_index           := rangeAdd(push_index, RASDepth)
//    }
//  }
//
//  io.pop.bits := ras(pop_index).addr
//  when(io.pop.ready && !io.push.valid) {
//    when(ras(pop_index).cnt =/= 0.U) {
//      ras(pop_index).cnt := ras(pop_index).cnt - 1.U
//    }.otherwise {
//      push_index := pop_index
//    }
//  }
//
//  when(io.push.valid && io.pop.ready) {
//    io.pop.bits := io.push.bits
//  }
//
//}
//
//object RASGen extends App {
//  (new chisel3.stage.ChiselStage)
//    .execute(
//      Array("--target-dir", "./build/test"),
//      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new RAS()))
//    )
//}
