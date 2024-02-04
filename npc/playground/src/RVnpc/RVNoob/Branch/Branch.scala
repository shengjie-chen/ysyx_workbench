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
    val pc         = Input(UInt(addr_w.W))
    val snpc       = Input(UInt(addr_w.W))
    val valid      = Input(Bool())
    val br_pre     = Input(new branch_pre)
    val br_info    = Input(new branch_info)
    val btb_update = Output(new BTBUpdate)
    val pht_update = Output(new PHTUpdate)
    val ras_push   = ValidIO(UInt(addr_w.W))
  })

  when(io.br_info.br_type =/= br_type_id("not_br").U && io.valid) {
    io.pht_update.valid := 1.B
    io.pht_update.addr  := io.pc
    io.pht_update.taken := io.br_info.taken
  }.otherwise {
    io.pht_update.valid := 0.B
    io.pht_update.addr  := 0.U
    io.pht_update.taken := 0.B
  }

  when(io.br_info.br_type =/= br_type_id("not_br").U && (io.br_info.br_type =/= io.br_pre.br_type || io.br_info.target =/= io.br_pre.target) && io.valid) {
    io.btb_update.valid   := 1.B
    io.btb_update.addr    := io.pc
    io.btb_update.bta     := io.br_info.target
    io.btb_update.br_type := io.br_info.br_type
  }.otherwise {
    io.btb_update.valid   := 0.B
    io.btb_update.addr    := 0.U
    io.btb_update.bta     := 0.U
    io.btb_update.br_type := 0.U
  }

  io.ras_push.bits := io.snpc
  when(io.br_info.br_type === br_type_id("call").U && io.valid) {
    io.ras_push.valid := 1.B
  }.otherwise {
    io.ras_push.valid := 0.B
  }

}
