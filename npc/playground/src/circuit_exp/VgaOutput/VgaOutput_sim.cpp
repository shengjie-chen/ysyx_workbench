#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "time.h"
#include "VVgaOutput.h"
#include "verilated.h"
#include "verilated_vcd_c.h"


#define	GET_BIT(x, bit)	((x & (1 << bit)) >> bit)

vluint64_t main_time = 0;
const vluint64_t sim_time = 256;

static void single_cycle() {
  dut.clock = 0; dut.eval();tfp->dump(main_time);
  dut.clock = 1; dut.eval();tfp->dump(main_time);
}

static void reset(int n) {
  dut.reset = 1;
  while (n -- > 0) single_cycle();
  dut.reset = 0;
}

int main(int argc, char **argv, char **env){
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	VVgaOutput *top = new VVgaOutput;
	VerilatedVcdC *tfp = new VerilatedVcdC;

	top->trace(tfp,99);
	tfp->open("./build/circuit_exp/VgaOutput/VgaOutput.vcd");

    reset(10);

	while (!Verilated::gotFinish() && main_time < sim_time) {

        single_cycle();

		main_time++;

	}
	tfp->close();
	delete top;
	delete tfp;
	exit(0);
	return 0;
}
