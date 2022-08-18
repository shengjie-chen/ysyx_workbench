#include "macro.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <stddef.h>
extern void one_clock();
#define NR_CMD ARRLEN(cmd_table)

char *rl_gets()
{
  char *line_read = NULL;

  line_read = readline("(npc) ");

  return line_read;
}

static int cmd_help(char *args)
{
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  } else {
    for (i = 0; i < NR_CMD; i++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

static int cmd_c(char *args)
{
  while (!Verilated::gotFinish() && main_time < sim_time) {
    one_clock();
  }
  return 0;
}

static int cmd_si(char *args)
{
  if (args == 0) {
    one_clock();
  } else {
    int n, i;
    sscanf(args, "%d", &n);
    i = 0;
    while (!Verilated::gotFinish() && main_time < sim_time && i < n) {
      one_clock();
    }
  }
  return 0;
}

static int cmd_info(char *args)
{
  if (*args == 'r') {
    isa_reg_display();
  }
  //   else if (*args == 'w') {
  //     print_watchpoint();
  //   }
  return 0;
}

struct {
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display informations about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},

    /* TODO: Add more commands */
    {"si", "Next step", cmd_si},
    {"info", "Print program state", cmd_info},
    {"x", "Scan Memory", cmd_x},
    {"p", "Calculate Expression", cmd_p},
    {"w", "Watchpoint", cmd_w},
    {"d", "Delete Watchpoint", cmd_d},

};
