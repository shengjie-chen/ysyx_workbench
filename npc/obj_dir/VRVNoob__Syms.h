// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VRVNOOB__SYMS_H_
#define VERILATED_VRVNOOB__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VRVNoob.h"

// INCLUDE MODULE CLASSES
#include "VRVNoob___024root.h"
#include "VRVNoob___024unit.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class VRVNoob__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VRVNoob* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VRVNoob___024root              TOP;
    VRVNoob___024unit              TOP____024unit;

    // SCOPE NAMES
    VerilatedScope __Vscope_RVNoob__ifm;

    // CONSTRUCTORS
    VRVNoob__Syms(VerilatedContext* contextp, const char* namep, VRVNoob* modelp);
    ~VRVNoob__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
