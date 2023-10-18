#include "syscall.h"
#include "fs.h"
#include <common.h>
#include <proc.h>

// ctrl + H : uprintf -> //uprintf
extern void naive_uload(PCB *pcb, const char *filename);

void do_syscall(Context *c) {
  uintptr_t a[4];
  a[0] = c->GPR1;
  a[1] = c->GPR2;
  a[2] = c->GPR3;
  a[3] = c->GPR4;

  //printf("\n[  log  ]system call ! ");

  switch (a[0]) {
  case SYS_exit:
    //printf("sys_id:%ld, status:%ld, a2:%ld, a3:%ld  ", a[0], a[1], a[2], a[3]);
    //printf("name : %s", "SYS_exit\n");
    // halt(a[1]);
    naive_uload(NULL,"/bin/nterm");
    break;
  case SYS_yield:
    //printf("sys_id:%ld, a1:%ld, a2:%ld, a3:%ld  ", a[0], a[1], a[2], a[3]);
    //printf("name : %s", "SYS_yield\n");
    yield();
    c->GPRx = 0;
    break;
  case SYS_open: {
    //printf("sys_id:%ld, path:%lx, a2:%ld, a3:%ld  ", a[0], a[1], a[2], a[3]);
    c->GPRx = fs_open((char *)a[1], 0, 0);
    printf("name : %s, return fd : %d\n", "SYS_open", c->GPRx);
  } break;

  case SYS_read: {
    // printf("sys_id:%ld, fd:%ld, buf:%lx, count:%ld  ", a[0], a[1], a[2], a[3]);
    c->GPRx = fs_read(a[1], (void *)a[2], a[3]);
    printf("name : %s, transfor data num: %d\n", "SYS_read", c->GPRx);
  } break;
  case SYS_write: {
    //printf("sys_id:%ld, fd:%ld, buf:%lx, count:%ld  ", a[0], a[1], a[2], a[3]);
    //printf("name : %s, wirte usage:\n", "SYS_write");
    c->GPRx = fs_write(a[1], (void *)a[2], a[3]);
  } break;

  case SYS_close: {
    //printf("sys_id:%ld, fd:%ld, a2:%ld, a3:%ld  ", a[0], a[1], a[2], a[3]);
    printf("name : %s, id: %ld", "SYS_close\n", a[1]);
    c->GPRx = fs_close(a[1]);
  } break;
  case SYS_lseek: {
    //printf("sys_id:%ld, fd:%ld, offset:%ld, type:%ld  ", a[0], a[1], a[2], a[3]);
    c->GPRx = fs_lseek(a[1], a[2], a[3]);
    //printf("name : %s, offset : 0x%x\n", "SYS_lseek", c->GPRx);
  } break;
  case SYS_brk: {
    //printf("sys_id:%ld, increment:%ld, a2:%ld, a3:%ld  ", a[0], a[1], a[2], a[3]);
    //printf("name : %s, malloc : %d\n", "SYS_brk", a[1]);
    malloc(a[1]);
    c->GPRx = 0;
  } break;
  case SYS_gettimeofday: {
    long int us = io_read(AM_TIMER_UPTIME).us;
    *(long int *)a[1] = us / 1000000;
    *((long int *)a[1] + 1) = us % 1000000;
    //printf("name : %s, get time : %lds %ldus\n", "SYS_gettimeofday", *(long int *)a[1], *((long int *)a[1] + 1));
    c->GPRx = 0;
  } break;
  case SYS_execve: {
    naive_uload(NULL, (const char *)a[1]);
    c->GPRx = -1;
  }

  default:
    panic("Unhandled syscall ID = %d", a[0]);
  }
}
