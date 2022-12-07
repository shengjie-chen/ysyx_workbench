#ifndef __RVNOOB_H__
#define __RVNOOB_H__
#include "common.h"
#include "verilated_dpi.h"
//#include "/home/jiexxpu/ysyx/ysyx-workbench/nemu/src/cpu/difftest/ref.c"
// typedef signed char __int8_t;
// typedef unsigned char __uint8_t;
// typedef signed short int __int16_t;
// typedef unsigned short int __uint16_t;
// typedef signed int __int32_t;
// typedef unsigned int __uint32_t;
// typedef signed long int __int64_t;
// typedef unsigned long int __uint64_t;
// typedef __uint8_t uint8_t;
// typedef __uint16_t uint16_t;
// typedef __uint32_t uint32_t;
// typedef __uint64_t uint64_t;
//#define PG_ALIGN __attribute((aligned(4096)))
//#define IFDEF(macro, ...) MUXDEF(macro, __KEEP, __IGNORE)(__VA_ARGS__)
//#define MUXDEF(macro, X, Y)  MUX_MACRO_PROPERTY(__P_DEF_, macro, X, Y)
//#define MUX_MACRO_PROPERTY(p, macro, a, b) MUX_WITH_COMMA(concat(p, macro), a, b)

#define CONFIG_RT_CHECK 1

char *img_file = NULL;

uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
//const uint32_t img[] = {
//    0xff010113, // addi	sp,sp,-16
//    0xfa010113, // addi	sp,sp,-96
//    0x004c8c93, // addi	s9,s9,4
//    0x00840413, // addi	s0,s0,8
//    0x004a0a13, // addi	s4,s4,4
//    0xff010113, // addi	sp,sp,-16
//    0xfa010113, // addi	sp,sp,-96
//    0x004c8c93, // addi	s9,s9,4
//    0x00840413, // addi	s0,s0,8
//    0x004a0a13, // addi	s4,s4,4
//    0x00100073  // ebreak
//    //  0x0102b503,  // ld  a0,16(t0)
//    //  0x00100073,  // ebreak (used as NPC_trap)
//    //  0xdeadbeef,  // some data
//};
// const uint32_t img[] = { // 测试用例中不包括跳转指令，且不存在指令相关性冲突
//     0x00000413, // li	s0,0
//     0x00009117, // auipc	sp,0x9
//     0x01858593, // addi	a1,a1,24 
//     0x004c8c93, // addi	s9,s9,4
//     0x00840413, // addi	s0,s0,8
//     0x004a0a13, // addi	s4,s4,4
//     0xffc10113, // addi	sp,sp,-4
//     0x01858593, // addi	a1,a1,24 
//     0x004c8c93, // addi	s9,s9,4
//     0x00840413, // addi	s0,s0,8
//     0x004a0a13, // addi	s4,s4,4 
//     0xff010113, // addi	sp,sp,-16
//     0x01858593, // addi	a1,a1,24 
//     0x004c8c93, // addi	s9,s9,4
//     0x00840413, // addi	s0,s0,8
//     0x004a0a13, // addi	s4,s4,4
//     0x00b13423, // sd	a1,8(sp)
//     0x00006597, // auipc	a1,0x6
//     0x00000517, // auipc	a0,0x0
//     0x0015869b, // addiw	a3,a1,1
//     0xff010113, // addi	sp,sp,-16
//     0x01c50513, // addi	a0,a0,28 
//     0x004c8c93, // addi	s9,s9,4
//     0x00050513, // mv	a0,a0
//     0x00813983, // ld	s3,8(sp)  
//     0x00100073  // ebreak
//     //  0x0102b503,  // ld  a0,16(t0)
//     //  0x00100073,  // ebreak (used as NPC_trap)
//     //  0xdeadbeef,  // some data
// };

const uint32_t img[] = { // 测试用例中包括跳转指令，但不存在指令相关性冲突
    0x00000413, // li	s0,0              0x80000000
    0x00009117, // auipc	sp,0x9        0x80000004
    0x01858593, // addi	a1,a1,24        0x80000008
    0x004c8c93, // addi	s9,s9,4         0x8000000c
    0x02040a63, // beqz	s0,0x34         0x80000010 -> 0x80000044
    // 0x00840413, // addi	s0,s0,8
    0x004a0a13, // addi	s4,s4,4         0x80000014
    0xffc10113, // addi	sp,sp,-4        0x80000018
    0x01858593, // addi	a1,a1,24        0x8000001c
    0x004c8c93, // addi	s9,s9,4         0x80000020
    0x00840413, // addi	s0,s0,8         0x80000024
    0x004a0a13, // addi	s4,s4,4         0x80000028
    0xff010113, // addi	sp,sp,-16       0x8000002c
    0x01858593, // addi	a1,a1,24        0x80000030
    0x004c8c93, // addi	s9,s9,4         0x80000034
    0x00840413, // addi	s0,s0,8         0x80000038
    0x004a0a13, // addi	s4,s4,4         0x8000003c
    0x00b13423, // sd	a1,8(sp)          0x80000040
    0x00006597, // auipc	a1,0x6        0x80000044
    0x00000517, // auipc	a0,0x0        0x80000048
    0x0015869b, // addiw	a3,a1,1       0x8000004c
    0xff010113, // addi	sp,sp,-16       0x80000050
    0x01c50513, // addi	a0,a0,28 
    0x004c8c93, // addi	s9,s9,4
    0x00050513, // mv	a0,a0
    0x00813983, // ld	s3,8(sp)  
    0x00100073  // ebreak
    //  0x0102b503,  // ld  a0,16(t0)
    //  0x00100073,  // ebreak (used as NPC_trap)
    //  0xdeadbeef,  // some data
};

/// @brief 将客户地址向主机地址转换-----地址可以分为客户地址（npc地址，通常是0x800...）和主机地址（实际地址）
/// @param paddr 
/// @return 
uint8_t *guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }

long load_img()
{
  if (~strcmp(img_file,"default")) {
    printf("No image is given. Use the default build-in image.\n");
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

void host_write(void *addr, int len, word_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    IFDEF(CONFIG_ISA64, case 8: *(uint64_t *)addr = data; return);
    IFDEF(CONFIG_RT_CHECK, default: assert(0));
  }
}

word_t pmem_read(paddr_t addr, int len)
{
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

void pmem_write(paddr_t addr, int len, word_t data)
{
  host_write(guest_to_host(addr), len, data);
}

bool in_pmem(paddr_t addr) {
  return (addr >= CONFIG_MBASE) && (addr - CONFIG_MSIZE < (paddr_t)CONFIG_MBASE);
}

/// @brief NPC当前运行状态等
typedef struct {
  int state;
  vaddr_t halt_pc;
  // uint32_t halt_ret;
} NPCState;

#define CSR_NUM 4
/// @brief RV64CPU寄存器状态
typedef struct {
  word_t gpr[32];
  vaddr_t pc;
  word_t csr[CSR_NUM];
} NPC_riscv64_CPU_state;

typedef NPC_riscv64_CPU_state CPU_state;

enum { NPC_RUNNING,
       NPC_STOP,
       NPC_END , NPC_ABORT, NPC_QUIT };

// extern NPCState npc_state;

#endif