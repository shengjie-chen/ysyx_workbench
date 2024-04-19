#include <am.h>
#include <klib-macros.h>
#include "stdio.h"

#define STACK_SIZE (4096 * 8)
typedef union {
  uint8_t stack[STACK_SIZE];
  struct { Context *cp; };
} PCB;
static PCB pcb[2], pcb_boot, *current = &pcb_boot;

static void f(void *arg) {
  while (1) {
    putch("?AB"[(uintptr_t)arg > 2 ? 0 : (uintptr_t)arg]);
    for (int volatile i = 0; i < 100000; i++) ;
    yield();
  }
}

static Context *schedule(Event ev, Context *prev) {
    switch (ev.event) {
    case EVENT_SYSCALL:
        printf("syscall!!\n");
        break;
    case EVENT_YIELD:
        // printf("yield!!\n");
        current->cp = prev;
        current = (current == &pcb[0] ? &pcb[1] : &pcb[0]);
        return current->cp;
        break;
    default:
        printf("Unhandled event ID = %d", ev.event);
    }
    return prev;
}

int main() {
  cte_init(schedule);
  pcb[0].cp = kcontext((Area) { pcb[0].stack, &pcb[0] + 1 }, f, (void *)1L);
  pcb[1].cp = kcontext((Area) { pcb[1].stack, &pcb[1] + 1 }, f, (void *)2L);
  yield();
  panic("Should not reach here!");
}
