#pragma once

// Agar keyboard compatibility layer
#ifdef AGAR_ENABLE

// Basic type definitions
typedef uint8_t td_state_t;
typedef struct {
    uint16_t keycode;
    uint8_t count;
    bool finished:1;
    bool pressed:1;
} tap_dance_state_t;

typedef struct {
    uint16_t kc1;
    uint16_t kc2;
    uint8_t  layer;
    void (*layer_function)(uint8_t);
} tap_dance_dual_role_t;

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

// Keycode compatibility
#define KC_GLOBE KC_APP  // Using KC_APP as a substitute for KC_GLOBE
#define KC_GLB KC_GLOBE
#define QK_CAPS_WORD_TOGGLE KC_CAPS_LOCK

// Original tap dance macros
#define ACTION_TAP_DANCE_LAYER_TOGGLE(kc, layer) { \
    .fn = {NULL, tap_dance_dual_role_finished, tap_dance_dual_role_reset}, \
    .user_data = (void *)&((tap_dance_dual_role_t){kc, KC_NO, layer, layer_toggle}) \
}

#define ACTION_TAP_DANCE_FN_ADVANCED(on_each_tap, on_dance_finished, on_dance_reset) { \
    .fn = {on_each_tap, on_dance_finished, on_dance_reset}, \
    .user_data = NULL \
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) { \
    .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, \
    .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}) \
}

// Forward function declarations
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data);
void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data);
void tap_dance_dual_role_finished(tap_dance_state_t *state, void *user_data);
void tap_dance_dual_role_reset(tap_dance_state_t *state, void *user_data);
void cps_ctl_finished(tap_dance_state_t *state, void *user_data);
void cps_ctl_reset(tap_dance_state_t *state, void *user_data);

#endif