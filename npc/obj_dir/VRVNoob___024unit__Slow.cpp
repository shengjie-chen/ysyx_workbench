// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRVNoob.h for the primary calling header

#include "VRVNoob___024unit.h"
#include "VRVNoob__Syms.h"

#include "verilated_dpi.h"

//==========


void VRVNoob___024unit___ctor_var_reset(VRVNoob___024unit* vlSelf);

VRVNoob___024unit::VRVNoob___024unit(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VRVNoob___024unit___ctor_var_reset(this);
}

void VRVNoob___024unit::__Vconfigure(VRVNoob__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VRVNoob___024unit::~VRVNoob___024unit() {
}

void VRVNoob___024unit___ctor_var_reset(VRVNoob___024unit* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        VRVNoob___024unit___ctor_var_reset\n"); );
}
