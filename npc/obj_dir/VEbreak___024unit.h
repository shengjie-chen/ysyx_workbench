// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VEbreak.h for the primary calling header

#ifndef VERILATED_VEBREAK___024UNIT_H_
#define VERILATED_VEBREAK___024UNIT_H_  // guard

#include "verilated_heavy.h"

//==========

class VEbreak__Syms;
class VEbreak_VerilatedVcd;


//----------

VL_MODULE(VEbreak___024unit) {
  public:

    // INTERNAL VARIABLES
    VEbreak__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VEbreak___024unit);  ///< Copying not allowed
  public:
    VEbreak___024unit(const char* name);
    ~VEbreak___024unit();

    // INTERNAL METHODS
    void __Vconfigure(VEbreak__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
