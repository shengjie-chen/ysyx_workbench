#include <stdio.h>
#include <nvboard.h>
#include "VMultiplexer.h"

static VMultiplexer dut;

void nvboard_bind_all_pins(VMultiplexer* top);

int main() {
		nvboard_bind_all_pins(&dut);
		nvboard_init();

		while(1){
			dut.eval();
			nvboard_update();
		}
}
