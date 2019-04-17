#ifndef MTOURNE_H
#define MTOURNE_H

#include QMK_KEYBOARD_H

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

#define KC_OCTL OSM(MOD_LCTL)
#define KC_OALT OSM(MOD_LALT)
#define KC_OGUI OSM(MOD_LGUI)

// space function
#define KC_SPC_FN  LT(_SPACE_FN, KC_SPC)

// == MACROS ==
// ============
#define KC_CT(_a) CTL_T(KC_##_a)
#define KC_AL(_a) ALT_T(KC_##_a)
#define KC_GU(_a) GUI_T(KC_##_a)

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

#define KC_CC(_a) LCTL(KC_##_a)

#define KC_MOU(_a) LT(_MOUSE, KC_##_a)
#define MOU(_a) LT(_MOUSE, _a)

#define KC_ADJ MO(_ADJUST)

// ESCC is the ESC that also cancels one shot mods
// it needs to be defined to what the key is currently set at.
#define ESCC KC_ESC

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
#define KC_ALTAB ALT_TAB


enum custom_keycodes {
   ALT_TAB = SAFE_RANGE,
   // permanent layer switch
   QWERTY,
   DVORAK,
};

// function defs
bool mtourne_process_record_user(uint16_t keycode, keyrecord_t *record);

void matrix_scan_altab(void);

#endif
