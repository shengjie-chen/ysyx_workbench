#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "time.h"
#include "VRVNoob.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "RVNoob.h"
#include "svdpi.h"
#include "VRVNoob__Dpi.h"

int add(int a, int b) { return a+b; }

vluint64_t main_time = 0;
const vluint64_t sim_time = 40;

int main(int argc, char **argv, char **env){
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	VRVNoob *top = new VRVNoob;
	VerilatedVcdC *tfp = new VerilatedVcdC;

	top->trace(tfp,99);
	tfp->open("./build/RVnpc/RVNoob/RVNoob.vcd");

    memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));

    int n = 10;
    top->reset = 1;
    while (n -- > 0) {
        top->clock = 0; top->eval();tfp->dump(main_time);
        main_time++;

        top->clock = 1; top->eval();tfp->dump(main_time);
        main_time++;
    }
    top->reset = 0;

	while (!Verilated::gotFinish() && main_time < sim_time) {

        top->clock = 0;
        top->io_inst = pmem_read(top->io_pc,4);
        top->eval();
        tfp->dump(main_time);
        main_time++;


        top->clock = 1;
        top->eval();
        tfp->dump(main_time);
		main_time++;

	}
	tfp->close();
	delete top;
	delete tfp;
	exit(0);
	return 0;
}
