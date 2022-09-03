// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VEBREAK__SYMS_H_
#define VERILATED_VEBREAK__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VEbreak.h"

// INCLUDE MODULE CLASSES
#include "VEbreak___024root.h"
#include "VEbreak___024unit.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class VEbreak__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VEbreak* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VEbreak___024root              TOP;
    VEbreak___024unit              TOP____024unit;

    // CONSTRUCTORS
    VEbreak__Syms(VerilatedContext* contextp, const char* namep, VEbreak* modelp);
    ~VEbreak__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
