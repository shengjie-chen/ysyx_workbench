import Chisel.{Cat, switch}
import chisel3._
import chisel3.util.is


class AluFourBit extends RawModule {
  val io = IO(new Bundle {
    val fun = Input(UInt(3.W))
    val A = Input(SInt(4.W))
    val B = Input(SInt(4.W))
    val out = Output(SInt(4.W))
    val zero = Output(Bool())
    val overflow = Output(Bool())
    val carry = Output(Bool())
  })

  switch(io.fun) {
    is("b000".U){
      val tmp = Wire(SInt(5.W))
      tmp := io.A + io.B
      io.carry := tmp(4)
      io.out := tmp(3,0).asSInt()
      io.overflow := (io.A(3) === io.B(3) && io.A(3) =/= io.out(3))
      io.zero :=  io.out.asUInt().orR()
    }
    is("b001".U){
      val t_no_Cin = Vec(4,1.U).asUInt() ^ io.B.asUInt()
      val tmp = Wire(SInt(5.W))
      tmp := io.A + t_no_Cin.asSInt()
      io.carry := tmp(4)
      io.out := tmp(3,0)
      io.overflow := (io.A(3) === t_no_Cin(3) && io.A(3) =/= io.out(3))
      io.zero :=  ~io.out.asUInt().orR()
    }
    is("b010".U){
      io.out := ~io.A
    }
    is("b011".U){
      io.out := io.A & io.B
    }
    is("b100".U){
      io.out := io.A | io.B
    }
    is("b101".U){
      io.out := io.A ^ io.B
    }
    is("b110".U){
      io.out := (io.A < io.B)
    }
    is("b111".U){
      io.out := (io.A === io.B)
    }
  }

}