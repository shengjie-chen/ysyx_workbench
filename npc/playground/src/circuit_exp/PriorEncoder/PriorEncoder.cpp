#include <stdio.h>
#include <nvboard.h>
#include "VPriorEncoder.h"

static VPriorEncoder dut;

void nvboard_bind_all_pins(VPriorEncoder* top);

int main() {
		nvboard_bind_all_pins(&dut);
		nvboard_init();

		while(1){
			dut.eval();
			nvboard_update();
		}
}