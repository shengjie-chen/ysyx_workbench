#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10
void check_watchpoint();

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

static char iringbuf[16][128];
static int iringbuf_ptr = 0;

void device_update();

static void trace_and_difftest(Decode *_this, vaddr_t dnpc)
{
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) {
    log_write("%s\n", _this->logbuf);
  }
#endif
  if (g_print_step) {
    IFDEF(CONFIG_ITRACE, puts(_this->logbuf));
  }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
#ifdef CONFIG_WATCHPOINT
  check_watchpoint();
#endif
}

#ifdef CONFIG_FTRACE
#define MAX_FUNC_NUM 100
extern int ftrace_func_num;
extern int ftrace_depth;
extern char symname[MAX_FUNC_NUM][20];
extern vaddr_t symaddr[MAX_FUNC_NUM];
extern vaddr_t symaddr_end[MAX_FUNC_NUM];
extern FILE *ftrace_fp;
static void ftrace_call_ret(Decode *s, vaddr_t pc)
{
  // printf("djfa;d");
  // if ((s->isa.inst.val & 0x7F) != 0x6F || (s->isa.inst.val & 0x7F) != 0x67) {
  //   return;
  // }
  if (s->isa.inst.val == 0x00008067) {
    for (int i = 0; i < ftrace_func_num; i++) {
      if (s->dnpc >= symaddr[i] && s->dnpc <= symaddr_end[i]) {
        ftrace_depth--;
        fprintf(ftrace_fp, "0x%8lx: ", pc);
        for (int i = 0; i < ftrace_depth; i++) {
          fprintf(ftrace_fp, "  ");
        }
        fprintf(ftrace_fp, "#%d ret  [%s@%8lx]\n", ftrace_depth, symname[i], s->dnpc);
        return;
      }
    }
    return;
  }
  for (int i = 0; i < ftrace_func_num; i++) {
    if (s->dnpc == symaddr[i]) {
      fprintf(ftrace_fp, "0x%8lx: ", pc);
      for (int i = 0; i < ftrace_depth; i++) {
        fprintf(ftrace_fp, "  ");
      }
      fprintf(ftrace_fp, "#%d call [%s@%8lx]\n", ftrace_depth, symname[i], symaddr[i]);
      ftrace_depth++;
      return;
    }
  }
  return;
}
#endif

static void exec_once(Decode *s, vaddr_t pc)
{
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
#ifdef CONFIG_FTRACE
  ftrace_call_ret(s, pc);
#endif
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = ilen - 1; i >= 0; i--) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0)
    space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
              MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
#endif

  // #ifdef CONFIG_IRINGBUF
  char *ptr = iringbuf[iringbuf_ptr];
  if (nemu_state.state == NEMU_ABORT) {
    memcpy(ptr, " --> ", 5);
  } else {
    memcpy(ptr, "     ", 5);
  }
  ptr += 5;
  memcpy(ptr, s->logbuf, 123);

  if (nemu_state.state == NEMU_ABORT) {
    char *iringbuf_file = "/home/jiexxpu/ysyx/ysyx-workbench/nemu/build/nemu-iringbuf-log.txt";
    FILE *iringbuf_fp = fopen(iringbuf_file, "w");
    Assert(iringbuf_fp, "Can not open '%s'", iringbuf_file);
    int i;
    for (i = 0; i < 16; i++) {
      fprintf(iringbuf_fp, "%s\n", iringbuf[i]);
      // printf("%s\n", iringbuf[i]);
    }
  }
  if (iringbuf_ptr == 15) {
    iringbuf_ptr = 0;
  } else {
    iringbuf_ptr++;
  }
  memset(iringbuf[iringbuf_ptr], 0, 128);
  // #endif
}

static void execute(uint64_t n)
{
  Decode s;
  for (; n > 0; n--) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst++;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING)
      break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic()
{
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%ld", "%'ld")
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0)
    Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else
    Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg()
{
  isa_reg_display();
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n)
{
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
  case NEMU_END:
  case NEMU_ABORT:
    printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
    return;
  default:
    nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
  case NEMU_RUNNING:
    nemu_state.state = NEMU_STOP;
    break;

  case NEMU_END:
  case NEMU_ABORT:
    Log("nemu: %s at pc = " FMT_WORD,
        (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) : (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) : ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
        nemu_state.halt_pc);
    // fall through
  case NEMU_QUIT:
    statistic();
  }
}
