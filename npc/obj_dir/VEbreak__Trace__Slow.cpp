// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VEbreak__Syms.h"


void VEbreak___024root__traceInitSub0(VEbreak___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VEbreak___024root__traceInitTop(VEbreak___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VEbreak___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VEbreak___024root__traceInitSub0(VEbreak___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+65,"clk", false,-1);
        tracep->declBus(c+66,"inst", false,-1, 31,0);
        tracep->declQuad(c+67,"a0", false,-1, 63,0);
        tracep->declBit(c+69,"ebreak", false,-1);
        tracep->declQuad(c+70,"rf_0", false,-1, 63,0);
        tracep->declQuad(c+72,"rf_1", false,-1, 63,0);
        tracep->declQuad(c+74,"rf_2", false,-1, 63,0);
        tracep->declQuad(c+76,"rf_3", false,-1, 63,0);
        tracep->declQuad(c+78,"rf_4", false,-1, 63,0);
        tracep->declQuad(c+80,"rf_5", false,-1, 63,0);
        tracep->declQuad(c+82,"rf_6", false,-1, 63,0);
        tracep->declQuad(c+84,"rf_7", false,-1, 63,0);
        tracep->declQuad(c+86,"rf_8", false,-1, 63,0);
        tracep->declQuad(c+88,"rf_9", false,-1, 63,0);
        tracep->declQuad(c+90,"rf_10", false,-1, 63,0);
        tracep->declQuad(c+92,"rf_11", false,-1, 63,0);
        tracep->declQuad(c+94,"rf_12", false,-1, 63,0);
        tracep->declQuad(c+96,"rf_13", false,-1, 63,0);
        tracep->declQuad(c+98,"rf_14", false,-1, 63,0);
        tracep->declQuad(c+100,"rf_15", false,-1, 63,0);
        tracep->declQuad(c+102,"rf_16", false,-1, 63,0);
        tracep->declQuad(c+104,"rf_17", false,-1, 63,0);
        tracep->declQuad(c+106,"rf_18", false,-1, 63,0);
        tracep->declQuad(c+108,"rf_19", false,-1, 63,0);
        tracep->declQuad(c+110,"rf_20", false,-1, 63,0);
        tracep->declQuad(c+112,"rf_21", false,-1, 63,0);
        tracep->declQuad(c+114,"rf_22", false,-1, 63,0);
        tracep->declQuad(c+116,"rf_23", false,-1, 63,0);
        tracep->declQuad(c+118,"rf_24", false,-1, 63,0);
        tracep->declQuad(c+120,"rf_25", false,-1, 63,0);
        tracep->declQuad(c+122,"rf_26", false,-1, 63,0);
        tracep->declQuad(c+124,"rf_27", false,-1, 63,0);
        tracep->declQuad(c+126,"rf_28", false,-1, 63,0);
        tracep->declQuad(c+128,"rf_29", false,-1, 63,0);
        tracep->declQuad(c+130,"rf_30", false,-1, 63,0);
        tracep->declQuad(c+132,"rf_31", false,-1, 63,0);
        tracep->declBit(c+65,"Ebreak clk", false,-1);
        tracep->declBus(c+66,"Ebreak inst", false,-1, 31,0);
        tracep->declQuad(c+67,"Ebreak a0", false,-1, 63,0);
        tracep->declBit(c+69,"Ebreak ebreak", false,-1);
        tracep->declQuad(c+70,"RF_read rf_0", false,-1, 63,0);
        tracep->declQuad(c+72,"RF_read rf_1", false,-1, 63,0);
        tracep->declQuad(c+74,"RF_read rf_2", false,-1, 63,0);
        tracep->declQuad(c+76,"RF_read rf_3", false,-1, 63,0);
        tracep->declQuad(c+78,"RF_read rf_4", false,-1, 63,0);
        tracep->declQuad(c+80,"RF_read rf_5", false,-1, 63,0);
        tracep->declQuad(c+82,"RF_read rf_6", false,-1, 63,0);
        tracep->declQuad(c+84,"RF_read rf_7", false,-1, 63,0);
        tracep->declQuad(c+86,"RF_read rf_8", false,-1, 63,0);
        tracep->declQuad(c+88,"RF_read rf_9", false,-1, 63,0);
        tracep->declQuad(c+90,"RF_read rf_10", false,-1, 63,0);
        tracep->declQuad(c+92,"RF_read rf_11", false,-1, 63,0);
        tracep->declQuad(c+94,"RF_read rf_12", false,-1, 63,0);
        tracep->declQuad(c+96,"RF_read rf_13", false,-1, 63,0);
        tracep->declQuad(c+98,"RF_read rf_14", false,-1, 63,0);
        tracep->declQuad(c+100,"RF_read rf_15", false,-1, 63,0);
        tracep->declQuad(c+102,"RF_read rf_16", false,-1, 63,0);
        tracep->declQuad(c+104,"RF_read rf_17", false,-1, 63,0);
        tracep->declQuad(c+106,"RF_read rf_18", false,-1, 63,0);
        tracep->declQuad(c+108,"RF_read rf_19", false,-1, 63,0);
        tracep->declQuad(c+110,"RF_read rf_20", false,-1, 63,0);
        tracep->declQuad(c+112,"RF_read rf_21", false,-1, 63,0);
        tracep->declQuad(c+114,"RF_read rf_22", false,-1, 63,0);
        tracep->declQuad(c+116,"RF_read rf_23", false,-1, 63,0);
        tracep->declQuad(c+118,"RF_read rf_24", false,-1, 63,0);
        tracep->declQuad(c+120,"RF_read rf_25", false,-1, 63,0);
        tracep->declQuad(c+122,"RF_read rf_26", false,-1, 63,0);
        tracep->declQuad(c+124,"RF_read rf_27", false,-1, 63,0);
        tracep->declQuad(c+126,"RF_read rf_28", false,-1, 63,0);
        tracep->declQuad(c+128,"RF_read rf_29", false,-1, 63,0);
        tracep->declQuad(c+130,"RF_read rf_30", false,-1, 63,0);
        tracep->declQuad(c+132,"RF_read rf_31", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+1+i*2,"RF_read rf", true,(i+0), 63,0);}}
    }
}

void VEbreak___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VEbreak___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VEbreak___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VEbreak___024root__traceRegister(VEbreak___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VEbreak___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VEbreak___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VEbreak___024root__traceCleanup, vlSelf);
    }
}

void VEbreak___024root__traceFullSub0(VEbreak___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VEbreak___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VEbreak___024root* const __restrict vlSelf = static_cast<VEbreak___024root*>(voidSelf);
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VEbreak___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VEbreak___024root__traceFullSub0(VEbreak___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullQData(oldp+1,(vlSelf->RF_read__DOT__rf[0]),64);
        tracep->fullQData(oldp+3,(vlSelf->RF_read__DOT__rf[1]),64);
        tracep->fullQData(oldp+5,(vlSelf->RF_read__DOT__rf[2]),64);
        tracep->fullQData(oldp+7,(vlSelf->RF_read__DOT__rf[3]),64);
        tracep->fullQData(oldp+9,(vlSelf->RF_read__DOT__rf[4]),64);
        tracep->fullQData(oldp+11,(vlSelf->RF_read__DOT__rf[5]),64);
        tracep->fullQData(oldp+13,(vlSelf->RF_read__DOT__rf[6]),64);
        tracep->fullQData(oldp+15,(vlSelf->RF_read__DOT__rf[7]),64);
        tracep->fullQData(oldp+17,(vlSelf->RF_read__DOT__rf[8]),64);
        tracep->fullQData(oldp+19,(vlSelf->RF_read__DOT__rf[9]),64);
        tracep->fullQData(oldp+21,(vlSelf->RF_read__DOT__rf[10]),64);
        tracep->fullQData(oldp+23,(vlSelf->RF_read__DOT__rf[11]),64);
        tracep->fullQData(oldp+25,(vlSelf->RF_read__DOT__rf[12]),64);
        tracep->fullQData(oldp+27,(vlSelf->RF_read__DOT__rf[13]),64);
        tracep->fullQData(oldp+29,(vlSelf->RF_read__DOT__rf[14]),64);
        tracep->fullQData(oldp+31,(vlSelf->RF_read__DOT__rf[15]),64);
        tracep->fullQData(oldp+33,(vlSelf->RF_read__DOT__rf[16]),64);
        tracep->fullQData(oldp+35,(vlSelf->RF_read__DOT__rf[17]),64);
        tracep->fullQData(oldp+37,(vlSelf->RF_read__DOT__rf[18]),64);
        tracep->fullQData(oldp+39,(vlSelf->RF_read__DOT__rf[19]),64);
        tracep->fullQData(oldp+41,(vlSelf->RF_read__DOT__rf[20]),64);
        tracep->fullQData(oldp+43,(vlSelf->RF_read__DOT__rf[21]),64);
        tracep->fullQData(oldp+45,(vlSelf->RF_read__DOT__rf[22]),64);
        tracep->fullQData(oldp+47,(vlSelf->RF_read__DOT__rf[23]),64);
        tracep->fullQData(oldp+49,(vlSelf->RF_read__DOT__rf[24]),64);
        tracep->fullQData(oldp+51,(vlSelf->RF_read__DOT__rf[25]),64);
        tracep->fullQData(oldp+53,(vlSelf->RF_read__DOT__rf[26]),64);
        tracep->fullQData(oldp+55,(vlSelf->RF_read__DOT__rf[27]),64);
        tracep->fullQData(oldp+57,(vlSelf->RF_read__DOT__rf[28]),64);
        tracep->fullQData(oldp+59,(vlSelf->RF_read__DOT__rf[29]),64);
        tracep->fullQData(oldp+61,(vlSelf->RF_read__DOT__rf[30]),64);
        tracep->fullQData(oldp+63,(vlSelf->RF_read__DOT__rf[31]),64);
        tracep->fullBit(oldp+65,(vlSelf->clk));
        tracep->fullIData(oldp+66,(vlSelf->inst),32);
        tracep->fullQData(oldp+67,(vlSelf->a0),64);
        tracep->fullBit(oldp+69,(vlSelf->ebreak));
        tracep->fullQData(oldp+70,(vlSelf->rf_0),64);
        tracep->fullQData(oldp+72,(vlSelf->rf_1),64);
        tracep->fullQData(oldp+74,(vlSelf->rf_2),64);
        tracep->fullQData(oldp+76,(vlSelf->rf_3),64);
        tracep->fullQData(oldp+78,(vlSelf->rf_4),64);
        tracep->fullQData(oldp+80,(vlSelf->rf_5),64);
        tracep->fullQData(oldp+82,(vlSelf->rf_6),64);
        tracep->fullQData(oldp+84,(vlSelf->rf_7),64);
        tracep->fullQData(oldp+86,(vlSelf->rf_8),64);
        tracep->fullQData(oldp+88,(vlSelf->rf_9),64);
        tracep->fullQData(oldp+90,(vlSelf->rf_10),64);
        tracep->fullQData(oldp+92,(vlSelf->rf_11),64);
        tracep->fullQData(oldp+94,(vlSelf->rf_12),64);
        tracep->fullQData(oldp+96,(vlSelf->rf_13),64);
        tracep->fullQData(oldp+98,(vlSelf->rf_14),64);
        tracep->fullQData(oldp+100,(vlSelf->rf_15),64);
        tracep->fullQData(oldp+102,(vlSelf->rf_16),64);
        tracep->fullQData(oldp+104,(vlSelf->rf_17),64);
        tracep->fullQData(oldp+106,(vlSelf->rf_18),64);
        tracep->fullQData(oldp+108,(vlSelf->rf_19),64);
        tracep->fullQData(oldp+110,(vlSelf->rf_20),64);
        tracep->fullQData(oldp+112,(vlSelf->rf_21),64);
        tracep->fullQData(oldp+114,(vlSelf->rf_22),64);
        tracep->fullQData(oldp+116,(vlSelf->rf_23),64);
        tracep->fullQData(oldp+118,(vlSelf->rf_24),64);
        tracep->fullQData(oldp+120,(vlSelf->rf_25),64);
        tracep->fullQData(oldp+122,(vlSelf->rf_26),64);
        tracep->fullQData(oldp+124,(vlSelf->rf_27),64);
        tracep->fullQData(oldp+126,(vlSelf->rf_28),64);
        tracep->fullQData(oldp+128,(vlSelf->rf_29),64);
        tracep->fullQData(oldp+130,(vlSelf->rf_30),64);
        tracep->fullQData(oldp+132,(vlSelf->rf_31),64);
    }
}
