#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "time.h"
#include "VRVNoob.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "RVNoob.h"

vluint64_t main_time = 0;
const vluint64_t sim_time = 20;

static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
static const uint32_t img [] = {
  0xff010113,          	// addi	sp,sp,-16
  0xfa010113,          	// addi	sp,sp,-96
  0x004c8c93,          	// addi	s9,s9,4
  0x00840413,          	// addi	s0,s0,8
  0x004a0a13,          	// addi	s4,s4,4
  0xff010113,          	// addi	sp,sp,-16
  0xfa010113,          	// addi	sp,sp,-96
  0x004c8c93,          	// addi	s9,s9,4
  0x00840413,          	// addi	s0,s0,8
  0x004a0a13,          	// addi	s4,s4,4
//  0x0102b503,  // ld  a0,16(t0)
//  0x00100073,  // ebreak (used as nemu_trap)
//  0xdeadbeef,  // some data
};

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }

static inline word_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    IFDEF(CONFIG_ISA64, case 8: return *(uint64_t *)addr);
    default: MUXDEF(CONFIG_RT_CHECK, assert(0), return 0);
  }
}

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

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
        top->clock = 1; top->eval();tfp->dump(main_time);
    }
    top->reset = 0;

	while (!Verilated::gotFinish() && main_time < sim_time) {

        top->clock = 0;
        top->io_inst = pmem_read(top->io_pc,4);
        top->eval();
        tfp->dump(main_time);

        top->clock = 1;
        top->io_inst = pmem_read(top->io_pc,4);
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
