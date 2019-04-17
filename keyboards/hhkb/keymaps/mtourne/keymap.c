/*
 * mtourne HHKB Layout. inspired from cinaeco
 */
#include QMK_KEYBOARD_H
#include <print.h>
#include "mtourne.h"

// Layers.
enum extra_layers {
   _HHKB = _MTOURNE_LAYERS_SAFE_RANGE,
};

// Easier-to-read Layer Arrays.
#define ____ KC_TRNS
#define xxxx KC_NO

// tell which key cancels OSM
#define ESCC KC_ESC

// TODO reintroduce all the "in aplpha" modifiers and layers to match chimera experience.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWER Layer: Qwerty Default
     *
     * ,--------------------------------------------------------------.
     * |`  |    1 |  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|Esc|
     * |--------------------------------------------------------------|
     * |Tab  |     Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|
     * |--------------------------------------------------------------|
     * |Ctrl  |     A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|     Ent|
     * |--------------------------------------------------------------|
     * |Shift   |     Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn0|
     * `--------------------------------------------------------------'
     *       |Alt|Gui  |       Space/UTIL      |Gui  |Alt|
     *       `-------------------------------------------'
     *
     */

    [_QWERTY] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_ESC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        OSM(MOD_LCTL), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        TD(TD_SFT_CAPS), KC_Z, MOU(KC_X), KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(TD_SFT_CAPS), MO(_HHKB),
        OSM(MOD_LALT), OSM(MOD_LGUI), KC_SPC_FN, OSM(MOD_LGUI), OSM(MOD_LCTL)
    ),


     /* DVOR Layer: Dvorak
     *
     * ,--------------------------------------------------------------.
     * |`  |    1 |  2|  3|  4|  5|  6|  7|  8|  9|  0|  [|  ]|  \|Esc|
     * |--------------------------------------------------------------|
     * |Tab  |     '|  ,|  .|  P|  Y|  F|  G|  C|  R|  L|  /|  =|Backs|
     * |--------------------------------------------------------------|
     * |Ctrl  |     A|O/$|  E|  U|  I|  D|  H|  T|N/#|  S|  -|     Ent|
     * |--------------------------------------------------------------|
     * |Shift   |     ;|  Q|  J|  K|  X|  B|  M|  W|  V|  Z|Shift |Fn0|
     * `--------------------------------------------------------------'
     *       |Alt|Gui  |       Space/UTIL      |Gui  |Alt|
     *       `-------------------------------------------'
     *
     */

    [_DVORAK] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_LBRC, KC_RBRC, KC_BSLS, KC_ESC,
        KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_EQL, KC_BSPC,
        OSM(MOD_LCTL), KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_ENT,
        TD(TD_SFT_CAPS), KC_SCLN, MOU(KC_Q), KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, TD(TD_SFT_CAPS), MO(_HHKB),
        OSM(MOD_LALT), OSM(MOD_LGUI), KC_SPC_FN, OSM(MOD_LGUI), OSM(MOD_LCTL)),

    /* HHKB Layer: HHKB mode (HHKB Fn)
     *
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |PLA|PRV|NXT|   |   |   |   |Psc|Slk|Pus|Up |   |Backs|
     * |-----------------------------------------------------------|
     * |      |VoD|VoU|Mut|Ejc|   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |        |QWE|DVO|   |   |   |  +|  -|End|PgD|Dow|      |   |
     * `-----------------------------------------------------------'
     *       |   |     |                       |STOP |   |
     *       `-------------------------------------------'
     */

    [_HHKB] = LAYOUT(
        KC_PWR, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_CAPS, KC_MPLY, KC_MPRV, KC_MNXT, ____, ____, ____, ____, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, ____, KC_BSPC,
        ____, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, ____, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_ENT,
        ____, QWERTY, DVORAK, ____, ____, ____, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, ____, ____,
        AG_NORM, AG_SWAP, ____, KC_MSTP, ____),


    [_MOUSE] = LAYOUT(
       //  1     2     3     4     5.    6     7     8.    9     10    11    12    13    14    15
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
         // wheel up down are inverted for mac os.
         // TODO in "pc" config they should reverse
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, KC_WH_D, KC_BTN1, KC_MS_U, KC_BTN2, xxxx, xxxx, xxxx, xxxx,
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, xxxx, xxxx, xxxx,
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
         xxxx, xxxx, TG(_MOUSE_LK), xxxx, xxxx),

    [_MOUSE_LK] = LAYOUT(
       //  1     2     3     4     5.    6     7     8.    9     10    11    12    13    14    15
       TG(_MOUSE_LK), xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, TG(_MOUSE_LK),
       // wheel up down are inverted for mac os.
       // TODO in "pc" config they should reverse
       xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, KC_WH_D, KC_BTN1, KC_MS_U, KC_BTN2, xxxx, xxxx, xxxx, xxxx,
       xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, xxxx, xxxx, xxxx,
       xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
       xxxx, xxxx, TG(_MOUSE_LK), xxxx, xxxx),


    // Naked util with just nav cluster
    [_SPACE_FN] = LAYOUT(
       //  1     2      3      4       5.      6     7     8.     9      10      11      12     13    14    15
       KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F1, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, ____,
       KC_ALTAB, KC_CC(QUOT), ____, ____, ____, ____, KC_PGUP, KC_BSPC, KC_UP, KC_DEL, ____, ____, ____, ____,
       ____, KC_CC(A), ____, KC_CC(E), KC_ALTAB, ____, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_ENT, ____, ____,
       ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
       ____, ____, ____, ____, ____),


    // Util NAV
    // + useful symbols () {} []
    // + one-shot to activate numbers
    // + one-shot to activate shifted numbers (symb)
   // [UTIL] = LAYOUT(
   //    //  1     2      3      4       5.      6     7     8.     9      10      11      12     13    14    15
   //     KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, ____,
   //     ____, ____, ____, KC_UNDERSCORE, KC_PLUS, KC_BSLS, KC_PGUP, KC_BSPC, KC_UP, KC_DEL, ____, ____, ____, ____,
   //     ____, ____, ____, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_RBRACKET, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_ENT, OSL(SYMB), ____,
   //     ____, ____, ____, KC_MINUS, KC_EQUAL, LCTL(SDVO_X), ____, OSM(MOD_LCTL), OSM(MOD_LGUI), OSM(MOD_LALT), OSL(NUM), ____, ____,
   //     ____, ____, ____, ____, ____),

    /*
    // TODO : match chimera ortho. 1 starts on index.
    [NUM] = LAYOUT(
       //  1     2      3      4       5.      6     7     8.     9      10      11      12     13    14    15
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, ____,
        ____, ____, KC_7, KC_8, KC_9, ____, ____, ____,  ____,  ____, ____, ____, ____, ____,
        ____, KC_0, KC_4, KC_5, KC_6, ____, ____,  ____,  ____, ____, ____, ____, ____,
        ____, ____, KC_1, KC_2, KC_3, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, TG(NUMLOCK), ____, ____),

    // numlock exactly the same as above. but lock.
    [NUMLOCK] = LAYOUT(
       //  1     2      3      4       5.      6     7     8.     9      10      11      12     13    14    15
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, ____,
        ____, ____, KC_7, KC_8, KC_9, ____, ____, ____,  ____,  ____, ____, ____, ____, ____,
        ____, KC_0, KC_4, KC_5, KC_6, ____, ____,  ____,  ____, ____, ____, ____, ____,
        ____, ____, KC_1, KC_2, KC_3, ____, ____, ____, ____, ____, TG(NUMLOCK), ____, ____,
        ____, ____, TG(NUMLOCK), ____, ____),

    // same as num cluster above but pre-shifted
    [SYMB] = LAYOUT(
       //  1     2      3      4       5.      6     7     8.     9      10      11      12     13    14    15
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, ____,
        ____, ____, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, ____, ____, ____,  ____,  ____, ____, ____, ____, ____,
        ____, KC_RIGHT_PAREN, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, ____, ____,  ____,  ____, ____, ____, ____, ____,
        ____, ____, KC_EXCLAIM, KC_AT, KC_HASH, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, TG(SYMBLOCK), ____, ____),

    // same as above but locked by space
    [SYMBLOCK] = LAYOUT(
       //  1     2      3      4       5.      6     7     8.     9      10      11      12     13    14    15
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, ____,
        ____, ____, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN, ____, ____, ____,  ____,  ____, ____, ____, ____, ____,
        ____, KC_RIGHT_PAREN, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, ____, ____,  ____,  ____, ____, ____, ____, ____,
        ____, ____, KC_EXCLAIM, KC_AT, KC_HASH, ____, ____, ____, ____, TG(SYMBLOCK), ____, ____, ____,
        ____, ____, TG(SYMBLOCK), ____, ____),
    */

    /* // [EMPTY] = LAYOUT( */
    /* //      //  1     2     3     4     5.    6     7     8.    9     10    11    12    13    14    15 */
    /* //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, */
    /* //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, */
    /* //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, */
    /* //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, */
    /* //     ____, ____, ____, ____, ____), */
         };


// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   return mtourne_process_record_user(keycode, record);
}

// TODO permanent qwerty / dvoark set (survives restart)
uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {

  default:
      break;
  }

  return state;
}

void matrix_scan_user(void){
   // altab func.
   matrix_scan_altab();
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
#ifdef DEBUG
  debug_enable=true;
#endif
  //odebug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
