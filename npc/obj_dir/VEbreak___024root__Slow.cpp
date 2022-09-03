// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VEbreak.h for the primary calling header

#include "VEbreak___024root.h"
#include "VEbreak__Syms.h"

#include "verilated_dpi.h"

//==========


void VEbreak___024root___ctor_var_reset(VEbreak___024root* vlSelf);

VEbreak___024root::VEbreak___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VEbreak___024root___ctor_var_reset(this);
}

void VEbreak___024root::__Vconfigure(VEbreak__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VEbreak___024root::~VEbreak___024root() {
}

void VEbreak___024unit____Vdpiimwrap_set_gpr_ptr__Vdpioc2_TOP____024unit(const VlUnpacked<QData/*63:0*/, 32> &a);

void VEbreak___024root___initial__TOP__4(VEbreak___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEbreak___024root___initial__TOP__4\n"); );
    // Body
    VEbreak___024unit____Vdpiimwrap_set_gpr_ptr__Vdpioc2_TOP____024unit(vlSelf->RF_read__DOT__rf);
}

void VEbreak___024root___eval_initial(VEbreak___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEbreak___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    VEbreak___024root___initial__TOP__4(vlSelf);
}

void VEbreak___024root___combo__TOP__2(VEbreak___024root* vlSelf);

void VEbreak___024root___eval_settle(VEbreak___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEbreak___024root___eval_settle\n"); );
    // Body
    VEbreak___024root___combo__TOP__2(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

void VEbreak___024root___final(VEbreak___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEbreak___024root___final\n"); );
}

void VEbreak___024root___ctor_var_reset(VEbreak___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEbreak___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->a0 = VL_RAND_RESET_Q(64);
    vlSelf->ebreak = VL_RAND_RESET_I(1);
    vlSelf->rf_0 = VL_RAND_RESET_Q(64);
    vlSelf->rf_1 = VL_RAND_RESET_Q(64);
    vlSelf->rf_2 = VL_RAND_RESET_Q(64);
    vlSelf->rf_3 = VL_RAND_RESET_Q(64);
    vlSelf->rf_4 = VL_RAND_RESET_Q(64);
    vlSelf->rf_5 = VL_RAND_RESET_Q(64);
    vlSelf->rf_6 = VL_RAND_RESET_Q(64);
    vlSelf->rf_7 = VL_RAND_RESET_Q(64);
    vlSelf->rf_8 = VL_RAND_RESET_Q(64);
    vlSelf->rf_9 = VL_RAND_RESET_Q(64);
    vlSelf->rf_10 = VL_RAND_RESET_Q(64);
    vlSelf->rf_11 = VL_RAND_RESET_Q(64);
    vlSelf->rf_12 = VL_RAND_RESET_Q(64);
    vlSelf->rf_13 = VL_RAND_RESET_Q(64);
    vlSelf->rf_14 = VL_RAND_RESET_Q(64);
    vlSelf->rf_15 = VL_RAND_RESET_Q(64);
    vlSelf->rf_16 = VL_RAND_RESET_Q(64);
    vlSelf->rf_17 = VL_RAND_RESET_Q(64);
    vlSelf->rf_18 = VL_RAND_RESET_Q(64);
    vlSelf->rf_19 = VL_RAND_RESET_Q(64);
    vlSelf->rf_20 = VL_RAND_RESET_Q(64);
    vlSelf->rf_21 = VL_RAND_RESET_Q(64);
    vlSelf->rf_22 = VL_RAND_RESET_Q(64);
    vlSelf->rf_23 = VL_RAND_RESET_Q(64);
    vlSelf->rf_24 = VL_RAND_RESET_Q(64);
    vlSelf->rf_25 = VL_RAND_RESET_Q(64);
    vlSelf->rf_26 = VL_RAND_RESET_Q(64);
    vlSelf->rf_27 = VL_RAND_RESET_Q(64);
    vlSelf->rf_28 = VL_RAND_RESET_Q(64);
    vlSelf->rf_29 = VL_RAND_RESET_Q(64);
    vlSelf->rf_30 = VL_RAND_RESET_Q(64);
    vlSelf->rf_31 = VL_RAND_RESET_Q(64);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->RF_read__DOT__rf[__Vi0] = VL_RAND_RESET_Q(64);
    }
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
