#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "VMultiplexer.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

vluint64_t main_time = 0;
const vluint64_t sim_time = 1024;

int main(int argc, char **argv, char **env){
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	VMultiplexer *top = new VMultiplexer;
	VerilatedVcdC *tfp = new VerilatedVcdC;

	top->trace(tfp,99);
	tfp->open("Multiplexer.vcd");

	while (!Verilated::gotFinish() && main_time < sim_time) {
		int a = rand() & 1;
		int b = rand() & 1;
		top->a = a;
		top->b = b;

		top->eval();
		tfp->dump(main_time);

		main_time++;
		printf("a = %d, b = %d, f = %d\n", a, b, top->f);
		assert(top->f == a ^ b);
	}
	tfp->close();
	delete top;
	delete tfp;
	exit(0);
	return 0;
}
