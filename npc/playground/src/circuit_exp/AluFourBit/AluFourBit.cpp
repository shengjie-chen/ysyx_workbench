#include <stdio.h>
#include <nvboard.h>
#include "VAluFourBit.h"

static VAluFourBit dut;

void nvboard_bind_all_pins(VAluFourBit* top);

int main() {
		nvboard_bind_all_pins(&dut);
		nvboard_init();

		while(1){
			dut.eval();
			nvboard_update();
		}
}