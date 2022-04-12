#include <nvboard.h>
#include "VAluFourBit.h"

void nvboard_bind_all_pins(VAluFourBit* top) {
	nvboard_bind_pin( &top->io_fun, BIND_RATE_SCR, BIND_DIR_IN , 3, BTNL, BTNC, BTNR);
	nvboard_bind_pin( &top->io_A, BIND_RATE_SCR, BIND_DIR_IN , 4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->io_B, BIND_RATE_SCR, BIND_DIR_IN , 4, SW7, SW6, SW5, SW4);
	nvboard_bind_pin( &top->io_out, BIND_RATE_SCR, BIND_DIR_OUT, 3, LD2, LD1, LD0);
	nvboard_bind_pin( &top->io_zero, BIND_RATE_SCR, BIND_DIR_OUT, 1, LD3);
	nvboard_bind_pin( &top->io_overflow, BIND_RATE_SCR, BIND_DIR_OUT, 1, LD4);
	nvboard_bind_pin( &top->io_carry, BIND_RATE_SCR, BIND_DIR_OUT, 1, LD5);
}
