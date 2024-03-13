#include "klib.h"
#include "soc.h"
#include <am.h>

extern char data_start[];
extern char data_size[];
extern char data_load_start[];

extern char _heap_start;
int main(const char *args);

Area heap = RANGE(&_heap_start, SRAM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch) { outb(UART_PORT, ch); }

void halt(int code) {
    npc_trap(code);

    // should not reach here
    while (1)
        ;
}

void _trm_init() {
	// printf("data_load_start: %lx\n", data_load_start);
    if (data_start != data_load_start && data_size != 0) {
        memcpy(data_start, data_load_start, (size_t)data_size);
    }
    int ret = main(mainargs);
    halt(ret);
}
