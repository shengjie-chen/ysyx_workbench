#include <stdio.h>
#include <nvboard.h>
#include "VXor.h"

static VXor dut;

void nvboard_bind_all_pins(VXor* top);

int main() {
		nvboard_bind_all_pins(&dut);
		nvboard_init();

		while(1){
			dut.eval();
			nvboard_update();
		}
}
