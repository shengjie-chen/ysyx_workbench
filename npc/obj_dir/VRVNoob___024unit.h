// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VRVNoob.h for the primary calling header

#ifndef VERILATED_VRVNOOB___024UNIT_H_
#define VERILATED_VRVNOOB___024UNIT_H_  // guard

#include "verilated_heavy.h"

//==========

class VRVNoob__Syms;
class VRVNoob_VerilatedVcd;


//----------

VL_MODULE(VRVNoob___024unit) {
  public:

    // INTERNAL VARIABLES
    VRVNoob__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VRVNoob___024unit);  ///< Copying not allowed
  public:
    VRVNoob___024unit(const char* name);
    ~VRVNoob___024unit();

    // INTERNAL METHODS
    void __Vconfigure(VRVNoob__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
