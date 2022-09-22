#include "syscall.h"
#include <common.h>
// #include <stdio.h>

// extern FILE *strace_fp;
// extern void write_strace(uintptr_t *a);

void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;
  a[1] = c->GPR2;
  a[2] = c->GPR3;
  a[3] = c->GPR4;

  // write_strace(a);
  printf("\n[  log  ]system call ! ");
  printf("a0:%ld, a1:%ld, a2:%lx, a3:%ld  ", a[0], a[1], a[2], a[3]);

  switch (a[0]) {
  case SYS_brk: {
    printf("name : %s", "SYS_brk\n");
    malloc(a[1]);
    c->GPRx = 0;
  } break;
  case SYS_write: {
    printf("name : %s", "SYS_write\n");
    int i = 0;
    if (a[1] == 1 || a[1] == 2) {
      for (i = 0; i < a[3]; i++) {
        putch(*((char *)a[2] + i));
      }
    }
    c->GPRx = i;
  } break;
  case SYS_yield:
    printf("name : %s", "SYS_yield\n");

    yield();
    c->GPRx = 0;
    break;
  case SYS_exit:
    printf("name : %s", "SYS_exit\n");

    // printf("%x\n", 0);
    // asm volatile ("ebreak");
    halt(a[1]);
    break;
  default:
    panic("Unhandled syscall ID = %d", a[0]);
  }
}
