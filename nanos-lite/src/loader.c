#include <elf.h>
#include <fs.h>
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
  Elf_Ehdr elf_head;

  // 读取 head 到elf_head
  // ramdisk_read(&elf_head, 0, sizeof(Elf_Ehdr));
  int fd = fs_open(filename, 0, 0);
  fs_read(fd, &elf_head, sizeof(Elf_Ehdr));

  // 判断elf文件类型 machine
  assert(*(uint32_t *)elf_head.e_ident == 0x464c457f);
  // printf("%d\n",elf_head.e_machine);
  assert(elf_head.e_machine == EXPECT_TYPE);

  uintptr_t entry = 0;
  Elf_Phdr elf_seg;

  // uintptr_t vaddr_offset = elf_head.e_phoff + elf_head.e_phnum * elf_head.e_phentsize;
  // for (int i = 0; i < elf_head.e_phnum; i++) {
  //   ramdisk_read(&elf_seg, elf_head.e_phoff + i * elf_head.e_phentsize, sizeof(Elf_Phdr));
  //   if (elf_seg.p_type == PT_LOAD) {
  //     memcpy((void *)elf_seg.p_vaddr + vaddr_offset, elf_head.e_phoff + elf_head.e_phnum * elf_head.e_phentsize + (&ramdisk_start), elf_seg.p_filesz);
  //     memset((void *)(elf_seg.p_vaddr + vaddr_offset + elf_seg.p_filesz), 0, elf_seg.p_memsz - elf_seg.p_filesz);
  //   }
  // }
  fs_lseek(fd, elf_head.e_phoff, SEEK_CUR);

  for (int i = 0; i < elf_head.e_phnum; i++) {
    // ramdisk_read(&elf_seg, elf_head.e_phoff + i * elf_head.e_phentsize, sizeof(Elf_Phdr));
    fs_read(fd, &elf_seg, sizeof(Elf_Phdr));
    if (elf_seg.p_type == PT_LOAD) {
      // memcpy((void *)elf_seg.p_vaddr, elf_seg.p_offset + (&ramdisk_start), elf_seg.p_filesz);
      // memset((void *)(elf_seg.p_vaddr + elf_seg.p_filesz), 0, elf_seg.p_memsz - elf_seg.p_filesz);
      fs_lseek(fd, elf_seg.p_offset, SEEK_SET);
      fs_read(fd, (void *)elf_seg.p_vaddr, elf_seg.p_filesz);
      fs_read(fd, (void *)(elf_seg.p_vaddr + elf_seg.p_filesz), elf_seg.p_memsz - elf_seg.p_filesz);
    }
  }

  entry = elf_head.e_entry;
  // printf("%x\n", entry);
  return entry;
}

void naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %x", entry);
  ((void (*)())entry)();
}
