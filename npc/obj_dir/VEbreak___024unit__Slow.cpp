// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VEbreak.h for the primary calling header

#include "VEbreak___024unit.h"
#include "VEbreak__Syms.h"

#include "verilated_dpi.h"

//==========


void VEbreak___024unit___ctor_var_reset(VEbreak___024unit* vlSelf);

VEbreak___024unit::VEbreak___024unit(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VEbreak___024unit___ctor_var_reset(this);
}

void VEbreak___024unit::__Vconfigure(VEbreak__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VEbreak___024unit::~VEbreak___024unit() {
}

void VEbreak___024unit___ctor_var_reset(VEbreak___024unit* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VEbreak___024unit___ctor_var_reset\n"); );
}
