# Bootloader selection
BOOTLOADER = atmel-dfu #caterina

LTO_ENABLE = yes

# APPLE_FN_ENABLE = yes
NKRO_ENABLE = yes

SRC += chrisgve.c

# REDUCE_RGB = yes
RGB_MATRIX_ENABLE = no
MOUSEKEY_ENABLE = yes
# TAP_DANCE_ENABLE = yes

# Both are needed for CAPS_WORD since shift cannot be used
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
