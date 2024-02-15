package RVnpc.RVNoob.Branch
import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

class BHTUpdate extends Bundle with RVNoobConfig {
  val valid = Bool()
  val addr  = UInt(addr_w.W)
  val taken = Bool()
}
class BHT extends Module with RVNoobConfig {
  val io = IO(new Bundle {
    val addr    = Input(UInt(addr_w.W))
    val bht_reg = Output(UInt(BHTRegWidth.W))
    val update  = Input(new BHTUpdate)
  })

  def bht(take: Bool, correct: Bool): Array[Bool] = {
    val bht = Array.fill(BHTRegWidth)(RegInit(0.B))
    when(correct) {
      for (i <- 1 until BHTRegWidth) {
        bht(i) := bht(i - 1)
      }
      bht(0) := take
    }
    bht
  }
  def get_index(pc: UInt): UInt = {
    val index = pc(2 + BHTAddrWidth - 1, 2)
    index
  }

  // update
  val update_index        = get_index(io.update.addr)
  val bhts_correct_choose = Wire(Vec(BHTDepth, Bool()))
  bhts_correct_choose := 0.U.asTypeOf(bhts_correct_choose)
  when(io.update.valid) {
    bhts_correct_choose(update_index) := 1.B
  }

  val bhts = Array.tabulate(BHTDepth)(index => bht(io.update.taken, bhts_correct_choose(index)))

  // read
  val read_index = get_index(io.addr)
  val bhts_wire  = Wire(Vec(BHTDepth, UInt(BHTRegWidth.W)))
  for (i <- 0 until BHTDepth) {
    bhts_wire(i) := Cat(bhts(i).reverse)
  }
  io.bht_reg := bhts_wire(read_index)

}

object BHTGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/test"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new BHT()))
    )
}
