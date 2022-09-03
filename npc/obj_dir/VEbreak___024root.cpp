// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VEbreak.h for the primary calling header

#include "VEbreak___024root.h"
#include "VEbreak__Syms.h"

#include "verilated_dpi.h"

//==========

void VEbreak___024unit____Vdpiimwrap_npc_ebreak_TOP____024unit();

VL_INLINE_OPT void VEbreak___024root___sequent__TOP__1(VEbreak___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEbreak___024root___sequent__TOP__1\n"); );
    // Body
    if ((0x100073U == vlSelf->inst)) {
        if ((0ULL == vlSelf->a0)) {
            VL_WRITEF("!!!!  HIT GOOD TRAP !!!!\n");
        } else {
            VL_WRITEF("!!!!  HIT BAD TRAP !!!!\n");
        }
        vlSelf->ebreak = 1U;
        VEbreak___024unit____Vdpiimwrap_npc_ebreak_TOP____024unit();
    } else {
        vlSelf->ebreak = 0U;
    }
}

VL_INLINE_OPT void VEbreak___024root___combo__TOP__2(VEbreak___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEbreak___024root___combo__TOP__2\n"); );
    // Body
    vlSelf->RF_read__DOT__rf[0U] = vlSelf->rf_0;
    vlSelf->RF_read__DOT__rf[1U] = vlSelf->rf_1;
    vlSelf->RF_read__DOT__rf[2U] = vlSelf->rf_2;
    vlSelf->RF_read__DOT__rf[3U] = vlSelf->rf_3;
    vlSelf->RF_read__DOT__rf[4U] = vlSelf->rf_4;
    vlSelf->RF_read__DOT__rf[5U] = vlSelf->rf_5;
    vlSelf->RF_read__DOT__rf[6U] = vlSelf->rf_6;
    vlSelf->RF_read__DOT__rf[7U] = vlSelf->rf_7;
    vlSelf->RF_read__DOT__rf[8U] = vlSelf->rf_8;
    vlSelf->RF_read__DOT__rf[9U] = vlSelf->rf_9;
    vlSelf->RF_read__DOT__rf[0xaU] = vlSelf->rf_10;
    vlSelf->RF_read__DOT__rf[0xbU] = vlSelf->rf_11;
    vlSelf->RF_read__DOT__rf[0xcU] = vlSelf->rf_12;
    vlSelf->RF_read__DOT__rf[0xdU] = vlSelf->rf_13;
    vlSelf->RF_read__DOT__rf[0xeU] = vlSelf->rf_14;
    vlSelf->RF_read__DOT__rf[0xfU] = vlSelf->rf_15;
    vlSelf->RF_read__DOT__rf[0x10U] = vlSelf->rf_16;
    vlSelf->RF_read__DOT__rf[0x11U] = vlSelf->rf_17;
    vlSelf->RF_read__DOT__rf[0x12U] = vlSelf->rf_18;
    vlSelf->RF_read__DOT__rf[0x13U] = vlSelf->rf_19;
    vlSelf->RF_read__DOT__rf[0x14U] = vlSelf->rf_20;
    vlSelf->RF_read__DOT__rf[0x15U] = vlSelf->rf_21;
    vlSelf->RF_read__DOT__rf[0x16U] = vlSelf->rf_22;
    vlSelf->RF_read__DOT__rf[0x17U] = vlSelf->rf_23;
    vlSelf->RF_read__DOT__rf[0x18U] = vlSelf->rf_24;
    vlSelf->RF_read__DOT__rf[0x19U] = vlSelf->rf_25;
    vlSelf->RF_read__DOT__rf[0x1aU] = vlSelf->rf_26;
    vlSelf->RF_read__DOT__rf[0x1bU] = vlSelf->rf_27;
    vlSelf->RF_read__DOT__rf[0x1cU] = vlSelf->rf_28;
    vlSelf->RF_read__DOT__rf[0x1dU] = vlSelf->rf_29;
    vlSelf->RF_read__DOT__rf[0x1eU] = vlSelf->rf_30;
    vlSelf->RF_read__DOT__rf[0x1fU] = vlSelf->rf_31;
}

void VEbreak___024root___eval(VEbreak___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEbreak___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        VEbreak___024root___sequent__TOP__1(vlSelf);
    }
    VEbreak___024root___combo__TOP__2(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData VEbreak___024root___change_request_1(VEbreak___024root* vlSelf);

VL_INLINE_OPT QData VEbreak___024root___change_request(VEbreak___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEbreak___024root___change_request\n"); );
    // Body
    return (VEbreak___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VEbreak___024root___change_request_1(VEbreak___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEbreak___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VEbreak___024root___eval_debug_assertions(VEbreak___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VEbreak___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
