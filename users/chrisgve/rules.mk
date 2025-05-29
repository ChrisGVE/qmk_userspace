BOOTMAGIC_ENABLE = yes
OS_DETECTION_ENABLE = no # must be explicitly enabled
LTO_ENABLE = yes
SHIFT_ENABLE = yes
STENO_ENABLE = no
MIDI_ENABLE = no
TAP_DANCE_ENABLE = yes
NKRO_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes

# Both are needed for CAPS_WORD since shift cannot be used
CAPS_WORD_ENABLE = yes

ifeq ($(strip $(COMBO_ENABLE)), no)
	COMBO_ENABLE = no
else
	COMBO_ENABLE = yes
endif

# Enable the KC_GLOBE key
KEYBOARD_SHARED_EP = yes

ifeq ($(strip $(DEBUG)), yes)
	OPT_DEFS += -DDEBUG
	CONSOLE_ENABLE = yes
	COMMAND_ENABLE = yes
	# NKRO_ENABLE = no
	# EXTRAKEYS_ENABLE = no
	# MOUSEKEY_ENABLE = no
	#    CAPS_WORD_ENABLE = no
else
	MOUSEKEY_ENABLE = yes
	COMMAND_ENABLE = no
	CONSOLE_ENABLE = no
	NKRO_ENABLE= yes
	EXTRAKEYS_ENABLE = yes
	CAPS_WORD_ENABLE = yes
endif

ifdef TAP_DANCE_ENABLE
	INTROSPECTION_KEYMAP_C = chrisgve.c
else
	SRC += chrisgve.c
endif

ifdef USER_NAME
	ifeq ($(strip $(USER_NAME)), chrisgve)
		OPT_DEFS += -DCHRISGVE
	endif
endif

ifeq ($(strip $(AGAR_ENABLE)), yes)
	OPT_DEFS += -DAGAR_ENABLE
endif

ifeq ($(strip $(DISABLE_USER_CODE)), yes)
	OPT_DEFS += -DDISABLE_USER_CODE
endif

ifeq ($(strip $(DISABLE_LAYER_TRACKING)), yes)
	OPT_DEFS += -DDISABLE_LAYER_TRACKING
endif

ifeq ($(strip $(DISABLE_POST_INIT)), yes)
	OPT_DEFS += -DDISABLE_POST_INIT
endif

ifeq ($(strip $(REDUCE_RGB)), yes)
	OPT_DEFS += -DREDUCE_RGB
endif

ifeq ($(strip $(MACROS_ENABLE)), yes)
	OPT_DEFS += -DMACROS_ENABLE
endif

ifeq ($(strip $(REMOVE_DEBOUNCE)), yes)
	OPT_DEFS += -DREMOVE_DEBOUNCE
endif

ifeq ($(strip $(MODIFIERS_ENABLE)), yes)
	OPT_DEFS += -DMODIFIERS_ENABLE
endif

ifeq ($(strip $(TAPPING_TERM_PER_KEY)), yes)
	OPT_DEFS += -DTAPPING_TERM_PER_KEY
endif

ifeq ($(strip $(RGBLIGHT_DISABLE)), yes)
	OPT_DEFS += -DRGBLIGHT_DISABLE
endif

ifeq ($(strip $(PERMISSIVE_HOLD_PER_KEY)), yes)
	OPT_DEFS += -DPERMISSIVE_HOLD_PER_KEY
endif

ifeq ($(strip $(HOLD_ON_OTHER_KEY_PRESS_PER_KEY)), yes)
	OPT_DEFS += -DHOLD_ON_OTHER_KEY_PRESS_PER_KEY
endif

ifeq ($(strip $(RETRO_TAPPING_PER_KEY)), yes)
	OPT_DEFS += -DRETRO_TAPPING_PER_KEY
endif

ifeq ($(strip $(TAPPING_FORCE_HOLD_PER_KEY)), yes)
	OPT_DEFS += -DTAPPING_FORCE_HOLD_PER_KEY
endif

ifeq ($(strip $(PERMISSIVE_HOLD)), yes)
	OPT_DEFS += -DPERMISSIVE_HOLD
endif

ifeq ($(strip $(DYNAMIC_TAPPING_TERM_ENABLE)), yes)
	OPT_DEFS += -DDYNAMIC_TAPPING_TERM_ENABLE
endif
