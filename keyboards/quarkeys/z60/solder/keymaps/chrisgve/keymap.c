/*
/ Copyright 2022 quarkeys
/ This program is free software: you can redistribute it and/or modify
/ it under the terms of the GNU General Public License as published by
/ the Free Software Foundation, either version 2 of the License, or
/ (at your option) any later version.
/ This program is distributed in the hope that it will be useful,
/ but WITHOUT ANY WARRANTY; without even the implied warranty of
/ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
/ GNU General Public License for more details.
/ You should have received a copy of the GNU General Public License
/ along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "chrisgve.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* [0]
     * ,--------------------------------------------------------------------------------------------------------.
     * | Esc  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  -   |  +   | Back | Del  |
	 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab     |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |  {   |  }   |   \      |
     * |---------+------+------+------+------+------+------+------+------+------+------+------+------+----------|
     * | Capslock   |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |  "   |  ~   | Enter |
     * |------------+------+------+------+------+------|------+------+------+------+------+------+--------------|
     * | SHIFT  |  \   |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |   Shift   |  Fn  |
     * |--------+------+------+------+------+------+------+------+------+------+------+------+-----------+------|
     * | Ctrl   |  Win   |  ALT   |                  SPACE                     |  ALT  |  Win  |  Manu |  Ctrl  |
     * `--------+--------+--------+--------------------------------------------+-------+-------+-------+--------'
     */
	[_GAMING] = LAYOUT_60_tsangan_hhkb(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, ADJUST,
		xxxxxxx, KC_LALT, KC_LGUI,                            KC_SPC,                                               KC_RGUI, KC_RALT, xxxxxxx
    ),

	[_QWERTY_MAC] = LAYOUT_60_tsangan_hhkb(
		ESC_GLB, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, GRV_MEH,
		TAB_HYP, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
		KC_LCTL, A_MOUSE, KC_S,    M_NAV,   F_NAV_2, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
		SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          R_SHIFT, ADJUST,
		xxxxxxx, KC_LALT, KC_LGUI,                            SPC_RSE,                                              KC_RGUI, KC_RALT, xxxxxxx
    ),

	[_MAC_NAV] = LAYOUT_60_tsangan_hhkb(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
		_______, xxxxxxx, M_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, M_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, M_PUT,   xxxxxxx, xxxxxxx, _______,
		_______, A_SHIFT, S_SHIFT, xxxxxxx, NAV_2,   xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          xxxxxxx,
		_______, xxxxxxx, M_DEL,   xxxxxxx, xxxxxxx, M_B_WRD, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx,          _______, _______,
		xxxxxxx, _______, _______,                            xxxxxxx,                                              _______, _______, xxxxxxx
    ),

	[_QWERTY_LINUX] = LAYOUT_60_tsangan_hhkb(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, GRV_MEH,
		TAB_HYP, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
		KC_LCTL, A_MOUSE, KC_S,    L_NAV,   F_NAV_2, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
		SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          R_SHIFT, ADJUST,
		xxxxxxx, KC_LGUI, KC_LALT,                            SPC_RSE,                                              KC_RALT, KC_RGUI, xxxxxxx
    ),

	[_LINUX_NAV] = LAYOUT_60_tsangan_hhkb(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
		_______, xxxxxxx, L_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, L_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, L_PUT,   xxxxxxx, xxxxxxx, _______,
		_______, A_SHIFT, S_SHIFT, xxxxxxx, NAV_2,   xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          xxxxxxx,
		_______, xxxxxxx, L_DEL,   xxxxxxx, xxxxxxx, L_B_WRD, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx,          _______, _______,
		xxxxxxx, _______, _______,                            xxxxxxx,                                              _______, _______, xxxxxxx
    ),

	[_QWERTY_WIN] = LAYOUT_60_tsangan_hhkb(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
		TAB_HYP, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
		KC_LCTL, KC_A,    KC_S,    W_NAV,   F_NAV_2, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
		SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, ADJUST,
		xxxxxxx, KC_LGUI, KC_LALT,                            SPC_RSE,                                              KC_RALT, KC_RGUI, xxxxxxx
    ),

	[_WIN_NAV] = LAYOUT_60_tsangan_hhkb(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
		_______, xxxxxxx, W_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, W_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, W_PUT,   xxxxxxx, xxxxxxx, _______,
		_______, A_SHIFT, S_SHIFT, xxxxxxx, NAV_2,   xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          xxxxxxx,
		_______, xxxxxxx, W_DEL,   xxxxxxx, xxxxxxx, W_B_WRD, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx,          _______, _______,
		xxxxxxx, _______, _______,                            xxxxxxx,                                              _______, _______, xxxxxxx
    ),

	[_NAV_2] = LAYOUT_60_tsangan_hhkb(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, xxxxxxx,          xxxxxxx,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          _______, _______,
		xxxxxxx, _______, _______,                            xxxxxxx,                                              _______, _______, xxxxxxx
    ),

	[_RAISE] = LAYOUT_60_tsangan_hhkb(
		xxxxxxx, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  xxxxxxx, xxxxxxx,
		xxxxxxx, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_DEL,
		KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,          KC_EQL,
		xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx, xxxxxxx,
		xxxxxxx, xxxxxxx, xxxxxxx,                            xxxxxxx,                                              xxxxxxx, xxxxxxx, xxxxxxx
    ),

	[_ADJUST] = LAYOUT_60_tsangan_hhkb(
		xxxxxxx, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  xxxxxxx, xxxxxxx,
		QK_BOOT, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, WM_UP,   xxxxxxx, KC_DEL,
		KC_CAPS, DF_M_P,  DF_L_P,  DF_W_P,  DF_G_P,  KC_GLB,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, WM_LEFT, WM_RGHT,          xxxxxxx,
		xxxxxxx, DF_MAC,  DF_LNX,  DF_WIN,  DF_GMG,  xxxxxxx, xxxxxxx, KC_MUTE, xxxxxxx, xxxxxxx, WM_DOWN,          KC_MPLY, xxxxxxx,
		xxxxxxx, xxxxxxx, xxxxxxx,                            KC_MPLY,                                              xxxxxxx, xxxxxxx, xxxxxxx
    ),

	[_MOUSE] = LAYOUT_60_tsangan_hhkb(
		_______, MS_BTN1, MS_BTN2, MS_BTN3, MS_BTN4, MS_BTN5, MS_BTN6, MS_BTN7, MS_BTN8, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_MEH,
		KC_HYPR, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
		_______, xxxxxxx, MS_ACL2, MS_ACL1, MS_ACL0, MS_BTN2, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, xxxxxxx, xxxxxxx,          _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, xxxxxxx,          KC_RSFT, _______,
		xxxxxxx, _______, _______,                            MS_BTN1,                                              _______, _______, xxxxxxx
    ),

	[_EX_MOUSE] = LAYOUT_60_tsangan_hhkb(
		_______, MS_BTN1, MS_BTN2, MS_BTN3, MS_BTN4, MS_BTN5, MS_BTN6, MS_BTN7, MS_BTN8, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_MEH,
		KC_HYPR, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
		_______, xxxxxxx, MS_ACL2, MS_ACL1, MS_ACL0, MS_BTN2, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, xxxxxxx, xxxxxxx,          _______,
		TG_MSE,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, xxxxxxx,          KC_RSFT, _______,
		xxxxxxx, _______, _______,                            MS_BTN1,                                              _______, _______, xxxxxxx
    )

};
// clang-format on
