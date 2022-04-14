package circuit_exp.Multiplexer

object MultiplexerGen extends App{
        (new chisel3.stage.ChiselStage).execute(args,
        Seq(chisel3.stage.ChiselGeneratorAnnotation(()=>new Multiplexer())))
        }
