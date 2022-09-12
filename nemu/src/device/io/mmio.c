#include <device/map.h>

#define NR_MAP 16

static IOMap maps[NR_MAP] = {};
static int nr_map = 0;

static IOMap *fetch_mmio_map(paddr_t addr) {
  int mapid = find_mapid_by_addr(maps, nr_map, addr);
  return (mapid == -1 ? NULL : &maps[mapid]);
}

/* device interface */
void add_mmio_map(const char *name, paddr_t addr, void *space, uint32_t len, io_callback_t callback) {
  assert(nr_map < NR_MAP);
  maps[nr_map] = (IOMap){.name = name, .low = addr, .high = addr + len - 1, .space = space, .callback = callback};
  Log("Add mmio map '%s' at [" FMT_PADDR ", " FMT_PADDR "]",
      maps[nr_map].name, maps[nr_map].low, maps[nr_map].high);

  nr_map++;
}

#ifdef CONFIG_MTRACE
extern FILE *mtrace_fp;
#endif

/* bus interface */
word_t mmio_read(paddr_t addr, int len) {
  word_t mem_value = map_read(addr, len, fetch_mmio_map(addr));
  fprintf(mtrace_fp, "read  mmio ## addr: %x", addr);
#ifdef CONFIG_MTRACE
  switch (len) {
  case 1:
    fprintf(mtrace_fp, " -> 0x%02lx \n", mem_value);
    break;
  case 2:
    fprintf(mtrace_fp, " -> 0x%04lx \n", mem_value);
    break;
  case 4:
    fprintf(mtrace_fp, " -> 0x%08lx \n", mem_value);
    break;
    IFDEF(CONFIG_ISA64, case 8
          : fprintf(mtrace_fp, " -> 0x%016lx \n", mem_value);
          break);
    IFDEF(CONFIG_RT_CHECK, default
          : assert(0));
  }
#endif
  return mem_value;
}

void mmio_write(paddr_t addr, int len, word_t data) {
  map_write(addr, len, data, fetch_mmio_map(addr));
#ifdef CONFIG_MTRACE
  fprintf(mtrace_fp, "write mmio ## addr: %x", addr);
  word_t mem_value;
  word_t *mem_value_ptr = &mem_value;
  switch (len) {
  case 1:
    *(uint8_t *)mem_value_ptr = data;
    fprintf(mtrace_fp, " -> 0x%02x \n", *(uint8_t *)mem_value_ptr);
    break;
  case 2:
    *(uint16_t *)mem_value_ptr = data;
    fprintf(mtrace_fp, " -> 0x%04x \n", *(uint16_t *)mem_value_ptr);
    break;
  case 4:
    *(uint32_t *)mem_value_ptr = data;
    fprintf(mtrace_fp, "\n 1 \n");
    fprintf(mtrace_fp, " -> 0x%08x \n", *(uint32_t *)mem_value_ptr);
    break;
    IFDEF(CONFIG_ISA64, case 8
          : *(uint64_t *)mem_value_ptr = data;
          fprintf(mtrace_fp, " -> 0x%016lx \n", *mem_value_ptr);
          break);
    IFDEF(CONFIG_RT_CHECK, default
          : assert(0));
  }
#endif
}
