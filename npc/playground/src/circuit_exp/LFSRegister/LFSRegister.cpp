#include <stdio.h>
#include <nvboard.h>
#include "VLFSRegister.h"

static VLFSRegister dut;

void nvboard_bind_all_pins(VLFSRegister* top);

int main() {
		nvboard_bind_all_pins(&dut);
		nvboard_init();

		while(1){
			dut.eval();
			nvboard_update();
		}
}