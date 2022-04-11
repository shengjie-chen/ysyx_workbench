#include <nvboard.h>
#include "VXor.h"

void nvboard_bind_all_pins(VXor* top) {
	nvboard_bind_pin( &top->io_f, BIND_RATE_SCR, BIND_DIR_OUT, 1, LD0);
	nvboard_bind_pin( &top->io_a, BIND_RATE_SCR, BIND_DIR_IN , 1, SW0);
	nvboard_bind_pin( &top->io_b, BIND_RATE_SCR, BIND_DIR_IN , 1, SW1);
}
