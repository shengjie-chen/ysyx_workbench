// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VRVNoob__Syms.h"
#include "VRVNoob.h"
#include "VRVNoob___024root.h"
#include "VRVNoob___024unit.h"

// FUNCTIONS
VRVNoob__Syms::~VRVNoob__Syms()
{
}

VRVNoob__Syms::VRVNoob__Syms(VerilatedContext* contextp, const char* namep,VRVNoob* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp(modelp)
    // Setup module instances
    , TOP(namep)
    , TOP____024unit(Verilated::catName(namep, "$unit"))
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT____024unit = &TOP____024unit;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(this, true);
    TOP____024unit.__Vconfigure(this, true);
    // Setup scopes
    __Vscope_RVNoob__ifm.configure(this, name(), "RVNoob.ifm", "ifm", -12, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
    }
}
