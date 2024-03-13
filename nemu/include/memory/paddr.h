#ifndef __MEMORY_PADDR_H__
#define __MEMORY_PADDR_H__

#include <common.h>

#ifdef CONFIG_SOC
#define RESET_VECTOR (CONFIG_MROM_BASE + CONFIG_PC_RESET_OFFSET)
#else
#define RESET_VECTOR (CONFIG_MBASE + CONFIG_PC_RESET_OFFSET)
#endif

/* convert the guest physical address in the guest program to host virtual address in NEMU */
uint8_t *guest_to_host(paddr_t paddr);
/* convert the host virtual address in NEMU to guest physical address in the guest program */
paddr_t host_to_guest(uint8_t *haddr);

static inline bool in_pmem(paddr_t addr) {
  return (addr >= CONFIG_MBASE) && (addr - CONFIG_MSIZE < (paddr_t)CONFIG_MBASE);
}

#ifdef CONFIG_SOC
static inline bool in_mrom(paddr_t addr) {
  return (addr >= CONFIG_MROM_BASE) && (addr - CONFIG_MROM_SIZE < (paddr_t)CONFIG_MROM_BASE);
}

static inline bool in_sram(paddr_t addr) {
  return (addr >= CONFIG_SRAM_BASE) && (addr - CONFIG_SRAM_SIZE < (paddr_t)CONFIG_SRAM_BASE);
}
#endif

#define MMIO_MBASE 0xa0000000
#define MMIO_MEND 0xa0001000
static inline bool in_mmio(paddr_t addr) {
  return (addr >= MMIO_MBASE) && (addr < MMIO_MEND);
}

word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);

#endif
