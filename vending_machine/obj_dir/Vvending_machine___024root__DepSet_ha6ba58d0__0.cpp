// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvending_machine.h for the primary calling header

#include "Vvending_machine__pch.h"
#include "Vvending_machine___024root.h"

VL_INLINE_OPT void Vvending_machine___024root___ico_sequent__TOP__0(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->o_output_item = 0U;
    if (((IData)(vlSelf->i_select_item) & (vlSelf->vending_machine__DOT__current_total 
                                           >= vlSelf->vending_machine__DOT__item_price
                                           [0U]))) {
        vlSelf->o_output_item = (1U | (IData)(vlSelf->o_output_item));
    }
    if ((((IData)(vlSelf->i_select_item) >> 1U) & (vlSelf->vending_machine__DOT__current_total 
                                                   >= 
                                                   vlSelf->vending_machine__DOT__item_price
                                                   [1U]))) {
        vlSelf->o_output_item = (2U | (IData)(vlSelf->o_output_item));
    }
    if ((((IData)(vlSelf->i_select_item) >> 2U) & (vlSelf->vending_machine__DOT__current_total 
                                                   >= 
                                                   vlSelf->vending_machine__DOT__item_price
                                                   [2U]))) {
        vlSelf->o_output_item = (4U | (IData)(vlSelf->o_output_item));
    }
    if ((((IData)(vlSelf->i_select_item) >> 3U) & (vlSelf->vending_machine__DOT__current_total 
                                                   >= 
                                                   vlSelf->vending_machine__DOT__item_price
                                                   [3U]))) {
        vlSelf->o_output_item = (8U | (IData)(vlSelf->o_output_item));
    }
    if (((0U == vlSelf->vending_machine__DOT__wait_time) 
         | (IData)(vlSelf->i_trigger_return))) {
        if ((vlSelf->vending_machine__DOT__current_total 
             >= vlSelf->vending_machine__DOT__coin_value
             [2U])) {
            vlSelf->o_return_coin = 4U;
        }
        if (((vlSelf->vending_machine__DOT__current_total 
              - vlSelf->vending_machine__DOT__coin_value
              [2U]) >= vlSelf->vending_machine__DOT__coin_value
             [1U])) {
            vlSelf->o_return_coin = (7U & ((IData)(2U) 
                                           + (IData)(vlSelf->o_return_coin)));
        }
        if ((((vlSelf->vending_machine__DOT__current_total 
               - vlSelf->vending_machine__DOT__coin_value
               [2U]) - vlSelf->vending_machine__DOT__coin_value
              [1U]) >= vlSelf->vending_machine__DOT__coin_value
             [0U])) {
            vlSelf->o_return_coin = (7U & ((IData)(1U) 
                                           + (IData)(vlSelf->o_return_coin)));
        }
    }
    vlSelf->vending_machine__DOT__input_total = 0U;
    vlSelf->vending_machine__DOT__output_total = 0U;
    if (((IData)(vlSelf->i_select_item) & (vlSelf->vending_machine__DOT__current_total 
                                           >= vlSelf->vending_machine__DOT__item_price
                                           [0U]))) {
        vlSelf->vending_machine__DOT__output_total 
            = (vlSelf->vending_machine__DOT__output_total 
               + vlSelf->vending_machine__DOT__item_price
               [0U]);
    }
    vlSelf->vending_machine__DOT__return_total = 0U;
    if ((1U & (IData)(vlSelf->i_input_coin))) {
        vlSelf->vending_machine__DOT__input_total = 
            (vlSelf->vending_machine__DOT__input_total 
             + vlSelf->vending_machine__DOT__coin_value
             [0U]);
    }
    if ((2U & (IData)(vlSelf->i_input_coin))) {
        vlSelf->vending_machine__DOT__input_total = 
            (vlSelf->vending_machine__DOT__input_total 
             + vlSelf->vending_machine__DOT__coin_value
             [1U]);
    }
    if ((4U & (IData)(vlSelf->i_input_coin))) {
        vlSelf->vending_machine__DOT__input_total = 
            (vlSelf->vending_machine__DOT__input_total 
             + vlSelf->vending_machine__DOT__coin_value
             [2U]);
    }
    if ((((IData)(vlSelf->i_select_item) >> 1U) & (
                                                   (vlSelf->vending_machine__DOT__current_total 
                                                    - vlSelf->vending_machine__DOT__output_total) 
                                                   >= 
                                                   vlSelf->vending_machine__DOT__item_price
                                                   [1U]))) {
        vlSelf->vending_machine__DOT__output_total 
            = (vlSelf->vending_machine__DOT__output_total 
               + vlSelf->vending_machine__DOT__item_price
               [1U]);
    }
    if ((((IData)(vlSelf->i_select_item) >> 2U) & (
                                                   (vlSelf->vending_machine__DOT__current_total 
                                                    - vlSelf->vending_machine__DOT__output_total) 
                                                   >= 
                                                   vlSelf->vending_machine__DOT__item_price
                                                   [2U]))) {
        vlSelf->vending_machine__DOT__output_total 
            = (vlSelf->vending_machine__DOT__output_total 
               + vlSelf->vending_machine__DOT__item_price
               [2U]);
    }
    if ((((IData)(vlSelf->i_select_item) >> 3U) & (
                                                   (vlSelf->vending_machine__DOT__current_total 
                                                    - vlSelf->vending_machine__DOT__output_total) 
                                                   >= 
                                                   vlSelf->vending_machine__DOT__item_price
                                                   [3U]))) {
        vlSelf->vending_machine__DOT__output_total 
            = (vlSelf->vending_machine__DOT__output_total 
               + vlSelf->vending_machine__DOT__item_price
               [3U]);
    }
    if ((1U & (IData)(vlSelf->o_return_coin))) {
        vlSelf->vending_machine__DOT__return_total 
            = (vlSelf->vending_machine__DOT__return_total 
               + vlSelf->vending_machine__DOT__coin_value
               [0U]);
    }
    if ((2U & (IData)(vlSelf->o_return_coin))) {
        vlSelf->vending_machine__DOT__return_total 
            = (vlSelf->vending_machine__DOT__return_total 
               + vlSelf->vending_machine__DOT__coin_value
               [1U]);
    }
    if ((4U & (IData)(vlSelf->o_return_coin))) {
        vlSelf->vending_machine__DOT__return_total 
            = (vlSelf->vending_machine__DOT__return_total 
               + vlSelf->vending_machine__DOT__coin_value
               [2U]);
    }
    vlSelf->vending_machine__DOT__current_total_nxt 
        = (((vlSelf->vending_machine__DOT__current_total 
             + vlSelf->vending_machine__DOT__input_total) 
            - vlSelf->vending_machine__DOT__output_total) 
           - vlSelf->vending_machine__DOT__return_total);
}

void Vvending_machine___024root___eval_ico(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vvending_machine___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vvending_machine___024root___eval_triggers__ico(Vvending_machine___024root* vlSelf);

bool Vvending_machine___024root___eval_phase__ico(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vvending_machine___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vvending_machine___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vvending_machine___024root___eval_act(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vvending_machine___024root___nba_sequent__TOP__0(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__vending_machine__DOT__wait_time 
        = vlSelf->vending_machine__DOT__wait_time;
}

VL_INLINE_OPT void Vvending_machine___024root___nba_sequent__TOP__1(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___nba_sequent__TOP__1\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->reset_n)))) {
        vlSelf->__Vdly__vending_machine__DOT__wait_time = 0U;
    }
    vlSelf->__Vdly__vending_machine__DOT__wait_time 
        = ((0U == vlSelf->vending_machine__DOT__wait_time)
            ? 0U : (vlSelf->vending_machine__DOT__wait_time 
                    - (IData)(1U)));
    vlSelf->vending_machine__DOT__current_total = ((IData)(vlSelf->reset_n)
                                                    ? vlSelf->vending_machine__DOT__current_total_nxt
                                                    : 0U);
    vlSelf->o_available_item = 0U;
    if ((vlSelf->vending_machine__DOT__current_total 
         >= vlSelf->vending_machine__DOT__item_price
         [0U])) {
        vlSelf->o_available_item = (1U | (IData)(vlSelf->o_available_item));
    }
    if ((vlSelf->vending_machine__DOT__current_total 
         >= vlSelf->vending_machine__DOT__item_price
         [1U])) {
        vlSelf->o_available_item = (2U | (IData)(vlSelf->o_available_item));
    }
    if ((vlSelf->vending_machine__DOT__current_total 
         >= vlSelf->vending_machine__DOT__item_price
         [2U])) {
        vlSelf->o_available_item = (4U | (IData)(vlSelf->o_available_item));
    }
    if ((vlSelf->vending_machine__DOT__current_total 
         >= vlSelf->vending_machine__DOT__item_price
         [3U])) {
        vlSelf->o_available_item = (8U | (IData)(vlSelf->o_available_item));
    }
}

VL_INLINE_OPT void Vvending_machine___024root___nba_sequent__TOP__2(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___nba_sequent__TOP__2\n"); );
    // Body
    if (((0U != (IData)(vlSelf->i_input_coin)) | (0U 
                                                  != (IData)(vlSelf->o_output_item)))) {
        vlSelf->__Vdly__vending_machine__DOT__wait_time = 0U;
    }
}

VL_INLINE_OPT void Vvending_machine___024root___nba_sequent__TOP__3(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->o_output_item = 0U;
    if (((IData)(vlSelf->i_select_item) & (vlSelf->vending_machine__DOT__current_total 
                                           >= vlSelf->vending_machine__DOT__item_price
                                           [0U]))) {
        vlSelf->o_output_item = (1U | (IData)(vlSelf->o_output_item));
    }
    if ((((IData)(vlSelf->i_select_item) >> 1U) & (vlSelf->vending_machine__DOT__current_total 
                                                   >= 
                                                   vlSelf->vending_machine__DOT__item_price
                                                   [1U]))) {
        vlSelf->o_output_item = (2U | (IData)(vlSelf->o_output_item));
    }
    if ((((IData)(vlSelf->i_select_item) >> 2U) & (vlSelf->vending_machine__DOT__current_total 
                                                   >= 
                                                   vlSelf->vending_machine__DOT__item_price
                                                   [2U]))) {
        vlSelf->o_output_item = (4U | (IData)(vlSelf->o_output_item));
    }
    if ((((IData)(vlSelf->i_select_item) >> 3U) & (vlSelf->vending_machine__DOT__current_total 
                                                   >= 
                                                   vlSelf->vending_machine__DOT__item_price
                                                   [3U]))) {
        vlSelf->o_output_item = (8U | (IData)(vlSelf->o_output_item));
    }
}

VL_INLINE_OPT void Vvending_machine___024root___nba_sequent__TOP__4(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___nba_sequent__TOP__4\n"); );
    // Body
    vlSelf->vending_machine__DOT__wait_time = vlSelf->__Vdly__vending_machine__DOT__wait_time;
}

VL_INLINE_OPT void Vvending_machine___024root___nba_comb__TOP__0(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___nba_comb__TOP__0\n"); );
    // Body
    if (((0U == vlSelf->vending_machine__DOT__wait_time) 
         | (IData)(vlSelf->i_trigger_return))) {
        if ((vlSelf->vending_machine__DOT__current_total 
             >= vlSelf->vending_machine__DOT__coin_value
             [2U])) {
            vlSelf->o_return_coin = 4U;
        }
        if (((vlSelf->vending_machine__DOT__current_total 
              - vlSelf->vending_machine__DOT__coin_value
              [2U]) >= vlSelf->vending_machine__DOT__coin_value
             [1U])) {
            vlSelf->o_return_coin = (7U & ((IData)(2U) 
                                           + (IData)(vlSelf->o_return_coin)));
        }
        if ((((vlSelf->vending_machine__DOT__current_total 
               - vlSelf->vending_machine__DOT__coin_value
               [2U]) - vlSelf->vending_machine__DOT__coin_value
              [1U]) >= vlSelf->vending_machine__DOT__coin_value
             [0U])) {
            vlSelf->o_return_coin = (7U & ((IData)(1U) 
                                           + (IData)(vlSelf->o_return_coin)));
        }
    }
    vlSelf->vending_machine__DOT__input_total = 0U;
    vlSelf->vending_machine__DOT__output_total = 0U;
    vlSelf->vending_machine__DOT__return_total = 0U;
    if ((1U & (IData)(vlSelf->i_input_coin))) {
        vlSelf->vending_machine__DOT__input_total = 
            (vlSelf->vending_machine__DOT__input_total 
             + vlSelf->vending_machine__DOT__coin_value
             [0U]);
    }
    if ((2U & (IData)(vlSelf->i_input_coin))) {
        vlSelf->vending_machine__DOT__input_total = 
            (vlSelf->vending_machine__DOT__input_total 
             + vlSelf->vending_machine__DOT__coin_value
             [1U]);
    }
    if ((4U & (IData)(vlSelf->i_input_coin))) {
        vlSelf->vending_machine__DOT__input_total = 
            (vlSelf->vending_machine__DOT__input_total 
             + vlSelf->vending_machine__DOT__coin_value
             [2U]);
    }
    if (((IData)(vlSelf->i_select_item) & (vlSelf->vending_machine__DOT__current_total 
                                           >= vlSelf->vending_machine__DOT__item_price
                                           [0U]))) {
        vlSelf->vending_machine__DOT__output_total 
            = (vlSelf->vending_machine__DOT__output_total 
               + vlSelf->vending_machine__DOT__item_price
               [0U]);
    }
    if ((((IData)(vlSelf->i_select_item) >> 1U) & (
                                                   (vlSelf->vending_machine__DOT__current_total 
                                                    - vlSelf->vending_machine__DOT__output_total) 
                                                   >= 
                                                   vlSelf->vending_machine__DOT__item_price
                                                   [1U]))) {
        vlSelf->vending_machine__DOT__output_total 
            = (vlSelf->vending_machine__DOT__output_total 
               + vlSelf->vending_machine__DOT__item_price
               [1U]);
    }
    if ((((IData)(vlSelf->i_select_item) >> 2U) & (
                                                   (vlSelf->vending_machine__DOT__current_total 
                                                    - vlSelf->vending_machine__DOT__output_total) 
                                                   >= 
                                                   vlSelf->vending_machine__DOT__item_price
                                                   [2U]))) {
        vlSelf->vending_machine__DOT__output_total 
            = (vlSelf->vending_machine__DOT__output_total 
               + vlSelf->vending_machine__DOT__item_price
               [2U]);
    }
    if ((((IData)(vlSelf->i_select_item) >> 3U) & (
                                                   (vlSelf->vending_machine__DOT__current_total 
                                                    - vlSelf->vending_machine__DOT__output_total) 
                                                   >= 
                                                   vlSelf->vending_machine__DOT__item_price
                                                   [3U]))) {
        vlSelf->vending_machine__DOT__output_total 
            = (vlSelf->vending_machine__DOT__output_total 
               + vlSelf->vending_machine__DOT__item_price
               [3U]);
    }
    if ((1U & (IData)(vlSelf->o_return_coin))) {
        vlSelf->vending_machine__DOT__return_total 
            = (vlSelf->vending_machine__DOT__return_total 
               + vlSelf->vending_machine__DOT__coin_value
               [0U]);
    }
    if ((2U & (IData)(vlSelf->o_return_coin))) {
        vlSelf->vending_machine__DOT__return_total 
            = (vlSelf->vending_machine__DOT__return_total 
               + vlSelf->vending_machine__DOT__coin_value
               [1U]);
    }
    if ((4U & (IData)(vlSelf->o_return_coin))) {
        vlSelf->vending_machine__DOT__return_total 
            = (vlSelf->vending_machine__DOT__return_total 
               + vlSelf->vending_machine__DOT__coin_value
               [2U]);
    }
    vlSelf->vending_machine__DOT__current_total_nxt 
        = (((vlSelf->vending_machine__DOT__current_total 
             + vlSelf->vending_machine__DOT__input_total) 
            - vlSelf->vending_machine__DOT__output_total) 
           - vlSelf->vending_machine__DOT__return_total);
}

void Vvending_machine___024root___eval_nba(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___eval_nba\n"); );
    // Body
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vvending_machine___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vvending_machine___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vvending_machine___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vvending_machine___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vvending_machine___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((6ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vvending_machine___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vvending_machine___024root___eval_triggers__act(Vvending_machine___024root* vlSelf);

bool Vvending_machine___024root___eval_phase__act(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vvending_machine___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vvending_machine___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vvending_machine___024root___eval_phase__nba(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vvending_machine___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvending_machine___024root___dump_triggers__ico(Vvending_machine___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vvending_machine___024root___dump_triggers__nba(Vvending_machine___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vvending_machine___024root___dump_triggers__act(Vvending_machine___024root* vlSelf);
#endif  // VL_DEBUG

void Vvending_machine___024root___eval(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vvending_machine___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("vending_machine.v", 9, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vvending_machine___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vvending_machine___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("vending_machine.v", 9, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vvending_machine___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("vending_machine.v", 9, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vvending_machine___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vvending_machine___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vvending_machine___024root___eval_debug_assertions(Vvending_machine___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vvending_machine__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvending_machine___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset_n & 0xfeU))) {
        Verilated::overWidthError("reset_n");}
    if (VL_UNLIKELY((vlSelf->i_input_coin & 0xf8U))) {
        Verilated::overWidthError("i_input_coin");}
    if (VL_UNLIKELY((vlSelf->i_select_item & 0xf0U))) {
        Verilated::overWidthError("i_select_item");}
    if (VL_UNLIKELY((vlSelf->i_trigger_return & 0xfeU))) {
        Verilated::overWidthError("i_trigger_return");}
}
#endif  // VL_DEBUG
