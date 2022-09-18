#include "/home/jiexxpu/ysyx/ysyx-workbench/nemu/src/isa/riscv64/local-include/reg.h"
#include <isa.h>

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */

#ifdef CONFIG_ETRACE
  fprintf(etrace_fp, "*%s", "isa_raise_intr:\n");
  fprintf(etrace_fp, "   mepc   write %lx\n", epc);
  fprintf(etrace_fp, "   mcause write %lx\n", NO);
  fprintf(etrace_fp, "   mtvec  read  %lx to dnpc\n", cpu.csr[1]);
#endif
  cpu.csr[2] = epc;
  cpu.csr[3] = NO;
  return cpu.csr[1];
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
