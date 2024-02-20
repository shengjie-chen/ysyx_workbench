package RVnpc.RVNoob.Branch

import RVnpc.RVNoob._
import chisel3._
import chisel3.util._

class BTBArrays extends Bundle with RVNoobConfig {
  val valid   = Bool()
  val tag     = UInt(BTBTagWidth.W)
  val bta     = UInt((addr_w - 2 - BTBBtaComWidth).W) // branch target address
  val br_type = UInt(2.W) // branch type
}

class RetArrays extends Bundle with RVNoobConfig {
  val valid = Bool()
  val tag   = UInt(BTBTagWidth.W)
}

class BTBUpdate extends Bundle with RVNoobConfig {
  val valid          = Bool()
  val addr           = UInt(addr_w.W)
  val bta            = UInt(addr_w.W)
  val br_type        = UInt(2.W)
  val entity_invalid = Bool()
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
  val ret_arrays = RegInit(Vec(BTBSet, new RetArrays), 0.B.asTypeOf(Vec(BTBSet, new RetArrays)))
  val bta_arrays = RegInit(Vec(BTBSet, UInt(BTBBtaComWidth.W)), 0.B.asTypeOf(Vec(BTBSet, UInt(BTBBtaComWidth.W))))

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
  val set_idx     = get_index(io.addr)
  val read_tag    = get_tag(io.addr)
  val btb_hit_oh  = Wire(Vec(BTBWay, Bool()))
  val btb_hit_way = OHToUInt(btb_hit_oh)
  val ret_hit     = Wire(Bool())
  val hit         = btb_hit_oh.asUInt().orR || ret_hit
  btb_hit_oh := 0.B.asTypeOf(btb_hit_oh)
  for (w <- 0 until BTBWay) {
    btb_hit_oh(w) := (btb_arrays(w)(set_idx).tag === read_tag) && btb_arrays(w)(set_idx).valid
  }
  if (BTBWay == 1) { btb_hit_way := 0.U }
  ret_hit    := ret_arrays(set_idx).tag === read_tag && ret_arrays(set_idx).valid
  io.hit     := hit
  io.bta     := bta_arrays(set_idx) ## Mux(ret_hit, 0.U, btb_arrays(btb_hit_way)(set_idx).bta) ## 0.U(2.W)
  io.br_type := Mux(ret_hit, br_type_id("return").U, btb_arrays(btb_hit_way)(set_idx).br_type)

  // ********************************** Write **********************************
  val correct_idx = get_index(io.update.addr)
  val correct_tag = get_tag(io.update.addr)

  //TODO: lru change may delay one cycle after id
  val LRU_bits = RegInit(VecInit(Seq.fill(BTBSet)(0.B))) //sets, UInt(waysWidth.W)))
  if (BTBWay == 2) {
    when(hit) {
      LRU_bits(set_idx) := btb_hit_way
    }
  }

  val correct_way = Wire(UInt(1.W))
  if (BTBWay == 2) {
    val correct_lru_tag0 = btb_arrays(0)(correct_idx).tag
    val correct_lru_tag1 = btb_arrays(1)(correct_idx).tag
    val correct_tag_same = correct_lru_tag0 === correct_tag || correct_lru_tag1 === correct_tag
    val correct_same_way = Mux(correct_lru_tag0 === correct_tag, 0.U, 1.U)
    correct_way := Mux(correct_tag_same, correct_same_way, ~LRU_bits(correct_idx))
  } else {
    correct_way := 0.U
  }

  when(io.update.valid) {
    when(io.update.br_type === br_type_id("return").U) {
      ret_arrays(correct_idx).valid := !io.update.entity_invalid
      ret_arrays(correct_idx).tag   := correct_tag
    }.otherwise {
      btb_arrays(correct_way)(correct_idx).valid   := !io.update.entity_invalid
      btb_arrays(correct_way)(correct_idx).tag     := correct_tag
      btb_arrays(correct_way)(correct_idx).bta     := io.update.bta(addr_w - BTBBtaComWidth - 1, 2)
      btb_arrays(correct_way)(correct_idx).br_type := io.update.br_type
      when(!io.update.entity_invalid) {
        bta_arrays(correct_idx) := io.update.bta(addr_w - 1, addr_w - BTBBtaComWidth)
      }
    }
  }

  override def desiredName = if (tapeout) ysyxid + "_" + getClassName else getClassName

}

object BTBGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/test"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new BTB()))
    )
}
