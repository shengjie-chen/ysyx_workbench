// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VRVNoob.h"
#include "VRVNoob__Syms.h"
#include "verilated_vcd_c.h"
#include "verilated_dpi.h"

//============================================================
// Constructors

VRVNoob::VRVNoob(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VRVNoob__Syms(_vcontextp__, _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_pc{vlSymsp->TOP.io_pc}
    , io_inst{vlSymsp->TOP.io_inst}
    , io_res{vlSymsp->TOP.io_res}
    , io_ebreak{vlSymsp->TOP.io_ebreak}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
}

VRVNoob::VRVNoob(const char* _vcname__)
    : VRVNoob(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VRVNoob::~VRVNoob() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VRVNoob___024root___eval_initial(VRVNoob___024root* vlSelf);
void VRVNoob___024root___eval_settle(VRVNoob___024root* vlSelf);
void VRVNoob___024root___eval(VRVNoob___024root* vlSelf);
QData VRVNoob___024root___change_request(VRVNoob___024root* vlSelf);
#ifdef VL_DEBUG
void VRVNoob___024root___eval_debug_assertions(VRVNoob___024root* vlSelf);
#endif  // VL_DEBUG
void VRVNoob___024root___final(VRVNoob___024root* vlSelf);

static void _eval_initial_loop(VRVNoob__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VRVNoob___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VRVNoob___024root___eval_settle(&(vlSymsp->TOP));
        VRVNoob___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VRVNoob___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob/Verilog_Gen/RVNoob.v", 1221, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VRVNoob___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VRVNoob::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VRVNoob::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VRVNoob___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VRVNoob___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VRVNoob___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/jiexxpu/ysyx/ysyx-workbench/npc/build/RVnpc/RVNoob/Verilog_Gen/RVNoob.v", 1221, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VRVNoob___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VRVNoob::final() {
    VRVNoob___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VRVNoob::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VRVNoob::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VRVNoob___024root__traceInitTop(VRVNoob___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VRVNoob___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRVNoob___024root*>(voidSelf);
    VRVNoob__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VRVNoob___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VRVNoob___024root__traceRegister(VRVNoob___024root* vlSelf, VerilatedVcd* tracep);

void VRVNoob::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VRVNoob___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
