package RVnpc.RVNoob.Branch

import RVnpc.RVNoob._
import chisel3._

class PHTUpdate extends Bundle with RVNoobConfig {
  val valid = Bool()
  val addr  = UInt(addr_w.W)
  val taken = Bool()
}

class PHTs extends Module with RVNoobConfig {
  val io = IO(new Bundle {
    val addr   = Input(UInt(addr_w.W))
    val taken  = Output(Bool())
    val update = Input(new PHTUpdate)
  })

  def pht(take: Bool, correct: Bool): UInt = {
    val pht = RegInit(1.U(2.W))
    when(correct) {
      when(pht === 0.U && !take || pht === 3.U && take) {
        pht := pht
      }.elsewhen(take) {
        pht := pht + 1.U
      }.elsewhen(!take) {
        pht := pht - 1.U
      }
    }
    pht
  }

  // update
  val update_addr = io.update.addr(PhtAddrWidth - 1 + 2, 2)
  val phts_correct_choose = Wire(Vec(PhtDepth, Bool()))
  phts_correct_choose := 0.U.asTypeOf(phts_correct_choose)
  when(io.update.valid) {
    phts_correct_choose(update_addr) := 1.B
  }
  val phts  = Array.tabulate(PhtDepth)(index => pht(io.update.taken, phts_correct_choose(index)))

  // read
  val read_index = io.addr(PhtAddrWidth - 1 + 2, 2)
  val taken = Wire(Vec(PhtDepth, Bool()))
  for (i <- 0 until PhtDepth) {
    taken(i) := phts(i)(1)
  }
  io.taken := taken(read_index)

}

object PHTsGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/test"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new PHTs()))
    )
}
