#include "syscall.h"
#include <common.h>
// #include <stdio.h>

// extern FILE *strace_fp;

void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;
  a[1] = c->GPR2;
  a[2] = c->GPR3;
  a[3] = c->GPR4;

  // fprintf(strace_fp, "system call ! ");
  // fprintf(strace_fp, "name : %s",);

  switch (a[0]) {
  case SYS_write: {
    int i = 0;
    if (a[1] == 1 || a[1] == 2) {
      for (i = 0; i < a[3]; i++) {
        putch(*((char *)a[2] + i));
      }
    }
    c->GPRx = i;
  } break;
  case SYS_yield:
    yield();
    c->GPRx = 0;
    break;
  case SYS_exit:
    // printf("%x\n", 0);
    // asm volatile ("ebreak");
    halt(a[1]);
    break;
  default:
    panic("Unhandled syscall ID = %d", a[0]);
  }
}
