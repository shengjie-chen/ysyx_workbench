// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRVNoob.h for the primary calling header

#include "VRVNoob___024root.h"
#include "VRVNoob__Syms.h"

#include "verilated_dpi.h"

//==========


void VRVNoob___024root___ctor_var_reset(VRVNoob___024root* vlSelf);

VRVNoob___024root::VRVNoob___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VRVNoob___024root___ctor_var_reset(this);
}

void VRVNoob___024root::__Vconfigure(VRVNoob__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VRVNoob___024root::~VRVNoob___024root() {
}

void VRVNoob___024unit____Vdpiimwrap_inst_change_TOP____024unit(IData/*31:0*/ a);

void VRVNoob___024root___settle__TOP__2(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___settle__TOP__2\n"); );
    // Variables
    QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_44;
    // Body
    VRVNoob___024unit____Vdpiimwrap_inst_change_TOP____024unit(vlSelf->io_inst);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_addi = (IData)(
                                                      (0x13U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__immU_lo_lo = ((0x80U 
                                                  & (vlSelf->io_inst 
                                                     >> 0x18U)) 
                                                 | ((0x40U 
                                                     & (vlSelf->io_inst 
                                                        >> 0x19U)) 
                                                    | ((0x20U 
                                                        & (vlSelf->io_inst 
                                                           >> 0x1aU)) 
                                                       | ((0x10U 
                                                           & (vlSelf->io_inst 
                                                              >> 0x1bU)) 
                                                          | ((8U 
                                                              & (vlSelf->io_inst 
                                                                 >> 0x1cU)) 
                                                             | ((4U 
                                                                 & (vlSelf->io_inst 
                                                                    >> 0x1dU)) 
                                                                | ((2U 
                                                                    & (vlSelf->io_inst 
                                                                       >> 0x1eU)) 
                                                                   | (vlSelf->io_inst 
                                                                      >> 0x1fU))))))));
    vlSelf->RVNoob__DOT__idu__DOT__immJ_lo_lo_lo = 
        ((0x10U & (vlSelf->io_inst >> 0x1bU)) | ((8U 
                                                  & (vlSelf->io_inst 
                                                     >> 0x1cU)) 
                                                 | ((4U 
                                                     & (vlSelf->io_inst 
                                                        >> 0x1dU)) 
                                                    | ((2U 
                                                        & (vlSelf->io_inst 
                                                           >> 0x1eU)) 
                                                       | (vlSelf->io_inst 
                                                          >> 0x1fU)))));
    vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo = 
        ((0x20U & (vlSelf->io_inst >> 0x1aU)) | ((0x10U 
                                                  & (vlSelf->io_inst 
                                                     >> 0x1bU)) 
                                                 | ((8U 
                                                     & (vlSelf->io_inst 
                                                        >> 0x1cU)) 
                                                    | ((4U 
                                                        & (vlSelf->io_inst 
                                                           >> 0x1dU)) 
                                                       | ((2U 
                                                           & (vlSelf->io_inst 
                                                              >> 0x1eU)) 
                                                          | (vlSelf->io_inst 
                                                             >> 0x1fU))))));
    vlSelf->io_ebreak = vlSelf->RVNoob__DOT__U_ebreak_ebreak;
    vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr = (IData)(
                                                      (0x67U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__snpc = (4ULL + vlSelf->RVNoob__DOT__pc);
    vlSelf->io_pc = vlSelf->RVNoob__DOT__pc;
    if (vlSelf->reset) {
        vlSelf->RVNoob__DOT__rf__DOT___GEN_0 = 1ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_1 = 2ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_2 = 3ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_3 = 4ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_4 = 5ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_5 = 6ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_6 = 7ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_7 = 8ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_8 = 9ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_10 = 0xbULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_11 = 0xcULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_12 = 0xdULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_13 = 0xeULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_14 = 0xfULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_15 = 0x10ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_16 = 0x11ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_17 = 0x12ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_18 = 0x13ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_19 = 0x14ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_20 = 0x15ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_21 = 0x16ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_22 = 0x17ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_23 = 0x18ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_24 = 0x19ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_25 = 0x1aULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_26 = 0x1bULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_27 = 0x1cULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_28 = 0x1dULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_29 = 0x1eULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_30 = 0x1fULL;
    } else {
        vlSelf->RVNoob__DOT__rf__DOT___GEN_0 = vlSelf->RVNoob__DOT__rf__DOT__rf_1;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_1 = vlSelf->RVNoob__DOT__rf__DOT__rf_2;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_2 = vlSelf->RVNoob__DOT__rf__DOT__rf_3;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_3 = vlSelf->RVNoob__DOT__rf__DOT__rf_4;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_4 = vlSelf->RVNoob__DOT__rf__DOT__rf_5;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_5 = vlSelf->RVNoob__DOT__rf__DOT__rf_6;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_6 = vlSelf->RVNoob__DOT__rf__DOT__rf_7;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_7 = vlSelf->RVNoob__DOT__rf__DOT__rf_8;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_8 = vlSelf->RVNoob__DOT__rf__DOT__rf_9;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_10 = vlSelf->RVNoob__DOT__rf__DOT__rf_11;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_11 = vlSelf->RVNoob__DOT__rf__DOT__rf_12;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_12 = vlSelf->RVNoob__DOT__rf__DOT__rf_13;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_13 = vlSelf->RVNoob__DOT__rf__DOT__rf_14;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_14 = vlSelf->RVNoob__DOT__rf__DOT__rf_15;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_15 = vlSelf->RVNoob__DOT__rf__DOT__rf_16;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_16 = vlSelf->RVNoob__DOT__rf__DOT__rf_17;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_17 = vlSelf->RVNoob__DOT__rf__DOT__rf_18;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_18 = vlSelf->RVNoob__DOT__rf__DOT__rf_19;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_19 = vlSelf->RVNoob__DOT__rf__DOT__rf_20;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_20 = vlSelf->RVNoob__DOT__rf__DOT__rf_21;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_21 = vlSelf->RVNoob__DOT__rf__DOT__rf_22;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_22 = vlSelf->RVNoob__DOT__rf__DOT__rf_23;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_23 = vlSelf->RVNoob__DOT__rf__DOT__rf_24;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_24 = vlSelf->RVNoob__DOT__rf__DOT__rf_25;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_25 = vlSelf->RVNoob__DOT__rf__DOT__rf_26;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_26 = vlSelf->RVNoob__DOT__rf__DOT__rf_27;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_27 = vlSelf->RVNoob__DOT__rf__DOT__rf_28;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_28 = vlSelf->RVNoob__DOT__rf__DOT__rf_29;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_29 = vlSelf->RVNoob__DOT__rf__DOT__rf_30;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_30 = vlSelf->RVNoob__DOT__rf__DOT__rf_31;
    }
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_0;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[1U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_1;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[2U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_2;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[3U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_3;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[4U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_4;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[5U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_5;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[6U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_6;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[7U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_7;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[8U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_8;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[9U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_9;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0xbU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_11;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0xcU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_12;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0xdU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_13;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0xeU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_14;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0xfU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_15;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x10U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_16;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x11U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_17;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x12U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_18;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x13U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_19;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x14U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_20;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x15U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_21;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x16U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_22;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x17U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_23;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x18U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_24;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x19U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_25;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x1aU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_26;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x1bU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_27;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x1cU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_28;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x1dU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_29;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x1eU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_30;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x1fU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_31;
    vlSelf->RVNoob__DOT__rf__DOT___GEN_9 = ((IData)(vlSelf->reset)
                                             ? 0xaULL
                                             : vlSelf->RVNoob__DOT__rf__DOT__rf_10);
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0xaU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_10;
    RVNoob__DOT__rf__DOT___GEN_44 = ((0xdU == (0x1fU 
                                               & (vlSelf->io_inst 
                                                  >> 0xfU)))
                                      ? vlSelf->RVNoob__DOT__rf__DOT__rf_13
                                      : ((0xcU == (0x1fU 
                                                   & (vlSelf->io_inst 
                                                      >> 0xfU)))
                                          ? vlSelf->RVNoob__DOT__rf__DOT__rf_12
                                          : ((0xbU 
                                              == (0x1fU 
                                                  & (vlSelf->io_inst 
                                                     >> 0xfU)))
                                              ? vlSelf->RVNoob__DOT__rf__DOT__rf_11
                                              : ((0xaU 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->io_inst 
                                                      >> 0xfU)))
                                                  ? vlSelf->RVNoob__DOT__rf__DOT__rf_10
                                                  : 
                                                 ((9U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->io_inst 
                                                       >> 0xfU)))
                                                   ? vlSelf->RVNoob__DOT__rf__DOT__rf_9
                                                   : 
                                                  ((8U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->io_inst 
                                                        >> 0xfU)))
                                                    ? vlSelf->RVNoob__DOT__rf__DOT__rf_8
                                                    : 
                                                   ((7U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->io_inst 
                                                         >> 0xfU)))
                                                     ? vlSelf->RVNoob__DOT__rf__DOT__rf_7
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->io_inst 
                                                          >> 0xfU)))
                                                      ? vlSelf->RVNoob__DOT__rf__DOT__rf_6
                                                      : 
                                                     ((5U 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelf->io_inst 
                                                           >> 0xfU)))
                                                       ? vlSelf->RVNoob__DOT__rf__DOT__rf_5
                                                       : 
                                                      ((4U 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->io_inst 
                                                            >> 0xfU)))
                                                        ? vlSelf->RVNoob__DOT__rf__DOT__rf_4
                                                        : 
                                                       ((3U 
                                                         == 
                                                         (0x1fU 
                                                          & (vlSelf->io_inst 
                                                             >> 0xfU)))
                                                         ? vlSelf->RVNoob__DOT__rf__DOT__rf_3
                                                         : 
                                                        ((2U 
                                                          == 
                                                          (0x1fU 
                                                           & (vlSelf->io_inst 
                                                              >> 0xfU)))
                                                          ? vlSelf->RVNoob__DOT__rf__DOT__rf_2
                                                          : 
                                                         ((1U 
                                                           == 
                                                           (0x1fU 
                                                            & (vlSelf->io_inst 
                                                               >> 0xfU)))
                                                           ? vlSelf->RVNoob__DOT__rf__DOT__rf_1
                                                           : vlSelf->RVNoob__DOT__rf__DOT__rf_0)))))))))))));
    vlSelf->RVNoob__DOT__idu__DOT___io_imm_T_1 = ((
                                                   (0x17U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->io_inst)) 
                                                   | (0x37U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->io_inst)))
                                                   ? 
                                                  (((QData)((IData)(
                                                                    ((0x80000000U 
                                                                      & vlSelf->io_inst) 
                                                                     | ((0x40000000U 
                                                                         & (vlSelf->io_inst 
                                                                            >> 1U)) 
                                                                        | ((0x20000000U 
                                                                            & (vlSelf->io_inst 
                                                                               >> 2U)) 
                                                                           | ((0x10000000U 
                                                                               & (vlSelf->io_inst 
                                                                                >> 3U)) 
                                                                              | ((0x8000000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 4U)) 
                                                                                | ((0x4000000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 5U)) 
                                                                                | ((0x2000000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 6U)) 
                                                                                | ((0x1000000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 7U)) 
                                                                                | (((IData)(vlSelf->RVNoob__DOT__idu__DOT__immU_lo_lo) 
                                                                                << 0x10U) 
                                                                                | ((0x8000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x10U)) 
                                                                                | ((0x4000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x11U)) 
                                                                                | ((0x2000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x12U)) 
                                                                                | ((0x1000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x13U)) 
                                                                                | ((0x800U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x14U)) 
                                                                                | ((0x400U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x15U)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x16U)) 
                                                                                | ((0x100U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x17U)) 
                                                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immU_lo_lo)))))))))))))))))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     (0xfffff000U 
                                                                      & vlSelf->io_inst))))
                                                   : 0ULL);
    vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1 = (
                                                   ((QData)((IData)(
                                                                    (vlSelf->io_inst 
                                                                     >> 0x1fU))) 
                                                    << 0x2bU) 
                                                   | (((QData)((IData)(
                                                                       (vlSelf->io_inst 
                                                                        >> 0x1fU))) 
                                                       << 0x2aU) 
                                                      | (((QData)((IData)(
                                                                          (vlSelf->io_inst 
                                                                           >> 0x1fU))) 
                                                          << 0x29U) 
                                                         | (((QData)((IData)(
                                                                             (vlSelf->io_inst 
                                                                              >> 0x1fU))) 
                                                             << 0x28U) 
                                                            | (((QData)((IData)(
                                                                                (vlSelf->io_inst 
                                                                                >> 0x1fU))) 
                                                                << 0x27U) 
                                                               | (((QData)((IData)(
                                                                                (vlSelf->io_inst 
                                                                                >> 0x1fU))) 
                                                                   << 0x26U) 
                                                                  | (((QData)((IData)(vlSelf->RVNoob__DOT__idu__DOT__immJ_lo_lo_lo)) 
                                                                      << 0x21U) 
                                                                     | (((QData)((IData)(
                                                                                ((0x80000000U 
                                                                                & vlSelf->io_inst) 
                                                                                | ((0x40000000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 1U)) 
                                                                                | ((0x20000000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 2U)) 
                                                                                | ((0x10000000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 3U)) 
                                                                                | ((0x8000000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 4U)) 
                                                                                | ((0x4000000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 5U)) 
                                                                                | (((IData)(vlSelf->RVNoob__DOT__idu__DOT__immJ_lo_lo_lo) 
                                                                                << 0x15U) 
                                                                                | ((0x100000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0xbU)) 
                                                                                | ((0x80000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0xcU)) 
                                                                                | ((0x40000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0xdU)) 
                                                                                | ((0x20000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0xeU)) 
                                                                                | ((0x10000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0xfU)) 
                                                                                | ((0x8000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x10U)) 
                                                                                | (((IData)(vlSelf->RVNoob__DOT__idu__DOT__immJ_lo_lo_lo) 
                                                                                << 0xaU) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x16U)) 
                                                                                | ((0x100U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x17U)) 
                                                                                | ((0x80U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x18U)) 
                                                                                | ((0x40U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x19U)) 
                                                                                | ((0x20U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x1aU)) 
                                                                                | ((0x10U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x1bU)) 
                                                                                | ((8U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x1cU)) 
                                                                                | ((4U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x1dU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0x1eU)) 
                                                                                | (vlSelf->io_inst 
                                                                                >> 0x1fU)))))))))))))))))))))))))) 
                                                                         << 1U) 
                                                                        | (QData)((IData)(
                                                                                (vlSelf->io_inst 
                                                                                >> 0x1fU)))))))))));
    vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo = ((0x1000U 
                                                  & (vlSelf->io_inst 
                                                     >> 0x13U)) 
                                                 | ((0x800U 
                                                     & (vlSelf->io_inst 
                                                        >> 0x14U)) 
                                                    | ((0x400U 
                                                        & (vlSelf->io_inst 
                                                           >> 0x15U)) 
                                                       | ((0x200U 
                                                           & (vlSelf->io_inst 
                                                              >> 0x16U)) 
                                                          | ((0x100U 
                                                              & (vlSelf->io_inst 
                                                                 >> 0x17U)) 
                                                             | ((0x80U 
                                                                 & (vlSelf->io_inst 
                                                                    >> 0x18U)) 
                                                                | ((0x40U 
                                                                    & (vlSelf->io_inst 
                                                                       >> 0x19U)) 
                                                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo))))))));
    vlSelf->RVNoob__DOT__idu_io_wen = (((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                          | (0x17U 
                                             == (0x7fU 
                                                 & vlSelf->io_inst))) 
                                         | (0x37U == 
                                            (0x7fU 
                                             & vlSelf->io_inst))) 
                                        | (0x6fU == 
                                           (0x7fU & vlSelf->io_inst))) 
                                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr));
    vlSelf->RVNoob__DOT__rf__DOT___GEN_57 = ((0x1aU 
                                              == (0x1fU 
                                                  & (vlSelf->io_inst 
                                                     >> 0xfU)))
                                              ? vlSelf->RVNoob__DOT__rf__DOT__rf_26
                                              : ((0x19U 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->io_inst 
                                                      >> 0xfU)))
                                                  ? vlSelf->RVNoob__DOT__rf__DOT__rf_25
                                                  : 
                                                 ((0x18U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->io_inst 
                                                       >> 0xfU)))
                                                   ? vlSelf->RVNoob__DOT__rf__DOT__rf_24
                                                   : 
                                                  ((0x17U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->io_inst 
                                                        >> 0xfU)))
                                                    ? vlSelf->RVNoob__DOT__rf__DOT__rf_23
                                                    : 
                                                   ((0x16U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->io_inst 
                                                         >> 0xfU)))
                                                     ? vlSelf->RVNoob__DOT__rf__DOT__rf_22
                                                     : 
                                                    ((0x15U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->io_inst 
                                                          >> 0xfU)))
                                                      ? vlSelf->RVNoob__DOT__rf__DOT__rf_21
                                                      : 
                                                     ((0x14U 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelf->io_inst 
                                                           >> 0xfU)))
                                                       ? vlSelf->RVNoob__DOT__rf__DOT__rf_20
                                                       : 
                                                      ((0x13U 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->io_inst 
                                                            >> 0xfU)))
                                                        ? vlSelf->RVNoob__DOT__rf__DOT__rf_19
                                                        : 
                                                       ((0x12U 
                                                         == 
                                                         (0x1fU 
                                                          & (vlSelf->io_inst 
                                                             >> 0xfU)))
                                                         ? vlSelf->RVNoob__DOT__rf__DOT__rf_18
                                                         : 
                                                        ((0x11U 
                                                          == 
                                                          (0x1fU 
                                                           & (vlSelf->io_inst 
                                                              >> 0xfU)))
                                                          ? vlSelf->RVNoob__DOT__rf__DOT__rf_17
                                                          : 
                                                         ((0x10U 
                                                           == 
                                                           (0x1fU 
                                                            & (vlSelf->io_inst 
                                                               >> 0xfU)))
                                                           ? vlSelf->RVNoob__DOT__rf__DOT__rf_16
                                                           : 
                                                          ((0xfU 
                                                            == 
                                                            (0x1fU 
                                                             & (vlSelf->io_inst 
                                                                >> 0xfU)))
                                                            ? vlSelf->RVNoob__DOT__rf__DOT__rf_15
                                                            : 
                                                           ((0xeU 
                                                             == 
                                                             (0x1fU 
                                                              & (vlSelf->io_inst 
                                                                 >> 0xfU)))
                                                             ? vlSelf->RVNoob__DOT__rf__DOT__rf_14
                                                             : RVNoob__DOT__rf__DOT___GEN_44)))))))))))));
    vlSelf->RVNoob__DOT__idu_io_imm = (((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))
                                          ? (((QData)((IData)(
                                                              (vlSelf->io_inst 
                                                               >> 0x1fU))) 
                                              << 0x3fU) 
                                             | (((QData)((IData)(
                                                                 (vlSelf->io_inst 
                                                                  >> 0x1fU))) 
                                                 << 0x3eU) 
                                                | (((QData)((IData)(
                                                                    (vlSelf->io_inst 
                                                                     >> 0x1fU))) 
                                                    << 0x3dU) 
                                                   | (((QData)((IData)(
                                                                       (vlSelf->io_inst 
                                                                        >> 0x1fU))) 
                                                       << 0x3cU) 
                                                      | (((QData)((IData)(
                                                                          (vlSelf->io_inst 
                                                                           >> 0x1fU))) 
                                                          << 0x3bU) 
                                                         | (((QData)((IData)(
                                                                             (vlSelf->io_inst 
                                                                              >> 0x1fU))) 
                                                             << 0x3aU) 
                                                            | (((QData)((IData)(
                                                                                (vlSelf->io_inst 
                                                                                >> 0x1fU))) 
                                                                << 0x39U) 
                                                               | (((QData)((IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo)) 
                                                                   << 0x33U) 
                                                                  | (((QData)((IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo)) 
                                                                      << 0x26U) 
                                                                     | (((QData)((IData)(
                                                                                (vlSelf->io_inst 
                                                                                >> 0x1fU))) 
                                                                         << 0x25U) 
                                                                        | (((QData)((IData)(
                                                                                (vlSelf->io_inst 
                                                                                >> 0x1fU))) 
                                                                            << 0x24U) 
                                                                           | (((QData)((IData)(
                                                                                (vlSelf->io_inst 
                                                                                >> 0x1fU))) 
                                                                               << 0x23U) 
                                                                              | (((QData)((IData)(
                                                                                (vlSelf->io_inst 
                                                                                >> 0x1fU))) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(
                                                                                (vlSelf->io_inst 
                                                                                >> 0x1fU))) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(
                                                                                (vlSelf->io_inst 
                                                                                >> 0x1fU))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                ((0x80000000U 
                                                                                & vlSelf->io_inst) 
                                                                                | (((IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo) 
                                                                                << 0x19U) 
                                                                                | (((IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo) 
                                                                                << 0xcU) 
                                                                                | (vlSelf->io_inst 
                                                                                >> 0x14U)))))))))))))))))))))
                                          : 0ULL) | vlSelf->RVNoob__DOT__idu__DOT___io_imm_T_1) 
                                       | ((0x6fU == 
                                           (0x7fU & vlSelf->io_inst))
                                           ? ((vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1 
                                               << 0x14U) 
                                              | (QData)((IData)(
                                                                ((0xff000U 
                                                                  & vlSelf->io_inst) 
                                                                 | ((0x800U 
                                                                     & (vlSelf->io_inst 
                                                                        >> 9U)) 
                                                                    | (0x7feU 
                                                                       & (vlSelf->io_inst 
                                                                          >> 0x14U)))))))
                                           : 0ULL));
    vlSelf->RVNoob__DOT__exe__DOT__alu_out = (((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                                 | (0x17U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->io_inst))) 
                                                | (0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->io_inst))) 
                                               | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))
                                               ? ((
                                                   ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                                    | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))
                                                    ? 
                                                   (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                                     | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))
                                                     ? 
                                                    ((0x1fU 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->io_inst 
                                                          >> 0xfU)))
                                                      ? vlSelf->RVNoob__DOT__rf__DOT__rf_31
                                                      : 
                                                     ((0x1eU 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelf->io_inst 
                                                           >> 0xfU)))
                                                       ? vlSelf->RVNoob__DOT__rf__DOT__rf_30
                                                       : 
                                                      ((0x1dU 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->io_inst 
                                                            >> 0xfU)))
                                                        ? vlSelf->RVNoob__DOT__rf__DOT__rf_29
                                                        : 
                                                       ((0x1cU 
                                                         == 
                                                         (0x1fU 
                                                          & (vlSelf->io_inst 
                                                             >> 0xfU)))
                                                         ? vlSelf->RVNoob__DOT__rf__DOT__rf_28
                                                         : 
                                                        ((0x1bU 
                                                          == 
                                                          (0x1fU 
                                                           & (vlSelf->io_inst 
                                                              >> 0xfU)))
                                                          ? vlSelf->RVNoob__DOT__rf__DOT__rf_27
                                                          : vlSelf->RVNoob__DOT__rf__DOT___GEN_57)))))
                                                     : 0ULL)
                                                    : vlSelf->RVNoob__DOT__pc) 
                                                  + vlSelf->RVNoob__DOT__idu_io_imm)
                                               : 0ULL);
    vlSelf->RVNoob__DOT__exe_io_gp_out = (((0x6fU == 
                                            (0x7fU 
                                             & vlSelf->io_inst)) 
                                           | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))
                                           ? (4ULL 
                                              + vlSelf->RVNoob__DOT__pc)
                                           : vlSelf->RVNoob__DOT__exe__DOT__alu_out);
    vlSelf->io_res = vlSelf->RVNoob__DOT__exe_io_gp_out;
}

void VRVNoob___024unit____Vdpiimwrap_set_gpr_ptr__Vdpioc2_TOP____024unit(const VlUnpacked<QData/*63:0*/, 32> &a);

void VRVNoob___024root___initial__TOP__4(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___initial__TOP__4\n"); );
    // Body
    VRVNoob___024unit____Vdpiimwrap_set_gpr_ptr__Vdpioc2_TOP____024unit(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf);
}

void VRVNoob___024root___eval_initial(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
    VRVNoob___024root___initial__TOP__4(vlSelf);
}

void VRVNoob___024root___eval_settle(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___eval_settle\n"); );
    // Body
    VRVNoob___024root___settle__TOP__2(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

void VRVNoob___024root___final(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___final\n"); );
}

void VRVNoob___024root___ctor_var_reset(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->io_pc = VL_RAND_RESET_Q(64);
    vlSelf->io_inst = VL_RAND_RESET_I(32);
    vlSelf->io_res = VL_RAND_RESET_Q(64);
    vlSelf->io_ebreak = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu_io_imm = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__idu_io_wen = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__exe_io_gp_out = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__U_ebreak_ebreak = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__pc = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__snpc = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_addi = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo = VL_RAND_RESET_I(6);
    vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo = VL_RAND_RESET_I(13);
    vlSelf->RVNoob__DOT__idu__DOT__immU_lo_lo = VL_RAND_RESET_I(8);
    vlSelf->RVNoob__DOT__idu__DOT__immJ_lo_lo_lo = VL_RAND_RESET_I(5);
    vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1 = VL_RAND_RESET_Q(44);
    vlSelf->RVNoob__DOT__idu__DOT___io_imm_T_1 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_0 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_1 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_2 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_3 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_4 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_5 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_6 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_7 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_8 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_9 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_10 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_11 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_12 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_13 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_14 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_15 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_16 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_17 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_18 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_19 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_20 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_21 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_22 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_23 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_24 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_25 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_26 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_27 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_28 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_29 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_30 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT__rf_31 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_0 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_1 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_2 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_3 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_4 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_5 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_6 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_7 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_8 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_9 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_10 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_11 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_12 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_13 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_14 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_15 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_16 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_17 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_18 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_19 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_20 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_21 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_22 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_23 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_24 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_25 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_26 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_27 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_28 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_29 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_30 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf__DOT___GEN_57 = VL_RAND_RESET_Q(64);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->RVNoob__DOT__exe__DOT__alu_out = VL_RAND_RESET_Q(64);
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
