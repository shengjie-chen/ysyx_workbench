/*
 * @Author: Shengjie Chen chenshengjie1999@126.com
 * @Date: 2022-11-05 16:32:16
 * @LastEditors: Shengjie Chen chenshengjie1999@126.com
 * @LastEditTime: 2022-12-10 11:08:05
 * @FilePath: /npc/playground/src/RVnpc/RVNoob/RVNoob_sim.cpp
 * @Description: 对RVNoob处理器进行仿真的主文件
 */
#include "VRVNoob.h"
#include "VRVNoob__Dpi.h"
#include "svdpi.h"
#include "time.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <sys/time.h>

#include "RVNoob.h"
#include "device.c"
#include "difftest.c"
#include "sdb.c"
#include "timer.c"
#include "trace.c"
#include "useddpi.c"

extern "C" void init_disasm(const char *triple);
extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

vluint64_t main_time = 0;       // 当前仿真时间
const vluint64_t sim_time = -1; // 最高仿真时间 可选：100
/// @brief NPC当前运行状态等
NPCState npc_state;
/// @brief NPC寄存器状态
CPU_state cpu_state;

#ifdef CONFIG_MTRACE
extern FILE *mtrace_fp;
#endif

#ifdef CONFIG_ITRACE
#define ITRACE_PATH NPC_HOME "/build/RVnpc/RVNoob/npc-itrace-log.txt"
char logbuf[128];
FILE *itrace_fp;
char *itrace_file = ITRACE_PATH;
#endif

VRVNoob *top = new VRVNoob;
#ifdef CONFIG_DUMPVCD
VerilatedVcdC *tfp = new VerilatedVcdC;
#endif

/// @brief 仿真一个时钟周期
void one_clock() {
  vaddr_t pc = top->io_pc;
  top->clock = 0;
  if (in_pmem(top->io_pc)) {
    // top->io_inst = pmem_read(top->io_pc, 4);
  } else {
    printf("error happen!! time %ld read inst addr : %x\n", main_time, top->io_pc);
    // tfp->close();
    // exit(1);
    npc_state.state = NPC_ABORT;
    return;
  }
  top->eval();
#ifdef CONFIG_DUMPVCD
  if (main_time > CONFIG_DUMPSTART)
    tfp->dump(main_time);
#endif
  main_time++;

#ifdef CONFIG_FTRACE
  ftrace_call_ret(cpu_inst, top->io_pc, cpu_npc);
#endif

#ifdef CONFIG_ITRACE
  if (main_time > CONFIG_DUMPSTART) {
    if (wb_valid == 1) {
      memset(logbuf, 0, 128);
      char *p = logbuf;
      p += snprintf(p, sizeof(logbuf), "0x%016lx:", wb_pc);
      int i;
      uint8_t *inst = (uint8_t *)(&wb_inst);
      // printf("%x\n", cpu_inst);
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
      disassemble(p, logbuf + sizeof(logbuf) - p,
                  top->io_pc, (uint8_t *)(&wb_inst), ilen);

      fprintf(itrace_fp, "%s\n", logbuf);
    }
  }
#endif

  top->clock = 1;
  top->eval();
#ifdef CONFIG_DUMPVCD
  if (main_time > CONFIG_DUMPSTART)
    tfp->dump(main_time);
#endif

#ifdef CONFIG_DIFFTEST
  difftest_step(pc, cpu_npc);
#endif

  device_update();
  main_time++;
}

int main(int argc, char **argv, char **env) {
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);
#ifdef CONFIG_DUMPVCD
  top->trace(tfp, 99);
  tfp->open("./build/RVnpc/RVNoob/RVNoob.vcd");
#endif
  clock_t start, end;
  start = clock();

  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
  img_file = *(argv + 1);
  printf("%s\n", img_file);
  long img_size = load_img();

#ifdef CONFIG_ITRACE
  init_disasm("riscv64-pc-linux-gnu");
  itrace_fp = fopen(itrace_file, "w+");
  printf("[ log ] Inst Trace Log is written to %s\n", itrace_file);
#endif
#ifdef CONFIG_MTRACE
  mtrace_fp = fopen(mtrace_file, "w");
  printf("[ log ] Mem Trace Log is written to %s\n", mtrace_file);
#endif

  init_i8042();
  init_vga();

  npc_state.state = NPC_RUNNING;

  int n = 10;
  top->reset = 1;
  while (n-- > 0) {
    top->clock = 0;
    top->eval();
#ifdef CONFIG_DUMPVCD
    tfp->dump(main_time);
#endif
    main_time++;

    top->clock = 1;
    top->eval();
#ifdef CONFIG_DUMPVCD
    tfp->dump(main_time);
#endif
    main_time++;
  }
  top->reset = 0;

  // parse_args
  bool sdb_en = 0;
  if (argc > 2) {
    sdb_en = ~strcmp(*(argv + 2), "sdb_y");
  }

#ifdef CONFIG_DIFFTEST
  bool diff_en = 0;
  if (argc > 4) {
    diff_en = ~strncmp(*(argv + 4), "diff=", 5);
  } else {
    panic("check difftest file!\n")
  }
  refresh_gpr_pc_csr();
  cpu_state.pc = top->io_pc;
  if (diff_en) {
    diff_file = *(argv + 4) + 5;
    init_difftest(diff_file, img_size, 0, &cpu_state);
  }
#endif

#ifdef CONFIG_FTRACE
  bool elf_en = 0;
  if (argc > 3) {
    elf_en = ~strncmp(*(argv + 3), "elf=", 4);
  } else {
    panic("check elf file!\n")
  }
  if (elf_en) {
    elf_file = *(argv + 3) + 4;
    printf("%s\n", elf_file);
    printf("[ log ] Function Trace Log is written to %s\n", ftrace_file);
    init_ftrace(elf_file);
  }
#endif

  // printf("%s\n",*(argv + 2));
  // printf("%d\n",sdb_en);
  if (sdb_en) {
    sdb_mainloop();
  } else {
    while (!Verilated::gotFinish() && main_time < sim_time && npc_state.state == NPC_RUNNING) {
      // printf("%d\n",npc_state.state);
      one_clock();
    }
  }
  end = clock();
  int time = double(end - start) / CLOCKS_PER_SEC;
  vluint64_t inst_cnt = top->io_inst_cnt;
  vluint64_t clock_cnt = main_time / 2;
  if(time == 0)    time = 1;
  printf("\n\033[;31m************ SIM SUMMARY ************\n\033[0m");
  printf("simulation time          : %d min %d s\n", time / 60, time % 60);
  printf("sim clock num            : %ld\n", clock_cnt);
  printf("complete inst num        : %ld\n", inst_cnt);
  printf("npc ipc                  : %f\n", (double)inst_cnt / (double)clock_cnt);
  printf("average clk speed        : %ld clock/s\n", clock_cnt / time);
  printf("average inst speed       : %ld insts/s\n", inst_cnt / time);
#ifdef SPMU_ENABLE
  printf("\n\033[;31m************ Software PMU Cache ************\n\033[0m");
  printf("icache hit               : %ld\n", icache_hit);
  printf("icache miss              : %ld\n", icache_miss);
  printf("dcache hit               : %ld\n", dcache_hit);
  printf("dcache miss              : %ld\n", dcache_miss);
  printf("\033[;34micache hit rate          : %f\n\033[0m", (double)icache_hit / (double)(icache_hit + icache_miss));
  printf("\033[;34mdcache hit rate          : %f\n\033[0m", (double)dcache_hit / (double)(dcache_hit + dcache_miss));

  uint64_t branch_error = id_branch_error + exe_branch_error + mem_branch_error;
  uint64_t must_taken_br = branch_inst - typeb_br;
  
  printf(ANSI_FMT("************ Software PMU Branch ************\n", ANSI_FG_RED));
  printf("branch inst num          : %ld\n", branch_inst);
  printf("branch error num         : %ld\n", branch_error);
  printf(ANSI_FMT("branch error rate        : %f\n", ANSI_FG_YELLOW), (double)branch_error / (double)branch_inst);
  printf("typeb inst num           : %ld\n", typeb_br);
  printf("typeb error num          : %ld\n", mem_branch_error);
  printf(ANSI_FMT("typeb error rate         : %f\n", ANSI_FG_YELLOW), (double)mem_branch_error / (double)typeb_br);
  printf("must taken inst num      : %ld\n", must_taken_br);
  printf("must taken error num     : %ld\n", exe_branch_error);
  printf(ANSI_FMT("must taken error rate    : %f\n", ANSI_FG_YELLOW), (double)exe_branch_error / (double)must_taken_br);
  printf(ANSI_FMT("not br but taken num     : %ld\n", ANSI_FG_YELLOW), id_branch_error);
  printf("retrun inst num          : %ld\n", ret_inst);
  printf("retrun inst error num    : %ld\n", ret_error_inst);
  printf(ANSI_FMT("retrun inst error rate   : %f\n", ANSI_FG_YELLOW), (double)ret_error_inst / (double)ret_inst);

#endif
  printf("\n");
#ifdef CONFIG_ITRACE
  fclose(itrace_fp);
#endif
#ifdef CONFIG_MTRACE
  fclose(mtrace_fp);
#endif
#ifdef CONFIG_FTRACE
  fclose(ftrace_fp);
#endif
  // #ifdef CONFIG_DUMPVCD
  //   sleep(1);
  // #endif

  free(vmem);
#ifdef CONFIG_DUMPVCD
  tfp->close();
  delete tfp;
#endif
  delete top;
  exit(0);
  return 0;
}
