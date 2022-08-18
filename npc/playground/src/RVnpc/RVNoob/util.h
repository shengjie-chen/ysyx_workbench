#ifndef __UTILS_H__
#define __UTILS_H__

typedef struct {
  int state;
  // vaddr_t halt_pc;
  // uint32_t halt_ret;
} NPCState;

enum { NPC_RUNNING,
       NPC_STOP,
       NPC_END /*, NPC_ABORT, NPC_QUIT*/ };

#endif