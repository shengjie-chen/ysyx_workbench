#include "RVNoob.h"
#include "VRVNoob.h"
#include "VRVNoob__Dpi.h"
#include "conf.h"
//#include "disasm.cc"
#include "sdb.c"
#include "svdpi.h"
#include "time.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

// int add(int a, int b) { return a + b; }

vluint64_t main_time = 0;
const vluint64_t sim_time = 100;
NPCState npc_state;

void npc_ebreak()
{
  npc_state.state = NPC_END;
  printf("!!!!!! npc ebreak !!!!!!\n");
}

uint32_t *cpu_inst = NULL;
extern "C" void set_inst_ptr(const svOpenArrayHandle r)
{
  cpu_inst = (uint32_t *)(((VerilatedDpiOpenVar *)r)->datap());
}

#ifdef CONFIG_ITRACE
char logbuf[128];
FILE *itrace_fp;
#endif

VRVNoob *top = new VRVNoob;
VerilatedVcdC *tfp = new VerilatedVcdC;

void one_clock()
{
  top->clock = 0;
  top->io_inst = pmem_read(top->io_pc, 4);
  top->eval();
  tfp->dump(main_time);
  main_time++;

#ifdef CONFIG_ITRACE
  itrace_fp = fopen("/home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob/npc-itrace-log.txt", "w+");

  char *p = logbuf;
  p += snprintf(p, sizeof(logbuf), "0x%016lx:", top->io_pc);
  int i;
  uint8_t *inst = (uint8_t *)cpu_inst;
  int ilen = 4;
  for (i = ilen - 1; i >= 0; i--) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = 4;
  int space_len = ilen_max - ilen;
  if (space_len < 0)
    space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, logbuf + sizeof(logbuf) - p,
              top->io_pc, (uint8_t *)cpu_inst, ilen);

  fprintf(itrace_fp, "%s\n", logbuf);

#endif

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

  bool sdb_en = 0;
  if (argc > 2) {
    sdb_en = ~strcmp(*(argv + 2), "sdb");
  }
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
              printf("inst args error or quit!!\n");
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
#ifdef CONFIG_ITRACE
  fclose(itrace_fp);
#endif

  tfp->close();
  delete top;
  delete tfp;
  exit(0);
  return 0;
}
