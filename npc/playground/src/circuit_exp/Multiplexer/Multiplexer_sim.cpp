#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "time.h"
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

    srand(time(NULL));
	while (!Verilated::gotFinish() && main_time < sim_time) {

		int sel = rand() % 4;
		int x0 = rand() % 4;
		int x1 = rand() % 4;
		int x2 = rand() % 4;
		int x3 = rand() % 4;
		int f;

		top->io_Y = sel;
		top->io_X_0 = x0;
		top->io_X_1 = x1;
		top->io_X_2 = x2;
		top->io_X_3 = x3;

		top->eval();
		tfp->dump(main_time);

		main_time++;
		printf("sel = %d\nx0 = %d, x1 = %d, x2 = %d, x3 = %d\nf = %d\n", sel, x0, x1, x2, x3, top->io_F);
		switch(sel){
		case 0:
		    f = x0;break;
		case 1:
		    f = x1;break;
		case 2:
            f = x2;break;
        case 3:
            f = x3;break;
		}
		assert(top->io_F == f);
	}
	tfp->close();
	delete top;
	delete tfp;
	exit(0);
	return 0;
}
