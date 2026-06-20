// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_generic_counter.h for the primary calling header

#include "Vtb_generic_counter__pch.h"

void Vtb_generic_counter___024root___ctor_var_reset(Vtb_generic_counter___024root* vlSelf);

Vtb_generic_counter___024root::Vtb_generic_counter___024root(Vtb_generic_counter__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
    , __Vm_mtaskstate_final__0nba(1U)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_generic_counter___024root___ctor_var_reset(this);
}

void Vtb_generic_counter___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_generic_counter___024root::~Vtb_generic_counter___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
