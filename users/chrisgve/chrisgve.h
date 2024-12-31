/* Copyright 2021 Christian C. Berclaz
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
#pragma once

// #include "quantum.h"
// #include "action.h"
// #include "version.h"

#include QMK_KEYBOARD_H

#ifndef IGNORE_MOD_TAP_INTERRUPT
  #define IGNORE_MOD_TAP_INTERRUPT
#endif

// Custom layers
enum default_layers {
  _QWERTY_MAC, // QWERTY Mac base layout
  MAC_BASE = _QWERTY_MAC,
  _MAC_NAV_1,  // Mac Navigation layer 1
  _MAC_NAV_2,  // Mac Navigation layer 2
  _QWERTY_WIN, // QWERTY Windows base layout
  WIN_BASE = _QWERTY_WIN,
  _WIN_NAV_1,    // Windows Navigation layer 1
  _WIN_NAV_2,    // Windows Navigation layer 2
  _QWERTY_LINUX, // QWERTY Linux base layout
  _LINUX_NAV_1,  // Linux Navigation layer 1
  _LINUX_NAV_2,  // Linux Navigation layer 2
  _RAISE,        // Raise layer on ortho
  _LOWER,        // Lower layer on ortho
  _MOUSE,        // Mouse key layer
  _GAMING,       // Gaming layout
  _ADJUST,       // Adjust layer
  _NUM,          // Numerical layer (for 40% layouts)
  _EX_MOUSE,     // Mouse key layer (exclusive)
  _CONFIG,       // Keyboard configuration layer
};

// Custom keys
enum custom_keycodes {

#ifdef FACTORY_TEST_ENABLE // when this flag is set, it means we are compiling for keychron
  QWERTY = NEW_SAFE_RANGE,
#else
  QWERTY = SAFE_RANGE,
#endif

  DF_M_P,  // Make Mac layer the default persistent layer
  DF_L_P,  // Make Linux layer the default persistent layer
  DF_W_P,  // Make Windows layer the default persistent layer
  DF_G_P,  // Make Gaming layer the default persistent layer
  WIN_SWT, // Function keys F1 to F12 behave as expected
  MAC_SWT, // Function keys F1 to F12 behave as expected if Apple Fn is sent
  CU_BSPC, // Acts as normal Backspace and Delete when shifted
  CU_SPBC, // Acts as normal Space and Backspace when shifted

#ifdef FACTORY_TEST_ENABLE // when this flag is set, it means we are compiling for keychron
  NEW_SAFE_RANGE_2
#else
  NEW_SAFE_RANGE
#endif
};

// RGB standard colors
// CAPS LOCK color  - Warm white
#define HSV_CAPS 23, 227, 230 // HSV_CORAL

// NAV 1 color - Blue
#define HSV_NAV1 HSV_TEAL // 181, 204, 255 // HSV_TEAL

// NAV 2 color - Purple
#define HSV_NAV2 191, 204, 255 // HSV_PURPLE

// ADJ color  - Green #33cc33
#define HSV_ADJ 85, 191, 204 // HSV_CHARTREUSE

// NUM color  - Cyan
#define HSV_NUM HSV_CYAN

// MOUSE color - Orange
#define HSV_MSE 6, 255, 255 // HSV_ORANGE

// Windows color - 0x3fff82
#define HSV_WIN HSV_BLUE

// Linux color - 0xffff00
#define HSV_LNX HSV_GOLD

// Gaming mode
#if defined(RGBLIGHT_ENABLE)
  #if defined(RGBLIGHT_EFFECT_RAINBOW_SWIRL)
    #define LGT_GMG_ON (RGBLIGHT_MODE_RAINBOW_SWIRL + 2)
  #endif
#elif defined(RGB_MATRIX_ENABLE)
  #define LGT_GMG_ON RGB_MATRIX_RAINBOW_BEACON
#endif

#define TAB_CTL CTL_T(KC_TAB)
#define ADJUST MO(_ADJUST)
#define ADJ_BSL LT(_ADJUST, KC_BSLS)
#define CONFIG MO(_CONFIG)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TMUX LT(_TMUX, KC_SCLN)
#define VIM LT(_VIM, KC_V)
#define S_SHIFT SFT_T(KC_S)
#define A_SHIFT SFT_T(KC_A)
#define R_SHIFT RSFT_T(KC_BSLS)
#define TAB_HYP HYPR_T(KC_TAB)
#define QUT_SFT RSFT_T(KC_QUOT)
#define GUI_BSL RGUI_T(KC_BSLS)
#define ALT_BSL RALT_T(KC_BSLS)
#define BSL_RSE LT(_RAISE, KC_BSLS)
#define S_MOUSE LT(_MOUSE, KC_S)
#define A_MOUSE LT(_MOUSE, KC_A)

#define END_ADJ LT(_ADJUST, KC_END)
#define PGDN_AD LT(_ADJUST, KC_PGDN)
#define SPC_LWR LT(_LOWER, KC_SPC)
#define SPC_RSE LT(_RAISE, KC_SPC)
#define SLS_SFT RSFT_T(KC_SLSH)
#define FN_NUM LT(_ADJUST, KC_NO)

#define WM_UP RGUI(KC_UP)
#define WM_DOWN RGUI(KC_DOWN)
#define WM_LEFT RGUI(KC_LEFT)
#define WM_RGHT RGUI(KC_RIGHT)

#define L_MOD LT(_RAISE, KC_SPC) // for split space bar, left bar
#define R_MOD LT(_LOWER, KC_SPC) // for split space bar, right bar
// #define R_MOD       RCTL_T(KC_SPC)  // for split space bar, right bar

#ifndef MODIFIERS_ENABLE
  #define CU_BSPC KC_BSPC
  #define CU_SPBC KC_SPC
#endif

// This section is copied from SpacebarRacercar userspace to insert the
// smart shift keycode, this is governed by the MODIFIERS_ENABLE switch
#ifdef MODIFIERS_ENABLE

  // Normal shift status
  #define SHIFT_NORM(kc1, kc2)      \
    if (record->event.pressed) {    \
      if (lshift || rshift) {       \
        if (lshift) {               \
          register_code(KC_LSFT);   \
        } else {                    \
          register_code(KC_RSFT);   \
        }                           \
        unregister_code(kc2);       \
        register_code(kc2);         \
      } else {                      \
        if (lshift) {               \
          unregister_code(KC_LSFT); \
        } else {                    \
          unregister_code(KC_RSFT); \
        }                           \
        unregister_code(kc1);       \
        register_code(kc1);         \
      }                             \
    } else {                        \
      unregister_code(kc1);         \
      unregister_code(kc2);         \
    }                               \
    return false;

  // Normal ctrl status
  #define CTRL_NORM(kc1, kc2)       \
    if (record->event.pressed) {    \
      if (lctrl || rctrl) {         \
        if (lctrl) {                \
          register_code(KC_LCTL);   \
        } else {                    \
          register_code(KC_RCTL);   \
        }                           \
        unregister_code(kc2);       \
        register_code(kc2);         \
      } else {                      \
        if (lctrl) {                \
          unregister_code(KC_LCTL); \
        } else {                    \
          unregister_code(KC_RCTL); \
        }                           \
        unregister_code(kc1);       \
        register_code(kc1);         \
      }                             \
    } else {                        \
      unregister_code(kc1);         \
      unregister_code(kc2);         \
    }                               \
    return false;

  // Normal alt status
  #define ALT_NORM(kc1, kc2)        \
    if (record->event.pressed) {    \
      if (lalt || ralt) {           \
        if (lalt) {                 \
          register_code(KC_LALT);   \
        } else {                    \
          register_code(KC_RALT);   \
        }                           \
        unregister_code(kc2);       \
        register_code(kc2);         \
      } else {                      \
        if (lalt) {                 \
          unregister_code(KC_LALT); \
        } else {                    \
          unregister_code(KC_RALT); \
        }                           \
        unregister_code(kc1);       \
        register_code(kc1);         \
      }                             \
    } else {                        \
      unregister_code(kc1);         \
      unregister_code(kc2);         \
    }                               \
    return false;

  // Normal gui status
  #define GUI_NORM(kc1, kc2)        \
    if (record->event.pressed) {    \
      if (lgui || rgui) {           \
        if (lgui) {                 \
          register_code(KC_LGUI);   \
        } else {                    \
          register_code(KC_RGUI);   \
        }                           \
        unregister_code(kc2);       \
        register_code(kc2);         \
      } else {                      \
        if (lgui) {                 \
          unregister_code(KC_LGUI); \
        } else {                    \
          unregister_code(KC_RGUI); \
        }                           \
        unregister_code(kc1);       \
        register_code(kc1);         \
      }                             \
    } else {                        \
      unregister_code(kc1);         \
      unregister_code(kc2);         \
    }                               \
    return false;

  // Inverted shift status
  #define SHIFT_SWITCH(kc1, kc2)    \
    if (record->event.pressed) {    \
      if (lshift || rshift) {       \
        if (lshift) {               \
          unregister_code(KC_LSFT); \
        } else {                    \
          unregister_code(KC_RSFT); \
        }                           \
        unregister_code(kc2);       \
        register_code(kc2);         \
      } else {                      \
        if (lshift) {               \
          register_code(KC_LSFT);   \
        } else {                    \
          register_code(KC_RSFT);   \
        }                           \
        unregister_code(kc1);       \
        register_code(kc1);         \
      }                             \
    } else {                        \
      unregister_code(kc1);         \
      unregister_code(kc2);         \
      if (lshift || rshift)         \
        if (lshift) {               \
          register_code(KC_LSFT);   \
        } else {                    \
          register_code(KC_RSFT);   \
        }                           \
      else {                        \
        unregister_code(KC_LSFT);   \
        unregister_code(KC_RSFT);   \
      }                             \
    }                               \
    return false;

  // Inverted ctrl status
  #define CTRL_SWITCH(kc1, kc2)     \
    if (record->event.pressed) {    \
      if (lctrl || rctrl) {         \
        if (lctrl) {                \
          unregister_code(KC_LCTL); \
        } else {                    \
          unregister_code(KC_RCTL); \
        }                           \
        unregister_code(kc2);       \
        register_code(kc2);         \
      } else {                      \
        if (lctrl) {                \
          register_code(KC_LCTL);   \
        } else {                    \
          register_code(KC_RCTL);   \
        }                           \
        unregister_code(kc1);       \
        register_code(kc1);         \
      }                             \
    } else {                        \
      unregister_code(kc1);         \
      unregister_code(kc2);         \
      if (lctrl || rctrl)           \
        if (lctrl) {                \
          register_code(KC_LCTL);   \
        } else {                    \
          register_code(KC_RCTL);   \
        }                           \
      else {                        \
        unregister_code(KC_LCTL);   \
        unregister_code(KC_RCTL);   \
      }                             \
    }                               \
    return false;

  // Inverted alt status
  #define ALT_SWITCH(kc1, kc2)      \
    if (record->event.pressed) {    \
      if (lalt || ralt) {           \
        if (lalt) {                 \
          unregister_code(KC_LALT); \
        } else {                    \
          unregister_code(KC_RALT); \
        }                           \
        unregister_code(kc2);       \
        register_code(kc2);         \
      } else {                      \
        if (lalt) {                 \
          register_code(KC_LALT);   \
        } else {                    \
          register_code(KC_RALT);   \
        }                           \
        unregister_code(kc1);       \
        register_code(kc1);         \
      }                             \
    } else {                        \
      unregister_code(kc1);         \
      unregister_code(kc2);         \
      if (lalt || ralt)             \
        if (lalt) {                 \
          register_code(KC_LALT);   \
        } else {                    \
          register_code(KC_RALT);   \
        }                           \
      else {                        \
        unregister_code(KC_LALT);   \
        unregister_code(KC_RALT);   \
      }                             \
    }                               \
    return false;

  // Inverted gui status
  #define GUI_SWITCH(kc1, kc2)      \
    if (record->event.pressed) {    \
      if (lgui || rgui) {           \
        if (lgui) {                 \
          unregister_code(KC_LGUI); \
        } else {                    \
          unregister_code(KC_RGUI); \
        }                           \
        unregister_code(kc2);       \
        register_code(kc2);         \
      } else {                      \
        if (lgui) {                 \
          register_code(KC_LGUI);   \
        } else {                    \
          register_code(KC_RGUI);   \
        }                           \
        unregister_code(kc1);       \
        register_code(kc1);         \
      }                             \
    } else {                        \
      unregister_code(kc1);         \
      unregister_code(kc2);         \
      if (lgui || rgui)             \
        if (lgui) {                 \
          register_code(KC_LGUI);   \
        } else {                    \
          register_code(KC_RGUI);   \
        }                           \
      else {                        \
        unregister_code(KC_LGUI);   \
        unregister_code(KC_RGUI);   \
      }                             \
    }                               \
    return false;

  // Always shifted
  #define SHIFT_ALL(kc1, kc2)     \
    if (record->event.pressed) {  \
      register_code(KC_LSFT);     \
      if (lshift || rshift) {     \
        unregister_code(kc2);     \
        register_code(kc2);       \
      } else {                    \
        unregister_code(kc1);     \
        register_code(kc1);       \
      }                           \
    } else {                      \
      unregister_code(kc1);       \
      unregister_code(kc2);       \
      if (lshift || rshift)       \
        if (lshift)               \
          register_code(KC_LSFT); \
        else                      \
          register_code(KC_RSFT); \
      else                        \
        unregister_code(KC_LSFT); \
    }                             \
    return false;

  // Always with control
  #define CTRL_ALL(kc1, kc2)      \
    if (record->event.pressed) {  \
      register_code(KC_LCTL);     \
      if (lctrl || rctrl) {       \
        unregister_code(kc2);     \
        register_code(kc2);       \
      } else {                    \
        unregister_code(kc1);     \
        register_code(kc1);       \
      }                           \
    } else {                      \
      unregister_code(kc1);       \
      unregister_code(kc2);       \
      if (lctrl || rctrl)         \
        if (lctrl)                \
          register_code(KC_LCTL); \
        else                      \
          register_code(KC_RCTL); \
      else                        \
        unregister_code(KC_LCTL); \
    }                             \
    return false;

  // Always with alt
  #define ALT_ALL(kc1, kc2)       \
    if (record->event.pressed) {  \
      register_code(KC_LALT);     \
      if (lalt || ralt) {         \
        unregister_code(kc2);     \
        register_code(kc2);       \
      } else {                    \
        unregister_code(kc1);     \
        register_code(kc1);       \
      }                           \
    } else {                      \
      unregister_code(kc1);       \
      unregister_code(kc2);       \
      if (lalt || ralt)           \
        if (lalt)                 \
          register_code(KC_LALT); \
        else                      \
          register_code(KC_RALT); \
      else                        \
        unregister_code(KC_LALT); \
    }                             \
    return false;

  // Always with gui
  #define GUI_ALL(kc1, kc2)       \
    if (record->event.pressed) {  \
      register_code(KC_LGUI);     \
      if (lgui || rgui) {         \
        unregister_code(kc2);     \
        register_code(kc2);       \
      } else {                    \
        unregister_code(kc1);     \
        register_code(kc1);       \
      }                           \
    } else {                      \
      unregister_code(kc1);       \
      unregister_code(kc2);       \
      if (lgui || rgui)           \
        if (lgui)                 \
          register_code(KC_LGUI); \
        else                      \
          register_code(KC_RGUI); \
      else                        \
        unregister_code(KC_LGUI); \
    }                             \
    return false;

  // Never shifted
  #define SHIFT_NO(kc1, kc2)      \
    if (record->event.pressed) {  \
      unregister_code(KC_LSFT);   \
      unregister_code(KC_RSFT);   \
      if (lshift || rshift) {     \
        unregister_code(kc2);     \
        register_code(kc2);       \
      } else {                    \
        unregister_code(kc1);     \
        register_code(kc1);       \
      }                           \
    } else {                      \
      unregister_code(kc1);       \
      unregister_code(kc2);       \
      if (lshift || rshift) {     \
        if (lshift) {             \
          register_code(KC_LSFT); \
        } else {                  \
          register_code(KC_RSFT); \
        }                         \
      } else {                    \
        unregister_code(KC_LSFT); \
        unregister_code(KC_RSFT); \
      }                           \
    }                             \
    return false;

  // Never with Ctrl
  #define CTRL_NO(kc1, kc2)       \
    if (record->event.pressed) {  \
      unregister_code(KC_LCTL);   \
      unregister_code(KC_RCTL);   \
      if (lctrl || rctrl) {       \
        unregister_code(kc2);     \
        register_code(kc2);       \
      } else {                    \
        unregister_code(kc1);     \
        register_code(kc1);       \
      }                           \
    } else {                      \
      unregister_code(kc1);       \
      unregister_code(kc2);       \
      if (lctrl || rctrl) {       \
        if (lctrl) {              \
          register_code(KC_LCTL); \
        } else {                  \
          register_code(KC_RCTL); \
        }                         \
      } else {                    \
        unregister_code(KC_LCTL); \
        unregister_code(KC_RCTL); \
      }                           \
    }                             \
    return false;

  // Never with Alt
  #define ALT_NO(kc1, kc2)        \
    if (record->event.pressed) {  \
      unregister_code(KC_LALT);   \
      unregister_code(KC_RALT);   \
      if (lalt || ralt) {         \
        unregister_code(kc2);     \
        register_code(kc2);       \
      } else {                    \
        unregister_code(kc1);     \
        register_code(kc1);       \
      }                           \
    } else {                      \
      unregister_code(kc1);       \
      unregister_code(kc2);       \
      if (lalt || ralt) {         \
        if (lalt) {               \
          register_code(KC_LALT); \
        } else {                  \
          register_code(KC_RALT); \
        }                         \
      } else {                    \
        unregister_code(KC_LALT); \
        unregister_code(KC_RALT); \
      }                           \
    }                             \
    return false;

  // Never with gui
  #define GUI_NO(kc1, kc2)        \
    if (record->event.pressed) {  \
      unregister_code(KC_LGUI);   \
      unregister_code(KC_RGUI);   \
      if (lgui || rgui) {         \
        unregister_code(kc2);     \
        register_code(kc2);       \
      } else {                    \
        unregister_code(kc1);     \
        register_code(kc1);       \
      }                           \
    } else {                      \
      unregister_code(kc1);       \
      unregister_code(kc2);       \
      if (lgui || rgui) {         \
        if (lgui) {               \
          register_code(KC_LGUI); \
        } else {                  \
          register_code(KC_RGUI); \
        }                         \
      } else {                    \
        unregister_code(KC_LGUI); \
        unregister_code(KC_RGUI); \
      }                           \
    }                             \
    return false;

#endif

// Mouse
#ifdef TAP_DANCE_ENABLE

  #ifdef MOUSEKEY_ENABLE
    // mouse parameters setup
    #define MK_KINETIC_SPEED
  // #        define MOUSEKEY_WHEEL_TIME_TO_MAX 80
  #endif

// Tap Dance declarations
enum tap_dance_codes {
  TD_LSHIFT_MOUSE,
  TD_CTRL_CAPS,
  TD_ADJ_NUM,
  #ifdef KEYBOARD_SHARED_EP
  TD_ESC_GLOBE,
  #endif
};

  // Define the keycode for the tap dance
  #ifdef MOUSEKEY_ENABLE
    #define SFT_MSE TD(TD_LSHIFT_MOUSE)
    #define TG_MSE TG(_EX_MOUSE)
  #else
    #define SFT_MSE KC_LSFT
    #define TG_MSE KC_LSFT
  #endif
  #ifdef KEYBOARD_SHARED_EP
    #define ESC_GLB TD(TD_ESC_GLOBE)
  #else
    #define ESC_GLB KC_ESC
  #endif
  #define CPS_CTL TD(TD_CTRL_CAPS)
  #define TG_NUM TG(_NUM)
  #define TD_ADJ TD(TD_ADJ_NUM)

#else

  #define SFT_MSE KC_LSFT
  #define TG_MSE _______
  #define CPS_CTL CTL_T(KC_CAPS)

#endif

// #define TAPPING_TOGGLE 2
#define M_TG_N1 TG(_MAC_NAV_1)
#define L_TG_N1 TG(_LINUX_NAV_1)
#define W_TG_N1 TG(_WIN_NAV_1)
#define M_TG_N2 TG(_MAC_NAV_2)
#define L_TG_N2 TG(_LINUX_NAV_2)
#define W_TG_N2 TG(_WIN_NAV_2)

#define DF_MAC DF(_QWERTY_MAC)
#define DF_WIN DF(_QWERTY_WIN)
#define DF_LNX DF(_QWERTY_LINUX)
#define DF_NUM DF(_NUM)
#define DF_GMG DF(_GAMING)

// Mac only definitions
#define M_NAV_1 LT(_MAC_NAV_1, KC_D)
#define M_NAV_2 MO(_MAC_NAV_2)
#define M_F_NAV LT(_MAC_NAV_2, KC_F)
#define M_F_WRD A(KC_RIGHT)
#define M_B_WRD A(KC_LEFT)
#define M_YANK G(KC_C)
#define M_PUT G(KC_V)
#define M_DEL G(KC_X)
// Screen capture
#define CAPTURE S(G(KC_5))

// Linux only definitions
#define L_NAV_1 LT(_LINUX_NAV_1, KC_D)
#define L_NAV_2 MO(_LINUX_NAV_2)
#define L_F_NAV LT(_LINUX_NAV_2, KC_F)
#define L_F_WRD A(KC_RIGHT)
#define L_B_WRD A(KC_LEFT)
#define L_YANK C(KC_C)
#define L_PUT C(KC_V)
#define L_DEL C(KC_X)

// Windows only definitions
#define W_NAV_1 LT(_WIN_NAV_1, KC_D)
#define W_NAV_2 MO(_WIN_NAV_2)
#define W_F_NAV LT(_WIN_NAV_2, KC_F)
#define W_F_WRD C(KC_RIGHT)
#define W_B_WRD C(KC_LEFT)
#define W_YANK C(KC_C)
#define W_PUT C(KC_V)
#define W_DEL C(KC_X)
