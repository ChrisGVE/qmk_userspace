/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
#include "chrisgve.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // [L3] = LAYOUT_ansi_60(
    //  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
    //  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx,
    //  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                   xxxxxxx,
    //  xxxxxxx,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx, xxxxxxx,
    //                    xxxxxxx, xxxxxxx,                            xxxxxxx,                            xxxxxxx, xxxxxxx),

	[_GAMING] = LAYOUT_ansi_60(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSPC,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT,
		KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, ADJUST,
		                  KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT
	),

	[MAC_BASE] = LAYOUT_ansi_60(
		ESC_GLB, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, GRV_MEH,
		TAB_HYP, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
		KC_LCTL, A_MOUSE, KC_S,    M_NAV,   F_NAV_2, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
		SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   R_SHIFT, ADJUST,
		         KC_LALT, KC_LGUI,                                     SPC_RSE,                                     KC_RGUI, KC_RALT
	),

	[_MAC_NAV] = LAYOUT_ansi_60(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
		_______, xxxxxxx, M_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, M_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, M_PUT,   xxxxxxx, xxxxxxx, _______,
		_______, A_SHIFT, S_SHIFT, xxxxxxx, NAV_2,   xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          _______,
		_______, xxxxxxx, M_DEL,   xxxxxxx, xxxxxxx, M_B_WRD, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx,                   _______, _______,
		         _______, _______,                                     xxxxxxx,                                     _______, _______
	),

	[_QWERTY_LINUX] = LAYOUT_ansi_60(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, GRV_MEH,
		TAB_HYP, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
		KC_LCTL, A_MOUSE, KC_S,    L_NAV,   F_NAV_2, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
		SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   R_SHIFT, ADJUST,
		         KC_LGUI, KC_LALT,                                     SPC_RSE,                                     KC_RALT, KC_RGUI
	),

	[_LINUX_NAV] = LAYOUT_ansi_60(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
		_______, xxxxxxx, L_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, L_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, L_PUT,   xxxxxxx, xxxxxxx, _______,
		_______, A_SHIFT, S_SHIFT, xxxxxxx, NAV_2,   xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          _______,
		_______, xxxxxxx, L_DEL,   xxxxxxx, xxxxxxx, L_B_WRD, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx,                   _______, _______,
		         _______, _______,                                     xxxxxxx,                                     _______, _______
	),

	[WIN_BASE] = LAYOUT_ansi_60(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
		KC_LCTL, KC_A,    KC_S,    W_NAV,   F_NAV_2, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
		SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT, ADJUST,
		         KC_LGUI, KC_LALT,                                     SPC_RSE,                                     KC_RALT, KC_RGUI
	),

	[_WIN_NAV] = LAYOUT_ansi_60(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
		_______, xxxxxxx, W_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, W_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, W_PUT,   xxxxxxx, xxxxxxx, _______,
		_______, A_SHIFT, S_SHIFT, xxxxxxx, NAV_2,   xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          _______,
		_______, xxxxxxx, W_DEL,   xxxxxxx, xxxxxxx, W_B_WRD, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx,                   _______, _______,
		         _______, _______,                                     xxxxxxx,                                     _______, _______
	),

	[_NAV_2] = LAYOUT_ansi_60(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, xxxxxxx,          _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                   _______, _______,
		         _______, _______,                                     xxxxxxx,                                     _______, _______
	),

	[_RAISE] = LAYOUT_ansi_60(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  xxxxxxx, _______,
		_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_DEL,
		KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,          KC_EQL,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                   _______, _______,
		         _______, _______,                                     xxxxxxx,                                     _______, _______
	),

	[_ADJUST] = LAYOUT_ansi_60(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  xxxxxxx, _______,
		QK_BOOT, BT_HST1, BT_HST2, BT_HST3, P2P4G,   xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, WM_UP,   xxxxxxx, KC_DEL,
		KC_CAPS, DF_M_P,  DF_L_P,  DF_W_P,  DF_G_P,  KC_GLB,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, WM_LEFT, WM_RGHT,          _______,
		_______, DF_MAC,  DF_LNX,  DF_WIN,  DF_GMG,  xxxxxxx, xxxxxxx, KC_MUTE, xxxxxxx, xxxxxxx, WM_DOWN,                   KC_MPLY, _______,
		         _______, _______,                                     KC_MPLY,                                     _______, _______
	),

	[_MOUSE] = LAYOUT_ansi_60(
		_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_BTN6, KC_BTN7, KC_BTN8, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_MEH,
		KC_HYPR, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
		_______, xxxxxxx, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN2, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, xxxxxxx,                   KC_RSFT, _______,
		         _______, _______,                                     KC_BTN1,                                     _______, _______
	),

	[_EX_MOUSE] = LAYOUT_ansi_60(
		_______, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_BTN5, KC_BTN6, KC_BTN7, KC_BTN8, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_MEH,
		KC_HYPR, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
		_______, xxxxxxx, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN2, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          _______,
		TG_MSE,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, xxxxxxx,                   KC_RSFT, _______,
		         _______, _______,                                     KC_BTN1,                                     _______, _______
	),

};

// clang-format on
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (!process_record_keychron_common(keycode, record)) {
//         return false;
//     }
//     return true;
// }
