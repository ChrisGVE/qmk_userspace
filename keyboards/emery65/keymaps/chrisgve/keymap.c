/* Copyright 2021 Yiancar-Designs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "chrisgve.h"

#ifdef CAPS_WORD_ENABLE
  #ifdef COMBO_ENABLE
const uint16_t PROGMEM word_caps_gui[] = {KC_LGUI, KC_RGUI, COMBO_END};
const uint16_t PROGMEM word_caps_alt[] = {KC_LALT, KC_RALT, COMBO_END};
combo_t                key_combos[]    = {
    COMBO(word_caps_gui, QK_CAPS_WORD_TOGGLE),
    COMBO(word_caps_alt, QK_CAPS_WORD_TOGGLE),
};
  #endif
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_GAMING] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        KC_ESC,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_HOME,
        KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGUP,
        KC_LCTL, KC_A,    KC_S,   KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,            END_ADJ,
        KC_LCTL, KC_LALT, KC_LGUI,                           KC_SPC,                                               KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_QWERTY_MAC] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        ESC_GLB, KC_1,    KC_2,   KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, GRV_MEH, KC_HOME,
        TAB_HYP, KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGUP,
        KC_LCTL, A_MOUSE, KC_S,   M_NAV_1, M_F_NAV, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        SFT_MSE,          KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, R_SHIFT, KC_UP,            END_ADJ,
        KC_GLB,  KC_LALT, KC_LGUI,                           SPC_RSE,                                              KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_MAC_NAV_1] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,
        _______, xxxxxxx, M_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, M_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, M_PUT,   xxxxxxx, xxxxxxx, _______,          _______,
        _______, xxxxxxx, S_SHIFT, xxxxxxx, M_NAV_2, xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          _______,          _______,
        _______,          xxxxxxx, M_DEL,   xxxxxxx, xxxxxxx, M_B_WRD, KC_HOME, KC_END,  xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,          _______,
        _______, _______, _______,                            xxxxxxx,                                              _______, _______, _______, _______
    ),

    [_MAC_NAV_2] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,          _______,
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, xxxxxxx,          _______,          _______,
        _______,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,          _______,
        _______, _______, _______,                            xxxxxxx,                                              _______, _______, _______, _______
    ),

    [_QWERTY_LINUX] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        KC_ESC,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, GRV_MEH, KC_HOME,
        TAB_HYP, KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGUP,
        KC_LCTL, A_MOUSE, KC_S,   L_NAV_1, L_F_NAV, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        SFT_MSE,          KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, R_SHIFT, KC_UP,            END_ADJ,
        KC_LCTL, KC_LGUI, KC_LALT,                           SPC_RSE,                                              KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_LINUX_NAV_1] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,
        _______, xxxxxxx, L_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, L_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, L_PUT,   xxxxxxx, xxxxxxx, _______,          _______,
        _______, xxxxxxx, S_SHIFT, xxxxxxx, L_NAV_2, xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          _______,          _______,
        _______,          xxxxxxx, L_DEL,   xxxxxxx, xxxxxxx, L_B_WRD, KC_HOME, KC_END,  xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,          _______,
        _______, _______, _______,                            xxxxxxx,                                              _______, _______, _______, _______
    ),

    [_LINUX_NAV_2] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,          _______,
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, xxxxxxx,          _______,          _______,
        _______,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,          _______,
        _______, _______, _______,                            xxxxxxx,                                              _______, _______, _______, _______
    ),

    [_QWERTY_WIN] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        KC_ESC,  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_HOME,
        KC_TAB,  KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGUP,
        KC_LCTL, KC_A,    KC_S,   W_NAV_1, W_F_NAV, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        SFT_MSE,          KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,            END_ADJ,
        KC_LCTL, KC_LGUI, KC_LALT,                           SPC_RSE,                                              KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_WIN_NAV_1] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,
        _______, xxxxxxx, W_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, W_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, W_PUT,   xxxxxxx, xxxxxxx, _______,          _______,
        _______, xxxxxxx, S_SHIFT, xxxxxxx, W_NAV_2, xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          _______,          _______,
        _______,          xxxxxxx, W_DEL,   xxxxxxx, xxxxxxx, W_B_WRD, KC_HOME, KC_END,  xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,          _______,
        _______, _______, _______,                            xxxxxxx,                                              _______, _______, _______, _______
    ),

    [_WIN_NAV_2] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,          _______,
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, xxxxxxx,          _______,          _______,
        _______,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,          _______,
        _______, _______, _______,                            xxxxxxx,                                              _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  xxxxxxx, _______, _______,
        xxxxxxx, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_DEL,           _______,
        KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,          KC_EQL,           _______,
        _______,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,          _______,
        _______, _______, _______,                            xxxxxxx,                                              _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  xxxxxxx, _______, _______,
        QK_BOOT, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, WM_UP,   xxxxxxx, KC_DEL,           _______,
        KC_CAPS, DF_M_P,  DF_L_P,  DF_W_P,  DF_G_P,  KC_GLB,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, WM_LEFT, WM_RGHT,          xxxxxxx,          _______,
        _______,          DF_MAC,  DF_LNX,  DF_WIN,  DF_GMG,  xxxxxxx, KC_MUTE, xxxxxxx, xxxxxxx, xxxxxxx, WM_DOWN, KC_MPLY, KC_VOLU,          _______,
        _______, _______, _______,                            KC_MPLY,                                              _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),

    [_MOUSE] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_MEH,  xxxxxxx,
        KC_HYPR, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,          KC_WH_U,
        _______, xxxxxxx, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, xxxxxxx, xxxxxxx,          _______,          KC_WH_D,
        _______,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_WH_U, KC_WH_D, xxxxxxx, xxxxxxx, xxxxxxx, KC_RSFT, KC_MS_U,          ADJUST,
        _______, _______, _______,                            KC_BTN1,                                              _______, KC_MS_L, KC_MS_D, KC_MS_R
    ),

    [_EX_MOUSE] = LAYOUT_65_ansi_blocker_tsangan_split_bs(
        _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_MEH,  xxxxxxx,
        KC_HYPR, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,          KC_WH_U,
        _______, xxxxxxx, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, xxxxxxx, xxxxxxx,          _______,          KC_WH_D,
        TG_MSE,           xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_WH_U, KC_WH_D, xxxxxxx, xxxxxxx, xxxxxxx, KC_RSFT, KC_MS_U,          ADJUST,
        _______, _______, _______,                            KC_BTN1,                                              _______, KC_MS_L, KC_MS_D, KC_MS_R
    ),

};
// clang-format on
