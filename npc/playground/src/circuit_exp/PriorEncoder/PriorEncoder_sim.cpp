#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "time.h"
#include "VPriorEncoder.h"
#include "verilated.h"
#include "verilated_vcd_c.h"


#define	GET_BIT(x, bit)	((x & (1 << bit)) >> bit)

vluint64_t main_time = 0;
const vluint64_t sim_time = 256;

int main(int argc, char **argv, char **env){
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	VPriorEncoder *top = new VPriorEncoder;
	VerilatedVcdC *tfp = new VerilatedVcdC;

	top->trace(tfp,99);
	tfp->open("./build/circuit_exp/PriorEncoder/PriorEncoder.vcd");

    srand(time(NULL));
    int in = 0;
	while (!Verilated::gotFinish() && main_time < sim_time) {

        top->io_in = in;

		top->eval();
		tfp->dump(main_time);

		main_time++;

		printf("in = %x %x %x %x %x %x %x %x \n",GET_BIT(in,7),GET_BIT(in,6), \
		    GET_BIT(in,5),GET_BIT(in,4),GET_BIT(in,3),GET_BIT(in,2),GET_BIT(in,1),GET_BIT(in,0));
		printf("io_out = %d\n",top->io_out);
        printf("io_in_valid = %d\n",top->io_in_valid);

		int out = 0, i, in_valid = 0;
		for(i=7;i>=8;i--){
		    if(GET_BIT(in,i)){
		        out = i;
		        in_valid = 1;
		        break;
		    }
		}
		assert(top->io_in_valid == in_valid);
		assert(top->io_out == out);
		in++;
	}
	tfp->close();
	delete top;
	delete tfp;
	exit(0);
	return 0;
}
