#include <device/mmio.h>
#include <isa.h>
#include <memory/host.h>
#include <memory/paddr.h>

#if defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

#ifdef CONFIG_MTRACE
extern FILE *mtrace_fp;
#endif

uint8_t *guest_to_host(paddr_t paddr)
{
  return pmem + paddr - CONFIG_MBASE;
}
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len)
{
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data)
{
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr)
{
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, (paddr_t)CONFIG_MBASE, (paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1, cpu.pc);
}

void init_mem()
{
#if defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
#ifdef CONFIG_MEM_RANDOM
  uint32_t *p = (uint32_t *)pmem;
  int i;
  for (i = 0; i < (int)(CONFIG_MSIZE / sizeof(p[0])); i++) {
    p[i] = rand();
  }
#endif
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]",
      (paddr_t)CONFIG_MBASE, (paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1);
}

word_t paddr_read(paddr_t addr, int len)
{
#ifdef CONFIG_MTRACE
  fprintf(mtrace_fp, "read  pmem ## addr: %x", addr);
#endif
  if (likely(in_pmem(addr))) {
#ifdef CONFIG_MTRACE
    word_t mem_value = pmem_read(addr, len);
    fprintf(mtrace_fp, " -> 0x%lx \n", mem_value);
    return mem_value;
#endif
    return pmem_read(addr, len);
  }
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
#ifdef CONFIG_MTRACE
  fprintf(mtrace_fp, " -> addr is out of bound!\n");
#endif
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data)
{
#ifdef CONFIG_MTRACE
  fprintf(mtrace_fp, "write pmem ## addr: %x", addr);
#endif
  if (likely(in_pmem(addr))) {
#ifdef CONFIG_MTRACE
    word_t mem_value;
    word_t *mem_value_ptr = &mem_value;
    switch (len) {
    case 1:
      *(uint8_t *)mem_value_ptr = data;
      break;
    case 2:
      *(uint16_t *)mem_value_ptr = data;
      break;
    case 4:
      *(uint32_t *)mem_value_ptr = data;
      break;
      IFDEF(CONFIG_ISA64, case 8
            : *(uint64_t *)mem_value_ptr = data;
            break);
      IFDEF(CONFIG_RT_CHECK, default
            : assert(0));
    }
    fprintf(mtrace_fp, " -> 0x%8lx \n", *mem_value_ptr);
#endif
    pmem_write(addr, len, data);
    return;
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return );
#ifdef CONFIG_MTRACE
  fprintf(mtrace_fp, " -> addr is out of bound!\n");
#endif
  out_of_bound(addr);
}
