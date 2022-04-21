#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "time.h"
#include "VVgaOutput.h"
#include "verilated.h"
#include "verilated_vcd_c.h"




vluint64_t main_time = 0;
const vluint64_t sim_time = 100000;



int main(int argc, char **argv, char **env){
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	VVgaOutput *top = new VVgaOutput;
	VerilatedVcdC *tfp = new VerilatedVcdC;

	top->trace(tfp,99);
	tfp->open("./build/circuit_exp/VgaOutput/VgaOutput.vcd");

    int n = 10;
    top->reset = 1;
    while (n -- > 0) {
        top->clock = 0; top->eval();tfp->dump(main_time);
        top->clock = 1; top->eval();tfp->dump(main_time);
    }
    top->reset = 0;

	while (!Verilated::gotFinish() && main_time < sim_time) {

        top->clock = 0; top->eval();tfp->dump(main_time);
        top->clock = 1; top->eval();tfp->dump(main_time);

		main_time++;

	}
	tfp->close();
	delete top;
	delete tfp;
	exit(0);
	return 0;
}
