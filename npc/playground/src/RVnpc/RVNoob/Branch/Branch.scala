package RVnpc.RVNoob.Branch

import RVnpc.RVNoob.RVNoobConfig
import chisel3._
import chisel3.util._

class branch_pre extends Bundle with RVNoobConfig {
  val taken  = Bool()
  val target = UInt(addr_w.W)
//  val snpc    = UInt(addr_w.W)
  val br_type = UInt(3.W) // 5 type
}

class branch_info extends Bundle with RVNoobConfig {
  val taken   = Bool()
  val target  = UInt(addr_w.W)
  val br_type = UInt(3.W) // 5 type
}

class BranchUpdate extends Module with RVNoobConfig {
  val io = IO(new Bundle {
    val pc            = Input(UInt(addr_w.W))
    val snpc          = Input(UInt(addr_w.W))
    val valid         = Input(Bool())
    val br_pre        = Input(new branch_pre)
    val br_info       = Input(new branch_info)
    val btb_update    = Output(new BTBUpdate)
    val pht_update    = Output(new PHTUpdate)
    val ras_push      = ValidIO(UInt(addr_w.W))
    val ras_pop_valid = Output(Bool())
    val ras_pop_reset = Output(Bool())
  })

  when(io.br_info.br_type === br_type_id("typeb").U && io.valid) {
    io.pht_update.valid := 1.B
    io.pht_update.addr  := io.pc
    io.pht_update.taken := io.br_info.taken
  }.otherwise {
    io.pht_update.valid := 0.B
    io.pht_update.addr  := 0.U
    io.pht_update.taken := 0.B
  }

  when(
    (io.br_info.br_type =/= br_type_id("not_br").U && io.br_info.br_type =/= br_type_id("intr").U) && io.br_info.taken
      && (io.br_info.br_type =/= io.br_pre.br_type || io.br_info.target =/= io.br_pre.target) && io.valid
  ) {
    io.btb_update.valid          := 1.B
    io.btb_update.addr           := io.pc
    io.btb_update.bta            := io.br_info.target
    io.btb_update.br_type        := io.br_info.br_type(1, 0)
    io.btb_update.entity_invalid := 0.B
  }.elsewhen(
    (io.br_info.br_type =/= br_type_id("not_br").U && io.br_info.br_type =/= br_type_id("intr").U)
      && io.br_pre.taken && io.valid
  ) {
    io.btb_update.valid          := 1.B
    io.btb_update.addr           := io.pc
    io.btb_update.bta            := 0.U
    io.btb_update.br_type        := io.br_pre.br_type(1, 0)
    io.btb_update.entity_invalid := 1.B
  }.otherwise {
    io.btb_update.valid          := 0.B
    io.btb_update.addr           := 0.U
    io.btb_update.bta            := 0.U
    io.btb_update.br_type        := 0.U
    io.btb_update.entity_invalid := 0.B
  }

  io.ras_push.bits := io.snpc
  when(io.br_info.br_type === br_type_id("call").U && io.valid) {
    io.ras_push.valid := 1.B
  }.otherwise {
    io.ras_push.valid := 0.B
  }
  val ras_error_cnt = RegInit(0.U(2.W))
  val ret_pre_right = io.br_pre.taken && io.br_pre.target === io.br_info.target
  val return_error  = io.br_info.br_type === br_type_id("return").U && io.valid && !ret_pre_right
  val return_right  = io.br_info.br_type === br_type_id("return").U && io.valid && ret_pre_right
  val ras_reset_reg = RegInit(0.B)

  io.ras_pop_valid := return_error
  when(!io.ras_pop_reset) {
    when(return_error) {
      ras_error_cnt := ras_error_cnt + 1.U
    }.elsewhen(return_right) {
      ras_error_cnt := 0.U
    }
  }

  io.ras_pop_reset := !io.ras_push.valid && ras_reset_reg
  when(return_error && !io.ras_pop_reset && ras_error_cnt === 3.U) {
    ras_reset_reg := 1.B
  }.elsewhen(io.ras_push.valid) {
    ras_reset_reg := 0.B
  }

  override def desiredName = if (tapeout) ysyxid + "_" + getClassName else getClassName
}
