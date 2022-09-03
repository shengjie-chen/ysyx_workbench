// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VEBREAK_H_
#define VERILATED_VEBREAK_H_  // guard

#include "verilated_heavy.h"
#include "svdpi.h"

class VEbreak__Syms;
class VEbreak___024root;
class VerilatedVcdC;
class VEbreak_VerilatedVcd;
class VEbreak___024unit;


// This class is the main interface to the Verilated model
class VEbreak VL_NOT_FINAL {
  private:
    // Symbol table holding complete model state (owned by this class)
    VEbreak__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_IN(&inst,31,0);
    VL_IN64(&a0,63,0);
    VL_OUT8(&ebreak,0,0);
    VL_IN64(&rf_0,63,0);
    VL_IN64(&rf_1,63,0);
    VL_IN64(&rf_2,63,0);
    VL_IN64(&rf_3,63,0);
    VL_IN64(&rf_4,63,0);
    VL_IN64(&rf_5,63,0);
    VL_IN64(&rf_6,63,0);
    VL_IN64(&rf_7,63,0);
    VL_IN64(&rf_8,63,0);
    VL_IN64(&rf_9,63,0);
    VL_IN64(&rf_10,63,0);
    VL_IN64(&rf_11,63,0);
    VL_IN64(&rf_12,63,0);
    VL_IN64(&rf_13,63,0);
    VL_IN64(&rf_14,63,0);
    VL_IN64(&rf_15,63,0);
    VL_IN64(&rf_16,63,0);
    VL_IN64(&rf_17,63,0);
    VL_IN64(&rf_18,63,0);
    VL_IN64(&rf_19,63,0);
    VL_IN64(&rf_20,63,0);
    VL_IN64(&rf_21,63,0);
    VL_IN64(&rf_22,63,0);
    VL_IN64(&rf_23,63,0);
    VL_IN64(&rf_24,63,0);
    VL_IN64(&rf_25,63,0);
    VL_IN64(&rf_26,63,0);
    VL_IN64(&rf_27,63,0);
    VL_IN64(&rf_28,63,0);
    VL_IN64(&rf_29,63,0);
    VL_IN64(&rf_30,63,0);
    VL_IN64(&rf_31,63,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    VEbreak___024unit* const __PVT____024unit;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    VEbreak___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit VEbreak(VerilatedContext* contextp, const char* name = "TOP");
    explicit VEbreak(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~VEbreak();
  private:
    VL_UNCOPYABLE(VEbreak);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp() const;
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
