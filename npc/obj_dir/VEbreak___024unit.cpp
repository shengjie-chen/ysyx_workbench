// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VEbreak.h for the primary calling header

#include "VEbreak___024unit.h"
#include "VEbreak__Syms.h"

#include "verilated_dpi.h"

//==========

extern "C" void npc_ebreak();

VL_INLINE_OPT void VEbreak___024unit____Vdpiimwrap_npc_ebreak_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VEbreak___024unit____Vdpiimwrap_npc_ebreak_TOP____024unit\n"); );
    // Body
    npc_ebreak();
}

extern "C" void set_gpr_ptr(const svOpenArrayHandle a);

VL_INLINE_OPT void VEbreak___024unit____Vdpiimwrap_set_gpr_ptr__Vdpioc2_TOP____024unit(const VlUnpacked<QData/*63:0*/, 32> &a) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VEbreak___024unit____Vdpiimwrap_set_gpr_ptr__Vdpioc2_TOP____024unit\n"); );
    // Body
    static const int a__Vopenprops__ulims[2] = {31, 0};
    static const VerilatedVarProps a__Vopenprops(VLVT_UINT64, VLVD_IN, VerilatedVarProps::Packed(), 63, 0, VerilatedVarProps::Unpacked(), 1, a__Vopenprops__ulims);
    VerilatedDpiOpenVar a__Vopenarray (&a__Vopenprops, &a);
    set_gpr_ptr(&a__Vopenarray);
}
