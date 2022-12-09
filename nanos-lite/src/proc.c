/*
 * @Author: Shengjie Chen chenshengjie1999@126.com
 * @Date: 2022-11-05 16:32:16
 * @LastEditors: Shengjie Chen chenshengjie1999@126.com
 * @LastEditTime: 2022-12-09 20:30:11
 * @FilePath: /nanos-lite/src/proc.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <proc.h>

#define MAX_NR_PROC 4

static PCB pcb[MAX_NR_PROC] __attribute__((used)) = {};
static PCB pcb_boot = {};
PCB *current = NULL;

extern void naive_uload(PCB *pcb, const char *filename);

void switch_boot_pcb() {
  current = &pcb_boot;
}

void hello_fun(void *arg) {
  int j = 1;
  while (1) {
    Log("Hello World from Nanos-lite with arg '%p' for the %dth time!", (uintptr_t)arg, j);
    j++;
    yield();
  }
}

void init_proc() {
  switch_boot_pcb();

  Log("Initializing processes...");

  // load program here
  // naive_uload(NULL, NULL);

  // APPS
  // naive_uload(NULL,"/bin/nslider");
  // naive_uload(NULL,"/bin/menu");
  // naive_uload(NULL,"/bin/nterm");
  // naive_uload(NULL,"/bin/bird");
  // naive_uload(NULL, "/bin/pal");

  // TESTS
  naive_uload(NULL,"/bin/dummy");
  // naive_uload(NULL,"/bin/hello");
  // naive_uload(NULL,"/bin/file-test");
  // naive_uload(NULL,"/bin/timer-test");
  // naive_uload(NULL,"/bin/event-test");
  // naive_uload(NULL,"/bin/bmp-test");
  // naive_uload(NULL,"/bin/fixedptc-test");
}

Context *schedule(Context *prev) {
  return NULL;
}
