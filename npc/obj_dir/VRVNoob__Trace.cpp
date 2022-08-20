// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VRVNoob__Syms.h"


void VRVNoob___024root__traceChgSub0(VRVNoob___024root* vlSelf, VerilatedVcd* tracep);

void VRVNoob___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VRVNoob___024root* const __restrict vlSelf = static_cast<VRVNoob___024root*>(voidSelf);
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VRVNoob___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VRVNoob___024root__traceChgSub0(VRVNoob___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
            tracep->chgQData(oldp+0,(vlSelf->RVNoob__DOT__idu_io_imm),64);
            tracep->chgBit(oldp+2,(vlSelf->RVNoob__DOT__idu_io_wen));
            tracep->chgBit(oldp+3,(((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                    | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))));
            tracep->chgQData(oldp+4,(vlSelf->RVNoob__DOT__exe_io_gp_out),64);
            tracep->chgBit(oldp+6,(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi));
            tracep->chgBit(oldp+7,(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr));
            tracep->chgCData(oldp+8,(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo),6);
            tracep->chgSData(oldp+9,(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo),13);
            tracep->chgCData(oldp+10,(vlSelf->RVNoob__DOT__idu__DOT__immU_lo_lo),8);
            tracep->chgCData(oldp+11,(vlSelf->RVNoob__DOT__idu__DOT__immJ_lo_lo_lo),5);
            tracep->chgQData(oldp+12,(vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1),44);
            tracep->chgQData(oldp+14,(vlSelf->RVNoob__DOT__exe__DOT__alu_out),64);
            tracep->chgQData(oldp+16,((vlSelf->RVNoob__DOT__exe__DOT__alu_out 
                                       >> 1U)),63);
        }
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
            tracep->chgQData(oldp+18,(vlSelf->RVNoob__DOT__rf__DOT__rf_10),64);
            tracep->chgQData(oldp+20,(vlSelf->RVNoob__DOT__pc),64);
            tracep->chgQData(oldp+22,((4ULL + vlSelf->RVNoob__DOT__pc)),64);
            tracep->chgBit(oldp+24,(vlSelf->RVNoob__DOT__U_ebreak_ebreak));
            tracep->chgQData(oldp+25,(vlSelf->RVNoob__DOT__rf__DOT__rf_0),64);
            tracep->chgQData(oldp+27,(vlSelf->RVNoob__DOT__rf__DOT__rf_1),64);
            tracep->chgQData(oldp+29,(vlSelf->RVNoob__DOT__rf__DOT__rf_2),64);
            tracep->chgQData(oldp+31,(vlSelf->RVNoob__DOT__rf__DOT__rf_3),64);
            tracep->chgQData(oldp+33,(vlSelf->RVNoob__DOT__rf__DOT__rf_4),64);
            tracep->chgQData(oldp+35,(vlSelf->RVNoob__DOT__rf__DOT__rf_5),64);
            tracep->chgQData(oldp+37,(vlSelf->RVNoob__DOT__rf__DOT__rf_6),64);
            tracep->chgQData(oldp+39,(vlSelf->RVNoob__DOT__rf__DOT__rf_7),64);
            tracep->chgQData(oldp+41,(vlSelf->RVNoob__DOT__rf__DOT__rf_8),64);
            tracep->chgQData(oldp+43,(vlSelf->RVNoob__DOT__rf__DOT__rf_9),64);
            tracep->chgQData(oldp+45,(vlSelf->RVNoob__DOT__rf__DOT__rf_11),64);
            tracep->chgQData(oldp+47,(vlSelf->RVNoob__DOT__rf__DOT__rf_12),64);
            tracep->chgQData(oldp+49,(vlSelf->RVNoob__DOT__rf__DOT__rf_13),64);
            tracep->chgQData(oldp+51,(vlSelf->RVNoob__DOT__rf__DOT__rf_14),64);
            tracep->chgQData(oldp+53,(vlSelf->RVNoob__DOT__rf__DOT__rf_15),64);
            tracep->chgQData(oldp+55,(vlSelf->RVNoob__DOT__rf__DOT__rf_16),64);
            tracep->chgQData(oldp+57,(vlSelf->RVNoob__DOT__rf__DOT__rf_17),64);
            tracep->chgQData(oldp+59,(vlSelf->RVNoob__DOT__rf__DOT__rf_18),64);
            tracep->chgQData(oldp+61,(vlSelf->RVNoob__DOT__rf__DOT__rf_19),64);
            tracep->chgQData(oldp+63,(vlSelf->RVNoob__DOT__rf__DOT__rf_20),64);
            tracep->chgQData(oldp+65,(vlSelf->RVNoob__DOT__rf__DOT__rf_21),64);
            tracep->chgQData(oldp+67,(vlSelf->RVNoob__DOT__rf__DOT__rf_22),64);
            tracep->chgQData(oldp+69,(vlSelf->RVNoob__DOT__rf__DOT__rf_23),64);
            tracep->chgQData(oldp+71,(vlSelf->RVNoob__DOT__rf__DOT__rf_24),64);
            tracep->chgQData(oldp+73,(vlSelf->RVNoob__DOT__rf__DOT__rf_25),64);
            tracep->chgQData(oldp+75,(vlSelf->RVNoob__DOT__rf__DOT__rf_26),64);
            tracep->chgQData(oldp+77,(vlSelf->RVNoob__DOT__rf__DOT__rf_27),64);
            tracep->chgQData(oldp+79,(vlSelf->RVNoob__DOT__rf__DOT__rf_28),64);
            tracep->chgQData(oldp+81,(vlSelf->RVNoob__DOT__rf__DOT__rf_29),64);
            tracep->chgQData(oldp+83,(vlSelf->RVNoob__DOT__rf__DOT__rf_30),64);
            tracep->chgQData(oldp+85,(vlSelf->RVNoob__DOT__rf__DOT__rf_31),64);
            tracep->chgQData(oldp+87,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0]),64);
            tracep->chgQData(oldp+89,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[1]),64);
            tracep->chgQData(oldp+91,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[2]),64);
            tracep->chgQData(oldp+93,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[3]),64);
            tracep->chgQData(oldp+95,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[4]),64);
            tracep->chgQData(oldp+97,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[5]),64);
            tracep->chgQData(oldp+99,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[6]),64);
            tracep->chgQData(oldp+101,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[7]),64);
            tracep->chgQData(oldp+103,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[8]),64);
            tracep->chgQData(oldp+105,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[9]),64);
            tracep->chgQData(oldp+107,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[10]),64);
            tracep->chgQData(oldp+109,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[11]),64);
            tracep->chgQData(oldp+111,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[12]),64);
            tracep->chgQData(oldp+113,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[13]),64);
            tracep->chgQData(oldp+115,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[14]),64);
            tracep->chgQData(oldp+117,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[15]),64);
            tracep->chgQData(oldp+119,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[16]),64);
            tracep->chgQData(oldp+121,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[17]),64);
            tracep->chgQData(oldp+123,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[18]),64);
            tracep->chgQData(oldp+125,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[19]),64);
            tracep->chgQData(oldp+127,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[20]),64);
            tracep->chgQData(oldp+129,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[21]),64);
            tracep->chgQData(oldp+131,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[22]),64);
            tracep->chgQData(oldp+133,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[23]),64);
            tracep->chgQData(oldp+135,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[24]),64);
            tracep->chgQData(oldp+137,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[25]),64);
            tracep->chgQData(oldp+139,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[26]),64);
            tracep->chgQData(oldp+141,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[27]),64);
            tracep->chgQData(oldp+143,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[28]),64);
            tracep->chgQData(oldp+145,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[29]),64);
            tracep->chgQData(oldp+147,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[30]),64);
            tracep->chgQData(oldp+149,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[31]),64);
        }
        tracep->chgBit(oldp+151,(vlSelf->clock));
        tracep->chgBit(oldp+152,(vlSelf->reset));
        tracep->chgQData(oldp+153,(vlSelf->io_pc),64);
        tracep->chgIData(oldp+155,(vlSelf->io_inst),32);
        tracep->chgQData(oldp+156,(vlSelf->io_res),64);
        tracep->chgBit(oldp+158,(vlSelf->io_ebreak));
        tracep->chgCData(oldp+159,((0x1fU & (vlSelf->io_inst 
                                             >> 7U))),5);
        tracep->chgCData(oldp+160,((0x1fU & (vlSelf->io_inst 
                                             >> 0xfU))),5);
        tracep->chgBit(oldp+161,(((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                    | (0x17U == (0x7fU 
                                                 & vlSelf->io_inst))) 
                                   | (0x6fU == (0x7fU 
                                                & vlSelf->io_inst))) 
                                  | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))));
        tracep->chgBit(oldp+162,(((0x6fU == (0x7fU 
                                             & vlSelf->io_inst)) 
                                  | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))));
        tracep->chgBit(oldp+163,((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr) 
                                   | (0x17U == (0x7fU 
                                                & vlSelf->io_inst))) 
                                  | (0x6fU == (0x7fU 
                                               & vlSelf->io_inst)))));
        tracep->chgBit(oldp+164,((IData)((0x67U == 
                                          (0x707fU 
                                           & vlSelf->io_inst)))));
        tracep->chgQData(oldp+165,((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                     | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))
                                     ? ((0x1fU == (0x1fU 
                                                   & (vlSelf->io_inst 
                                                      >> 0xfU)))
                                         ? vlSelf->RVNoob__DOT__rf__DOT__rf_31
                                         : ((0x1eU 
                                             == (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 0xfU)))
                                             ? vlSelf->RVNoob__DOT__rf__DOT__rf_30
                                             : ((0x1dU 
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
                                     : 0ULL)),64);
        tracep->chgQData(oldp+167,(((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr) 
                                      | (0x17U == (0x7fU 
                                                   & vlSelf->io_inst))) 
                                     | (0x6fU == (0x7fU 
                                                  & vlSelf->io_inst)))
                                     ? ((0xfffffffffffffffeULL 
                                         & vlSelf->RVNoob__DOT__exe__DOT__alu_out) 
                                        | (QData)((IData)(
                                                          (1U 
                                                           & ((~ (IData)(
                                                                         (0x67U 
                                                                          == 
                                                                          (0x707fU 
                                                                           & vlSelf->io_inst)))) 
                                                              & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_out))))))
                                     : vlSelf->RVNoob__DOT__idu_io_imm)),64);
        tracep->chgCData(oldp+169,((0x7fU & vlSelf->io_inst)),7);
        tracep->chgCData(oldp+170,((7U & (vlSelf->io_inst 
                                          >> 0xcU))),3);
        tracep->chgBit(oldp+171,((0x17U == (0x7fU & vlSelf->io_inst))));
        tracep->chgBit(oldp+172,((0x37U == (0x7fU & vlSelf->io_inst))));
        tracep->chgBit(oldp+173,((0x6fU == (0x7fU & vlSelf->io_inst))));
        tracep->chgBit(oldp+174,(((0x17U == (0x7fU 
                                             & vlSelf->io_inst)) 
                                  | (0x37U == (0x7fU 
                                               & vlSelf->io_inst)))));
        tracep->chgIData(oldp+175,(((0x2000000U & (vlSelf->io_inst 
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
                                                      | (((IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo) 
                                                          << 0xdU) 
                                                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo)))))))))),26);
        tracep->chgQData(oldp+176,((((QData)((IData)(
                                                     (vlSelf->io_inst 
                                                      >> 0x1fU))) 
                                     << 0x33U) | (((QData)((IData)(
                                                                   (vlSelf->io_inst 
                                                                    >> 0x1fU))) 
                                                   << 0x32U) 
                                                  | (((QData)((IData)(
                                                                      (vlSelf->io_inst 
                                                                       >> 0x1fU))) 
                                                      << 0x31U) 
                                                     | (((QData)((IData)(
                                                                         (vlSelf->io_inst 
                                                                          >> 0x1fU))) 
                                                         << 0x30U) 
                                                        | (((QData)((IData)(
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
                                                                 | (((QData)((IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo)) 
                                                                     << 0x27U) 
                                                                    | (((QData)((IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo)) 
                                                                        << 0x1aU) 
                                                                       | (QData)((IData)(
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
                                                                                | (((IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo) 
                                                                                << 0xdU) 
                                                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo))))))))))))))))))))),52);
        tracep->chgQData(oldp+178,((((QData)((IData)(
                                                     (vlSelf->io_inst 
                                                      >> 0x1fU))) 
                                     << 0x3fU) | (((QData)((IData)(
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
                                                                                >> 0x14U)))))))))))))))))))))),64);
        tracep->chgSData(oldp+180,(((0x8000U & (vlSelf->io_inst 
                                                >> 0x10U)) 
                                    | ((0x4000U & (vlSelf->io_inst 
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
                                                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immU_lo_lo)))))))))),16);
        tracep->chgIData(oldp+181,(((0x80000000U & vlSelf->io_inst) 
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
                                                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immU_lo_lo))))))))))))))))))),32);
        tracep->chgQData(oldp+182,((((QData)((IData)(
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
                                     << 0x20U) | (QData)((IData)(
                                                                 (0xfffff000U 
                                                                  & vlSelf->io_inst))))),64);
        tracep->chgSData(oldp+184,(((0x200U & (vlSelf->io_inst 
                                               >> 0x16U)) 
                                    | ((0x100U & (vlSelf->io_inst 
                                                  >> 0x17U)) 
                                       | ((0x80U & 
                                           (vlSelf->io_inst 
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
                                                               >> 0x1fU))))))))))),10);
        tracep->chgSData(oldp+185,(((0x400U & (vlSelf->io_inst 
                                               >> 0x15U)) 
                                    | ((0x200U & (vlSelf->io_inst 
                                                  >> 0x16U)) 
                                       | ((0x100U & 
                                           (vlSelf->io_inst 
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
                                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immJ_lo_lo_lo)))))))),11);
        tracep->chgIData(oldp+186,(((0x100000U & (vlSelf->io_inst 
                                                  >> 0xbU)) 
                                    | ((0x80000U & 
                                        (vlSelf->io_inst 
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
                                                                                >> 0x1fU)))))))))))))))))),21);
        tracep->chgCData(oldp+187,((0xffU & (vlSelf->io_inst 
                                             >> 0xcU))),8);
        tracep->chgBit(oldp+188,((1U & (vlSelf->io_inst 
                                        >> 0x14U))));
        tracep->chgSData(oldp+189,((0x3ffU & (vlSelf->io_inst 
                                              >> 0x15U))),10);
        tracep->chgQData(oldp+190,(((vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1 
                                     << 0x14U) | (QData)((IData)(
                                                                 ((0xff000U 
                                                                   & vlSelf->io_inst) 
                                                                  | ((0x800U 
                                                                      & (vlSelf->io_inst 
                                                                         >> 9U)) 
                                                                     | (0x7feU 
                                                                        & (vlSelf->io_inst 
                                                                           >> 0x14U)))))))),64);
        tracep->chgQData(oldp+192,(((0x1fU == (0x1fU 
                                               & (vlSelf->io_inst 
                                                  >> 0xfU)))
                                     ? vlSelf->RVNoob__DOT__rf__DOT__rf_31
                                     : ((0x1eU == (0x1fU 
                                                   & (vlSelf->io_inst 
                                                      >> 0xfU)))
                                         ? vlSelf->RVNoob__DOT__rf__DOT__rf_30
                                         : ((0x1dU 
                                             == (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 0xfU)))
                                             ? vlSelf->RVNoob__DOT__rf__DOT__rf_29
                                             : ((0x1cU 
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
                                                  : vlSelf->RVNoob__DOT__rf__DOT___GEN_57)))))),64);
        tracep->chgQData(oldp+194,((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                     | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))
                                     ? (((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))
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
                                         : 0ULL) : vlSelf->RVNoob__DOT__pc)),64);
        tracep->chgBit(oldp+196,((1U & ((~ (IData)(
                                                   (0x67U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->io_inst)))) 
                                        & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_out)))));
    }
}

void VRVNoob___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VRVNoob___024root* const __restrict vlSelf = static_cast<VRVNoob___024root*>(voidSelf);
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    }
}
