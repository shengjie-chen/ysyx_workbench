#include "../local-include/reg.h"
#include <cpu/difftest.h>
#include <isa.h>

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc)
{
  for (int i = 0; i < 32; i++) {
    if (gpr(i) != ref_r->gpr[i]) {
      printf("difftest fail! gpr[%d] is different!\n", i);
      printf("ref.gpr[%d] is " FMT_WORD "\n", i, ref_r->gpr[i]);
      printf("cpu.gpr[%d] is " FMT_WORD "\n", i, cpu.gpr[i]);
      printf("------------------------\n");
      return false;
    }
  }
  if (cpu.pc != ref_r->pc) {
    printf("difftest fail! pc is different!\n");
    printf("ref.pc is " FMT_WORD "\n", ref_r->pc);
    printf("cpu.pc is " FMT_WORD "\n", cpu.pc);
    printf("------------------------\n");
    return false;
  }
  return true;
}

void isa_difftest_attach()
{
}
