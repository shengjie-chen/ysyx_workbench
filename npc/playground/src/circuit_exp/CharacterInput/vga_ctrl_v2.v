module vga_ctrl_v2(
    input           pclk,     //25MHz时钟
    input           reset,    //置位
    input  [23:0]   vga_data, //上层模块提供的VGA颜色数据
    output [9:0]    h_addr,   //提供给上层模块的当前扫描像素点坐标
    output [9:0]    v_addr,
    output          hsync,    //行同步和列同步信号
    output          vsync,
    output          valid,    //消隐信号
    output [7:0]    vga_r,    //红绿蓝颜色信号
    output [7:0]    vga_g,
    output [7:0]    vga_b,
    output [6:0]    x_addr,    //当前像素在画面的第几列字符，需要用h_addr卡一下，因为630-640是多余的像素
    output [4:0]    y_addr,    //当前像素在画面的第几行字符
    output [3:0]    x_addr_cnt,//当前像素在字符的第几列像素
    output [3:0]    y_addr_cnt //当前像素在字符的第几行像素
    );

    //640x480分辨率下的VGA参数设置
    parameter    h_frontporch = 96;
    parameter    h_active = 144;
    parameter    h_backporch = 784;
    parameter    h_total = 800;

    parameter    v_frontporch = 2;
    parameter    v_active = 35;
    parameter    v_backporch = 515;
    parameter    v_total = 525;

    //像素计数值
    reg [9:0]    x_cnt;
    reg [9:0]    y_cnt;
    reg [6:0]    x_addr;
    reg [4:0]    y_addr;
    reg [3:0]    x_addr_cnt;
    reg [3:0]    y_addr_cnt;
    wire         h_valid;
    wire         v_valid;

    always @(posedge reset or posedge pclk) //行像素计数
      if (reset == 1'b1)
        x_cnt <= 1;
      else
      begin
        if (x_cnt == h_total)
            x_cnt <= 1;
        else
            x_cnt <= x_cnt + 10'd1;
      end

    always @(posedge pclk)  //列像素计数
      if (reset == 1'b1)
        y_cnt <= 1;
      else
      begin
        if (y_cnt == v_total & x_cnt == h_total)
            y_cnt <= 1;
        else if (x_cnt == h_total)
            y_cnt <= y_cnt + 10'd1;
      end


    always @(posedge reset or posedge pclk) //行字符坐标&计数
        if (reset == 1'b1)begin
            x_addr_cnt <= 0;
            x_addr <= 0;
        end
        else begin
            if((x_cnt >= h_active) & (x_cnt < h_backporch)) begin
                if (x_addr_cnt == 8) begin
                    x_addr_cnt <= 0;
                    x_addr <= x_addr + 7'd1;
                end
                else
                    x_addr_cnt <= x_addr_cnt + 4'd1;
            end
            else if(x_cnt = h_backporch) begin
                x_addr <= 0;
                x_addr_cnt <= 0;
            end
        end

    always @(posedge reset or posedge pclk) //列字符坐标&计数
        if (reset == 1'b1)begin
            y_addr_cnt <= 0;
            y_addr <= 0;
        end
        else begin
            if((y_cnt >= v_active) & (y_cnt < v_backporch)) begin
                if (y_addr_cnt == 15) begin
                    y_addr_cnt <= 0;
                    y_addr <= y_addr + 7'd1;
                end
                else
                    y_addr_cnt <= y_addr_cnt + 4'd1;
            end
            else if(y_cnt = v_backporch) begin
                y_addr <= 0;
                y_addr_cnt <= 0;
            end
        end

  //生成同步信号
  assign hsync = (x_cnt > h_frontporch);
  assign vsync = (y_cnt > v_frontporch);
  //生成消隐信号
  assign h_valid = (x_cnt > h_active) & (x_cnt <= h_backporch);
  assign v_valid = (y_cnt > v_active) & (y_cnt <= v_backporch);
  assign valid = h_valid & v_valid;
  //计算当前有效像素坐标
  assign h_addr = h_valid ? (x_cnt - 10'd145) : {10{1'b0}};
  assign v_addr = v_valid ? (y_cnt - 10'd36) : {10{1'b0}};
  //设置输出的颜色值
  assign vga_r = vga_data[23:16];
  assign vga_g = vga_data[15:8];
  assign vga_b = vga_data[7:0];
endmodule