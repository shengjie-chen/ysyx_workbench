#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>

word_t expr(char *e, bool *success);
void add_new_wp(char *args);
void free_wp(int index);
void print_watchpoint();

#endif
