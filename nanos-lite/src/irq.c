#include <common.h>

static Context *do_event(Event e, Context *c) {
  switch (e.event) {
  case EVENT_YIELD : {
  for (int i = 1; i < 35; i++) {
      if (i != 2)
        printf("gpr x%d : %lx", i, c->gpr[i]);
    }
    printf("mcause  : %lx", c->mcause);
    printf("mstatus : %lx", c->mstatus);
    printf("mepc    : %lx", c->mepc);}
    break;
  default:
    panic("Unhandled event ID = %d", e.event);
  }

  return c;
}

void init_irq(void) {
  Log("Initializing interrupt/exception handler...");
  cte_init(do_event);
}
