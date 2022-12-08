/*
 * @Author: Shengjie Chen chenshengjie1999@126.com
 * @Date: 2022-11-05 16:32:16
 * @LastEditors: Shengjie Chen chenshengjie1999@126.com
 * @LastEditTime: 2022-12-08 10:04:14
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


vluint64_t main_time = 0; // 当前仿真时间
const vluint64_t sim_time = -1; // 最高仿真时间 可选：100
/// @brief NPC当前运行状态等
NPCState npc_state;
/// @brief NPC寄存器状态
CPU_state cpu_state;

#ifdef CONFIG_MTRACE
extern FILE *mtrace_fp;
#endif

#ifdef CONFIG_ITRACE
char logbuf[128];
FILE *itrace_fp;
#endif

VRVNoob *top = new VRVNoob;
VerilatedVcdC *tfp = new VerilatedVcdC;

/// @brief 仿真一个时钟周期
void one_clock() {
  vaddr_t pc = top->io_pc;
  top->clock = 0;
  if (in_pmem(top->io_pc)) {
    // top->io_inst = pmem_read(top->io_pc, 4);
  } else {
    printf("error happen!! time %ld read inst addr : %lx\n", main_time, top->io_pc);
    tfp->close();
    exit(1);
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
  memset(logbuf, 0, 128);
  char *p = logbuf;
  p += snprintf(p, sizeof(logbuf), "0x%016lx:", top->io_pc);
  int i;
  uint8_t *inst = (uint8_t *)(&cpu_inst);
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
              top->io_pc, (uint8_t *)(&cpu_inst), ilen);

  fprintf(itrace_fp, "%s\n", logbuf);

#endif

  top->clock = 1;
  top->eval();
#ifdef CONFIG_DUMPVCD
  if (main_time > CONFIG_DUMPSTART)
    tfp->dump(main_time);
#endif
  main_time++;

#ifdef CONFIG_DIFFTEST
  difftest_step(pc, cpu_npc);
#endif

  device_update();
}

int main(int argc, char **argv, char **env) {
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);

  top->trace(tfp, 99);
  tfp->open("./build/RVnpc/RVNoob/RVNoob.vcd");

  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
  img_file = *(argv + 1);
  printf("%s\n", img_file);
  long img_size = load_img();

#ifdef CONFIG_ITRACE
  init_disasm("riscv64-pc-linux-gnu");
  itrace_fp = fopen("/home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob/npc-itrace-log.txt", "w+");
#endif
#ifdef CONFIG_MTRACE
  mtrace_fp = fopen(mtrace_file, "w");
#endif

  init_i8042();
  init_vga();

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
  tfp->close();
  delete top;
  delete tfp;
  exit(0);
  return 0;
}
