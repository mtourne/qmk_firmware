// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "process_keycode/process_tap_dance.h"

#define DEBOUNCE_CAPS_DELAY 100
#define ALT_TAB_SPEED 200
static bool caps_lock = false;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum chimera_ortho_layers {
  _DVORAK,
  _SPACE_FN,
  _CODING,

  // numpad style numbers and
  // symbols
  // combined left and right
  _NUM,
  _NUM_LK,
  _SYMB,
  _FUNC,

  // XXX: there has to be a smarter way to generate the _LK versions
  // left
  _NUMLEFT,
  _NUMLEFT_LK,
  _SYMBLEFT,

  // right
  _NUMRIGHT,
  _NUMRIGHT_LK,
  _SYMBRIGHT,

  // TODO implem.
  _FUNCLEFT,
  _FUNCRIGHT,

  // mouse
  _MOUSE,
  _MOUSE_LK
};

// add the KC_ because of LAYOUT_kc KC_ macro adding */
#define KC______  KC_TRNS
#define _____     KC_TRNS
#define KC_xxxxx  KC_NO
#define xxxxx     KC_NO

// == options ==
// =============

// activate one shot shift (in the tap dance for caps)
#define ONESHOT_SFT
//#define SEPARATE_LEFT_RIGHT

// == MODS ==
// ==========

#define KC_OCTL OSM(MOD_LCTL)
#define KC_OALT OSM(MOD_LALT)
#define KC_OGUI OSM(MOD_LGUI)

// TODO implem
// just bspc for now, later easily accessible
// coding layer
#define KC_BSPC_SYM KC_BSPC
// space function
#define KC_SPC_FN  LT(_SPACE_FN, KC_SPC)
// tap dance shift -> caps
#define KC_SHFT_C TD(TD_SFT_CAPS)

// == MACROS ==
// ============
#define KC_CT(_a) CTL_T(KC_##_a)
#define KC_AL(_a) ALT_T(KC_##_a)
#define KC_GU(_a) GUI_T(KC_##_a)

#define KC_CO(_a) LT(_CODING, KC_##_a)

#ifdef SEPARATE_LEFT_RIGHT

// left numb / symb / fs
#define KC_LN(_a) LT(_NUMLEFT, KC_##_a)
#define KC_LS(_a) LT(_SYMBLEFT, KC_##_a)
#define KC_LF(_a) LT(_FUNCLEFT, KC_##_a)

// right
#define KC_RN(_a) LT(_NUMRIGHT, KC_##_a)
#define KC_RS(_a) LT(_SYMBRIGHT, KC_##_a)
#define KC_RF(_a) LT(_FUNCRIGHT, KC_##_a)

#else

#define KC_LN(_a) LT(_NUM, KC_##_a)
#define KC_LS(_a) LT(_SYMB, KC_##_a)
#define KC_LF(_a) LT(_FUNC, KC_##_a)
#define KC_RN(_a) LT(_NUM, KC_##_a)
#define KC_RS(_a) LT(_SYMB, KC_##_a)
#define KC_RF(_a) LT(_FUNC, KC_##_a)

#endif

#define KC_MOU(_a) LT(_MOUSE, KC_##_a)

// == LOCKS ==
// ===========
#define LNUM_LK TG(_NUMLEFT_LK)
#define KC_LNUM_LK LNUM_LK

#define RNUM_LK TG(_NUMRIGHT_LK)
#define KC_RNUM_LK RNUM_LK

#define NUM_LK  TG(_NUM_LK)
#define KC_NUM_LK NUM_LK

#define MS_LK   TG(_MOUSE_LK)
#define KC_MS_LK MS_LK

// == MISC ==
// ==========
// TODO: on windows-mode should be actual alt+tab
// instead af command + tab.
#define KC_ALTAB ALT_TAB

enum custom_keycodes {
  KC_TEST = SAFE_RANGE,
  ALT_TAB,
};

//Tap Dance Declarations
enum {
  TD_SFT_CAPS = 0
};

// TODO : do something cool with unassigned keys.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
   MOU(ESC),RF(QUOT), COMM  ,   DOT ,   P   ,   Y   , _____ ,        GRV  ,   F   ,   G   ,   C   ,   R   , LF(L) ,  SLSH ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
       TAB  , RS(A) ,   O   ,   E   ,   U   ,   I   , _____,         ENT  ,   D  ,    H   ,   T   ,   N   , LS(S) ,  MINS ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
    SHFT_C ,RN(SCLN),   Q   , AL(J) , GU(K) , CT(X) ,  OALT ,        ENT  , CT(B) , GU(M) , AL(W) , LN(V) , LN(Z) , SHFT_C,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                       OCTL ,  OGUI ,                      SPC_FN ,CO(BSPC)
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  // use X(dvo k-qwer) as lock?
  // XXX remember the shifted keys don't work well wit software dvorak!!

   [_SPACE_FN] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
      _____ , _____ , _____ , _____ , _____ , _____ , _____ ,        ESC  , PGUP  , BSPC  ,  UP   ,  DEL  , _____ ,  BSLS ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ , ALTAB , _____ , _____ , _____ , _____ , _____ ,       _____ , PGDN  , LEFT  , DOWN  , RIGHT ,  ENT  ,  EQL  ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ , _____ , _____ , _____ , _____ ,       _____ ,  SPC  , _____ , _____ , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                       _____ , _____
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  // XXX more opportunity for things here
  [_CODING] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
      _____ , _____ , _____ , _____ , _____ , _____ , _____ ,       _____ , _____ ,  LBRC ,  RBRC , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ , _____ , _____ , _____ , _____ ,       _____ , _____ ,  LPRN ,  RPRN , _____ ,  ENT  , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ , _____ , _____ , _____ , _____ ,       _____ , _____ ,  LCBR ,  RCBR , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                       _____ , _____
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

 // [_EMPTY] = LAYOUT(
 // //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
 //     _____ , _____ , _____ , _____ , _____ , _____ , _____ ,       _____ , _____ , _____ , _____ , _____ , _____ , _____ ,
 // //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
 //     _____ , _____ , _____ , _____ , _____ , _____ , _____ ,       _____ , _____ , _____ , _____ , _____ , _____ , _____ ,
 // //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
 //     _____ , _____ , _____ , _____ , _____ , _____ , _____ ,       _____ , _____ , _____ , _____ , _____ , _____ , _____ ,
 // //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
 //                                     _____ , _____ ,                       _____ , _____
 // // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
 // ),

  // XXX add some slash bslash, plus equal?
  [_NUMLEFT] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.        ,-------+-------+-------+-------+-------+-------+-------.
      _____ ,   0   ,   9   ,   8   ,   7   ,  LBRC , _____ ,          _____ ,  RBRC , _____ , _____ , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ ,   0   ,   6   ,   5   ,   4   ,  LPRN , _____ ,          _____ ,  RPRN , _____ , _____ , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ ,   3   ,   2   ,   1   ,  LCBR , _____ ,          _____ ,  RCBR , _____ , _____ , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                         LNUM_LK, _____
  // \------------------------------+-------+-------+------/          \------+-------+-------+------------------------------/
  ),

  [_NUMLEFT_LK] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.        ,-------+-------+-------+-------+-------+-------+-------.
      _____ ,   0   ,   9   ,   8   ,   7   ,  LBRC , _____ ,          _____ ,  RBRC , _____ , _____ , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ ,   0   ,   6   ,   5   ,   4   ,  LPRN , _____ ,          _____ ,  RPRN , _____ , _____ , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ ,   3   ,   2   ,   1   ,  LCBR , _____ ,          _____ ,  RCBR , _____ , _____ , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                         LNUM_LK, _____
  // \------------------------------+-------+-------+------/          \------+-------+-------+------------------------------/
  ),

  [_NUMRIGHT] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.        ,-------+-------+-------+-------+-------+-------+-------.
      _____ , _____ , _____ , _____ , _____ ,  LBRC , _____ ,          _____ ,  RBRC ,   7   ,   8   ,   9   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ , _____ , _____ ,  LPRN , _____ ,          _____ ,  RPRN ,   4   ,   5   ,   6   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ , _____ , _____ ,  LCBR , _____ ,          _____ ,  RCBR ,   1   ,   2   ,   3   , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                         RNUM_LK, _____
  // \------------------------------+-------+-------+------/          \------+-------+-------+------------------------------/
  ),

  [_NUMRIGHT_LK] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.        ,-------+-------+-------+-------+-------+-------+-------.
      _____ , _____ , _____ , _____ , _____ ,  LBRC , _____ ,          _____ ,  RBRC ,   7   ,   8   ,   9   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ , _____ , _____ ,  LPRN , _____ ,          _____ ,  RPRN ,   4   ,   5   ,   6   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ , _____ , _____ ,  LCBR , _____ ,          _____ ,  RCBR ,   1   ,   2   ,   3   , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                         RNUM_LK, _____
  // \------------------------------+-------+-------+------/          \------+-------+-------+------------------------------/
  ),

  // above is not maintained
  // divergence : lock moved away from space
  [_NUM] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------+-------.
      _____ ,   0   ,   9   ,   8   ,   7   ,  LBRC , _____ ,           _____ ,  RBRC ,   7   ,   8   ,   9   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|         |-------+-------+-------+-------+-------+-------+-------|
      _____ ,   0   ,   6   ,   5   ,   4   ,  LPRN , NUM_LK,           _____ ,  RPRN ,   4   ,   5   ,   6   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|         |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ ,   3   ,   2   ,   1   ,  LCBR , _____ ,           _____ ,  RCBR ,   1   ,   2   ,   3   , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|         |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                           _____ , _____
  // \------------------------------+-------+-------+------/           \------+-------+-------+------------------------------/
  ),

  [_NUM_LK] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.         ,-------+-------+-------+-------+-------+-------+-------.
      _____ ,   0   ,   9   ,   8   ,   7   ,  LBRC , _____ ,           _____ ,  RBRC ,   7   ,   8   ,   9   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|         |-------+-------+-------+-------+-------+-------+-------|
      _____ ,   0   ,   6   ,   5   ,   4   ,  LPRN , NUM_LK,           _____ ,  RPRN ,   4   ,   5   ,   6   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|         |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ ,   3   ,   2   ,   1   ,  LCBR , _____ ,           _____ ,  RCBR ,   1   ,   2   ,   3   , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|         |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                           _____ , _____
  // \------------------------------+-------+-------+------/           \------+-------+-------+------------------------------/
  ),

  [_SYMBLEFT] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.        ,-------+-------+-------+-------+-------+-------+-------.
      _____ ,  LPRN ,  RPRN ,  ASTR ,  AMPR ,  LBRC , _____ ,          _____ ,  RBRC , _____ , _____ , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ ,  LPRN ,  CIRC ,  PERC ,  DLR  ,  LPRN , _____ ,          _____ ,  RPRN , _____ , _____ , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ ,  HASH ,  AMPR ,  EXLM ,  LCBR , _____ ,          _____ ,  RCBR , _____ , _____ , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                          _____ , _____
  // \------------------------------+-------+-------+------/          \------+-------+-------+------------------------------/
  ),


  [_SYMBRIGHT] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.        ,-------+-------+-------+-------+-------+-------+-------.
      _____ , _____ , _____ , _____ , _____ ,  LBRC , _____ ,          _____ ,  RBRC ,  AMPR ,  ASTR ,  LPRN ,  RPRN , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ , _____ , _____ ,  LPRN , _____ ,          _____ ,  RPRN ,  DLR  ,  PERC ,  CIRC ,  RPRN , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ , _____ , _____ ,  LCBR , _____ ,          _____ ,  RCBR ,  EXLM ,  AMPR ,  HASH , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                          _____ , _____
  // \------------------------------+-------+-------+------/          \------+-------+-------+------------------------------/
  ),

  [_SYMB] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.        ,-------+-------+-------+-------+-------+-------+-------.
      _____ ,  LPRN ,  RPRN ,  ASTR ,  AMPR ,  LBRC , _____ ,          _____ ,  RBRC ,  AMPR ,  ASTR ,  LPRN ,  RPRN , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ ,  LPRN ,  CIRC ,  PERC ,  DLR  ,  LPRN , _____ ,          _____ ,  RPRN ,  DLR  ,  PERC ,  CIRC ,  RPRN , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ ,  HASH ,  AMPR ,  EXLM ,  LCBR , _____ ,          _____ ,  RCBR ,  EXLM ,  AMPR ,  HASH , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                          _____ , _____
  // \------------------------------+-------+-------+------/          \------+-------+-------+------------------------------/
  ),


  // TODO func left / right layers.

  // reversed up down scroll (mac os default)
  // TODO: correct-order for windows mode?
 [_MOUSE] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
      xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx ,       xxxxx ,  WH_D ,  BTN1 ,  MS_U ,  BTN2 , xxxxx , xxxxx ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx ,       xxxxx ,  WH_U ,  MS_L ,  MS_D ,  MS_R , xxxxx , xxxxx ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx ,       xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                      xxxxx , xxxxx ,                       MS_LK , xxxxx
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

 [_MOUSE_LK] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
      MS_LK , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx ,       xxxxx ,  WH_D ,  BTN1 ,  MS_U ,  BTN2 , xxxxx , xxxxx ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx ,       xxxxx ,  WH_U ,  MS_L ,  MS_D ,  MS_R , xxxxx , xxxxx ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx ,       xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx , xxxxx ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                      xxxxx , xxxxx ,                       MS_LK , xxxxx
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  )
};


// TODO : share all this with hhkb in a lib.
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

bool alt_tab_enabled;
uint32_t alt_tab_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool queue = true;

  switch (keycode) {
  case ALT_TAB:
    alt_tab_enabled = record->event.pressed;
    if (alt_tab_enabled) {
      alt_tab_timer = timer_read();
      // would be LALT for windows-mode
      register_code(KC_LGUI);
      tap_code(KC_TAB);
    } else {
      // would be LALT for windows-mode
      unregister_code(KC_LGUI);
    }
    break;
  case KC_ESC:
    if (record->event.pressed) {
      dprint("ESC pressed\n");
      queue = cancel_all_oneshots();
    }
    break;
  }

  return queue;
};

// TODO share with hhkb.
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
  [TD_SFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, sft_finished, sft_reset, 180),
};

// TODO : set leds for any lock mods
// or num // symb active

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    if ( alt_tab_enabled && (timer_elapsed(alt_tab_timer) > ALT_TAB_SPEED) ) {
      tap_code(KC_TAB);
      alt_tab_timer = timer_read();
    }

    if (caps_lock) {
      set_led_red;
      return;
    }
    switch (layer) {
    case _DVORAK:
      set_led_green;
      break;
    case _SPACE_FN:
      set_led_white;
      break;
    case _CODING:
      set_led_cyan;
      break;
    case _NUMLEFT:
    case _NUMLEFT_LK:
    case _NUMRIGHT:
    case _NUMRIGHT_LK:
    case _NUM:
    case _NUM_LK:
      set_led_blue;
      break;
    case _SYMBLEFT:
    case _SYMBRIGHT:
    case _SYMB:
      set_led_magenta;
      break;
    case _MOUSE:
    case _MOUSE_LK:
      set_led_yellow;
      break;
    default:
      set_led_green;
      break;
    }
};


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //odebug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
