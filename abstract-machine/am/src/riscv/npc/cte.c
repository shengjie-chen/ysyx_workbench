#include <am.h>
#include <klib.h>
#include <riscv/riscv.h>

static Context *(*user_handler)(Event, Context *) = NULL;

Context *__am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
    case 0x8000000000000007: 
      ev.event = EVENT_IRQ_TIMER;
      break;
    case 11: {
      register intptr_t type asm("a7"); // or use c->GPR1
      if (type == -1) {
        c->mepc += 4;
        ev.event = EVENT_YIELD;
      } else {
        c->mepc += 4;
        ev.event = EVENT_SYSCALL;
      }
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
  if(enable){
    asm volatile("csrsi mstatus ,8"); // set mstatus[3] MIE
    asm volatile("csrrs x0, mie, %[mask]":: [mask] "r" (1 << 7):); // set mie[7] MTIE
  }else{
    asm volatile("csrci mstatus ,8");
    asm volatile("csrrc x0, mie ,%[mask]":: [mask] "r" (1 << 7):);
  }
}
