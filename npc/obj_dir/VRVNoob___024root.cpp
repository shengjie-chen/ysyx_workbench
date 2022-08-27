// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRVNoob.h for the primary calling header

#include "VRVNoob___024root.h"
#include "VRVNoob__Syms.h"

#include "verilated_dpi.h"

//==========

extern "C" void pmem_read_dpi(long long raddr, long long* rdata);

VL_INLINE_OPT void VRVNoob___024root____Vdpiimwrap_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_read_dpi_TOP(QData/*63:0*/ raddr, QData/*63:0*/ &rdata) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root____Vdpiimwrap_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_read_dpi_TOP\n"); );
    // Body
    long long raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    long long rdata__Vcvt;
    pmem_read_dpi(raddr__Vcvt, &rdata__Vcvt);
    rdata = rdata__Vcvt;
}

extern "C" void pmem_write_dpi(long long waddr, long long wdata, char wmask);

VL_INLINE_OPT void VRVNoob___024root____Vdpiimwrap_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_write_dpi_TOP(QData/*63:0*/ waddr, QData/*63:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root____Vdpiimwrap_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_write_dpi_TOP\n"); );
    // Body
    long long waddr__Vcvt;
    for (size_t waddr__Vidx = 0; waddr__Vidx < 1; ++waddr__Vidx) waddr__Vcvt = waddr;
    long long wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    char wmask__Vcvt;
    for (size_t wmask__Vidx = 0; wmask__Vidx < 1; ++wmask__Vidx) wmask__Vcvt = wmask;
    pmem_write_dpi(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

void VRVNoob___024unit____Vdpiimwrap_inst_change_TOP____024unit(IData/*31:0*/ a);

VL_INLINE_OPT void VRVNoob___024root___combo__TOP__2(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___combo__TOP__2\n"); );
    // Variables
    CData/*0:0*/ RVNoob__DOT__idu__DOT___rvi_add_T_2;
    CData/*0:0*/ RVNoob__DOT__idu__DOT___rvi_srl_T_2;
    CData/*0:0*/ RVNoob__DOT__idu__DOT___rvi_addw_T_2;
    // Body
    VRVNoob___024unit____Vdpiimwrap_inst_change_TOP____024unit(vlSelf->io_inst);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_add = ((IData)(
                                                      (0x33U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst))) 
                                              & (0U 
                                                 == 
                                                 (vlSelf->io_inst 
                                                  >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sll = ((IData)(
                                                      (0x1033U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst))) 
                                              & (0U 
                                                 == 
                                                 (vlSelf->io_inst 
                                                  >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_xor = ((IData)(
                                                      (0x4033U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst))) 
                                              & (0U 
                                                 == 
                                                 (vlSelf->io_inst 
                                                  >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_srl = ((IData)(
                                                      (0x5033U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst))) 
                                              & (0U 
                                                 == 
                                                 (vlSelf->io_inst 
                                                  >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_or = ((IData)(
                                                     (0x6033U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->io_inst))) 
                                             & (0U 
                                                == 
                                                (vlSelf->io_inst 
                                                 >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_and = ((IData)(
                                                      (0x7033U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst))) 
                                              & (0U 
                                                 == 
                                                 (vlSelf->io_inst 
                                                  >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvm_mulh = ((IData)(
                                                       (0x1033U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst))) 
                                               & (1U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvm_mulhsu = ((IData)(
                                                         (0x2033U 
                                                          == 
                                                          (0x707fU 
                                                           & vlSelf->io_inst))) 
                                                 & (1U 
                                                    == 
                                                    (vlSelf->io_inst 
                                                     >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvm_mulhu = ((IData)(
                                                        (0x3033U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->io_inst))) 
                                                & (1U 
                                                   == 
                                                   (vlSelf->io_inst 
                                                    >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvm_div = ((IData)(
                                                      (0x4033U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst))) 
                                              & (1U 
                                                 == 
                                                 (vlSelf->io_inst 
                                                  >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvm_rem = ((IData)(
                                                      (0x6033U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst))) 
                                              & (1U 
                                                 == 
                                                 (vlSelf->io_inst 
                                                  >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvm_remu = ((IData)(
                                                       (0x7033U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst))) 
                                               & (1U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_slt = ((IData)(
                                                      (0x2033U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst))) 
                                              & (0U 
                                                 == 
                                                 (vlSelf->io_inst 
                                                  >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sltu = ((IData)(
                                                       (0x3033U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst))) 
                                               & (0U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_addw = ((IData)(
                                                       (0x3bU 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst))) 
                                               & (0U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sllw = ((IData)(
                                                       (0x103bU 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst))) 
                                               & (0U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_srlw = ((IData)(
                                                       (0x503bU 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst))) 
                                               & (0U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sraw = ((IData)(
                                                       (0x503bU 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst))) 
                                               & (0x20U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvm_divw = ((IData)(
                                                       (0x403bU 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst))) 
                                               & (1U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvm_remw = ((IData)(
                                                       (0x603bU 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst))) 
                                               & (1U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x19U)));
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
    vlSelf->RVNoob__DOT__idu__DOT__type_U = ((0x37U 
                                              == (0x7fU 
                                                  & vlSelf->io_inst)) 
                                             | (0x17U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo_lo = 
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
    vlSelf->RVNoob__DOT__idu__DOT__rvi_beq = (IData)(
                                                     (0x63U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_bne = (IData)(
                                                     (0x1063U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_blt = (IData)(
                                                     (0x4063U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_bge = (IData)(
                                                     (0x5063U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_bltu = (IData)(
                                                      (0x6063U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_bgeu = (IData)(
                                                      (0x7063U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sb = (IData)(
                                                    (0x23U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sh = (IData)(
                                                    (0x1023U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sw = (IData)(
                                                    (0x2023U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sd = (IData)(
                                                    (0x3023U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_addi = (IData)(
                                                      (0x13U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_xori = (IData)(
                                                      (0x4013U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_ori = (IData)(
                                                     (0x6013U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_andi = (IData)(
                                                      (0x7013U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_slli = ((IData)(
                                                       (0x1013U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst))) 
                                               & (0U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x1aU)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_srli = ((IData)(
                                                       (0x5013U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst))) 
                                               & (0U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x1aU)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_srai = ((IData)(
                                                       (0x5013U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst))) 
                                               & (0x10U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x1aU)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_slti = (IData)(
                                                      (0x2013U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sltiu = (IData)(
                                                       (0x3013U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_addiw = (IData)(
                                                       (0x1bU 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_slliw = ((IData)(
                                                        (0x101bU 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->io_inst))) 
                                                & (0U 
                                                   == 
                                                   (vlSelf->io_inst 
                                                    >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_srliw = ((IData)(
                                                        (0x501bU 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->io_inst))) 
                                                & (0U 
                                                   == 
                                                   (vlSelf->io_inst 
                                                    >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sraiw = ((IData)(
                                                        (0x501bU 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->io_inst))) 
                                                & (0x20U 
                                                   == 
                                                   (vlSelf->io_inst 
                                                    >> 0x19U)));
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
    RVNoob__DOT__idu__DOT___rvi_add_T_2 = (IData)((0x33U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->io_inst)));
    RVNoob__DOT__idu__DOT___rvi_srl_T_2 = (IData)((0x5033U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->io_inst)));
    RVNoob__DOT__idu__DOT___rvi_addw_T_2 = (IData)(
                                                   (0x3bU 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_ld = (IData)(
                                                    (0x3003U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__jpg_sexb = (IData)(
                                                      (3U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__jpg_sexthw = (IData)(
                                                        (0x1003U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__jpg_uextb = (IData)(
                                                       (0x4003U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__jpg_uexthw = (IData)(
                                                        (0x5003U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__jpg_uextw = (IData)(
                                                       (0x6003U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->io_inst)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_lw = (IData)(
                                                    (0x2003U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->io_inst)));
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
    vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo = ((0x1000U 
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
                                                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo_lo))))))));
    vlSelf->RVNoob__DOT__idu__DOT__type_B = ((((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_beq) 
                                                 | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_bne)) 
                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_blt)) 
                                               | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_bge)) 
                                              | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_bltu)) 
                                             | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_bgeu));
    vlSelf->RVNoob__DOT__idu__DOT__jpg_slt = ((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_slti) 
                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sltiu)) 
                                               | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_slt)) 
                                              | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sltu));
    vlSelf->RVNoob__DOT__idu__DOT__immB_hi_hi_hi_1 
        = (((QData)((IData)((vlSelf->io_inst >> 0x1fU))) 
            << 0x32U) | (((QData)((IData)((vlSelf->io_inst 
                                           >> 0x1fU))) 
                          << 0x31U) | (((QData)((IData)(
                                                        (vlSelf->io_inst 
                                                         >> 0x1fU))) 
                                        << 0x30U) | 
                                       (((QData)((IData)(
                                                         (vlSelf->io_inst 
                                                          >> 0x1fU))) 
                                         << 0x2fU) 
                                        | (((QData)((IData)(
                                                            (vlSelf->io_inst 
                                                             >> 0x1fU))) 
                                            << 0x2eU) 
                                           | (((QData)((IData)(
                                                               (vlSelf->io_inst 
                                                                >> 0x1fU))) 
                                               << 0x2dU) 
                                              | (((QData)((IData)(
                                                                  (vlSelf->io_inst 
                                                                   >> 0x1fU))) 
                                                  << 0x2cU) 
                                                 | (((QData)((IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo)) 
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
                                                                                | ((0x1000000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 7U)) 
                                                                                | ((0x800000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 8U)) 
                                                                                | ((0x400000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 9U)) 
                                                                                | ((0x200000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0xaU)) 
                                                                                | ((0x100000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0xbU)) 
                                                                                | ((0x80000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0xcU)) 
                                                                                | ((0x40000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0xdU)) 
                                                                                | (((IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo) 
                                                                                << 0xcU) 
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
                                                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo)))))))))))))))))))))))))))))))));
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
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sub = ((IData)(RVNoob__DOT__idu__DOT___rvi_add_T_2) 
                                              & (0x20U 
                                                 == 
                                                 (vlSelf->io_inst 
                                                  >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvm_mul = ((IData)(RVNoob__DOT__idu__DOT___rvi_add_T_2) 
                                              & (1U 
                                                 == 
                                                 (vlSelf->io_inst 
                                                  >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sra = ((IData)(RVNoob__DOT__idu__DOT___rvi_srl_T_2) 
                                              & (0x20U 
                                                 == 
                                                 (vlSelf->io_inst 
                                                  >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvm_divu = ((IData)(RVNoob__DOT__idu__DOT___rvi_srl_T_2) 
                                               & (1U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_subw = ((IData)(RVNoob__DOT__idu__DOT___rvi_addw_T_2) 
                                               & (0x20U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__rvm_mulw = ((IData)(RVNoob__DOT__idu__DOT___rvi_addw_T_2) 
                                               & (1U 
                                                  == 
                                                  (vlSelf->io_inst 
                                                   >> 0x19U)));
    vlSelf->RVNoob__DOT__idu__DOT__jpg_sextw = ((((
                                                   (((((((((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addiw) 
                                                             | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_slliw)) 
                                                            | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_srliw)) 
                                                           | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sraiw)) 
                                                          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addw)) 
                                                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_subw)) 
                                                        | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sllw)) 
                                                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_srlw)) 
                                                      | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sraw)) 
                                                     | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulw)) 
                                                    | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_divw)) 
                                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_divw)) 
                                                  | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_remw)) 
                                                 | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_remw)) 
                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_lw));
    vlSelf->RVNoob__DOT__idu__DOT__type_R = (((((((
                                                   (((((((((((((((((((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_add) 
                                                                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sub)) 
                                                                      | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sll)) 
                                                                     | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_slt)) 
                                                                    | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sltu)) 
                                                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_xor)) 
                                                                  | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_srl)) 
                                                                 | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sra)) 
                                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_or)) 
                                                               | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_and)) 
                                                              | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addw)) 
                                                             | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_subw)) 
                                                            | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sllw)) 
                                                           | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_srlw)) 
                                                          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sraw)) 
                                                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_mul)) 
                                                        | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulh)) 
                                                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulhsu)) 
                                                      | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulhu)) 
                                                     | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_div)) 
                                                    | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_divu)) 
                                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_rem)) 
                                                  | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_remu)) 
                                                 | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulw)) 
                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_divw)) 
                                               | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_divw)) 
                                              | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_remw)) 
                                             | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_remw));
}

void VRVNoob___024unit____Vdpiimwrap_npc_ebreak_TOP____024unit();

VL_INLINE_OPT void VRVNoob___024root___sequent__TOP__3(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___sequent__TOP__3\n"); );
    // Body
    if ((0x100073U == vlSelf->io_inst)) {
        if ((0ULL == vlSelf->RVNoob__DOT__rf__DOT__rf_10)) {
            VL_WRITEF("!!!!  HIT GOOD TRAP !!!!\n");
        } else {
            VL_WRITEF("!!!!  HIT BAD TRAP !!!!\n");
        }
        vlSelf->RVNoob__DOT__U_ebreak_ebreak = 1U;
        VRVNoob___024unit____Vdpiimwrap_npc_ebreak_TOP____024unit();
    } else {
        vlSelf->RVNoob__DOT__U_ebreak_ebreak = 0U;
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem) 
                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S)) 
                      & (3U == (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))) 
                     & (~ ((0U == (7U & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U])) 
                           | (IData)(vlSelf->reset)))))) {
        VL_FWRITEF(0x80000002U,"Assertion failed\n    at IFM.scala:22 assert(shift === 0.U)\n");
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem) 
                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S)) 
                      & (3U == (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))) 
                     & (~ ((0U == (7U & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U])) 
                           | (IData)(vlSelf->reset)))))) {
        VL_WRITEF("[%0t] %%Error: RVNoob.v:70: Assertion failed in %NRVNoob.ifm\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("/home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob/Verilog_Gen/RVNoob.v", 70, "");
    }
    if (VL_UNLIKELY((((((IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem) 
                        | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S)) 
                       & (3U != (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))) 
                      & (2U == (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))) 
                     & (~ ((4U >= (7U & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U])) 
                           | (IData)(vlSelf->reset)))))) {
        VL_FWRITEF(0x80000002U,"Assertion failed\n    at IFM.scala:24 assert(shift <= 4.U)\n");
    }
    if (VL_UNLIKELY((((((IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem) 
                        | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S)) 
                       & (3U != (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))) 
                      & (2U == (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))) 
                     & (~ ((4U >= (7U & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U])) 
                           | (IData)(vlSelf->reset)))))) {
        VL_WRITEF("[%0t] %%Error: RVNoob.v:92: Assertion failed in %NRVNoob.ifm\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("/home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob/Verilog_Gen/RVNoob.v", 92, "");
    }
    if (VL_UNLIKELY(((((((IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem) 
                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S)) 
                        & (3U != (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))) 
                       & (2U != (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))) 
                      & (1U == (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))) 
                     & (~ ((6U >= (7U & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U])) 
                           | (IData)(vlSelf->reset)))))) {
        VL_FWRITEF(0x80000002U,"Assertion failed\n    at IFM.scala:26 assert(shift <= 6.U)\n");
    }
    if (VL_UNLIKELY(((((((IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem) 
                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S)) 
                        & (3U != (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))) 
                       & (2U != (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))) 
                      & (1U == (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))) 
                     & (~ ((6U >= (7U & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U])) 
                           | (IData)(vlSelf->reset)))))) {
        VL_WRITEF("[%0t] %%Error: RVNoob.v:114: Assertion failed in %NRVNoob.ifm\n",
                  64,VL_TIME_UNITED_Q(1),-12,vlSymsp->name());
        VL_STOP_MT("/home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob/Verilog_Gen/RVNoob.v", 114, "");
    }
    if (vlSelf->RVNoob__DOT__idu_io_wen) {
        vlSelf->RVNoob__DOT__rf__DOT__rf_31 = ((0x1fU 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_30);
        vlSelf->RVNoob__DOT__rf__DOT__rf_30 = ((0x1eU 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_29);
        vlSelf->RVNoob__DOT__rf__DOT__rf_27 = ((0x1bU 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_26);
        vlSelf->RVNoob__DOT__rf__DOT__rf_28 = ((0x1cU 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_27);
        vlSelf->RVNoob__DOT__rf__DOT__rf_29 = ((0x1dU 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_28);
        vlSelf->RVNoob__DOT__rf__DOT__rf_22 = ((0x16U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_21);
        vlSelf->RVNoob__DOT__rf__DOT__rf_14 = ((0xeU 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_13);
        vlSelf->RVNoob__DOT__rf__DOT__rf_15 = ((0xfU 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_14);
        vlSelf->RVNoob__DOT__rf__DOT__rf_16 = ((0x10U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_15);
        vlSelf->RVNoob__DOT__rf__DOT__rf_17 = ((0x11U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_16);
        vlSelf->RVNoob__DOT__rf__DOT__rf_18 = ((0x12U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_17);
        vlSelf->RVNoob__DOT__rf__DOT__rf_19 = ((0x13U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_18);
        vlSelf->RVNoob__DOT__rf__DOT__rf_20 = ((0x14U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_19);
        vlSelf->RVNoob__DOT__rf__DOT__rf_21 = ((0x15U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_20);
        vlSelf->RVNoob__DOT__rf__DOT__rf_23 = ((0x17U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_22);
        vlSelf->RVNoob__DOT__rf__DOT__rf_24 = ((0x18U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_23);
        vlSelf->RVNoob__DOT__rf__DOT__rf_25 = ((0x19U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_24);
        vlSelf->RVNoob__DOT__rf__DOT__rf_26 = ((0x1aU 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_25);
        vlSelf->RVNoob__DOT__rf__DOT__rf_13 = ((0xdU 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_12);
        vlSelf->RVNoob__DOT__rf__DOT__rf_12 = ((0xcU 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_11);
        vlSelf->RVNoob__DOT__rf__DOT__rf_11 = ((0xbU 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_10);
        vlSelf->RVNoob__DOT__rf__DOT__rf_9 = ((9U == 
                                               (0x1fU 
                                                & (vlSelf->io_inst 
                                                   >> 7U)))
                                               ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                               : vlSelf->RVNoob__DOT__rf__DOT___GEN_8);
        vlSelf->RVNoob__DOT__rf__DOT__rf_8 = ((8U == 
                                               (0x1fU 
                                                & (vlSelf->io_inst 
                                                   >> 7U)))
                                               ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                               : vlSelf->RVNoob__DOT__rf__DOT___GEN_7);
        vlSelf->RVNoob__DOT__rf__DOT__rf_7 = ((7U == 
                                               (0x1fU 
                                                & (vlSelf->io_inst 
                                                   >> 7U)))
                                               ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                               : vlSelf->RVNoob__DOT__rf__DOT___GEN_6);
        vlSelf->RVNoob__DOT__rf__DOT__rf_6 = ((6U == 
                                               (0x1fU 
                                                & (vlSelf->io_inst 
                                                   >> 7U)))
                                               ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                               : vlSelf->RVNoob__DOT__rf__DOT___GEN_5);
        vlSelf->RVNoob__DOT__rf__DOT__rf_5 = ((5U == 
                                               (0x1fU 
                                                & (vlSelf->io_inst 
                                                   >> 7U)))
                                               ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                               : vlSelf->RVNoob__DOT__rf__DOT___GEN_4);
        vlSelf->RVNoob__DOT__rf__DOT__rf_4 = ((4U == 
                                               (0x1fU 
                                                & (vlSelf->io_inst 
                                                   >> 7U)))
                                               ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                               : vlSelf->RVNoob__DOT__rf__DOT___GEN_3);
        vlSelf->RVNoob__DOT__rf__DOT__rf_3 = ((3U == 
                                               (0x1fU 
                                                & (vlSelf->io_inst 
                                                   >> 7U)))
                                               ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                               : vlSelf->RVNoob__DOT__rf__DOT___GEN_2);
        vlSelf->RVNoob__DOT__rf__DOT__rf_2 = ((2U == 
                                               (0x1fU 
                                                & (vlSelf->io_inst 
                                                   >> 7U)))
                                               ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                               : vlSelf->RVNoob__DOT__rf__DOT___GEN_1);
        vlSelf->RVNoob__DOT__rf__DOT__rf_1 = ((1U == 
                                               (0x1fU 
                                                & (vlSelf->io_inst 
                                                   >> 7U)))
                                               ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                               : vlSelf->RVNoob__DOT__rf__DOT___GEN_0);
    } else {
        vlSelf->RVNoob__DOT__rf__DOT__rf_31 = vlSelf->RVNoob__DOT__rf__DOT___GEN_30;
        vlSelf->RVNoob__DOT__rf__DOT__rf_30 = vlSelf->RVNoob__DOT__rf__DOT___GEN_29;
        vlSelf->RVNoob__DOT__rf__DOT__rf_27 = vlSelf->RVNoob__DOT__rf__DOT___GEN_26;
        vlSelf->RVNoob__DOT__rf__DOT__rf_28 = vlSelf->RVNoob__DOT__rf__DOT___GEN_27;
        vlSelf->RVNoob__DOT__rf__DOT__rf_29 = vlSelf->RVNoob__DOT__rf__DOT___GEN_28;
        vlSelf->RVNoob__DOT__rf__DOT__rf_22 = vlSelf->RVNoob__DOT__rf__DOT___GEN_21;
        vlSelf->RVNoob__DOT__rf__DOT__rf_14 = vlSelf->RVNoob__DOT__rf__DOT___GEN_13;
        vlSelf->RVNoob__DOT__rf__DOT__rf_15 = vlSelf->RVNoob__DOT__rf__DOT___GEN_14;
        vlSelf->RVNoob__DOT__rf__DOT__rf_16 = vlSelf->RVNoob__DOT__rf__DOT___GEN_15;
        vlSelf->RVNoob__DOT__rf__DOT__rf_17 = vlSelf->RVNoob__DOT__rf__DOT___GEN_16;
        vlSelf->RVNoob__DOT__rf__DOT__rf_18 = vlSelf->RVNoob__DOT__rf__DOT___GEN_17;
        vlSelf->RVNoob__DOT__rf__DOT__rf_19 = vlSelf->RVNoob__DOT__rf__DOT___GEN_18;
        vlSelf->RVNoob__DOT__rf__DOT__rf_20 = vlSelf->RVNoob__DOT__rf__DOT___GEN_19;
        vlSelf->RVNoob__DOT__rf__DOT__rf_21 = vlSelf->RVNoob__DOT__rf__DOT___GEN_20;
        vlSelf->RVNoob__DOT__rf__DOT__rf_23 = vlSelf->RVNoob__DOT__rf__DOT___GEN_22;
        vlSelf->RVNoob__DOT__rf__DOT__rf_24 = vlSelf->RVNoob__DOT__rf__DOT___GEN_23;
        vlSelf->RVNoob__DOT__rf__DOT__rf_25 = vlSelf->RVNoob__DOT__rf__DOT___GEN_24;
        vlSelf->RVNoob__DOT__rf__DOT__rf_26 = vlSelf->RVNoob__DOT__rf__DOT___GEN_25;
        vlSelf->RVNoob__DOT__rf__DOT__rf_13 = vlSelf->RVNoob__DOT__rf__DOT___GEN_12;
        vlSelf->RVNoob__DOT__rf__DOT__rf_12 = vlSelf->RVNoob__DOT__rf__DOT___GEN_11;
        vlSelf->RVNoob__DOT__rf__DOT__rf_11 = vlSelf->RVNoob__DOT__rf__DOT___GEN_10;
        vlSelf->RVNoob__DOT__rf__DOT__rf_9 = vlSelf->RVNoob__DOT__rf__DOT___GEN_8;
        vlSelf->RVNoob__DOT__rf__DOT__rf_8 = vlSelf->RVNoob__DOT__rf__DOT___GEN_7;
        vlSelf->RVNoob__DOT__rf__DOT__rf_7 = vlSelf->RVNoob__DOT__rf__DOT___GEN_6;
        vlSelf->RVNoob__DOT__rf__DOT__rf_6 = vlSelf->RVNoob__DOT__rf__DOT___GEN_5;
        vlSelf->RVNoob__DOT__rf__DOT__rf_5 = vlSelf->RVNoob__DOT__rf__DOT___GEN_4;
        vlSelf->RVNoob__DOT__rf__DOT__rf_4 = vlSelf->RVNoob__DOT__rf__DOT___GEN_3;
        vlSelf->RVNoob__DOT__rf__DOT__rf_3 = vlSelf->RVNoob__DOT__rf__DOT___GEN_2;
        vlSelf->RVNoob__DOT__rf__DOT__rf_2 = vlSelf->RVNoob__DOT__rf__DOT___GEN_1;
        vlSelf->RVNoob__DOT__rf__DOT__rf_1 = vlSelf->RVNoob__DOT__rf__DOT___GEN_0;
    }
    vlSelf->io_ebreak = vlSelf->RVNoob__DOT__U_ebreak_ebreak;
    vlSelf->RVNoob__DOT__pc = ((IData)(vlSelf->reset)
                                ? 0x80000000ULL : (
                                                   (1U 
                                                    & ((IData)(vlSelf->RVNoob__DOT__idu_io_pc_mux) 
                                                       | ((1U 
                                                           == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                           ? 
                                                          (0ULL 
                                                           == vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res)
                                                           : 
                                                          ((2U 
                                                            == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                            ? 
                                                           (0ULL 
                                                            != vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res)
                                                            : 
                                                           ((3U 
                                                             == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                             ? 
                                                            vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[2U]
                                                             : 
                                                            ((4U 
                                                              == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op)) 
                                                             & ((~ 
                                                                 vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[2U]) 
                                                                | (0ULL 
                                                                   == vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res))))))))
                                                    ? 
                                                   ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr)
                                                     ? 
                                                    (0xfffffffffffffffeULL 
                                                     & vlSelf->RVNoob__DOT__npc_add_res)
                                                     : vlSelf->RVNoob__DOT__npc_add_res)
                                                    : vlSelf->RVNoob__DOT__snpc));
    vlSelf->RVNoob__DOT__rf__DOT__rf_10 = ((IData)(vlSelf->RVNoob__DOT__idu_io_wen)
                                            ? ((0xaU 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 7U)))
                                                ? vlSelf->RVNoob__DOT__exe_io_gp_out
                                                : vlSelf->RVNoob__DOT__rf__DOT___GEN_9)
                                            : vlSelf->RVNoob__DOT__rf__DOT___GEN_9);
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x1fU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_31;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x1eU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_30;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x1bU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_27;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x1cU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_28;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x1dU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_29;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x16U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_22;
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
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x17U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_23;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x18U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_24;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x19U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_25;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0x1aU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_26;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0xdU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_13;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0xcU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_12;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0xbU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_11;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[9U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_9;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[8U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_8;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[7U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_7;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[6U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_6;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[5U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_5;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[4U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_4;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[3U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_3;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[2U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_2;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[1U] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_1;
    vlSelf->RVNoob__DOT__snpc = (4ULL + vlSelf->RVNoob__DOT__pc);
    vlSelf->io_pc = vlSelf->RVNoob__DOT__pc;
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0xaU] 
        = vlSelf->RVNoob__DOT__rf__DOT__rf_10;
}

void VRVNoob___024unit____Vdpiimwrap_npc_change_TOP____024unit(QData/*63:0*/ a);

VL_INLINE_OPT void VRVNoob___024root___combo__TOP__5(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___combo__TOP__5\n"); );
    // Variables
    VlWide<3>/*94:0*/ RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36;
    VlWide<3>/*94:0*/ RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42;
    VlWide<4>/*127:0*/ __Vtemp93;
    VlWide<4>/*127:0*/ __Vtemp94;
    VlWide<4>/*127:0*/ __Vtemp95;
    VlWide<3>/*95:0*/ __Vtemp98;
    VlWide<3>/*95:0*/ __Vtemp100;
    VlWide<3>/*95:0*/ __Vtemp101;
    VlWide<3>/*95:0*/ __Vtemp103;
    VlWide<3>/*95:0*/ __Vtemp104;
    VlWide<3>/*95:0*/ __Vtemp105;
    VlWide<3>/*95:0*/ __Vtemp108;
    VlWide<3>/*95:0*/ __Vtemp111;
    VlWide<3>/*95:0*/ __Vtemp112;
    VlWide<3>/*95:0*/ __Vtemp113;
    VlWide<3>/*95:0*/ __Vtemp114;
    VlWide<3>/*95:0*/ __Vtemp115;
    VlWide<3>/*95:0*/ __Vtemp116;
    VlWide<3>/*95:0*/ __Vtemp130;
    VlWide<3>/*95:0*/ __Vtemp131;
    VlWide<3>/*95:0*/ __Vtemp132;
    VlWide<3>/*95:0*/ __Vtemp134;
    VlWide<3>/*95:0*/ __Vtemp135;
    VlWide<3>/*95:0*/ __Vtemp136;
    VlWide<3>/*95:0*/ __Vtemp137;
    VlWide<3>/*95:0*/ __Vtemp138;
    VlWide<5>/*159:0*/ __Vtemp141;
    VlWide<5>/*159:0*/ __Vtemp142;
    VlWide<3>/*95:0*/ __Vtemp144;
    VlWide<5>/*159:0*/ __Vtemp145;
    VlWide<5>/*159:0*/ __Vtemp146;
    VlWide<5>/*159:0*/ __Vtemp147;
    VlWide<4>/*127:0*/ __Vtemp149;
    VlWide<4>/*127:0*/ __Vtemp150;
    VlWide<4>/*127:0*/ __Vtemp151;
    VlWide<4>/*127:0*/ __Vtemp152;
    VlWide<4>/*127:0*/ __Vtemp153;
    VlWide<3>/*95:0*/ __Vtemp158;
    VlWide<6>/*191:0*/ __Vtemp172;
    VlWide<6>/*191:0*/ __Vtemp173;
    VlWide<4>/*127:0*/ __Vtemp176;
    VlWide<4>/*127:0*/ __Vtemp177;
    VlWide<4>/*127:0*/ __Vtemp178;
    VlWide<4>/*127:0*/ __Vtemp179;
    QData/*63:0*/ RVNoob__DOT__idu__DOT___io_imm_T_5;
    QData/*63:0*/ RVNoob__DOT__idu__DOT___io_imm_T_7;
    QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_44;
    QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_76;
    QData/*63:0*/ RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_152;
    // Body
    vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op 
        = ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sb)
            ? 0U : ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sh)
                     ? 1U : ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sw)
                              ? 2U : ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sd)
                                       ? 3U : 0U))));
    vlSelf->RVNoob__DOT__idu__DOT__type_S = ((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sb) 
                                               | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sh)) 
                                              | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sw)) 
                                             | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sd));
    vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem = 
        (((((((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sexb) 
              | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sexthw)) 
             | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_lw)) 
            | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_uextb)) 
           | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_uexthw)) 
          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_uextw)) 
         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_ld));
    vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op = 
        ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_beq)
          ? 1U : ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_bne)
                   ? 2U : (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_blt) 
                            | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_bltu))
                            ? 3U : (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_bge) 
                                     | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_bgeu))
                                     ? 4U : ((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_slt)
                                              ? 5U : 
                                             ((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sextw)
                                               ? 6U
                                               : ((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sexb)
                                                   ? 8U
                                                   : 
                                                  ((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sexthw)
                                                    ? 7U
                                                    : 
                                                   ((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_uextw)
                                                     ? 9U
                                                     : 
                                                    ((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_uexthw)
                                                      ? 0xaU
                                                      : 
                                                     ((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_uextb)
                                                       ? 0xbU
                                                       : 0U)))))))))));
    vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr = (IData)(
                                                      (0x67U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->io_inst)));
    if (vlSelf->reset) {
        vlSelf->RVNoob__DOT__rf__DOT___GEN_30 = 0x1fULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_29 = 0x1eULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_26 = 0x1bULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_27 = 0x1cULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_28 = 0x1dULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_21 = 0x16ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_13 = 0xeULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_14 = 0xfULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_15 = 0x10ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_16 = 0x11ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_17 = 0x12ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_18 = 0x13ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_19 = 0x14ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_20 = 0x15ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_22 = 0x17ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_23 = 0x18ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_24 = 0x19ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_25 = 0x1aULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_12 = 0xdULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_11 = 0xcULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_10 = 0xbULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_8 = 9ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_7 = 8ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_6 = 7ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_5 = 6ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_4 = 5ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_3 = 4ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_2 = 3ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_1 = 2ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_0 = 1ULL;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_9 = 0xaULL;
    } else {
        vlSelf->RVNoob__DOT__rf__DOT___GEN_30 = vlSelf->RVNoob__DOT__rf__DOT__rf_31;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_29 = vlSelf->RVNoob__DOT__rf__DOT__rf_30;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_26 = vlSelf->RVNoob__DOT__rf__DOT__rf_27;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_27 = vlSelf->RVNoob__DOT__rf__DOT__rf_28;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_28 = vlSelf->RVNoob__DOT__rf__DOT__rf_29;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_21 = vlSelf->RVNoob__DOT__rf__DOT__rf_22;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_13 = vlSelf->RVNoob__DOT__rf__DOT__rf_14;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_14 = vlSelf->RVNoob__DOT__rf__DOT__rf_15;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_15 = vlSelf->RVNoob__DOT__rf__DOT__rf_16;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_16 = vlSelf->RVNoob__DOT__rf__DOT__rf_17;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_17 = vlSelf->RVNoob__DOT__rf__DOT__rf_18;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_18 = vlSelf->RVNoob__DOT__rf__DOT__rf_19;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_19 = vlSelf->RVNoob__DOT__rf__DOT__rf_20;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_20 = vlSelf->RVNoob__DOT__rf__DOT__rf_21;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_22 = vlSelf->RVNoob__DOT__rf__DOT__rf_23;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_23 = vlSelf->RVNoob__DOT__rf__DOT__rf_24;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_24 = vlSelf->RVNoob__DOT__rf__DOT__rf_25;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_25 = vlSelf->RVNoob__DOT__rf__DOT__rf_26;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_12 = vlSelf->RVNoob__DOT__rf__DOT__rf_13;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_11 = vlSelf->RVNoob__DOT__rf__DOT__rf_12;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_10 = vlSelf->RVNoob__DOT__rf__DOT__rf_11;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_8 = vlSelf->RVNoob__DOT__rf__DOT__rf_9;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_7 = vlSelf->RVNoob__DOT__rf__DOT__rf_8;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_6 = vlSelf->RVNoob__DOT__rf__DOT__rf_7;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_5 = vlSelf->RVNoob__DOT__rf__DOT__rf_6;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_4 = vlSelf->RVNoob__DOT__rf__DOT__rf_5;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_3 = vlSelf->RVNoob__DOT__rf__DOT__rf_4;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_2 = vlSelf->RVNoob__DOT__rf__DOT__rf_3;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_1 = vlSelf->RVNoob__DOT__rf__DOT__rf_2;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_0 = vlSelf->RVNoob__DOT__rf__DOT__rf_1;
        vlSelf->RVNoob__DOT__rf__DOT___GEN_9 = vlSelf->RVNoob__DOT__rf__DOT__rf_10;
    }
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
                                                           : 0ULL)))))))))))));
    RVNoob__DOT__rf__DOT___GEN_76 = ((0xdU == (0x1fU 
                                               & (vlSelf->io_inst 
                                                  >> 0x14U)))
                                      ? vlSelf->RVNoob__DOT__rf__DOT__rf_13
                                      : ((0xcU == (0x1fU 
                                                   & (vlSelf->io_inst 
                                                      >> 0x14U)))
                                          ? vlSelf->RVNoob__DOT__rf__DOT__rf_12
                                          : ((0xbU 
                                              == (0x1fU 
                                                  & (vlSelf->io_inst 
                                                     >> 0x14U)))
                                              ? vlSelf->RVNoob__DOT__rf__DOT__rf_11
                                              : ((0xaU 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->io_inst 
                                                      >> 0x14U)))
                                                  ? vlSelf->RVNoob__DOT__rf__DOT__rf_10
                                                  : 
                                                 ((9U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->io_inst 
                                                       >> 0x14U)))
                                                   ? vlSelf->RVNoob__DOT__rf__DOT__rf_9
                                                   : 
                                                  ((8U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->io_inst 
                                                        >> 0x14U)))
                                                    ? vlSelf->RVNoob__DOT__rf__DOT__rf_8
                                                    : 
                                                   ((7U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->io_inst 
                                                         >> 0x14U)))
                                                     ? vlSelf->RVNoob__DOT__rf__DOT__rf_7
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->io_inst 
                                                          >> 0x14U)))
                                                      ? vlSelf->RVNoob__DOT__rf__DOT__rf_6
                                                      : 
                                                     ((5U 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelf->io_inst 
                                                           >> 0x14U)))
                                                       ? vlSelf->RVNoob__DOT__rf__DOT__rf_5
                                                       : 
                                                      ((4U 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->io_inst 
                                                            >> 0x14U)))
                                                        ? vlSelf->RVNoob__DOT__rf__DOT__rf_4
                                                        : 
                                                       ((3U 
                                                         == 
                                                         (0x1fU 
                                                          & (vlSelf->io_inst 
                                                             >> 0x14U)))
                                                         ? vlSelf->RVNoob__DOT__rf__DOT__rf_3
                                                         : 
                                                        ((2U 
                                                          == 
                                                          (0x1fU 
                                                           & (vlSelf->io_inst 
                                                              >> 0x14U)))
                                                          ? vlSelf->RVNoob__DOT__rf__DOT__rf_2
                                                          : 
                                                         ((1U 
                                                           == 
                                                           (0x1fU 
                                                            & (vlSelf->io_inst 
                                                               >> 0x14U)))
                                                           ? vlSelf->RVNoob__DOT__rf__DOT__rf_1
                                                           : 0ULL)))))))))))));
    vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op = (
                                                   (((((((((((((0x17U 
                                                                == 
                                                                (0x7fU 
                                                                 & vlSelf->io_inst)) 
                                                               | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi)) 
                                                              | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_add)) 
                                                             | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addiw)) 
                                                            | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addw)) 
                                                           | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sexb)) 
                                                          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sexthw)) 
                                                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_lw)) 
                                                        | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_uextb)) 
                                                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_uexthw)) 
                                                      | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_uextw)) 
                                                     | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_ld)) 
                                                    | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S))
                                                    ? 1U
                                                    : 
                                                   ((((((((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_B) 
                                                          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_slti)) 
                                                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sltiu)) 
                                                        | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sub)) 
                                                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_slt)) 
                                                      | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sltu)) 
                                                     | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_subw))
                                                     ? 2U
                                                     : 
                                                    (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sll) 
                                                      | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_slli))
                                                      ? 3U
                                                      : 
                                                     (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_srl) 
                                                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_srli))
                                                       ? 4U
                                                       : 
                                                      (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sra) 
                                                        | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_srai))
                                                        ? 5U
                                                        : 
                                                       (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_xori) 
                                                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_xor))
                                                         ? 6U
                                                         : 
                                                        (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_ori) 
                                                          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_or))
                                                          ? 7U
                                                          : 
                                                         (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_andi) 
                                                           | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_and))
                                                           ? 8U
                                                           : 
                                                          (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_mul) 
                                                            | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulw))
                                                            ? 9U
                                                            : 
                                                           ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_divu)
                                                             ? 0xaU
                                                             : 
                                                            ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_remu)
                                                              ? 0xbU
                                                              : 
                                                             ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulhu)
                                                               ? 0xcU
                                                               : 
                                                              ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulh)
                                                                ? 0xdU
                                                                : 
                                                               ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulhsu)
                                                                 ? 0xeU
                                                                 : 
                                                                ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_div)
                                                                  ? 0xfU
                                                                  : 
                                                                 ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_divw)
                                                                   ? 0x10U
                                                                   : 
                                                                  ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_divw)
                                                                    ? 0x11U
                                                                    : 
                                                                   ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_rem)
                                                                     ? 0x12U
                                                                     : 
                                                                    ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_remw)
                                                                      ? 0x13U
                                                                      : 
                                                                     ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvm_remw)
                                                                       ? 0x14U
                                                                       : 
                                                                      (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_srliw) 
                                                                        | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_srlw))
                                                                        ? 0x15U
                                                                        : 
                                                                       (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sraiw) 
                                                                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sraw))
                                                                         ? 0x16U
                                                                         : 
                                                                        (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_slliw) 
                                                                          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sllw))
                                                                          ? 0x17U
                                                                          : 0U)))))))))))))))))))))));
    vlSelf->RVNoob__DOT__idu_io_pc_mux = ((0x6fU == 
                                           (0x7fU & vlSelf->io_inst)) 
                                          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr));
    vlSelf->RVNoob__DOT__idu__DOT__type_I = (((((((
                                                   ((((((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr) 
                                                          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi)) 
                                                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_slti)) 
                                                        | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sltiu)) 
                                                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_xori)) 
                                                      | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_ori)) 
                                                     | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_andi)) 
                                                    | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_slli)) 
                                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_srli)) 
                                                  | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_srai)) 
                                                 | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addiw)) 
                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_slliw)) 
                                               | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_srliw)) 
                                              | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_sraiw)) 
                                             | (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem));
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
    vlSelf->RVNoob__DOT__rf__DOT___GEN_89 = ((0x1aU 
                                              == (0x1fU 
                                                  & (vlSelf->io_inst 
                                                     >> 0x14U)))
                                              ? vlSelf->RVNoob__DOT__rf__DOT__rf_26
                                              : ((0x19U 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->io_inst 
                                                      >> 0x14U)))
                                                  ? vlSelf->RVNoob__DOT__rf__DOT__rf_25
                                                  : 
                                                 ((0x18U 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->io_inst 
                                                       >> 0x14U)))
                                                   ? vlSelf->RVNoob__DOT__rf__DOT__rf_24
                                                   : 
                                                  ((0x17U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->io_inst 
                                                        >> 0x14U)))
                                                    ? vlSelf->RVNoob__DOT__rf__DOT__rf_23
                                                    : 
                                                   ((0x16U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->io_inst 
                                                         >> 0x14U)))
                                                     ? vlSelf->RVNoob__DOT__rf__DOT__rf_22
                                                     : 
                                                    ((0x15U 
                                                      == 
                                                      (0x1fU 
                                                       & (vlSelf->io_inst 
                                                          >> 0x14U)))
                                                      ? vlSelf->RVNoob__DOT__rf__DOT__rf_21
                                                      : 
                                                     ((0x14U 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelf->io_inst 
                                                           >> 0x14U)))
                                                       ? vlSelf->RVNoob__DOT__rf__DOT__rf_20
                                                       : 
                                                      ((0x13U 
                                                        == 
                                                        (0x1fU 
                                                         & (vlSelf->io_inst 
                                                            >> 0x14U)))
                                                        ? vlSelf->RVNoob__DOT__rf__DOT__rf_19
                                                        : 
                                                       ((0x12U 
                                                         == 
                                                         (0x1fU 
                                                          & (vlSelf->io_inst 
                                                             >> 0x14U)))
                                                         ? vlSelf->RVNoob__DOT__rf__DOT__rf_18
                                                         : 
                                                        ((0x11U 
                                                          == 
                                                          (0x1fU 
                                                           & (vlSelf->io_inst 
                                                              >> 0x14U)))
                                                          ? vlSelf->RVNoob__DOT__rf__DOT__rf_17
                                                          : 
                                                         ((0x10U 
                                                           == 
                                                           (0x1fU 
                                                            & (vlSelf->io_inst 
                                                               >> 0x14U)))
                                                           ? vlSelf->RVNoob__DOT__rf__DOT__rf_16
                                                           : 
                                                          ((0xfU 
                                                            == 
                                                            (0x1fU 
                                                             & (vlSelf->io_inst 
                                                                >> 0x14U)))
                                                            ? vlSelf->RVNoob__DOT__rf__DOT__rf_15
                                                            : 
                                                           ((0xeU 
                                                             == 
                                                             (0x1fU 
                                                              & (vlSelf->io_inst 
                                                                 >> 0x14U)))
                                                             ? vlSelf->RVNoob__DOT__rf__DOT__rf_14
                                                             : RVNoob__DOT__rf__DOT___GEN_76)))))))))))));
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_div_res_T 
        = ((0xaU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
           | (0xfU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)));
    vlSelf->RVNoob__DOT__idu_io_wen = ((((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_R) 
                                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_I)) 
                                        | (0x6fU == 
                                           (0x7fU & vlSelf->io_inst))) 
                                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_U));
    RVNoob__DOT__idu__DOT___io_imm_T_5 = (((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_I)
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
                                            : 0ULL) 
                                          | ((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_U)
                                              ? (((QData)((IData)(
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
                                              : 0ULL));
    vlSelf->RVNoob__DOT__rf_io_rdata1 = (((((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_I) 
                                            | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_R)) 
                                           | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S)) 
                                          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_B))
                                          ? ((0x1fU 
                                              == (0x1fU 
                                                  & (vlSelf->io_inst 
                                                     >> 0xfU)))
                                              ? vlSelf->RVNoob__DOT__rf__DOT__rf_31
                                              : ((0x1eU 
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
                                          : 0ULL);
    vlSelf->RVNoob__DOT__rf_io_rdata2 = ((((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S) 
                                           | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_R)) 
                                          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_B))
                                          ? ((0x1fU 
                                              == (0x1fU 
                                                  & (vlSelf->io_inst 
                                                     >> 0x14U)))
                                              ? vlSelf->RVNoob__DOT__rf__DOT__rf_31
                                              : ((0x1eU 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->io_inst 
                                                      >> 0x14U)))
                                                  ? vlSelf->RVNoob__DOT__rf__DOT__rf_30
                                                  : 
                                                 ((0x1dU 
                                                   == 
                                                   (0x1fU 
                                                    & (vlSelf->io_inst 
                                                       >> 0x14U)))
                                                   ? vlSelf->RVNoob__DOT__rf__DOT__rf_29
                                                   : 
                                                  ((0x1cU 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->io_inst 
                                                        >> 0x14U)))
                                                    ? vlSelf->RVNoob__DOT__rf__DOT__rf_28
                                                    : 
                                                   ((0x1bU 
                                                     == 
                                                     (0x1fU 
                                                      & (vlSelf->io_inst 
                                                         >> 0x14U)))
                                                     ? vlSelf->RVNoob__DOT__rf__DOT__rf_27
                                                     : vlSelf->RVNoob__DOT__rf__DOT___GEN_89)))))
                                          : 0ULL);
    RVNoob__DOT__idu__DOT___io_imm_T_7 = ((RVNoob__DOT__idu__DOT___io_imm_T_5 
                                           | ((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S)
                                               ? ((
                                                   ((QData)((IData)(
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
                                                                     | (((QData)((IData)(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo_lo)) 
                                                                         << 0x33U) 
                                                                        | (((QData)((IData)(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo)) 
                                                                            << 0x26U) 
                                                                           | ((QData)((IData)(
                                                                                ((0x2000000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 6U)) 
                                                                                | ((0x1000000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 7U)) 
                                                                                | ((0x800000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 8U)) 
                                                                                | ((0x400000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 9U)) 
                                                                                | ((0x200000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0xaU)) 
                                                                                | ((0x100000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0xbU)) 
                                                                                | ((0x80000U 
                                                                                & (vlSelf->io_inst 
                                                                                >> 0xcU)) 
                                                                                | (((IData)(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo_lo) 
                                                                                << 0xdU) 
                                                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo))))))))))) 
                                                                              << 0xcU)))))))))) 
                                                  | (QData)((IData)(
                                                                    ((0xfe0U 
                                                                      & (vlSelf->io_inst 
                                                                         >> 0x14U)) 
                                                                     | (0x1fU 
                                                                        & (vlSelf->io_inst 
                                                                           >> 7U))))))
                                               : 0ULL)) 
                                          | ((0x6fU 
                                              == (0x7fU 
                                                  & vlSelf->io_inst))
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
    vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1 = ((
                                                   (0x37U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->io_inst)) 
                                                   | (0x17U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->io_inst)))
                                                   ? vlSelf->RVNoob__DOT__pc
                                                   : vlSelf->RVNoob__DOT__rf_io_rdata1);
    vlSelf->RVNoob__DOT__idu_io_imm = (RVNoob__DOT__idu__DOT___io_imm_T_7 
                                       | ((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_B)
                                           ? ((vlSelf->RVNoob__DOT__idu__DOT__immB_hi_hi_hi_1 
                                               << 0xdU) 
                                              | (QData)((IData)(
                                                                ((0x1000U 
                                                                  & (vlSelf->io_inst 
                                                                     >> 0x13U)) 
                                                                 | ((0x800U 
                                                                     & (vlSelf->io_inst 
                                                                        << 4U)) 
                                                                    | ((0x7e0U 
                                                                        & (vlSelf->io_inst 
                                                                           >> 0x14U)) 
                                                                       | (0x1eU 
                                                                          & (vlSelf->io_inst 
                                                                             >> 7U))))))))
                                           : 0ULL));
    vlSelf->RVNoob__DOT__npc_add_res = (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr)
                                          ? vlSelf->RVNoob__DOT__rf_io_rdata1
                                          : vlSelf->RVNoob__DOT__pc) 
                                        + vlSelf->RVNoob__DOT__idu_io_imm);
    vlSelf->RVNoob__DOT__exe__DOT__alu_io_src2 = ((
                                                   ((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_I) 
                                                    | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S)) 
                                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_U))
                                                   ? vlSelf->RVNoob__DOT__idu_io_imm
                                                   : vlSelf->RVNoob__DOT__rf_io_rdata2);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2 
        = ((2U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
            ? (1ULL + (~ vlSelf->RVNoob__DOT__exe__DOT__alu_io_src2))
            : vlSelf->RVNoob__DOT__exe__DOT__alu_io_src2);
    VL_EXTEND_WQ(128,64, __Vtemp93, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    VL_EXTEND_WQ(128,64, __Vtemp94, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2);
    VL_MUL_W(4, __Vtemp95, __Vtemp93, __Vtemp94);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[0U] 
        = __Vtemp95[0U];
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[1U] 
        = __Vtemp95[1U];
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[2U] 
        = __Vtemp95[2U];
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[3U] 
        = __Vtemp95[3U];
    VL_EXTEND_WQ(65,64, __Vtemp98, VL_DIV_QQQ(64, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2));
    VL_EXTENDS_WQ(65,64, __Vtemp100, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    __Vtemp101[0U] = __Vtemp100[0U];
    __Vtemp101[1U] = __Vtemp100[1U];
    __Vtemp101[2U] = (1U & __Vtemp100[2U]);
    VL_EXTENDS_WQ(65,64, __Vtemp103, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2);
    __Vtemp104[0U] = __Vtemp103[0U];
    __Vtemp104[1U] = __Vtemp103[1U];
    __Vtemp104[2U] = (1U & __Vtemp103[2U]);
    VL_DIVS_WWW(65, __Vtemp105, __Vtemp101, __Vtemp104);
    VL_EXTEND_WQ(65,33, __Vtemp108, (0x1ffffffffULL 
                                     & ((0x11U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                         ? (QData)((IData)(
                                                           VL_DIV_III(32, (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1), (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2))))
                                         : VL_DIVS_QQQ(33, 
                                                       (0x1ffffffffULL 
                                                        & VL_EXTENDS_QI(33,32, (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1))), 
                                                       (0x1ffffffffULL 
                                                        & VL_EXTENDS_QI(33,32, (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2)))))));
    VL_EXTEND_WQ(95,64, __Vtemp111, (((QData)((IData)(
                                                      ((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_div_res_T)
                                                        ? 
                                                       ((0xaU 
                                                         == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                         ? 
                                                        __Vtemp98[1U]
                                                         : 
                                                        __Vtemp105[1U])
                                                        : 
                                                       __Vtemp108[1U]))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  ((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_div_res_T)
                                                                    ? 
                                                                   ((0xaU 
                                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                                     ? 
                                                                    __Vtemp98[0U]
                                                                     : 
                                                                    __Vtemp105[0U])
                                                                    : 
                                                                   __Vtemp108[0U])))));
    VL_EXTEND_WQ(95,64, __Vtemp112, (((0x14U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                                      | (0x13U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                                      ? (QData)((IData)(
                                                        ((0x14U 
                                                          == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                          ? 
                                                         VL_MODDIV_III(32, (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1), (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2))
                                                          : 
                                                         VL_MODDIVS_III(32, (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1), (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2)))))
                                      : ((0x12U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                          ? VL_MODDIVS_QQQ(64, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2)
                                          : VL_MODDIV_QQQ(64, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2))));
    VL_EXTEND_WI(95,32, __Vtemp113, ((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1) 
                                     >> (0x1fU & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2))));
    VL_EXTEND_WI(95,32, __Vtemp114, VL_SHIFTRS_III(32,32,5, (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1), 
                                                   (0x1fU 
                                                    & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2))));
    VL_EXTEND_WQ(95,64, __Vtemp115, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    VL_SHIFTL_WWI(95,95,5, __Vtemp116, __Vtemp115, 
                  (0x1fU & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2)));
    if ((((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_div_res_T) 
          | (0x11U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
         | (0x10U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))) {
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[0U] 
            = __Vtemp111[0U];
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[1U] 
            = __Vtemp111[1U];
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[2U] 
            = (0x7fffffffU & __Vtemp111[2U]);
    } else {
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[0U] 
            = (((((0xbU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                  | (0x12U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                 | (0x14U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                | (0x13U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                ? __Vtemp112[0U] : ((0x15U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                     ? __Vtemp113[0U]
                                     : ((0x16U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                         ? __Vtemp114[0U]
                                         : ((0x17U 
                                             == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                             ? __Vtemp116[0U]
                                             : 0U))));
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[1U] 
            = (((((0xbU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                  | (0x12U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                 | (0x14U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                | (0x13U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                ? __Vtemp112[1U] : ((0x15U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                     ? __Vtemp113[1U]
                                     : ((0x16U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                         ? __Vtemp114[1U]
                                         : ((0x17U 
                                             == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                             ? __Vtemp116[1U]
                                             : 0U))));
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[2U] 
            = (0x7fffffffU & (((((0xbU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                                 | (0x12U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                | (0x14U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                               | (0x13U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                               ? __Vtemp112[2U] : (
                                                   (0x15U 
                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                    ? 
                                                   __Vtemp113[2U]
                                                    : 
                                                   ((0x16U 
                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                     ? 
                                                    __Vtemp114[2U]
                                                     : 
                                                    ((0x17U 
                                                      == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                      ? 
                                                     __Vtemp116[2U]
                                                      : 0U)))));
    }
    VL_EXTEND_WQ(65,64, __Vtemp130, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    VL_EXTEND_WQ(65,64, __Vtemp131, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2);
    VL_ADD_W(3, __Vtemp132, __Vtemp130, __Vtemp131);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U] 
        = __Vtemp132[0U];
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[1U] 
        = __Vtemp132[1U];
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[2U] 
        = (1U & __Vtemp132[2U]);
    VL_EXTEND_WQ(95,64, __Vtemp134, (vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1 
                                     >> (0x3fU & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2))));
    VL_EXTEND_WQ(95,64, __Vtemp135, VL_SHIFTRS_QQI(64,64,6, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1, 
                                                   (0x3fU 
                                                    & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2))));
    VL_EXTEND_WQ(95,64, __Vtemp136, (vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1 
                                     ^ vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2));
    VL_EXTEND_WQ(95,64, __Vtemp137, (vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1 
                                     | vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2));
    VL_EXTEND_WQ(95,64, __Vtemp138, (vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1 
                                     & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2));
    VL_EXTENDS_WQ(129,64, __Vtemp141, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    __Vtemp142[0U] = __Vtemp141[0U];
    __Vtemp142[1U] = __Vtemp141[1U];
    __Vtemp142[2U] = __Vtemp141[2U];
    __Vtemp142[3U] = __Vtemp141[3U];
    __Vtemp142[4U] = (1U & __Vtemp141[4U]);
    VL_EXTEND_WQ(65,64, __Vtemp144, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2);
    VL_EXTENDS_WW(129,65, __Vtemp145, __Vtemp144);
    __Vtemp146[0U] = __Vtemp145[0U];
    __Vtemp146[1U] = __Vtemp145[1U];
    __Vtemp146[2U] = __Vtemp145[2U];
    __Vtemp146[3U] = __Vtemp145[3U];
    __Vtemp146[4U] = (1U & __Vtemp145[4U]);
    VL_MULS_WWW(129,129,129, __Vtemp147, __Vtemp142, __Vtemp146);
    VL_EXTENDS_WQ(128,64, __Vtemp149, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    VL_EXTENDS_WQ(128,64, __Vtemp150, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2);
    VL_MULS_WWW(128,128,128, __Vtemp151, __Vtemp149, __Vtemp150);
    VL_EXTEND_WQ(128,64, __Vtemp152, ((0xeU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                       ? (((QData)((IData)(
                                                           __Vtemp147[3U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            __Vtemp147[2U])))
                                       : (((QData)((IData)(
                                                           __Vtemp151[3U])) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            __Vtemp151[2U])))));
    VL_EXTEND_WQ(128,64, __Vtemp153, (((QData)((IData)(
                                                       vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[3U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[2U]))));
    VL_EXTEND_WQ(95,64, __Vtemp158, (((QData)((IData)(
                                                      (((0xeU 
                                                         == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                                                        | (0xdU 
                                                           == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                                                        ? 
                                                       __Vtemp152[1U]
                                                        : 
                                                       ((0xcU 
                                                         == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                         ? 
                                                        __Vtemp153[1U]
                                                         : 
                                                        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[1U])))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (((0xeU 
                                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                                                                    | (0xdU 
                                                                       == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                                                                    ? 
                                                                   __Vtemp152[0U]
                                                                    : 
                                                                   ((0xcU 
                                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                                     ? 
                                                                    __Vtemp153[0U]
                                                                     : 
                                                                    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[0U]))))));
    if ((4U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) {
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42[0U] 
            = __Vtemp134[0U];
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42[1U] 
            = __Vtemp134[1U];
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42[2U] 
            = __Vtemp134[2U];
    } else {
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42[0U] 
            = ((5U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                ? __Vtemp135[0U] : ((6U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                     ? __Vtemp136[0U]
                                     : ((7U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                         ? __Vtemp137[0U]
                                         : ((8U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                             ? __Vtemp138[0U]
                                             : ((((
                                                   (9U 
                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                                                   | (0xcU 
                                                      == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                                  | (0xdU 
                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                                 | (0xeU 
                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                                                 ? 
                                                __Vtemp158[0U]
                                                 : 
                                                RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[0U])))));
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42[1U] 
            = ((5U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                ? __Vtemp135[1U] : ((6U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                     ? __Vtemp136[1U]
                                     : ((7U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                         ? __Vtemp137[1U]
                                         : ((8U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                             ? __Vtemp138[1U]
                                             : ((((
                                                   (9U 
                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                                                   | (0xcU 
                                                      == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                                  | (0xdU 
                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                                 | (0xeU 
                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                                                 ? 
                                                __Vtemp158[1U]
                                                 : 
                                                RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[1U])))));
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42[2U] 
            = ((5U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                ? __Vtemp135[2U] : ((6U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                     ? __Vtemp136[2U]
                                     : ((7U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                         ? __Vtemp137[2U]
                                         : ((8U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                             ? __Vtemp138[2U]
                                             : ((((
                                                   (9U 
                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                                                   | (0xcU 
                                                      == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                                  | (0xdU 
                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                                 | (0xeU 
                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                                                 ? 
                                                __Vtemp158[2U]
                                                 : 
                                                RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[2U])))));
    }
    if (vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem) {
        VRVNoob___024root____Vdpiimwrap_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_read_dpi_TOP(0ULL, vlSelf->__Vtask_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_read_dpi__0__rdata);
        vlSelf->RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__rdata_t 
            = vlSelf->__Vtask_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_read_dpi__0__rdata;
    } else {
        vlSelf->RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__rdata_t = 0ULL;
    }
    if (vlSelf->RVNoob__DOT__idu__DOT__type_S) {
        VL_EXTEND_WQ(191,64, __Vtemp172, vlSelf->RVNoob__DOT__rf_io_rdata2);
        VL_SHIFTL_WWI(191,191,7, __Vtemp173, __Vtemp172, 
                      (0x38U & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U] 
                                << 3U)));
        VRVNoob___024root____Vdpiimwrap_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_write_dpi_TOP(0ULL, 
                                                                                (((QData)((IData)(
                                                                                __Vtemp173[1U])) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                __Vtemp173[0U]))), 
                                                                                ((3U 
                                                                                == (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))
                                                                                 ? 0xffU
                                                                                 : 
                                                                                (0xffU 
                                                                                & ((2U 
                                                                                == (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))
                                                                                 ? 
                                                                                ((IData)(0xfU) 
                                                                                << 
                                                                                (7U 
                                                                                & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U]))
                                                                                 : 
                                                                                (0x1ffU 
                                                                                & ((1U 
                                                                                == (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))
                                                                                 ? 
                                                                                ((IData)(3U) 
                                                                                << 
                                                                                (7U 
                                                                                & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U]))
                                                                                 : 
                                                                                ((0U 
                                                                                == (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))
                                                                                 ? 
                                                                                (0xffU 
                                                                                & ((IData)(1U) 
                                                                                << 
                                                                                (7U 
                                                                                & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U])))
                                                                                 : 0xffU)))))));
    }
    VL_EXTEND_WQ(127,64, __Vtemp176, (((QData)((IData)(
                                                       vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[1U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U]))));
    VL_EXTEND_WQ(127,64, __Vtemp177, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    VL_SHIFTL_WWI(127,127,6, __Vtemp178, __Vtemp177, 
                  (0x3fU & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2)));
    VL_EXTEND_WW(127,95, __Vtemp179, RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42);
    if (((1U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
         | (2U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))) {
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[0U] 
            = __Vtemp176[0U];
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[1U] 
            = __Vtemp176[1U];
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[2U] 
            = __Vtemp176[2U];
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[3U] 
            = (0x7fffffffU & __Vtemp176[3U]);
    } else {
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[0U] 
            = ((3U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                ? __Vtemp178[0U] : __Vtemp179[0U]);
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[1U] 
            = ((3U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                ? __Vtemp178[1U] : __Vtemp179[1U]);
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[2U] 
            = ((3U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                ? __Vtemp178[2U] : __Vtemp179[2U]);
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[3U] 
            = (0x7fffffffU & ((3U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                               ? __Vtemp178[3U] : __Vtemp179[3U]));
    }
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
        = ((IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem)
            ? ((0x3fU >= (0x38U & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U] 
                                   << 3U))) ? (vlSelf->RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__rdata_t 
                                               >> (0x38U 
                                                   & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U] 
                                                      << 3U)))
                : 0ULL) : (((QData)((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[0U]))));
    VRVNoob___024unit____Vdpiimwrap_npc_change_TOP____024unit(
                                                              ((1U 
                                                                & ((IData)(vlSelf->RVNoob__DOT__idu_io_pc_mux) 
                                                                   | ((1U 
                                                                       == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                                       ? 
                                                                      (0ULL 
                                                                       == vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res)
                                                                       : 
                                                                      ((2U 
                                                                        == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                                        ? 
                                                                       (0ULL 
                                                                        != vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res)
                                                                        : 
                                                                       ((3U 
                                                                         == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                                         ? 
                                                                        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[2U]
                                                                         : 
                                                                        ((4U 
                                                                          == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op)) 
                                                                         & ((~ 
                                                                             vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[2U]) 
                                                                            | (0ULL 
                                                                               == vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res))))))))
                                                                ? 
                                                               ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr)
                                                                 ? 
                                                                (0xfffffffffffffffeULL 
                                                                 & vlSelf->RVNoob__DOT__npc_add_res)
                                                                 : vlSelf->RVNoob__DOT__npc_add_res)
                                                                : 
                                                               (4ULL 
                                                                + vlSelf->RVNoob__DOT__pc)));
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo 
        = ((0x80U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                              >> 0x1fU)) << 7U)) | 
           ((0x40U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                               >> 0x1fU)) << 6U)) | 
            ((0x20U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                >> 0x1fU)) << 5U)) 
             | ((0x10U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                   >> 0x1fU)) << 4U)) 
                | ((8U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                   >> 0x1fU)) << 3U)) 
                   | ((4U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                      >> 0x1fU)) << 2U)) 
                      | ((2U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                         >> 0x1fU)) 
                                << 1U)) | (1U & (IData)(
                                                        (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                         >> 0x1fU))))))))));
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_1 
        = ((0x20U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                              >> 0xfU)) << 5U)) | (
                                                   (0x10U 
                                                    & ((IData)(
                                                               (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                >> 0xfU)) 
                                                       << 4U)) 
                                                   | ((8U 
                                                       & ((IData)(
                                                                  (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                   >> 0xfU)) 
                                                          << 3U)) 
                                                      | ((4U 
                                                          & ((IData)(
                                                                     (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                      >> 0xfU)) 
                                                             << 2U)) 
                                                         | ((2U 
                                                             & ((IData)(
                                                                        (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                         >> 0xfU)) 
                                                                << 1U)) 
                                                            | (1U 
                                                               & (IData)(
                                                                         (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                          >> 0xfU))))))));
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2 
        = ((0x40U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                              >> 7U)) << 6U)) | ((0x20U 
                                                  & ((IData)(
                                                             (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                              >> 7U)) 
                                                     << 5U)) 
                                                 | ((0x10U 
                                                     & ((IData)(
                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                 >> 7U)) 
                                                        << 4U)) 
                                                    | ((8U 
                                                        & ((IData)(
                                                                   (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                    >> 7U)) 
                                                           << 3U)) 
                                                       | ((4U 
                                                           & ((IData)(
                                                                      (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                       >> 7U)) 
                                                              << 2U)) 
                                                          | ((2U 
                                                              & ((IData)(
                                                                         (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                          >> 7U)) 
                                                                 << 1U)) 
                                                             | (1U 
                                                                & (IData)(
                                                                          (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                           >> 7U)))))))));
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_1 
        = ((0x800U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                               >> 0xfU)) << 0xbU)) 
           | ((0x400U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                  >> 0xfU)) << 0xaU)) 
              | ((0x200U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                     >> 0xfU)) << 9U)) 
                 | ((0x100U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                        >> 0xfU)) << 8U)) 
                    | ((0x80U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                          >> 0xfU)) 
                                 << 7U)) | ((0x40U 
                                             & ((IData)(
                                                        (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                         >> 0xfU)) 
                                                << 6U)) 
                                            | (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_1)))))));
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_2 
        = ((0x2000U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                >> 7U)) << 0xdU)) | 
           ((0x1000U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                 >> 7U)) << 0xcU)) 
            | ((0x800U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                   >> 7U)) << 0xbU)) 
               | ((0x400U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                      >> 7U)) << 0xaU)) 
                  | ((0x200U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                         >> 7U)) << 9U)) 
                     | ((0x100U & ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                            >> 7U)) 
                                   << 8U)) | ((0x80U 
                                               & ((IData)(
                                                          (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                           >> 7U)) 
                                                  << 7U)) 
                                              | (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2))))))));
    RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_152 
        = ((8U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
            ? (((QData)((IData)((1U & (IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                               >> 7U))))) 
                << 0x3fU) | (((QData)((IData)((1U & (IData)(
                                                            (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                             >> 7U))))) 
                              << 0x3eU) | (((QData)((IData)(
                                                            (1U 
                                                             & (IData)(
                                                                       (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                        >> 7U))))) 
                                            << 0x3dU) 
                                           | (((QData)((IData)(
                                                               (1U 
                                                                & (IData)(
                                                                          (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                           >> 7U))))) 
                                               << 0x3cU) 
                                              | (((QData)((IData)(
                                                                  (1U 
                                                                   & (IData)(
                                                                             (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                              >> 7U))))) 
                                                  << 0x3bU) 
                                                 | (((QData)((IData)(
                                                                     (1U 
                                                                      & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U))))) 
                                                     << 0x3aU) 
                                                    | (((QData)((IData)(
                                                                        (1U 
                                                                         & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U))))) 
                                                        << 0x39U) 
                                                       | (((QData)((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2)) 
                                                           << 0x32U) 
                                                          | (((QData)((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_2)) 
                                                              << 0x24U) 
                                                             | (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U))))) 
                                                                 << 0x23U) 
                                                                | (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U))))) 
                                                                    << 0x22U) 
                                                                   | (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U))))) 
                                                                       << 0x21U) 
                                                                      | (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U))))) 
                                                                          << 0x20U) 
                                                                         | (QData)((IData)(
                                                                                (((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U)) 
                                                                                << 0x1fU) 
                                                                                | ((0x40000000U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U)) 
                                                                                << 0x1eU)) 
                                                                                | ((0x20000000U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U)) 
                                                                                << 0x1dU)) 
                                                                                | (((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_2) 
                                                                                << 8U) 
                                                                                | (0xffU 
                                                                                & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res))))))))))))))))))))))
            : ((9U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                ? (QData)((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res))
                : ((0xaU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                    ? (QData)((IData)((0xffffU & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res))))
                    : ((0xbU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                        ? (QData)((IData)((0xffU & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res))))
                        : vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res))));
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_154 
        = ((6U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
            ? (((QData)((IData)((((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                           >> 0x1fU)) 
                                  << 0x1fU) | ((0x40000000U 
                                                & ((IData)(
                                                           (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                            >> 0x1fU)) 
                                                   << 0x1eU)) 
                                               | ((0x20000000U 
                                                   & ((IData)(
                                                              (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                               >> 0x1fU)) 
                                                      << 0x1dU)) 
                                                  | ((0x10000000U 
                                                      & ((IData)(
                                                                 (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                  >> 0x1fU)) 
                                                         << 0x1cU)) 
                                                     | ((0x8000000U 
                                                         & ((IData)(
                                                                    (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                     >> 0x1fU)) 
                                                            << 0x1bU)) 
                                                        | ((0x4000000U 
                                                            & ((IData)(
                                                                       (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                        >> 0x1fU)) 
                                                               << 0x1aU)) 
                                                           | ((0x2000000U 
                                                               & ((IData)(
                                                                          (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                           >> 0x1fU)) 
                                                                  << 0x19U)) 
                                                              | ((0x1000000U 
                                                                  & ((IData)(
                                                                             (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                              >> 0x1fU)) 
                                                                     << 0x18U)) 
                                                                 | (((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo) 
                                                                     << 0x10U) 
                                                                    | ((0x8000U 
                                                                        & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0x1fU)) 
                                                                           << 0xfU)) 
                                                                       | ((0x4000U 
                                                                           & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0x1fU)) 
                                                                              << 0xeU)) 
                                                                          | ((0x2000U 
                                                                              & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0x1fU)) 
                                                                                << 0xdU)) 
                                                                             | ((0x1000U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0x1fU)) 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0x1fU)) 
                                                                                << 0xbU)) 
                                                                                | ((0x400U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0x1fU)) 
                                                                                << 0xaU)) 
                                                                                | ((0x200U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0x1fU)) 
                                                                                << 9U)) 
                                                                                | ((0x100U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0x1fU)) 
                                                                                << 8U)) 
                                                                                | (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo)))))))))))))))))))) 
                << 0x20U) | (QData)((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res)))
            : ((7U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                ? (((QData)((IData)((1U & (IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                   >> 0xfU))))) 
                    << 0x3fU) | (((QData)((IData)((1U 
                                                   & (IData)(
                                                             (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                              >> 0xfU))))) 
                                  << 0x3eU) | (((QData)((IData)(
                                                                (1U 
                                                                 & (IData)(
                                                                           (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                            >> 0xfU))))) 
                                                << 0x3dU) 
                                               | (((QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                               >> 0xfU))))) 
                                                   << 0x3cU) 
                                                  | (((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0xfU))))) 
                                                      << 0x3bU) 
                                                     | (((QData)((IData)(
                                                                         (1U 
                                                                          & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0xfU))))) 
                                                         << 0x3aU) 
                                                        | (((QData)((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_1)) 
                                                            << 0x34U) 
                                                           | (((QData)((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_1)) 
                                                               << 0x28U) 
                                                              | (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0xfU))))) 
                                                                  << 0x27U) 
                                                                 | (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0xfU))))) 
                                                                     << 0x26U) 
                                                                    | (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0xfU))))) 
                                                                        << 0x25U) 
                                                                       | (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0xfU))))) 
                                                                           << 0x24U) 
                                                                          | (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0xfU))))) 
                                                                              << 0x23U) 
                                                                             | (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 0xfU))))) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_1)) 
                                                                                << 0x1cU) 
                                                                                | (QData)((IData)(
                                                                                (((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_1) 
                                                                                << 0x10U) 
                                                                                | (0xffffU 
                                                                                & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res))))))))))))))))))))
                : RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_152));
    vlSelf->RVNoob__DOT__exe_io_gp_out = ((((0x37U 
                                             == (0x7fU 
                                                 & vlSelf->io_inst)) 
                                            | (0x6fU 
                                               == (0x7fU 
                                                   & vlSelf->io_inst))) 
                                           | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))
                                           ? ((0x37U 
                                               == (0x7fU 
                                                   & vlSelf->io_inst))
                                               ? vlSelf->RVNoob__DOT__idu_io_imm
                                               : (4ULL 
                                                  + vlSelf->RVNoob__DOT__pc))
                                           : ((((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_slt) 
                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sextw)) 
                                               | (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem))
                                               ? ((5U 
                                                   == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                   ? (QData)((IData)(
                                                                     (1U 
                                                                      & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[2U])))
                                                   : vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_154)
                                               : (((QData)((IData)(
                                                                   vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[0U])))));
    vlSelf->io_res = vlSelf->RVNoob__DOT__exe_io_gp_out;
}

void VRVNoob___024root___eval(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___eval\n"); );
    // Body
    VRVNoob___024root___combo__TOP__2(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    if (((IData)(vlSelf->clock) & (~ (IData)(vlSelf->__Vclklast__TOP__clock)))) {
        VRVNoob___024root___sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    VRVNoob___024root___combo__TOP__5(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

QData VRVNoob___024root___change_request_1(VRVNoob___024root* vlSelf);

VL_INLINE_OPT QData VRVNoob___024root___change_request(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___change_request\n"); );
    // Body
    return (VRVNoob___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VRVNoob___024root___change_request_1(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VRVNoob___024root___eval_debug_assertions(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
