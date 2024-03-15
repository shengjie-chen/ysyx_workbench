#include "klib.h"
#include "nemusoc.h"
#include <am.h>

extern char data_start[];
// extern char data_end[];
extern char _bss_start[];
extern char _bss_end[];
// extern char data_size[];
extern char data_load_start[];
extern char data_load_end[];
// extern char edata[];

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
    // printf("virtual data_start: %lx\n", data_start);
    // printf("virtual data_end: %lx\n", data_end);
    // printf("virtual data_size: %lx\n", data_size);
    // printf("data_load_start: %lx\n", data_load_start);
    // printf("data_load_end: %lx\n", data_load_end);
    // printf("load_data_size: %lx\n", data_load_end - data_load_start);
    // printf("\n");

    // printf("virtual _bss_start: %lx\n", _bss_start);
    // printf("virtual _bss_end: %lx\n", _bss_end);
    // printf("virtual data_size: %lx\n", _bss_end - _bss_start);
    // printf("bss_load_start: %lx\n", data_load_end);
    // printf("bss_load_end: not know\n");
    // printf("bss_load_end: not know %lx\n", data_load_end);
    // printf("bss_size: %lx\n", data_load_end - data_load_start);
    size_t load_data_size = data_load_end - data_load_start;
    size_t bss_size = _bss_end - _bss_start;
    if ((data_start != data_load_start)) {
        memcpy(data_start, data_load_start, load_data_size);
    }
    if ((_bss_end != _bss_start)) {
        memset(_bss_start, 0, bss_size);
    }

    int ret = main(mainargs);
    halt(ret);
}
