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

	[_GAMING] = LAYOUT_tsangan(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_PGUP,  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGDN,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           END_ADJ,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,                      KC_P1,   KC_P2,   KC_P3,   KC_PENT,
		KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                    KC_RGUI,                   KC_LEFT, KC_DOWN, KC_RGHT,                    KC_P0,            KC_PDOT
    ),

	[_QWERTY_MAC] = LAYOUT_tsangan(
		ESC_GLB, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, GRV_MEH, KC_PGUP,  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
		TAB_HYP, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGDN,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
		KC_LCTL, A_MOUSE, KC_S,    M_NAV_1, M_F_NAV, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           END_ADJ,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
		SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, R_SHIFT,          KC_UP,                      KC_P1,   KC_P2,   KC_P3,   KC_PENT,
		KC_GLB,  KC_LALT, KC_LGUI,                   SPC_RSE,                   KC_RGUI,                   KC_LEFT, KC_DOWN, KC_RGHT,                    KC_P0,            KC_PDOT
    ),

	[_MAC_NAV_1] = LAYOUT_tsangan(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,  _______,  _______, _______, _______, _______,
		_______, xxxxxxx, M_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, M_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, M_PUT,   xxxxxxx, xxxxxxx, _______,           _______,  _______, _______, _______, _______,
		_______, A_SHIFT, S_SHIFT, xxxxxxx, M_NAV_2, xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          _______,           _______,  _______, _______, _______, _______,
		_______, xxxxxxx, M_DEL,   xxxxxxx, xxxxxxx, M_B_WRD, KC_HOME, KC_END,  xxxxxxx, xxxxxxx, xxxxxxx, _______,          _______,                     _______, _______, _______, _______,
		_______, _______, _______,                   xxxxxxx,                            _______,                   _______, _______, _______,            _______,          _______
    ),

	[_MAC_NAV_2] = LAYOUT_tsangan(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,  _______,  _______, _______, _______, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,           _______,  _______, _______, _______, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, xxxxxxx,          _______,           _______,  _______, _______, _______, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,          _______,                     _______, _______, _______, _______,
		_______, _______, _______,                   xxxxxxx,                            _______,                   _______, _______, _______,            _______,          _______
    ),

	[_QWERTY_LINUX] = LAYOUT_tsangan(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, GRV_MEH, KC_PGUP,  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
		TAB_HYP, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGDN,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
		KC_LCTL, A_MOUSE, KC_S,    L_NAV_1, L_F_NAV, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           END_ADJ,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
		SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, R_SHIFT,          KC_UP,                      KC_P1,   KC_P2,   KC_P3,   KC_PENT,
		KC_LCTL, KC_LGUI, KC_LALT,                   SPC_RSE,                   KC_RGUI,                   KC_LEFT, KC_DOWN, KC_RGHT,                    KC_P0,            KC_PDOT
    ),

	[_LINUX_NAV_1] = LAYOUT_tsangan(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,  _______,  _______, _______, _______, _______,
		_______, xxxxxxx, L_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, L_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, L_PUT,   xxxxxxx, xxxxxxx, _______,           _______,  _______, _______, _______, _______,
		_______, A_SHIFT, S_SHIFT, xxxxxxx, L_NAV_2, xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          _______,           _______,  _______, _______, _______, _______,
		_______, xxxxxxx, L_DEL,   xxxxxxx, xxxxxxx, L_B_WRD, KC_HOME, KC_END,  xxxxxxx, xxxxxxx, xxxxxxx, _______,           _______,                     _______, _______, _______, _______,
		_______, _______, _______,                   xxxxxxx,                            _______,                   _______, _______, _______,            _______,          _______
    ),

	[_LINUX_NAV_2] = LAYOUT_tsangan(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,  _______,  _______, _______, _______, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,           _______,  _______, _______, _______, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, xxxxxxx,          _______,           _______,  _______, _______, _______, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,          _______,                     _______, _______, _______, _______,
		_______, _______, _______,                   xxxxxxx,                            _______,                   _______, _______, _______,            _______,          _______
    ),

	[_QWERTY_WIN] = LAYOUT_tsangan(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_PGUP,  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGDN,  KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
		KC_LCTL, KC_A,    KC_S,    W_NAV_1, W_F_NAV, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           END_ADJ,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
		SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,                      KC_P1,   KC_P2,   KC_P3,   KC_PENT,
		KC_LCTL, KC_LGUI, KC_LALT,                   SPC_RSE,                   KC_RGUI,                   KC_LEFT, KC_DOWN, KC_RGHT,                    KC_P0,            KC_PDOT
    ),

	[_WIN_NAV_1] = LAYOUT_tsangan(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,  _______,  _______, _______, _______, _______,
		_______, xxxxxxx, W_F_WRD, xxxxxxx, xxxxxxx, xxxxxxx, W_YANK,  xxxxxxx, xxxxxxx, xxxxxxx, W_PUT,   xxxxxxx, xxxxxxx, _______,           _______,  _______, _______, _______, _______,
		_______, A_SHIFT, S_SHIFT, xxxxxxx, W_NAV_2, xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx,          _______,           _______,  _______, _______, _______, _______,
		_______, xxxxxxx, W_DEL,   xxxxxxx, xxxxxxx, W_B_WRD, KC_HOME, KC_END,  xxxxxxx, xxxxxxx, xxxxxxx, _______,          _______,                     _______, _______, _______, _______,
		_______, _______, _______,                   xxxxxxx,                            _______,                   _______, _______, _______,            _______,          _______
    ),

	[_WIN_NAV_2] = LAYOUT_tsangan(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,  _______,  _______, _______, _______, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,           _______,  _______, _______, _______, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  xxxxxxx, xxxxxxx,          _______,           _______,  _______, _______, _______, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,          _______,                     _______, _______, _______, _______,
		_______, _______, _______,                   xxxxxxx,                            _______,                   _______, _______, _______,            _______,          _______
    ),

	[_RAISE] = LAYOUT_tsangan(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  xxxxxxx, _______,  _______,  _______, _______, _______, _______,
		_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_DEL,            _______,  _______, _______, _______, _______,
		KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,          KC_EQL,            _______,  _______, _______, _______, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,          _______,                     _______, _______, _______, _______,
		_______, _______, _______,                   xxxxxxx,                            _______,                   _______, _______, _______,            _______,          _______
    ),

	[_ADJUST] = LAYOUT_tsangan(
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  xxxxxxx, _______,  _______,  _______, _______, _______, _______,
		QK_BOOT, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, WM_UP,   xxxxxxx, KC_DEL,            _______,  _______, _______, _______, _______,
		KC_CAPS, DF_M_P,  DF_L_P,  DF_W_P,  DF_G_P,  KC_GLB,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, WM_LEFT, WM_RGHT,          _______,           _______,  _______, _______, _______, _______,
		_______, DF_MAC,  DF_LNX,  DF_WIN,  DF_GMG,  xxxxxxx, xxxxxxx, KC_MUTE, xxxxxxx, xxxxxxx, WM_DOWN, KC_MPLY,          KC_VOLU,                     _______, _______, _______, _______,
		_______, _______, _______,                   KC_MPLY,                            _______,                   KC_MPRV, KC_VOLD, KC_MNXT,            _______,          _______
    ),

	[_MOUSE] = LAYOUT_tsangan(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,  KC_WH_U,  _______, _______, _______, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,           KC_WH_D,  _______, _______, _______, _______,
		_______, xxxxxxx, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, xxxxxxx, xxxxxxx,          _______,           _______,  _______, _______, _______, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_WH_U, KC_WH_D, xxxxxxx, xxxxxxx, xxxxxxx, _______,          KC_MS_U,                     _______, _______, _______, _______,
		_______, _______, _______,                   KC_BTN1,                            _______,                   KC_MS_L, KC_MS_D, KC_MS_R,            _______,          _______
    ),

	[_EX_MOUSE] = LAYOUT_tsangan(
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,  KC_WH_U,  _______, _______, _______, _______,
		_______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,           KC_WH_D,  _______, _______, _______, _______,
		_______, xxxxxxx, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, xxxxxxx, xxxxxxx,          _______,           _______,  _______, _______, _______, _______,
		TG_MSE,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_WH_U, KC_WH_D, xxxxxxx, xxxxxxx, xxxxxxx, _______,          KC_MS_U,                     _______, _______, _______, _______,
		_______, _______, _______,                   KC_BTN1,                            _______,                   KC_MS_L, KC_MS_D, KC_MS_R,            _______,          _______
    ),

};
// clang-format on
