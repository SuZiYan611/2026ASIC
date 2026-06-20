// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_generic_counter__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vtb_generic_counter::Vtb_generic_counter(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_generic_counter__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtb_generic_counter::Vtb_generic_counter(const char* _vcname__)
    : Vtb_generic_counter(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_generic_counter::~Vtb_generic_counter() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_generic_counter___024root___eval_debug_assertions(Vtb_generic_counter___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_generic_counter___024root___eval_static(Vtb_generic_counter___024root* vlSelf);
void Vtb_generic_counter___024root___eval_initial(Vtb_generic_counter___024root* vlSelf);
void Vtb_generic_counter___024root___eval_settle(Vtb_generic_counter___024root* vlSelf);
void Vtb_generic_counter___024root___eval(Vtb_generic_counter___024root* vlSelf);

void Vtb_generic_counter::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_generic_counter::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_generic_counter___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_generic_counter___024root___eval_static(&(vlSymsp->TOP));
        Vtb_generic_counter___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_generic_counter___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_generic_counter___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_generic_counter::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_generic_counter::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_generic_counter::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_generic_counter___024root___eval_final(Vtb_generic_counter___024root* vlSelf);

VL_ATTR_COLD void Vtb_generic_counter::final() {
    contextp()->executingFinal(true);
    Vtb_generic_counter___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_generic_counter::hierName() const { return vlSymsp->name(); }
const char* Vtb_generic_counter::modelName() const { return "Vtb_generic_counter"; }
unsigned Vtb_generic_counter::threads() const { return 4; }
void Vtb_generic_counter::prepareClone() const { contextp()->prepareClone(); }
void Vtb_generic_counter::atClone() const {
    vlSymsp->__Vm_threadPoolp = static_cast<VlThreadPool*>(contextp()->threadPoolpOnClone());
}
std::unique_ptr<VerilatedTraceConfig> Vtb_generic_counter::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vtb_generic_counter___024root__trace_decl_types(VerilatedFst* tracep);

void Vtb_generic_counter___024root__trace_init_top(Vtb_generic_counter___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtb_generic_counter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_generic_counter___024root*>(voidSelf);
    Vtb_generic_counter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vtb_generic_counter___024root__trace_decl_types(tracep);
    Vtb_generic_counter___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_generic_counter___024root__trace_register(Vtb_generic_counter___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vtb_generic_counter::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_generic_counter::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 8);
    Vtb_generic_counter___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
