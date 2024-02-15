package RVnpc.RVNoob.Branch

import RVnpc.RVNoob._
import chisel3._

class PHTUpdate extends Bundle with RVNoobConfig {
  val valid   = Bool()
  val addr    = UInt(addr_w.W)
  val taken   = Bool()
  val bht_reg = Input(UInt(BHTRegWidth.W))
}

class PHTs extends Module with RVNoobConfig {
  val io = IO(new Bundle {
    val addr    = Input(UInt(addr_w.W))
    val taken   = Output(Bool())
    val bht_reg = Input(UInt(BHTRegWidth.W))
    val update  = Input(new PHTUpdate)
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

  def hash_index(pc: UInt, bht_reg: UInt): UInt = {
    val pc_width = PhtAddrWidth - BHTRegWidth
    val index    = Wire(UInt(PhtAddrWidth.W))
    index := pc(pc_width - 1 + 2 + BHTAddrWidth, 2 + BHTAddrWidth) ## bht_reg
    index
  }

  // update
  val update_index        = hash_index(io.update.addr, io.update.bht_reg)
  val phts_correct_choose = Wire(Vec(PhtDepth, Bool()))
  phts_correct_choose := 0.U.asTypeOf(phts_correct_choose)
  when(io.update.valid) {
    phts_correct_choose(update_index) := 1.B
  }

  val phts = Array.tabulate(PhtDepth)(index => pht(io.update.taken, phts_correct_choose(index)))

  // read
  val read_index = hash_index(io.addr, io.bht_reg)
  val taken      = Wire(Vec(PhtDepth, Bool()))
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
