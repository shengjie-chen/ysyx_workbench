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
void VRVNoob___024root____Vdpiimwrap_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_read_dpi_TOP(QData/*63:0*/ raddr, QData/*63:0*/ &rdata);
void VRVNoob___024root____Vdpiimwrap_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_write_dpi_TOP(QData/*63:0*/ waddr, QData/*63:0*/ wdata, CData/*7:0*/ wmask);
void VRVNoob___024unit____Vdpiimwrap_npc_change_TOP____024unit(QData/*63:0*/ a);

void VRVNoob___024root___settle__TOP__1(VRVNoob___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRVNoob___024root___settle__TOP__1\n"); );
    // Variables
    CData/*0:0*/ RVNoob__DOT__idu__DOT___rvi_add_T_2;
    CData/*0:0*/ RVNoob__DOT__idu__DOT___rvi_srl_T_2;
    CData/*0:0*/ RVNoob__DOT__idu__DOT___rvi_addw_T_2;
    VlWide<3>/*94:0*/ RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36;
    VlWide<3>/*94:0*/ RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42;
    VlWide<4>/*127:0*/ __Vtemp1;
    VlWide<4>/*127:0*/ __Vtemp2;
    VlWide<4>/*127:0*/ __Vtemp3;
    VlWide<3>/*95:0*/ __Vtemp6;
    VlWide<3>/*95:0*/ __Vtemp8;
    VlWide<3>/*95:0*/ __Vtemp9;
    VlWide<3>/*95:0*/ __Vtemp11;
    VlWide<3>/*95:0*/ __Vtemp12;
    VlWide<3>/*95:0*/ __Vtemp13;
    VlWide<3>/*95:0*/ __Vtemp16;
    VlWide<3>/*95:0*/ __Vtemp19;
    VlWide<3>/*95:0*/ __Vtemp20;
    VlWide<3>/*95:0*/ __Vtemp21;
    VlWide<3>/*95:0*/ __Vtemp22;
    VlWide<3>/*95:0*/ __Vtemp23;
    VlWide<3>/*95:0*/ __Vtemp24;
    VlWide<3>/*95:0*/ __Vtemp38;
    VlWide<3>/*95:0*/ __Vtemp39;
    VlWide<3>/*95:0*/ __Vtemp40;
    VlWide<3>/*95:0*/ __Vtemp42;
    VlWide<3>/*95:0*/ __Vtemp43;
    VlWide<3>/*95:0*/ __Vtemp44;
    VlWide<3>/*95:0*/ __Vtemp45;
    VlWide<3>/*95:0*/ __Vtemp46;
    VlWide<5>/*159:0*/ __Vtemp49;
    VlWide<5>/*159:0*/ __Vtemp50;
    VlWide<3>/*95:0*/ __Vtemp52;
    VlWide<5>/*159:0*/ __Vtemp53;
    VlWide<5>/*159:0*/ __Vtemp54;
    VlWide<5>/*159:0*/ __Vtemp55;
    VlWide<4>/*127:0*/ __Vtemp57;
    VlWide<4>/*127:0*/ __Vtemp58;
    VlWide<4>/*127:0*/ __Vtemp59;
    VlWide<4>/*127:0*/ __Vtemp60;
    VlWide<4>/*127:0*/ __Vtemp61;
    VlWide<3>/*95:0*/ __Vtemp66;
    VlWide<6>/*191:0*/ __Vtemp80;
    VlWide<6>/*191:0*/ __Vtemp81;
    VlWide<4>/*127:0*/ __Vtemp84;
    VlWide<4>/*127:0*/ __Vtemp85;
    VlWide<4>/*127:0*/ __Vtemp86;
    VlWide<4>/*127:0*/ __Vtemp87;
    QData/*63:0*/ RVNoob__DOT__idu__DOT___io_imm_T_5;
    QData/*63:0*/ RVNoob__DOT__idu__DOT___io_imm_T_7;
    QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_44;
    QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_76;
    QData/*63:0*/ RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_152;
    // Body
    vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0U] = 0ULL;
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
    vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem = 
        (((((((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sexb) 
              | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sexthw)) 
             | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_lw)) 
            | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_uextb)) 
           | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_uexthw)) 
          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_uextw)) 
         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_ld));
    vlSelf->RVNoob__DOT__idu_io_pc_mux = ((0x6fU == 
                                           (0x7fU & vlSelf->io_inst)) 
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
    VL_EXTEND_WQ(128,64, __Vtemp1, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    VL_EXTEND_WQ(128,64, __Vtemp2, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2);
    VL_MUL_W(4, __Vtemp3, __Vtemp1, __Vtemp2);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[0U] 
        = __Vtemp3[0U];
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[1U] 
        = __Vtemp3[1U];
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[2U] 
        = __Vtemp3[2U];
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[3U] 
        = __Vtemp3[3U];
    VL_EXTEND_WQ(65,64, __Vtemp6, VL_DIV_QQQ(64, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2));
    VL_EXTENDS_WQ(65,64, __Vtemp8, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    __Vtemp9[0U] = __Vtemp8[0U];
    __Vtemp9[1U] = __Vtemp8[1U];
    __Vtemp9[2U] = (1U & __Vtemp8[2U]);
    VL_EXTENDS_WQ(65,64, __Vtemp11, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2);
    __Vtemp12[0U] = __Vtemp11[0U];
    __Vtemp12[1U] = __Vtemp11[1U];
    __Vtemp12[2U] = (1U & __Vtemp11[2U]);
    VL_DIVS_WWW(65, __Vtemp13, __Vtemp9, __Vtemp12);
    VL_EXTEND_WQ(65,33, __Vtemp16, (0x1ffffffffULL 
                                    & ((0x11U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                        ? (QData)((IData)(
                                                          VL_DIV_III(32, (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1), (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2))))
                                        : VL_DIVS_QQQ(33, 
                                                      (0x1ffffffffULL 
                                                       & VL_EXTENDS_QI(33,32, (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1))), 
                                                      (0x1ffffffffULL 
                                                       & VL_EXTENDS_QI(33,32, (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2)))))));
    VL_EXTEND_WQ(95,64, __Vtemp19, (((QData)((IData)(
                                                     ((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_div_res_T)
                                                       ? 
                                                      ((0xaU 
                                                        == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                        ? 
                                                       __Vtemp6[1U]
                                                        : 
                                                       __Vtemp13[1U])
                                                       : 
                                                      __Vtemp16[1U]))) 
                                     << 0x20U) | (QData)((IData)(
                                                                 ((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_div_res_T)
                                                                   ? 
                                                                  ((0xaU 
                                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                                    ? 
                                                                   __Vtemp6[0U]
                                                                    : 
                                                                   __Vtemp13[0U])
                                                                   : 
                                                                  __Vtemp16[0U])))));
    VL_EXTEND_WQ(95,64, __Vtemp20, (((0x14U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
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
    VL_EXTEND_WI(95,32, __Vtemp21, ((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1) 
                                    >> (0x1fU & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2))));
    VL_EXTEND_WI(95,32, __Vtemp22, VL_SHIFTRS_III(32,32,5, (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1), 
                                                  (0x1fU 
                                                   & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2))));
    VL_EXTEND_WQ(95,64, __Vtemp23, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    VL_SHIFTL_WWI(95,95,5, __Vtemp24, __Vtemp23, (0x1fU 
                                                  & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2)));
    if ((((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_div_res_T) 
          | (0x11U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
         | (0x10U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))) {
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[0U] 
            = __Vtemp19[0U];
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[1U] 
            = __Vtemp19[1U];
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[2U] 
            = (0x7fffffffU & __Vtemp19[2U]);
    } else {
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[0U] 
            = (((((0xbU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                  | (0x12U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                 | (0x14U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                | (0x13U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                ? __Vtemp20[0U] : ((0x15U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                    ? __Vtemp21[0U]
                                    : ((0x16U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                        ? __Vtemp22[0U]
                                        : ((0x17U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                            ? __Vtemp24[0U]
                                            : 0U))));
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[1U] 
            = (((((0xbU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                  | (0x12U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                 | (0x14U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                | (0x13U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                ? __Vtemp20[1U] : ((0x15U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                    ? __Vtemp21[1U]
                                    : ((0x16U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                        ? __Vtemp22[1U]
                                        : ((0x17U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                            ? __Vtemp24[1U]
                                            : 0U))));
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[2U] 
            = (0x7fffffffU & (((((0xbU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                                 | (0x12U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                | (0x14U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                               | (0x13U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                               ? __Vtemp20[2U] : ((0x15U 
                                                   == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                   ? 
                                                  __Vtemp21[2U]
                                                   : 
                                                  ((0x16U 
                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                    ? 
                                                   __Vtemp22[2U]
                                                    : 
                                                   ((0x17U 
                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                     ? 
                                                    __Vtemp24[2U]
                                                     : 0U)))));
    }
    VL_EXTEND_WQ(65,64, __Vtemp38, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    VL_EXTEND_WQ(65,64, __Vtemp39, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2);
    VL_ADD_W(3, __Vtemp40, __Vtemp38, __Vtemp39);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U] 
        = __Vtemp40[0U];
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[1U] 
        = __Vtemp40[1U];
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[2U] 
        = (1U & __Vtemp40[2U]);
    VL_EXTEND_WQ(95,64, __Vtemp42, (vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1 
                                    >> (0x3fU & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2))));
    VL_EXTEND_WQ(95,64, __Vtemp43, VL_SHIFTRS_QQI(64,64,6, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1, 
                                                  (0x3fU 
                                                   & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2))));
    VL_EXTEND_WQ(95,64, __Vtemp44, (vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1 
                                    ^ vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2));
    VL_EXTEND_WQ(95,64, __Vtemp45, (vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1 
                                    | vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2));
    VL_EXTEND_WQ(95,64, __Vtemp46, (vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1 
                                    & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2));
    VL_EXTENDS_WQ(129,64, __Vtemp49, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    __Vtemp50[0U] = __Vtemp49[0U];
    __Vtemp50[1U] = __Vtemp49[1U];
    __Vtemp50[2U] = __Vtemp49[2U];
    __Vtemp50[3U] = __Vtemp49[3U];
    __Vtemp50[4U] = (1U & __Vtemp49[4U]);
    VL_EXTEND_WQ(65,64, __Vtemp52, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2);
    VL_EXTENDS_WW(129,65, __Vtemp53, __Vtemp52);
    __Vtemp54[0U] = __Vtemp53[0U];
    __Vtemp54[1U] = __Vtemp53[1U];
    __Vtemp54[2U] = __Vtemp53[2U];
    __Vtemp54[3U] = __Vtemp53[3U];
    __Vtemp54[4U] = (1U & __Vtemp53[4U]);
    VL_MULS_WWW(129,129,129, __Vtemp55, __Vtemp50, __Vtemp54);
    VL_EXTENDS_WQ(128,64, __Vtemp57, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    VL_EXTENDS_WQ(128,64, __Vtemp58, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2);
    VL_MULS_WWW(128,128,128, __Vtemp59, __Vtemp57, __Vtemp58);
    VL_EXTEND_WQ(128,64, __Vtemp60, ((0xeU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                      ? (((QData)((IData)(
                                                          __Vtemp55[3U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           __Vtemp55[2U])))
                                      : (((QData)((IData)(
                                                          __Vtemp59[3U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           __Vtemp59[2U])))));
    VL_EXTEND_WQ(128,64, __Vtemp61, (((QData)((IData)(
                                                      vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[3U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[2U]))));
    VL_EXTEND_WQ(95,64, __Vtemp66, (((QData)((IData)(
                                                     (((0xeU 
                                                        == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                                                       | (0xdU 
                                                          == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                                                       ? 
                                                      __Vtemp60[1U]
                                                       : 
                                                      ((0xcU 
                                                        == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                        ? 
                                                       __Vtemp61[1U]
                                                        : 
                                                       vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[1U])))) 
                                     << 0x20U) | (QData)((IData)(
                                                                 (((0xeU 
                                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                                                                   | (0xdU 
                                                                      == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                                                                   ? 
                                                                  __Vtemp60[0U]
                                                                   : 
                                                                  ((0xcU 
                                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                                    ? 
                                                                   __Vtemp61[0U]
                                                                    : 
                                                                   vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12[0U]))))));
    if ((4U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) {
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42[0U] 
            = __Vtemp42[0U];
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42[1U] 
            = __Vtemp42[1U];
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42[2U] 
            = __Vtemp42[2U];
    } else {
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42[0U] 
            = ((5U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                ? __Vtemp43[0U] : ((6U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                    ? __Vtemp44[0U]
                                    : ((7U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                        ? __Vtemp45[0U]
                                        : ((8U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                            ? __Vtemp46[0U]
                                            : (((((9U 
                                                   == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                                                  | (0xcU 
                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                                 | (0xdU 
                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                                | (0xeU 
                                                   == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                                                ? __Vtemp66[0U]
                                                : RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[0U])))));
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42[1U] 
            = ((5U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                ? __Vtemp43[1U] : ((6U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                    ? __Vtemp44[1U]
                                    : ((7U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                        ? __Vtemp45[1U]
                                        : ((8U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                            ? __Vtemp46[1U]
                                            : (((((9U 
                                                   == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                                                  | (0xcU 
                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                                 | (0xdU 
                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                                | (0xeU 
                                                   == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                                                ? __Vtemp66[1U]
                                                : RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[1U])))));
        RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42[2U] 
            = ((5U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                ? __Vtemp43[2U] : ((6U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                    ? __Vtemp44[2U]
                                    : ((7U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                        ? __Vtemp45[2U]
                                        : ((8U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                            ? __Vtemp46[2U]
                                            : (((((9U 
                                                   == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
                                                  | (0xcU 
                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                                 | (0xdU 
                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))) 
                                                | (0xeU 
                                                   == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))
                                                ? __Vtemp66[2U]
                                                : RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_36[2U])))));
    }
    if (vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem) {
        VRVNoob___024root____Vdpiimwrap_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_read_dpi_TOP(
                                                                                (0xfffffffffffffff8ULL 
                                                                                & (((QData)((IData)(
                                                                                vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[1U])) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U])))), vlSelf->__Vtask_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_read_dpi__0__rdata);
        vlSelf->RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__rdata_t 
            = vlSelf->__Vtask_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_read_dpi__0__rdata;
    } else {
        vlSelf->RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__rdata_t = 0ULL;
    }
    if (vlSelf->RVNoob__DOT__idu__DOT__type_S) {
        VL_EXTEND_WQ(191,64, __Vtemp80, vlSelf->RVNoob__DOT__rf_io_rdata2);
        VL_SHIFTL_WWI(191,191,7, __Vtemp81, __Vtemp80, 
                      (0x38U & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U] 
                                << 3U)));
        VRVNoob___024root____Vdpiimwrap_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_write_dpi_TOP(
                                                                                (0xfffffffffffffff8ULL 
                                                                                & (((QData)((IData)(
                                                                                vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[1U])) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U])))), 
                                                                                (((QData)((IData)(
                                                                                __Vtemp81[1U])) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                __Vtemp81[0U]))), 
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
    VL_EXTEND_WQ(127,64, __Vtemp84, (((QData)((IData)(
                                                      vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U]))));
    VL_EXTEND_WQ(127,64, __Vtemp85, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
    VL_SHIFTL_WWI(127,127,6, __Vtemp86, __Vtemp85, 
                  (0x3fU & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2)));
    VL_EXTEND_WW(127,95, __Vtemp87, RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_42);
    if (((1U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)) 
         | (2U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op)))) {
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[0U] 
            = __Vtemp84[0U];
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[1U] 
            = __Vtemp84[1U];
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[2U] 
            = __Vtemp84[2U];
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[3U] 
            = (0x7fffffffU & __Vtemp84[3U]);
    } else {
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[0U] 
            = ((3U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                ? __Vtemp86[0U] : __Vtemp87[0U]);
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[1U] 
            = ((3U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                ? __Vtemp86[1U] : __Vtemp87[1U]);
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[2U] 
            = ((3U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                ? __Vtemp86[2U] : __Vtemp87[2U]);
        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44[3U] 
            = (0x7fffffffU & ((3U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                               ? __Vtemp86[3U] : __Vtemp87[3U]));
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
    VRVNoob___024root___settle__TOP__1(vlSelf);
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
    vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op = VL_RAND_RESET_I(4);
    vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op = VL_RAND_RESET_I(5);
    vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op = VL_RAND_RESET_I(2);
    vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu_io_pc_mux = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__rf_io_rdata1 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__rf_io_rdata2 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__exe_io_gp_out = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__U_ebreak_ebreak = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__pc = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__npc_add_res = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__snpc = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__rdata_t = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_beq = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_bne = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_blt = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_bge = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_bltu = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_bgeu = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__jpg_sexb = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__jpg_sexthw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_lw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__jpg_uextb = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__jpg_uexthw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sb = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sh = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_addi = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_slti = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sltiu = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_xori = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_ori = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_andi = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_add = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sub = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sll = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_slt = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sltu = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_xor = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_srl = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sra = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_or = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_and = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__jpg_uextw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_ld = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sd = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_slli = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_srli = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_srai = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_addiw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_slliw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_srliw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sraiw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_addw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_subw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sllw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_srlw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvi_sraw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvm_mul = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvm_mulh = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvm_mulhsu = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvm_mulhu = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvm_div = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvm_divu = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvm_rem = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvm_remu = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvm_mulw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvm_divw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__rvm_remw = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__type_I = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__type_U = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__type_S = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__type_R = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__type_B = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo = VL_RAND_RESET_I(6);
    vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo = VL_RAND_RESET_I(13);
    vlSelf->RVNoob__DOT__idu__DOT__immU_lo_lo = VL_RAND_RESET_I(8);
    vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo_lo = VL_RAND_RESET_I(6);
    vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo = VL_RAND_RESET_I(13);
    vlSelf->RVNoob__DOT__idu__DOT__immJ_lo_lo_lo = VL_RAND_RESET_I(5);
    vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1 = VL_RAND_RESET_Q(44);
    vlSelf->RVNoob__DOT__idu__DOT__immB_hi_hi_hi_1 = VL_RAND_RESET_Q(51);
    vlSelf->RVNoob__DOT__idu__DOT__jpg_slt = VL_RAND_RESET_I(1);
    vlSelf->RVNoob__DOT__idu__DOT__jpg_sextw = VL_RAND_RESET_I(1);
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
    vlSelf->RVNoob__DOT__rf__DOT___GEN_89 = VL_RAND_RESET_Q(64);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__exe__DOT__alu_io_src2 = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res = VL_RAND_RESET_Q(64);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2 = VL_RAND_RESET_Q(64);
    VL_RAND_RESET_W(65, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_div_res_T = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_mul_res_T_12);
    VL_RAND_RESET_W(127, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_44);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo = VL_RAND_RESET_I(8);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_1 = VL_RAND_RESET_I(6);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_1 = VL_RAND_RESET_I(12);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2 = VL_RAND_RESET_I(7);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_2 = VL_RAND_RESET_I(14);
    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_154 = VL_RAND_RESET_Q(64);
    vlSelf->__Vtask_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_read_dpi__0__rdata = 0;
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
