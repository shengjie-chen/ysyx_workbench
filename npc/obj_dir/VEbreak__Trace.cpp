// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VEbreak__Syms.h"


void VEbreak___024root__traceChgSub0(VEbreak___024root* vlSelf, VerilatedVcd* tracep);

void VEbreak___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VEbreak___024root* const __restrict vlSelf = static_cast<VEbreak___024root*>(voidSelf);
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VEbreak___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VEbreak___024root__traceChgSub0(VEbreak___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
            tracep->chgQData(oldp+0,(vlSelf->RF_read__DOT__rf[0]),64);
            tracep->chgQData(oldp+2,(vlSelf->RF_read__DOT__rf[1]),64);
            tracep->chgQData(oldp+4,(vlSelf->RF_read__DOT__rf[2]),64);
            tracep->chgQData(oldp+6,(vlSelf->RF_read__DOT__rf[3]),64);
            tracep->chgQData(oldp+8,(vlSelf->RF_read__DOT__rf[4]),64);
            tracep->chgQData(oldp+10,(vlSelf->RF_read__DOT__rf[5]),64);
            tracep->chgQData(oldp+12,(vlSelf->RF_read__DOT__rf[6]),64);
            tracep->chgQData(oldp+14,(vlSelf->RF_read__DOT__rf[7]),64);
            tracep->chgQData(oldp+16,(vlSelf->RF_read__DOT__rf[8]),64);
            tracep->chgQData(oldp+18,(vlSelf->RF_read__DOT__rf[9]),64);
            tracep->chgQData(oldp+20,(vlSelf->RF_read__DOT__rf[10]),64);
            tracep->chgQData(oldp+22,(vlSelf->RF_read__DOT__rf[11]),64);
            tracep->chgQData(oldp+24,(vlSelf->RF_read__DOT__rf[12]),64);
            tracep->chgQData(oldp+26,(vlSelf->RF_read__DOT__rf[13]),64);
            tracep->chgQData(oldp+28,(vlSelf->RF_read__DOT__rf[14]),64);
            tracep->chgQData(oldp+30,(vlSelf->RF_read__DOT__rf[15]),64);
            tracep->chgQData(oldp+32,(vlSelf->RF_read__DOT__rf[16]),64);
            tracep->chgQData(oldp+34,(vlSelf->RF_read__DOT__rf[17]),64);
            tracep->chgQData(oldp+36,(vlSelf->RF_read__DOT__rf[18]),64);
            tracep->chgQData(oldp+38,(vlSelf->RF_read__DOT__rf[19]),64);
            tracep->chgQData(oldp+40,(vlSelf->RF_read__DOT__rf[20]),64);
            tracep->chgQData(oldp+42,(vlSelf->RF_read__DOT__rf[21]),64);
            tracep->chgQData(oldp+44,(vlSelf->RF_read__DOT__rf[22]),64);
            tracep->chgQData(oldp+46,(vlSelf->RF_read__DOT__rf[23]),64);
            tracep->chgQData(oldp+48,(vlSelf->RF_read__DOT__rf[24]),64);
            tracep->chgQData(oldp+50,(vlSelf->RF_read__DOT__rf[25]),64);
            tracep->chgQData(oldp+52,(vlSelf->RF_read__DOT__rf[26]),64);
            tracep->chgQData(oldp+54,(vlSelf->RF_read__DOT__rf[27]),64);
            tracep->chgQData(oldp+56,(vlSelf->RF_read__DOT__rf[28]),64);
            tracep->chgQData(oldp+58,(vlSelf->RF_read__DOT__rf[29]),64);
            tracep->chgQData(oldp+60,(vlSelf->RF_read__DOT__rf[30]),64);
            tracep->chgQData(oldp+62,(vlSelf->RF_read__DOT__rf[31]),64);
        }
        tracep->chgBit(oldp+64,(vlSelf->clk));
        tracep->chgIData(oldp+65,(vlSelf->inst),32);
        tracep->chgQData(oldp+66,(vlSelf->a0),64);
        tracep->chgBit(oldp+68,(vlSelf->ebreak));
        tracep->chgQData(oldp+69,(vlSelf->rf_0),64);
        tracep->chgQData(oldp+71,(vlSelf->rf_1),64);
        tracep->chgQData(oldp+73,(vlSelf->rf_2),64);
        tracep->chgQData(oldp+75,(vlSelf->rf_3),64);
        tracep->chgQData(oldp+77,(vlSelf->rf_4),64);
        tracep->chgQData(oldp+79,(vlSelf->rf_5),64);
        tracep->chgQData(oldp+81,(vlSelf->rf_6),64);
        tracep->chgQData(oldp+83,(vlSelf->rf_7),64);
        tracep->chgQData(oldp+85,(vlSelf->rf_8),64);
        tracep->chgQData(oldp+87,(vlSelf->rf_9),64);
        tracep->chgQData(oldp+89,(vlSelf->rf_10),64);
        tracep->chgQData(oldp+91,(vlSelf->rf_11),64);
        tracep->chgQData(oldp+93,(vlSelf->rf_12),64);
        tracep->chgQData(oldp+95,(vlSelf->rf_13),64);
        tracep->chgQData(oldp+97,(vlSelf->rf_14),64);
        tracep->chgQData(oldp+99,(vlSelf->rf_15),64);
        tracep->chgQData(oldp+101,(vlSelf->rf_16),64);
        tracep->chgQData(oldp+103,(vlSelf->rf_17),64);
        tracep->chgQData(oldp+105,(vlSelf->rf_18),64);
        tracep->chgQData(oldp+107,(vlSelf->rf_19),64);
        tracep->chgQData(oldp+109,(vlSelf->rf_20),64);
        tracep->chgQData(oldp+111,(vlSelf->rf_21),64);
        tracep->chgQData(oldp+113,(vlSelf->rf_22),64);
        tracep->chgQData(oldp+115,(vlSelf->rf_23),64);
        tracep->chgQData(oldp+117,(vlSelf->rf_24),64);
        tracep->chgQData(oldp+119,(vlSelf->rf_25),64);
        tracep->chgQData(oldp+121,(vlSelf->rf_26),64);
        tracep->chgQData(oldp+123,(vlSelf->rf_27),64);
        tracep->chgQData(oldp+125,(vlSelf->rf_28),64);
        tracep->chgQData(oldp+127,(vlSelf->rf_29),64);
        tracep->chgQData(oldp+129,(vlSelf->rf_30),64);
        tracep->chgQData(oldp+131,(vlSelf->rf_31),64);
    }
}

void VEbreak___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VEbreak___024root* const __restrict vlSelf = static_cast<VEbreak___024root*>(voidSelf);
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    }
}
