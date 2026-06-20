// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_generic_counter.h for the primary calling header

#include "Vtb_generic_counter__pch.h"

VL_ATTR_COLD void Vtb_generic_counter___024root___eval_static__TOP(Vtb_generic_counter___024root* vlSelf);
void Vtb_generic_counter___024root___timing_ready(Vtb_generic_counter___024root* vlSelf);

VL_ATTR_COLD void Vtb_generic_counter___024root___eval_static(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval_static\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_generic_counter___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_generic_counter__DOT__clk__0 = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_generic_counter__DOT__rstn__0 
        = vlSelfRef.tb_generic_counter__DOT__rstn;
    Vtb_generic_counter___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_generic_counter___024root___eval_static__TOP(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval_static__TOP\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_generic_counter__DOT__clk = 0U;
    vlSelfRef.tb_generic_counter__DOT__dut__DOT__counter = 0U;
}

VL_ATTR_COLD void Vtb_generic_counter___024root___eval_final(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval_final\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtb_generic_counter___024root___eval_settle(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___eval_settle\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vtb_generic_counter___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_generic_counter___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_generic_counter___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_generic_counter.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge tb_generic_counter.rstn)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_generic_counter___024root___ctor_var_reset(Vtb_generic_counter___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_generic_counter___024root___ctor_var_reset\n"); );
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_generic_counter__DOT__rstn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14012024403631486632ull);
    vlSelf->tb_generic_counter__DOT__en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7318460110507431256ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_generic_counter__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_generic_counter__DOT__rstn__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
