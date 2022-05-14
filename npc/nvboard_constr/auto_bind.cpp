#include <nvboard.h>
#include "VCharacterInput.h"

void nvboard_bind_all_pins(VCharacterInput* top) {
	nvboard_bind_pin( &top->io_ps2_clk, BIND_RATE_RT , BIND_DIR_IN , 1, PS2_CLK);
	nvboard_bind_pin( &top->io_ps2_data, BIND_RATE_RT , BIND_DIR_IN , 1, PS2_DAT);
	nvboard_bind_pin( &top->io_VGA_VS, BIND_RATE_RT , BIND_DIR_OUT, 1, VGA_VSYNC);
	nvboard_bind_pin( &top->io_VGA_HS, BIND_RATE_RT , BIND_DIR_OUT, 1, VGA_HSYNC);
	nvboard_bind_pin( &top->io_VGA_BLANK_N, BIND_RATE_RT , BIND_DIR_OUT, 1, VGA_BLANK_N);
	nvboard_bind_pin( &top->io_VGA_R, BIND_RATE_RT , BIND_DIR_OUT, 8, VGA_R7, VGA_R6, VGA_R5, VGA_R4, VGA_R3, VGA_R2, VGA_R1, VGA_R0);
	nvboard_bind_pin( &top->io_VGA_G, BIND_RATE_RT , BIND_DIR_OUT, 8, VGA_G7, VGA_G6, VGA_G5, VGA_G4, VGA_G3, VGA_G2, VGA_G1, VGA_G0);
	nvboard_bind_pin( &top->io_VGA_B, BIND_RATE_RT , BIND_DIR_OUT, 8, VGA_B7, VGA_B6, VGA_B5, VGA_B4, VGA_B3, VGA_B2, VGA_B1, VGA_B0);
}
