#include <isa.h>
#include <memory/paddr.h>
extern FILE *mtrace_fp;
word_t vaddr_ifetch(vaddr_t addr, int len)
{
#ifdef CONFIG_MTRACE
  fprintf(mtrace_fp, "ifetch: ");
#endif
  return paddr_read(addr, len);
}

word_t vaddr_read(vaddr_t addr, int len)
{
  return paddr_read(addr, len);
}

void vaddr_write(vaddr_t addr, int len, word_t data)
{
  paddr_write(addr, len, data);
}
