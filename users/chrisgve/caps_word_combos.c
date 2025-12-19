
#include QMK_KEYBOARD_H

#if defined(CHRISGVE_CAPS_WORD_ENABLE)
  // Ensure introspection sees combo symbols/prototypes early enough when it includes userspace
  #if __has_include("quantum/keymap_introspection.h")
    #include "quantum/keymap_introspection.h"
  #endif

  #if defined(CAPS_WORD_ENABLE) && defined(COMBO_ENABLE)

const uint16_t PROGMEM word_caps_gui[] = {KC_LGUI, KC_RGUI, COMBO_END};
const uint16_t PROGMEM word_caps_alt[] = {KC_LALT, KC_RALT, COMBO_END};

combo_t key_combos[] = {
    COMBO(word_caps_gui, QK_CAPS_WORD_TOGGLE),
    COMBO(word_caps_alt, QK_CAPS_WORD_TOGGLE),
};

  #endif

#endif
