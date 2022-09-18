#include "/home/jiexxpu/ysyx/ysyx-workbench/nemu/src/isa/riscv64/local-include/reg.h"
#include <isa.h>

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */

#ifdef CONFIG_ETRACE
  fprintf(etrace_fp, " %s", "isa_raise_intr\n");
#endif
  cpu.csr[2] = epc;
  cpu.csr[3] = NO;
  return cpu.csr[1];
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
