#include "klib.h"
#include "nemusoc.h"
#include <am.h>

extern char data_start[];
extern char data_end[];
extern char data_size[];
// extern size_t data_size;
extern char data_load_start[];
extern char data_load_end[];
extern char edata[];

extern char _heap_start;
int main(const char *args);

Area heap = RANGE(&_heap_start, SRAM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch) { outb(UART_PORT, ch); }

void halt(int code) {
    nemu_trap(code);

    // should not reach here
    while (1)
        ;
}

void _trm_init() {
    printf("data_load_start: %lx\n", data_load_start);
    printf("data_load_end: %lx\n", data_load_end);
    printf("data_size: %lx\n", (size_t)data_size);
    printf("data_size: %lx\n", data_size);
    printf("data_start: %lx\n", data_start);
	printf("data_size: %lx\n", data_start - data_end);
	printf("load_data_size: %lx\n", data_load_end - data_load_start);
	int load_data_size = data_load_end - data_load_start;
    if ((data_start != data_load_start)) {
        memcpy(data_start, data_load_start, (size_t)load_data_size);
        // for(int i = 0; i < data_size; i++){
        // 	data_start[i] = data_load_start[i];
        // }
    }
    int ret = main(mainargs);
    halt(ret);
}
