#include <cpu/cpu.h>
#include <difftest-def.h>
#include <isa.h>
#include <memory/paddr.h>

struct diff_context_t {
  word_t gpr[32];
  vaddr_t pc;
};

void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction)
{
  if (direction == DIFFTEST_TO_DUT) {
    // for (size_t i = 0; i < n; i++) {
    memcpy(buf, guest_to_host(addr), n);
  } else if (direction == DIFFTEST_TO_REF) {
    memcpy(guest_to_host(addr), buf, n);
  }
}

void difftest_regcpy(void *dut, bool direction)
{
  if (direction == DIFFTEST_TO_DUT) {
    struct diff_context_t *ctx = (struct diff_context_t *)dut;
    for (int i = 0; i < 32; i++) {
      ctx->gpr[i] = cpu.gpr[i];
      ctx->pc = cpu.pc;
    }
  } else if (direction == DIFFTEST_TO_REF) {
    struct diff_context_t *ctx = (struct diff_context_t *)dut;
    for (int i = 0; i < 32; i++) {
      cpu.gpr[i] = ctx->gpr[i];
      cpu.pc = ctx->pc;
    }
  }
}

void difftest_exec(uint64_t n)
{
  cpu_exec(n);
}

void difftest_raise_intr(word_t NO)
{
  cpu.csr[3] = NO;
  // assert(0);
}

void difftest_init(int port)
{
  /* Perform ISA dependent initialization. */
  init_isa();
}
