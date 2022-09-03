// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VEbreak.h for the primary calling header

#ifndef VERILATED_VEBREAK___024ROOT_H_
#define VERILATED_VEBREAK___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VEbreak__Syms;
class VEbreak_VerilatedVcd;
class VEbreak___024unit;


//----------

VL_MODULE(VEbreak___024root) {
  public:
    // CELLS
    VEbreak___024unit* __PVT____024unit;

    // PORTS
    VL_IN8(clk,0,0);
    VL_OUT8(ebreak,0,0);
    VL_IN(inst,31,0);
    VL_IN64(a0,63,0);
    VL_IN64(rf_0,63,0);
    VL_IN64(rf_1,63,0);
    VL_IN64(rf_2,63,0);
    VL_IN64(rf_3,63,0);
    VL_IN64(rf_4,63,0);
    VL_IN64(rf_5,63,0);
    VL_IN64(rf_6,63,0);
    VL_IN64(rf_7,63,0);
    VL_IN64(rf_8,63,0);
    VL_IN64(rf_9,63,0);
    VL_IN64(rf_10,63,0);
    VL_IN64(rf_11,63,0);
    VL_IN64(rf_12,63,0);
    VL_IN64(rf_13,63,0);
    VL_IN64(rf_14,63,0);
    VL_IN64(rf_15,63,0);
    VL_IN64(rf_16,63,0);
    VL_IN64(rf_17,63,0);
    VL_IN64(rf_18,63,0);
    VL_IN64(rf_19,63,0);
    VL_IN64(rf_20,63,0);
    VL_IN64(rf_21,63,0);
    VL_IN64(rf_22,63,0);
    VL_IN64(rf_23,63,0);
    VL_IN64(rf_24,63,0);
    VL_IN64(rf_25,63,0);
    VL_IN64(rf_26,63,0);
    VL_IN64(rf_27,63,0);
    VL_IN64(rf_28,63,0);
    VL_IN64(rf_29,63,0);
    VL_IN64(rf_30,63,0);
    VL_IN64(rf_31,63,0);

    // LOCAL SIGNALS
    VlUnpacked<QData/*63:0*/, 32> RF_read__DOT__rf;

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    VEbreak__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VEbreak___024root);  ///< Copying not allowed
  public:
    VEbreak___024root(const char* name);
    ~VEbreak___024root();

    // INTERNAL METHODS
    void __Vconfigure(VEbreak__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
