#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "time.h"
#include "VPriorEncoder.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

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
	while (!Verilated::gotFinish() && main_time < sim_time) {

		int in[8];
        int i;
        for(i=0;i<8:i++){
            in[i] = rand() % 2
            top.io_in(0) = in[i]
        }

		top->eval();
		tfp->dump(main_time);

		main_time++;

		printf("in = ");
        for(i=0;i<8;i++){
            printf("%d",in[7-i]);
        }
		printf("\n");
		printf("io_out = %d\n",top.io_out);
        printf("io_in_valid = %d\n",top.io_in_valid);

		int out,in_valid = 0;
		for(i=0;i<8;i++){
		    if(in[7-i]){
		        out = 7-i;
		        in_valid = 1;
		        break;
		    }
		}
		assert(top->io_in_valid == in_valid);
		assert(top->io_out == out);
	}
	tfp->close();
	delete top;
	delete tfp;
	exit(0);
	return 0;
}
