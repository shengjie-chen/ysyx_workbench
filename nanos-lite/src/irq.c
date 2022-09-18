#include <common.h>

static Context *do_event(Event e, Context *c) {
  switch (e.event) {
  case EVENT_YIELD : {
  for (int i = 1; i < 35; i++) {
      if (i != 2)
        printf("gpr x%d : %lx\n", i, c->gpr[i]);
    }
    printf("mcause  : %lx\n", c->mcause);
    printf("mstatus : %lx\n", c->mstatus);
    printf("mepc    : %lx\n", c->mepc);}
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
