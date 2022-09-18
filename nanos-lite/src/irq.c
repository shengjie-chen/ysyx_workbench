#include <common.h>

static Context *do_event(Event e, Context *c) {
  switch (e.event) {
  case EVENT_YIELD : {
  for (int i = 1; i < 35; i++) {
      if (i != 2)
        printf("gpr x%d : %d\n", i, c->gpr[i]);
    }
    printf("mcause  : %d\n", c->mcause);
    printf("mstatus : %d\n", c->mstatus);
    printf("mepc    : %d\n", c->mepc);}
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
