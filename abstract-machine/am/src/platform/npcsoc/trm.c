#include "klib.h"
#include "soc.h"
#include <am.h>

extern char data_start;
extern char data_load_start;
extern char data_load_end;
extern char _bss_start;
extern char _bss_end;
// extern char data_size;

extern char _heap_start;
int main(const char *args);

Area heap = RANGE(&_heap_start, SRAM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch) {
    while ((inb(UART_PORT + 5) & 0x60) != 0x60)
        ;
    outb(UART_PORT, ch);
}

void halt(int code) {
    npc_trap(code);

    // should not reach here
    while (1)
        ;
}

void uart_init() {
    outb(UART_PORT + 3, 0x83);
    outb(UART_PORT + 0, 0x0D);
    outb(UART_PORT + 3, 0x03);
}

void _trm_init() {
    // printf("1\n");
    // printf("data_load_start: %x\n", (uint32_t)data_load_start);
    uart_init();

    size_t load_data_size = (uint64_t)&data_load_end - (uint64_t)&data_load_start;
    // size_t bss_size = (uint64_t)&_bss_end - (uint64_t)&_bss_start;
    if (load_data_size != 0) {
        memcpy(&data_start, &data_load_start, load_data_size);
    }
    // if (bss_size != 0) {
    //     memset(&_bss_start, 0, bss_size);
    // }
    int ret = main(mainargs);
    halt(ret);
}
