package RVnpc.RVNoob.Pipeline
import chisel3._
import chisel3.util._
import RVnpc.RVNoob._

class RegCtrl extends Bundle {
  val en    = Bool()
  val flush = Bool()
}

// maybe name PipeLineCtrl
class PipelineCtrl extends Module with RVNoobConfig {
  val io = IO(new Bundle {
    val idu_rf          = Input(new IdRfCtrlIO)
    val idu_csr         = Input(new IdCsrCtrlIO)
    val ex_reg_rf       = Input(new WbRfCtrlIO)
    val ex_reg_csr      = Input(new WbCsrCtrlIO)
    val ex_reg_mem_ctrl = Input(new MemCtrlIO)
    val mem_reg_rf      = Input(new WbRfCtrlIO)
    val mem_reg_csr     = Input(new WbCsrCtrlIO)
    val dnpc_en         = Input(Bool())
    val miss            = Input(Bool())
    val id_reg_ctrl     = Output(new RegCtrl)
    val ex_reg_ctrl     = Output(new RegCtrl)
    val mem_reg_ctrl    = Output(new RegCtrl)
    val wb_reg_ctrl     = Output(new RegCtrl)
    val pc_en           = Output(Bool())
    val forward1        = Output(UInt(2.W))
    val forward2        = Output(UInt(2.W))
    val ex_csr_hazard   = Output(Bool())
  })
  val sNone :: sDH1 :: Nil = Enum(2) // Data Hazard
  val state                = RegInit(sNone)
  // condition
  val ex_hazard_1 =
    (io.idu_rf.rs1 === io.ex_reg_rf.rd) && (io.ex_reg_rf.rd =/= 0.U) && io.ex_reg_rf.wen && io.idu_rf.ren1
  val ex_hazard_2 =
    (io.idu_rf.rs2 === io.ex_reg_rf.rd) && (io.ex_reg_rf.rd =/= 0.U) && io.ex_reg_rf.wen && io.idu_rf.ren2
  val ex_hazard_1_bypass = ex_hazard_1 && !io.ex_reg_mem_ctrl.r_pmem
  val ex_hazard_1_delay  = ex_hazard_1 && io.ex_reg_mem_ctrl.r_pmem
  val ex_hazard_2_bypass = ex_hazard_2 && !io.ex_reg_mem_ctrl.r_pmem
  val ex_hazard_2_delay  = ex_hazard_2 && io.ex_reg_mem_ctrl.r_pmem
  val mem_hazard_1 =
    (io.idu_rf.rs1 === io.mem_reg_rf.rd) && (io.mem_reg_rf.rd =/= 0.U) && io.mem_reg_rf.wen && io.idu_rf.ren1
  val mem_hazard_2 =
    (io.idu_rf.rs2 === io.mem_reg_rf.rd) && (io.mem_reg_rf.rd =/= 0.U) && io.mem_reg_rf.wen && io.idu_rf.ren2

  val ex_csr_hazard =
    io.ex_reg_csr.csr_wen && io.idu_csr.csr_ren && io.idu_csr.csr_raddr === io.ex_reg_csr.csr_waddr
  val mem_csr_hazard =
    io.mem_reg_csr.csr_wen && io.idu_csr.csr_ren && io.idu_csr.csr_raddr === io.mem_reg_csr.csr_waddr

  // Forward
  val forward1 =
    RegEnable(Mux(ex_hazard_1_bypass, 2.U, Mux(mem_hazard_1, 1.U, 0.U)), 0.U, !io.miss) // ex_hazard优先级大于mem_hazard
  val forward2 = RegEnable(Mux(ex_hazard_2_bypass, 2.U, Mux(mem_hazard_2, 1.U, 0.U)), 0.U, !io.miss)
  io.forward1 := forward1
  io.forward2 := forward2

  // Delay
  val normal_state = {
    val ns = Wire(new RegCtrl)
    ns.en    := 1.B
    ns.flush := 0.B
    ns
  }
  val delay_state = {
    val ns = Wire(new RegCtrl)
    ns.en    := 0.B
    ns.flush := 0.B
    ns
  }
  val flush_state = {
    val ns = Wire(new RegCtrl)
    ns.en    := 0.B
    ns.flush := 1.B
    ns
  }

  io.id_reg_ctrl   := normal_state
  io.ex_reg_ctrl   := normal_state
  io.mem_reg_ctrl  := normal_state
  io.wb_reg_ctrl   := normal_state
  io.pc_en         := 1.B
  io.ex_csr_hazard := 0.B

  def if_id_delay_ex_flush = { // if,id stop, ex flush
    io.id_reg_ctrl := delay_state
    io.ex_reg_ctrl := flush_state
    io.pc_en       := 0.B
  }

  when(io.miss) {
    io.id_reg_ctrl  := delay_state
    io.ex_reg_ctrl  := delay_state
    io.mem_reg_ctrl := delay_state
    io.wb_reg_ctrl  := delay_state
    io.pc_en        := 0.B
  }.otherwise {
    when(io.dnpc_en) {
      io.id_reg_ctrl := flush_state
      io.ex_reg_ctrl := flush_state
      state          := sNone
    }.otherwise {
      switch(state) {
        is(sNone) {
          when(ex_hazard_1_delay || ex_hazard_2_delay) {
            if_id_delay_ex_flush
            state := sNone
          }.elsewhen(ex_csr_hazard) {
            if_id_delay_ex_flush
            state            := sDH1
            io.ex_csr_hazard := 1.B
          }.elsewhen(mem_csr_hazard) {
            if_id_delay_ex_flush
            state := sNone
          }
        }
        is(sDH1) {
          if_id_delay_ex_flush
          io.mem_reg_ctrl := flush_state
          state           := sNone
        }
      }
    }
  }

  override def desiredName = if (tapeout) ysyxid + "_" + getClassName else getClassName

}

object PipelineCtrl {
  def apply(
    idu_rf:      IdRfCtrlIO,
    idu_csr:     IdCsrCtrlIO,
    ex_reg_rf:   WbRfCtrlIO,
    ex_reg_csr:  WbCsrCtrlIO,
    mem_reg_rf:  WbRfCtrlIO,
    mem_reg_csr: WbCsrCtrlIO,
    dnpc_en:     Bool
  ): PipelineCtrl = {
    val hazard = Module(new PipelineCtrl)
    hazard.io.idu_rf      <> idu_rf
    hazard.io.idu_csr     <> idu_csr
    hazard.io.ex_reg_rf   <> ex_reg_rf
    hazard.io.ex_reg_csr  <> ex_reg_csr
    hazard.io.mem_reg_rf  <> mem_reg_rf
    hazard.io.mem_reg_csr <> mem_reg_csr
    hazard.io.dnpc_en     <> dnpc_en

    hazard
  }
}

object PipelineCtrlGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/test"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new PipelineCtrl()))
    )
}
