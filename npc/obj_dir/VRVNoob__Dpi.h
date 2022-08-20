// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/jiexxpu/ysyx/ysyx-workbench/npc/playground/src/RVnpc/RVNoob/Ebreak.v:2:30
    extern void npc_ebreak();
    // DPI import at /home/jiexxpu/ysyx/ysyx-workbench/npc/playground/src/RVnpc/RVNoob/RF_read.v:1:30
    extern void set_gpr_ptr(const svOpenArrayHandle a);
    // DPI import at /home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob/Verilog_Gen/DpiInst.v:2:30
    extern void set_inst_ptr(const svLogicVecVal* a);

#ifdef __cplusplus
}
#endif
