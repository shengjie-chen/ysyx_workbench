/*
 * @Author: Shengjie Chen chenshengjie1999@126.com
 * @Date: 2022-11-05 16:32:16
 * @LastEditors: Shengjie Chen chenshengjie1999@126.com
 * @LastEditTime: 2022-12-08 08:56:47
 * @FilePath: /npc/playground/src/RVnpc/RVNoob/difftest.c
 * @Description: difftest相关的变量与函数
 */
#include "RVNoob.h"
#include "VRVNoob.h"
#include "common.h"
#include "dlfcn.h"

extern CPU_state cpu_state;
extern NPCState npc_state;
extern uint64_t *cpu_gpr;
extern uint64_t *cpu_csr;
extern VRVNoob *top;

char *diff_file = NULL;

enum { DIFFTEST_TO_DUT,
       DIFFTEST_TO_REF };

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

/// @brief 从硬件那里更新仿真软件这边的cpu寄存器
void refresh_gpr_pc_csr() {
  int i;
  for (i = 0; i < 32; i++) {
    cpu_state.gpr[i] = cpu_gpr[i];
  }
#ifdef CONFIG_PIPELINE
  cpu_state.pc = top->io_diff_pc;
#else
  cpu_state.pc = top->io_pc;
#endif
  for (i = 0; i < CSR_NUM; i++) {
    cpu_state.csr[i] = cpu_csr[i];
  }
}

/// @brief 显式调用动态链接库,进行difftest初始化
/// @param ref_so_file 
/// @param img_size 
/// @param port 
/// @param cpu 
void init_difftest(char *ref_so_file, long img_size, int port, void *cpu) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(paddr_t, void *, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void *, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint64_t))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(cpu, DIFFTEST_TO_REF);
}

bool isa_difftest_checkregs(CPU_state *ref_r) {
  for (int i = 0; i < 32; i++) {
    if (cpu_state.gpr[i] != ref_r->gpr[i]) {
      printf("!!!!!!!\n");
      printf("cpu.gpr[%d] is " FMT_WORD "\n", i, cpu_state.gpr[i]);
      printf("ref.gpr[%d] is " FMT_WORD "\n", i, ref_r->gpr[i]);
      printf("!!!!!!!\n");
      return false;
    }
  }
  if (cpu_state.pc != ref_r->pc) {
    printf("!!!!!!!\n");
    printf("cpu.pc is " FMT_WORD "\n", cpu_state.pc);
    printf("ref.pc is " FMT_WORD "\n", ref_r->pc);
    printf("!!!!!!!\n");
    return false;
  }
  for (int i = 0; i < CSR_NUM; i++) {
    if (cpu_state.csr[i] != ref_r->csr[i]) {
      printf("!!!!!!!\n");
      printf("cpu.csr[%d] is " FMT_WORD "\n", i, cpu_state.csr[i]);
      printf("ref.csr[%d] is " FMT_WORD "\n", i, ref_r->csr[i]);
      printf("!!!!!!!\n");
      return false;
    }
  }
  return true;
}

void isa_reg_display(CPU_state *ref) {
  printf("cpu.pc is " FMT_WORD "\n", cpu_state.pc);
  printf("ref.pc is " FMT_WORD "\n", ref->pc);
  int i;
  for (i = 0; i < 32; i++) {
    printf("cpu.gpr[%d] is " FMT_WORD "\n", i, cpu_state.gpr[i]);
    printf("ref.gpr[%d] is " FMT_WORD "\n", i, ref->gpr[i]);
  }
  for (i = 0; i < CSR_NUM; i++) {
    printf("cpu.csr[%d] is " FMT_WORD "\n", i, cpu_state.csr[i]);
    printf("ref.csr[%d] is " FMT_WORD "\n", i, ref->csr[i]);
  }
}

void checkregs(CPU_state *ref, vaddr_t pc) {
  if (!isa_difftest_checkregs(ref)) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = pc;
    printf("diff test fail!!\n");
    printf("error inst is " FMT_WORD "\n", pc);
    isa_reg_display(ref);
  }
}

#ifdef CONFIG_PIPELINE
static int is_skip_ref_num = 0;
vaddr_t wb_pc = 0x80000000;
#else
static bool is_skip_ref = false;
#endif

void difftest_step(vaddr_t pc, vaddr_t npc) {
#ifdef CONFIG_PIPELINE
  CPU_state ref_r;
  if (top->io_diff_en) {
    if (is_skip_ref_num != 0) {
      // to skip the checking of an instruction, just copy the reg state to reference design
      refresh_gpr_pc_csr();                             // 更新状态
      ref_difftest_regcpy(&cpu_state, DIFFTEST_TO_REF); // 把状态拷贝到nemu
      is_skip_ref_num--;
      return;
    }
    refresh_gpr_pc_csr();

    ref_difftest_exec(1);
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

    checkregs(&ref_r, wb_pc);
    wb_pc = top->io_diff_pc;
  }

#else
  CPU_state ref_r;

  // if (skip_dut_nr_inst > 0) {
  //   ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
  //   if (ref_r.pc == npc) {
  //     skip_dut_nr_inst = 0;
  //     checkregs(&ref_r, npc);
  //     return;
  //   }
  //   skip_dut_nr_inst--;
  //   if (skip_dut_nr_inst == 0)
  //     panic("can not catch up with ref.pc = " FMT_WORD " at pc = " FMT_WORD, ref_r.pc, pc);
  //   return;
  // }

  if (is_skip_ref) {
    // to skip the checking of an instruction, just copy the reg state to reference design
    refresh_gpr_pc_csr();                             // 更新状态
    ref_difftest_regcpy(&cpu_state, DIFFTEST_TO_REF); // 把状态拷贝到nemu
    is_skip_ref = false;
    return;
  }

  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  refresh_gpr_pc_csr();
  checkregs(&ref_r, pc);
#endif
}

/// @brief 对外设进行读写时需要跳过difftest
/// @todo 因为读写发生在mem阶段，需要记录pc或者inst，等到这个指令执行到wb阶段，再进行跳过
void difftest_skip_ref() {
#ifdef CONFIG_PIPELINE
  is_skip_ref_num++;
#else
  is_skip_ref = true;
#endif
}