#include <common.h>
#include <elf.h>

extern uint64_t g_nr_guest_inst;
FILE *log_fp = NULL;

#ifdef CONFIG_MTRACE
char *mtrace_file = "/home/jiexxpu/ysyx/ysyx-workbench/nemu/build/nemu-mtrace-log.txt";
FILE *mtrace_fp = NULL;
#endif

#ifdef CONFIG_DTRACE
char *dtrace_file = "/home/jiexxpu/ysyx/ysyx-workbench/nemu/build/nemu-dtrace-log.txt";
FILE *dtrace_fp = NULL;
#endif

#ifdef CONFIG_FTRACE
FILE *ftrace_fp = NULL;
char *ftrace_file = "/home/jiexxpu/ysyx/ysyx-workbench/nemu/build/nemu-ftrace-log.txt";
int ftrace_depth = 0;
int ftrace_func_num;
#define MAX_FUNC_NUM 100
char symname[MAX_FUNC_NUM][30];
vaddr_t symaddr[MAX_FUNC_NUM];
vaddr_t symaddr_end[MAX_FUNC_NUM];

void init_ftrace(const char *elf_file)
{
  FILE *fp = fopen(elf_file, "r");
  // if (NULL == fp) {
  //   printf("fail to open the elf file");
  //   exit(0);
  // }
  Assert(fp, "Can not open '%s'", elf_file);
  ftrace_fp = fopen(ftrace_file, "w");

  // 解析head
  Elf64_Ehdr elf_head;
  int a;

  // 读取 head 到elf_head
  a = fread(&elf_head, sizeof(Elf64_Ehdr), 1, fp); // fread参数1：读取内容存储地址，参数2：读取内容大小，参数3：读取次数，参数4：文件读取引擎
  if (0 == a) {
    printf("fail to read head\n");
    exit(0);
  }

  // 判断elf文件类型
  if (elf_head.e_ident[0] != 0x7F ||
      elf_head.e_ident[1] != 'E' ||
      elf_head.e_ident[2] != 'L' ||
      elf_head.e_ident[3] != 'F') {
    printf("Not a ELF file\n");
    exit(0);
  }

  // 解析section 分配内存 section * 数量
  Elf64_Shdr *shdr = (Elf64_Shdr *)malloc(sizeof(Elf64_Shdr) * elf_head.e_shnum);
  if (NULL == shdr) {
    printf("shdr malloc failed\n");
    exit(0);
  }

  // 设置fp偏移量 offset，e_shoff含义
  a = fseek(fp, elf_head.e_shoff, SEEK_SET); // fseek调整指针的位置，采用参考位置+偏移量
  if (0 != a) {
    printf("\nfaile to fseek\n");
    exit(0);
  }

  // 读取section 到 shdr, 大小为shdr * 数量
  a = fread(shdr, sizeof(Elf64_Shdr) * elf_head.e_shnum, 1, fp);
  if (0 == a) {
    printf("\nfail to read section\n");
    exit(0);
  }

  // 重置指针位置到文件流开头
  rewind(fp);

  // 将fp指针移到 字符串表偏移位置处
  fseek(fp, shdr[elf_head.e_shstrndx].sh_offset, SEEK_SET);

  // 第e_shstrndx项是字符串表 定义 字节 长度 char类型 数组
  char shstrtab[shdr[elf_head.e_shstrndx].sh_size];
  char *temp = shstrtab;

  // 读取内容
  a = fread(shstrtab, shdr[elf_head.e_shstrndx].sh_size, 1, fp);
  if (0 == a) {
    printf("\nfaile to read\n");
  }

  // 遍历  strtab
  uint8_t *strtab_data = NULL;
  for (int i = 0; i < elf_head.e_shnum; i++) {
    temp = shstrtab;
    temp = temp + shdr[i].sh_name;
    if (strcmp(temp, ".strtab") != 0)
      continue; //该section名称
    strtab_data = (uint8_t *)malloc(sizeof(uint8_t) * shdr[i].sh_size);
    // 依据此段在文件中的偏移读取出
    fseek(fp, shdr[i].sh_offset, SEEK_SET);
    a = fread(strtab_data, sizeof(uint8_t) * shdr[i].sh_size, 1, fp);
  }

  /******************************************************
    symtab
  ******************************************************/

  // 遍历  symtab
  int i;
  for (i = 0; i < elf_head.e_shnum; i++) {
    temp = shstrtab;
    temp = temp + shdr[i].sh_name;
    if (strcmp(temp, ".symtab") != 0)
      continue; //该section名称
    else
      break;
  }
  Elf64_Sym *symtab = (Elf64_Sym *)malloc(shdr[i].sh_size);
  if (NULL == symtab) {
    printf("symtab malloc failed\n");
    exit(0);
  }
  // 设置fp偏移量 offset，e_shoff含义
  a = fseek(fp, shdr[i].sh_offset, SEEK_SET); // fseek调整指针的位置，采用参考位置+偏移量
  if (0 != a) {
    printf("\nfaile to fseek\n");
    exit(0);
  }
  // 读取section 到 shdr, 大小为shdr * 数量
  a = fread(symtab, shdr[i].sh_size, 1, fp);
  if (0 == a) {
    printf("\nfail to read symtab\n");
    exit(0);
  }
  int symnum = shdr[i].sh_size / sizeof(Elf64_Sym);
  int n = 0;
  int j;
  for (j = 0; j < symnum; j++) {
    if (ELF64_ST_TYPE(symtab[j].st_info) == STT_FUNC) {
      if (n > MAX_FUNC_NUM) {
        panic("ftrace : program have too many function, you have to increase MAX_FUNC_NUM!!");
      }
      strcpy(symname[n], (char *)(strtab_data + symtab[j].st_name));
      // symname[n] = (char *)(strtab_data + symtab[j].st_name);
      symaddr[n] = symtab[j].st_value;
      symaddr_end[n] = symtab[j].st_value + symtab[j].st_size;
      // printf("%s : %lx\n", symname[n], symaddr[n]);
      n++;
    }
  }
  ftrace_func_num = n;
  free(shdr);
  free(strtab_data);
  free(symtab);
}
#endif

void init_log(const char *log_file)
{
  log_fp = stdout;
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open '%s'", log_file);
    log_fp = fp;
  }
  Log("Log is written to %s", log_file ? log_file : "stdout");
#ifdef CONFIG_MTRACE
  mtrace_fp = fopen(mtrace_file, "w");
#endif
#ifdef CONFIG_DTRACE
  dtrace_fp = fopen(dtrace_file, "w");
#endif
}

bool log_enable()
{
  return MUXDEF(CONFIG_TRACE, (g_nr_guest_inst >= CONFIG_TRACE_START) && (g_nr_guest_inst <= CONFIG_TRACE_END), false);
}
