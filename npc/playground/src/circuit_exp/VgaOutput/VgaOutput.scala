package circuit_exp.VgaOutput

import chisel3._
import chisel3.util._
import chisel3.util.experimental.loadMemoryFromFileInline

class clkgen extends BlackBox(Map("clk_freq" -> 25000000)) {
  val io = IO(new Bundle{
    val clkin = Input(Clock())
    val rst = Input(Bool())
    val clken = Input(Bool())
    val clkout = Output(Clock())
  })
}

class vga_ctl extends Module{
  val io = IO(new Bundle {
    val pclk = Input(Clock())
    val reset = Input(Bool())
    val vga_data = Input(UInt(24.W))
    val h_addr = Output(UInt(10.W))
    val v_addr = Output(UInt(10.W))
    val hsync = Output(Bool())
    val vsync = Output(Bool())
    val valid = Output(Bool())
    val vga_r = Output(UInt(8.W))
    val vga_g = Output(UInt(8.W))
    val vga_b = Output(UInt(8.W))
  })
}
class Vmem extends Module {
  val io = IO(new Bundle {
    val h_addr = Input(UInt(10.W))
    val v_addr = Input(UInt(9.W))
    val vga_data = Output(UInt(24.W))
  })
  val memory = Mem(524288,UInt(24.W))
  loadMemoryFromFileInline(memory = memory,
    fileName = "/home/jiexxpu/ysyx/ysyx-workbench/npc/playground/src/circuit_exp/VgaOutput/picture.hex")

  io.vga_data := memory(Cat(io.h_addr,io.v_addr))
  
}

class VgaOutput extends Module {
  val io = IO(new Bundle {
    val VGA_R = Output(UInt(8.W))
    val VGA_G = Output(UInt(8.W))
    val VGA_B = Output(UInt(8.W))
    val VGA_CLK = Output(Clock())
    val VGA_SYNC_N = Output(Bool())
    val VGA_BLANK_N = Output(Bool())
    val VGA_HS = Output(Bool())
    val VGA_VS = Output(Bool())
  })
  val clk_gen = Module(new clkgen)
  val ctl = Module(new vga_ctl)
  val mem = Module(new Vmem)
// clk_gen
  clk_gen.io.clken := 1.B
  clk_gen.io.clkin := clock
  io.VGA_CLK := clk_gen.io.clkout
  clk_gen.io.rst := reset

// ctl
  ctl.io.pclk := clk_gen.io.clkout
  ctl.io.reset := reset
  io.VGA_HS := ctl.io.hsync
  io.VGA_VS := ctl.io.vsync

  ctl.io.vga_data := mem.io.vga_data
  ctl.io.h_addr := mem.io.h_addr
  ctl.io.v_addr := mem.io.v_addr


  io.VGA_BLANK_N := ctl.io.valid
  io.VGA_SYNC_N := 0.B

  io.VGA_R := ctl.io.vga_r
  io.VGA_G := ctl.io.vga_g
  io.VGA_B := ctl.io.vga_b


}