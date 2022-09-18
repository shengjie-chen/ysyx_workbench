#include <isa.h>
#include </home/jiexxpu/ysyx/ysyx-workbench/nemu/src/isa/riscv64/local-include/reg.h>

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
  CSRs(2) = epc;
  CSRs(3) = NO;
  cpu.pc = CSRs(1);
  return 0;
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
