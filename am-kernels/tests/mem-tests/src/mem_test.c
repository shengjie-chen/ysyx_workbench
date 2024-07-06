#include "am.h"
#include "klib.h"
#include "riscv.h"

extern char _heap_start;
extern char _heap_end;

int main() {
    size_t heap_size = (uint64_t)&_heap_end - (uint64_t)&_heap_start;
    char *str;
    uint8_t *heap_start = malloc(heap_size);
    // size_t heap_size = 8;

    // 8bit
    assert(heap_size % 1 == 0);
    for (int i = 0; i < heap_size; i++) {
        outb((uint64_t)(heap_start + i), (uint64_t)(heap_start + i) && 0xff);
    }
    for (int i = 0; i < heap_size; i++) {
        if (inb((uint64_t)(heap_start + i)) != ((uint64_t)(heap_start + i) && 0xff)) {
            str = "8bit fail!\n";
            for (int i = 0; str[i] != '\0'; i++) {
                putch(str[i]);
            }
            halt(1);
            return 1;
        }
    }
    str = "8bit pass!\n";
    for (int i = 0; str[i] != '\0'; i++) {
        putch(str[i]);
    }

    // 16bit
    assert(heap_size % 2 == 0);
    uint16_t *heap_start_16 = (uint16_t *)heap_start;
    for (int i = 0; i < heap_size / 2; i++) {
        outw((uint64_t)(heap_start_16 + i), (uint64_t)(heap_start_16 + i) && 0xffff);
    }
    for (int i = 0; i < heap_size / 2; i++) {
        if (inw((uint64_t)(heap_start_16 + i)) != ((uint64_t)(heap_start_16 + i) && 0xffff)) {
            str = "16bit fail!\n";
            for (int i = 0; str[i] != '\0'; i++) {
                putch(str[i]);
            }
            halt(1);
            return 1;
        }
    }
    str = "16bit pass!\n";
    for (int i = 0; str[i] != '\0'; i++) {
        putch(str[i]);
    }

    // 32bit
    assert(heap_size % 4 == 0);
    uint32_t *heap_start_32 = (uint32_t *)heap_start;
    for (int i = 0; i < heap_size / 4; i++) {
        outw((uint64_t)(heap_start_32 + i), (uint64_t)(heap_start_32 + i) && 0xffffffff);
    }
    for (int i = 0; i < heap_size / 4; i++) {
        if (inw((uint64_t)(heap_start_32 + i)) != ((uint64_t)(heap_start_32 + i) && 0xffffffff)) {
            str = "32bit fail!\n";
            for (int i = 0; str[i] != '\0'; i++) {
                putch(str[i]);
            }
            halt(1);
            return 1;
        }
    }
    str = "32bit pass!\n";
    for (int i = 0; str[i] != '\0'; i++) {
        putch(str[i]);
    }

    // 64bit
    assert(heap_size % 8 == 0);
    uint64_t *heap_start_64 = (uint64_t *)heap_start;
    for (int i = 0; i < heap_size / 8; i++) {
        outw((uint64_t)(heap_start_64 + i), (uint64_t)(heap_start_64 + i) && 0xffffffffffffffff);
    }
    for (int i = 0; i < heap_size / 8; i++) {
        if (inw((uint64_t)(heap_start_64 + i)) != ((uint64_t)(heap_start_64 + i) && 0xffffffffffffffff)) {
            str = "64bit fail!\n";
            for (int i = 0; str[i] != '\0'; i++) {
                putch(str[i]);
            }
            halt(1);
            return 1;
        }
    }
    str = "64bit pass!\n";
    for (int i = 0; str[i] != '\0'; i++) {
        putch(str[i]);
    }

    halt(0);
}