package circuit_exp.VgaOutput

object VgaOutputGen extends App{
  (new chisel3.stage.ChiselStage).execute(args,
    Seq(chisel3.stage.ChiselGeneratorAnnotation(()=>new VgaOutput())))
}
