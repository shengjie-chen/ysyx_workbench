/*
 * @Author: Shengjie Chen chenshengjie1999@126.com
 * @Date: 2022-12-07 22:51:47
 * @LastEditors: Shengjie Chen chenshengjie1999@126.com
 * @LastEditTime: 2022-12-08 12:05:04
 * @FilePath: /npc/playground/src/RVnpc/RVNoob/useddpi.c
 * @Description: 用到的dpi变量和函数集合
 */

/// @brief dpi函数用于读任意有效地址
/// @param raddr 
/// @param rdata 
extern "C" void pmem_read_dpi(long long raddr, long long *rdata) {
  if (raddr == RTC_ADDR) {
    struct timeval now;
    gettimeofday(&now, NULL);
    *rdata = now.tv_sec * 1000000 + now.tv_usec;
#ifdef CONFIG_MTRACE
    fprintf(mtrace_fp, "read  rtc ## addr: %llx", raddr & ~0x7ull);
    fprintf(mtrace_fp, " -> 0x%016llx \n", *rdata);
#endif
#ifdef CONFIG_DIFFTEST
    difftest_skip_ref();
#endif
    return;
  }

  if (raddr == KBD_ADDR) {
    i8042_data_io_handler();
    *rdata = i8042_data_port_base;
#ifdef CONFIG_MTRACE
    fprintf(mtrace_fp, "read  keyboard ## addr: %llx", raddr & ~0x7ull);
    fprintf(mtrace_fp, " -> 0x%08llx \n", *rdata);
#endif
#ifdef CONFIG_DIFFTEST
    difftest_skip_ref();
#endif
    return;
  }

  if (raddr == VGACTL_ADDR || raddr == (VGACTL_ADDR + 2)) {
    if (raddr == VGACTL_ADDR) {
      *rdata = vgactl_port_base;
    } else {
      *rdata = vgactl_port_base >> 16;
    }
#ifdef CONFIG_MTRACE
    fprintf(mtrace_fp, "read  vgactrl ## addr: %llx", raddr & ~0x7ull);
    fprintf(mtrace_fp, " -> 0x%08llx \n", *rdata);
#endif
#ifdef CONFIG_DIFFTEST
    difftest_skip_ref();
#endif
    return;
  }

  if (raddr >= FB_ADDR && raddr < (FB_ADDR + screen_size)) {
    *rdata = *(uint32_t *)((uint8_t *)vmem + raddr - FB_ADDR);
    // *rdata = *(uint32_t *)((uint8_t *)vmem + raddr - FB_ADDR);
#ifdef CONFIG_DIFFTEST
    difftest_skip_ref();
#endif
    return;
  }

  // 总是读取地址为`raddr & ~0x7ull`的8字节返回给`rdata`
  if (likely(in_pmem(raddr))) {
    *rdata = pmem_read(raddr & ~0x7ull, 8);
#ifdef CONFIG_MTRACE
    fprintf(mtrace_fp, "read  pmem ## addr: %llx", raddr & ~0x7ull);
    fprintf(mtrace_fp, " -> 0x%016llx \n", *rdata);
#endif
  }
}

/// @brief dpi函数用于写任意有效地址
/// @param waddr 
/// @param wdata 
/// @param wmask 
extern "C" void pmem_write_dpi(long long waddr, long long wdata, char wmask) {
  // 总是往地址为`waddr & ~0x7ull`的8字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  // printf("waddr is %016x\n",waddr);
  if (waddr == SERIAL_PORT) {
    printf("%c", (char)wdata);
#ifdef CONFIG_MTRACE
    fprintf(mtrace_fp, "write serial ## addr: %llx", waddr & ~0x7ull);
    fprintf(mtrace_fp, " -> 0x%016llx ", wdata);
    fprintf(mtrace_fp, " wmask-> 0x%02x \n", (uint8_t)wmask);
#endif
#ifdef CONFIG_DIFFTEST
    difftest_skip_ref();
#endif
    return;
  }

  if (waddr >= FB_ADDR && waddr < (FB_ADDR + screen_size)) {
    // printf("wmask = %x\n", wmask);
    assert((wmask == 0x0f) || (wmask == (char)0xf0));
    if (wmask == 0x0f) {
      *(uint32_t *)((uint8_t *)vmem + (waddr & ~0x7ull) - FB_ADDR) = wdata;
    } else if (wmask == (char)0xf0) {
      *(uint32_t *)((uint8_t *)vmem + (waddr & ~0x7ull) - FB_ADDR + 4) = wdata >> 32;
    }
#ifdef CONFIG_DIFFTEST
    difftest_skip_ref();
#endif
    return;
  }

  if (waddr == VGACTL_ADDR) {
    assert(wmask == (char)0xf0);
    vgactl_port_base_syn = wdata >> 32;
#ifdef CONFIG_DIFFTEST
    difftest_skip_ref();
#endif
    return;
  }

  if (waddr < CONFIG_MBASE || waddr >= (CONFIG_MBASE + CONFIG_MSIZE)) {
    printf("!!! out of bound. write addr:%llx\n", waddr);
  }

#ifdef CONFIG_MTRACE
  fprintf(mtrace_fp, "write pmem ## addr: %llx", waddr & ~0x7ull);
  fprintf(mtrace_fp, " -> 0x%016llx ", wdata);
  fprintf(mtrace_fp, " wmask-> 0x%02x \n", (uint8_t)wmask);
#endif
  for (int i = 0; i < 8; i++) {
    if ((wmask >> i) & 1 == 1) {
      pmem_write((waddr & ~0x7ull) + i, 1, wdata >> (8 * i));
    }
  }
}

/// @brief 获取cpu的指令，当前得到idu的指令
uint32_t cpu_inst;
extern "C" void inst_change(const svLogicVecVal *r) {
  cpu_inst = *(uint32_t *)(r);
  // printf("inst : %x\n", cpu_inst);
}

/// @brief 获取下一个pc值，即下一周期pc寄存器的值
uint32_t cpu_npc;
extern "C" void npc_change(const svLogicVecVal *r) {
  cpu_npc = *(vaddr_t *)(r);
}

void npc_ebreak() {
  npc_state.state = NPC_END;
  printf("!!!!!! npc ebreak !!!!!!\n");
}

// uint32_t *cpu_inst = NULL;
// extern "C" void set_inst_ptr(const svLogicVecVal *r)
//{
//   cpu_inst = (uint32_t *)(r);
// }

/// @brief 获取mem_reg.out.pc
uint32_t mem_pc;
extern "C" void mem_pc_change(const svLogicVecVal *r) {
  mem_pc = *(uint32_t *)(r);
}

