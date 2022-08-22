#include "RVNoob.h"
#include "common.h"
#include "dlfcn.h"

extern CPU_state cpu_state;
extern NPCState npc_state;

char *diff_file = NULL;

enum { DIFFTEST_TO_DUT,
       DIFFTEST_TO_REF };

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

void refresh_gpr_pc()
{
  int i;
  for (i = 0; i < 32; i++) {
    cpu_state.gpr[i] = cpu_gpr[i];
  }
  cpu_state.pc = top->io_pc;
}

void init_difftest(char *ref_so_file, long img_size, int port, void *cpu)
{
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

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc)
{
  printf("error\n");

  for (int i = 0; i < 32; i++) {
    printf("error\n");
    word_t npc_gpr = *(cpu_state.gpr + i);
    printf("error\n");
    word_t ref_gpr = *(ref_r->gpr + i);
    if (npc_gpr != ref_gpr) {
      printf("error\n");

      return false;
    }
  }
  if (pc != ref_r->pc) {
    return false;
  }
  return true;
}
void isa_reg_display()
{
  printf("cpu.pc is " FMT_WORD "\n", cpu_state.pc);
  int i;
  for (i = 0; i < 32; i++) {
    printf("cpu.gpr[%d] is " FMT_WORD "\n", i, cpu_state.gpr[i]);
  }
}

void checkregs(CPU_state *ref, vaddr_t pc)
{
  if (!isa_difftest_checkregs(ref, pc)) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = pc;
    isa_reg_display();
  }
}

void difftest_step(vaddr_t pc, vaddr_t npc)
{
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

  // if (is_skip_ref) {
  //   // to skip the checking of an instruction, just copy the reg state to reference design
  //   ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
  //   is_skip_ref = false;
  //   return;
  // }

  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  refresh_gpr_pc();
  checkregs(&ref_r, pc);
}

