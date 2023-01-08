package RVnpc.RVNoob.Axi
import RVnpc.RVNoob.RVNoobConfig
import chisel3._
import chisel3.util._

class AxiCrossBar extends MultiIOModule with RVNoobConfig {
  val in1 = IO(new Bundle {
    val rctrl = new AxiReadCtrlIO
    val wctrl = new AxiWriteCtrlIO
    val pc    = Input(UInt(64.W))
  })
  val in2 = IO(new Bundle {
    val rctrl = new AxiReadCtrlIO
    val wctrl = new AxiWriteCtrlIO
    val pc    = Input(UInt(64.W))
  })
  val maxi = IO(new Bundle {
    val rctrl = Flipped(new AxiReadCtrlIO)
    val wctrl = Flipped(new AxiWriteCtrlIO)
    val pc    = Output(UInt(64.W))
    val busy  = Input(Bool())
  })

  val sInit :: sWait :: sNowait :: Nil = Enum(3)
  val state                            = RegInit(sInit)

  val finish = !maxi.busy && RegNext(maxi.busy)

  val in1_request = in1.rctrl.en || in1.wctrl.en
  val in2_request = in2.rctrl.en || in2.wctrl.en

  val in_ren_reg = Reg(Bool())
  val in_wen_reg = Reg(Bool())
  val choose     = Wire(Bool())
  val choose_reg = RegInit(0.B)

  when(in1_request) {
    in_ren_reg := in1.rctrl.en
    in_wen_reg := in1.wctrl.en
  }.elsewhen(in2_request) {
    in_ren_reg := in2.rctrl.en
    in_wen_reg := in2.wctrl.en
  }

  switch(state) {
    is(sInit) {
      when(in1_request && in2_request) {
        state := sWait
      }.otherwise {
        state := sNowait
      }
    }
    is(sWait) {
      when(finish && !in1_request && !in2_request) {
        state := sNowait
      }
    }
    is(sNowait) {
      when(finish) {
        when(!in1_request && !in2_request) {
          state := sInit
        }
      }.elsewhen(in1_request || in2_request) {
        state := sWait
      }
    }
  }

  choose := choose_reg
  switch(state) {
    is(sInit) {
      choose     := in2_request
      choose_reg := in2_request
    }
    is(sWait) {
      when(finish) {
        choose     := !choose_reg
        choose_reg := !choose_reg
      }
    }
  }

  when(state === sWait && finish) {
    maxi.rctrl.en := in_ren_reg
    maxi.wctrl.en := in_wen_reg
  }.otherwise {
    maxi.rctrl.en := Mux(choose, in2.rctrl.en, in1.rctrl.en)
    maxi.wctrl.en := Mux(choose, in2.wctrl.en, in1.wctrl.en)
  }

  when(choose) {
    maxi.pc               := in2.pc
    maxi.rctrl.id         := in2.rctrl.id
    maxi.rctrl.size       := in2.rctrl.size
    maxi.rctrl.addr       := in2.rctrl.addr
    maxi.rctrl.burst      := in2.rctrl.burst
    maxi.rctrl.len        := in2.rctrl.len
    maxi.wctrl.id         := in2.wctrl.id
    maxi.wctrl.size       := in2.wctrl.size
    maxi.wctrl.wbuf_ready := in2.wctrl.wbuf_ready
    maxi.wctrl.burst      := in2.wctrl.burst
    maxi.wctrl.addr       := in2.wctrl.addr
    maxi.wctrl.len        := in2.wctrl.len
    maxi.wctrl.data       := in2.wctrl.data
    maxi.wctrl.strb       := in2.wctrl.strb

    in1.rctrl.handshake  := 0.B
    in1.rctrl.data       := 0.U
    in1.wctrl.whandshake := 0.B
    in1.wctrl.bhandshake := 0.B

    in2.rctrl.handshake  := maxi.rctrl.handshake
    in2.rctrl.data       := maxi.rctrl.data
    in2.wctrl.whandshake := maxi.wctrl.whandshake
    in2.wctrl.bhandshake := maxi.wctrl.bhandshake
  }.otherwise {
    maxi.pc               := in1.pc
    maxi.rctrl.id         := in1.rctrl.id
    maxi.rctrl.size       := in1.rctrl.size
    maxi.rctrl.addr       := in1.rctrl.addr
    maxi.rctrl.burst      := in1.rctrl.burst
    maxi.rctrl.len        := in1.rctrl.len
    maxi.wctrl.id         := in1.wctrl.id
    maxi.wctrl.size       := in1.wctrl.size
    maxi.wctrl.wbuf_ready := in1.wctrl.wbuf_ready
    maxi.wctrl.burst      := in1.wctrl.burst
    maxi.wctrl.addr       := in1.wctrl.addr
    maxi.wctrl.len        := in1.wctrl.len
    maxi.wctrl.data       := in1.wctrl.data
    maxi.wctrl.strb       := in1.wctrl.strb

    in2.rctrl.handshake  := 0.B
    in2.rctrl.data       := 0.U
    in2.wctrl.whandshake := 0.B
    in2.wctrl.bhandshake := 0.B

    in1.rctrl.handshake  := maxi.rctrl.handshake
    in1.rctrl.data       := maxi.rctrl.data
    in1.wctrl.whandshake := maxi.wctrl.whandshake
    in1.wctrl.bhandshake := maxi.wctrl.bhandshake
  }

  //  maxi <> Mux(choose, in2, in1)
//  when(!maxi.busy && in_wait) {
//    maxi.rctrl.en := in_ren_reg
//    maxi.wctrl.en := in_wen_reg
//  }.otherwise {
//    maxi.rctrl.en := Mux(choose, in2.rctrl.en, in1.rctrl.en)
//    maxi.wctrl.en := Mux(choose, in2.wctrl.en, in2.wctrl.en)
//  }
//  val in_wait    = RegInit(0.B)
//  when(in1_request && in2_request) {
//    in_wait    := 1.B
//    in_ren_reg := in1.rctrl.en
//    in_wen_reg := in1.wctrl.en
//  }.elsewhen(!maxi.busy && in_wait) {
//    in_wait    := 0.B
//    in_ren_reg := 0.B
//    in_wen_reg := 0.B
//  }
//  choose := in2_request || (choose_reg && maxi.busy)
//  when(in2_request) {
//    choose_reg := 1.B
//  }.elsewhen(!maxi.busy && choose_reg) {
//    choose_reg := 0.B
//  }
}
