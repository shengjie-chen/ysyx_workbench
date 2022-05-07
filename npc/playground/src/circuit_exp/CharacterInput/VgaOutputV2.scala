package circuit_exp.CharacterInput

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

class vga_ctrl_v2 extends BlackBox{
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
    val x_addr = Output(UInt(7.W))     //当前像素在画面的第几列字符，需要用h_addr卡一下，因为630-640是多余的像素
    val y_addr = Output(UInt(5.W))     //当前像素在画面的第几行字符
    val x_addr_cnt = Output(UInt(4.W)) //当前像素在字符的第几列像素
    val y_addr_cnt = Output(UInt(4.W)) //当前像素在字符的第几行像素

  })
}

class Vmem extends Module {
  val io = IO(new Bundle {
    val x_addr = Input(UInt(7.W))
    val y_addr = Input(UInt(5.W))
    val x_addr_cnt = Input(UInt(4.W)) //当前像素在字符的第几列像素
    val y_addr_cnt = Input(UInt(4.W)) //当前像素在字符的第几行像素
    val vga_data = Output(UInt(24.W))
    val write_en    = Input(Bool())
    val write_data  = Input(UInt(8.W))
    val char = Input(Bool()) //当前像素在字符中
  })
  val memory = Mem(2100,UInt(8.W)) //30行70列
  val row_mul_lut = VecInit((0 to 29) map {i => i.U * 70.U}) //根据行数返回对应的字符次序
  val row = row_mul_lut(io.y_addr)
  val idx = row + io.x_addr
  val ascii = memory(idx)
  val dot_txt = Mem(4096,UInt(12.W))
  loadMemoryFromFileInline(memory = dot_txt,
    fileName = "/home/jiexxpu/ysyx/ysyx-workbench/npc/playground/src/circuit_exp/CharacterInput/vga_font.txt")

  val char_baseaddr_lut = VecInit((0 to 255) map {i => i.U * 16.U})
  val char_baseaddr = char_baseaddr_lut(ascii)
  val piexl_addr = char_baseaddr + io.y_addr_cnt
  val pixel_white = dot_txt(piexl_addr)(io.x_addr_cnt) & io.char

  when(pixel_white.asBool()){
    io.vga_data := 0xffffff.U
  }.otherwise{
    io.vga_data := 0x000000.U
  }

  // 对memory更新字符
  val write_point = RegInit(UInt(12.W),0.U)
  when(io.write_en){
    memory.write(write_point,io.write_data)
    when(write_point === 2099.U){
      write_point := 0.U
    }.otherwise{
      write_point := write_point + 1.U
    }
  }
}


class VgaOutput extends Module {
  val io = IO(new Bundle {
    val VGA_R = Output(UInt(8.W))
    val VGA_G = Output(UInt(8.W))
    val VGA_B = Output(UInt(8.W))
    val VGA_CLK = Output(Clock())
//    val VGA_SYNC_N = Output(Bool())
    val VGA_BLANK_N = Output(Bool())
    val VGA_HS = Output(Bool())
    val VGA_VS = Output(Bool())

    val mem_write_en    = Input(Bool())
    val mem_write_data  = Input(UInt(8.W))

  })
//  val clk_gen = Module(new clkgen)
  val ctl = Module(new vga_ctrl_v2)
  val mem = Module(new Vmem)

  // clk_gen
//  clk_gen.io.clken := 1.B
//  clk_gen.io.clkin := clock
//  io.VGA_CLK := clk_gen.io.clkout
//  clk_gen.io.rst := reset

  io.VGA_CLK := clock

  // ctl
  ctl.io.pclk       := clock //clk_gen.io.clkout
  ctl.io.reset      := reset.asBool()
  ctl.io.vga_data   := mem.io.vga_data
  io.VGA_HS         := ctl.io.hsync
  io.VGA_VS         := ctl.io.vsync
  io.VGA_BLANK_N    := ctl.io.valid
  io.VGA_R          := ctl.io.vga_r
  io.VGA_G          := ctl.io.vga_g
  io.VGA_B          := ctl.io.vga_b
  mem.io.x_addr     := ctl.io.x_addr
  ctl.io.y_addr     := mem.io.y_addr
  ctl.io.x_addr_cnt := mem.io.x_addr_cnt
  ctl.io.y_addr_cnt := mem.io.y_addr_cnt

  // Mem
  val char = Wire(Bool())
  when(ctl.io.h_addr >629.U){
    char := 0.B
  }.otherwise{
    char := 1.B
  }
  mem.io.char := char
  mem.io.write_data := io.mem_write_data
  mem.io.write_en := io.mem_write_en
}