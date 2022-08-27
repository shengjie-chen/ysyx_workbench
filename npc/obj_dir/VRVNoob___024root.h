// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VRVNoob.h for the primary calling header

#ifndef VERILATED_VRVNOOB___024ROOT_H_
#define VERILATED_VRVNOOB___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VRVNoob__Syms;
class VRVNoob_VerilatedVcd;
class VRVNoob___024unit;


//----------

VL_MODULE(VRVNoob___024root) {
  public:
    // CELLS
    VRVNoob___024unit* __PVT____024unit;

    // PORTS
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_ebreak,0,0);
    VL_IN(io_inst,31,0);
    VL_OUT64(io_pc,63,0);
    VL_OUT64(io_res,63,0);

    // LOCAL SIGNALS
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ RVNoob__DOT__idu_io_wen;
        CData/*3:0*/ RVNoob__DOT__idu_io_exe_ctrl_judge_op;
        CData/*4:0*/ RVNoob__DOT__idu_io_exe_ctrl_alu_op;
        CData/*1:0*/ RVNoob__DOT__idu_io_pmem_ctrl_zero_ex_op;
        CData/*0:0*/ RVNoob__DOT__idu_io_pmem_ctrl_r_pmem;
        CData/*0:0*/ RVNoob__DOT__idu_io_pc_mux;
        CData/*0:0*/ RVNoob__DOT__U_ebreak_ebreak;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_jalr;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_beq;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_bne;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_blt;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_bge;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_bltu;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_bgeu;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__jpg_sexb;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__jpg_sexthw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_lw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__jpg_uextb;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__jpg_uexthw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_sb;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_sh;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_sw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_addi;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_slti;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_sltiu;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_xori;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_ori;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_andi;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_add;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_sub;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_sll;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_slt;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_sltu;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_xor;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_srl;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_sra;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_or;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_and;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__jpg_uextw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_ld;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_sd;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_slli;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_srli;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_srai;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_addiw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_slliw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_srliw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_sraiw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_addw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_subw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_sllw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_srlw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_sraw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvm_mul;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvm_mulh;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvm_mulhsu;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvm_mulhu;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvm_div;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvm_divu;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvm_rem;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvm_remu;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvm_mulw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvm_divw;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvm_remw;
    };
    struct {
        CData/*0:0*/ RVNoob__DOT__idu__DOT__type_I;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__type_U;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__type_S;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__type_R;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__type_B;
        CData/*5:0*/ RVNoob__DOT__idu__DOT__immI_lo_lo_lo;
        CData/*7:0*/ RVNoob__DOT__idu__DOT__immU_lo_lo;
        CData/*5:0*/ RVNoob__DOT__idu__DOT__immS_lo_lo_lo;
        CData/*4:0*/ RVNoob__DOT__idu__DOT__immJ_lo_lo_lo;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__jpg_slt;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__jpg_sextw;
        CData/*0:0*/ RVNoob__DOT__exe__DOT__alu__DOT___alu_div_res_T;
        CData/*7:0*/ RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo;
        CData/*5:0*/ RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_1;
        CData/*6:0*/ RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_lo_2;
        SData/*12:0*/ RVNoob__DOT__idu__DOT__immI_lo_lo;
        SData/*12:0*/ RVNoob__DOT__idu__DOT__immS_lo_lo;
        SData/*11:0*/ RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_1;
        SData/*13:0*/ RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT__io_new_res_lo_lo_2;
        VlWide<3>/*64:0*/ RVNoob__DOT__exe__DOT__alu__DOT__add_res;
        VlWide<4>/*127:0*/ RVNoob__DOT__exe__DOT__alu__DOT___alu_res_T_71;
        QData/*63:0*/ RVNoob__DOT__idu_io_imm;
        QData/*63:0*/ RVNoob__DOT__rf_io_rdata1;
        QData/*63:0*/ RVNoob__DOT__rf_io_rdata2;
        QData/*63:0*/ RVNoob__DOT__exe_io_gp_out;
        QData/*63:0*/ RVNoob__DOT__pc;
        QData/*63:0*/ RVNoob__DOT__npc_add_res;
        QData/*63:0*/ RVNoob__DOT__snpc;
        QData/*63:0*/ RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__rdata_t;
        QData/*43:0*/ RVNoob__DOT__idu__DOT__immJ_hi_hi_1;
        QData/*50:0*/ RVNoob__DOT__idu__DOT__immB_hi_hi_hi_1;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_1;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_2;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_3;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_4;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_5;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_6;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_7;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_8;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_9;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_10;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_11;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_12;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_13;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_14;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_15;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_16;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_17;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_18;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_19;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_20;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_21;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_22;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_23;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_24;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_25;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_26;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_27;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_28;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_29;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_30;
        QData/*63:0*/ RVNoob__DOT__rf__DOT__rf_31;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_0;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_1;
    };
    struct {
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_2;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_3;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_4;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_5;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_6;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_7;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_8;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_9;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_10;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_11;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_12;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_13;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_14;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_15;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_16;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_17;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_18;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_19;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_20;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_21;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_22;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_23;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_24;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_25;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_26;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_27;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_28;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_29;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_30;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_57;
        QData/*63:0*/ RVNoob__DOT__rf__DOT___GEN_89;
        QData/*63:0*/ RVNoob__DOT__exe__DOT__alu_io_src1;
        QData/*63:0*/ RVNoob__DOT__exe__DOT__alu_io_src2;
        QData/*63:0*/ RVNoob__DOT__exe__DOT__alu__DOT__judge_io_old_res;
        QData/*63:0*/ RVNoob__DOT__exe__DOT__alu__DOT__alu_src2;
        QData/*63:0*/ RVNoob__DOT__exe__DOT__alu__DOT__judge__DOT___io_new_res_T_154;
        VlUnpacked<QData/*63:0*/, 32> RVNoob__DOT__rf__DOT__rf_read__DOT__rf;
    };

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clock;
    QData/*63:0*/ __Vtask_RVNoob__DOT__ifm__DOT__dpi_pmem__DOT__pmem_read_dpi__0__rdata;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VRVNoob__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VRVNoob___024root);  ///< Copying not allowed
  public:
    VRVNoob___024root(const char* name);
    ~VRVNoob___024root();

    // INTERNAL METHODS
    void __Vconfigure(VRVNoob__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
