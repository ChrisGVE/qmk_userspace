#include "chrisgve.h"
#include "action_layer.h"
#include "host.h"

#if defined(TAP_DANCE_ENABLE) && __has_include("quantum/keymap_introspection.h")
  #include "quantum/keymap_introspection.h"
#endif

#if defined(CHRISGVE_CAPS_WORD_ENABLE) && __has_include("quantum/keymap_introspection.h")
  // Ensure introspection sees combo symbols/prototypes early enough when it includes userspace
  #include "quantum/keymap_introspection.h"
#endif

#if defined(CHRISGVE_CAPS_WORD_ENABLE) && defined(CAPS_WORD_ENABLE) && defined(COMBO_ENABLE)
const uint16_t PROGMEM word_caps_gui[] = {KC_LGUI, KC_RGUI, COMBO_END};
const uint16_t PROGMEM word_caps_alt[] = {KC_LALT, KC_RALT, COMBO_END};

combo_t key_combos[] = {
    COMBO(word_caps_gui, QK_CAPS_WORD_TOGGLE),
    COMBO(word_caps_alt, QK_CAPS_WORD_TOGGLE),
};
#endif

#if defined(RGBLIGHT_ENABLE)
  #include "rgblight.h"
#elif defined(RGB_MATRIX_ENABLE)
  #include "rgb_matrix.h"
#endif

#include "print.h"

#ifndef DISABLE_USER_CODE

/*****************************************
 * Helper defines
 *****************************************/

  #if !defined(RGBLIGHT_ENABLE) && !defined(RGB_MATRIX_ENABLE)
    #define NO_RGB
  #endif

/*****************************************
 *
 *   Placeholder functions implementable in the respective keymaps
 *
 *****************************************/

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

__attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state) {
  return state;
}

__attribute__((weak)) void led_set_keymap(uint8_t usb_led) {}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
  return state;
}

  #ifdef RGB_MATRIX_ENABLE
__attribute__((weak)) bool rgb_matrix_indicators_keymap(void) {
  return true;
}
  #endif

/*****************************************
 *
 *   Common code
 *
 *****************************************/

  #ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case S_SHIFT:
    case A_SHIFT:
    case R_SHIFT:
    case S_MOUSE:
    case SFT_MSE:
    case SPC_LWR:
    case SPC_RSE:
    case SLS_SFT:
    case A_MOUSE:
    case M_NAV:
    case L_NAV:
    case W_NAV:
    case F_NAV_2:
    #ifdef DYNAMIC_TAPPING_TERM_ENABLE
      return g_tapping_term;
    #else
      return TAPPING_TERM;
    #endif
    case CPS_CTL:
    case TAB_CTL:
    #ifdef DYNAMIC_TAPPING_TERM_ENABLE
      return g_tapping_term * 0.75;
    #else
      return TAPPING_TERM * 0.75;
    #endif
    default:
    #ifdef DYNAMIC_TAPPING_TERM_ENABLE
      return g_tapping_term / 2;
    #else
      return TAPPING_TERM / 2;
    #endif
  }
}
  #endif

  #ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case TAB_CTL:
    // case CPS_CTL:
    case ADJ_BSL:
    case END_ADJ:
    case PGDN_AD:
    // case SPC_LWR:
    // case SPC_RSE:
    // case M_NAV:
    // case L_NAV:
    // case W_NAV:
    // case F_NAV_2:
    case R_SHIFT:
      // Immediately select the hold action when another key is tapped.
      // return true;
      return true;
    default:
      // Do not select the hold action for other keys
      return false;
  }
}
  #endif

  #ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TAB_CTL:
    case QUT_SFT:
    case CPS_CTL:
    case SFT_MSE:
      // Immediately select the hold action when another key is pressed
      // return true;
      return true;
    default:
      // Do not select the hold action when another key is pressed
      return false;
  }
}
  #endif

  #ifdef IGNORE_MOD_TAP_INTERRUPT_PER_KEY
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Do not force the mod-tap key press to be handled as a modifier
    // if any other key was pressed while the mod-tap key is held down.
    // return true;
    default:
      // Force the mod-tap key press to e handled as a modifier if any
      // other key was pressed while the mod-tap key is held down.
      return false;
  }
}
  #endif

  #ifdef TAPPING_FORCE_HOLD_PER_KEY
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /* case A_MOUSE:
    case M_NAV:
    case L_NAV:
    case W_NAV:
    case F_NAV_2:
    case F_NAV_2:
    case F_NAV_2:
        return true; */
    default:
      return false;
  }
}
  #endif

  #ifdef RETRO_TAPPING_PER_KEY
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    default:
      return false;
  }
}
  #endif

  #if defined(WORD_CAPS_ENABLE) && !defined(AGAR_ENABLE) && defined(COMBO_ENABLE)
const uint16_t PROGMEM word_caps_gui[] = {KC_LGUI, KC_RGUI, COMBO_END};
const uint16_t PROGMEM word_caps_alt[] = {KC_LALT, KC_RALT, COMBO_END};
combo_t                key_combos[]    = {
    COMBO(word_caps_gui, KC_CAPS_WORD_TOGGLE),
    COMBO(word_caps_alt, KC_CAPS_WORD_TOGGLE),
};
  #endif
  // EEPROM user configuration
  #ifndef DISABLE_POST_INIT
typedef union {
  uint8_t raw; // 8 bit configuration
  struct {
    uint8_t default_layer;
  };
} user_config_t;

user_config_t user_config;

void eeconfig_init_user(void) { // EEPROM is getting reset
  user_config.raw = 0;
  eeconfig_update_user(user_config.raw);
  set_single_persistent_default_layer(_QWERTY_MAC);
}
  #endif

// Global variables
enum generic_layer_t {
  _DEF_L,
  _NAV1_L,
  _NAV2_L,
  _ADJ_L,
  _NUM_L,
  _MSE_L,
  _GMG_L,
};

bool    caps_lock             = false;
bool    caps_word             = false;
bool    def_layer             = true;
uint8_t cur_layer             = _DEF_L;
uint8_t current_default_layer = _QWERTY_MAC;
bool    mouse_layer           = false;

  #ifdef MODIFIERS_ENABLE
bool lshift = false;
bool rshift = false;
bool lctrl  = false;
bool rctrl  = false;
bool lalt   = false;
bool ralt   = false;
bool lgui   = false;
bool rgui   = false;
  #endif

  // Host OS Detection
  #if defined(OS_DETECTION_ENABLE) && !defined(DISABLE_LAYER_TRACKING)
bool process_detected_host_os_kb(os_variant_t detected_os) {
  if (!process_detected_host_os_user(detected_os)) {
    return false;
  }
    #ifndef DISABLE_POST_INIT
  if (user_config.default_layer) {
    return true;
  }
    #endif
  switch (detected_os) {
    case OS_MACOS:
    case OS_IOS:
      default_layer_set(_QWERTY_MAC);
      current_default_layer = _QWERTY_MAC;
      break;
    case OS_LINUX:
      default_layer_set(_QWERTY_LINUX);
      current_default_layer = _QWERTY_LINUX;
      break;
    case OS_WINDOWS:
      default_layer_set(_QWERTY_WIN);
      current_default_layer = _QWERTY_WIN;
      break;
    case OS_UNSURE:
      break;
  }
  return true;
}
  #endif

  // Tap dance configuration
  #ifdef TAP_DANCE_ENABLE

typedef struct {
  uint16_t tap;
  uint16_t hold;
  uint16_t held;
} tap_dance_tap_hold_t;

// Define a type containing the tapdance states to be tested
typedef enum { TD_NONE, TD_UNKNOWN, TD_SINGLE_TAP, TD_SINGLE_HOLD, TD_DOUBLE_SINGLE_TAP } td_state_t;

// Global instance of the tapdance state type
static td_state_t td_state;

    #ifdef AGAR_ENABLE
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    #else
td_state_t cur_dance(tap_dance_state_t *state) {
    #endif
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)
      return TD_SINGLE_TAP;
    else
      return TD_SINGLE_HOLD;
  }

  if (state->count == 2)
    return TD_DOUBLE_SINGLE_TAP;
  else
    return TD_UNKNOWN;
}

    #ifdef AGAR_ENABLE
void cps_ctl_finished(qk_tap_dance_state_t *state, void *user_data) {
    #else
void cps_ctl_finished(tap_dance_state_t *state, void *user_data) {
    #endif
  td_state = cur_dance(state);
  switch (td_state) {
    case TD_SINGLE_TAP:
      if (caps_lock) {
        register_code16(KC_CAPS);
      }
      break;
    case TD_SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LCTL));
      break;
    case TD_DOUBLE_SINGLE_TAP:
      register_code16(KC_CAPS);
      break;
    default:
      break;
  }
}

    #ifdef AGAR_ENABLE
void cps_ctl_reset(qk_tap_dance_state_t *state, void *user_data) {
    #else
void cps_ctl_reset(tap_dance_state_t *state, void *user_data) {
    #endif
  switch (td_state) {
    case TD_SINGLE_TAP:
      if (caps_lock) {
        unregister_code16(KC_CAPS);
      }
      break;
    case TD_SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LCTL));
      break;
    case TD_DOUBLE_SINGLE_TAP:
      unregister_code16(KC_CAPS);
      break;
    default:
      break;
  }
}

    #ifdef AGAR_ENABLE
void tap_dance_tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
    #else
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    #endif
  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

  if (state->pressed) {
    if (state->count == 1
    #ifndef PERMISSIVE_HOLD
        && !state->interrupted
    #endif
    ) {
      register_code16(tap_hold->hold);
      tap_hold->held = tap_hold->hold;
    } else {
      register_code16(tap_hold->tap);
      tap_hold->held = tap_hold->tap;
    }
  }
}

    #ifdef KEYBOARD_SHARED_EP

      #ifdef AGAR_ENABLE
void tap_dance_tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
      #else
void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
      #endif
  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

  if (tap_hold->held) {
    unregister_code16(tap_hold->held);
    tap_hold->held = 0;
  }
}

      #define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)                                      \
        {                                                                               \
            .fn        = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, \
            .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}),               \
        }

    #endif

    // Tap Dance definition
    #ifdef AGAR_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
    #else
tap_dance_action_t tap_dance_actions[] = {
    #endif
    // Tap once or Shift, twice for mouse layer
    #ifdef MOUSEKEY_ENABLE
  [TD_LSHIFT_MOUSE] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LSFT, _EX_MOUSE),
    #endif
  [TD_ADJ_NUM]   = ACTION_TAP_DANCE_LAYER_TOGGLE(ADJUST, _NUM),
  [TD_CTRL_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cps_ctl_finished, cps_ctl_reset),
    #ifdef KEYBOARD_SHARED_EP
  [TD_ESC_GLOBE] = ACTION_TAP_DANCE_TAP_HOLD(KC_ESC, KC_GLOBE),
    #endif
};

  #endif

// RGB Handling

  #ifndef NO_RGB

void set_hsv(uint8_t hue, uint8_t sat, uint8_t val) {
    #if defined(RGB_MATRIX_ENABLE)
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  rgb_matrix_sethsv_noeeprom(hue, sat, val);
    #elif defined(RGBLIGHT_ENABLE)
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_sethsv(hue, sat, val);
  dprintf("hue:%i sat:%i val:%i", hue, sat, val);
    #endif
}

void set_nav_1_hsv(void) {
  set_hsv(HSV_NAV1);
}

void set_nav_2_hsv(void) {
  set_hsv(HSV_NAV2);
}

void set_caps_hsv(void) {
  set_hsv(HSV_CAPS); // Warm white
}

void set_adj_hsv(void) {
  set_hsv(HSV_ADJ);
}

void set_mse_hsv(void) {
  set_hsv(HSV_MSE);
}

void set_win_hsv(void) {
  set_hsv(HSV_WIN);
}

void set_lnx_hsv(void) {
  set_hsv(HSV_LNX);
}

void set_num_hsv(void) {
  set_hsv(HSV_NUM);
}

void rgb_off(void) {
  set_hsv(HSV_OFF);
}

void set_gmg_hsv(void) {
    #if defined(LGT_GMG_ON) && defined(RGB_MATRIX_ENABLE)
  rgb_matrix_enable_noeeprom();
  rgb_matrix_mode_noeeprom(LGT_GMG_ON);
    #elif defined(LGT_GMG_ON) && defined(RGBLIGHT_ENABLE)
  rgblight_enable_noeeprom();
  rgblight_mode_noeeprom(LGT_GMG_ON);
      /* rgblight_sethsv_noeeprom(0, 0, 255); */
    #endif
}

void update_hsv(void) {
  if (current_default_layer == _GAMING) return; // if we are in gaming mode we do nothing
  if ((caps_lock || caps_word) && def_layer) {
    set_caps_hsv();
  } else if (mouse_layer) {
    set_mse_hsv();
  } else if (def_layer) {
    switch (current_default_layer) {
      case _QWERTY_MAC:
        rgb_off();
        break;
      case _QWERTY_WIN:
        set_win_hsv();
        break;
      case _QWERTY_LINUX:
        set_lnx_hsv();
        break;
      case _NUM:
        set_num_hsv();
        break;
      default: // We don't change the gaming layer
        break;
    }
  } else {
    switch (cur_layer) {
      case _NAV1_L:
        set_nav_1_hsv();
        break;
      case _NAV2_L:
        set_nav_2_hsv();
        break;
      case _ADJ_L:
        set_adj_hsv();
        break;
      default:
        break;
    }
  }
}

  #endif

bool update_indicator(void) {
  #ifndef NO_RGB
  update_hsv();
  #endif
  #ifdef LED_CAPS_LOCK_PIN
  bool state = caps_lock | caps_word;
  gpio_write_pin(LED_CAPS_LOCK_PIN, state);
  #endif
  return true;
}

  #ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
  if (!rgb_matrix_indicators_keymap()) {
    #ifdef LK_WIRELESS_ENABLE
    return true; // Allow Keychron wireless indicators to be processed
    #else
    return false;
    #endif
  }
  bool caps_lock_host = host_keyboard_led_state().caps_lock;
    #ifdef LK_WIRELESS_ENABLE
  caps_lock = caps_lock_host;
  update_indicator();
  return true; // Allow Keychron wireless indicators to be processed
    #else
  if (caps_lock == caps_lock_host) return false; // no change, thus nothing to do
  caps_lock = caps_lock_host;
  if (current_default_layer == _GAMING) return false; // if in gaming mode do nothing
  return update_indicator();
    #endif
}
  #endif

bool led_update_user(led_t led_state) {
  if (caps_lock == led_state.caps_lock) return false; // no change, thus nothing to do
  caps_lock = led_state.caps_lock;
  if (current_default_layer == _GAMING) return false; // if in gaming mode do nothing
  return update_indicator();
}

void caps_word_set_user(bool active) {
  if (caps_word == active) return;
  caps_word = active;
  if (current_default_layer != _GAMING) {
    update_indicator();
  }
}

  #ifndef DISABLE_LAYER_TRACKING
layer_state_t default_layer_state_set_user(layer_state_t state) {
  dprint("default_layer_state_set_user");
  if (!layer_state_cmp(state, current_default_layer)) {
    if (layer_state_cmp(state, _QWERTY_MAC)) {
      current_default_layer = _QWERTY_MAC;
    #ifndef NO_RGB
      rgb_off();
    #endif
    } else if (layer_state_cmp(state, _QWERTY_WIN)) {
      current_default_layer = _QWERTY_WIN;
    #ifndef NO_RGB
      set_win_hsv();
    #endif
    } else if (layer_state_cmp(state, _QWERTY_LINUX)) {
      current_default_layer = _QWERTY_LINUX;
    #ifndef NO_RGB
      set_lnx_hsv();
    #endif
    } else if (layer_state_cmp(state, _GAMING)) {
      current_default_layer = _GAMING;
    #ifndef NO_RGB
      set_gmg_hsv();
    #endif
    } else if (layer_state_cmp(state, _EX_MOUSE)) {
      current_default_layer = _EX_MOUSE;
    #ifndef NO_RGB
      set_mse_hsv();
    #endif
    } else if (layer_state_cmp(state, _NUM)) {
      current_default_layer = _NUM;
    #ifndef NO_RGB
      set_num_hsv();
    #endif
    }
    def_layer = true;
  }
  // Board specific handling
  return default_layer_state_set_keymap(state);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case _QWERTY_MAC:
      cur_layer   = _DEF_L;
      def_layer   = true;
      mouse_layer = false;
      break;
    case _QWERTY_LINUX:
      cur_layer   = _DEF_L;
      def_layer   = true;
      mouse_layer = false;
      break;
    case _QWERTY_WIN:
      cur_layer   = _DEF_L;
      def_layer   = true;
      mouse_layer = false;
      break;
    case _NUM:
      cur_layer   = _NUM_L;
      def_layer   = true;
      mouse_layer = false;
      break;
    case _EX_MOUSE:
      cur_layer   = _MSE_L;
      def_layer   = true;
      mouse_layer = true;
    case _GAMING:
      cur_layer = _GMG_L;
      def_layer = true;
      break;
    case _MAC_NAV:
    case _LINUX_NAV:
    case _WIN_NAV:
      cur_layer   = _NAV1_L;
      def_layer   = false;
      mouse_layer = false;
      break;
    case _NAV_2:
      cur_layer   = _NAV2_L;
      def_layer   = false;
      mouse_layer = false;
      break;
    case _ADJUST:
      cur_layer   = _ADJ_L;
      def_layer   = false;
      mouse_layer = false;
      break;
    /* case _MOUSE: */
    /*   cur_layer   = _MSE_L; */
    /*   def_layer   = false; */
    /*   mouse_layer = true; */
    /*   break; */
    default:
      cur_layer   = _DEF_L;
      def_layer   = true;
      mouse_layer = false;
  }

    #ifndef NO_RGB
  update_hsv();
    #endif
  // Board specific handling
  return layer_state_set_keymap(state);
}
  #endif

  #ifndef DISABLE_POST_INIT
// Keyboard post init
void keyboard_post_init_user(void) {
  // Read the user config from EEPROM
  user_config.raw       = eeconfig_read_user();
  current_default_layer = user_config.default_layer;

    // Init RGB
    #if !defined(NO_RGB) && defined(RGBLIGHT_ENABLE)
  rgblight_enable_noeeprom();
    #elif !defined(NO_RGB)
  rgb_matrix_enable();
    #endif

    #ifndef NO_RGB
  if (current_default_layer == _GAMING) {
    set_gmg_hsv();
  } else {
    update_hsv();
  }
    #endif

    // Init debug
    #ifdef DEBUG
  /* debug_enable   = true; */
  /* debug_matrix   = true; */
  debug_keyboard = true;
      #ifdef MOUSEKEY_ENABLE
      /* debug_mouse = true; */
      #endif
  dprint("keyboard_post_init_user() -- debug init");
    #endif

  // Call specific board initialization
  keyboard_post_init_keymap();
}
  #endif

// Key handling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #if defined(TAP_DANCE_ENABLE) && defined(KEYBOARD_SHARED_EP) && defined(AGAR_ENABLE)
  qk_tap_dance_action_t *action;
  #elif defined(TAP_DANCE_ENABLE) && defined(KEYBOARD_SHARED_EP)
  tap_dance_action_t *action;
  tap_dance_state_t  *state;
  #endif

  switch (keycode) {
  #if defined(TAP_DANCE_ENABLE) && defined(KEYBOARD_SHARED_EP)
    case TD(TD_ESC_GLOBE): // list all tap dance keycodes with tap-hold configurations
    #ifdef KEYCHRON_ENABLE
      action = &tap_dance_action[QK_TAP_DANCE_GET_INDEX(keycode)];
      if (!record->event.pressed && action->state.count && !action->state.finished)
    #else
      action = tap_dance_get(QK_TAP_DANCE_GET_INDEX(keycode));
      state  = tap_dance_get_state(QK_TAP_DANCE_GET_INDEX(keycode));
      if (!record->event.pressed && state->count && !state->finished) {
    #endif
        tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
      tap_code16(tap_hold->tap);
  }
  break;
  #endif
  /* Ensure that KC_GLOBE is emitted only when the base layer is _QWERTY_MAC */
  #if defined(KEYBOARD_SHARED_EP) && !defined(DISABLE_LAYER_TRACKING)
  case KC_GLOBE:
    if (current_default_layer != _QWERTY_MAC) {
      // --> Inject a NOP keycode since we are not supposed to have globe on anything but mac keyboard
      // i.e. we stop processing this key
      return false;
    }
    break;
  #elif defined(KEYBOARD_SHARED_EP)
    case KC_GLOBE:
      break;
  #endif
  /* Set the default persistent layer */
  case DF_M_P:
    if (!record->event.pressed) {
  #if !defined(DISABLE_LAYER_TRACKING) && !defined(DISABLE_POST_INIT)
      if (user_config.default_layer != _QWERTY_MAC) { // only if there is actually a change
        user_config.default_layer = _QWERTY_MAC;
        eeconfig_update_user(user_config.raw);
      }
  #endif
  #ifndef DISABLE_LAYER_TRACKING
      current_default_layer = _QWERTY_MAC;
  #endif
      set_single_persistent_default_layer(_QWERTY_MAC);
      return false;
    }
    break;
  case DF_L_P:
    if (!record->event.pressed) {
  #if !defined(DISABLE_LAYER_TRACKING) && !defined(DISABLE_POST_INIT)
      if (user_config.default_layer != _QWERTY_LINUX) { // only if there is actually a change
        user_config.default_layer = _QWERTY_LINUX;
        eeconfig_update_user(user_config.raw);
      }
  #endif
  #ifndef DISABLE_LAYER_TRACKING
      current_default_layer = _QWERTY_LINUX;
  #endif
      set_single_persistent_default_layer(_QWERTY_LINUX);
      return false;
    }
    break;
  case DF_W_P:
    if (!record->event.pressed) {
  #if !defined(DISABLE_LAYER_TRACKING) && !defined(DISABLE_POST_INIT)
      if (user_config.default_layer != _QWERTY_WIN) { // only if there is actually a change
        user_config.default_layer = _QWERTY_WIN;
        eeconfig_update_user(user_config.raw);
      }
  #endif
  #ifndef DISABLE_LAYER_TRACKING
      current_default_layer = _QWERTY_WIN;
  #endif
      set_single_persistent_default_layer(_QWERTY_WIN);
      return false;
    }
    break;
  case DF_G_P:
    if (!record->event.pressed) {
  #if !defined(DISABLE_LAYER_TRACKING) && !defined(DISABLE_POST_INIT)
      if (user_config.default_layer != _GAMING) { // only if there is actually a change
        user_config.default_layer = _GAMING;
        eeconfig_update_user(user_config.raw);
      }
  #endif
  #ifndef DISABLE_LAYER_TRACKING
      current_default_layer = _GAMING;
  #endif
      set_single_persistent_default_layer(_GAMING);
      return false;
    }
    break;
  #ifdef MODIFIERS_ENABLE
  /* Monitor shift state */
  case SFT_MSE:
  case KC_LSFT:
    if (record->event.pressed) {
      lshift = true;
    } else {
      lshift = false;
    }

    break;
  case QUT_SFT:
  case R_SHIFT:
  case KC_RSFT:
    if (record->event.pressed) {
      rshift = true;
    } else {
      rshift = false;
    }
    break;
  case TAB_CTL:
  case CPS_CTL:
  case KC_LCTL:
    if (record->event.pressed) {
      lctrl = true;
    } else {
      lctrl = false;
    }
    break;
  case KC_RCTL:
    if (record->event.pressed) {
      rctrl = true;
    } else {
      rctrl = false;
    }
    break;
  case KC_LALT:
    if (record->event.pressed) {
      lalt = true;
    } else {
      lalt = false;
    }
    break;
  case KC_RALT:
    if (record->event.pressed) {
      ralt = true;
    } else {
      ralt = false;
    }
    break;
  case KC_LGUI:
    if (record->event.pressed) {
      lgui = true;
    } else {
      lgui = false;
    }
    break;
  case KC_RGUI:
    if (record->event.pressed) {
      rgui = true;
    } else {
      rgui = false;
    }
    break;
  case CU_BSPC:
    // SHIFT_NO(KC_BSPC, KC_DEL)
    CTRL_NO(KC_BSPC, KC_DEL)
  #endif
  #ifdef MACROS_ENABLED
      /* Standard macros */
  #endif
  default:
    break;
}

// Board specific handling
return process_record_keymap(keycode, record);
}

#endif
