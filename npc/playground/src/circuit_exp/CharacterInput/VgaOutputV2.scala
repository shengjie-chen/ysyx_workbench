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
    val y_addr = Input(UInt(5.W))     //当前像素在第几行字符
    val x_addr_cnt = Input(UInt(4.W)) //当前像素在字符的第几列像素
    val y_addr_cnt = Input(UInt(4.W)) //当前像素在字符的第几行像素
    val vga_data = Output(UInt(24.W))
    val write_en    = Input(Bool())
    val write_data  = Input(UInt(8.W))
    val char = Input(Bool()) //当前像素在字符中
  })
  val memory = Mem(2100,UInt(8.W)) //30行70列字符
  val row_mul_lut = VecInit((0 to 29) map {i => i.U * 70.U}) //根据行数返回对应的字符次序
  val row = row_mul_lut(io.y_addr)  //当前行之前有多少字符
  val idx = row + io.x_addr // 当前扫描到字符的序号
  val ascii = memory(idx)   //当前字符的ascii
  val dot_txt = Mem(4096,UInt(12.W))
  loadMemoryFromFileInline(memory = dot_txt,
    fileName = "/home/jiexxpu/ysyx/ysyx-workbench/npc/playground/src/circuit_exp/CharacterInput/vga_font.txt")

  // 对memory更新字符
  val x_write_point = RegInit(UInt(7.W),0.U)
  val y_write_point = RegInit(UInt(5.W),0.U)
  val write_point = Wire(UInt(12.W))
  write_point := row_mul_lut(y_write_point) + x_write_point
  //  val enter_wp_add_num = VecInit((0 to 2099) map {i => 70.U - i.U % 70.U})// 当遇到回车时write_point需要增加的数值
  when(io.write_en){
    when(io.write_data === 8.U){ //backspace
      memory.write(write_point-1.U,0.U(8.W))
      when(y_write_point =/= 0.U && x_write_point === 0.U){
        y_write_point := y_write_point - 1.U
        x_write_point := 69.U
      }.elsewhen(y_write_point =/= 0.U && x_write_point =/= 0.U){
        x_write_point := x_write_point - 1.U
      }
    }.otherwise{
      memory.write(write_point,io.write_data)
      when(y_write_point === 29.U && x_write_point === 69.U){ // 30 * 70
        y_write_point := 0.U
        x_write_point := 0.U
      }.elsewhen(x_write_point === 69.U || io.write_data === 13.U){// enter
        x_write_point := 0.U
        y_write_point := y_write_point + 1.U
      }.otherwise{
        x_write_point := x_write_point + 1.U
      }
    }
  }

  // cursor
  val cursor = Wire(Bool()) // 当前像素在光标上的标志位
  cursor := (io.x_addr_cnt === 0.U | io.x_addr_cnt === 1.U) & (io.x_addr === x_write_point) & (io.y_addr === y_write_point)
  val cursor_white = RegInit(1.B)
  val (cursor_cnt, cursor_change) = Counter(cursor, 1024)
  when(cursor_change){cursor_white := ~cursor_white}

  // 输出当前像素亮度
  val char_baseaddr_lut = VecInit((0 to 255) map {i => i.U * 16.U}) // 一个字符在dot_txt中占据16行
  val char_baseaddr = char_baseaddr_lut(ascii)  // 计算当前ascii在dot_txt中第几行开始
  val piexl_addr = char_baseaddr + io.y_addr_cnt  // 当前像素在dot_txt中对应第几行
  val pixel_white = dot_txt(piexl_addr)(io.x_addr_cnt) & io.char //|| cursor//(cursor_white & cursor)

  when(pixel_white.asBool()){
    io.vga_data := 0xffffff.U
  }.otherwise{
    io.vga_data := 0x000000.U
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
  mem.io.y_addr     := ctl.io.y_addr
  mem.io.x_addr_cnt := ctl.io.x_addr_cnt
  mem.io.y_addr_cnt := ctl.io.y_addr_cnt

  // key code to ascii rom  扫描玛使用集合3（IBM 3270 PC）
  val keycode2ascii = MuxCase(0.U(8.W),Array(
    //a - z
    (io.mem_write_data === 0x1c.U) -> 97.U,
    (io.mem_write_data === 0x32.U) -> 98.U,
    (io.mem_write_data === 0x21.U) -> 99.U,
    (io.mem_write_data === 0x23.U) -> 100.U,
    (io.mem_write_data === 0x24.U) -> 101.U,
    (io.mem_write_data === 0x2b.U) -> 102.U,
    (io.mem_write_data === 0x34.U) -> 103.U,
    (io.mem_write_data === 0x33.U) -> 104.U,
    (io.mem_write_data === 0x43.U) -> 105.U,
    (io.mem_write_data === 0x3b.U) -> 106.U,
    (io.mem_write_data === 0x42.U) -> 107.U,
    (io.mem_write_data === 0x4b.U) -> 108.U,
    (io.mem_write_data === 0x3a.U) -> 109.U,
    (io.mem_write_data === 0x31.U) -> 110.U,
    (io.mem_write_data === 0x44.U) -> 111.U,
    (io.mem_write_data === 0x4d.U) -> 112.U,
    (io.mem_write_data === 0x15.U) -> 113.U,
    (io.mem_write_data === 0x2d.U) -> 114.U,
    (io.mem_write_data === 0x1b.U) -> 115.U,
    (io.mem_write_data === 0x2c.U) -> 116.U,
    (io.mem_write_data === 0x3c.U) -> 117.U,
    (io.mem_write_data === 0x2a.U) -> 118.U,
    (io.mem_write_data === 0x1d.U) -> 119.U,
    (io.mem_write_data === 0x22.U) -> 120.U,
    (io.mem_write_data === 0x35.U) -> 121.U,
    (io.mem_write_data === 0x1a.U) -> 122.U,
    // all Numeric keypad
    (io.mem_write_data === 0x70.U) -> 48.U,//0
    (io.mem_write_data === 0x69.U) -> 49.U,//1
    (io.mem_write_data === 0x72.U) -> 50.U,//2
    (io.mem_write_data === 0x7a.U) -> 51.U,//3
    (io.mem_write_data === 0x6b.U) -> 52.U,//4
    (io.mem_write_data === 0x73.U) -> 53.U,//5
    (io.mem_write_data === 0x74.U) -> 54.U,//6
    (io.mem_write_data === 0x6c.U) -> 55.U,//7
    (io.mem_write_data === 0x75.U) -> 56.U,//8
    (io.mem_write_data === 0x7d.U) -> 57.U,//9
    (io.mem_write_data === 0x7e.U) -> 42.U,//*
    (io.mem_write_data === 0x4e.U) -> 45.U,//-
    (io.mem_write_data === 0x7c.U) -> 43.U,//+
    (io.mem_write_data === 0x71.U) -> 46.U,//.
    (io.mem_write_data === 0x79.U) -> 13.U,//enter
    //
    (io.mem_write_data === 0x5a.U) -> 13.U,//enter
    (io.mem_write_data === 0x66.U) -> 8.U,//backspace
    (io.mem_write_data === 0x29.U) -> 32.U,//space
    // 0-1
    (io.mem_write_data === 0x45.U) -> 48.U,//0
    (io.mem_write_data === 0x16.U) -> 49.U,//1
    (io.mem_write_data === 0x1e.U) -> 50.U,//2
    (io.mem_write_data === 0x26.U) -> 51.U,//3
    (io.mem_write_data === 0x25.U) -> 52.U,//4
    (io.mem_write_data === 0x2e.U) -> 53.U,//5
    (io.mem_write_data === 0x36.U) -> 54.U,//6
    (io.mem_write_data === 0x3d.U) -> 55.U,//7
    (io.mem_write_data === 0x3e.U) -> 56.U,//8
    (io.mem_write_data === 0x46.U) -> 57.U,//9
    // symbol
    (io.mem_write_data === 0x0e.U) -> 96.U,//`
    (io.mem_write_data === 0x4e.U) -> 45.U,//-
    (io.mem_write_data === 0x55.U) -> 61.U,//=
    (io.mem_write_data === 0x5c.U) -> 92.U,//\
    (io.mem_write_data === 0x54.U) -> 91.U,//[
    (io.mem_write_data === 0x5b.U) -> 93.U,//]
    (io.mem_write_data === 0x4c.U) -> 59.U,//;
    (io.mem_write_data === 0x52.U) -> 39.U,//'
    (io.mem_write_data === 0x41.U) -> 44.U,//,
    (io.mem_write_data === 0x49.U) -> 46.U,//.
    (io.mem_write_data === 0x4a.U) -> 47.U,///


    //    (io.mem_write_data === 0x5a.U) -> 13.U,//enter
    //    (io.mem_write_data === 0x5a.U) -> 13.U,//enter
    //    (io.mem_write_data === 0x5a.U) -> 13.U,//enter
  ))
  
  // Mem
  val char = Wire(Bool())
  when(ctl.io.h_addr >629.U){
    char := 0.B
  }.otherwise{
    char := 1.B
  }
  mem.io.char := char
  mem.io.write_data := keycode2ascii
  mem.io.write_en := io.mem_write_en
}