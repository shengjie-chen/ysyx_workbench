package RVNoob
import chisel3._
class RVNoob extends Module{
  val io = IO(new Bundle{
    val pc = Output(UInt(64.W))
    val inst = Input(UInt(32.W))
  })
  val pc = RegInit(0x0000000080000000.U(64.W))
  val snpc = Wire(UInt(64.W))
  snpc := pc + 4.U
  pc := snpc
  io.pc := pc

  val idu = Module(new IDU)
  val rf = Module(new RegisterFile)
  val exe = Module(new EXE)

  idu.io.inst := io.inst

  rf.io.wen <> idu.io.wen
  rf.io.wdata <> exe.io.result
  rf.io.waddr <> idu.io.rd
  rf.io.ren1 <> idu.io.ren1
  rf.io.ren2 <> idu.io.ren2
  rf.io.raddr1 <> idu.io.rs1
  rf.io.raddr2 <> idu.io.rs2

  exe.io.src1 <> rf.io.rdata1
  exe.io.src2 <> idu.io.imm

}

object RVNoobGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(args, Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new RVNoob())))
}
