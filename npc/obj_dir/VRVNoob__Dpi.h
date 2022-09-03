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
    // DPI import at /home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob/Verilog_Gen/DpiInst.v:3:30
    extern void inst_change(const svLogicVecVal* a);
    // DPI import at /home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob/Verilog_Gen/DpiNpc.v:2:30
    extern void npc_change(const svLogicVecVal* a);
    // DPI import at /home/jiexxpu/ysyx/ysyx-workbench/npc/playground/src/RVnpc/RVNoob/Ebreak.v:2:30
    extern void npc_ebreak();
    // DPI import at /home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob/Verilog_Gen/DpiPmem.v:12:30
    extern void pmem_read_dpi(long long raddr, long long* rdata);
    // DPI import at /home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob/Verilog_Gen/DpiPmem.v:14:30
    extern void pmem_write_dpi(long long waddr, long long wdata, char wmask);
    // DPI import at /home/jiexxpu/ysyx/ysyx-workbench/npc/playground/src/RVnpc/RVNoob/RF_read.v:1:30
    extern void set_gpr_ptr(const svOpenArrayHandle a);

#ifdef __cplusplus
}
#endif
