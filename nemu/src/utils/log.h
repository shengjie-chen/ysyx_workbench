#pragma once
#ifdef CONFIG_FTRACE
FILE *ftrace_fp = NULL;
char *ftrace_file = "/home/jiexxpu/ysyx/ysyx-workbench/nemu/build/nemu-mtrace-log.txt";
int mtrace_depth = 0;
int mtrace_func_num;
#define MAX_FUNC_NUM 100
char symname[MAX_FUNC_NUM][20];
vaddr_t symaddr[MAX_FUNC_NUM];
#endif