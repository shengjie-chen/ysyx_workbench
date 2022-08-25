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
            tracep->chgBit(oldp+4,(vlSelf->RVNoob__DOT__idu_io_pc_mux));
            tracep->chgQData(oldp+5,(vlSelf->RVNoob__DOT__exe_io_gp_out),64);
            tracep->chgQData(oldp+7,(vlSelf->RVNoob__DOT__exe_io_dnpc),64);
            tracep->chgBit(oldp+9,(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi));
            tracep->chgBit(oldp+10,(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr));
            tracep->chgCData(oldp+11,(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo),6);
            tracep->chgSData(oldp+12,(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo),13);
            tracep->chgCData(oldp+13,(vlSelf->RVNoob__DOT__idu__DOT__immU_lo_lo),8);
            tracep->chgCData(oldp+14,(vlSelf->RVNoob__DOT__idu__DOT__immJ_lo_lo_lo),5);
            tracep->chgQData(oldp+15,(vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1),44);
            tracep->chgQData(oldp+17,(vlSelf->RVNoob__DOT__exe__DOT__alu_out),64);
            tracep->chgQData(oldp+19,((vlSelf->RVNoob__DOT__exe__DOT__alu_out 
                                       >> 1U)),63);
        }
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
            tracep->chgQData(oldp+21,(vlSelf->RVNoob__DOT__rf__DOT__rf_10),64);
            tracep->chgQData(oldp+23,(vlSelf->RVNoob__DOT__pc),64);
            tracep->chgQData(oldp+25,((4ULL + vlSelf->RVNoob__DOT__pc)),64);
            tracep->chgBit(oldp+27,(vlSelf->RVNoob__DOT__U_ebreak_ebreak));
            tracep->chgQData(oldp+28,(vlSelf->RVNoob__DOT__rf__DOT__rf_1),64);
            tracep->chgQData(oldp+30,(vlSelf->RVNoob__DOT__rf__DOT__rf_2),64);
            tracep->chgQData(oldp+32,(vlSelf->RVNoob__DOT__rf__DOT__rf_3),64);
            tracep->chgQData(oldp+34,(vlSelf->RVNoob__DOT__rf__DOT__rf_4),64);
            tracep->chgQData(oldp+36,(vlSelf->RVNoob__DOT__rf__DOT__rf_5),64);
            tracep->chgQData(oldp+38,(vlSelf->RVNoob__DOT__rf__DOT__rf_6),64);
            tracep->chgQData(oldp+40,(vlSelf->RVNoob__DOT__rf__DOT__rf_7),64);
            tracep->chgQData(oldp+42,(vlSelf->RVNoob__DOT__rf__DOT__rf_8),64);
            tracep->chgQData(oldp+44,(vlSelf->RVNoob__DOT__rf__DOT__rf_9),64);
            tracep->chgQData(oldp+46,(vlSelf->RVNoob__DOT__rf__DOT__rf_11),64);
            tracep->chgQData(oldp+48,(vlSelf->RVNoob__DOT__rf__DOT__rf_12),64);
            tracep->chgQData(oldp+50,(vlSelf->RVNoob__DOT__rf__DOT__rf_13),64);
            tracep->chgQData(oldp+52,(vlSelf->RVNoob__DOT__rf__DOT__rf_14),64);
            tracep->chgQData(oldp+54,(vlSelf->RVNoob__DOT__rf__DOT__rf_15),64);
            tracep->chgQData(oldp+56,(vlSelf->RVNoob__DOT__rf__DOT__rf_16),64);
            tracep->chgQData(oldp+58,(vlSelf->RVNoob__DOT__rf__DOT__rf_17),64);
            tracep->chgQData(oldp+60,(vlSelf->RVNoob__DOT__rf__DOT__rf_18),64);
            tracep->chgQData(oldp+62,(vlSelf->RVNoob__DOT__rf__DOT__rf_19),64);
            tracep->chgQData(oldp+64,(vlSelf->RVNoob__DOT__rf__DOT__rf_20),64);
            tracep->chgQData(oldp+66,(vlSelf->RVNoob__DOT__rf__DOT__rf_21),64);
            tracep->chgQData(oldp+68,(vlSelf->RVNoob__DOT__rf__DOT__rf_22),64);
            tracep->chgQData(oldp+70,(vlSelf->RVNoob__DOT__rf__DOT__rf_23),64);
            tracep->chgQData(oldp+72,(vlSelf->RVNoob__DOT__rf__DOT__rf_24),64);
            tracep->chgQData(oldp+74,(vlSelf->RVNoob__DOT__rf__DOT__rf_25),64);
            tracep->chgQData(oldp+76,(vlSelf->RVNoob__DOT__rf__DOT__rf_26),64);
            tracep->chgQData(oldp+78,(vlSelf->RVNoob__DOT__rf__DOT__rf_27),64);
            tracep->chgQData(oldp+80,(vlSelf->RVNoob__DOT__rf__DOT__rf_28),64);
            tracep->chgQData(oldp+82,(vlSelf->RVNoob__DOT__rf__DOT__rf_29),64);
            tracep->chgQData(oldp+84,(vlSelf->RVNoob__DOT__rf__DOT__rf_30),64);
            tracep->chgQData(oldp+86,(vlSelf->RVNoob__DOT__rf__DOT__rf_31),64);
            tracep->chgQData(oldp+88,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0]),64);
            tracep->chgQData(oldp+90,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[1]),64);
            tracep->chgQData(oldp+92,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[2]),64);
            tracep->chgQData(oldp+94,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[3]),64);
            tracep->chgQData(oldp+96,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[4]),64);
            tracep->chgQData(oldp+98,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[5]),64);
            tracep->chgQData(oldp+100,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[6]),64);
            tracep->chgQData(oldp+102,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[7]),64);
            tracep->chgQData(oldp+104,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[8]),64);
            tracep->chgQData(oldp+106,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[9]),64);
            tracep->chgQData(oldp+108,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[10]),64);
            tracep->chgQData(oldp+110,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[11]),64);
            tracep->chgQData(oldp+112,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[12]),64);
            tracep->chgQData(oldp+114,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[13]),64);
            tracep->chgQData(oldp+116,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[14]),64);
            tracep->chgQData(oldp+118,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[15]),64);
            tracep->chgQData(oldp+120,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[16]),64);
            tracep->chgQData(oldp+122,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[17]),64);
            tracep->chgQData(oldp+124,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[18]),64);
            tracep->chgQData(oldp+126,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[19]),64);
            tracep->chgQData(oldp+128,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[20]),64);
            tracep->chgQData(oldp+130,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[21]),64);
            tracep->chgQData(oldp+132,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[22]),64);
            tracep->chgQData(oldp+134,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[23]),64);
            tracep->chgQData(oldp+136,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[24]),64);
            tracep->chgQData(oldp+138,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[25]),64);
            tracep->chgQData(oldp+140,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[26]),64);
            tracep->chgQData(oldp+142,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[27]),64);
            tracep->chgQData(oldp+144,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[28]),64);
            tracep->chgQData(oldp+146,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[29]),64);
            tracep->chgQData(oldp+148,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[30]),64);
            tracep->chgQData(oldp+150,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[31]),64);
        }
        tracep->chgBit(oldp+152,(vlSelf->clock));
        tracep->chgBit(oldp+153,(vlSelf->reset));
        tracep->chgQData(oldp+154,(vlSelf->io_pc),64);
        tracep->chgIData(oldp+156,(vlSelf->io_inst),32);
        tracep->chgQData(oldp+157,(vlSelf->io_res),64);
        tracep->chgBit(oldp+159,(vlSelf->io_ebreak));
        tracep->chgCData(oldp+160,((0x1fU & (vlSelf->io_inst 
                                             >> 7U))),5);
        tracep->chgCData(oldp+161,((0x1fU & (vlSelf->io_inst 
                                             >> 0xfU))),5);
        tracep->chgBit(oldp+162,(((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                    | (0x17U == (0x7fU 
                                                 & vlSelf->io_inst))) 
                                   | (0x6fU == (0x7fU 
                                                & vlSelf->io_inst))) 
                                  | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))));
        tracep->chgBit(oldp+163,(((0x6fU == (0x7fU 
                                             & vlSelf->io_inst)) 
                                  | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))));
        tracep->chgBit(oldp+164,((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr) 
                                   | (0x17U == (0x7fU 
                                                & vlSelf->io_inst))) 
                                  | (0x6fU == (0x7fU 
                                               & vlSelf->io_inst)))));
        tracep->chgBit(oldp+165,((IData)((0x67U == 
                                          (0x707fU 
                                           & vlSelf->io_inst)))));
        tracep->chgQData(oldp+166,((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
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
        tracep->chgQData(oldp+168,(((IData)(vlSelf->RVNoob__DOT__idu_io_pc_mux)
                                     ? vlSelf->RVNoob__DOT__exe_io_dnpc
                                     : (4ULL + vlSelf->RVNoob__DOT__pc))),64);
        tracep->chgCData(oldp+170,((0x7fU & vlSelf->io_inst)),7);
        tracep->chgCData(oldp+171,((7U & (vlSelf->io_inst 
                                          >> 0xcU))),3);
        tracep->chgBit(oldp+172,((0x17U == (0x7fU & vlSelf->io_inst))));
        tracep->chgBit(oldp+173,((0x37U == (0x7fU & vlSelf->io_inst))));
        tracep->chgBit(oldp+174,((0x6fU == (0x7fU & vlSelf->io_inst))));
        tracep->chgBit(oldp+175,(((0x17U == (0x7fU 
                                             & vlSelf->io_inst)) 
                                  | (0x37U == (0x7fU 
                                               & vlSelf->io_inst)))));
        tracep->chgIData(oldp+176,(((0x2000000U & (vlSelf->io_inst 
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
        tracep->chgQData(oldp+177,((((QData)((IData)(
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
        tracep->chgQData(oldp+179,((((QData)((IData)(
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
        tracep->chgSData(oldp+181,(((0x8000U & (vlSelf->io_inst 
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
        tracep->chgIData(oldp+182,(((0x80000000U & vlSelf->io_inst) 
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
        tracep->chgQData(oldp+183,((((QData)((IData)(
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
        tracep->chgSData(oldp+185,(((0x200U & (vlSelf->io_inst 
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
        tracep->chgSData(oldp+186,(((0x400U & (vlSelf->io_inst 
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
        tracep->chgIData(oldp+187,(((0x100000U & (vlSelf->io_inst 
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
        tracep->chgCData(oldp+188,((0xffU & (vlSelf->io_inst 
                                             >> 0xcU))),8);
        tracep->chgBit(oldp+189,((1U & (vlSelf->io_inst 
                                        >> 0x14U))));
        tracep->chgSData(oldp+190,((0x3ffU & (vlSelf->io_inst 
                                              >> 0x15U))),10);
        tracep->chgQData(oldp+191,(((vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1 
                                     << 0x14U) | (QData)((IData)(
                                                                 ((0xff000U 
                                                                   & vlSelf->io_inst) 
                                                                  | ((0x800U 
                                                                      & (vlSelf->io_inst 
                                                                         >> 9U)) 
                                                                     | (0x7feU 
                                                                        & (vlSelf->io_inst 
                                                                           >> 0x14U)))))))),64);
        tracep->chgQData(oldp+193,(((0x1fU == (0x1fU 
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
        tracep->chgQData(oldp+195,((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
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
        tracep->chgBit(oldp+197,((1U & ((~ (IData)(
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
