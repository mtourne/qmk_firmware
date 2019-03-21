/*  -*-  eval: (turn-on-orgtbl); -*-
 * mtourne HHKB Layout. inspired from cinaeco
 */
#include QMK_KEYBOARD_H
#include <print.h>

// Layers.
#define QWER 0
#define DVOR 1
#define HHKB 2
#define UTIL 4
#define NUM 5
#define NUMLOCK 6
#define SYMB 7
#define SYMBLOCK 8
// dummy layers to turn on oneshots.
#define LLCTL 9
#define LLALT 10
#define LLGUI 11
#define MOUSE 12
#define MOUSELOCK 13

// Easier-to-read Layer Arrays.
#define ____ KC_TRNS
#define xxxx KC_NO

/* Notes
 *
 * 2019-02-14 :
 *  major modification to util layer in preparation for a 40%
 *   all lower hand row will do layers
 *  Currently space will lock a layer with symb && symblock
 * 2019-03-20:
 *  what I want for the layer keys is a better one shot
 *  tap once -> letter
 *  hold 200+ms -> one shot on layer (if nothing was entered)
 +  double tap -> lock layer (retap to unlock)
 */

//Tap Dance Declarations
enum {
  TD_LSFT_CAPS = 0
};

// caps lock stuff
static bool caps_lock = false;
#define DEBOUNCE_CAPS_DELAY 100

enum custom_keycodes { KC_CANCEL_OSM = SAFE_RANGE };


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

    [QWER] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_ESC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        OSM(MOD_LCTL), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        /* unbearable causes other mods to stick : OSM(MOD_LSFT),*/
        TD(TD_LSFT_CAPS)
        /*KC_LSFT*/, LT(MOUSE, KC_Z), KC_X, KC_C, KC_V, KC_B, LT(LLALT, KC_N), LT(LLCTL, KC_M), LT(LLGUI, KC_COMM), LT(SYMB, KC_DOT), LT(NUM, KC_SLSH), TD(TD_LSFT_CAPS), MO(HHKB),
        OSM(MOD_LALT), OSM(MOD_LGUI), LT(UTIL, KC_SPC), OSM(MOD_LGUI), OSM(MOD_LCTL)
    ),


    // XX (mt) : I would probably need a tap dance for desired
    // (works) short press : M
    // (works) long press -> OSM ctl
    // (missing) tap twice -> hold ctl
    [LLCTL] = LAYOUT(
       //  1     2     3     4     5.    6     7     8.    9     10    11    12    13    14    15
         ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
         ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
         ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
         ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
         ____, ____, ____, ____, ____),


   [LLALT] = LAYOUT(
          //  1     2     3     4     5.    6     7     8.    9     10    11    12    13    14    15
         ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
         ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
         ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
         ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
         ____, ____, ____, ____, ____),

    [LLGUI] = LAYOUT(
          //  1     2     3     4     5.    6     7     8.    9     10    11    12    13    14    15
         ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
         ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
         ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
         ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
         ____, ____, ____, ____, ____),


    /* DVOR Layer: Dvorak
    // TODO dvorak layer has really been abandonned this days since I use dvorak software from the os
    // need to backport all the features of qwer and make it work in UTIL layer as well (c-x for eg)
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

    [DVOR] = LAYOUT(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_LBRC, KC_RBRC, KC_BSLS, KC_ESC,
        KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_EQL, KC_BSPC,
        KC_LCTL, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_ENT,
        KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT, MO(HHKB),
        KC_LALT, KC_LGUI, LT(UTIL, KC_SPC), KC_RGUI, KC_RALT),

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

    [HHKB] = LAYOUT(
        KC_PWR, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,
        KC_CAPS, KC_MPLY, KC_MPRV, KC_MNXT, ____, ____, ____, ____, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, ____, KC_BSPC,
        ____, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, ____, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_ENT,
        ____, DF(QWER), DF(DVOR), ____, ____, ____, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, ____, ____,
        ____, ____, ____, KC_MSTP, ____),

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
     * Notes :
     *  2019-02-09: never using ESC from the UTIL mode
     */


    // OLD UTIL: has mouse direction under the left hand
    //  I've decided to put the mouse key on Z + ijkl. see above.
    //  2019-03-20: adding mouse layer ^^^


    [ MOUSE ] = LAYOUT(
       //  1     2     3     4     5.    6     7     8.    9     10    11    12    13    14    15
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
         // wheel up down are inverted for mac os.
         // TODO in "pc" config they should reverse
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, KC_WH_D, KC_BTN1, KC_MS_U, KC_BTN2, xxxx, xxxx, xxxx, xxxx,
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, xxxx, xxxx, xxxx,
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
         xxxx, xxxx, TG(MOUSELOCK), xxxx, xxxx),

    [ MOUSELOCK ] = LAYOUT(
       //  1     2     3     4     5.    6     7     8.    9     10    11    12    13    14    15
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
         // wheel up down are inverted for mac os.
         // TODO in "pc" config they should reverse
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, KC_WH_D, KC_BTN1, KC_MS_U, KC_BTN2, xxxx, xxxx, xxxx, xxxx,
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, xxxx, xxxx, xxxx,
         xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx, xxxx,
         xxxx, xxxx, TG(MOUSELOCK), xxxx, xxxx),


    //[UTIL] = LAYOUT(
    //    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, ____,
    //    ____, ____, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_PGUP, LCTL(KC_LEFT), KC_UP, LCTL(KC_RIGHT), ____, ____, ____, ____,
    //    ____, ____, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, ____, ____, ____,
    //    ____, ____, ____, ____, ____, KC_SPC, KC_BSPC, KC_DEL, ____, ____, ____, ____, ____,
    //    ____, ____, ____, ____, ____),


    // Naked util with just nav cluster
    // [UTIL] = LAYOUT(
    //    //  1     2      3      4       5.      6     7     8.     9      10      11      12     13    14    15
    //     KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F1, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, ____,
    //     ____, ____, ____, ____, ____, ____, KC_PGUP, ____, KC_UP, ____, ____, ____, ____, ____,
    //     ____, ____, ____, ____, ____, ____, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, ____, ____, ____,
    //     ____, ____, ____, ____, ____,, KC_BSPC, KC_DEL, ____, ____, ____, ____, ____,
    //     ____, ____, ____, ____, ____),


    // Util NAV
    // + useful symbols () {} []
    // + one-shot to activate numbers
    // + one-shot to activate shifted numbers (symb)
    [UTIL] = LAYOUT(
       //  1     2      3      4       5.      6     7     8.     9      10      11      12     13    14    15
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, ____,
        ____, ____, ____, KC_UNDERSCORE, KC_PLUS, KC_BSLS, KC_PGUP, KC_BSPC, KC_UP, KC_DEL, ____, ____, ____, ____,
        ____, ____, ____, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_RBRACKET, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_CANCEL_OSM, ____, ____,
        ____, ____, ____, KC_MINUS, KC_EQUAL, LCTL(KC_B) /* x software dvorak */, OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LGUI), OSL(SYMB), OSL(NUM), ____, ____,
        ____, ____, ____, ____, ____),

    // Util with number as base
    // [UTIL] = LAYOUT(
    //    //  1     2      3      4       5.      6     7     8.     9      10      11      12     13    14    15
    //     KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ____, ____,
    //     ____, ____, KC_7, KC_8, KC_9, ____, KC_PGUP, ____, KC_UP, MO(UTILPLUS), ____, ____, ____, ____,
    //     ____, KC_0, KC_4, KC_5, KC_6, ____, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_RSFT, ____, ____,
    //     ____, ____, KC_1, KC_2, KC_3, KC_SPC, KC_BSPC, KC_DEL, ____, ____, ____, ____, ____,
    //     ____, ____, ____, ____, ____),


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

    /* // [EMPTY] = LAYOUT( */
    /* //      //  1     2     3     4     5.    6     7     8.    9     10    11    12    13    14    15 */
    /* //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, */
    /* //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, */
    /* //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, */
    /* //     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, */
    /* //     ____, ____, ____, ____, ____), */
         };


bool cancel_all_oneshots(void) {
  bool queue = true;

  uprintf("before: oneshot_mods(): %d, oneshot_locked_mods: %d, mods: %d\n", get_oneshot_mods(), get_oneshot_locked_mods(), get_mods());

  if (get_oneshot_mods() && !has_oneshot_mods_timed_out()) {
    clear_oneshot_mods();
    queue = false;
  }

  if (get_oneshot_locked_mods()) {
    clear_oneshot_mods();
    clear_oneshot_locked_mods();
    unregister_mods(get_mods());
    queue = false;
  }

  uprintf("after: oneshot_mods(): %d, oneshot_locked_mods: %d, mods: %d\n", get_oneshot_mods(), get_oneshot_locked_mods(), get_mods());

  // XX should esc release caps lock too?
  if (caps_lock) {
    caps_lock = false;
    dprint("caps lock off\n");
    register_code(KC_CAPSLOCK);
    wait_ms(DEBOUNCE_CAPS_DELAY);
    unregister_code(KC_CAPSLOCK);
    queue = false;
  }

  return queue;
}

// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool queue = true;

  if (record->event.pressed) {
       dprintf("KEY PRESSED: %d\n\toneshot_mods(): %d, oneshot_locked_mods: %d, mods: %d\n",
             keycode,
             get_oneshot_mods(), get_oneshot_locked_mods(), get_mods());

  } else {
     dprintf("KEY RELEASED: %d\n\toneshot_mods(): %d, oneshot_locked_mods: %d, mods: %d\n",
             keycode,
             get_oneshot_mods(), get_oneshot_locked_mods(), get_mods());

  }

  // Cancel one-shot mods.
  switch (keycode) {

    case KC_ESC:
      if (record->event.pressed) {
        dprint("ESC pressed\n");
        queue = cancel_all_oneshots();
      }
      break;

    case KC_CANCEL_OSM:
      if (record->event.pressed) {
        queue = cancel_all_oneshots();
      }
      break;
  }

  return queue;
}

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case LLCTL:
      uprint("lctl dummy layer\n");
      set_oneshot_mods(MOD_LCTL);
      break;

    case LLALT:
      uprint("lalt dummy layer\n");
      set_oneshot_mods(MOD_LALT);
      break;

    case LLGUI:
      uprint("lgui dummy layer\n");
      set_oneshot_mods(MOD_LGUI);
      break;

    default:
      break;
  }

  return state;
}

// adapted from
// https://beta.docs.qmk.fm/features/feature_tap_dance#example-5-using-tap-dance-for-advanced-mod-tap-and-layer-tap-keys

// define a type containing as many tapdance states as you need
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

// create a global instance of the tapdance state type
static td_state_t td_state_sft;

// determine the tapdance state to return
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
    else { return SINGLE_HOLD; }
  }
  if (state->count == 2) { return DOUBLE_SINGLE_TAP; }
  else { return 3; } // any number higher than the maximum state value you return above
}

// handle the possible states for each tapdance keycode you define:

void sft_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state_sft = cur_dance(state);
  if (td_state_sft == DOUBLE_SINGLE_TAP) {
    if (!caps_lock) {
      register_code(KC_CAPSLOCK);
      return;
    }
  }

  if (caps_lock) {
    register_code(KC_CAPSLOCK);
  } else {
    register_code(KC_LSFT);
  }
}

void sft_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (td_state_sft == DOUBLE_SINGLE_TAP) {
      if (!caps_lock) {
        caps_lock = true;
        wait_ms(DEBOUNCE_CAPS_DELAY);
        unregister_code(KC_CAPSLOCK);
        return;
      }
    }

    if (caps_lock) {
      caps_lock = false;
      wait_ms(DEBOUNCE_CAPS_DELAY);
      unregister_code(KC_CAPSLOCK);
    } else {
      unregister_code(KC_LSFT);
    }
}


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Shift, twice for Caps Lock
  // try to do same as tap dance double but with print
  [TD_LSFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sft_finished, sft_reset)
};


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //odebug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
