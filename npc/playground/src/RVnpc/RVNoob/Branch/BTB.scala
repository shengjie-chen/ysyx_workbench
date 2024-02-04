package RVnpc.RVNoob.Branch

import RVnpc.RVNoob._
import chisel3._
import chisel3.util._
import scala.math.pow

class BTBArrays extends Bundle with RVNoobConfig {
  val valid   = Bool()
  val tag     = UInt(BTBTagWidth.W)
  val bta     = UInt(addr_w.W) // branch target address
  val br_type = UInt(2.W) // branch type
}

class BTBUpdate extends Bundle with RVNoobConfig {
  val valid   = Bool()
  val addr    = UInt(addr_w.W)
  val bta     = UInt(addr_w.W)
  val br_type = UInt(2.W)
}

class BTB extends Module with RVNoobConfig {
  val io = IO(new Bundle {
    val addr    = Input(UInt(addr_w.W))
    val bta     = Output(UInt(addr_w.W))
    val br_type = Output(UInt(2.W))
    val hit     = Output(Bool())
    val update  = Input(new BTBUpdate)
  })

  val btb_arrays =
    RegInit(Vec(BTBWay, Vec(BTBSet, new BTBArrays)), 0.B.asTypeOf(Vec(BTBWay, Vec(BTBSet, new BTBArrays))))

  def xor_hash(addr: UInt): UInt = {
    assert(addr.getWidth == 2 * BTBTagWidth)
    val hash_value = Wire(Vec(BTBTagWidth, Bool()))
    for (i <- 0 until BTBTagWidth) {
      hash_value(i) := addr(i) ^ addr(i + BTBTagWidth)
    }
    hash_value.asUInt()
  }

  def get_tag(addr: UInt): UInt = {
    xor_hash(addr(1 + BTBSetWidth + 2 * BTBTagWidth, 2 + BTBSetWidth))
  }

  def get_index(addr: UInt): UInt = {
    addr(1 + BTBSetWidth, 2)
  }

  // ********************************** Read **********************************
  val set_idx  = get_index(io.addr)
  val read_tag = get_tag(io.addr)
  val hit_oh   = Wire(Vec(BTBWay, Bool()))
  val hit_way  = OHToUInt(hit_oh)
  val hit      = hit_oh.asUInt().orR
  hit_oh := 0.B.asTypeOf(hit_oh)
  for (w <- 0 until BTBWay) {
    hit_oh(w) := (btb_arrays(w)(set_idx).tag === read_tag) && btb_arrays(w)(set_idx).valid
  }
  io.hit     := hit
  io.bta     := btb_arrays(hit_way)(set_idx).bta
  io.br_type := btb_arrays(hit_way)(set_idx).br_type

  // ********************************** Write **********************************
  val correct_idx = get_index(io.update.addr)
  val correct_tag = get_tag(io.update.addr)

  //TODO: PLRU change may delay one cycle after id
  val PLRU_bits = RegInit(VecInit(Seq.fill(BTBSet)(0.B))) //sets, UInt(waysWidth.W)))
  if (BTBWay == 2) {
    when(hit) {
      PLRU_bits(set_idx) := hit_way
    }
  }

  val correct_way = Wire(UInt(log2Ceil(BTBWay).W))
  correct_way := Mux(
    btb_arrays(PLRU_bits(correct_idx))(correct_idx).tag === correct_tag,
    PLRU_bits(correct_idx),
    !PLRU_bits(correct_idx)
  )

  when(io.update.valid) {
    btb_arrays(correct_way)(correct_idx).valid   := 1.B
    btb_arrays(correct_way)(correct_idx).tag     := correct_tag
    btb_arrays(correct_way)(correct_idx).bta     := io.update.bta
    btb_arrays(correct_way)(correct_idx).br_type := io.update.br_type
  }

}

object BTBGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/test"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new BTB()))
    )
}
