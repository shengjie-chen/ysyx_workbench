package circuit_exp.PriorEncoder

object PriorEncoderGen extends App{
  (new chisel3.stage.ChiselStage).execute(args,
    Seq(chisel3.stage.ChiselGeneratorAnnotation(()=>new PriorEncoder())))
}
