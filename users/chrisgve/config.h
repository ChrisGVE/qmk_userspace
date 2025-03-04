// Standard config

#ifdef TAPPING_TERM
  #undef TAPPING_TERM
#endif

#define TAPPING_TERM 200

// DEBOUNCE

#ifdef REMOVE_DEBOUNCE
  #ifdef DEBOUNCE
    #undef DEBOUNCE
  #endif
#endif

// #define RGB_MATRIX_DISABLE_SHARED_KEYCODES

#ifdef REDUCE_RGB

// Matrix RGB

  #define ENABLE_RGB_MATRIX_RAINBOW_BEACON

  #ifdef ENABLE_RGB_MATRIX_ALPHAS_MODS
    #undef ENABLE_RGB_MATRIX_ALPHAS_MODS
  #endif

  #ifdef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
  #endif

  #ifdef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
  #endif

  #ifdef ENABLE_RGB_MATRIX_BREATHING
    #undef ENABLE_RGB_MATRIX_BREATHING
  #endif

  #ifdef ENABLE_RGB_MATRIX_BAND_SAT
    #undef ENABLE_RGB_MATRIX_BAND_SAT
  #endif

  #ifdef ENABLE_RGB_MATRIX_BAND_VAL
    #undef ENABLE_RGB_MATRIX_BAND_VAL
  #endif

  #ifdef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
  #endif

  #ifdef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
  #endif

  #ifdef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
  #endif

  #ifdef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
  #endif

  #ifdef ENABLE_RGB_MATRIX_CYCLE_ALL
    #undef ENABLE_RGB_MATRIX_CYCLE_ALL
  #endif

  #ifdef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
  #endif

  #ifdef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
  #endif

  #ifdef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  #endif

  #ifdef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
  #endif

  #ifdef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
  #endif

  #ifdef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
  #endif

  #ifdef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    #undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
  #endif

  #ifdef ENABLE_RGB_MATRIX_DUAL_BEACON
    #undef ENABLE_RGB_MATRIX_DUAL_BEACON
  #endif

  #ifdef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
  #endif

  #ifdef ENABLE_RGB_MATRIX_FLOWER_BLOOMING
    #undef ENABLE_RGB_MATRIX_FLOWER_BLOOMING
  #endif

  #ifdef ENABLE_RGB_MATRIX_RAINDROPS
    #undef ENABLE_RGB_MATRIX_RAINDROPS
  #endif

  #ifdef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
  #endif

  #ifdef ENABLE_RGB_MATRIX_HUE_BREATHING
    #undef ENABLE_RGB_MATRIX_HUE_BREATHING
  #endif

  #ifdef ENABLE_RGB_MATRIX_HUE_PENDULUM
    #undef ENABLE_RGB_MATRIX_HUE_PENDULUM
  #endif

  #ifdef ENABLE_RGB_MATRIX_HUE_WAVE
    #undef ENABLE_RGB_MATRIX_HUE_WAVE
  #endif

  #ifdef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
    #undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
  #endif

  #ifdef ENABLE_RGB_MATRIX_PIXEL_FLOW
    #undef ENABLE_RGB_MATRIX_PIXEL_FLOW
  #endif

  #ifdef ENABLE_RGB_MATRIX_PIXEL_RAIN
    #undef ENABLE_RGB_MATRIX_PIXEL_RAIN
  #endif

  #ifdef ENABLE_RGB_MATRIX_STARLIGHT
    #undef ENABLE_RGB_MATRIX_STARLIGHT
  #endif

  #ifdef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
    #undef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
  #endif

  #ifdef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
    #undef ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
  #endif

  #ifdef ENABLE_RGB_MATRIX_RIVERFLOW
    #undef ENABLE_RGB_MATRIX_RIVERFLOW
  #endif

  #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
  #endif

  #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
  #endif

  #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
  #endif

  #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
  #endif

  #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
  #endif

  #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  #endif

  #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  #endif

  #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
  #endif

  #ifdef ENABLE_RGB_MATRIX_SPLASH
    #undef ENABLE_RGB_MATRIX_SPLASH
  #endif

  #ifdef ENABLE_RGB_MATRIX_MULTISPLASH
    #undef ENABLE_RGB_MATRIX_MULTISPLASH
  #endif

  #ifdef ENABLE_RGB_MATRIX_SOLID_SPLASH
    #undef ENABLE_RGB_MATRIX_SOLID_SPLASH
  #endif

  #ifdef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
    #undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
  #endif

// RGB lighting

  #ifdef RGBLIGHT_EFFECT_ALTERNATING
    #undef RGBLIGHT_EFFECT_ALTERNATING
  #endif

  #ifdef RGBLIGHT_EFFECT_BREATHING
    #undef RGBLIGHT_EFFECT_BREATHING
  #endif

  #ifdef RGBLIGHT_EFFECT_CHRISTMAS
    #undef RGBLIGHT_EFFECT_CHRISTMAS
  #endif

  #ifdef RGBLIGHT_EFFECT_KNIGHT
    #undef RGBLIGHT_EFFECT_KNIGHT
  #endif

  #ifdef RGBLIGHT_EFFECT_RAINBOW_MOOD
    #undef RGBLIGHT_EFFECT_RAINBOW_MOOD
  #endif

  #ifdef RGBLIGHT_EFFECT_RGB_TEST
    #undef RGBLIGHT_EFFECT_RGB_TEST
  #endif

  #ifdef RGBLIGHT_EFFECT_SNAKE
    #under RGBLIGHT_EFFECT_SNAKE
  #endif

  #ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    #undef RGBLIGHT_EFFECT_STATIC_GRADIENT
  #endif

  #ifdef RGBLIGHT_EFFECT_TWINKLE
    #undef RGBLIGHT_EFFECT_TWINKLE
  #endif

#endif
