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
        tracep->declBit(c+299,"clock", false,-1);
        tracep->declBit(c+300,"reset", false,-1);
        tracep->declQuad(c+301,"io_pc", false,-1, 63,0);
        tracep->declBus(c+303,"io_inst", false,-1, 31,0);
        tracep->declQuad(c+304,"io_res", false,-1, 63,0);
        tracep->declBit(c+306,"io_ebreak", false,-1);
        tracep->declBit(c+299,"RVNoob clock", false,-1);
        tracep->declBit(c+300,"RVNoob reset", false,-1);
        tracep->declQuad(c+301,"RVNoob io_pc", false,-1, 63,0);
        tracep->declBus(c+303,"RVNoob io_inst", false,-1, 31,0);
        tracep->declQuad(c+304,"RVNoob io_res", false,-1, 63,0);
        tracep->declBit(c+306,"RVNoob io_ebreak", false,-1);
        tracep->declBit(c+299,"RVNoob ifm_clock", false,-1);
        tracep->declBit(c+300,"RVNoob ifm_reset", false,-1);
        tracep->declQuad(c+1,"RVNoob ifm_io_data_addr", false,-1, 63,0);
        tracep->declQuad(c+3,"RVNoob ifm_io_wdata", false,-1, 63,0);
        tracep->declQuad(c+5,"RVNoob ifm_io_rdata", false,-1, 63,0);
        tracep->declBus(c+7,"RVNoob ifm_io_pmem_ctrl_zero_ex_op", false,-1, 1,0);
        tracep->declBit(c+8,"RVNoob ifm_io_pmem_ctrl_r_pmem", false,-1);
        tracep->declBit(c+9,"RVNoob ifm_io_pmem_ctrl_w_pmem", false,-1);
        tracep->declBus(c+303,"RVNoob idu_io_inst", false,-1, 31,0);
        tracep->declQuad(c+10,"RVNoob idu_io_imm", false,-1, 63,0);
        tracep->declBit(c+12,"RVNoob idu_io_wen", false,-1);
        tracep->declBus(c+307,"RVNoob idu_io_rd", false,-1, 4,0);
        tracep->declBit(c+13,"RVNoob idu_io_ren1", false,-1);
        tracep->declBit(c+14,"RVNoob idu_io_ren2", false,-1);
        tracep->declBus(c+308,"RVNoob idu_io_rs1", false,-1, 4,0);
        tracep->declBus(c+309,"RVNoob idu_io_rs2", false,-1, 4,0);
        tracep->declBit(c+15,"RVNoob idu_io_exe_ctrl_judge_mux", false,-1);
        tracep->declBus(c+16,"RVNoob idu_io_exe_ctrl_judge_op", false,-1, 3,0);
        tracep->declBus(c+17,"RVNoob idu_io_exe_ctrl_alu_op", false,-1, 4,0);
        tracep->declBit(c+8,"RVNoob idu_io_exe_ctrl_old_val_mux", false,-1);
        tracep->declBit(c+310,"RVNoob idu_io_exe_ctrl_alu_src1_mux", false,-1);
        tracep->declBit(c+18,"RVNoob idu_io_exe_ctrl_alu_src2_mux", false,-1);
        tracep->declBit(c+311,"RVNoob idu_io_exe_ctrl_exe_out_mux", false,-1);
        tracep->declBit(c+312,"RVNoob idu_io_exe_ctrl_dir_out_mux", false,-1);
        tracep->declBus(c+7,"RVNoob idu_io_pmem_ctrl_zero_ex_op", false,-1, 1,0);
        tracep->declBit(c+8,"RVNoob idu_io_pmem_ctrl_r_pmem", false,-1);
        tracep->declBit(c+9,"RVNoob idu_io_pmem_ctrl_w_pmem", false,-1);
        tracep->declBit(c+19,"RVNoob idu_io_dnpc_jalr", false,-1);
        tracep->declBit(c+20,"RVNoob idu_io_pc_mux", false,-1);
        tracep->declBit(c+299,"RVNoob rf_clock", false,-1);
        tracep->declBit(c+300,"RVNoob rf_reset", false,-1);
        tracep->declBit(c+12,"RVNoob rf_io_wen", false,-1);
        tracep->declQuad(c+21,"RVNoob rf_io_wdata", false,-1, 63,0);
        tracep->declBus(c+307,"RVNoob rf_io_waddr", false,-1, 4,0);
        tracep->declBit(c+13,"RVNoob rf_io_ren1", false,-1);
        tracep->declBit(c+14,"RVNoob rf_io_ren2", false,-1);
        tracep->declQuad(c+23,"RVNoob rf_io_rdata1", false,-1, 63,0);
        tracep->declQuad(c+3,"RVNoob rf_io_rdata2", false,-1, 63,0);
        tracep->declBus(c+308,"RVNoob rf_io_raddr1", false,-1, 4,0);
        tracep->declBus(c+309,"RVNoob rf_io_raddr2", false,-1, 4,0);
        tracep->declQuad(c+168,"RVNoob rf_io_a0", false,-1, 63,0);
        tracep->declQuad(c+23,"RVNoob exe_io_src1", false,-1, 63,0);
        tracep->declQuad(c+3,"RVNoob exe_io_src2", false,-1, 63,0);
        tracep->declQuad(c+10,"RVNoob exe_io_imm", false,-1, 63,0);
        tracep->declQuad(c+5,"RVNoob exe_io_mem_data", false,-1, 63,0);
        tracep->declQuad(c+1,"RVNoob exe_io_mem_addr", false,-1, 63,0);
        tracep->declQuad(c+170,"RVNoob exe_io_pc", false,-1, 63,0);
        tracep->declQuad(c+172,"RVNoob exe_io_snpc", false,-1, 63,0);
        tracep->declQuad(c+21,"RVNoob exe_io_gp_out", false,-1, 63,0);
        tracep->declBit(c+15,"RVNoob exe_io_ctrl_judge_mux", false,-1);
        tracep->declBus(c+16,"RVNoob exe_io_ctrl_judge_op", false,-1, 3,0);
        tracep->declBus(c+17,"RVNoob exe_io_ctrl_alu_op", false,-1, 4,0);
        tracep->declBit(c+8,"RVNoob exe_io_ctrl_old_val_mux", false,-1);
        tracep->declBit(c+310,"RVNoob exe_io_ctrl_alu_src1_mux", false,-1);
        tracep->declBit(c+18,"RVNoob exe_io_ctrl_alu_src2_mux", false,-1);
        tracep->declBit(c+311,"RVNoob exe_io_ctrl_exe_out_mux", false,-1);
        tracep->declBit(c+312,"RVNoob exe_io_ctrl_dir_out_mux", false,-1);
        tracep->declBit(c+25,"RVNoob exe_io_B_en", false,-1);
        tracep->declQuad(c+313,"RVNoob dpi_npc_npc", false,-1, 63,0);
        tracep->declBit(c+299,"RVNoob U_ebreak_clk", false,-1);
        tracep->declBus(c+303,"RVNoob U_ebreak_inst", false,-1, 31,0);
        tracep->declQuad(c+168,"RVNoob U_ebreak_a0", false,-1, 63,0);
        tracep->declBit(c+174,"RVNoob U_ebreak_ebreak", false,-1);
        tracep->declQuad(c+170,"RVNoob pc", false,-1, 63,0);
        tracep->declQuad(c+26,"RVNoob npc_add_res", false,-1, 63,0);
        tracep->declQuad(c+172,"RVNoob snpc", false,-1, 63,0);
        tracep->declQuad(c+28,"RVNoob dnpc_hi", false,-1, 62,0);
        tracep->declQuad(c+30,"RVNoob dnpc", false,-1, 63,0);
        tracep->declBit(c+299,"RVNoob ifm clock", false,-1);
        tracep->declBit(c+300,"RVNoob ifm reset", false,-1);
        tracep->declQuad(c+1,"RVNoob ifm io_data_addr", false,-1, 63,0);
        tracep->declQuad(c+3,"RVNoob ifm io_wdata", false,-1, 63,0);
        tracep->declQuad(c+5,"RVNoob ifm io_rdata", false,-1, 63,0);
        tracep->declBus(c+7,"RVNoob ifm io_pmem_ctrl_zero_ex_op", false,-1, 1,0);
        tracep->declBit(c+8,"RVNoob ifm io_pmem_ctrl_r_pmem", false,-1);
        tracep->declBit(c+9,"RVNoob ifm io_pmem_ctrl_w_pmem", false,-1);
        tracep->declQuad(c+356,"RVNoob ifm dpi_pmem_raddr", false,-1, 63,0);
        tracep->declQuad(c+356,"RVNoob ifm dpi_pmem_waddr", false,-1, 63,0);
        tracep->declBus(c+32,"RVNoob ifm dpi_pmem_wmask", false,-1, 7,0);
        tracep->declQuad(c+33,"RVNoob ifm dpi_pmem_rdata", false,-1, 63,0);
        tracep->declQuad(c+35,"RVNoob ifm dpi_pmem_wdata", false,-1, 63,0);
        tracep->declBit(c+8,"RVNoob ifm dpi_pmem_r_pmem", false,-1);
        tracep->declBit(c+9,"RVNoob ifm dpi_pmem_w_pmem", false,-1);
        tracep->declBus(c+37,"RVNoob ifm shift", false,-1, 2,0);
        tracep->declQuad(c+33,"RVNoob ifm rdata", false,-1, 63,0);
        tracep->declQuad(c+356,"RVNoob ifm dpi_pmem raddr", false,-1, 63,0);
        tracep->declQuad(c+356,"RVNoob ifm dpi_pmem waddr", false,-1, 63,0);
        tracep->declBus(c+32,"RVNoob ifm dpi_pmem wmask", false,-1, 7,0);
        tracep->declQuad(c+33,"RVNoob ifm dpi_pmem rdata", false,-1, 63,0);
        tracep->declQuad(c+35,"RVNoob ifm dpi_pmem wdata", false,-1, 63,0);
        tracep->declBit(c+8,"RVNoob ifm dpi_pmem r_pmem", false,-1);
        tracep->declBit(c+9,"RVNoob ifm dpi_pmem w_pmem", false,-1);
        tracep->declQuad(c+33,"RVNoob ifm dpi_pmem rdata_t", false,-1, 63,0);
        tracep->declBus(c+303,"RVNoob idu io_inst", false,-1, 31,0);
        tracep->declQuad(c+10,"RVNoob idu io_imm", false,-1, 63,0);
        tracep->declBit(c+12,"RVNoob idu io_wen", false,-1);
        tracep->declBus(c+307,"RVNoob idu io_rd", false,-1, 4,0);
        tracep->declBit(c+13,"RVNoob idu io_ren1", false,-1);
        tracep->declBit(c+14,"RVNoob idu io_ren2", false,-1);
        tracep->declBus(c+308,"RVNoob idu io_rs1", false,-1, 4,0);
        tracep->declBus(c+309,"RVNoob idu io_rs2", false,-1, 4,0);
        tracep->declBit(c+15,"RVNoob idu io_exe_ctrl_judge_mux", false,-1);
        tracep->declBus(c+16,"RVNoob idu io_exe_ctrl_judge_op", false,-1, 3,0);
        tracep->declBus(c+17,"RVNoob idu io_exe_ctrl_alu_op", false,-1, 4,0);
        tracep->declBit(c+8,"RVNoob idu io_exe_ctrl_old_val_mux", false,-1);
        tracep->declBit(c+310,"RVNoob idu io_exe_ctrl_alu_src1_mux", false,-1);
        tracep->declBit(c+18,"RVNoob idu io_exe_ctrl_alu_src2_mux", false,-1);
        tracep->declBit(c+311,"RVNoob idu io_exe_ctrl_exe_out_mux", false,-1);
        tracep->declBit(c+312,"RVNoob idu io_exe_ctrl_dir_out_mux", false,-1);
        tracep->declBus(c+7,"RVNoob idu io_pmem_ctrl_zero_ex_op", false,-1, 1,0);
        tracep->declBit(c+8,"RVNoob idu io_pmem_ctrl_r_pmem", false,-1);
        tracep->declBit(c+9,"RVNoob idu io_pmem_ctrl_w_pmem", false,-1);
        tracep->declBit(c+19,"RVNoob idu io_dnpc_jalr", false,-1);
        tracep->declBit(c+20,"RVNoob idu io_pc_mux", false,-1);
        tracep->declBus(c+303,"RVNoob idu dpi_inst_inst", false,-1, 31,0);
        tracep->declBus(c+315,"RVNoob idu opcode", false,-1, 6,0);
        tracep->declBus(c+316,"RVNoob idu fun3", false,-1, 2,0);
        tracep->declBus(c+317,"RVNoob idu fun7", false,-1, 6,0);
        tracep->declBit(c+312,"RVNoob idu rvi_lui", false,-1);
        tracep->declBit(c+318,"RVNoob idu rvi_auipc", false,-1);
        tracep->declBit(c+319,"RVNoob idu rvi_jal", false,-1);
        tracep->declBit(c+19,"RVNoob idu rvi_jalr", false,-1);
        tracep->declBit(c+38,"RVNoob idu rvi_beq", false,-1);
        tracep->declBit(c+39,"RVNoob idu rvi_bne", false,-1);
        tracep->declBit(c+40,"RVNoob idu rvi_blt", false,-1);
        tracep->declBit(c+41,"RVNoob idu rvi_bge", false,-1);
        tracep->declBit(c+42,"RVNoob idu rvi_bltu", false,-1);
        tracep->declBit(c+43,"RVNoob idu rvi_bgeu", false,-1);
        tracep->declBit(c+44,"RVNoob idu jpg_sexb", false,-1);
        tracep->declBit(c+45,"RVNoob idu jpg_sexthw", false,-1);
        tracep->declBit(c+46,"RVNoob idu rvi_lw", false,-1);
        tracep->declBit(c+47,"RVNoob idu jpg_uextb", false,-1);
        tracep->declBit(c+48,"RVNoob idu jpg_uexthw", false,-1);
        tracep->declBit(c+49,"RVNoob idu rvi_sb", false,-1);
        tracep->declBit(c+50,"RVNoob idu rvi_sh", false,-1);
        tracep->declBit(c+51,"RVNoob idu rvi_sw", false,-1);
        tracep->declBit(c+52,"RVNoob idu rvi_addi", false,-1);
        tracep->declBit(c+53,"RVNoob idu rvi_slti", false,-1);
        tracep->declBit(c+54,"RVNoob idu rvi_sltiu", false,-1);
        tracep->declBit(c+55,"RVNoob idu rvi_xori", false,-1);
        tracep->declBit(c+56,"RVNoob idu rvi_ori", false,-1);
        tracep->declBit(c+57,"RVNoob idu rvi_andi", false,-1);
        tracep->declBit(c+58,"RVNoob idu rvi_add", false,-1);
        tracep->declBit(c+59,"RVNoob idu rvi_sub", false,-1);
        tracep->declBit(c+60,"RVNoob idu rvi_sll", false,-1);
        tracep->declBit(c+61,"RVNoob idu rvi_slt", false,-1);
        tracep->declBit(c+62,"RVNoob idu rvi_sltu", false,-1);
        tracep->declBit(c+63,"RVNoob idu rvi_xor", false,-1);
        tracep->declBit(c+64,"RVNoob idu rvi_srl", false,-1);
        tracep->declBit(c+65,"RVNoob idu rvi_sra", false,-1);
        tracep->declBit(c+66,"RVNoob idu rvi_or", false,-1);
        tracep->declBit(c+67,"RVNoob idu rvi_and", false,-1);
        tracep->declBit(c+68,"RVNoob idu jpg_uextw", false,-1);
        tracep->declBit(c+69,"RVNoob idu rvi_ld", false,-1);
        tracep->declBit(c+70,"RVNoob idu rvi_sd", false,-1);
        tracep->declBit(c+71,"RVNoob idu rvi_slli", false,-1);
        tracep->declBit(c+72,"RVNoob idu rvi_srli", false,-1);
        tracep->declBit(c+73,"RVNoob idu rvi_srai", false,-1);
        tracep->declBit(c+74,"RVNoob idu rvi_addiw", false,-1);
        tracep->declBit(c+75,"RVNoob idu rvi_slliw", false,-1);
        tracep->declBit(c+76,"RVNoob idu rvi_srliw", false,-1);
        tracep->declBit(c+77,"RVNoob idu rvi_sraiw", false,-1);
        tracep->declBit(c+78,"RVNoob idu rvi_addw", false,-1);
        tracep->declBit(c+79,"RVNoob idu rvi_subw", false,-1);
        tracep->declBit(c+80,"RVNoob idu rvi_sllw", false,-1);
        tracep->declBit(c+81,"RVNoob idu rvi_srlw", false,-1);
        tracep->declBit(c+82,"RVNoob idu rvi_sraw", false,-1);
        tracep->declBit(c+83,"RVNoob idu rvm_mul", false,-1);
        tracep->declBit(c+84,"RVNoob idu rvm_mulh", false,-1);
        tracep->declBit(c+85,"RVNoob idu rvm_mulhsu", false,-1);
        tracep->declBit(c+86,"RVNoob idu rvm_mulhu", false,-1);
        tracep->declBit(c+87,"RVNoob idu rvm_div", false,-1);
        tracep->declBit(c+88,"RVNoob idu rvm_divu", false,-1);
        tracep->declBit(c+89,"RVNoob idu rvm_rem", false,-1);
        tracep->declBit(c+90,"RVNoob idu rvm_remu", false,-1);
        tracep->declBit(c+91,"RVNoob idu rvm_mulw", false,-1);
        tracep->declBit(c+92,"RVNoob idu rvm_divw", false,-1);
        tracep->declBit(c+93,"RVNoob idu rvm_remw", false,-1);
        tracep->declBit(c+94,"RVNoob idu type_I", false,-1);
        tracep->declBit(c+95,"RVNoob idu type_U", false,-1);
        tracep->declBit(c+9,"RVNoob idu type_S", false,-1);
        tracep->declBit(c+96,"RVNoob idu type_R", false,-1);
        tracep->declBit(c+97,"RVNoob idu type_B", false,-1);
        tracep->declBus(c+98,"RVNoob idu immI_lo_lo_lo", false,-1, 5,0);
        tracep->declBus(c+99,"RVNoob idu immI_lo_lo", false,-1, 12,0);
        tracep->declBus(c+320,"RVNoob idu immI_lo", false,-1, 25,0);
        tracep->declQuad(c+321,"RVNoob idu immI_hi_1", false,-1, 51,0);
        tracep->declQuad(c+323,"RVNoob idu immI", false,-1, 63,0);
        tracep->declBus(c+100,"RVNoob idu immU_lo_lo", false,-1, 7,0);
        tracep->declBus(c+325,"RVNoob idu immU_lo", false,-1, 15,0);
        tracep->declBus(c+326,"RVNoob idu immU_hi_hi_1", false,-1, 31,0);
        tracep->declQuad(c+327,"RVNoob idu immU", false,-1, 63,0);
        tracep->declBus(c+101,"RVNoob idu immS_lo_lo_lo", false,-1, 5,0);
        tracep->declBus(c+102,"RVNoob idu immS_lo_lo", false,-1, 12,0);
        tracep->declBus(c+329,"RVNoob idu immS_lo", false,-1, 25,0);
        tracep->declQuad(c+330,"RVNoob idu immS_hi_hi_1", false,-1, 51,0);
        tracep->declQuad(c+332,"RVNoob idu immS", false,-1, 63,0);
        tracep->declBus(c+103,"RVNoob idu immJ_lo_lo_lo", false,-1, 4,0);
        tracep->declBus(c+334,"RVNoob idu immJ_lo_lo", false,-1, 9,0);
        tracep->declBus(c+98,"RVNoob idu immJ_lo_hi_hi", false,-1, 5,0);
        tracep->declBus(c+335,"RVNoob idu immJ_lo_hi", false,-1, 10,0);
        tracep->declBus(c+336,"RVNoob idu immJ_lo", false,-1, 20,0);
        tracep->declBus(c+337,"RVNoob idu immJ_hi_lo_1", false,-1, 7,0);
        tracep->declBit(c+338,"RVNoob idu immJ_lo_hi_hi_1", false,-1);
        tracep->declBus(c+339,"RVNoob idu immJ_lo_hi_lo_1", false,-1, 9,0);
        tracep->declQuad(c+104,"RVNoob idu immJ_hi_hi_1", false,-1, 43,0);
        tracep->declQuad(c+340,"RVNoob idu immJ", false,-1, 63,0);
        tracep->declBus(c+342,"RVNoob idu immB_lo_lo", false,-1, 11,0);
        tracep->declBus(c+343,"RVNoob idu immB_lo_hi", false,-1, 12,0);
        tracep->declBus(c+344,"RVNoob idu immB_lo", false,-1, 24,0);
        tracep->declQuad(c+106,"RVNoob idu immB_hi_hi_hi_1", false,-1, 50,0);
        tracep->declBit(c+345,"RVNoob idu immB_hi_lo_1", false,-1);
        tracep->declBus(c+346,"RVNoob idu immB_lo_hi_hi_1", false,-1, 5,0);
        tracep->declBus(c+347,"RVNoob idu immB_lo_hi_lo_1", false,-1, 3,0);
        tracep->declQuad(c+348,"RVNoob idu immB", false,-1, 63,0);
        tracep->declBit(c+108,"RVNoob idu jpg_slt", false,-1);
        tracep->declBit(c+109,"RVNoob idu jpg_sextw", false,-1);
        tracep->declBus(c+303,"RVNoob idu dpi_inst inst", false,-1, 31,0);
        tracep->declBit(c+299,"RVNoob rf clock", false,-1);
        tracep->declBit(c+300,"RVNoob rf reset", false,-1);
        tracep->declBit(c+12,"RVNoob rf io_wen", false,-1);
        tracep->declQuad(c+21,"RVNoob rf io_wdata", false,-1, 63,0);
        tracep->declBus(c+307,"RVNoob rf io_waddr", false,-1, 4,0);
        tracep->declBit(c+13,"RVNoob rf io_ren1", false,-1);
        tracep->declBit(c+14,"RVNoob rf io_ren2", false,-1);
        tracep->declQuad(c+23,"RVNoob rf io_rdata1", false,-1, 63,0);
        tracep->declQuad(c+3,"RVNoob rf io_rdata2", false,-1, 63,0);
        tracep->declBus(c+308,"RVNoob rf io_raddr1", false,-1, 4,0);
        tracep->declBus(c+309,"RVNoob rf io_raddr2", false,-1, 4,0);
        tracep->declQuad(c+168,"RVNoob rf io_a0", false,-1, 63,0);
        tracep->declQuad(c+356,"RVNoob rf rf_read_rf_0", false,-1, 63,0);
        tracep->declQuad(c+175,"RVNoob rf rf_read_rf_1", false,-1, 63,0);
        tracep->declQuad(c+177,"RVNoob rf rf_read_rf_2", false,-1, 63,0);
        tracep->declQuad(c+179,"RVNoob rf rf_read_rf_3", false,-1, 63,0);
        tracep->declQuad(c+181,"RVNoob rf rf_read_rf_4", false,-1, 63,0);
        tracep->declQuad(c+183,"RVNoob rf rf_read_rf_5", false,-1, 63,0);
        tracep->declQuad(c+185,"RVNoob rf rf_read_rf_6", false,-1, 63,0);
        tracep->declQuad(c+187,"RVNoob rf rf_read_rf_7", false,-1, 63,0);
        tracep->declQuad(c+189,"RVNoob rf rf_read_rf_8", false,-1, 63,0);
        tracep->declQuad(c+191,"RVNoob rf rf_read_rf_9", false,-1, 63,0);
        tracep->declQuad(c+168,"RVNoob rf rf_read_rf_10", false,-1, 63,0);
        tracep->declQuad(c+193,"RVNoob rf rf_read_rf_11", false,-1, 63,0);
        tracep->declQuad(c+195,"RVNoob rf rf_read_rf_12", false,-1, 63,0);
        tracep->declQuad(c+197,"RVNoob rf rf_read_rf_13", false,-1, 63,0);
        tracep->declQuad(c+199,"RVNoob rf rf_read_rf_14", false,-1, 63,0);
        tracep->declQuad(c+201,"RVNoob rf rf_read_rf_15", false,-1, 63,0);
        tracep->declQuad(c+203,"RVNoob rf rf_read_rf_16", false,-1, 63,0);
        tracep->declQuad(c+205,"RVNoob rf rf_read_rf_17", false,-1, 63,0);
        tracep->declQuad(c+207,"RVNoob rf rf_read_rf_18", false,-1, 63,0);
        tracep->declQuad(c+209,"RVNoob rf rf_read_rf_19", false,-1, 63,0);
        tracep->declQuad(c+211,"RVNoob rf rf_read_rf_20", false,-1, 63,0);
        tracep->declQuad(c+213,"RVNoob rf rf_read_rf_21", false,-1, 63,0);
        tracep->declQuad(c+215,"RVNoob rf rf_read_rf_22", false,-1, 63,0);
        tracep->declQuad(c+217,"RVNoob rf rf_read_rf_23", false,-1, 63,0);
        tracep->declQuad(c+219,"RVNoob rf rf_read_rf_24", false,-1, 63,0);
        tracep->declQuad(c+221,"RVNoob rf rf_read_rf_25", false,-1, 63,0);
        tracep->declQuad(c+223,"RVNoob rf rf_read_rf_26", false,-1, 63,0);
        tracep->declQuad(c+225,"RVNoob rf rf_read_rf_27", false,-1, 63,0);
        tracep->declQuad(c+227,"RVNoob rf rf_read_rf_28", false,-1, 63,0);
        tracep->declQuad(c+229,"RVNoob rf rf_read_rf_29", false,-1, 63,0);
        tracep->declQuad(c+231,"RVNoob rf rf_read_rf_30", false,-1, 63,0);
        tracep->declQuad(c+233,"RVNoob rf rf_read_rf_31", false,-1, 63,0);
        tracep->declQuad(c+175,"RVNoob rf rf_1", false,-1, 63,0);
        tracep->declQuad(c+177,"RVNoob rf rf_2", false,-1, 63,0);
        tracep->declQuad(c+179,"RVNoob rf rf_3", false,-1, 63,0);
        tracep->declQuad(c+181,"RVNoob rf rf_4", false,-1, 63,0);
        tracep->declQuad(c+183,"RVNoob rf rf_5", false,-1, 63,0);
        tracep->declQuad(c+185,"RVNoob rf rf_6", false,-1, 63,0);
        tracep->declQuad(c+187,"RVNoob rf rf_7", false,-1, 63,0);
        tracep->declQuad(c+189,"RVNoob rf rf_8", false,-1, 63,0);
        tracep->declQuad(c+191,"RVNoob rf rf_9", false,-1, 63,0);
        tracep->declQuad(c+168,"RVNoob rf rf_10", false,-1, 63,0);
        tracep->declQuad(c+193,"RVNoob rf rf_11", false,-1, 63,0);
        tracep->declQuad(c+195,"RVNoob rf rf_12", false,-1, 63,0);
        tracep->declQuad(c+197,"RVNoob rf rf_13", false,-1, 63,0);
        tracep->declQuad(c+199,"RVNoob rf rf_14", false,-1, 63,0);
        tracep->declQuad(c+201,"RVNoob rf rf_15", false,-1, 63,0);
        tracep->declQuad(c+203,"RVNoob rf rf_16", false,-1, 63,0);
        tracep->declQuad(c+205,"RVNoob rf rf_17", false,-1, 63,0);
        tracep->declQuad(c+207,"RVNoob rf rf_18", false,-1, 63,0);
        tracep->declQuad(c+209,"RVNoob rf rf_19", false,-1, 63,0);
        tracep->declQuad(c+211,"RVNoob rf rf_20", false,-1, 63,0);
        tracep->declQuad(c+213,"RVNoob rf rf_21", false,-1, 63,0);
        tracep->declQuad(c+215,"RVNoob rf rf_22", false,-1, 63,0);
        tracep->declQuad(c+217,"RVNoob rf rf_23", false,-1, 63,0);
        tracep->declQuad(c+219,"RVNoob rf rf_24", false,-1, 63,0);
        tracep->declQuad(c+221,"RVNoob rf rf_25", false,-1, 63,0);
        tracep->declQuad(c+223,"RVNoob rf rf_26", false,-1, 63,0);
        tracep->declQuad(c+225,"RVNoob rf rf_27", false,-1, 63,0);
        tracep->declQuad(c+227,"RVNoob rf rf_28", false,-1, 63,0);
        tracep->declQuad(c+229,"RVNoob rf rf_29", false,-1, 63,0);
        tracep->declQuad(c+231,"RVNoob rf rf_30", false,-1, 63,0);
        tracep->declQuad(c+233,"RVNoob rf rf_31", false,-1, 63,0);
        tracep->declQuad(c+350,"RVNoob rf rdata1", false,-1, 63,0);
        tracep->declQuad(c+352,"RVNoob rf rdata2", false,-1, 63,0);
        tracep->declQuad(c+356,"RVNoob rf rf_read rf_0", false,-1, 63,0);
        tracep->declQuad(c+175,"RVNoob rf rf_read rf_1", false,-1, 63,0);
        tracep->declQuad(c+177,"RVNoob rf rf_read rf_2", false,-1, 63,0);
        tracep->declQuad(c+179,"RVNoob rf rf_read rf_3", false,-1, 63,0);
        tracep->declQuad(c+181,"RVNoob rf rf_read rf_4", false,-1, 63,0);
        tracep->declQuad(c+183,"RVNoob rf rf_read rf_5", false,-1, 63,0);
        tracep->declQuad(c+185,"RVNoob rf rf_read rf_6", false,-1, 63,0);
        tracep->declQuad(c+187,"RVNoob rf rf_read rf_7", false,-1, 63,0);
        tracep->declQuad(c+189,"RVNoob rf rf_read rf_8", false,-1, 63,0);
        tracep->declQuad(c+191,"RVNoob rf rf_read rf_9", false,-1, 63,0);
        tracep->declQuad(c+168,"RVNoob rf rf_read rf_10", false,-1, 63,0);
        tracep->declQuad(c+193,"RVNoob rf rf_read rf_11", false,-1, 63,0);
        tracep->declQuad(c+195,"RVNoob rf rf_read rf_12", false,-1, 63,0);
        tracep->declQuad(c+197,"RVNoob rf rf_read rf_13", false,-1, 63,0);
        tracep->declQuad(c+199,"RVNoob rf rf_read rf_14", false,-1, 63,0);
        tracep->declQuad(c+201,"RVNoob rf rf_read rf_15", false,-1, 63,0);
        tracep->declQuad(c+203,"RVNoob rf rf_read rf_16", false,-1, 63,0);
        tracep->declQuad(c+205,"RVNoob rf rf_read rf_17", false,-1, 63,0);
        tracep->declQuad(c+207,"RVNoob rf rf_read rf_18", false,-1, 63,0);
        tracep->declQuad(c+209,"RVNoob rf rf_read rf_19", false,-1, 63,0);
        tracep->declQuad(c+211,"RVNoob rf rf_read rf_20", false,-1, 63,0);
        tracep->declQuad(c+213,"RVNoob rf rf_read rf_21", false,-1, 63,0);
        tracep->declQuad(c+215,"RVNoob rf rf_read rf_22", false,-1, 63,0);
        tracep->declQuad(c+217,"RVNoob rf rf_read rf_23", false,-1, 63,0);
        tracep->declQuad(c+219,"RVNoob rf rf_read rf_24", false,-1, 63,0);
        tracep->declQuad(c+221,"RVNoob rf rf_read rf_25", false,-1, 63,0);
        tracep->declQuad(c+223,"RVNoob rf rf_read rf_26", false,-1, 63,0);
        tracep->declQuad(c+225,"RVNoob rf rf_read rf_27", false,-1, 63,0);
        tracep->declQuad(c+227,"RVNoob rf rf_read rf_28", false,-1, 63,0);
        tracep->declQuad(c+229,"RVNoob rf rf_read rf_29", false,-1, 63,0);
        tracep->declQuad(c+231,"RVNoob rf rf_read rf_30", false,-1, 63,0);
        tracep->declQuad(c+233,"RVNoob rf rf_read rf_31", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+235+i*2,"RVNoob rf rf_read rf", true,(i+0), 63,0);}}
        tracep->declQuad(c+23,"RVNoob exe io_src1", false,-1, 63,0);
        tracep->declQuad(c+3,"RVNoob exe io_src2", false,-1, 63,0);
        tracep->declQuad(c+10,"RVNoob exe io_imm", false,-1, 63,0);
        tracep->declQuad(c+5,"RVNoob exe io_mem_data", false,-1, 63,0);
        tracep->declQuad(c+1,"RVNoob exe io_mem_addr", false,-1, 63,0);
        tracep->declQuad(c+170,"RVNoob exe io_pc", false,-1, 63,0);
        tracep->declQuad(c+172,"RVNoob exe io_snpc", false,-1, 63,0);
        tracep->declQuad(c+21,"RVNoob exe io_gp_out", false,-1, 63,0);
        tracep->declBit(c+15,"RVNoob exe io_ctrl_judge_mux", false,-1);
        tracep->declBus(c+16,"RVNoob exe io_ctrl_judge_op", false,-1, 3,0);
        tracep->declBus(c+17,"RVNoob exe io_ctrl_alu_op", false,-1, 4,0);
        tracep->declBit(c+8,"RVNoob exe io_ctrl_old_val_mux", false,-1);
        tracep->declBit(c+310,"RVNoob exe io_ctrl_alu_src1_mux", false,-1);
        tracep->declBit(c+18,"RVNoob exe io_ctrl_alu_src2_mux", false,-1);
        tracep->declBit(c+311,"RVNoob exe io_ctrl_exe_out_mux", false,-1);
        tracep->declBit(c+312,"RVNoob exe io_ctrl_dir_out_mux", false,-1);
        tracep->declBit(c+25,"RVNoob exe io_B_en", false,-1);
        tracep->declQuad(c+110,"RVNoob exe alu_io_src1", false,-1, 63,0);
        tracep->declQuad(c+112,"RVNoob exe alu_io_src2", false,-1, 63,0);
        tracep->declBit(c+15,"RVNoob exe alu_io_ctrl_judge_mux", false,-1);
        tracep->declBus(c+16,"RVNoob exe alu_io_ctrl_judge_op", false,-1, 3,0);
        tracep->declBus(c+17,"RVNoob exe alu_io_ctrl_alu_op", false,-1, 4,0);
        tracep->declBit(c+8,"RVNoob exe alu_io_ctrl_old_val_mux", false,-1);
        tracep->declQuad(c+114,"RVNoob exe alu_io_result", false,-1, 63,0);
        tracep->declBit(c+25,"RVNoob exe alu_io_B_en", false,-1);
        tracep->declQuad(c+5,"RVNoob exe alu_io_mem_data", false,-1, 63,0);
        tracep->declQuad(c+1,"RVNoob exe alu_io_mem_addr", false,-1, 63,0);
        tracep->declQuad(c+354,"RVNoob exe dir_out", false,-1, 63,0);
        tracep->declQuad(c+114,"RVNoob exe alu_out", false,-1, 63,0);
        tracep->declQuad(c+110,"RVNoob exe alu io_src1", false,-1, 63,0);
        tracep->declQuad(c+112,"RVNoob exe alu io_src2", false,-1, 63,0);
        tracep->declBit(c+15,"RVNoob exe alu io_ctrl_judge_mux", false,-1);
        tracep->declBus(c+16,"RVNoob exe alu io_ctrl_judge_op", false,-1, 3,0);
        tracep->declBus(c+17,"RVNoob exe alu io_ctrl_alu_op", false,-1, 4,0);
        tracep->declBit(c+8,"RVNoob exe alu io_ctrl_old_val_mux", false,-1);
        tracep->declQuad(c+114,"RVNoob exe alu io_result", false,-1, 63,0);
        tracep->declBit(c+25,"RVNoob exe alu io_B_en", false,-1);
        tracep->declQuad(c+5,"RVNoob exe alu io_mem_data", false,-1, 63,0);
        tracep->declQuad(c+1,"RVNoob exe alu io_mem_addr", false,-1, 63,0);
        tracep->declBit(c+116,"RVNoob exe alu judge_io_less", false,-1);
        tracep->declQuad(c+117,"RVNoob exe alu judge_io_old_res", false,-1, 63,0);
        tracep->declBus(c+16,"RVNoob exe alu judge_io_judge_op", false,-1, 3,0);
        tracep->declQuad(c+119,"RVNoob exe alu judge_io_new_res", false,-1, 63,0);
        tracep->declBit(c+25,"RVNoob exe alu judge_io_B_en", false,-1);
        tracep->declBit(c+121,"RVNoob exe alu add", false,-1);
        tracep->declBit(c+122,"RVNoob exe alu sub", false,-1);
        tracep->declBit(c+123,"RVNoob exe alu sll", false,-1);
        tracep->declBit(c+124,"RVNoob exe alu srl", false,-1);
        tracep->declBit(c+125,"RVNoob exe alu sra", false,-1);
        tracep->declBit(c+126,"RVNoob exe alu xor_", false,-1);
        tracep->declBit(c+127,"RVNoob exe alu or_", false,-1);
        tracep->declBit(c+128,"RVNoob exe alu and_", false,-1);
        tracep->declBit(c+129,"RVNoob exe alu mul", false,-1);
        tracep->declBit(c+130,"RVNoob exe alu div", false,-1);
        tracep->declBit(c+131,"RVNoob exe alu rem", false,-1);
        tracep->declBit(c+132,"RVNoob exe alu mulh", false,-1);
        tracep->declBit(c+133,"RVNoob exe alu mulhs", false,-1);
        tracep->declBit(c+134,"RVNoob exe alu mulhsu", false,-1);
        tracep->declBit(c+135,"RVNoob exe alu alu_div", false,-1);
        tracep->declBit(c+136,"RVNoob exe alu divsw", false,-1);
        tracep->declBit(c+137,"RVNoob exe alu divw", false,-1);
        tracep->declBit(c+138,"RVNoob exe alu rems", false,-1);
        tracep->declBit(c+139,"RVNoob exe alu remsw", false,-1);
        tracep->declBit(c+140,"RVNoob exe alu remw", false,-1);
        tracep->declBit(c+141,"RVNoob exe alu srlw", false,-1);
        tracep->declBit(c+142,"RVNoob exe alu sraw", false,-1);
        tracep->declBit(c+143,"RVNoob exe alu sllw", false,-1);
        tracep->declQuad(c+144,"RVNoob exe alu alu_src2", false,-1, 63,0);
        tracep->declArray(c+146,"RVNoob exe alu add_res", false,-1, 64,0);
        tracep->declQuad(c+149,"RVNoob exe alu alu_div_res", false,-1, 63,0);
        tracep->declQuad(c+151,"RVNoob exe alu alu_res", false,-1, 63,0);
        tracep->declBit(c+116,"RVNoob exe alu judge io_less", false,-1);
        tracep->declQuad(c+117,"RVNoob exe alu judge io_old_res", false,-1, 63,0);
        tracep->declBus(c+16,"RVNoob exe alu judge io_judge_op", false,-1, 3,0);
        tracep->declQuad(c+119,"RVNoob exe alu judge io_new_res", false,-1, 63,0);
        tracep->declBit(c+25,"RVNoob exe alu judge io_B_en", false,-1);
        tracep->declBit(c+153,"RVNoob exe alu judge zero", false,-1);
        tracep->declBus(c+154,"RVNoob exe alu judge io_new_res_lo", false,-1, 31,0);
        tracep->declBus(c+155,"RVNoob exe alu judge io_new_res_lo_lo", false,-1, 7,0);
        tracep->declBus(c+156,"RVNoob exe alu judge io_new_res_lo_1", false,-1, 15,0);
        tracep->declBus(c+157,"RVNoob exe alu judge io_new_res_hi_1", false,-1, 31,0);
        tracep->declBus(c+158,"RVNoob exe alu judge io_new_res_lo_2", false,-1, 15,0);
        tracep->declBus(c+159,"RVNoob exe alu judge io_new_res_lo_lo_lo_1", false,-1, 5,0);
        tracep->declBus(c+160,"RVNoob exe alu judge io_new_res_lo_lo_1", false,-1, 11,0);
        tracep->declBus(c+161,"RVNoob exe alu judge io_new_res_lo_3", false,-1, 23,0);
        tracep->declBus(c+162,"RVNoob exe alu judge io_new_res_lo_4", false,-1, 7,0);
        tracep->declBus(c+163,"RVNoob exe alu judge io_new_res_lo_lo_lo_2", false,-1, 6,0);
        tracep->declBus(c+164,"RVNoob exe alu judge io_new_res_lo_lo_2", false,-1, 13,0);
        tracep->declBus(c+165,"RVNoob exe alu judge io_new_res_lo_5", false,-1, 27,0);
        tracep->declQuad(c+166,"RVNoob exe alu judge io_new_res_hi_5", false,-1, 55,0);
        tracep->declQuad(c+313,"RVNoob dpi_npc npc", false,-1, 63,0);
        tracep->declBit(c+299,"RVNoob U_ebreak clk", false,-1);
        tracep->declBus(c+303,"RVNoob U_ebreak inst", false,-1, 31,0);
        tracep->declQuad(c+168,"RVNoob U_ebreak a0", false,-1, 63,0);
        tracep->declBit(c+174,"RVNoob U_ebreak ebreak", false,-1);
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
    VlWide<6>/*191:0*/ __Vtemp210;
    VlWide<6>/*191:0*/ __Vtemp211;
    VlWide<3>/*95:0*/ __Vtemp214;
    VlWide<3>/*95:0*/ __Vtemp216;
    VlWide<3>/*95:0*/ __Vtemp217;
    VlWide<3>/*95:0*/ __Vtemp219;
    VlWide<3>/*95:0*/ __Vtemp220;
    VlWide<3>/*95:0*/ __Vtemp221;
    VlWide<3>/*95:0*/ __Vtemp224;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullQData(oldp+1,((((QData)((IData)(
                                                    vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U])))),64);
        tracep->fullQData(oldp+3,(vlSelf->RVNoob__DOT__rf_io_rdata2),64);
        tracep->fullQData(oldp+5,(((0x3fU >= (0x38U 
                                              & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U] 
                                                 << 3U)))
                                    ? (vlSelf->RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__rdata_t 
                                       >> (0x38U & 
                                           (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U] 
                                            << 3U)))
                                    : 0ULL)),64);
        tracep->fullCData(oldp+7,(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op),2);
        tracep->fullBit(oldp+8,(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem));
        tracep->fullBit(oldp+9,(vlSelf->RVNoob__DOT__idu__DOT__type_S));
        tracep->fullQData(oldp+10,(vlSelf->RVNoob__DOT__idu_io_imm),64);
        tracep->fullBit(oldp+12,(vlSelf->RVNoob__DOT__idu_io_wen));
        tracep->fullBit(oldp+13,(((((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_I) 
                                    | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_R)) 
                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S)) 
                                  | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_B))));
        tracep->fullBit(oldp+14,((((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S) 
                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_R)) 
                                  | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_B))));
        tracep->fullBit(oldp+15,((((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_slt) 
                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sextw)) 
                                  | (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem))));
        tracep->fullCData(oldp+16,(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op),4);
        tracep->fullCData(oldp+17,(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op),5);
        tracep->fullBit(oldp+18,(((IData)(vlSelf->RVNoob__DOT__idu__DOT__type_I) 
                                  | (IData)(vlSelf->RVNoob__DOT__idu__DOT__type_S))));
        tracep->fullBit(oldp+19,(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr));
        tracep->fullBit(oldp+20,(vlSelf->RVNoob__DOT__idu_io_pc_mux));
        tracep->fullQData(oldp+21,(vlSelf->RVNoob__DOT__exe_io_gp_out),64);
        tracep->fullQData(oldp+23,(vlSelf->RVNoob__DOT__rf_io_rdata1),64);
        tracep->fullBit(oldp+25,((1U & ((1U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                         ? (0ULL == vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res)
                                         : ((2U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                             ? (0ULL 
                                                != vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res)
                                             : ((3U 
                                                 == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                 ? 
                                                vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[2U]
                                                 : 
                                                ((4U 
                                                  == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op)) 
                                                 & ((~ 
                                                     vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[2U]) 
                                                    | (0ULL 
                                                       == vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res)))))))));
        tracep->fullQData(oldp+26,(vlSelf->RVNoob__DOT__npc_add_res),64);
        tracep->fullQData(oldp+28,((vlSelf->RVNoob__DOT__npc_add_res 
                                    >> 1U)),63);
        tracep->fullQData(oldp+30,(((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr)
                                     ? (0xfffffffffffffffeULL 
                                        & vlSelf->RVNoob__DOT__npc_add_res)
                                     : vlSelf->RVNoob__DOT__npc_add_res)),64);
        tracep->fullCData(oldp+32,(((3U == (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op))
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
        tracep->fullQData(oldp+33,(vlSelf->RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__rdata_t),64);
        VL_EXTEND_WQ(191,64, __Vtemp210, vlSelf->RVNoob__DOT__rf_io_rdata2);
        VL_SHIFTL_WWI(191,191,7, __Vtemp211, __Vtemp210, 
                      (0x38U & (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U] 
                                << 3U)));
        tracep->fullQData(oldp+35,((((QData)((IData)(
                                                     __Vtemp211[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 __Vtemp211[0U])))),64);
        tracep->fullCData(oldp+37,((7U & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[0U])),3);
        tracep->fullBit(oldp+38,(vlSelf->RVNoob__DOT__idu__DOT__rvi_beq));
        tracep->fullBit(oldp+39,(vlSelf->RVNoob__DOT__idu__DOT__rvi_bne));
        tracep->fullBit(oldp+40,(vlSelf->RVNoob__DOT__idu__DOT__rvi_blt));
        tracep->fullBit(oldp+41,(vlSelf->RVNoob__DOT__idu__DOT__rvi_bge));
        tracep->fullBit(oldp+42,(vlSelf->RVNoob__DOT__idu__DOT__rvi_bltu));
        tracep->fullBit(oldp+43,(vlSelf->RVNoob__DOT__idu__DOT__rvi_bgeu));
        tracep->fullBit(oldp+44,(vlSelf->RVNoob__DOT__idu__DOT__jpg_sexb));
        tracep->fullBit(oldp+45,(vlSelf->RVNoob__DOT__idu__DOT__jpg_sexthw));
        tracep->fullBit(oldp+46,(vlSelf->RVNoob__DOT__idu__DOT__rvi_lw));
        tracep->fullBit(oldp+47,(vlSelf->RVNoob__DOT__idu__DOT__jpg_uextb));
        tracep->fullBit(oldp+48,(vlSelf->RVNoob__DOT__idu__DOT__jpg_uexthw));
        tracep->fullBit(oldp+49,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sb));
        tracep->fullBit(oldp+50,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sh));
        tracep->fullBit(oldp+51,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sw));
        tracep->fullBit(oldp+52,(vlSelf->RVNoob__DOT__idu__DOT__rvi_addi));
        tracep->fullBit(oldp+53,(vlSelf->RVNoob__DOT__idu__DOT__rvi_slti));
        tracep->fullBit(oldp+54,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sltiu));
        tracep->fullBit(oldp+55,(vlSelf->RVNoob__DOT__idu__DOT__rvi_xori));
        tracep->fullBit(oldp+56,(vlSelf->RVNoob__DOT__idu__DOT__rvi_ori));
        tracep->fullBit(oldp+57,(vlSelf->RVNoob__DOT__idu__DOT__rvi_andi));
        tracep->fullBit(oldp+58,(vlSelf->RVNoob__DOT__idu__DOT__rvi_add));
        tracep->fullBit(oldp+59,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sub));
        tracep->fullBit(oldp+60,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sll));
        tracep->fullBit(oldp+61,(vlSelf->RVNoob__DOT__idu__DOT__rvi_slt));
        tracep->fullBit(oldp+62,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sltu));
        tracep->fullBit(oldp+63,(vlSelf->RVNoob__DOT__idu__DOT__rvi_xor));
        tracep->fullBit(oldp+64,(vlSelf->RVNoob__DOT__idu__DOT__rvi_srl));
        tracep->fullBit(oldp+65,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sra));
        tracep->fullBit(oldp+66,(vlSelf->RVNoob__DOT__idu__DOT__rvi_or));
        tracep->fullBit(oldp+67,(vlSelf->RVNoob__DOT__idu__DOT__rvi_and));
        tracep->fullBit(oldp+68,(vlSelf->RVNoob__DOT__idu__DOT__jpg_uextw));
        tracep->fullBit(oldp+69,(vlSelf->RVNoob__DOT__idu__DOT__rvi_ld));
        tracep->fullBit(oldp+70,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sd));
        tracep->fullBit(oldp+71,(vlSelf->RVNoob__DOT__idu__DOT__rvi_slli));
        tracep->fullBit(oldp+72,(vlSelf->RVNoob__DOT__idu__DOT__rvi_srli));
        tracep->fullBit(oldp+73,(vlSelf->RVNoob__DOT__idu__DOT__rvi_srai));
        tracep->fullBit(oldp+74,(vlSelf->RVNoob__DOT__idu__DOT__rvi_addiw));
        tracep->fullBit(oldp+75,(vlSelf->RVNoob__DOT__idu__DOT__rvi_slliw));
        tracep->fullBit(oldp+76,(vlSelf->RVNoob__DOT__idu__DOT__rvi_srliw));
        tracep->fullBit(oldp+77,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sraiw));
        tracep->fullBit(oldp+78,(vlSelf->RVNoob__DOT__idu__DOT__rvi_addw));
        tracep->fullBit(oldp+79,(vlSelf->RVNoob__DOT__idu__DOT__rvi_subw));
        tracep->fullBit(oldp+80,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sllw));
        tracep->fullBit(oldp+81,(vlSelf->RVNoob__DOT__idu__DOT__rvi_srlw));
        tracep->fullBit(oldp+82,(vlSelf->RVNoob__DOT__idu__DOT__rvi_sraw));
        tracep->fullBit(oldp+83,(vlSelf->RVNoob__DOT__idu__DOT__rvm_mul));
        tracep->fullBit(oldp+84,(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulh));
        tracep->fullBit(oldp+85,(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulhsu));
        tracep->fullBit(oldp+86,(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulhu));
        tracep->fullBit(oldp+87,(vlSelf->RVNoob__DOT__idu__DOT__rvm_div));
        tracep->fullBit(oldp+88,(vlSelf->RVNoob__DOT__idu__DOT__rvm_divu));
        tracep->fullBit(oldp+89,(vlSelf->RVNoob__DOT__idu__DOT__rvm_rem));
        tracep->fullBit(oldp+90,(vlSelf->RVNoob__DOT__idu__DOT__rvm_remu));
        tracep->fullBit(oldp+91,(vlSelf->RVNoob__DOT__idu__DOT__rvm_mulw));
        tracep->fullBit(oldp+92,(vlSelf->RVNoob__DOT__idu__DOT__rvm_divw));
        tracep->fullBit(oldp+93,(vlSelf->RVNoob__DOT__idu__DOT__rvm_remw));
        tracep->fullBit(oldp+94,(vlSelf->RVNoob__DOT__idu__DOT__type_I));
        tracep->fullBit(oldp+95,(vlSelf->RVNoob__DOT__idu__DOT__type_U));
        tracep->fullBit(oldp+96,(vlSelf->RVNoob__DOT__idu__DOT__type_R));
        tracep->fullBit(oldp+97,(vlSelf->RVNoob__DOT__idu__DOT__type_B));
        tracep->fullCData(oldp+98,(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo),6);
        tracep->fullSData(oldp+99,(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo),13);
        tracep->fullCData(oldp+100,(vlSelf->RVNoob__DOT__idu__DOT__immU_lo_lo),8);
        tracep->fullCData(oldp+101,(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo_lo),6);
        tracep->fullSData(oldp+102,(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo),13);
        tracep->fullCData(oldp+103,(vlSelf->RVNoob__DOT__idu__DOT__immJ_lo_lo_lo),5);
        tracep->fullQData(oldp+104,(vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1),44);
        tracep->fullQData(oldp+106,(vlSelf->RVNoob__DOT__idu__DOT__immB_hi_hi_hi_1),51);
        tracep->fullBit(oldp+108,(vlSelf->RVNoob__DOT__idu__DOT__jpg_slt));
        tracep->fullBit(oldp+109,(vlSelf->RVNoob__DOT__idu__DOT__jpg_sextw));
        tracep->fullQData(oldp+110,(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1),64);
        tracep->fullQData(oldp+112,(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src2),64);
        tracep->fullQData(oldp+114,(((((IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_slt) 
                                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__jpg_sextw)) 
                                      | (IData)(vlSelf->RVNoob__DOT__idu_io_pmem_ctrl_r_pmem))
                                      ? ((5U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                          ? (QData)((IData)(
                                                            (1U 
                                                             & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[2U])))
                                          : vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_154)
                                      : (((QData)((IData)(
                                                          vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_71[1U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_71[0U]))))),64);
        tracep->fullBit(oldp+116,((1U & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[2U])));
        tracep->fullQData(oldp+117,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res),64);
        tracep->fullQData(oldp+119,(((5U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                      ? (QData)((IData)(
                                                        (1U 
                                                         & vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res[2U])))
                                      : vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_154)),64);
        tracep->fullBit(oldp+121,((1U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+122,((2U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+123,((3U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+124,((4U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+125,((5U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+126,((6U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+127,((7U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+128,((8U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+129,((9U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+130,((0xaU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+131,((0xbU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+132,((0xcU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+133,((0xdU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+134,((0xeU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+135,((0xfU == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+136,((0x10U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+137,((0x11U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+138,((0x12U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+139,((0x13U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+140,((0x14U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+141,((0x15U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+142,((0x16U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullBit(oldp+143,((0x17U == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))));
        tracep->fullQData(oldp+144,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2),64);
        tracep->fullWData(oldp+146,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__add_res),65);
        VL_EXTEND_WQ(65,64, __Vtemp214, VL_DIV_QQQ(64, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2));
        VL_EXTENDS_WQ(65,64, __Vtemp216, vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1);
        __Vtemp217[0U] = __Vtemp216[0U];
        __Vtemp217[1U] = __Vtemp216[1U];
        __Vtemp217[2U] = (1U & __Vtemp216[2U]);
        VL_EXTENDS_WQ(65,64, __Vtemp219, vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2);
        __Vtemp220[0U] = __Vtemp219[0U];
        __Vtemp220[1U] = __Vtemp219[1U];
        __Vtemp220[2U] = (1U & __Vtemp219[2U]);
        VL_DIVS_WWW(65, __Vtemp221, __Vtemp217, __Vtemp220);
        VL_EXTEND_WQ(65,33, __Vtemp224, (0x1ffffffffULL 
                                         & ((0x11U 
                                             == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                             ? (QData)((IData)(
                                                               VL_DIV_III(32, (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1), (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2))))
                                             : VL_DIVS_QQQ(33, 
                                                           (0x1ffffffffULL 
                                                            & VL_EXTENDS_QI(33,32, (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu_io_src1))), 
                                                           (0x1ffffffffULL 
                                                            & VL_EXTENDS_QI(33,32, (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__alu_src2)))))));
        tracep->fullQData(oldp+149,((((QData)((IData)(
                                                      ((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_div_res_T)
                                                        ? 
                                                       ((0xaU 
                                                         == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                         ? 
                                                        __Vtemp214[1U]
                                                         : 
                                                        __Vtemp221[1U])
                                                        : 
                                                       __Vtemp224[1U]))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  ((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_div_res_T)
                                                                    ? 
                                                                   ((0xaU 
                                                                     == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_alu_op))
                                                                     ? 
                                                                    __Vtemp214[0U]
                                                                     : 
                                                                    __Vtemp221[0U])
                                                                    : 
                                                                   __Vtemp224[0U]))))),64);
        tracep->fullQData(oldp+151,((((QData)((IData)(
                                                      vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_71[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlSelf->RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_71[0U])))),64);
        tracep->fullBit(oldp+153,((0ULL == vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res)));
        tracep->fullIData(oldp+154,((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res)),32);
        tracep->fullCData(oldp+155,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo),8);
        tracep->fullSData(oldp+156,(((0x8000U & ((IData)(
                                                         (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                          >> 0x1fU)) 
                                                 << 0xfU)) 
                                     | ((0x4000U & 
                                         ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
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
                                                          | (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo)))))))))),16);
        tracep->fullIData(oldp+157,((((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                               >> 0x1fU)) 
                                      << 0x1fU) | (
                                                   (0x40000000U 
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
                                                                                | (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo))))))))))))))))))),32);
        tracep->fullSData(oldp+158,((0xffffU & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res))),16);
        tracep->fullCData(oldp+159,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_1),6);
        tracep->fullSData(oldp+160,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_1),12);
        tracep->fullIData(oldp+161,(((0x800000U & ((IData)(
                                                           (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                            >> 0xfU)) 
                                                   << 0x17U)) 
                                     | ((0x400000U 
                                         & ((IData)(
                                                    (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                     >> 0xfU)) 
                                            << 0x16U)) 
                                        | ((0x200000U 
                                            & ((IData)(
                                                       (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                        >> 0xfU)) 
                                               << 0x15U)) 
                                           | ((0x100000U 
                                               & ((IData)(
                                                          (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                           >> 0xfU)) 
                                                  << 0x14U)) 
                                              | ((0x80000U 
                                                  & ((IData)(
                                                             (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                              >> 0xfU)) 
                                                     << 0x13U)) 
                                                 | ((0x40000U 
                                                     & ((IData)(
                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                 >> 0xfU)) 
                                                        << 0x12U)) 
                                                    | (((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_1) 
                                                        << 0xcU) 
                                                       | (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_1))))))))),24);
        tracep->fullCData(oldp+162,((0xffU & (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res))),8);
        tracep->fullCData(oldp+163,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2),7);
        tracep->fullSData(oldp+164,(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_2),14);
        tracep->fullIData(oldp+165,(((0x8000000U & 
                                      ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                >> 7U)) 
                                       << 0x1bU)) | 
                                     ((0x4000000U & 
                                       ((IData)((vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                 >> 7U)) 
                                        << 0x1aU)) 
                                      | ((0x2000000U 
                                          & ((IData)(
                                                     (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                      >> 7U)) 
                                             << 0x19U)) 
                                         | ((0x1000000U 
                                             & ((IData)(
                                                        (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                         >> 7U)) 
                                                << 0x18U)) 
                                            | ((0x800000U 
                                                & ((IData)(
                                                           (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                            >> 7U)) 
                                                   << 0x17U)) 
                                               | ((0x400000U 
                                                   & ((IData)(
                                                              (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                               >> 7U)) 
                                                      << 0x16U)) 
                                                  | ((0x200000U 
                                                      & ((IData)(
                                                                 (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                  >> 7U)) 
                                                         << 0x15U)) 
                                                     | (((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2) 
                                                         << 0xeU) 
                                                        | (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_2)))))))))),28);
        tracep->fullQData(oldp+166,((((QData)((IData)(
                                                      (1U 
                                                       & (IData)(
                                                                 (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                  >> 7U))))) 
                                      << 0x37U) | (
                                                   ((QData)((IData)(
                                                                    (1U 
                                                                     & (IData)(
                                                                               (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U))))) 
                                                    << 0x36U) 
                                                   | (((QData)((IData)(
                                                                       (1U 
                                                                        & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U))))) 
                                                       << 0x35U) 
                                                      | (((QData)((IData)(
                                                                          (1U 
                                                                           & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U))))) 
                                                          << 0x34U) 
                                                         | (((QData)((IData)(
                                                                             (1U 
                                                                              & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U))))) 
                                                             << 0x33U) 
                                                            | (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U))))) 
                                                                << 0x32U) 
                                                               | (((QData)((IData)(
                                                                                (1U 
                                                                                & (IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U))))) 
                                                                   << 0x31U) 
                                                                  | (((QData)((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2)) 
                                                                      << 0x2aU) 
                                                                     | (((QData)((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_2)) 
                                                                         << 0x1cU) 
                                                                        | (QData)((IData)(
                                                                                ((0x8000000U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U)) 
                                                                                << 0x1bU)) 
                                                                                | ((0x4000000U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U)) 
                                                                                << 0x1aU)) 
                                                                                | ((0x2000000U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U)) 
                                                                                << 0x19U)) 
                                                                                | ((0x1000000U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U)) 
                                                                                << 0x18U)) 
                                                                                | ((0x800000U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U)) 
                                                                                << 0x17U)) 
                                                                                | ((0x400000U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U)) 
                                                                                << 0x16U)) 
                                                                                | ((0x200000U 
                                                                                & ((IData)(
                                                                                (vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res 
                                                                                >> 7U)) 
                                                                                << 0x15U)) 
                                                                                | (((IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2) 
                                                                                << 0xeU) 
                                                                                | (IData)(vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_2))))))))))))))))))))),56);
        tracep->fullQData(oldp+168,(vlSelf->RVNoob__DOT__rf__DOT__rf_10),64);
        tracep->fullQData(oldp+170,(vlSelf->RVNoob__DOT__pc),64);
        tracep->fullQData(oldp+172,((4ULL + vlSelf->RVNoob__DOT__pc)),64);
        tracep->fullBit(oldp+174,(vlSelf->RVNoob__DOT__U_ebreak_ebreak));
        tracep->fullQData(oldp+175,(vlSelf->RVNoob__DOT__rf__DOT__rf_1),64);
        tracep->fullQData(oldp+177,(vlSelf->RVNoob__DOT__rf__DOT__rf_2),64);
        tracep->fullQData(oldp+179,(vlSelf->RVNoob__DOT__rf__DOT__rf_3),64);
        tracep->fullQData(oldp+181,(vlSelf->RVNoob__DOT__rf__DOT__rf_4),64);
        tracep->fullQData(oldp+183,(vlSelf->RVNoob__DOT__rf__DOT__rf_5),64);
        tracep->fullQData(oldp+185,(vlSelf->RVNoob__DOT__rf__DOT__rf_6),64);
        tracep->fullQData(oldp+187,(vlSelf->RVNoob__DOT__rf__DOT__rf_7),64);
        tracep->fullQData(oldp+189,(vlSelf->RVNoob__DOT__rf__DOT__rf_8),64);
        tracep->fullQData(oldp+191,(vlSelf->RVNoob__DOT__rf__DOT__rf_9),64);
        tracep->fullQData(oldp+193,(vlSelf->RVNoob__DOT__rf__DOT__rf_11),64);
        tracep->fullQData(oldp+195,(vlSelf->RVNoob__DOT__rf__DOT__rf_12),64);
        tracep->fullQData(oldp+197,(vlSelf->RVNoob__DOT__rf__DOT__rf_13),64);
        tracep->fullQData(oldp+199,(vlSelf->RVNoob__DOT__rf__DOT__rf_14),64);
        tracep->fullQData(oldp+201,(vlSelf->RVNoob__DOT__rf__DOT__rf_15),64);
        tracep->fullQData(oldp+203,(vlSelf->RVNoob__DOT__rf__DOT__rf_16),64);
        tracep->fullQData(oldp+205,(vlSelf->RVNoob__DOT__rf__DOT__rf_17),64);
        tracep->fullQData(oldp+207,(vlSelf->RVNoob__DOT__rf__DOT__rf_18),64);
        tracep->fullQData(oldp+209,(vlSelf->RVNoob__DOT__rf__DOT__rf_19),64);
        tracep->fullQData(oldp+211,(vlSelf->RVNoob__DOT__rf__DOT__rf_20),64);
        tracep->fullQData(oldp+213,(vlSelf->RVNoob__DOT__rf__DOT__rf_21),64);
        tracep->fullQData(oldp+215,(vlSelf->RVNoob__DOT__rf__DOT__rf_22),64);
        tracep->fullQData(oldp+217,(vlSelf->RVNoob__DOT__rf__DOT__rf_23),64);
        tracep->fullQData(oldp+219,(vlSelf->RVNoob__DOT__rf__DOT__rf_24),64);
        tracep->fullQData(oldp+221,(vlSelf->RVNoob__DOT__rf__DOT__rf_25),64);
        tracep->fullQData(oldp+223,(vlSelf->RVNoob__DOT__rf__DOT__rf_26),64);
        tracep->fullQData(oldp+225,(vlSelf->RVNoob__DOT__rf__DOT__rf_27),64);
        tracep->fullQData(oldp+227,(vlSelf->RVNoob__DOT__rf__DOT__rf_28),64);
        tracep->fullQData(oldp+229,(vlSelf->RVNoob__DOT__rf__DOT__rf_29),64);
        tracep->fullQData(oldp+231,(vlSelf->RVNoob__DOT__rf__DOT__rf_30),64);
        tracep->fullQData(oldp+233,(vlSelf->RVNoob__DOT__rf__DOT__rf_31),64);
        tracep->fullQData(oldp+235,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[0]),64);
        tracep->fullQData(oldp+237,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[1]),64);
        tracep->fullQData(oldp+239,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[2]),64);
        tracep->fullQData(oldp+241,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[3]),64);
        tracep->fullQData(oldp+243,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[4]),64);
        tracep->fullQData(oldp+245,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[5]),64);
        tracep->fullQData(oldp+247,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[6]),64);
        tracep->fullQData(oldp+249,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[7]),64);
        tracep->fullQData(oldp+251,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[8]),64);
        tracep->fullQData(oldp+253,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[9]),64);
        tracep->fullQData(oldp+255,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[10]),64);
        tracep->fullQData(oldp+257,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[11]),64);
        tracep->fullQData(oldp+259,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[12]),64);
        tracep->fullQData(oldp+261,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[13]),64);
        tracep->fullQData(oldp+263,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[14]),64);
        tracep->fullQData(oldp+265,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[15]),64);
        tracep->fullQData(oldp+267,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[16]),64);
        tracep->fullQData(oldp+269,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[17]),64);
        tracep->fullQData(oldp+271,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[18]),64);
        tracep->fullQData(oldp+273,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[19]),64);
        tracep->fullQData(oldp+275,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[20]),64);
        tracep->fullQData(oldp+277,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[21]),64);
        tracep->fullQData(oldp+279,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[22]),64);
        tracep->fullQData(oldp+281,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[23]),64);
        tracep->fullQData(oldp+283,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[24]),64);
        tracep->fullQData(oldp+285,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[25]),64);
        tracep->fullQData(oldp+287,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[26]),64);
        tracep->fullQData(oldp+289,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[27]),64);
        tracep->fullQData(oldp+291,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[28]),64);
        tracep->fullQData(oldp+293,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[29]),64);
        tracep->fullQData(oldp+295,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[30]),64);
        tracep->fullQData(oldp+297,(vlSelf->RVNoob__DOT__rf__DOT__rf_read__DOT__rf[31]),64);
        tracep->fullBit(oldp+299,(vlSelf->clock));
        tracep->fullBit(oldp+300,(vlSelf->reset));
        tracep->fullQData(oldp+301,(vlSelf->io_pc),64);
        tracep->fullIData(oldp+303,(vlSelf->io_inst),32);
        tracep->fullQData(oldp+304,(vlSelf->io_res),64);
        tracep->fullBit(oldp+306,(vlSelf->io_ebreak));
        tracep->fullCData(oldp+307,((0x1fU & (vlSelf->io_inst 
                                              >> 7U))),5);
        tracep->fullCData(oldp+308,((0x1fU & (vlSelf->io_inst 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+309,((0x1fU & (vlSelf->io_inst 
                                              >> 0x14U))),5);
        tracep->fullBit(oldp+310,(((0x37U == (0x7fU 
                                              & vlSelf->io_inst)) 
                                   | (0x17U == (0x7fU 
                                                & vlSelf->io_inst)))));
        tracep->fullBit(oldp+311,((((0x37U == (0x7fU 
                                               & vlSelf->io_inst)) 
                                    | (0x6fU == (0x7fU 
                                                 & vlSelf->io_inst))) 
                                   | (IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr))));
        tracep->fullBit(oldp+312,((0x37U == (0x7fU 
                                             & vlSelf->io_inst))));
        tracep->fullQData(oldp+313,(((1U & ((IData)(vlSelf->RVNoob__DOT__idu_io_pc_mux) 
                                            | ((1U 
                                                == (IData)(vlSelf->RVNoob__DOT__idu_io_exe_ctrl_judge_op))
                                                ? (0ULL 
                                                   == vlSelf->RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res)
                                                : (
                                                   (2U 
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
                                      ? ((IData)(vlSelf->RVNoob__DOT__idu__DOT__rvi_jalr)
                                          ? (0xfffffffffffffffeULL 
                                             & vlSelf->RVNoob__DOT__npc_add_res)
                                          : vlSelf->RVNoob__DOT__npc_add_res)
                                      : (4ULL + vlSelf->RVNoob__DOT__pc))),64);
        tracep->fullCData(oldp+315,((0x7fU & vlSelf->io_inst)),7);
        tracep->fullCData(oldp+316,((7U & (vlSelf->io_inst 
                                           >> 0xcU))),3);
        tracep->fullCData(oldp+317,((vlSelf->io_inst 
                                     >> 0x19U)),7);
        tracep->fullBit(oldp+318,((0x17U == (0x7fU 
                                             & vlSelf->io_inst))));
        tracep->fullBit(oldp+319,((0x6fU == (0x7fU 
                                             & vlSelf->io_inst))));
        tracep->fullIData(oldp+320,(((0x2000000U & 
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
        tracep->fullQData(oldp+321,((((QData)((IData)(
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
        tracep->fullQData(oldp+323,((((QData)((IData)(
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
        tracep->fullSData(oldp+325,(((0x8000U & (vlSelf->io_inst 
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
        tracep->fullIData(oldp+326,(((0x80000000U & vlSelf->io_inst) 
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
        tracep->fullQData(oldp+327,((((QData)((IData)(
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
        tracep->fullIData(oldp+329,(((0x2000000U & 
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
                                                                 | (((IData)(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo_lo) 
                                                                     << 0xdU) 
                                                                    | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immS_lo_lo)))))))))),26);
        tracep->fullQData(oldp+330,((((QData)((IData)(
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
        tracep->fullQData(oldp+332,(((((QData)((IData)(
                                                       (vlSelf->io_inst 
                                                        >> 0x1fU))) 
                                       << 0x3fU) | 
                                      (((QData)((IData)(
                                                        (vlSelf->io_inst 
                                                         >> 0x1fU))) 
                                        << 0x3eU) | 
                                       (((QData)((IData)(
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
        tracep->fullSData(oldp+334,(((0x200U & (vlSelf->io_inst 
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
        tracep->fullSData(oldp+335,(((0x400U & (vlSelf->io_inst 
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
        tracep->fullIData(oldp+336,(((0x100000U & (vlSelf->io_inst 
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
        tracep->fullCData(oldp+337,((0xffU & (vlSelf->io_inst 
                                              >> 0xcU))),8);
        tracep->fullBit(oldp+338,((1U & (vlSelf->io_inst 
                                         >> 0x14U))));
        tracep->fullSData(oldp+339,((0x3ffU & (vlSelf->io_inst 
                                               >> 0x15U))),10);
        tracep->fullQData(oldp+340,(((vlSelf->RVNoob__DOT__idu__DOT__immJ_hi_hi_1 
                                      << 0x14U) | (QData)((IData)(
                                                                  ((0xff000U 
                                                                    & vlSelf->io_inst) 
                                                                   | ((0x800U 
                                                                       & (vlSelf->io_inst 
                                                                          >> 9U)) 
                                                                      | (0x7feU 
                                                                         & (vlSelf->io_inst 
                                                                            >> 0x14U)))))))),64);
        tracep->fullSData(oldp+342,(((0x800U & (vlSelf->io_inst 
                                                >> 0x14U)) 
                                     | ((0x400U & (vlSelf->io_inst 
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
                                                    | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo)))))))),12);
        tracep->fullSData(oldp+343,(((0x1000U & (vlSelf->io_inst 
                                                 >> 0x13U)) 
                                     | ((0x800U & (vlSelf->io_inst 
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
                                                       | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo))))))))),13);
        tracep->fullIData(oldp+344,(((0x1000000U & 
                                      (vlSelf->io_inst 
                                       >> 7U)) | ((0x800000U 
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
                                                                                | (IData)(vlSelf->RVNoob__DOT__idu__DOT__immI_lo_lo_lo)))))))))))))))),25);
        tracep->fullBit(oldp+345,((1U & (vlSelf->io_inst 
                                         >> 7U))));
        tracep->fullCData(oldp+346,((0x3fU & (vlSelf->io_inst 
                                              >> 0x19U))),6);
        tracep->fullCData(oldp+347,((0xfU & (vlSelf->io_inst 
                                             >> 8U))),4);
        tracep->fullQData(oldp+348,(((vlSelf->RVNoob__DOT__idu__DOT__immB_hi_hi_hi_1 
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
        tracep->fullQData(oldp+350,(((0x1fU == (0x1fU 
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
        tracep->fullQData(oldp+352,(((0x1fU == (0x1fU 
                                                & (vlSelf->io_inst 
                                                   >> 0x14U)))
                                      ? vlSelf->RVNoob__DOT__rf__DOT__rf_31
                                      : ((0x1eU == 
                                          (0x1fU & 
                                           (vlSelf->io_inst 
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
        tracep->fullQData(oldp+354,(((0x37U == (0x7fU 
                                                & vlSelf->io_inst))
                                      ? vlSelf->RVNoob__DOT__idu_io_imm
                                      : (4ULL + vlSelf->RVNoob__DOT__pc))),64);
        tracep->fullQData(oldp+356,(0ULL),64);
    }
}
