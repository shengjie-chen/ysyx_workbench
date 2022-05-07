package circuit_exp.CharacterInput

import chisel3._
import chisel3.util.{Cat, MuxCase, MuxLookup, ShiftRegister}

class CharacterInput extends Module {
  val io = IO(new Bundle {
    val VGA_R       = Output(UInt(8.W))
    val VGA_G       = Output(UInt(8.W))
    val VGA_B       = Output(UInt(8.W))
    val VGA_CLK     = Output(Clock())
    val VGA_BLANK_N = Output(Bool())
    val VGA_HS      = Output(Bool())
    val VGA_VS      = Output(Bool())

    val ps2_clk     = Input(Bool())
    val ps2_data    = Input(Bool())
  })

  val keyboard = Module(new KeyBoardV2)
  val vga = Module(new VgaOutput)

  io.VGA_R        := vga.io.VGA_R
  io.VGA_G        := vga.io.VGA_G
  io.VGA_B        := vga.io.VGA_B
  io.VGA_CLK      := vga.io.VGA_CLK
  io.VGA_BLANK_N  := vga.io.VGA_BLANK_N
  io.VGA_HS       := vga.io.VGA_HS
  io.VGA_VS       := vga.io.VGA_VS
  keyboard.io.ps2_clk      := io.ps2_clk
  keyboard.io.ps2_data     := io.ps2_data
  vga.io.mem_write_data   := keyboard.io.data
  vga.io.mem_write_en     := keyboard.io.mem_write_en
}
