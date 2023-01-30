package RVnpc.RVNoob.MulDiv
import chisel3._
import RVnpc.RVNoob.RVNoobConfig

class BoothTransform extends Module with RVNoobConfig {
  val io = IO(new Bundle() {
    val multiplicand = Input(UInt(128.W))
    val low_3b       = Input(UInt(3.W))
    val part_product = Output(UInt(128.W))
  })
  val y_add = io.low_3b(2)
  val y     = io.low_3b(1)
  val y_sub = io.low_3b(0)

  val sel_negative        = y_add & ((y & !y_sub) | (!y & y_sub))
  val sel_positive        = !y_add & (y & !y_sub | !y & y_sub)
  val sel_double_negative = y_add & !y & !y_sub
  val sel_double_positive = !y_add & y & y_sub

  val x     = io.multiplicand.asBools()
  val x_sub = io.multiplicand << 1

  val p = VecInit(io.part_product.asBools())
  for (i <- 0 to 127) {
    p(i) := !(!(sel_negative & !x(i)) && !(sel_double_negative & !x_sub(i))
      & !(sel_positive & x(i)) & !(sel_double_positive & x_sub(i)))
  }

  io.part_product := Mux(sel_negative || sel_double_negative, p.asUInt() + 1.U, p.asUInt())

  override def desiredName = if (tapeout) ysyxid + "_" + getClassName else getClassName
}

object BoothTransformGen extends App {
  (new chisel3.stage.ChiselStage)
    .execute(
      Array("--target-dir", "./build/test"),
      Seq(chisel3.stage.ChiselGeneratorAnnotation(() => new BoothTransform()))
    )
}
