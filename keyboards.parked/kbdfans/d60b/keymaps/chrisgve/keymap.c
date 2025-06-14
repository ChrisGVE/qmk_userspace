#include QMK_KEYBOARD_H
#include "chrisgve.h"

/* led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   0,		1,		2,		3,		4,		5,		6,		7,		8,		9,		10,		11,		12,		13,		14},
  {   15,		NO_LED, 16,		17,		18,		19,		20,		21,		22,		23,		24,		25,		26,		27,		28},
  {   29,		NO_LED, 30,		31,		32,		33,		34,		35,		36,		37,		38,		39,		40,		NO_LED,	41},
  {   NO_LED,   42,		43,		44,		45,		46,		47,		48,		49,		50,		51,		52,		NO_LED, 53,		54},
  {   55,		NO_LED, 56,		57,		NO_LED,	NO_LED,	NO_LED,  58,	NO_LED, NO_LED, NO_LED,	59,		NO_LED, 60,		61}
}, {
  // LED Index to Physical Position
  {  0,  0},   { 16,  0},  { 32, 0 },   { 48, 0 },   { 64, 0},    { 80, 0},    { 96, 0},   { 112, 0},   { 128, 0},   { 144, 0},   { 160, 0},   { 176, 0},  { 192, 0},  { 208, 0},  { 224, 0},
  {  0,  16},              { 32,  16},  { 48, 16},   { 64, 16},   { 80, 16},   { 96, 16},  { 112, 16},  { 128, 16},  { 144, 16},  { 160, 16},  { 176, 16}, { 192, 16}, { 208, 16}, { 224, 16}, 			//,
  {  0,  32},              { 32,  32},  { 48, 32 },  { 64, 32},   { 80, 32},   { 96, 32},  { 112, 32},  { 128, 32},  { 144, 32},  { 160, 32},  { 176, 32}, { 192, 32},             { 224, 32}, //,
               { 16,  48}, { 32, 48 },  { 48, 48 },  { 64, 48},   { 80, 48},   { 96, 48},  { 112, 48},  { 128, 48},  { 144, 48},  { 160, 48},  { 176, 48},             { 208, 48}, { 224, 48}, //,
  {  0,  64},              { 32,  64},  { 48, 64 },  			  				           { 112, 64},  			  				  		   { 176, 64},  		   { 208, 64}, { 224, 64},
}, {
  // LED Index to Flag
      4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4,		4,
      4, 				4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4,
      4, 				4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		  		4,
                4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 		4, 				4, 		4,
      4, 				4, 		4, 		 		  		        4, 		  		  		  		4, 		  		4, 		4,
} }; */

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_GAMING]=LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
	    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, 	                 KC_RSFT, ADJUST,
        xxxxxxx, KC_LALT, KC_LGUI,                                     KC_SPC,                                      KC_RGUI, KC_RALT, xxxxxxx
    ),

    [_QWERTY_MAC]=LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, BPC_MEH,
        KC_LCTL, A_MOUSE, KC_S,    M_NAV_1, M_F_NAV, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
	    SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, 	                 R_SHIFT, ADJUST,
        xxxxxxx, KC_LALT, KC_LGUI,                                     SPC_RSE,                                     KC_RGUI, KC_RALT, xxxxxxx
    ),

    [_MAC_NAV_1]=LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, M_F_WRD, _______, _______, _______, M_YANK,  _______, _______, _______, M_PUT,   _______, _______, _______,
        _______, A_SHIFT, S_SHIFT, _______, M_NAV_2, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,
        _______, _______, M_DEL,   _______, _______, M_B_WRD, KC_HOME, KC_END,  _______, _______, _______,                   _______, _______,
        _______, _______, _______,                                     _______,                                     _______, _______, _______
    ),

    [_MAC_NAV_2]=LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,
        _______, _______, _______,                                     _______,                                     _______, _______, _______
    ),

    [_QWERTY_LINUX]=LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, BPC_MEH,
        KC_LCTL, A_MOUSE, KC_S,    L_NAV_1, L_F_NAV, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
	    SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, 	                 R_SHIFT, ADJUST,
        xxxxxxx, KC_LGUI, KC_LALT,                                     SPC_RSE,                                     KC_RALT, KC_RGUI, xxxxxxx
    ),

    [_LINUX_NAV_1]=LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, L_F_WRD, _______, _______, _______, L_YANK,  _______, _______, _______, L_PUT,   _______, _______, _______,
        _______, A_SHIFT, S_SHIFT, _______, L_NAV_2, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,
        _______, _______, L_DEL,   _______, _______, L_B_WRD, KC_HOME, KC_END,  _______, _______, _______,                   _______, _______,
        _______, _______, _______,                                     _______,                                     _______, _______, _______
    ),

    [_LINUX_NAV_2]=LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,
        _______, _______, _______,                                     _______,                                     _______, _______, _______
    ),

    [_QWERTY_WIN]=LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, A_MOUSE, KC_S,    W_NAV_1, W_F_NAV, KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
	    SFT_MSE, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, 	                 KC_RSFT, ADJUST,
        xxxxxxx, KC_LGUI, KC_LALT,                                     SPC_RSE,                                     KC_RALT, KC_RGUI, xxxxxxx
    ),

    [_WIN_NAV_1]=LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, W_F_WRD, _______, _______, _______, W_YANK,  _______, _______, _______, W_PUT,   _______, _______, _______,
        _______, A_SHIFT, S_SHIFT, _______, W_NAV_2, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,
        _______, _______, W_DEL,   _______, _______, W_B_WRD, KC_HOME, KC_END,  _______, _______, _______,                   _______, _______,
        _______, _______, _______,                                     _______,                                     _______, _______, _______
    ),

    [_WIN_NAV_2]=LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,
        _______, _______, _______,                                     _______,                                     _______, _______, _______
    ),

    [_RAISE]=LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_DEL,
        KC_CAPS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,          KC_EQL,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______,
        _______, _______, _______,                                     _______,                                     _______, _______, _______
    ),

    [_ADJUST]=LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        QK_BOOT, MAC_SWT, _______, WIN_SWT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_CAPS, DF_M_P,  DF_L_P,  DF_W_P,  _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______,          _______,
        _______, DF_MAC,  DF_LNX,  DF_WIN,  _______, _______, _______, KC_MUTE, _______, _______, _______,                   _______, _______,
        _______, _______, _______,                                     KC_MPLY,                                     _______, _______, _______
    ),

    [_MOUSE]=LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, KC_WH_U, KC_WH_D, _______, _______, _______,                   _______, _______,
        _______, _______, _______,                                     KC_BTN1,                                     _______, _______, _______
    ),

    [_EX_MOUSE]=LAYOUT(
        TG_MSE,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
        xxxxxxx, xxxxxxx, KC_ACL2, KC_ACL1, KC_ACL0, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, xxxxxxx, xxxxxxx,          xxxxxxx,
        TG_MSE,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_WH_U, KC_WH_D, xxxxxxx, xxxxxxx, xxxxxxx,                   xxxxxxx, xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx,                                     KC_BTN1,                                     xxxxxxx, xxxxxxx, xxxxxxx
    ),

};
// clang-format on
