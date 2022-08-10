#include <common.h>

extern uint64_t g_nr_guest_inst;
FILE *log_fp = NULL;

#ifdef CONFIG_MTRACE
  char *mtrace_file = "/home/jiexxpu/ysyx/ysyx-workbench/nemu/build/nemu-mtrace-log.txt";
  FILE *mtrace_fp = NULL;
#endif

void init_log(const char *log_file) {
  log_fp = stdout;
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open '%s'", log_file);
    log_fp = fp;
  }
  Log("Log is written to %s", log_file ? log_file : "stdout");
#ifdef CONFIG_MTRACE
  mtrace_fp = fopen(mtrace_file, "w");
#endif
}

bool log_enable() {
  return MUXDEF(CONFIG_TRACE, (g_nr_guest_inst >= CONFIG_TRACE_START) &&
         (g_nr_guest_inst <= CONFIG_TRACE_END), false);
}
