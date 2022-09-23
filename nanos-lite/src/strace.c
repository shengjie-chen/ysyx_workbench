// #ifndef __STRACE_H__
// #define __STRACE_H__

// #include <common.h>
// #include <memory.h>
// #endif
// #include "syscall.h"
// #include <stdio.h>

// char *strace_file = "/home/jiexxpu/ysyx/ysyx-workbench/nemu/build/nemu-strace-log.txt";
// FILE *strace_fp = NULL;

// void init_strace() {
//   strace_fp = fopen(strace_file, "w");
// }

// void write_strace(uintptr_t *a) {
//   fprintf(strace_fp, "\nsystem call ! ");
//   fprintf(strace_fp, "a0:%ld, a1:%ld, a2:%ld, a3:%ld  ", a[0], a[1], a[2], a[3]);
//   switch (a[0]) {
//   case SYS_write: {
//     fprintf(strace_fp, "name : %s", "SYS_write");

//   } break;
//   case SYS_yield:
//     fprintf(strace_fp, "name : %s", "SYS_yield");

//     break;
//   case SYS_exit:
//     fprintf(strace_fp, "name : %s", "SYS_exit");
//     break;
//   default:;
//   }
// }

// void printf_strace(uintptr_t *a) {

// }
// #endif