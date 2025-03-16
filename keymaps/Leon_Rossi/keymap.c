//New! Keyboard shortcuts … Drive keyboard shortcuts have been updated to give you first-letters navigation
// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap_swiss_de.h"
#include "sendstring_swiss_de.h"


enum {
    Base = 0,
    Numbers,
    AeOeUe,
    Arrows,
    Symbols,
    Gaming,
};

const key_override_t tab_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPACE, KC_TAB);
const key_override_t escape_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_ENT, KC_ESC);

const key_override_t controlZ_key_override = ko_make_basic(MOD_MASK_CTRL, CH_Y, LCTL(CH_Z));

const key_override_t capitalAe_key_override = ko_make_basic(MOD_MASK_SHIFT, CH_ADIA, LCTL(CH_Z));

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &escape_key_override,
    &controlZ_key_override,

    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [Base] = LAYOUT_split_3x6_3(
        KC_ESC,  CH_Q,    CH_W,    CH_E,    CH_R,    CH_T,                               CH_Z,    CH_U,    CH_I,    CH_O,    CH_P,    TG(5),
        KC_NO, CH_A,    CH_S,    LALT_T(CH_D),    LCTL_T(CH_F),    CH_G,                               CH_H,    LCTL_T(CH_J),    LALT_T(CH_K),    CH_L,    CH_SCLN, KC_NO,
        KC_NO, CH_Y,    CH_X,    CH_C,    CH_V,    CH_B,                               CH_N,    CH_M,    CH_COMM, CH_DOT,  CH_SLSH, KC_NO,
                                            TT(1), KC_LEFT_SHIFT, KC_BACKSPACE,           TT(4),  KC_SPACE,  KC_ENT
    ),

    [Numbers] = LAYOUT_split_3x6_3(
        KC_NO,  CH_UNDS,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                               KC_NO,   CH_COLN,  CH_PIPE,   KC_NO,    KC_NO,    KC_NO,
        KC_NO, CH_1,    CH_2,    LALT_T(CH_3),    LCTL_T(CH_4),    CH_5,                               CH_6,    LCTL_T(CH_7),    LALT_T(CH_8),    CH_9,    CH_0, KC_NO,
        uC_NO, CH_PLUS,    CH_MINS,    CH_ASTR,    CH_SLSH,    CH_EQL,                               CH_QUES,    CH_EXLM,    CH_COMM, CH_DOT,  KC_NO, KC_NO,
                                            TO(0), KC_LEFT_SHIFT, KC_BACKSPACE,           KC_TAB,  KC_SPACE,  KC_ENT
    ),

    [Arrows] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                               CH_AT,    CH_HASH,    CH_AMPR,    CH_PERC,  KC_NO, KC_NO,
        KC_NO, KC_NO,    KC_TAB,    KC_TRANSPARENT,    KC_TRANSPARENT,    KC_NO,                               KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,  KC_TAB, KC_NO,
        KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                               KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO, KC_NO,
                                            KC_NO, KC_LEFT_SHIFT, KC_LEFT_CTRL,           KC_LEFT_ALT,  KC_SPACE,  KC_RALT
    ),

    [AeOeUe] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                               KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO, KC_NO,
        KC_NO, CH_DQUO,    CH_UDIA,    CH_ODIA,    CH_ADIA,    KC_NO,                               KC_NO,    KC_TRANSPARENT,    KC_TRANSPARENT,    KC_NO,  KC_NO, KC_NO,
        KC_NO, KC_NO,    KC_NO,    KC_DOWN,    KC_NO,    KC_NO,                               KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO, KC_TRANSPARENT,
                                            TO(0), KC_LEFT_SHIFT, KC_LEFT_CTRL,           KC_LEFT_ALT,  KC_SPACE,  KC_RALT
    ),

    [Symbols] = LAYOUT_split_3x6_3(
        KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                               KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
        KC_NO, CH_LABK,    CH_LBRC,    CH_LCBR,    CH_LPRN, CH_DQUO,                                  CH_QUOT,  CH_RPRN,    CH_RCBR,    CH_RBRC,    CH_RABK, KC_NO,
        KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                               KC_NO,    KC_NO,    KC_NO, KC_NO,  KC_NO, KC_NO,
                                            KC_TAB, KC_LEFT_SHIFT, KC_LEFT_CTRL,           TO(0),  KC_SPACE,  KC_NO
    ),

    [Gaming] = LAYOUT_split_3x6_3(
        KC_ESC,  CH_Q,    CH_W,    CH_E,    CH_R,    CH_T,                               CH_Z,    CH_U,    CH_I,    CH_O,    CH_P,    KC_TRANSPARENT,
        KC_TAB, CH_A,    CH_S,    CH_D,    CH_F,    CH_G,                               CH_H,    CH_J,    CH_K,    CH_L,    CH_SCLN, KC_NO,
        TT(4), CH_Y,    CH_X,    CH_C,    CH_V,    CH_B,                               CH_N,    CH_M,    CH_COMM, CH_DOT,  CH_SLSH, KC_NO,
                                            KC_ENT, KC_LEFT_SHIFT, KC_SPACE,           KC_LEFT_ALT,  KC_LEFT_CTRL,  KC_ENT
    ),
};

enum combos {
  //Layers (Arrows/AeOeUe)
    D_F_LAYER,
    J_K_LAYER,
  //GUI
    S_D_LAYER,
    K_L_LAYER,

    COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;
    const uint16_t PROGMEM d_f_layer[] = { LALT_T(CH_D), LCTL_T(CH_F), COMBO_END};
    const uint16_t PROGMEM j_k_layer[] = { LCTL_T(CH_J), LALT_T(CH_K), COMBO_END};

    const uint16_t PROGMEM s_d_layer[] = { CH_S, LALT_T(CH_D), COMBO_END};
    const uint16_t PROGMEM k_l_layer[] = { LALT_T(CH_K), CH_L, COMBO_END};

combo_t key_combos[] = {
    //Layers (Arrows/ÄÖÜ)
    [J_K_LAYER] = COMBO(j_k_layer, TT(2)),
    [D_F_LAYER] = COMBO(d_f_layer, TT(3)),
    //GUI
    [S_D_LAYER] = COMBO(s_d_layer, KC_LEFT_GUI),
    [K_L_LAYER] = COMBO(k_l_layer, KC_LEFT_GUI)
};
