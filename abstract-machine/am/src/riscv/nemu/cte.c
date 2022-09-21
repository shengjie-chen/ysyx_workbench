#include "/home/jiexxpu/ysyx/ysyx-workbench/navy-apps/libs/libos/src/syscall.h"
#include <am.h>
#include <klib.h>
#include <riscv/riscv.h>
static Context *(*user_handler)(Event, Context *) = NULL;

Context *__am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
    case 11: {
      register intptr_t type asm("a7");
      if (type == SYS_exit)
        ev.event = EVENT_SYSCALL;
      else
        ev.event = EVENT_YIELD;
    } break;
    default:
      ev.event = EVENT_ERROR;
      break;
    }
    c = user_handler(ev, c);
    assert(c != NULL);
  }
  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context *(*handler)(Event, Context *)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0"
               :
               : "r"(__am_asm_trap));

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  return NULL;
}

void yield() {
  asm volatile("li a7, -1; ecall");
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
