/* Copyright 2020 Team Mechlovin
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

    [_GAMING] = LAYOUT_alice_split_bs(
     KC_PGUP, KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
     KC_PGDN, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
     KC_END,  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
              KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  ADJUST,  KC_RSFT, KC_SLSH,
              _______,          KC_LGUI,          KC_SPC,           KC_LALT,                  KC_SPC,           KC_RGUI,                            _______
    ),

    [_QWERTY_MAC] = LAYOUT_alice_split_bs(
     KC_PGUP, ESC_GLB, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, GRV_MEH,
     KC_PGDN, TAB_HYP, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
     KC_END,  KC_LCTL, A_MOUSE, KC_S,    M_NAV_1, M_F_NAV, KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
              SFT_MSE,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  ADJUST,  R_SHIFT, KC_SLSH,
              _______,          KC_LGUI,          SPC_RSE,          KC_LALT,                  SPC_RSE,          KC_RGUI,                            _______
    ),

    [_MAC_NAV_1] = LAYOUT_alice_split_bs(
     _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, M_F_WRD, _______, _______, _______,                  M_YANK,  _______, _______, _______, M_PUT,   _______, _______, _______,
     _______, _______, A_SHIFT, S_SHIFT, _______, M_NAV_2, _______,                  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
              _______,          _______, M_DEL,   _______, _______, M_B_WRD,         M_B_WRD, KC_HOME, KC_END,  _______, _______, _______, _______, _______,
              _______,          _______,          _______,          _______,                  _______,          _______,                            _______
    ),

    [_MAC_NAV_2] = LAYOUT_alice_split_bs(
     _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,                  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______,
              _______,          _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
              _______,          _______,          _______,          _______,                  _______,          _______,                            _______
    ),

    [_QWERTY_LINUX] = LAYOUT_alice_split_bs(
     KC_PGUP, KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, GRV_MEH,
     KC_PGDN, TAB_HYP, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
     KC_END,  KC_LCTL, A_MOUSE, KC_S,    L_NAV_1, L_F_NAV, KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
              SFT_MSE,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  ADJUST,  R_SHIFT, KC_SLSH,
              _______,          KC_LALT,          SPC_RSE,          KC_LGUI,                  SPC_RSE,          KC_RALT,                            _______
    ),

    [_LINUX_NAV_1] = LAYOUT_alice_split_bs(
     _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, L_F_WRD, _______, _______, _______,                  L_YANK,  _______, _______, _______, L_PUT,   _______, _______, _______,
     _______, _______, A_SHIFT, S_SHIFT, _______, L_NAV_2, _______,                  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
              _______,          _______, L_DEL,   _______, _______, L_B_WRD,         L_B_WRD, KC_HOME, KC_END,  _______, _______, _______, _______, _______,
              _______,          _______,          _______,          _______,                  _______,          _______,                            _______
    ),

    [_LINUX_NAV_2] = LAYOUT_alice_split_bs(
     _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,                  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______,
              _______,          _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
              _______,          _______,          _______,          _______,                  _______,          _______,                            _______
    ),

    [_QWERTY_WIN] = LAYOUT_alice_split_bs(
     KC_PGUP, KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
     KC_PGDN, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
     KC_END,  KC_LCTL, KC_A,    KC_S,    W_NAV_1, W_F_NAV, KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
              SFT_MSE,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  ADJUST,  KC_RSFT, KC_SLSH,
              _______,          KC_LALT,          SPC_RSE,          KC_RGUI,                  SPC_RSE,          KC_RALT,                            _______
    ),

    [_WIN_NAV_1] = LAYOUT_alice_split_bs(
     _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, W_F_WRD, _______, _______, _______,                  W_YANK,  _______, _______, _______, W_PUT,   _______, _______, _______,
     _______, _______, A_SHIFT, S_SHIFT, _______, W_NAV_2, _______,                  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
              _______,          _______, W_DEL,   _______, _______, W_B_WRD,         W_B_WRD, KC_HOME, KC_END,  _______, _______, _______, _______, _______,
              _______,          _______,          _______,          _______,                  _______,          _______,                            _______
    ),

    [_WIN_NAV_2] = LAYOUT_alice_split_bs(
     _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,                  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______,
              _______,          _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
              _______,          _______,          _______,          _______,                  _______,          _______,                            _______
    ),

    [_RAISE] = LAYOUT_alice_split_bs(
     _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,                  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______, KC_DEL,
     _______, KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
              _______,          _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
              _______,          _______,          _______,          _______,                  _______,          _______,                            _______
    ),

    [_ADJUST] = LAYOUT_alice_split_bs(
     _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
     _______, QK_BOOT, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, WM_UP,   _______, KC_DEL,
     _______, KC_CAPS, DF_M_P,  DF_L_P,  DF_W_P,  DF_G_P,  KC_GLB,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, WM_LEFT, WM_RGHT, _______,
              _______,          DF_MAC,  DF_LNX,  DF_WIN,  DF_GMG,  _______,         _______, KC_MUTE, _______, _______, _______, _______, KC_MPLY, WM_DOWN,
              _______,          _______,          KC_MPLY,          KC_MPLY,                  KC_MPLY,          _______,                            _______
    ),

    [_MOUSE] = LAYOUT_alice_split_bs(
     _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,                  _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN2,                  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______,
              _______,          _______, _______, _______, _______, _______,         _______, KC_WH_U, KC_WH_D, _______, _______, _______, _______, _______,
              _______,          _______,          KC_BTN1,          KC_BTN1,                  KC_BTN1,          _______,                            _______
    ),

    [_EX_MOUSE] = LAYOUT_alice_split_bs(
     XXXXXXX, TG_MSE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN2,                  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX,
              TG_MSE,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         KC_WH_U, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
              XXXXXXX,          XXXXXXX,          KC_BTN1,          KC_BTN1,                  KC_BTN1,          XXXXXXX,                            XXXXXXX
    ),

};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) {
    if (clockwise) {
      tap_code(KC_LEFT);
    } else {
      tap_code(KC_RGHT);
    }
  } else if (index == 2) {
    if (clockwise) {
      tap_code(KC_UP);
    } else {
      tap_code(KC_DOWN);
    }
  }
  return true;
}

#endif
