// insipred from hasu hhkb keymap
#include "infinity60.h"

#include QMK_KEYBOARD_H

// Layers.
#define QWER 0
#define DVOR 1
#define HHKB 2
#define UTIL 4

// Easier-to-read Layer Arrays.
#define ____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|ESC|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Bspc|
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn0|
     * |-----------------------------------------------------------'
     * |     |Alt|  Gui|         Space         |Gui  |Alt|   |     |
     * `-----------------------------------------------------------'
z     */
    [QWER] = KEYMAP(
        KC_GRV,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,           KC_MINS,KC_EQL, KC_BSLS, KC_ESC, \
        KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,           KC_LBRC,KC_RBRC,KC_BSPC, \
        KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_RSFT, MO(HHKB), \
        KC_NO,     KC_LALT, KC_LGUI,         LT(UTIL, KC_SPC),              KC_RGUI, KC_RALT, KC_NO, KC_NO),
    // TODO (mtourne) find usage for the 3 NO keys bottom row.

    /* DVOR: hardwired dvorak (works with US layout)
     * ,--------------------------------------------------------------.
     * |`  |    1 |  2|  3|  4|  5|  6|  7|  8|  9|  0|  [|  ]|  \|Esc|
     * |--------------------------------------------------------------|
     * |Tab  |     '|  ,|  .|  P|  Y|  F|  G|  C|  R|  L|  /|  =|Backs|
     * |--------------------------------------------------------------|
     * |Ctrl  |     A|  O|  E|  U|  I|  D|  H|  T|  N|  S|  -|     Ent|
     * |--------------------------------------------------------------|
     * |Shift   |     ;|  Q|  J|  K|  X|  B|  M|  W|  V|  Z|Shift |Fn0|
     * `--------------------------------------------------------------'
     *       |Alt|Gui  |       Space/UTIL      |Gui  |Alt|
     *       `-------------------------------------------'
     */
    [DVOR] = KEYMAP(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_LBRC, KC_RBRC, KC_BSLS, KC_ESC,
        KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_EQL, KC_BSPC,
        KC_LCTL, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_ENT,
        KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT, MO(HHKB),
        KC_NO, KC_LALT, KC_LGUI, LT(UTIL, KC_SPC), KC_RGUI, KC_RALT, KC_NO, KC_NO),

    /* Layer 1: HHKB mode (HHKB Fn)
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |PLA|PRV|NXT|   |   |   |   |Psc|Slk|Pus|Up |   |Backs|
     * |-----------------------------------------------------------|
     * |      |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |        |QWE|DVO|   |   |   |  +|  -|End|PgD|Dow|      |   |
     * `-----------------------------------------------------------'
     * |     |   |     |                       |STOP |   |   |     |
     * `-----------------------------------------------------------'
     */
    [HHKB] = KEYMAP(
        KC_PWR, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL, \
        KC_CAPS, KC_MPLY, KC_MPRV, KC_MNXT,____,____,____,____,KC_PSCR,KC_SLCK,KC_PAUS, KC_UP,  ____,KC_BSPC, \
        ____, KC_VOLD,KC_VOLU,KC_MUTE,____,____,KC_PAST,KC_PSLS,KC_HOME,KC_PGUP,KC_LEFT,KC_RGHT,KC_ENT, \
        ____, DF(QWER), DF(DVOR),____,____,____,KC_PPLS,KC_PMNS,KC_END, KC_PGDN,KC_DOWN,____,____, \
        ____, ____,    ____ ,          ____,                      KC_MSTP, ____,____,____),

    /* UTIL Layer: Extra utilities
     *
     * ,-------------------------------------------------------------.
     * |ESC|  F1|  F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |   |
     * |-------------------------------------------------------------|
     * |     |     |M-1|M-U|M-2|MwU|PuP|L-wd| UP|Rwd|   |   |   |    |
     * |-------------------------------------------------------------|
     * |      |    |M-Lt|M-D|M-R|MwD|PdW|LEF|DOW|RIG|   |   |        |
     * |-------------------------------------------------------------|
     * |        |    |    |   |   |SPC|BKS|Del|   |   |   |      |   |
     * `-------------------------------------------------------------'
     *       |   |     |                       |     |   |
     *       `-------------------------------------------'
     *
     */

    [UTIL] = KEYMAP(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, ____,
        ____, ____, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_PGUP, LCTL(KC_LEFT), KC_UP, LCTL(KC_RIGHT), ____, ____, ____, ____,
        ____, ____, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, ____, ____, ____,
        ____, ____, ____, ____, ____, KC_SPC, KC_BSPC, KC_DEL, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____),

};

/*
 * Fn action definition
 */
const uint16_t fn_actions[] = {

};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};
