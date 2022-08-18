#include "RVNoob.h"
#include "VRVNoob.h"
#include "VRVNoob__Dpi.h"
#include "sdb.c"
#include "svdpi.h"
#include "time.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

// int add(int a, int b) { return a + b; }

vluint64_t main_time = 0;
const vluint64_t sim_time = 20;
NPCState npc_state;

void npc_ebreak()
{
  npc_state.state = NPC_END;
  printf("!!!!!! npc ebreak !!!!!!\n");
}

VRVNoob *top = new VRVNoob;
VerilatedVcdC *tfp = new VerilatedVcdC;

void one_clock()
{
  top->clock = 0;
  top->io_inst = pmem_read(top->io_pc, 4);
  top->eval();
  tfp->dump(main_time);
  main_time++;

  top->clock = 1;
  top->eval();
  tfp->dump(main_time);
  main_time++;
}

int main(int argc, char **argv, char **env)
{
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);

  top->trace(tfp, 99);
  tfp->open("./build/RVnpc/RVNoob/RVNoob.vcd");

  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
  img_file = *(argv + 1);
  load_img();
  printf("!!\n");
  npc_state.state = NPC_RUNNING;

  int n = 10;
  top->reset = 1;
  while (n-- > 0) {
    top->clock = 0;
    top->eval();
    tfp->dump(main_time);
    main_time++;

    top->clock = 1;
    top->eval();
    tfp->dump(main_time);
    main_time++;
  }
  top->reset = 0;

  bool sdb_en = ~strcmp(*(argv + 2), "sdb");
  // printf("%s\n",*(argv + 2));
  // printf("%d\n",sdb_en);
  if (sdb_en) {
    while (!Verilated::gotFinish() && main_time < sim_time && npc_state.state == NPC_RUNNING) {
      char *str;
      if ((str = rl_gets()) != NULL) {
        char *str_end = str + strlen(str);

        /* extract the first token as the command */
        char *cmd = strtok(str, " ");
        if (cmd == NULL) {
          continue;
        }

        /* treat the remaining string as the arguments,
         * which may need further parsing
         */
        char *args = cmd + strlen(cmd) + 1;
        if (args >= str_end) {
          args = NULL;
        }

        int i;
        for (i = 0; i < NR_CMD; i++) {
          if (strcmp(cmd, cmd_table[i].name) == 0) {
            if (cmd_table[i].handler(args) < 0) {
              printf("inst args error or quit!!");
            }
            break;
          }
        }

        if (i == NR_CMD) {
          printf("Unknown command '%s'\n", cmd);
        }
      }
    }
  } else {
    while (!Verilated::gotFinish() && main_time < sim_time && npc_state.state == NPC_RUNNING) {
      // printf("%d\n",npc_state.state);
      one_clock();
    }
  }

  tfp->close();
  delete top;
  delete tfp;
  exit(0);
  return 0;
}
