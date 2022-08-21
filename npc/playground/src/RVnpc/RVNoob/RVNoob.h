#ifndef __RVNPPB_H__
#define __RVNPPB_H__
#include "macro.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verilated_dpi.h"


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;

typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

typedef uint64_t word_t;
typedef uint64_t paddr_t;

#define CONFIG_MSIZE 0x8000000
#define CONFIG_MBASE 0x80000000

//#define PG_ALIGN __attribute((aligned(4096)))
#define CONFIG_ISA64 1
//#define IFDEF(macro, ...) MUXDEF(macro, __KEEP, __IGNORE)(__VA_ARGS__)
//#define MUXDEF(macro, X, Y)  MUX_MACRO_PROPERTY(__P_DEF_, macro, X, Y)
#define CONFIG_RT_CHECK 1

#define RESET_VECTOR (CONFIG_MBASE + CONFIG_PC_RESET_OFFSET)
#define CONFIG_PC_RESET_OFFSET 0x0
//#define MUX_MACRO_PROPERTY(p, macro, a, b) MUX_WITH_COMMA(concat(p, macro), a, b)

char *img_file = NULL;

uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
const uint32_t img[] = {
    0xff010113, // addi	sp,sp,-16
    0xfa010113, // addi	sp,sp,-96
    0x004c8c93, // addi	s9,s9,4
    0x00840413, // addi	s0,s0,8
    0x004a0a13, // addi	s4,s4,4
    0xff010113, // addi	sp,sp,-16
    0xfa010113, // addi	sp,sp,-96
    0x004c8c93, // addi	s9,s9,4
    0x00840413, // addi	s0,s0,8
    0x004a0a13, // addi	s4,s4,4
    0x00100073  // ebreak
    //  0x0102b503,  // ld  a0,16(t0)
    //  0x00100073,  // ebreak (used as NPC_trap)
    //  0xdeadbeef,  // some data
};

uint8_t *guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }

long load_img()
{
  if (img_file == NULL) {
    printf("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  if (fp == NULL) {
    printf("Can not open '%s'", img_file);
  }

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  printf("The image is %s, size = %ld\n", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

word_t host_read(void *addr, int len)
{
  switch (len) {
  case 1:
    return *(uint8_t *)addr;
  case 2:
    return *(uint16_t *)addr;
  case 4:
    return *(uint32_t *)addr;
    IFDEF(CONFIG_ISA64, case 8
          : return *(uint64_t *)addr);
  default:
    MUXDEF(CONFIG_RT_CHECK, assert(0), return 0);
  }
}

word_t pmem_read(paddr_t addr, int len)
{
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}


typedef struct {
  int state;
  // vaddr_t halt_pc;
  // uint32_t halt_ret;
} NPCState;

enum { NPC_RUNNING,
       NPC_STOP,
       NPC_END /*, NPC_ABORT*/, NPC_QUIT };


// extern NPCState npc_state;

void sdb_mainloop();
extern "C" void set_gpr_ptr(const svOpenArrayHandle r);

#endif