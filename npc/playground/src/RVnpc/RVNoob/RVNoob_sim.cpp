#include "RVNoob.h"
#include "VRVNoob.h"
#include "VRVNoob__Dpi.h"
// #include "disasm.cc"
#include "difftest.c"
#include "sdb.c"
#include "svdpi.h"
#include "time.h"
#include <sys/time.h>
#include "trace.c"
#include "verilated.h"
#include "verilated_vcd_c.h"

// int add(int a, int b) { return a + b; }

vluint64_t main_time = 0;
const vluint64_t sim_time = 100;
NPCState npc_state;
CPU_state cpu_state;

void npc_ebreak()
{
  npc_state.state = NPC_END;
  printf("!!!!!! npc ebreak !!!!!!\n");
}

// uint32_t *cpu_inst = NULL;
// extern "C" void set_inst_ptr(const svLogicVecVal *r)
//{
//   cpu_inst = (uint32_t *)(r);
// }

uint32_t cpu_inst;
extern "C" void inst_change(const svLogicVecVal *r)
{
  cpu_inst = *(uint32_t *)(r);
  // printf("inst : %x\n", cpu_inst);
}

uint32_t cpu_npc;
extern "C" void npc_change(const svLogicVecVal *r)
{
  cpu_npc = *(vaddr_t *)(r);
}

#ifdef CONFIG_MTRACE
extern FILE *mtrace_fp;
#endif

extern "C" void pmem_read_dpi(long long raddr, long long *rdata)
{
  if(raddr == RTC_ADDR) {
    struct timeval now;
    gettimeofday(&now, NULL);
    *rdata = now.tv_sec * 1000000 + now.tv_usec;
  }
  // 总是读取地址为`raddr & ~0x7ull`的8字节返回给`rdata`
  if (likely(in_pmem(raddr))) {
    *rdata = pmem_read(raddr & ~0x7ull, 8);
#ifdef CONFIG_MTRACE
    fprintf(mtrace_fp, "read  pmem ## addr: %llx", raddr & ~0x7ull);
    fprintf(mtrace_fp, " -> 0x%016llx \n", *rdata);
#endif
  }
}
extern "C" void pmem_write_dpi(long long waddr, long long wdata, char wmask)
{
  // 总是往地址为`waddr & ~0x7ull`的8字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  // printf("waddr is %016x\n",waddr);
  if(waddr == SERIAL_PORT){
    printf("write serial\n");
  }
  for (int i = 0; i < 8; i++) {
    if ((wmask >> i) & 1 == 1) {
      pmem_write((waddr & ~0x7ull) + i, 1, wdata >> (8 * i));
    }
  }
#ifdef CONFIG_MTRACE
  fprintf(mtrace_fp, "write pmem ## addr: %llx", waddr & ~0x7ull);
  fprintf(mtrace_fp, " -> 0x%016llx ", wdata);
  fprintf(mtrace_fp, " wmask-> 0x%08x \n", wmask);
#endif
}

extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
extern "C" void init_disasm(const char *triple);

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

#ifdef CONFIG_FTRACE
  ftrace_call_ret(cpu_inst, top->io_pc, cpu_npc);
#endif
#ifdef CONFIG_MTRACE
  mtrace_fp = fopen(mtrace_file, "w");
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
  tfp->dump(main_time);
  main_time++;

#ifdef CONFIG_DIFFTEST
  difftest_step(top->io_pc, cpu_npc);
#endif
}

int main(int argc, char **argv, char **env)
{
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);

  top->trace(tfp, 99);
  tfp->open("./build/RVnpc/RVNoob/RVNoob.vcd");

  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
  img_file = *(argv + 1);
  long img_size = load_img();

#ifdef CONFIG_ITRACE
  init_disasm("riscv64-pc-linux-gnu");
  itrace_fp = fopen("/home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob/npc-itrace-log.txt", "w+");
#endif

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
  refresh_gpr_pc();
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

  tfp->close();
  delete top;
  delete tfp;
  exit(0);
  return 0;
}
