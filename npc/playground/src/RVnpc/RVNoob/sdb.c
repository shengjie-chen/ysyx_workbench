#include "macro.h"
#include "verilated.h"
#include "verilated_dpi.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <stddef.h>
#include <string>
#include "RVNoob.h"
using namespace std;
extern void one_clock();
extern NPCState npc_state;
extern vluint64_t main_time;
extern const vluint64_t sim_time;

uint64_t *cpu_gpr = NULL;
extern "C" void set_gpr_ptr(const svOpenArrayHandle r)
{
  cpu_gpr = (uint64_t *)(((VerilatedDpiOpenVar *)r)->datap());
}

// 一个输出RTL中通用寄存器的值的示例
void dump_gpr()
{
  int i;
  for (i = 0; i < 8; i++) {
    printf("gpr[%d] = 0x%lx\t\t\t", i, cpu_gpr[i]);
    printf("gpr[%d] = 0x%lx\t\t\t", i + 4, cpu_gpr[i + 4]);
    printf("gpr[%d] = 0x%lx\t\t\t", i + 8, cpu_gpr[i + 8]);
    printf("gpr[%d] = 0x%lx\n", i + 12, cpu_gpr[i + 12]);
  }
}

char line_read[20] = {0};
char *rl_gets()
{
  cin.getline(line_read, 20);

  return line_read;
}

static int cmd_c(char *args)
{
  while (!Verilated::gotFinish() && main_time < sim_time && npc_state.state == NPC_RUNNING) {
    one_clock();
  }
  return 0;
}

static int cmd_si(char *args)
{
  // printf("main_time:%d\n", main_time);
  if (args == 0) {
    one_clock();
  } else {
    int n, i;
    sscanf(args, "%d", &n);
    i = 0;
    while (!Verilated::gotFinish() && main_time < sim_time && npc_state.state == NPC_RUNNING && i < n) {
      one_clock();
      i++;
    }
  }
  return 0;
}

static int cmd_info(char *args)
{
  if (args == NULL) {
    return -1;
  }
  if (*args == 'r') {
    printf("exe info r \n");
    dump_gpr();
  } else {
    return -1;
  }
  //   else if (*args == 'w') {
  //     print_watchpoint();
  //   }
  return 0;
}

static int cmd_q(char *args)
{
  npc_state.state = NPC_QUIT;
  printf("Exit NEMU\n");
  return -1;
}

static int cmd_help(char *args);

struct {
  const char *name;
  const char *description;
  int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display informations about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},

    /* TODO: Add more commands */
    {"si", "Next step", cmd_si},
    {"info", "Print program state", cmd_info}
    // {"x", "Scan Memory", cmd_x},
    // {"p", "Calculate Expression", cmd_p},
    // {"w", "Watchpoint", cmd_w},
    // {"d", "Delete Watchpoint", cmd_d},

};

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