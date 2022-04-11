#include <nvboard.h>
#include "VMultiplexer.h"

void nvboard_bind_all_pins(VMultiplexer* top) {
	nvboard_bind_pin( &top->io_X_0, BIND_RATE_SCR, BIND_DIR_IN , 2, SW3, SW2);
	nvboard_bind_pin( &top->io_X_1, BIND_RATE_SCR, BIND_DIR_IN , 2, SW5, SW4);
	nvboard_bind_pin( &top->io_X_2, BIND_RATE_SCR, BIND_DIR_IN , 2, SW7, SW6);
	nvboard_bind_pin( &top->io_X_3, BIND_RATE_SCR, BIND_DIR_IN , 2, SW9, SW8);
	nvboard_bind_pin( &top->io_Y, BIND_RATE_SCR, BIND_DIR_IN , 2, SW1, SW0);
	nvboard_bind_pin( &top->io_F, BIND_RATE_SCR, BIND_DIR_OUT, 2, LD1, LD0);
}
