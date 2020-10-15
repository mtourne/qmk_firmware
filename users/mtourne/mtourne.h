#ifndef MTOURNE_H
#define MTOURNE_H

#include QMK_KEYBOARD_H

// == TIMINGS ==
// =============

#define ALT_TAB_HOLD_DURATION 800

// short tapping term for the spc bar
// TAPPING_TERM_PER_KEY needs to be set in config.h
#define TAPPING_TERM_SPC_FN 200

// short tapping term for modifiers in keeb
// TAPPING_TERM_PER_KEY needs to be set in config.h
#define TAPPING_TERM_IN_KEEB_MODS 150

// long tapping term for a mid keyboard mouse key
#define TAPPING_TERM_MOUSE_KEY 300

// == LAYERS ==
// =============

// common layers
enum mtourne_layers {
   _QWERTY,
   _DVORAK,
   _SPACE_FN,

   // coding (paren, extra)
   _CODING,

   // num / symb / func
   _NUM,
   _NUM_LK,
   _SYMB,
   _FUNC,

   // space + num (for spacemacs movements)
   _SPC_NUM,

   // mouse movements
   _MOUSE,
   _MOUSE_LK,

   _MTOURNE_LAYERS_SAFE_RANGE,
};

// == persistent layer change ==
// =============================

// == options ==
// =============

// #define VERBOSE_DEBUG
// #define DEBUG

#ifdef VERBOSE_DEBUG
#define DEBUG
#endif

// activate one shot shift (in the tap dance for caps)
#define ONESHOT_SFT

// == MODS ==
// ==========

// one shot modifiers
// (holds modifier)
#define KC_OLCTL OSM(MOD_LCTL)
#define KC_ORCTL OSM(MOD_RCTL)

#define KC_OLALT OSM(MOD_LALT)
#define KC_ORALT OSM(MOD_RALT)

#define KC_OLGUI OSM(MOD_LGUI)
#define KC_ORGUI OSM(MOD_RGUI)

// like OSM SHIFT with caps lock
#define KC_SFT_CAPS TD(TD_SFT_CAPS)

// space function
#define KC_SPC_FN  LT(_SPACE_FN, KC_SPC)

// == MACROS ==
// ============
#define KC_LCT(_a) LCTL_T(KC_##_a)
#define KC_LAL(_a) LALT_T(KC_##_a)
#define KC_LGU(_a) LGUI_T(KC_##_a)

#define KC_RCT(_a) RCTL_T(KC_##_a)
#define KC_RAL(_a) RALT_T(KC_##_a)
#define KC_RGU(_a) RGUI_T(KC_##_a)

#define KC_CO(_a) LT(_CODING, KC_##_a)

// L and R are for left or right numpad style
// NUM / SYMB / FUNC
// which both sides are currently on the same layer.
#define KC_LN(_a) LT(_NUM, KC_##_a)
#define KC_LS(_a) LT(_SYMB, KC_##_a)
#define KC_LF(_a) LT(_FUNC, KC_##_a)
#define KC_RN(_a) LT(_NUM, KC_##_a)
#define KC_RS(_a) LT(_SYMB, KC_##_a)
#define KC_RF(_a) LT(_FUNC, KC_##_a)

#define KC_SN(_a) LT(_SPC_NUM, KC_##_a)

// add a control before sending the code
#define KC_CC(_a) LCTL(KC_##_a)

#define KC_MOU(_a) LT(_MOUSE, KC_##_a)
#define MOU(_a) LT(_MOUSE, _a)

#define KC_ADJ MO(_ADJUST)

// ESCC is the ESC that also cancels one shot mods
// it needs to be defined to what the key is currently set at.
#define ESCC KC_ESC

#define KC_LALT(_a) LALT(KC_##_a)

// == LOCKS ==
// ===========
#define NUM_LK  TG(_NUM_LK)
#define KC_NUM_LK NUM_LK

#define MS_LK   TG(_MOUSE_LK)
#define KC_MS_LK MS_LK


// == Tap Dance ==
// ===============

enum {
      TD_SFT_CAPS = 0,
};


// == MISC ==
// ==========
// TODO: on windows-mode should be actual alt+tab
// instead af command + tab.
#define KC_ALTAB  ALT_TAB
#define KC_DVORAK DVORAK
#define KC_QWERTY QWERTY

enum custom_keycodes {
   ALT_TAB = SAFE_RANGE,
   // permanent layer switch
   QWERTY,
   DVORAK,
};

// function defs
bool mtourne_process_record_user(uint16_t keycode, keyrecord_t *record);
void matrix_scan_altab(void);
uint16_t mtourne_get_tapping_term(uint16_t keycode);

#endif
