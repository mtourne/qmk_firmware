/*
 * mtourne HHKB Layout. inspired from cinaeco
 */
#include QMK_KEYBOARD_H
#include <print.h>

// Layers.
#define QWER 0
#define DVOR 1
#define LOC_CTL 3
#define HHKB 4
#define UTIL 5
#define NUM 6
#define NUMLOCK 7
#define SYMB 8
#define SYMBLOCK 9


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
 *  double tap -> lock layer (retap to unlock)
 * 2019-03-21:
 *  implemented: most of the above ^^ but it actually seems
 *  a bit cumbersome
 */

//Tap Dance Declarations
enum {
  TD_LSFT_CAPS = 0,
};

// caps lock stuff
static bool caps_lock = false;
#define DEBOUNCE_CAPS_DELAY 100

enum custom_keycodes {
  KC_CANCEL_OSM = SAFE_RANGE,
  KC_TEST,
  KC_SPC_LOCK
};


// keys
#define SDVO_X KC_B

// #define VERBOSE_DEBUG

// make tap dance shift -> caps lock work with OSM shift or regular shift
#define ONESHOT_SFT


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
        OSM(MOD_LCTL), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(SYMB, KC_QUOT), KC_ENT,
        /* unbearable causes other mods to stick : OSM(MOD_LSFT),*/
        TD(TD_LSFT_CAPS)
        /*KC_LSFT*/, LT(MOUSE, KC_Z), ALT_T(KC_X), GUI_T(KC_C), CTL_T(KC_V), KC_B, KC_N, CTL_T(KC_M), GUI_T(KC_COMM), ALT_T(KC_DOT), LT(NUM, KC_SLSH), TD(TD_LSFT_CAPS), MO(HHKB),
        OSM(MOD_LALT), OSM(MOD_LGUI), LT(UTIL, KC_SPC), OSM(MOD_LGUI), OSM(MOD_LCTL)
    ),


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
        OSM(MOD_LCTL), KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_ENT,
        TD(TD_LSFT_CAPS), KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, TD(TD_LSFT_CAPS), MO(HHKB),
        OSM(MOD_LALT), OSM(MOD_LGUI), LT(UTIL, KC_SPC), OSM(MOD_LGUI), OSM(MOD_LCTL)),

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
        ____, ____, ____, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_RBRACKET, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_CANCEL_OSM, OSL(SYMB), ____,
        ____, ____, ____, KC_MINUS, KC_EQUAL, LCTL(SDVO_X), ____, OSM(MOD_LCTL), OSM(MOD_LGUI), OSM(MOD_LALT), OSL(NUM), ____, ____,
        ____, ____, ____, ____, ____),


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

  dprintf("after: oneshot_mods(): %d, oneshot_locked_mods: %d, mods: %d\n", get_oneshot_mods(), get_oneshot_locked_mods(), get_mods());

  // XX should esc release caps lock too?
  //if (caps_lock) {
  //  caps_lock = false;
  //  dprint("caps lock off\n");
  //  register_code(kc_capslock);
  //  wait_ms(debounce_caps_delay);
  //  unregister_code(kc_capslock);
  //  queue = false;
  //}

  return queue;
}


// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool queue = true;

#ifdef VERBOSE_DEBUG
  if (record->event.pressed) {
       dprintf("KEY PRESSED: %d\n\toneshot_mods(): %d, oneshot_locked_mods: %d, mods: %d\n",
             keycode,
             get_oneshot_mods(), get_oneshot_locked_mods(), get_mods());

  } else {
     dprintf("KEY RELEASED: %d\n\toneshot_mods(): %d, oneshot_locked_mods: %d, mods: %d\n",
             keycode,
             get_oneshot_mods(), get_oneshot_locked_mods(), get_mods());
  }
#endif

  // Cancel one-shot mods.
  switch (keycode) {

    case KC_TEST:
      queue = false;
      dprint("GOT TEST KEY\n");
      break;

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
int cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted) {
      dprint("1 PRESS: INTERRUPTED\n");
    }
    if (state->pressed) {
      dprint("1 PRESS: STILL PRESSED\n");
    }
    if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
    else { return SINGLE_HOLD; }
  }
  if (state->count == 2) { return DOUBLE_SINGLE_TAP; }
  else { return 3; } // any number higher than the maximum state value you return above
}

// handle the possible states for each tapdance keycode you define:

void sft_finished(qk_tap_dance_state_t *state, void *user_data) {
  td_state_sft = cur_dance(state);
  if (td_state_sft == DOUBLE_SINGLE_TAP) {
      register_code(KC_CAPSLOCK);
      return;
  }

#ifdef ONESHOT_SFT
  if (td_state_sft == SINGLE_TAP) {
    dprint("SINGLE TAP. setting OSM shift\n");
    set_oneshot_mods(MOD_LSFT | get_oneshot_mods());
  }
  // send shift for tap or hold
#endif
  dprint("SHIFT\n");
  register_code(KC_LSFT);
}

void sft_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (td_state_sft == DOUBLE_SINGLE_TAP) {
    caps_lock = !caps_lock;
    wait_ms(DEBOUNCE_CAPS_DELAY);
    unregister_code(KC_CAPSLOCK);
    return;
  }

#ifdef ONESHOT_SFT
  if (td_state_sft == SINGLE_TAP) {
    // nothing to do osm already set.
  }
  // hold or tap
#endif
  dprint("SHIFT OFF\n");
  unregister_code(KC_LSFT);
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Shift, twice for Caps Lock
  // try to do same as tap dance double but with print
  [TD_LSFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, sft_finished, sft_reset, 200),
};


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //odebug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
