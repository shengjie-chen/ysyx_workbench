#include <device/map.h>
#include <isa.h>
#include <memory/host.h>
#include <memory/vaddr.h>

#define IO_SPACE_MAX (2 * 1024 * 1024)

#ifdef CONFIG_DTRACE
extern FILE *dtrace_fp;
#endif

static uint8_t *io_space = NULL;
static uint8_t *p_space = NULL;

uint8_t *new_space(int size)
{
  uint8_t *p = p_space;
  // page aligned;
  size = (size + (PAGE_SIZE - 1)) & ~PAGE_MASK;
  p_space += size;
  assert(p_space - io_space < IO_SPACE_MAX);
  return p;
}

static void check_bound(IOMap *map, paddr_t addr)
{
  if (map == NULL) {
    Assert(map != NULL, "address (" FMT_PADDR ") is out of bound at pc = " FMT_WORD, addr, cpu.pc);
  } else {
    Assert(addr <= map->high && addr >= map->low,
           "address (" FMT_PADDR ") is out of bound {%s} [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
           addr, map->name, map->low, map->high, cpu.pc);
  }
}

static void invoke_callback(io_callback_t c, paddr_t offset, int len, bool is_write)
{
  if (c != NULL) {
    c(offset, len, is_write);
  }
}

void init_map()
{
  io_space = malloc(IO_SPACE_MAX);
  assert(io_space);
  p_space = io_space;
}

word_t map_read(paddr_t addr, int len, IOMap *map)
{
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  invoke_callback(map->callback, offset, len, false); // prepare data to read
  word_t ret = host_read(map->space + offset, len);
#ifdef CONFIG_DTRACE
  fprintf(dtrace_fp, "read  device %s ## addr: %x", map->name, addr);
  switch (len) {
  case 1:
    fprintf(dtrace_fp, " -> 0x%02lx \n", ret);
    break;
  case 2:
    fprintf(dtrace_fp, " -> 0x%04lx \n", ret);
    break;
  case 4:
    fprintf(dtrace_fp, " -> 0x%08lx \n", ret);
    break;
    IFDEF(CONFIG_ISA64, case 8
          : fprintf(dtrace_fp, " -> 0x%016lx \n", ret);
          break);
    IFDEF(CONFIG_RT_CHECK, default
          : assert(0));
  }
#endif
  return ret;
}

void map_write(paddr_t addr, int len, word_t data, IOMap *map)
{
  assert(len >= 1 && len <= 8);
  check_bound(map, addr);
  paddr_t offset = addr - map->low;
  host_write(map->space + offset, len, data);
  invoke_callback(map->callback, offset, len, true);
#ifdef CONFIG_DTRACE
  fprintf(dtrace_fp, "write device %s ## addr: %x", map->name, addr);
  switch (len) {
  case 1:
    fprintf(dtrace_fp, " -> 0x%02lx \n", data);
    break;
  case 2:
    fprintf(dtrace_fp, " -> 0x%04lx \n", data);
    break;
  case 4:
    fprintf(dtrace_fp, " -> 0x%08lx \n", data);
    break;
    IFDEF(CONFIG_ISA64, case 8
          : fprintf(dtrace_fp, " -> 0x%016lx \n", data);
          break);
    IFDEF(CONFIG_RT_CHECK, default
          : assert(0));
  }
#endif
}
