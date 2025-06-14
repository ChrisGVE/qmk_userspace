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
              KC_LALT,          KC_LGUI,          KC_SPC,           ADJUST,                   KC_SPC,           KC_RGUI,                            KC_RALT
    ),

    [_QWERTY_MAC] = LAYOUT_alice_split_bs(
     KC_PGUP, ESC_GLB, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, GRV_MEH,
     KC_PGDN, TAB_HYP, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
     KC_END,  KC_LCTL, A_MOUSE, KC_S,    M_NAV_1, M_F_NAV, KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
              SFT_MSE,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  ADJUST,   R_SHIFT, KC_SLSH,
              KC_LALT,          KC_LGUI,          SPC_RSE,          ADJUST,                   SPC_RSE,          KC_RGUI,                            KC_RALT
    ),

    [_MAC_NAV_1] = LAYOUT_alice_split_bs(
     _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
     _______, _______, xxxxxxx, M_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx,                  M_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, M_PUT,   xxxxxxx, xxxxxxx, _______,
     _______, _______, A_SHIFT, S_SHIFT, xxxxxxx, M_NAV_2, xxxxxxx,                  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx, _______,
              _______,          xxxxxxx, M_DEL,   xxxxxxx, xxxxxxx, M_B_WRD,         M_B_WRD, KC_HOME, KC_END,  xxxxxxx, xxxxxxx, _______, _______, xxxxxxx,
              _______,          _______,          xxxxxxx,          _______,                  xxxxxxx,          _______,                            _______
    ),

    [_MAC_NAV_2] = LAYOUT_alice_split_bs(
     _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
     _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
     _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, xxxxxxx, _______,
              _______,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______, xxxxxxx,
              _______,          _______,          xxxxxxx,          _______,                  xxxxxxx,          _______,                            _______
    ),

    [_QWERTY_LINUX] = LAYOUT_alice_split_bs(
     KC_PGUP, KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, GRV_MEH,
     KC_PGDN, TAB_HYP, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
     KC_END,  KC_LCTL, A_MOUSE, KC_S,    L_NAV_1, L_F_NAV, KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
              SFT_MSE,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  ADJUST,  R_SHIFT, KC_SLSH,
              KC_LGUI,          KC_LALT,          SPC_RSE,          ADJUST,                   SPC_RSE,          KC_RALT,                            KC_RGUI
    ),

    [_LINUX_NAV_1] = LAYOUT_alice_split_bs(
     _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
     _______, _______, xxxxxxx, L_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx,                  L_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, L_PUT,   xxxxxxx, xxxxxxx, _______,
     _______, _______, A_SHIFT, S_SHIFT, xxxxxxx, L_NAV_2, xxxxxxx,                  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx, _______,
              _______,          xxxxxxx, L_DEL,   xxxxxxx, xxxxxxx, L_B_WRD,         L_B_WRD, KC_HOME, KC_END,  xxxxxxx, xxxxxxx, _______, _______, xxxxxxx,
              _______,          _______,          xxxxxxx,          _______,                  xxxxxxx,          _______,                            _______
    ),

    [_LINUX_NAV_2] = LAYOUT_alice_split_bs(
     _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
     _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
     _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, xxxxxxx, _______,
              _______,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______, xxxxxxx,
              _______,          _______,          xxxxxxx,          _______,                  xxxxxxx,          _______,                            _______
    ),

    [_QWERTY_WIN] = LAYOUT_alice_split_bs(
     KC_PGUP, KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,            KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
     KC_PGDN, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
     KC_END,  KC_LCTL, KC_A,    KC_S,    W_NAV_1, W_F_NAV, KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
              SFT_MSE,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  ADJUST,  KC_RSFT, KC_SLSH,
              KC_LGUI,          KC_LALT,          SPC_RSE,          ADJUST,                   SPC_RSE,          KC_RALT,                            KC_RGUI
    ),

    [_WIN_NAV_1] = LAYOUT_alice_split_bs(
     _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
     _______, _______, xxxxxxx, W_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx,                  W_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, W_PUT,   xxxxxxx, xxxxxxx, _______,
     _______, _______, A_SHIFT, S_SHIFT, xxxxxxx, W_NAV_2, xxxxxxx,                  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx, _______,
              _______,          xxxxxxx, W_DEL,   xxxxxxx, xxxxxxx, W_B_WRD,         W_B_WRD, KC_HOME, KC_END,  xxxxxxx, xxxxxxx, _______, _______, xxxxxxx,
              _______,          _______,          xxxxxxx,          _______,                  xxxxxxx,          _______,                            _______
    ),

    [_WIN_NAV_2] = LAYOUT_alice_split_bs(
     _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
     _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
     _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, xxxxxxx, _______,
              _______,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______, xxxxxxx,
              _______,          _______,          xxxxxxx,          _______,                  xxxxxxx,          _______,                            _______
    ),

    [_RAISE] = LAYOUT_alice_split_bs(
     _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  xxxxxxx, _______,
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,                  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, xxxxxxx, KC_DEL,
     _______, KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
              _______,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, _______, xxxxxxx,
              _______,          _______,          xxxxxxx,          _______,                  xxxxxxx,          _______,                            _______
    ),

    [_ADJUST] = LAYOUT_alice_split_bs(
     _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  xxxxxxx, _______,
     _______, QK_BOOT, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, WM_UP,   xxxxxxx, KC_DEL,
     _______, KC_CAPS, DF_M_P,  DF_L_P,  DF_W_P,  DF_G_P,  KC_GLB,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, WM_LEFT, WM_RGHT, _______,
              _______,          DF_MAC,  DF_LNX,  DF_WIN,  DF_GMG,  xxxxxxx,         xxxxxxx, KC_MUTE, xxxxxxx, xxxxxxx, xxxxxxx, _______, KC_MPLY, WM_DOWN,
              _______,          _______,          KC_MPLY,          _______,                  KC_MPLY,          _______,                            _______
    ),

    [_MOUSE] = LAYOUT_alice_split_bs(
     KC_WH_U, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_MEH,
     KC_WH_D, KC_HYPR, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
     xxxxxxx, _______, xxxxxxx, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN2,                  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, xxxxxxx, xxxxxxx, _______,
              _______,          xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         KC_WH_U, KC_WH_D, xxxxxxx, xxxxxxx, xxxxxxx, _______, KC_RSFT, xxxxxxx,
              _______,          _______,          KC_BTN1,          _______,                  KC_BTN1,          _______,                            _______
    ),

    [_EX_MOUSE] = LAYOUT_alice_split_bs(
     KC_WH_U, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_MEH,
     KC_WH_D, KC_HYPR, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
     xxxxxxx, _______, xxxxxxx, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN2,                  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, xxxxxxx, xxxxxxx, _______,
              TG_MSE,           xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,         KC_WH_U, KC_WH_D, xxxxxxx, xxxxxxx, xxxxxxx, _______, KC_RSFT, xxxxxxx,
              _______,          _______,          KC_BTN1,          _______,                  KC_BTN1,          _______,                            _______
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
