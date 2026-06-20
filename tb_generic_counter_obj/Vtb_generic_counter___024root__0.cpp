// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_generic_counter.h for the primary calling header

#include "Vtb_generic_counter__pch.h"

VlCoroutine Vtb_generic_counter___024root___eval_initial__TOP__Vtiming__0(Vtb_generic_counter___024root* vlSelf);
VlCoroutine Vtb_generic_counter___024root___eval_initial__TOP__Vtiming__1(Vtb_generic_counter___024root* vlSelf);

void Vtb_generic_counter___024root___eval_initial(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval_initial\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_generic_counter___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_generic_counter___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

void Vtb_generic_counter___024root____VbeforeTrig_h68df5bc7__0(Vtb_generic_counter___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtb_generic_counter___024root___eval_initial__TOP__Vtiming__0(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_generic_counter__DOT__unnamedblk1_2__DOT____Vrepeat1;
    tb_generic_counter__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    IData/*31:0*/ tb_generic_counter__DOT__unnamedblk1_3__DOT____Vrepeat2;
    tb_generic_counter__DOT__unnamedblk1_3__DOT____Vrepeat2 = 0;
    IData/*31:0*/ __Vtask_tb_generic_counter__DOT__wait_cycles__0__tb_generic_counter__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_generic_counter__DOT__wait_cycles__0__tb_generic_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_generic_counter__DOT__wait_cycles__1__n;
    __Vtask_tb_generic_counter__DOT__wait_cycles__1__n = 0;
    IData/*31:0*/ __Vtask_tb_generic_counter__DOT__wait_cycles__1__tb_generic_counter__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_generic_counter__DOT__wait_cycles__1__tb_generic_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    // Body
    VL_WRITEF_NX("=== generic_counter testbench (MAX=10) ===\n",0);
    vlSelfRef.tb_generic_counter__DOT__rstn = 0U;
    vlSelfRef.tb_generic_counter__DOT__en = 0U;
    __Vtask_tb_generic_counter__DOT__wait_cycles__0__tb_generic_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 = 2U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_generic_counter__DOT__wait_cycles__0__tb_generic_counter__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_generic_counter___024root____VbeforeTrig_h68df5bc7__0(vlSelf, 
                                                                  "@(posedge tb_generic_counter.clk)");
        co_await vlSelfRef.__VtrigSched_h68df5bc7__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_generic_counter.clk)", 
                                                             "tests/tb_generic_counter.sv", 
                                                             19);
        __Vtask_tb_generic_counter__DOT__wait_cycles__0__tb_generic_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_generic_counter__DOT__wait_cycles__0__tb_generic_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_generic_counter__DOT__rstn = 1U;
    __Vtask_tb_generic_counter__DOT__wait_cycles__1__n = 2U;
    __Vtask_tb_generic_counter__DOT__wait_cycles__1__tb_generic_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    __Vtask_tb_generic_counter__DOT__wait_cycles__1__tb_generic_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 
        = __Vtask_tb_generic_counter__DOT__wait_cycles__1__n;
    while (VL_LTS_III(32, 0U, __Vtask_tb_generic_counter__DOT__wait_cycles__1__tb_generic_counter__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_generic_counter___024root____VbeforeTrig_h68df5bc7__0(vlSelf, 
                                                                  "@(posedge tb_generic_counter.clk)");
        co_await vlSelfRef.__VtrigSched_h68df5bc7__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_generic_counter.clk)", 
                                                             "tests/tb_generic_counter.sv", 
                                                             19);
        __Vtask_tb_generic_counter__DOT__wait_cycles__1__tb_generic_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_generic_counter__DOT__wait_cycles__1__tb_generic_counter__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.tb_generic_counter__DOT__dut__DOT__counter))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_generic_counter.sv:27: Assertion failed in %m: FAIL starts at 0\n",3, 'M',vlSymsp->name(),"tb_generic_counter", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("tests/tb_generic_counter.sv", 27, "", false);
    } else {
        VL_WRITEF_NX("PASS starts at 0\n",0);
    }
    if (VL_UNLIKELY(((9U == (IData)(vlSelfRef.tb_generic_counter__DOT__dut__DOT__counter))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_generic_counter.sv:28: Assertion failed in %m: FAIL ending low at 0\n",3, 'M',vlSymsp->name(),"tb_generic_counter", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("tests/tb_generic_counter.sv", 28, "", false);
    } else {
        VL_WRITEF_NX("PASS ending low at 0\n",0);
    }
    VL_WRITEF_NX("--- count to MAX-1 ---\n",0);
    vlSelfRef.tb_generic_counter__DOT__en = 1U;
    tb_generic_counter__DOT__unnamedblk1_2__DOT____Vrepeat1 = 9U;
    while (VL_LTS_III(32, 0U, tb_generic_counter__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
        Vtb_generic_counter___024root____VbeforeTrig_h68df5bc7__0(vlSelf, 
                                                                  "@(posedge tb_generic_counter.clk)");
        co_await vlSelfRef.__VtrigSched_h68df5bc7__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_generic_counter.clk)", 
                                                             "tests/tb_generic_counter.sv", 
                                                             33);
        tb_generic_counter__DOT__unnamedblk1_2__DOT____Vrepeat1 
            = (tb_generic_counter__DOT__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((9U != (IData)(vlSelfRef.tb_generic_counter__DOT__dut__DOT__counter))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_generic_counter.sv:34: Assertion failed in %m: FAIL reached MAX-1 (9)\n",3, 'M',vlSymsp->name(),"tb_generic_counter", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("tests/tb_generic_counter.sv", 34, "", false);
    } else {
        VL_WRITEF_NX("PASS reached MAX-1 (9)\n",0);
    }
    if (VL_LIKELY(((9U == (IData)(vlSelfRef.tb_generic_counter__DOT__dut__DOT__counter))))) {
        VL_WRITEF_NX("PASS ending high at MAX-1\n",0);
    } else {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_generic_counter.sv:35: Assertion failed in %m: FAIL ending high at MAX-1\n",3, 'M',vlSymsp->name(),"tb_generic_counter", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("tests/tb_generic_counter.sv", 35, "", false);
    }
    Vtb_generic_counter___024root____VbeforeTrig_h68df5bc7__0(vlSelf, 
                                                              "@(posedge tb_generic_counter.clk)");
    co_await vlSelfRef.__VtrigSched_h68df5bc7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_generic_counter.clk)", 
                                                         "tests/tb_generic_counter.sv", 
                                                         38);
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.tb_generic_counter__DOT__dut__DOT__counter))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_generic_counter.sv:39: Assertion failed in %m: FAIL wraps to 0\n",3, 'M',vlSymsp->name(),"tb_generic_counter", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("tests/tb_generic_counter.sv", 39, "", false);
    } else {
        VL_WRITEF_NX("PASS wraps to 0\n",0);
    }
    if (VL_UNLIKELY(((9U == (IData)(vlSelfRef.tb_generic_counter__DOT__dut__DOT__counter))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_generic_counter.sv:40: Assertion failed in %m: FAIL ending low after wrap\n",3, 'M',vlSymsp->name(),"tb_generic_counter", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("tests/tb_generic_counter.sv", 40, "", false);
    } else {
        VL_WRITEF_NX("PASS ending low after wrap\n",0);
    }
    VL_WRITEF_NX("--- en gating ---\n",0);
    vlSelfRef.tb_generic_counter__DOT__en = 0U;
    tb_generic_counter__DOT__unnamedblk1_3__DOT____Vrepeat2 = 5U;
    while (VL_LTS_III(32, 0U, tb_generic_counter__DOT__unnamedblk1_3__DOT____Vrepeat2)) {
        Vtb_generic_counter___024root____VbeforeTrig_h68df5bc7__0(vlSelf, 
                                                                  "@(posedge tb_generic_counter.clk)");
        co_await vlSelfRef.__VtrigSched_h68df5bc7__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_generic_counter.clk)", 
                                                             "tests/tb_generic_counter.sv", 
                                                             45);
        tb_generic_counter__DOT__unnamedblk1_3__DOT____Vrepeat2 
            = (tb_generic_counter__DOT__unnamedblk1_3__DOT____Vrepeat2 
               - (IData)(1U));
    }
    if (VL_UNLIKELY(((0U != (IData)(vlSelfRef.tb_generic_counter__DOT__dut__DOT__counter))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_generic_counter.sv:46: Assertion failed in %m: FAIL stays 0 while en=0\n",3, 'M',vlSymsp->name(),"tb_generic_counter", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("tests/tb_generic_counter.sv", 46, "", false);
    } else {
        VL_WRITEF_NX("PASS stays 0 while en=0\n",0);
    }
    vlSelfRef.tb_generic_counter__DOT__en = 1U;
    Vtb_generic_counter___024root____VbeforeTrig_h68df5bc7__0(vlSelf, 
                                                              "@(posedge tb_generic_counter.clk)");
    co_await vlSelfRef.__VtrigSched_h68df5bc7__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_generic_counter.clk)", 
                                                         "tests/tb_generic_counter.sv", 
                                                         47);
    if (VL_UNLIKELY(((1U != (IData)(vlSelfRef.tb_generic_counter__DOT__dut__DOT__counter))))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_generic_counter.sv:48: Assertion failed in %m: FAIL resumes counting when en=1\n",3, 'M',vlSymsp->name(),"tb_generic_counter", 'T',-9
                     , '#',64,VL_TIME_UNITED_Q(1000));
        VL_STOP_MT("tests/tb_generic_counter.sv", 48, "", false);
    } else {
        VL_WRITEF_NX("PASS resumes counting when en=1\n",0);
    }
    VL_WRITEF_NX("=== ALL TESTS PASSED ===\n",0);
    VL_FINISH_MT("tests/tb_generic_counter.sv", 51, "");
    co_return;
}

VlCoroutine Vtb_generic_counter___024root___eval_initial__TOP__Vtiming__1(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000001388ULL, 
                                             nullptr, 
                                             "tests/tb_generic_counter.sv", 
                                             12);
        vlSelfRef.tb_generic_counter__DOT__clk = (1U 
                                                  & (~ (IData)(vlSelfRef.tb_generic_counter__DOT__clk)));
    }
    co_return;
}

void Vtb_generic_counter___024root___eval_triggers_vec__act(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval_triggers_vec__act\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                      << 2U) 
                                                     | ((((~ (IData)(vlSelfRef.tb_generic_counter__DOT__rstn)) 
                                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_generic_counter__DOT__rstn__0)) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.tb_generic_counter__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_generic_counter__DOT__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_generic_counter__DOT__clk__0 
        = vlSelfRef.tb_generic_counter__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_generic_counter__DOT__rstn__0 
        = vlSelfRef.tb_generic_counter__DOT__rstn;
}

bool Vtb_generic_counter___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtb_generic_counter___024root___nba_sequent__TOP__1(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___nba_sequent__TOP__1\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb_generic_counter__DOT__rstn) {
        if (vlSelfRef.tb_generic_counter__DOT__en) {
            vlSelfRef.tb_generic_counter__DOT__dut__DOT__counter 
                = ((9U == (IData)(vlSelfRef.tb_generic_counter__DOT__dut__DOT__counter))
                    ? 0U : (0x0000000fU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.tb_generic_counter__DOT__dut__DOT__counter))));
        }
    } else {
        vlSelfRef.tb_generic_counter__DOT__dut__DOT__counter = 0U;
    }
}

void Vtb_generic_counter___024root__nba_mtask1(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root__nba_mtask1\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Verilated::mtaskId(1);
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_generic_counter___024root___nba_sequent__TOP__1(vlSelf);
    }
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
}

void Vtb_generic_counter___024root____Vthread__nba__s0__t0(void* voidSelf, bool even_cycle);

void Vtb_generic_counter___024root___eval_nba(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval_nba\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->__Vm_even_cycle__nba = !vlSymsp->__Vm_even_cycle__nba;
    Vtb_generic_counter___024root____Vthread__nba__s0__t0(vlSelf, vlSymsp->__Vm_even_cycle__nba);
    vlSelf->__Vm_mtaskstate_final__0nba.waitUntilUpstreamDone(vlSymsp->__Vm_even_cycle__nba);
    Verilated::mtaskId(0);
}

void Vtb_generic_counter___024root___timing_ready(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___timing_ready\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VtrigSched_h68df5bc7__0.ready("@(posedge tb_generic_counter.clk)");
    }
}

void Vtb_generic_counter___024root___timing_resume(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___timing_resume\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VtrigSched_h68df5bc7__0.moveToResumeQueue(
                                                          "@(posedge tb_generic_counter.clk)");
    vlSelfRef.__VtrigSched_h68df5bc7__0.resume("@(posedge tb_generic_counter.clk)");
    if ((4ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_generic_counter___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_generic_counter___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_generic_counter___024root___eval_phase__act(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval_phase__act\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_generic_counter___024root___eval_triggers_vec__act(vlSelf);
    Vtb_generic_counter___024root___timing_ready(vlSelf);
    Vtb_generic_counter___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_generic_counter___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_generic_counter___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_generic_counter___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_generic_counter___024root___timing_resume(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_generic_counter___024root___eval_phase__inact(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval_phase__inact\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tests/tb_generic_counter.sv", 3, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_generic_counter___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_generic_counter___024root___eval_phase__nba(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval_phase__nba\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_generic_counter___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_generic_counter___024root___eval_nba(vlSelf);
        Vtb_generic_counter___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_generic_counter___024root___eval(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_generic_counter___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tests/tb_generic_counter.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("tests/tb_generic_counter.sv", 3, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_generic_counter___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("tests/tb_generic_counter.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_generic_counter___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_generic_counter___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_generic_counter___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

void Vtb_generic_counter___024root____VbeforeTrig_h68df5bc7__0(Vtb_generic_counter___024root* vlSelf, const char* __VeventDescription) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root____VbeforeTrig_h68df5bc7__0\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlUnpacked<QData/*63:0*/, 1> __VTmp;
    // Body
    __VTmp[0U] = (QData)((IData)(((IData)(vlSelfRef.tb_generic_counter__DOT__clk) 
                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_generic_counter__DOT__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_generic_counter__DOT__clk__0 
        = vlSelfRef.tb_generic_counter__DOT__clk;
    if ((1ULL & __VTmp[0U])) {
        vlSelfRef.__VtrigSched_h68df5bc7__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h68df5bc7__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h68df5bc7__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h68df5bc7__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h68df5bc7__0.ready(__VeventDescription);
        vlSelfRef.__VtrigSched_h68df5bc7__0.ready(__VeventDescription);
    }
    vlSelfRef.__VactTriggeredAcc[0U] = (vlSelfRef.__VactTriggeredAcc[0U] 
                                        | __VTmp[0U]);
}

#ifdef VL_DEBUG
void Vtb_generic_counter___024root___eval_debug_assertions(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval_debug_assertions\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG

void Vtb_generic_counter___024root____Vthread__nba__s0__t0(void* voidSelf, bool even_cycle) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root____Vthread__nba__s0__t0\n"); );
    // Body
    Vtb_generic_counter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_generic_counter___024root*>(voidSelf);
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtb_generic_counter___024root__nba_mtask1((&vlSymsp->TOP));
    vlSelf->__Vm_mtaskstate_final__0nba.signalUpstreamDone(even_cycle);
}
