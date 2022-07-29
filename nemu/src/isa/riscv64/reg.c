#include "local-include/reg.h"
#include <isa.h>

const char *regs[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
    "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

void isa_reg_display()
{
  printf("cpu.pc is " FMT_WORD "\n", cpu.pc);
  int i;
  for (i = 0; i < 32; i++) {
    printf("cpu.gpr[%d] is " FMT_WORD "\n", i, cpu.gpr[i]);
  }
}

word_t isa_reg_str2val(const char *s, bool *success)
{
  int reg_index;
  char *reg = 0;
  if (*(s + 1) > 48 && *(s + 1) < 57) {
    sscanf(s + 1, "%d", &reg_index);
    if (reg_index > 32) {
      *success = false;
      panic("reg index overflow\n");
    }
  } else {
    sscanf(s + 1, "%s", reg);
    int i;
    for (i = 0; i < 32; i++) {
      if (regs[i] == reg) {
        reg_index = i;
        goto return_flag;
      }
    }
    *success = false;
    panic("reg tag incorrect\n");
  }
return_flag:
  return cpu.gpr[reg_index];
}
