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
        CData/*0:0*/ RVNoob__DOT__idu_io_pc_mux;
        CData/*0:0*/ RVNoob__DOT__U_ebreak_ebreak;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_addi;
        CData/*0:0*/ RVNoob__DOT__idu__DOT__rvi_jalr;
        CData/*5:0*/ RVNoob__DOT__idu__DOT__immI_lo_lo_lo;
        CData/*7:0*/ RVNoob__DOT__idu__DOT__immU_lo_lo;
        CData/*4:0*/ RVNoob__DOT__idu__DOT__immJ_lo_lo_lo;
        SData/*12:0*/ RVNoob__DOT__idu__DOT__immI_lo_lo;
        QData/*63:0*/ RVNoob__DOT__idu_io_imm;
        QData/*63:0*/ RVNoob__DOT__exe_io_gp_out;
        QData/*63:0*/ RVNoob__DOT__exe_io_dnpc;
        QData/*63:0*/ RVNoob__DOT__pc;
        QData/*63:0*/ RVNoob__DOT__snpc;
        QData/*43:0*/ RVNoob__DOT__idu__DOT__immJ_hi_hi_1;
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
    };
    struct {
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
        QData/*63:0*/ RVNoob__DOT__exe__DOT__alu_out;
        VlUnpacked<QData/*63:0*/, 32> RVNoob__DOT__rf__DOT__rf_read__DOT__rf;
    };

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clock;
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
