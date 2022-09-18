#ifndef __RISCV64_REG_H__
#define __RISCV64_REG_H__

#include <common.h>

#ifdef CONFIG_ETRACE
extern FILE *etrace_fp;
#endif

static inline int check_reg_idx(int idx) {
  IFDEF(CONFIG_RT_CHECK, assert(idx >= 0 && idx < 32));
  return idx;
}

#define gpr(idx) (cpu.gpr[check_reg_idx(idx)])

static inline const char *reg_name(int idx, int width) {
  extern const char *regs[];
  return regs[check_reg_idx(idx)];
}

#define CSRs(i) (cpu.csr[csr_idx(i)])

static inline int csr_idx(word_t addr) {
  switch (addr) {
  // 0 mstatus; 1 mtvec; 2 mepc; 3 mcause;
  case 0x300:    return 0; break;
  case 0x305:    return 1; break;
  case 0x341:    return 2; break;
  case 0x342:    return 3; break;
  default:
    panic("csr addr %lx is invalid\n",addr);
  }

#ifdef CONFIG_ETRACE
  fprintf(etrace_fp, "CSRs  ");
  switch (addr) {
  case 0:
    fprintf(etrace_fp, " %s", "mstatus:\n");
    break;
  case 1:
    fprintf(etrace_fp, " %s", "mtvec  :\n");
    break;
  case 2:
    fprintf(etrace_fp, " %s", "mepc   :\n");
    break;
  case 3:
    fprintf(etrace_fp, " %s", "mcause :\n");
    break;
  }
#endif
}

#endif
