/* Copyright 2020 Andrew Kannan
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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_GAMING] = LAYOUT_all(
    QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSPC,  KC_PGUP,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,            KC_PGDN,
    SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, R_SHIFT,  KC_UP,             ADJUST,
    KC_LCTL, KC_LALT, KC_LGUI,          SPC_RSE, SPC_RSE,          KC_RGUI, KC_RGUI, KC_RALT,          KC_LEFT,  KC_DOWN, KC_RIGHT
  ),

  [_QWERTY_MAC] = LAYOUT_all(
    QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, BPC_MEH,  KC_PGUP,
    TAB_CTL, A_MOUSE, KC_S,    M_NAV,   F_NAV_2, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,            KC_PGDN,
    SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, R_SHIFT,  KC_UP,             ADJUST,
    KC_HYPR, KC_LALT, KC_LGUI,          SPC_RSE, SPC_RSE,          KC_RGUI, KC_RGUI, KC_RALT,          KC_LEFT,  KC_DOWN, KC_RIGHT
  ),

  [_MAC_NAV] = LAYOUT_all(
    _______, xxxxxxx, M_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, M_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, M_PUT,   xxxxxxx, xxxxxxx, _______, _______,
    _______, A_SHIFT, S_SHIFT, xxxxxxx, NAV_2,   xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx, _______,          _______,
    _______, xxxxxxx, M_DEL,   xxxxxxx, xxxxxxx, M_B_WRD, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, _______, _______,          _______,
    _______, _______, _______, xxxxxxx, xxxxxxx, _______, _______, _______,                            _______, _______, _______
  ),

  [_QWERTY_LINUX] = LAYOUT_all(
    QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, BPC_MEH,  KC_PGUP,
    TAB_CTL, A_MOUSE, KC_S,    L_NAV,   F_NAV_2, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,            KC_PGDN,
    SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, R_SHIFT,  KC_UP,             ADJUST,
    KC_HYPR, KC_LGUI, KC_LALT,          SPC_RSE, SPC_RSE,          KC_RALT, KC_RALT, KC_RGUI,          KC_LEFT,  KC_DOWN, KC_RIGHT
  ),

  [_LINUX_NAV] = LAYOUT_all(
    _______, xxxxxxx, L_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, L_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, L_PUT,   xxxxxxx, xxxxxxx, _______, _______,
    _______, A_SHIFT, S_SHIFT, xxxxxxx, NAV_2,   xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx, _______,          _______,
    _______, xxxxxxx, L_DEL,   xxxxxxx, xxxxxxx, L_B_WRD, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, _______, _______,          _______,
    _______, _______, _______, xxxxxxx, xxxxxxx, _______, _______, _______,                            _______, _______, _______
  ),

  [_QWERTY_WIN] = LAYOUT_all(
    QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSPC,  KC_PGUP,
    TAB_CTL, KC_A,    KC_S,    W_NAV,   F_NAV_2, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,            KC_PGDN,
    SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_UP,             ADJUST,
    KC_LCTL, KC_LGUI, KC_LALT,          SPC_RSE, SPC_RSE,          KC_RALT, KC_RALT, KC_RGUI,          KC_LEFT,  KC_DOWN, KC_RIGHT
  ),

  [_WIN_NAV] = LAYOUT_all(
    _______, xxxxxxx, W_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, W_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, W_PUT,   xxxxxxx, xxxxxxx, _______, _______,
    _______, A_SHIFT, S_SHIFT, xxxxxxx, NAV_2,   xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx, _______,          _______,
    _______, xxxxxxx, W_DEL,   xxxxxxx, xxxxxxx, W_B_WRD, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, _______, _______,          _______,
    _______, _______, _______, xxxxxxx, xxxxxxx, _______, _______, _______,                            _______, _______, _______
  ),

  [_NAV_2] = LAYOUT_all(
    _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,
    _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, xxxxxxx, _______,          _______,
    _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,          _______,
    _______, _______, _______, xxxxxxx, xxxxxxx, _______, _______, _______,                            _______, _______, _______
  ),

  [_RAISE] = LAYOUT_all(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_DEL,  _______,
    KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           _______,
    _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______,          _______,
    _______, _______, _______, xxxxxxx, xxxxxxx, _______, _______, _______,                            _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_all(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
    QK_BOOT, DF_M_P,  DF_L_P,  DF_W_P,  DF_G_P,  KC_GLB,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, xxxxxxx, xxxxxxx, xxxxxxx,          _______,
    _______, DF_MAC,  DF_LNX,  DF_WIN,  DF_GMG,  xxxxxxx, xxxxxxx, KC_MUTE, xxxxxxx, xxxxxxx, xxxxxxx, KC_MPLY, KC_VOLU,          _______,
    _______, _______, _______, KC_MPLY, KC_MPLY, _______, _______, _______,                            KC_MPRV, KC_VOLD, KC_MNXT
  ),

  [_MOUSE] = LAYOUT_all(
    _______, MS_BTN1, MS_BTN2, MS_BTN3, MS_BTN4, MS_BTN5, MS_BTN6, MS_BTN7, MS_BTN8, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, MS_WHLU,
    _______, xxxxxxx, MS_ACL2, MS_ACL1, MS_ACL0, MS_BTN2, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, xxxxxxx, xxxxxxx, _______,          MS_WHLD,
    _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, xxxxxxx, KC_RSFT, MS_UP,            ADJUST,
    _______, _______, _______, MS_BTN1, MS_BTN1, _______, _______, _______,                            MS_LEFT, MS_DOWN, MS_RGHT
  ),

  [_EX_MOUSE] = LAYOUT_all(
    _______, MS_BTN1, MS_BTN2, MS_BTN3, MS_BTN4, MS_BTN5, MS_BTN6, MS_BTN7, MS_BTN8, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, MS_WHLU,
    _______, xxxxxxx, MS_ACL2, MS_ACL1, MS_ACL0, MS_BTN2, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, xxxxxxx, xxxxxxx, _______,          MS_WHLD,
    TG_MSE,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, xxxxxxx, KC_RSFT, MS_UP,            ADJUST,
    _______, _______, _______, MS_BTN1, MS_BTN1, _______, _______, _______,                            MS_LEFT, MS_DOWN, MS_RGHT
  ),

};
// clang-format on
