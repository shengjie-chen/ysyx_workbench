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
    VlWide<6>/*191:0*/ __Vtemp276;
    VlWide<6>/*191:0*/ __Vtemp277;
    VlWide<3>/*95:0*/ __Vtemp279;
    VlWide<3>/*95:0*/ __Vtemp282;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
            tracep->chgQData(oldp+0,((((QData)((IData)(
                                                       vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[1U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U])))),64);
            tracep->chgQData(oldp+2,(vlSelf->RVNoob__DOT__rf_io_rdata2),64);
            tracep->chgQData(oldp+4,(((0x3fU >= (0x38U 
                                                 & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U] 
                                                    << 3U)))
                                       ? (vlSelf->RVNoob__DOT__ifm__DOT__dpi_pmem_rdata 
                                          >> (0x38U 
                                              & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U] 
                                                 << 3U)))
                                       : 0ULL)),64);
            tracep->chgCData(oldp+6,(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op),2);
            tracep->chgBit(oldp+7,(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem));
            tracep->chgBit(oldp+8,(vlSelf->RVNoob__DOT__idu__DOT__type_S));
            tracep->chgQData(oldp+9,(vlSelf->RVNoob__DOT__idu_io_imm),64);
            tracep->chgBit(oldp+11,(vlSelf->RVNoob__DOT__idu_io_wen));
            tracep->chgBit(oldp+12,(((((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_I) 
                                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_R)) 
                                      | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S)) 
                                     | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_B))));
            tracep->chgBit(oldp+13,((((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S) 
                                      | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_R)) 
                                     | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_B))));
            tracep->chgBit(oldp+14,((((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_slt) 
                                      | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sextw)) 
                                     | (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem))));
            tracep->chgCData(oldp+15,(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op),4);
            tracep->chgCData(oldp+16,(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op),5);
            tracep->chgBit(oldp+17,(((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_I) 
                                     | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S))));
            tracep->chgBit(oldp+18,(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr));
            tracep->chgBit(oldp+19,(vlSelf->RVNoob__DOT__idu_io_pc_mux));
            tracep->chgQData(oldp+20,(vlSelf->RVNoob__DOT__exe_io_gp_out),64);
            tracep->chgQData(oldp+22,(vlSelf->RVNoob__DOT__rf_io_rdata1),64);
            tracep->chgBit(oldp+24,((1U & ((1U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                            ? (0ULL 
                                               == (
                                                   ((QData)((IData)(
                                                                    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U]))))
                                            : ((2U 
                                                == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                ? (0ULL 
                                                   != 
                                                   (((QData)((IData)(
                                                                     vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U]))))
                                                : (
                                                   (3U 
                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                    ? 
                                                   vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[2U]
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op)) 
                                                    & ((~ 
                                                        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[2U]) 
                                                       | (0ULL 
                                                          == 
                                                          (((QData)((IData)(
                                                                            vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U]))))))))))));
            tracep->chgQData(oldp+25,(vlSelf->RVNoob__DOT__npc_add_res),64);
            tracep->chgQData(oldp+27,((vlSelf->RVNoob__DOT__npc_add_res 
                                       >> 1U)),63);
            tracep->chgQData(oldp+29,(((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr)
                                        ? (0xfffffffffffffffeULL 
                                           & vlSelf->RVNoob__DOT__npc_add_res)
                                        : vlSelf->RVNoob__DOT__npc_add_res)),64);
            tracep->chgCData(oldp+31,(((3U == (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))
                                        ? 0xffU : (0xffU 
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
                                                            : 0xffU))))))),8);
            tracep->chgQData(oldp+32,(vlSelf->RVNoob__DOT__ifm__DOT__dpi_pmem_rdata),64);
            VL_EXTEND_WQ(191,64, __Vtemp276, vlSelf->RVNoob__DOT__rf_io_rdata2);
            VL_SHIFTL_WWI(191,191,7, __Vtemp277, __Vtemp276, 
                          (0x38U & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U] 
                                    << 3U)));
            tracep->chgQData(oldp+34,((((QData)((IData)(
                                                        __Vtemp277[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    __Vtemp277[0U])))),64);
            tracep->chgCData(oldp+36,((7U & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U])),3);
            tracep->chgBit(oldp+37,(vlSelf->RVNoob__DOT__idu__DOT__rvi_beq));
            tracep->chgBit(oldp+38,(vlSelf->RVNoob__DOT__idu__DOT__rvi_bne));
            tracep->chgBit(oldp+39,(vlSelf->RVNoob__DOT__idu__DOT__rvi_blt));
            tracep->chgBit(oldp+40,(vlSelf->RVNoob__DOT__idu__DOT__rvi_bge));
            tracep->chgBit(oldp+41,(vlSelf->RVNoob__DOT__idu__DOT__rvi_bltu));
            tracep->chgBit(oldp+42,(vlSelf->RVNoob__DOT__idu__DOT__rvi_bgeu));
            tracep->chgBit(oldp+43,(vlSelf->RVNoob__DOT__idu__DOT__jpg_sexb));
            tracep->chgBit(oldp+44,(vlSelf->RVNoob__DOT__idu__DOT__jpg_sexthw));
            tracep->chgBit(oldp+45,(vlSelf->RVNoob__DOT__idu__DOT__rvi_lw));
            tracep->chgBit(oldp+46,(vlSelf->RVNoob__DOT__idu__DOT__jpg_uextb));
            tracep->chgBit(oldp+47,(vlSelf->RVNoob__DOT__idu__DOT__jpg_uexthw));
            tracep->chgBit(oldp+48,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sb));
            tracep->chgBit(oldp+49,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sh));
            tracep->chgBit(oldp+50,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sw));
            tracep->chgBit(oldp+51,(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi));
            tracep->chgBit(oldp+52,(vlSelf->RVNoob__DOT__idu__DOT__rvi_slti));
            tracep->chgBit(oldp+53,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sltiu));
            tracep->chgBit(oldp+54,(vlSelf->RVNoob__DOT__idu__DOT__rvi_xori));
            tracep->chgBit(oldp+55,(vlSelf->RVNoob__DOT__idu__DOT__rvi_ori));
            tracep->chgBit(oldp+56,(vlSelf->RVNoob__DOT__idu__DOT__rvi_andi));
            tracep->chgBit(oldp+57,(vlSelf->RVNoob__DOT__idu__DOT__rvi_add));
            tracep->chgBit(oldp+58,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sub));
            tracep->chgBit(oldp+59,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sll));
            tracep->chgBit(oldp+60,(vlSelf->RVNoob__DOT__idu__DOT__rvi_slt));
            tracep->chgBit(oldp+61,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sltu));
            tracep->chgBit(oldp+62,(vlSelf->RVNoob__DOT__idu__DOT__rvi_xor));
            tracep->chgBit(oldp+63,(vlSelf->RVNoob__DOT__idu__DOT__rvi_srl));
            tracep->chgBit(oldp+64,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sra));
            tracep->chgBit(oldp+65,(vlSelf->RVNoob__DOT__idu__DOT__rvi_or));
            tracep->chgBit(oldp+66,(vlSelf->RVNoob__DOT__idu__DOT__rvi_and));
            tracep->chgBit(oldp+67,(vlSelf->RVNoob__DOT__idu__DOT__jpg_uextw));
            tracep->chgBit(oldp+68,(vlSelf->RVNoob__DOT__idu__DOT__rvi_ld));
            tracep->chgBit(oldp+69,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sd));
            tracep->chgBit(oldp+70,(vlSelf->RVNoob__DOT__idu__DOT__rvi_slli));
            tracep->chgBit(oldp+71,(vlSelf->RVNoob__DOT__idu__DOT__rvi_srli));
            tracep->chgBit(oldp+72,(vlSelf->RVNoob__DOT__idu__DOT__rvi_srai));
            tracep->chgBit(oldp+73,(vlSelf->RVNoob__DOT__idu__DOT__rvi_addiw));
            tracep->chgBit(oldp+74,(vlSelf->RVNoob__DOT__idu__DOT__rvi_slliw));
            tracep->chgBit(oldp+75,(vlSelf->RVNoob__DOT__idu__DOT__rvi_srliw));
            tracep->chgBit(oldp+76,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sraiw));
            tracep->chgBit(oldp+77,(vlSelf->RVNoob__DOT__idu__DOT__rvi_addw));
            tracep->chgBit(oldp+78,(vlSelf->RVNoob__DOT__idu__DOT__rvi_subw));
            tracep->chgBit(oldp+79,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sllw));
            tracep->chgBit(oldp+80,(vlSelf->RVNoob__DOT__idu__DOT__rvi_srlw));
            tracep->chgBit(oldp+81,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sraw));
            tracep->chgBit(oldp+82,(vlSelf->RVNoob__DOT__idu__DOT__rvm_mul));
            tracep->chgBit(oldp+83,(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulh));
            tracep->chgBit(oldp+84,(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulhsu));
            tracep->chgBit(oldp+85,(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulhu));
            tracep->chgBit(oldp+86,(vlSelf->RVNoob__DOT__idu__DOT__rvm_div));
            tracep->chgBit(oldp+87,(vlSelf->RVNoob__DOT__idu__DOT__rvm_divu));
            tracep->chgBit(oldp+88,(vlSelf->RVNoob__DOT__idu__DOT__rvm_rem));
            tracep->chgBit(oldp+89,(vlSelf->RVNoob__DOT__idu__DOT__rvm_remu));
            tracep->chgBit(oldp+90,(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulw));
            tracep->chgBit(oldp+91,(vlSelf->RVNoob__DOT__idu__DOT__rvm_divw));
            tracep->chgBit(oldp+92,(vlSelf->RVNoob__DOT__idu__DOT__rvm_remw));
            tracep->chgBit(oldp+93,(vlSelf->RVNoob__DOT__idu__DOT__type_I));
            tracep->chgBit(oldp+94,(vlSelf->RVNoob__DOT__idu__DOT__type_U));
            tracep->chgBit(oldp+95,(vlSelf->RVNoob__DOT__idu__DOT__type_R));
            tracep->chgBit(oldp+96,(vlSelf->RVNoob__DOT__idu__DOT__type_B));
            tracep->chgCData(oldp+97,(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo),6);
            tracep->chgSData(oldp+98,(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo),13);
            tracep->chgCData(oldp+99,(vlSelf->RVNoob__DOT__idu__DOT__immU_lo_lo),8);
            tracep->chgCData(oldp+100,(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo_lo),6);
            tracep->chgSData(oldp+101,(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo),13);
            tracep->chgCData(oldp+102,(vlSelf->RVNoob__DOT__idu__DOT__immJ_lo_lo_lo),5);
            tracep->chgQData(oldp+103,(vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1),44);
            tracep->chgQData(oldp+105,(vlSelf->RVNoob__DOT__idu__DOT__immB_hi_hi_hi_1),51);
            tracep->chgBit(oldp+107,(vlSelf->RVNoob__DOT__idu__DOT__jpg_slt));
            tracep->chgBit(oldp+108,(vlSelf->RVNoob__DOT__idu__DOT__jpg_sextw));
            tracep->chgQData(oldp+109,(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1),64);
            tracep->chgQData(oldp+111,(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src2),64);
            VL_EXTEND_WI(65,1, __Vtemp279, (1U & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[2U]));
            tracep->chgQData(oldp+113,(((((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_slt) 
                                          | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sextw)) 
                                         | (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem))
                                         ? (((QData)((IData)(
                                                             ((5U 
                                                               == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                               ? 
                                                              __Vtemp279[1U]
                                                               : 
                                                              vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_155[1U]))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              ((5U 
                                                                == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                                ? 
                                                               __Vtemp279[0U]
                                                                : 
                                                               vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_155[0U]))))
                                         : (((QData)((IData)(
                                                             vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_85[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_85[0U]))))),64);
            tracep->chgWData(oldp+115,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res),65);
            VL_EXTEND_WI(65,1, __Vtemp282, (1U & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[2U]));
            tracep->chgQData(oldp+118,((((QData)((IData)(
                                                         ((5U 
                                                           == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                           ? 
                                                          __Vtemp282[1U]
                                                           : 
                                                          vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_155[1U]))) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((5U 
                                                            == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                            ? 
                                                           __Vtemp282[0U]
                                                            : 
                                                           vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_155[0U]))))),64);
            tracep->chgBit(oldp+120,((1U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+121,((2U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+122,((3U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+123,((4U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+124,((5U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+125,((6U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+126,((7U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+127,((8U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+128,((9U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+129,((0xaU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+130,((0xbU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+131,((0xcU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+132,((0xdU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+133,((0xeU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+134,((0xfU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+135,((0x10U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+136,((0x11U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+137,((0x12U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+138,((0x13U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+139,((0x14U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+140,((0x15U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+141,((0x16U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgBit(oldp+142,((0x17U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
            tracep->chgQData(oldp+143,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2),64);
            tracep->chgWData(oldp+145,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res),65);
            tracep->chgQData(oldp+148,((((QData)((IData)(
                                                         vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_85[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_85[0U])))),64);
            tracep->chgBit(oldp+150,((0ULL == (((QData)((IData)(
                                                                vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[1U])) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U]))))));
            tracep->chgIData(oldp+151,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U]),32);
            tracep->chgCData(oldp+152,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo),8);
            tracep->chgSData(oldp+153,(((0x8000U & 
                                         (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                          >> 0x10U)) 
                                        | ((0x4000U 
                                            & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                               >> 0x11U)) 
                                           | ((0x2000U 
                                               & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                  >> 0x12U)) 
                                              | ((0x1000U 
                                                  & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                     >> 0x13U)) 
                                                 | ((0x800U 
                                                     & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                        >> 0x14U)) 
                                                    | ((0x400U 
                                                        & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                           >> 0x15U)) 
                                                       | ((0x200U 
                                                           & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                              >> 0x16U)) 
                                                          | ((0x100U 
                                                              & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                 >> 0x17U)) 
                                                             | (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo)))))))))),16);
            tracep->chgIData(oldp+154,(((0x80000000U 
                                         & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U]) 
                                        | ((0x40000000U 
                                            & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                               >> 1U)) 
                                           | ((0x20000000U 
                                               & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                  >> 2U)) 
                                              | ((0x10000000U 
                                                  & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                     >> 3U)) 
                                                 | ((0x8000000U 
                                                     & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                        >> 4U)) 
                                                    | ((0x4000000U 
                                                        & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                           >> 5U)) 
                                                       | ((0x2000000U 
                                                           & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                              >> 6U)) 
                                                          | ((0x1000000U 
                                                              & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                 >> 7U)) 
                                                             | (((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo) 
                                                                 << 0x10U) 
                                                                | ((0x8000U 
                                                                    & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                       >> 0x10U)) 
                                                                   | ((0x4000U 
                                                                       & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                          >> 0x11U)) 
                                                                      | ((0x2000U 
                                                                          & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                             >> 0x12U)) 
                                                                         | ((0x1000U 
                                                                             & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                                >> 0x13U)) 
                                                                            | ((0x800U 
                                                                                & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                                >> 0x14U)) 
                                                                               | ((0x400U 
                                                                                & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                                >> 0x15U)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                                >> 0x16U)) 
                                                                                | ((0x100U 
                                                                                & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                                >> 0x17U)) 
                                                                                | (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo))))))))))))))))))),32);
            tracep->chgSData(oldp+155,((0xffffU & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U])),16);
            tracep->chgCData(oldp+156,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_1),6);
            tracep->chgSData(oldp+157,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_1),12);
            tracep->chgIData(oldp+158,(((0x800000U 
                                         & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                            << 8U)) 
                                        | ((0x400000U 
                                            & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                               << 7U)) 
                                           | ((0x200000U 
                                               & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                  << 6U)) 
                                              | ((0x100000U 
                                                  & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                     << 5U)) 
                                                 | ((0x80000U 
                                                     & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                        << 4U)) 
                                                    | ((0x40000U 
                                                        & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                           << 3U)) 
                                                       | (((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_1) 
                                                           << 0xcU) 
                                                          | (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_1))))))))),24);
            tracep->chgCData(oldp+159,((0xffU & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U])),8);
            tracep->chgCData(oldp+160,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2),7);
            tracep->chgSData(oldp+161,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_2),14);
            tracep->chgIData(oldp+162,(((0x8000000U 
                                         & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                            << 0x14U)) 
                                        | ((0x4000000U 
                                            & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                               << 0x13U)) 
                                           | ((0x2000000U 
                                               & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                  << 0x12U)) 
                                              | ((0x1000000U 
                                                  & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                     << 0x11U)) 
                                                 | ((0x800000U 
                                                     & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                        << 0x10U)) 
                                                    | ((0x400000U 
                                                        & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                           << 0xfU)) 
                                                       | ((0x200000U 
                                                           & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                              << 0xeU)) 
                                                          | (((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2) 
                                                              << 0xeU) 
                                                             | (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_2)))))))))),28);
            tracep->chgQData(oldp+163,((((QData)((IData)(
                                                         (1U 
                                                          & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                             >> 7U)))) 
                                         << 0x37U) 
                                        | (((QData)((IData)(
                                                            (1U 
                                                             & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                >> 7U)))) 
                                            << 0x36U) 
                                           | (((QData)((IData)(
                                                               (1U 
                                                                & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                   >> 7U)))) 
                                               << 0x35U) 
                                              | (((QData)((IData)(
                                                                  (1U 
                                                                   & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                      >> 7U)))) 
                                                  << 0x34U) 
                                                 | (((QData)((IData)(
                                                                     (1U 
                                                                      & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                         >> 7U)))) 
                                                     << 0x33U) 
                                                    | (((QData)((IData)(
                                                                        (1U 
                                                                         & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                            >> 7U)))) 
                                                        << 0x32U) 
                                                       | (((QData)((IData)(
                                                                           (1U 
                                                                            & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                               >> 7U)))) 
                                                           << 0x31U) 
                                                          | (((QData)((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2)) 
                                                              << 0x2aU) 
                                                             | (((QData)((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_2)) 
                                                                 << 0x1cU) 
                                                                | (QData)((IData)(
                                                                                ((0x8000000U 
                                                                                & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                                << 0x14U)) 
                                                                                | ((0x4000000U 
                                                                                & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                                << 0x13U)) 
                                                                                | ((0x2000000U 
                                                                                & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                                << 0x12U)) 
                                                                                | ((0x1000000U 
                                                                                & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                                << 0x11U)) 
                                                                                | ((0x800000U 
                                                                                & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                                << 0x10U)) 
                                                                                | ((0x400000U 
                                                                                & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                                << 0xfU)) 
                                                                                | ((0x200000U 
                                                                                & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U] 
                                                                                << 0xeU)) 
                                                                                | (((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2) 
                                                                                << 0xeU) 
                                                                                | (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_2))))))))))))))))))))),56);
        }
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
            tracep->chgQData(oldp+165,(vlSelf->RVNoob__DOT__rf__DOT__rf_10),64);
            tracep->chgQData(oldp+167,(vlSelf->RVNoob__DOT__pc),64);
            tracep->chgQData(oldp+169,((4ULL + vlSelf->RVNoob__DOT__pc)),64);
            tracep->chgBit(oldp+171,(vlSelf->RVNoob__DOT__U_ebreak_ebreak));
            tracep->chgQData(oldp+172,(vlSelf->RVNoob__DOT__rf__DOT__rf_1),64);
            tracep->chgQData(oldp+174,(vlSelf->RVNoob__DOT__rf__DOT__rf_2),64);
            tracep->chgQData(oldp+176,(vlSelf->RVNoob__DOT__rf__DOT__rf_3),64);
            tracep->chgQData(oldp+178,(vlSelf->RVNoob__DOT__rf__DOT__rf_4),64);
            tracep->chgQData(oldp+180,(vlSelf->RVNoob__DOT__rf__DOT__rf_5),64);
            tracep->chgQData(oldp+182,(vlSelf->RVNoob__DOT__rf__DOT__rf_6),64);
            tracep->chgQData(oldp+184,(vlSelf->RVNoob__DOT__rf__DOT__rf_7),64);
            tracep->chgQData(oldp+186,(vlSelf->RVNoob__DOT__rf__DOT__rf_8),64);
            tracep->chgQData(oldp+188,(vlSelf->RVNoob__DOT__rf__DOT__rf_9),64);
            tracep->chgQData(oldp+190,(vlSelf->RVNoob__DOT__rf__DOT__rf_11),64);
            tracep->chgQData(oldp+192,(vlSelf->RVNoob__DOT__rf__DOT__rf_12),64);
            tracep->chgQData(oldp+194,(vlSelf->RVNoob__DOT__rf__DOT__rf_13),64);
            tracep->chgQData(oldp+196,(vlSelf->RVNoob__DOT__rf__DOT__rf_14),64);
            tracep->chgQData(oldp+198,(vlSelf->RVNoob__DOT__rf__DOT__rf_15),64);
            tracep->chgQData(oldp+200,(vlSelf->RVNoob__DOT__rf__DOT__rf_16),64);
            tracep->chgQData(oldp+202,(vlSelf->RVNoob__DOT__rf__DOT__rf_17),64);
            tracep->chgQData(oldp+204,(vlSelf->RVNoob__DOT__rf__DOT__rf_18),64);
            tracep->chgQData(oldp+206,(vlSelf->RVNoob__DOT__rf__DOT__rf_19),64);
            tracep->chgQData(oldp+208,(vlSelf->RVNoob__DOT__rf__DOT__rf_20),64);
            tracep->chgQData(oldp+210,(vlSelf->RVNoob__DOT__rf__DOT__rf_21),64);
            tracep->chgQData(oldp+212,(vlSelf->RVNoob__DOT__rf__DOT__rf_22),64);
            tracep->chgQData(oldp+214,(vlSelf->RVNoob__DOT__rf__DOT__rf_23),64);
            tracep->chgQData(oldp+216,(vlSelf->RVNoob__DOT__rf__DOT__rf_24),64);
            tracep->chgQData(oldp+218,(vlSelf->RVNoob__DOT__rf__DOT__rf_25),64);
            tracep->chgQData(oldp+220,(vlSelf->RVNoob__DOT__rf__DOT__rf_26),64);
            tracep->chgQData(oldp+222,(vlSelf->RVNoob__DOT__rf__DOT__rf_27),64);
            tracep->chgQData(oldp+224,(vlSelf->RVNoob__DOT__rf__DOT__rf_28),64);
            tracep->chgQData(oldp+226,(vlSelf->RVNoob__DOT__rf__DOT__rf_29),64);
            tracep->chgQData(oldp+228,(vlSelf->RVNoob__DOT__rf__DOT__rf_30),64);
            tracep->chgQData(oldp+230,(vlSelf->RVNoob__DOT__rf__DOT__rf_31),64);
            tracep->chgQData(oldp+232,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0]),64);
            tracep->chgQData(oldp+234,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[1]),64);
            tracep->chgQData(oldp+236,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[2]),64);
            tracep->chgQData(oldp+238,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[3]),64);
            tracep->chgQData(oldp+240,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[4]),64);
            tracep->chgQData(oldp+242,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[5]),64);
            tracep->chgQData(oldp+244,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[6]),64);
            tracep->chgQData(oldp+246,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[7]),64);
            tracep->chgQData(oldp+248,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[8]),64);
            tracep->chgQData(oldp+250,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[9]),64);
            tracep->chgQData(oldp+252,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[10]),64);
            tracep->chgQData(oldp+254,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[11]),64);
            tracep->chgQData(oldp+256,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[12]),64);
            tracep->chgQData(oldp+258,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[13]),64);
            tracep->chgQData(oldp+260,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[14]),64);
            tracep->chgQData(oldp+262,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[15]),64);
            tracep->chgQData(oldp+264,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[16]),64);
            tracep->chgQData(oldp+266,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[17]),64);
            tracep->chgQData(oldp+268,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[18]),64);
            tracep->chgQData(oldp+270,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[19]),64);
            tracep->chgQData(oldp+272,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[20]),64);
            tracep->chgQData(oldp+274,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[21]),64);
            tracep->chgQData(oldp+276,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[22]),64);
            tracep->chgQData(oldp+278,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[23]),64);
            tracep->chgQData(oldp+280,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[24]),64);
            tracep->chgQData(oldp+282,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[25]),64);
            tracep->chgQData(oldp+284,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[26]),64);
            tracep->chgQData(oldp+286,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[27]),64);
            tracep->chgQData(oldp+288,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[28]),64);
            tracep->chgQData(oldp+290,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[29]),64);
            tracep->chgQData(oldp+292,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[30]),64);
            tracep->chgQData(oldp+294,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[31]),64);
        }
        tracep->chgBit(oldp+296,(vlSelf->clock));
        tracep->chgBit(oldp+297,(vlSelf->reset));
        tracep->chgQData(oldp+298,(vlSelf->io_pc),64);
        tracep->chgIData(oldp+300,(vlSelf->io_inst),32);
        tracep->chgQData(oldp+301,(vlSelf->io_res),64);
        tracep->chgBit(oldp+303,(vlSelf->io_ebreak));
        tracep->chgCData(oldp+304,((0x1fU & (vlSelf->io_inst 
                                             >> 7U))),5);
        tracep->chgCData(oldp+305,((0x1fU & (vlSelf->io_inst 
                                             >> 0xfU))),5);
        tracep->chgCData(oldp+306,((0x1fU & (vlSelf->io_inst 
                                             >> 0x14U))),5);
        tracep->chgBit(oldp+307,(((0x37U == (0x7fU 
                                             & vlSelf->io_inst)) 
                                  | (0x17U == (0x7fU 
                                               & vlSelf->io_inst)))));
        tracep->chgBit(oldp+308,((((0x37U == (0x7fU 
                                              & vlSelf->io_inst)) 
                                   | (0x6fU == (0x7fU 
                                                & vlSelf->io_inst))) 
                                  | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))));
        tracep->chgBit(oldp+309,((0x37U == (0x7fU & vlSelf->io_inst))));
        tracep->chgQData(oldp+310,(((1U & ((IData)(vlSelf->RVNoob__DOT__idu_io_pc_mux) 
                                           | ((1U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                               ? (0ULL 
                                                  == 
                                                  (((QData)((IData)(
                                                                    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U]))))
                                               : ((2U 
                                                   == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                   ? 
                                                  (0ULL 
                                                   != 
                                                   (((QData)((IData)(
                                                                     vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U]))))
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                    ? 
                                                   vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[2U]
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op)) 
                                                    & ((~ 
                                                        vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[2U]) 
                                                       | (0ULL 
                                                          == 
                                                          (((QData)((IData)(
                                                                            vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[1U])) 
                                                            << 0x20U) 
                                                           | (QData)((IData)(
                                                                             vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_alu_res[0U])))))))))))
                                     ? ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr)
                                         ? (0xfffffffffffffffeULL 
                                            & vlSelf->RVNoob__DOT__npc_add_res)
                                         : vlSelf->RVNoob__DOT__npc_add_res)
                                     : (4ULL + vlSelf->RVNoob__DOT__pc))),64);
        tracep->chgCData(oldp+312,((0x7fU & vlSelf->io_inst)),7);
        tracep->chgCData(oldp+313,((7U & (vlSelf->io_inst 
                                          >> 0xcU))),3);
        tracep->chgCData(oldp+314,((vlSelf->io_inst 
                                    >> 0x19U)),7);
        tracep->chgBit(oldp+315,((0x17U == (0x7fU & vlSelf->io_inst))));
        tracep->chgBit(oldp+316,((0x6fU == (0x7fU & vlSelf->io_inst))));
        tracep->chgIData(oldp+317,(((0x2000000U & (vlSelf->io_inst 
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
        tracep->chgQData(oldp+318,((((QData)((IData)(
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
        tracep->chgQData(oldp+320,((((QData)((IData)(
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
        tracep->chgSData(oldp+322,(((0x8000U & (vlSelf->io_inst 
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
        tracep->chgIData(oldp+323,(((0x80000000U & vlSelf->io_inst) 
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
        tracep->chgQData(oldp+324,((((QData)((IData)(
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
        tracep->chgIData(oldp+326,(((0x2000000U & (vlSelf->io_inst 
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
                                                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo)))))))))),26);
        tracep->chgQData(oldp+327,((((QData)((IData)(
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
                                                                 | (((QData)((IData)(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo_lo)) 
                                                                     << 0x27U) 
                                                                    | (((QData)((IData)(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo)) 
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
                                                                                | (((IData)(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo_lo) 
                                                                                << 0xdU) 
                                                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo))))))))))))))))))))),52);
        tracep->chgQData(oldp+329,(((((QData)((IData)(
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
                                                             >> 7U))))))),64);
        tracep->chgSData(oldp+331,(((0x200U & (vlSelf->io_inst 
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
        tracep->chgSData(oldp+332,(((0x400U & (vlSelf->io_inst 
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
        tracep->chgIData(oldp+333,(((0x100000U & (vlSelf->io_inst 
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
        tracep->chgCData(oldp+334,((0xffU & (vlSelf->io_inst 
                                             >> 0xcU))),8);
        tracep->chgBit(oldp+335,((1U & (vlSelf->io_inst 
                                        >> 0x14U))));
        tracep->chgSData(oldp+336,((0x3ffU & (vlSelf->io_inst 
                                              >> 0x15U))),10);
        tracep->chgQData(oldp+337,(((vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1 
                                     << 0x14U) | (QData)((IData)(
                                                                 ((0xff000U 
                                                                   & vlSelf->io_inst) 
                                                                  | ((0x800U 
                                                                      & (vlSelf->io_inst 
                                                                         >> 9U)) 
                                                                     | (0x7feU 
                                                                        & (vlSelf->io_inst 
                                                                           >> 0x14U)))))))),64);
        tracep->chgSData(oldp+339,(((0x800U & (vlSelf->io_inst 
                                               >> 0x14U)) 
                                    | ((0x400U & (vlSelf->io_inst 
                                                  >> 0x15U)) 
                                       | ((0x200U & 
                                           (vlSelf->io_inst 
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
                                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo)))))))),12);
        tracep->chgSData(oldp+340,(((0x1000U & (vlSelf->io_inst 
                                                >> 0x13U)) 
                                    | ((0x800U & (vlSelf->io_inst 
                                                  >> 0x14U)) 
                                       | ((0x400U & 
                                           (vlSelf->io_inst 
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
                                                      | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo))))))))),13);
        tracep->chgIData(oldp+341,(((0x1000000U & (vlSelf->io_inst 
                                                   >> 7U)) 
                                    | ((0x800000U & 
                                        (vlSelf->io_inst 
                                         >> 8U)) | 
                                       ((0x400000U 
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
                                                                         | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo)))))))))))))))),25);
        tracep->chgBit(oldp+342,((1U & (vlSelf->io_inst 
                                        >> 7U))));
        tracep->chgCData(oldp+343,((0x3fU & (vlSelf->io_inst 
                                             >> 0x19U))),6);
        tracep->chgCData(oldp+344,((0xfU & (vlSelf->io_inst 
                                            >> 8U))),4);
        tracep->chgQData(oldp+345,(((vlSelf->RVNoob__DOT__idu__DOT__immB_hi_hi_hi_1 
                                     << 0xdU) | (QData)((IData)(
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
                                                                             >> 7U))))))))),64);
        tracep->chgQData(oldp+347,(((0x1fU == (0x1fU 
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
        tracep->chgQData(oldp+349,(((0x1fU == (0x1fU 
                                               & (vlSelf->io_inst 
                                                  >> 0x14U)))
                                     ? vlSelf->RVNoob__DOT__rf__DOT__rf_31
                                     : ((0x1eU == (0x1fU 
                                                   & (vlSelf->io_inst 
                                                      >> 0x14U)))
                                         ? vlSelf->RVNoob__DOT__rf__DOT__rf_30
                                         : ((0x1dU 
                                             == (0x1fU 
                                                 & (vlSelf->io_inst 
                                                    >> 0x14U)))
                                             ? vlSelf->RVNoob__DOT__rf__DOT__rf_29
                                             : ((0x1cU 
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
                                                  : vlSelf->RVNoob__DOT__rf__DOT___GEN_89)))))),64);
        tracep->chgQData(oldp+351,(((0x37U == (0x7fU 
                                               & vlSelf->io_inst))
                                     ? vlSelf->RVNoob__DOT__idu_io_imm
                                     : (4ULL + vlSelf->RVNoob__DOT__pc))),64);
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
