// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_generic_counter.h for the primary calling header

#ifndef VERILATED_VTB_GENERIC_COUNTER___024ROOT_H_
#define VERILATED_VTB_GENERIC_COUNTER___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"
#include "verilated_timing.h"


class Vtb_generic_counter__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_generic_counter___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_generic_counter__DOT__rstn;
    CData/*0:0*/ tb_generic_counter__DOT__en;
    CData/*3:0*/ tb_generic_counter__DOT__dut__DOT__counter;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    CData/*0:0*/ tb_generic_counter__DOT__clk;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_generic_counter__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_generic_counter__DOT__rstn__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h68df5bc7__0;
    VlMTaskVertex __Vm_mtaskstate_final__0nba;

    // INTERNAL VARIABLES
    Vtb_generic_counter__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_generic_counter___024root(Vtb_generic_counter__Syms* symsp, const char* namep);
    ~Vtb_generic_counter___024root();
    VL_UNCOPYABLE(Vtb_generic_counter___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
