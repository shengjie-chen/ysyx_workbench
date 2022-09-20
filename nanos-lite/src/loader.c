#include <elf.h>
#include <proc.h>

#ifdef __LP64__
#define Elf_Ehdr Elf64_Ehdr
#define Elf_Phdr Elf64_Phdr
#else
#define Elf_Ehdr Elf32_Ehdr
#define Elf_Phdr Elf32_Phdr
#endif

#if defined(__ISA_AM_NATIVE__)
#define EXPECT_TYPE EM_X86_64
#elif defined(__ISA_X86__)
#define EXPECT_TYPE EM_X86_64
#elif defined(__ISA_RISCV32__) || defined(__ISA_RISCV64__)
#define EXPECT_TYPE EM_RISCV
#else
#error Unsupported ISA
#endif
extern uint8_t ramdisk_start;

extern size_t ramdisk_read(void *buf, size_t offset, size_t len);

static uintptr_t loader(PCB *pcb, const char *filename) {
  Elf_Ehdr *elf_head;

  // 读取 head 到elf_head
  ramdisk_read(&elf_head, 0, sizeof(Elf_Ehdr));
  // 判断elf文件类型 machine
    // 判断elf文件类型
  if (elf_head->e_ident[0] != 0x7F ||
      elf_head->e_ident[1] != 'E' ||
      elf_head->e_ident[2] != 'L' ||
      elf_head->e_ident[3] != 'F') {
    panic("Not a ELF file\n");
  }
  // assert(*(uint32_t *)elf_head->e_ident == 0x464c457f);
  assert(elf_head->e_machine == EXPECT_TYPE);

  uintptr_t entry = 0;
  Elf_Phdr *elf_seg;
  int j = 0;
  for (int i = 0; i < elf_head->e_phnum; i++) {
    ramdisk_read(&elf_seg, elf_head->e_phoff + i * elf_head->e_phentsize, sizeof(Elf_Phdr));
    if (elf_seg->p_type == PT_LOAD) {
      if (j == 0) {
        entry = elf_seg->p_vaddr;
        j++;
      }
      memcpy((void *)elf_seg->p_vaddr, elf_head->e_phoff + (&ramdisk_start), elf_seg->p_filesz);
      memset((void *)(elf_seg->p_vaddr + elf_seg->p_filesz), 0, elf_seg->p_memsz - elf_seg->p_filesz);
    }
  }
  return entry;
}

void naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void (*)())entry)();
}
