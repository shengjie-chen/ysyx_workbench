#include "syscall.h"
#include "fs.h"
#include <common.h>
// #include <stdio.h>
// #ifdef CONFIG_STRACE
// extern void write_strace(uintptr_t *a);
// #endif

// extern FILE *strace_fp;
// extern void write_strace(uintptr_t *a);
#define __IGNORE(...)
#define CHOOSE2nd(a, b, ...) b
#define MUX_WITH_COMMA(contain_comma, a, b) CHOOSE2nd(contain_comma a, b)
#define MUX_MACRO_PROPERTY(p, macro, a, b) MUX_WITH_COMMA(concat(p, macro), a, b)
#define MUXDEF(macro, X, Y)  MUX_MACRO_PROPERTY(__P_DEF_, macro, X, Y)
#define IFDEF(macro, ...) MUXDEF(macro, __KEEP, __IGNORE)(__VA_ARGS__)

#define CONFIG_STRACE

void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;
  a[1] = c->GPR2;
  a[2] = c->GPR3;
  a[3] = c->GPR4;

#ifdef CONFIG_STRACE
  // write_strace(a);
  printf("\n[  log  ]system call ! ");
  printf("a0:%ld, a1:%ld, a2:%lx, a3:%ld  ", a[0], a[1], a[2], a[3]);
#endif
  switch (a[0]) {
  case SYS_exit:
    IFDEF(CONFIG_STRACE, printf("name : %s", "SYS_exit\n"));
    halt(a[1]);
    break;
  case SYS_yield:
    IFDEF(CONFIG_STRACE, printf("name : %s", "SYS_yield\n"));
    yield();
    c->GPRx = 0;
    break;
  case SYS_open: {
    IFDEF(CONFIG_STRACE, printf("name : %s", "SYS_open\n"));
    c->GPRx = fs_open((char *)a[1], 0, 0);
  } break;

  case SYS_read: {
    c->GPRx = fs_read(a[1], (void *)a[2], a[3]);
    IFDEF(CONFIG_STRACE, printf("name : %s, data num: %d\n", "SYS_read", c->GPRx));
  } break;
  case SYS_write: {
    IFDEF(CONFIG_STRACE, printf("name : %s", "SYS_write\n"));
    // int i = 0;
    // if (a[1] == 1 || a[1] == 2) {
    //   for (i = 0; i < a[3]; i++) {
    //     putch(*((char *)a[2] + i));
    //   }
    // }
    // c->GPRx = i;
    c->GPRx = fs_write(a[1], (void *)a[2], a[3]);
  } break;

  case SYS_close: {
    IFDEF(CONFIG_STRACE, printf("name : %s", "SYS_close\n"));
    c->GPRx = fs_close(a[1]);
  } break;
  case SYS_lseek: {
    c->GPRx = fs_lseek(a[1], a[2], a[3]);
    IFDEF(CONFIG_STRACE, printf("name : %s, offset : 0x%x\n", "SYS_lseek", c->GPRx));
  } break;
  case SYS_brk: {
    IFDEF(CONFIG_STRACE, printf("name : %s, malloc : %d\n", "SYS_brk", a[1]));
    malloc(a[1]);
    c->GPRx = 0;
  } break;
  case SYS_gettimeofday: {
    long int ms = io_read(AM_TIMER_UPTIME).us / 1000;
    *(long int *)a[1] = ms / 1000;
    *((long int *)a[1] + 1) = ms % 1000;
    // printf("name : %s, get time : %lds %ldms\n", "SYS_gettimeofday", *(long int *)a[1], *((long int *)a[1] + 1));
    IFDEF(CONFIG_STRACE, printf("name : %s, get time : %lds %ldms\n", "SYS_gettimeofday", *(long int *)a[1], *((long int *)a[1] + 1)));
    c->GPRx = 0;
  } break;

  default:
    panic("Unhandled syscall ID = %d", a[0]);
  }
}
