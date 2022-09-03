// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VEbreak.h"
#include "VEbreak__Syms.h"
#include "verilated_vcd_c.h"
#include "verilated_dpi.h"

//============================================================
// Constructors

VEbreak::VEbreak(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VEbreak__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , inst{vlSymsp->TOP.inst}
    , a0{vlSymsp->TOP.a0}
    , ebreak{vlSymsp->TOP.ebreak}
    , rf_0{vlSymsp->TOP.rf_0}
    , rf_1{vlSymsp->TOP.rf_1}
    , rf_2{vlSymsp->TOP.rf_2}
    , rf_3{vlSymsp->TOP.rf_3}
    , rf_4{vlSymsp->TOP.rf_4}
    , rf_5{vlSymsp->TOP.rf_5}
    , rf_6{vlSymsp->TOP.rf_6}
    , rf_7{vlSymsp->TOP.rf_7}
    , rf_8{vlSymsp->TOP.rf_8}
    , rf_9{vlSymsp->TOP.rf_9}
    , rf_10{vlSymsp->TOP.rf_10}
    , rf_11{vlSymsp->TOP.rf_11}
    , rf_12{vlSymsp->TOP.rf_12}
    , rf_13{vlSymsp->TOP.rf_13}
    , rf_14{vlSymsp->TOP.rf_14}
    , rf_15{vlSymsp->TOP.rf_15}
    , rf_16{vlSymsp->TOP.rf_16}
    , rf_17{vlSymsp->TOP.rf_17}
    , rf_18{vlSymsp->TOP.rf_18}
    , rf_19{vlSymsp->TOP.rf_19}
    , rf_20{vlSymsp->TOP.rf_20}
    , rf_21{vlSymsp->TOP.rf_21}
    , rf_22{vlSymsp->TOP.rf_22}
    , rf_23{vlSymsp->TOP.rf_23}
    , rf_24{vlSymsp->TOP.rf_24}
    , rf_25{vlSymsp->TOP.rf_25}
    , rf_26{vlSymsp->TOP.rf_26}
    , rf_27{vlSymsp->TOP.rf_27}
    , rf_28{vlSymsp->TOP.rf_28}
    , rf_29{vlSymsp->TOP.rf_29}
    , rf_30{vlSymsp->TOP.rf_30}
    , rf_31{vlSymsp->TOP.rf_31}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
}

VEbreak::VEbreak(const char* _vcname__)
    : VEbreak(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VEbreak::~VEbreak() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VEbreak___024root___eval_initial(VEbreak___024root* vlSelf);
void VEbreak___024root___eval_settle(VEbreak___024root* vlSelf);
void VEbreak___024root___eval(VEbreak___024root* vlSelf);
QData VEbreak___024root___change_request(VEbreak___024root* vlSelf);
#ifdef VL_DEBUG
void VEbreak___024root___eval_debug_assertions(VEbreak___024root* vlSelf);
#endif  // VL_DEBUG
void VEbreak___024root___final(VEbreak___024root* vlSelf);

static void _eval_initial_loop(VEbreak__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VEbreak___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VEbreak___024root___eval_settle(&(vlSymsp->TOP));
        VEbreak___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VEbreak___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/jiexxpu/ysyx/ysyx-workbench/npc/playground/src/RVnpc/RVNoob/Ebreak.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VEbreak___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VEbreak::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VEbreak::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VEbreak___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VEbreak___024root___eval(&(vlSymsp->TOP));
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = VEbreak___024root___change_request(&(vlSymsp->TOP));
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/jiexxpu/ysyx/ysyx-workbench/npc/playground/src/RVnpc/RVNoob/Ebreak.v", 3, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = VEbreak___024root___change_request(&(vlSymsp->TOP));
        }
    } while (VL_UNLIKELY(__Vchange));
}

//============================================================
// Invoke final blocks

void VEbreak::final() {
    VEbreak___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* VEbreak::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VEbreak::name() const {
    return vlSymsp->name();
}

//============================================================
// Trace configuration

void VEbreak___024root__traceInitTop(VEbreak___024root* vlSelf, VerilatedVcd* tracep);

static void traceInit(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VEbreak___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VEbreak___024root*>(voidSelf);
    VEbreak__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VEbreak___024root__traceInitTop(vlSelf, tracep);
    tracep->scopeEscape('.');
}

void VEbreak___024root__traceRegister(VEbreak___024root* vlSelf, VerilatedVcd* tracep);

void VEbreak::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, &(vlSymsp->TOP));
    VEbreak___024root__traceRegister(&(vlSymsp->TOP), tfp->spTrace());
}
