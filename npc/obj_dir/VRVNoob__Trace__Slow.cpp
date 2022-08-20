// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VRVNoob__Syms.h"


void VRVNoob___024root__traceInitSub0(VRVNoob___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VRVNoob___024root__traceInitTop(VRVNoob___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VRVNoob___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VRVNoob___024root__traceInitSub0(VRVNoob___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+152,"clock", false,-1);
        tracep->declBit(c+153,"reset", false,-1);
        tracep->declQuad(c+154,"io_pc", false,-1, 63,0);
        tracep->declBus(c+156,"io_inst", false,-1, 31,0);
        tracep->declQuad(c+157,"io_res", false,-1, 63,0);
        tracep->declBit(c+159,"io_ebreak", false,-1);
        tracep->declBit(c+152,"RVNoob clock", false,-1);
        tracep->declBit(c+153,"RVNoob reset", false,-1);
        tracep->declQuad(c+154,"RVNoob io_pc", false,-1, 63,0);
        tracep->declBus(c+156,"RVNoob io_inst", false,-1, 31,0);
        tracep->declQuad(c+157,"RVNoob io_res", false,-1, 63,0);
        tracep->declBit(c+159,"RVNoob io_ebreak", false,-1);
        tracep->declBus(c+156,"RVNoob idu_io_inst", false,-1, 31,0);
        tracep->declQuad(c+1,"RVNoob idu_io_imm", false,-1, 63,0);
        tracep->declBit(c+3,"RVNoob idu_io_wen", false,-1);
        tracep->declBus(c+160,"RVNoob idu_io_rd", false,-1, 4,0);
        tracep->declBit(c+4,"RVNoob idu_io_ren1", false,-1);
        tracep->declBus(c+161,"RVNoob idu_io_rs1", false,-1, 4,0);
        tracep->declBit(c+162,"RVNoob idu_io_add_en", false,-1);
        tracep->declBit(c+4,"RVNoob idu_io_alu_src1_mux", false,-1);
        tracep->declBit(c+163,"RVNoob idu_io_exe_out_mux", false,-1);
        tracep->declBit(c+164,"RVNoob idu_io_dnpc_mux", false,-1);
        tracep->declBit(c+163,"RVNoob idu_io_pc_mux", false,-1);
        tracep->declBit(c+165,"RVNoob idu_io_dnpc_0b0", false,-1);
        tracep->declBit(c+152,"RVNoob rf_clock", false,-1);
        tracep->declBit(c+153,"RVNoob rf_reset", false,-1);
        tracep->declBit(c+3,"RVNoob rf_io_wen", false,-1);
        tracep->declQuad(c+5,"RVNoob rf_io_wdata", false,-1, 63,0);
        tracep->declBus(c+160,"RVNoob rf_io_waddr", false,-1, 4,0);
        tracep->declBit(c+4,"RVNoob rf_io_ren1", false,-1);
        tracep->declQuad(c+166,"RVNoob rf_io_rdata1", false,-1, 63,0);
        tracep->declBus(c+161,"RVNoob rf_io_raddr1", false,-1, 4,0);
        tracep->declQuad(c+19,"RVNoob rf_io_a0", false,-1, 63,0);
        tracep->declQuad(c+166,"RVNoob exe_io_src1", false,-1, 63,0);
        tracep->declQuad(c+1,"RVNoob exe_io_imm", false,-1, 63,0);
        tracep->declQuad(c+21,"RVNoob exe_io_pc", false,-1, 63,0);
        tracep->declQuad(c+23,"RVNoob exe_io_snpc", false,-1, 63,0);
        tracep->declQuad(c+5,"RVNoob exe_io_gp_out", false,-1, 63,0);
        tracep->declQuad(c+168,"RVNoob exe_io_dnpc", false,-1, 63,0);
        tracep->declBit(c+162,"RVNoob exe_io_add_en", false,-1);
        tracep->declBit(c+4,"RVNoob exe_io_alu_src1_mux", false,-1);
        tracep->declBit(c+163,"RVNoob exe_io_exe_out_mux", false,-1);
        tracep->declBit(c+164,"RVNoob exe_io_dnpc_mux", false,-1);
        tracep->declBit(c+165,"RVNoob exe_io_dnpc_0b0", false,-1);
        tracep->declBit(c+152,"RVNoob U_ebreak_clk", false,-1);
        tracep->declBus(c+156,"RVNoob U_ebreak_inst", false,-1, 31,0);
        tracep->declQuad(c+19,"RVNoob U_ebreak_a0", false,-1, 63,0);
        tracep->declBit(c+25,"RVNoob U_ebreak_ebreak", false,-1);
        tracep->declQuad(c+21,"RVNoob pc", false,-1, 63,0);
        tracep->declQuad(c+23,"RVNoob snpc", false,-1, 63,0);
        tracep->declBus(c+156,"RVNoob idu io_inst", false,-1, 31,0);
        tracep->declQuad(c+1,"RVNoob idu io_imm", false,-1, 63,0);
        tracep->declBit(c+3,"RVNoob idu io_wen", false,-1);
        tracep->declBus(c+160,"RVNoob idu io_rd", false,-1, 4,0);
        tracep->declBit(c+4,"RVNoob idu io_ren1", false,-1);
        tracep->declBus(c+161,"RVNoob idu io_rs1", false,-1, 4,0);
        tracep->declBit(c+162,"RVNoob idu io_add_en", false,-1);
        tracep->declBit(c+4,"RVNoob idu io_alu_src1_mux", false,-1);
        tracep->declBit(c+163,"RVNoob idu io_exe_out_mux", false,-1);
        tracep->declBit(c+164,"RVNoob idu io_dnpc_mux", false,-1);
        tracep->declBit(c+163,"RVNoob idu io_pc_mux", false,-1);
        tracep->declBit(c+165,"RVNoob idu io_dnpc_0b0", false,-1);
        tracep->declBus(c+156,"RVNoob idu dpi_inst_inst", false,-1, 31,0);
        tracep->declBus(c+170,"RVNoob idu opcode", false,-1, 6,0);
        tracep->declBus(c+171,"RVNoob idu fun3", false,-1, 2,0);
        tracep->declBit(c+7,"RVNoob idu rvi_addi", false,-1);
        tracep->declBit(c+172,"RVNoob idu rvi_auipc", false,-1);
        tracep->declBit(c+173,"RVNoob idu rvi_lui", false,-1);
        tracep->declBit(c+174,"RVNoob idu rvi_jal", false,-1);
        tracep->declBit(c+8,"RVNoob idu rvi_jalr", false,-1);
        tracep->declBit(c+4,"RVNoob idu type_I", false,-1);
        tracep->declBit(c+175,"RVNoob idu type_U", false,-1);
        tracep->declBus(c+9,"RVNoob idu immI_lo_lo_lo", false,-1, 5,0);
        tracep->declBus(c+10,"RVNoob idu immI_lo_lo", false,-1, 12,0);
        tracep->declBus(c+176,"RVNoob idu immI_lo", false,-1, 25,0);
        tracep->declQuad(c+177,"RVNoob idu immI_hi_1", false,-1, 51,0);
        tracep->declQuad(c+179,"RVNoob idu immI", false,-1, 63,0);
        tracep->declBus(c+11,"RVNoob idu immU_lo_lo", false,-1, 7,0);
        tracep->declBus(c+181,"RVNoob idu immU_lo", false,-1, 15,0);
        tracep->declBus(c+182,"RVNoob idu immU_hi_hi_1", false,-1, 31,0);
        tracep->declQuad(c+183,"RVNoob idu immU", false,-1, 63,0);
        tracep->declBus(c+12,"RVNoob idu immJ_lo_lo_lo", false,-1, 4,0);
        tracep->declBus(c+185,"RVNoob idu immJ_lo_lo", false,-1, 9,0);
        tracep->declBus(c+186,"RVNoob idu immJ_lo_hi", false,-1, 10,0);
        tracep->declBus(c+187,"RVNoob idu immJ_lo", false,-1, 20,0);
        tracep->declBus(c+188,"RVNoob idu immJ_hi_lo_1", false,-1, 7,0);
        tracep->declBit(c+189,"RVNoob idu immJ_lo_hi_hi_1", false,-1);
        tracep->declBus(c+190,"RVNoob idu immJ_lo_hi_lo_1", false,-1, 9,0);
        tracep->declQuad(c+13,"RVNoob idu immJ_hi_hi_1", false,-1, 43,0);
        tracep->declQuad(c+191,"RVNoob idu immJ", false,-1, 63,0);
        tracep->declBus(c+156,"RVNoob idu dpi_inst inst", false,-1, 31,0);
        tracep->declBit(c+152,"RVNoob rf clock", false,-1);
        tracep->declBit(c+153,"RVNoob rf reset", false,-1);
        tracep->declBit(c+3,"RVNoob rf io_wen", false,-1);
        tracep->declQuad(c+5,"RVNoob rf io_wdata", false,-1, 63,0);
        tracep->declBus(c+160,"RVNoob rf io_waddr", false,-1, 4,0);
        tracep->declBit(c+4,"RVNoob rf io_ren1", false,-1);
        tracep->declQuad(c+166,"RVNoob rf io_rdata1", false,-1, 63,0);
        tracep->declBus(c+161,"RVNoob rf io_raddr1", false,-1, 4,0);
        tracep->declQuad(c+19,"RVNoob rf io_a0", false,-1, 63,0);
        tracep->declQuad(c+26,"RVNoob rf rf_read_rf_0", false,-1, 63,0);
        tracep->declQuad(c+28,"RVNoob rf rf_read_rf_1", false,-1, 63,0);
        tracep->declQuad(c+30,"RVNoob rf rf_read_rf_2", false,-1, 63,0);
        tracep->declQuad(c+32,"RVNoob rf rf_read_rf_3", false,-1, 63,0);
        tracep->declQuad(c+34,"RVNoob rf rf_read_rf_4", false,-1, 63,0);
        tracep->declQuad(c+36,"RVNoob rf rf_read_rf_5", false,-1, 63,0);
        tracep->declQuad(c+38,"RVNoob rf rf_read_rf_6", false,-1, 63,0);
        tracep->declQuad(c+40,"RVNoob rf rf_read_rf_7", false,-1, 63,0);
        tracep->declQuad(c+42,"RVNoob rf rf_read_rf_8", false,-1, 63,0);
        tracep->declQuad(c+44,"RVNoob rf rf_read_rf_9", false,-1, 63,0);
        tracep->declQuad(c+19,"RVNoob rf rf_read_rf_10", false,-1, 63,0);
        tracep->declQuad(c+46,"RVNoob rf rf_read_rf_11", false,-1, 63,0);
        tracep->declQuad(c+48,"RVNoob rf rf_read_rf_12", false,-1, 63,0);
        tracep->declQuad(c+50,"RVNoob rf rf_read_rf_13", false,-1, 63,0);
        tracep->declQuad(c+52,"RVNoob rf rf_read_rf_14", false,-1, 63,0);
        tracep->declQuad(c+54,"RVNoob rf rf_read_rf_15", false,-1, 63,0);
        tracep->declQuad(c+56,"RVNoob rf rf_read_rf_16", false,-1, 63,0);
        tracep->declQuad(c+58,"RVNoob rf rf_read_rf_17", false,-1, 63,0);
        tracep->declQuad(c+60,"RVNoob rf rf_read_rf_18", false,-1, 63,0);
        tracep->declQuad(c+62,"RVNoob rf rf_read_rf_19", false,-1, 63,0);
        tracep->declQuad(c+64,"RVNoob rf rf_read_rf_20", false,-1, 63,0);
        tracep->declQuad(c+66,"RVNoob rf rf_read_rf_21", false,-1, 63,0);
        tracep->declQuad(c+68,"RVNoob rf rf_read_rf_22", false,-1, 63,0);
        tracep->declQuad(c+70,"RVNoob rf rf_read_rf_23", false,-1, 63,0);
        tracep->declQuad(c+72,"RVNoob rf rf_read_rf_24", false,-1, 63,0);
        tracep->declQuad(c+74,"RVNoob rf rf_read_rf_25", false,-1, 63,0);
        tracep->declQuad(c+76,"RVNoob rf rf_read_rf_26", false,-1, 63,0);
        tracep->declQuad(c+78,"RVNoob rf rf_read_rf_27", false,-1, 63,0);
        tracep->declQuad(c+80,"RVNoob rf rf_read_rf_28", false,-1, 63,0);
        tracep->declQuad(c+82,"RVNoob rf rf_read_rf_29", false,-1, 63,0);
        tracep->declQuad(c+84,"RVNoob rf rf_read_rf_30", false,-1, 63,0);
        tracep->declQuad(c+86,"RVNoob rf rf_read_rf_31", false,-1, 63,0);
        tracep->declQuad(c+26,"RVNoob rf rf_0", false,-1, 63,0);
        tracep->declQuad(c+28,"RVNoob rf rf_1", false,-1, 63,0);
        tracep->declQuad(c+30,"RVNoob rf rf_2", false,-1, 63,0);
        tracep->declQuad(c+32,"RVNoob rf rf_3", false,-1, 63,0);
        tracep->declQuad(c+34,"RVNoob rf rf_4", false,-1, 63,0);
        tracep->declQuad(c+36,"RVNoob rf rf_5", false,-1, 63,0);
        tracep->declQuad(c+38,"RVNoob rf rf_6", false,-1, 63,0);
        tracep->declQuad(c+40,"RVNoob rf rf_7", false,-1, 63,0);
        tracep->declQuad(c+42,"RVNoob rf rf_8", false,-1, 63,0);
        tracep->declQuad(c+44,"RVNoob rf rf_9", false,-1, 63,0);
        tracep->declQuad(c+19,"RVNoob rf rf_10", false,-1, 63,0);
        tracep->declQuad(c+46,"RVNoob rf rf_11", false,-1, 63,0);
        tracep->declQuad(c+48,"RVNoob rf rf_12", false,-1, 63,0);
        tracep->declQuad(c+50,"RVNoob rf rf_13", false,-1, 63,0);
        tracep->declQuad(c+52,"RVNoob rf rf_14", false,-1, 63,0);
        tracep->declQuad(c+54,"RVNoob rf rf_15", false,-1, 63,0);
        tracep->declQuad(c+56,"RVNoob rf rf_16", false,-1, 63,0);
        tracep->declQuad(c+58,"RVNoob rf rf_17", false,-1, 63,0);
        tracep->declQuad(c+60,"RVNoob rf rf_18", false,-1, 63,0);
        tracep->declQuad(c+62,"RVNoob rf rf_19", false,-1, 63,0);
        tracep->declQuad(c+64,"RVNoob rf rf_20", false,-1, 63,0);
        tracep->declQuad(c+66,"RVNoob rf rf_21", false,-1, 63,0);
        tracep->declQuad(c+68,"RVNoob rf rf_22", false,-1, 63,0);
        tracep->declQuad(c+70,"RVNoob rf rf_23", false,-1, 63,0);
        tracep->declQuad(c+72,"RVNoob rf rf_24", false,-1, 63,0);
        tracep->declQuad(c+74,"RVNoob rf rf_25", false,-1, 63,0);
        tracep->declQuad(c+76,"RVNoob rf rf_26", false,-1, 63,0);
        tracep->declQuad(c+78,"RVNoob rf rf_27", false,-1, 63,0);
        tracep->declQuad(c+80,"RVNoob rf rf_28", false,-1, 63,0);
        tracep->declQuad(c+82,"RVNoob rf rf_29", false,-1, 63,0);
        tracep->declQuad(c+84,"RVNoob rf rf_30", false,-1, 63,0);
        tracep->declQuad(c+86,"RVNoob rf rf_31", false,-1, 63,0);
        tracep->declQuad(c+193,"RVNoob rf rdata1", false,-1, 63,0);
        tracep->declQuad(c+26,"RVNoob rf rf_read rf_0", false,-1, 63,0);
        tracep->declQuad(c+28,"RVNoob rf rf_read rf_1", false,-1, 63,0);
        tracep->declQuad(c+30,"RVNoob rf rf_read rf_2", false,-1, 63,0);
        tracep->declQuad(c+32,"RVNoob rf rf_read rf_3", false,-1, 63,0);
        tracep->declQuad(c+34,"RVNoob rf rf_read rf_4", false,-1, 63,0);
        tracep->declQuad(c+36,"RVNoob rf rf_read rf_5", false,-1, 63,0);
        tracep->declQuad(c+38,"RVNoob rf rf_read rf_6", false,-1, 63,0);
        tracep->declQuad(c+40,"RVNoob rf rf_read rf_7", false,-1, 63,0);
        tracep->declQuad(c+42,"RVNoob rf rf_read rf_8", false,-1, 63,0);
        tracep->declQuad(c+44,"RVNoob rf rf_read rf_9", false,-1, 63,0);
        tracep->declQuad(c+19,"RVNoob rf rf_read rf_10", false,-1, 63,0);
        tracep->declQuad(c+46,"RVNoob rf rf_read rf_11", false,-1, 63,0);
        tracep->declQuad(c+48,"RVNoob rf rf_read rf_12", false,-1, 63,0);
        tracep->declQuad(c+50,"RVNoob rf rf_read rf_13", false,-1, 63,0);
        tracep->declQuad(c+52,"RVNoob rf rf_read rf_14", false,-1, 63,0);
        tracep->declQuad(c+54,"RVNoob rf rf_read rf_15", false,-1, 63,0);
        tracep->declQuad(c+56,"RVNoob rf rf_read rf_16", false,-1, 63,0);
        tracep->declQuad(c+58,"RVNoob rf rf_read rf_17", false,-1, 63,0);
        tracep->declQuad(c+60,"RVNoob rf rf_read rf_18", false,-1, 63,0);
        tracep->declQuad(c+62,"RVNoob rf rf_read rf_19", false,-1, 63,0);
        tracep->declQuad(c+64,"RVNoob rf rf_read rf_20", false,-1, 63,0);
        tracep->declQuad(c+66,"RVNoob rf rf_read rf_21", false,-1, 63,0);
        tracep->declQuad(c+68,"RVNoob rf rf_read rf_22", false,-1, 63,0);
        tracep->declQuad(c+70,"RVNoob rf rf_read rf_23", false,-1, 63,0);
        tracep->declQuad(c+72,"RVNoob rf rf_read rf_24", false,-1, 63,0);
        tracep->declQuad(c+74,"RVNoob rf rf_read rf_25", false,-1, 63,0);
        tracep->declQuad(c+76,"RVNoob rf rf_read rf_26", false,-1, 63,0);
        tracep->declQuad(c+78,"RVNoob rf rf_read rf_27", false,-1, 63,0);
        tracep->declQuad(c+80,"RVNoob rf rf_read rf_28", false,-1, 63,0);
        tracep->declQuad(c+82,"RVNoob rf rf_read rf_29", false,-1, 63,0);
        tracep->declQuad(c+84,"RVNoob rf rf_read rf_30", false,-1, 63,0);
        tracep->declQuad(c+86,"RVNoob rf rf_read rf_31", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+88+i*2,"RVNoob rf rf_read rf", true,(i+0), 63,0);}}
        tracep->declQuad(c+166,"RVNoob exe io_src1", false,-1, 63,0);
        tracep->declQuad(c+1,"RVNoob exe io_imm", false,-1, 63,0);
        tracep->declQuad(c+21,"RVNoob exe io_pc", false,-1, 63,0);
        tracep->declQuad(c+23,"RVNoob exe io_snpc", false,-1, 63,0);
        tracep->declQuad(c+5,"RVNoob exe io_gp_out", false,-1, 63,0);
        tracep->declQuad(c+168,"RVNoob exe io_dnpc", false,-1, 63,0);
        tracep->declBit(c+162,"RVNoob exe io_add_en", false,-1);
        tracep->declBit(c+4,"RVNoob exe io_alu_src1_mux", false,-1);
        tracep->declBit(c+163,"RVNoob exe io_exe_out_mux", false,-1);
        tracep->declBit(c+164,"RVNoob exe io_dnpc_mux", false,-1);
        tracep->declBit(c+165,"RVNoob exe io_dnpc_0b0", false,-1);
        tracep->declQuad(c+195,"RVNoob exe alu_src1", false,-1, 63,0);
        tracep->declQuad(c+15,"RVNoob exe alu_out", false,-1, 63,0);
        tracep->declQuad(c+17,"RVNoob exe io_dnpc_hi", false,-1, 62,0);
        tracep->declBit(c+197,"RVNoob exe io_dnpc_lo", false,-1);
        tracep->declBit(c+152,"RVNoob U_ebreak clk", false,-1);
        tracep->declBus(c+156,"RVNoob U_ebreak inst", false,-1, 31,0);
        tracep->declQuad(c+19,"RVNoob U_ebreak a0", false,-1, 63,0);
        tracep->declBit(c+25,"RVNoob U_ebreak ebreak", false,-1);
    }
}

void VRVNoob___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VRVNoob___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VRVNoob___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VRVNoob___024root__traceRegister(VRVNoob___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VRVNoob___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VRVNoob___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VRVNoob___024root__traceCleanup, vlSelf);
    }
}

void VRVNoob___024root__traceFullSub0(VRVNoob___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VRVNoob___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VRVNoob___024root* const __restrict vlSelf = static_cast<VRVNoob___024root*>(voidSelf);
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VRVNoob___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VRVNoob___024root__traceFullSub0(VRVNoob___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullQData(oldp+1,(vlSelf->RVNoob__DOT__idu_io_imm),64);
        tracep->fullBit(oldp+3,(vlSelf->RVNoob__DOT__idu_io_wen));
        tracep->fullBit(oldp+4,(((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                 | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))));
        tracep->fullQData(oldp+5,(vlSelf->RVNoob__DOT__exe_io_gp_out),64);
        tracep->fullBit(oldp+7,(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi));
        tracep->fullBit(oldp+8,(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr));
        tracep->fullCData(oldp+9,(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo),6);
        tracep->fullSData(oldp+10,(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo),13);
        tracep->fullCData(oldp+11,(vlSelf->RVNoob__DOT__idu__DOT__immU_lo_lo),8);
        tracep->fullCData(oldp+12,(vlSelf->RVNoob__DOT__idu__DOT__immJ_lo_lo_lo),5);
        tracep->fullQData(oldp+13,(vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1),44);
        tracep->fullQData(oldp+15,(vlSelf->RVNoob__DOT__exe__DOT__alu_out),64);
        tracep->fullQData(oldp+17,((vlSelf->RVNoob__DOT__exe__DOT__alu_out 
                                    >> 1U)),63);
        tracep->fullQData(oldp+19,(vlSelf->RVNoob__DOT__rf__DOT__rf_10),64);
        tracep->fullQData(oldp+21,(vlSelf->RVNoob__DOT__pc),64);
        tracep->fullQData(oldp+23,((4ULL + vlSelf->RVNoob__DOT__pc)),64);
        tracep->fullBit(oldp+25,(vlSelf->RVNoob__DOT__U_ebreak_ebreak));
        tracep->fullQData(oldp+26,(vlSelf->RVNoob__DOT__rf__DOT__rf_0),64);
        tracep->fullQData(oldp+28,(vlSelf->RVNoob__DOT__rf__DOT__rf_1),64);
        tracep->fullQData(oldp+30,(vlSelf->RVNoob__DOT__rf__DOT__rf_2),64);
        tracep->fullQData(oldp+32,(vlSelf->RVNoob__DOT__rf__DOT__rf_3),64);
        tracep->fullQData(oldp+34,(vlSelf->RVNoob__DOT__rf__DOT__rf_4),64);
        tracep->fullQData(oldp+36,(vlSelf->RVNoob__DOT__rf__DOT__rf_5),64);
        tracep->fullQData(oldp+38,(vlSelf->RVNoob__DOT__rf__DOT__rf_6),64);
        tracep->fullQData(oldp+40,(vlSelf->RVNoob__DOT__rf__DOT__rf_7),64);
        tracep->fullQData(oldp+42,(vlSelf->RVNoob__DOT__rf__DOT__rf_8),64);
        tracep->fullQData(oldp+44,(vlSelf->RVNoob__DOT__rf__DOT__rf_9),64);
        tracep->fullQData(oldp+46,(vlSelf->RVNoob__DOT__rf__DOT__rf_11),64);
        tracep->fullQData(oldp+48,(vlSelf->RVNoob__DOT__rf__DOT__rf_12),64);
        tracep->fullQData(oldp+50,(vlSelf->RVNoob__DOT__rf__DOT__rf_13),64);
        tracep->fullQData(oldp+52,(vlSelf->RVNoob__DOT__rf__DOT__rf_14),64);
        tracep->fullQData(oldp+54,(vlSelf->RVNoob__DOT__rf__DOT__rf_15),64);
        tracep->fullQData(oldp+56,(vlSelf->RVNoob__DOT__rf__DOT__rf_16),64);
        tracep->fullQData(oldp+58,(vlSelf->RVNoob__DOT__rf__DOT__rf_17),64);
        tracep->fullQData(oldp+60,(vlSelf->RVNoob__DOT__rf__DOT__rf_18),64);
        tracep->fullQData(oldp+62,(vlSelf->RVNoob__DOT__rf__DOT__rf_19),64);
        tracep->fullQData(oldp+64,(vlSelf->RVNoob__DOT__rf__DOT__rf_20),64);
        tracep->fullQData(oldp+66,(vlSelf->RVNoob__DOT__rf__DOT__rf_21),64);
        tracep->fullQData(oldp+68,(vlSelf->RVNoob__DOT__rf__DOT__rf_22),64);
        tracep->fullQData(oldp+70,(vlSelf->RVNoob__DOT__rf__DOT__rf_23),64);
        tracep->fullQData(oldp+72,(vlSelf->RVNoob__DOT__rf__DOT__rf_24),64);
        tracep->fullQData(oldp+74,(vlSelf->RVNoob__DOT__rf__DOT__rf_25),64);
        tracep->fullQData(oldp+76,(vlSelf->RVNoob__DOT__rf__DOT__rf_26),64);
        tracep->fullQData(oldp+78,(vlSelf->RVNoob__DOT__rf__DOT__rf_27),64);
        tracep->fullQData(oldp+80,(vlSelf->RVNoob__DOT__rf__DOT__rf_28),64);
        tracep->fullQData(oldp+82,(vlSelf->RVNoob__DOT__rf__DOT__rf_29),64);
        tracep->fullQData(oldp+84,(vlSelf->RVNoob__DOT__rf__DOT__rf_30),64);
        tracep->fullQData(oldp+86,(vlSelf->RVNoob__DOT__rf__DOT__rf_31),64);
        tracep->fullQData(oldp+88,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0]),64);
        tracep->fullQData(oldp+90,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[1]),64);
        tracep->fullQData(oldp+92,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[2]),64);
        tracep->fullQData(oldp+94,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[3]),64);
        tracep->fullQData(oldp+96,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[4]),64);
        tracep->fullQData(oldp+98,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[5]),64);
        tracep->fullQData(oldp+100,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[6]),64);
        tracep->fullQData(oldp+102,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[7]),64);
        tracep->fullQData(oldp+104,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[8]),64);
        tracep->fullQData(oldp+106,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[9]),64);
        tracep->fullQData(oldp+108,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[10]),64);
        tracep->fullQData(oldp+110,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[11]),64);
        tracep->fullQData(oldp+112,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[12]),64);
        tracep->fullQData(oldp+114,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[13]),64);
        tracep->fullQData(oldp+116,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[14]),64);
        tracep->fullQData(oldp+118,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[15]),64);
        tracep->fullQData(oldp+120,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[16]),64);
        tracep->fullQData(oldp+122,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[17]),64);
        tracep->fullQData(oldp+124,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[18]),64);
        tracep->fullQData(oldp+126,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[19]),64);
        tracep->fullQData(oldp+128,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[20]),64);
        tracep->fullQData(oldp+130,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[21]),64);
        tracep->fullQData(oldp+132,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[22]),64);
        tracep->fullQData(oldp+134,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[23]),64);
        tracep->fullQData(oldp+136,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[24]),64);
        tracep->fullQData(oldp+138,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[25]),64);
        tracep->fullQData(oldp+140,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[26]),64);
        tracep->fullQData(oldp+142,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[27]),64);
        tracep->fullQData(oldp+144,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[28]),64);
        tracep->fullQData(oldp+146,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[29]),64);
        tracep->fullQData(oldp+148,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[30]),64);
        tracep->fullQData(oldp+150,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[31]),64);
        tracep->fullBit(oldp+152,(vlSelf->clock));
        tracep->fullBit(oldp+153,(vlSelf->reset));
        tracep->fullQData(oldp+154,(vlSelf->io_pc),64);
        tracep->fullIData(oldp+156,(vlSelf->io_inst),32);
        tracep->fullQData(oldp+157,(vlSelf->io_res),64);
        tracep->fullBit(oldp+159,(vlSelf->io_ebreak));
        tracep->fullCData(oldp+160,((0x1fU & (vlSelf->io_inst 
                                              >> 7U))),5);
        tracep->fullCData(oldp+161,((0x1fU & (vlSelf->io_inst 
                                              >> 0xfU))),5);
        tracep->fullBit(oldp+162,(((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                     | (0x17U == (0x7fU 
                                                  & vlSelf->io_inst))) 
                                    | (0x6fU == (0x7fU 
                                                 & vlSelf->io_inst))) 
                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))));
        tracep->fullBit(oldp+163,(((0x6fU == (0x7fU 
                                              & vlSelf->io_inst)) 
                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))));
        tracep->fullBit(oldp+164,((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr) 
                                    | (0x17U == (0x7fU 
                                                 & vlSelf->io_inst))) 
                                   | (0x6fU == (0x7fU 
                                                & vlSelf->io_inst)))));
        tracep->fullBit(oldp+165,((IData)((0x67U == 
                                           (0x707fU 
                                            & vlSelf->io_inst)))));
        tracep->fullQData(oldp+166,((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
                                      | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))
                                      ? ((0x1fU == 
                                          (0x1fU & 
                                           (vlSelf->io_inst 
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
        tracep->fullQData(oldp+168,(((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr) 
                                       | (0x17U == 
                                          (0x7fU & vlSelf->io_inst))) 
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
        tracep->fullCData(oldp+170,((0x7fU & vlSelf->io_inst)),7);
        tracep->fullCData(oldp+171,((7U & (vlSelf->io_inst 
                                           >> 0xcU))),3);
        tracep->fullBit(oldp+172,((0x17U == (0x7fU 
                                             & vlSelf->io_inst))));
        tracep->fullBit(oldp+173,((0x37U == (0x7fU 
                                             & vlSelf->io_inst))));
        tracep->fullBit(oldp+174,((0x6fU == (0x7fU 
                                             & vlSelf->io_inst))));
        tracep->fullBit(oldp+175,(((0x17U == (0x7fU 
                                              & vlSelf->io_inst)) 
                                   | (0x37U == (0x7fU 
                                                & vlSelf->io_inst)))));
        tracep->fullIData(oldp+176,(((0x2000000U & 
                                      (vlSelf->io_inst 
                                       >> 6U)) | ((0x1000000U 
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
        tracep->fullQData(oldp+177,((((QData)((IData)(
                                                      (vlSelf->io_inst 
                                                       >> 0x1fU))) 
                                      << 0x33U) | (
                                                   ((QData)((IData)(
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
        tracep->fullQData(oldp+179,((((QData)((IData)(
                                                      (vlSelf->io_inst 
                                                       >> 0x1fU))) 
                                      << 0x3fU) | (
                                                   ((QData)((IData)(
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
        tracep->fullSData(oldp+181,(((0x8000U & (vlSelf->io_inst 
                                                 >> 0x10U)) 
                                     | ((0x4000U & 
                                         (vlSelf->io_inst 
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
        tracep->fullIData(oldp+182,(((0x80000000U & vlSelf->io_inst) 
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
        tracep->fullQData(oldp+183,((((QData)((IData)(
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
        tracep->fullSData(oldp+185,(((0x200U & (vlSelf->io_inst 
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
        tracep->fullSData(oldp+186,(((0x400U & (vlSelf->io_inst 
                                                >> 0x15U)) 
                                     | ((0x200U & (vlSelf->io_inst 
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
                                                    | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immJ_lo_lo_lo)))))))),11);
        tracep->fullIData(oldp+187,(((0x100000U & (vlSelf->io_inst 
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
        tracep->fullCData(oldp+188,((0xffU & (vlSelf->io_inst 
                                              >> 0xcU))),8);
        tracep->fullBit(oldp+189,((1U & (vlSelf->io_inst 
                                         >> 0x14U))));
        tracep->fullSData(oldp+190,((0x3ffU & (vlSelf->io_inst 
                                               >> 0x15U))),10);
        tracep->fullQData(oldp+191,(((vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1 
                                      << 0x14U) | (QData)((IData)(
                                                                  ((0xff000U 
                                                                    & vlSelf->io_inst) 
                                                                   | ((0x800U 
                                                                       & (vlSelf->io_inst 
                                                                          >> 9U)) 
                                                                      | (0x7feU 
                                                                         & (vlSelf->io_inst 
                                                                            >> 0x14U)))))))),64);
        tracep->fullQData(oldp+193,(((0x1fU == (0x1fU 
                                                & (vlSelf->io_inst 
                                                   >> 0xfU)))
                                      ? vlSelf->RVNoob__DOT__rf__DOT__rf_31
                                      : ((0x1eU == 
                                          (0x1fU & 
                                           (vlSelf->io_inst 
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
        tracep->fullQData(oldp+195,((((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi) 
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
        tracep->fullBit(oldp+197,((1U & ((~ (IData)(
                                                    (0x67U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->io_inst)))) 
                                         & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_out)))));
    }
}
