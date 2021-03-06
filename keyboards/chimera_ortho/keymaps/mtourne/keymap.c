#include QMK_KEYBOARD_H
#include "process_keycode/process_tap_dance.h"

enum chimera_ortho_layers {
  _DVORAK,
  _SPACE_FN,
  _CODING,

  // numpad style numbers and
  // symbols
  // left and right mirrored on each hand.
  _NUM,
  _NUM_LK,
  _SYMB,
  _SPC_NUM,
  // TODO implem func
  _FUNC,

  // mouse
  _MOUSE,
  _MOUSE_LK,

  // bootloader magic stuff
  _ADJUST,
};

// add the KC_ because of LAYOUT_kc KC_ macro adding */
#define KC______  KC_TRNS
#define _____     KC_TRNS
#define KC_xxxxx  KC_NO
#define xxxxx     KC_NO

// == options ==
// =============

// #define VERBOSE_DEBUG
// #define DEBUG
#ifdef VERBOSE_DEBUG
#define DEBUG
#endif

// activate one shot shift (in the tap dance for caps)
#define ONESHOT_SFT

// failed? experiment of having long press actions
// #define TAP_HOLD_EXPERIMENT

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

#define KC_ADJ MO(_ADJUST)

// ESCC is the ESC that also cancels one shot mods
// it needs to be defined to what the key is currently set at.
#define ESCC KC_MOU(ESC)

// == LOCKS ==
// ===========
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
  TD_SFT_CAPS = 0,
  TD_C_LPRN,
  TD_R_RPRN,
  TD_MINS_ENT,
};

#define KC_SHFT_C TD(TD_SFT_CAPS)

#ifdef TAP_HOLD_EXPERIMENT
#define KC_C_LPR  TD(TD_C_LPRN)
#define KC_R_RPR  TD(TD_R_RPRN)
#define KC_MIN_ENT TD(TD_MINS_ENT)

#else

#define KC_C_LPR KC_C
#define KC_R_RPR KC_R
#define KC_MIN_ENT KC_MINS
// #define KC_MIN_ENT TD(TD_MINS_ENT)

#endif
// TODO : * maybe make long press C and R as () - currently backspace layer is error prone
//        * do something cool with unassigned keys.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
   MOU(ESC),RF(QUOT), COMM  ,   DOT ,   P   ,   Y   ,  ADJ  ,        GRV  ,   F   ,   G   , C_LPR , R_RPR , LF(L) ,  SLSH ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
       TAB  , RN(A) , CO(O) ,   E   ,   U   , SN(I) , _____ ,        ENT  , SN(D) ,   H   ,   T   , CO(N) , LN(S) ,MIN_ENT,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
    SHFT_C ,RS(SCLN), MOU(Q), AL(J) , GU(K) , CT(X) ,  OALT ,        ENT  , CT(B) , GU(M) , AL(W) , LN(V) , LS(Z) , SHFT_C,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                       OGUI ,  OCTL ,                      SPC_FN ,  BSPC
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  // use X(dvo k-qwer) as lock?
  // XXX remember the shifted keys don't work well wit software dvorak!!
  // will probably have to introduce a macro for shifted ansi keys to work for hardwire dvorak (os in qwerty),
  // soft dvorak (os in dvorak) and possibly qwerty??

   [_SPACE_FN] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     _____ ,CC(QUOT), _____ , _____ , _____ , _____ , _____ ,        ESC  , PGUP  , BSPC  ,  UP   ,  DEL  , _____ ,  BSLS ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      ALTAB , CC(A) , _____ , CC(E) , _____ , _____ , _____ ,       _____ , PGDN  , LEFT  , DOWN  , RIGHT ,  ENT  ,  EQL  ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ , _____ , _____ , _____ , _____ ,       _____ ,  SPC  , _____ , _____ , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                       _____ , _____
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  // XXX more opportunity for things here
  // maybe have plus and pipe on their own
  [_CODING] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
      _____ , _____ , _____ ,  LBRC ,  RBRC , _____ , _____ ,        ESC  , _____ ,  LBRC ,  RBRC , _____ , _____ ,  PIPE ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ ,  LPRN ,  RPRN , _____ , _____ ,       _____ , _____ ,  LPRN ,  RPRN , _____ , _____ ,  PLUS ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ ,  LCBR ,  RCBR , _____ , _____ ,       _____ , _____ ,  LCBR ,  RCBR , _____ , _____ , _____ ,
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

  // TODO: space_Fn in lock mode doesn't work. it probably has to do wit the way layers are stacked
  // for now lk has been put back on spc too
  [_NUM] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
      _____ ,   0   ,   9   ,   8   ,   7   ,  LBRC , _____ ,       _____ ,  RBRC ,   7   ,   8   ,   9   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ ,   0   ,   6   ,   5   ,   4   ,  LPRN , NUM_LK,       _____ ,  RPRN ,   4   ,   5   ,   6   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ ,   3   ,   2   ,   1   ,  LCBR , _____ ,       _____ ,  RCBR ,   1   ,   2   ,   3   , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                       _____ , _____
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_NUM_LK] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
      NUM_LK,   0   ,   9   ,   8   ,   7   ,  LBRC , _____ ,       _____ ,  RBRC ,   7   ,   8   ,   9   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ ,   0   ,   6   ,   5   ,   4   ,  LPRN , NUM_LK,       _____ ,  RPRN ,   4   ,   5   ,   6   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ ,   3   ,   2   ,   1   ,  LCBR , _____ ,       _____ ,  RCBR ,   1   ,   2   ,   3   , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                       _____ , _____
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  // layer that would send space + number so I can switch buffers really fast in spacemacs
  [_SPC_NUM] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
      _____ ,   0   ,   9   ,   8   ,   7   ,  LBRC , _____ ,       _____ ,  RBRC ,   7   ,   8   ,   9   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ ,   0   ,   6   ,   5   ,   4   ,  LPRN , _____ ,       _____ ,  RPRN ,   4   ,   5   ,   6   ,   0   , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ ,   3   ,   2   ,   1   ,  LCBR , _____ ,       _____ ,  RCBR ,   1   ,   2   ,   3   , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                       _____ , _____
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  [_SYMB] = LAYOUT_kc(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
      _____ ,  LPRN ,  RPRN ,  ASTR ,  AMPR ,  LBRC , _____ ,       _____ ,  RBRC ,  AMPR ,  ASTR ,  LPRN ,  RPRN , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ ,  LPRN ,  CIRC ,  PERC ,  DLR  ,  LPRN , _____ ,       _____ ,  RPRN ,  DLR  ,  PERC ,  CIRC ,  RPRN , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ ,  HASH ,   AT  ,  EXLM ,  LCBR , _____ ,       _____ ,  RCBR ,  EXLM ,   AT  ,  HASH , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                       _____ , _____
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

  // TODO func layer.

  // change layouts and other virtual dip magics
  // maybe also audio control?
  // AG_SWAP swaps alt / gui
  // AG_NORM puts them back
  // (also possible to use AG_TOGGLE) but makes it harder to know which mode im in.
  [_ADJUST] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
      _____ , _____ , _____ , _____ , _____ , _____ , _____ ,       _____ , _____ , _____ , _____ , _____ ,AG_NORM,AG_SWAP,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ , _____ , _____ , _____ , _____ ,       _____ , _____ , _____ , _____ , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
      _____ , _____ , _____ , _____ , _____ , _____ , _____ ,       _____ , _____ , _____ , _____ , _____ , _____ , _____ ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
                                      _____ , _____ ,                       _____ , _____
  // \------------------------------+-------+-------+------/       \------+-------+-------+------------------------------/
  ),

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


// TODO : share everything below with HHKB on a lib
// ================================================

// SHIFT CAPSLOCK
#define DEBOUNCE_CAPS_DELAY 100
static bool caps_lock = false;

// ALTAB
#define ALT_TAB_HOLD_DURATION 1000
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool cancel_all_oneshots(void) {
  bool queue = true;

  dprintf("before: oneshot_mods(): %d, oneshot_locked_mods: %d, mods: %d\n", get_oneshot_mods(), get_oneshot_locked_mods(), get_mods());

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

// mas os is the default (not shifted)
bool is_mac_os(void) {
  if(keymap_config.swap_lalt_lgui || keymap_config.swap_ralt_rgui) {
    return false;
  }
  return true;
}

// get the "alt" in alttab functionality
// cmd for mac os
// alt for windows
uint16_t get_alt_key(void) {
  if (!is_mac_os()) {
    return KC_LALT;
  }
  return KC_LGUI;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t layer = biton32(layer_state);
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

  switch (keycode) {

  // ALTAB
  case ALT_TAB:
    if (record->event.pressed) {
      if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(get_alt_key());
      }
      alt_tab_timer = timer_read();
      register_code(KC_TAB);
    } else {
      unregister_code(KC_TAB);
    }
    break;
  case KC_LEFT:
  case KC_RIGHT:
    // if we're altab'ing, and an arrow is sent. prolongue the timer
    if (is_alt_tab_active && record->event.pressed) {
      alt_tab_timer = timer_read();
    }
    break;
  case KC_SPC_FN:
    // if we're altabing and spc fn is realeased, stop
    if (is_alt_tab_active && !record->event.pressed) {
      is_alt_tab_active = false;
      unregister_code(get_alt_key());
    }
    break;

  // ESC CANCEL OSM
  case ESCC:
    if (record->event.pressed) {
      dprint("ESC CANCEL MODS pressed\n");
      queue = cancel_all_oneshots();
    }
    break;

  // _SPC_NUM attempt
  case KC_O:
  case KC_1:
  case KC_2:
  case KC_3:
  case KC_4:
  case KC_5:
  case KC_6:
  case KC_7:
  case KC_8:
  case KC_9:
    if (layer == _SPC_NUM) {
      if (record->event.pressed) {
        register_code(KC_SPC);
        register_code(keycode);
      } else {
        unregister_code(keycode);
        unregister_code(KC_SPC);
      }
    }
    break;
  }

  return queue;
};

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  // ALTAB
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > ALT_TAB_HOLD_DURATION) {
      unregister_code(get_alt_key());
      is_alt_tab_active = false;
    }
  }

  // LEDS
  if (get_oneshot_locked_mods() || get_oneshot_mods()) {
    // most precedence, locked mod
    set_led_red;
    return;
  }

  if (caps_lock) {
    // second most, caps lock on.
    set_led_magenta;
    return;
  }

  switch (layer) {
  case _DVORAK:
    set_led_green;
    break;
  case _SPACE_FN:
  case _CODING:
    set_led_white;
    break;
  case _NUM:
  case _NUM_LK:
    set_led_blue;
    break;
  case _SYMB:
    set_led_cyan;
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

// adapted from
// https://beta.docs.qmk.fm/features/feature_tap_dance#example-5-using-tap-dance-for-advanced-mod-tap-and-layer-tap-keys

// define a type containing as many tapdance states as you need
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

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

static td_state_t td_state_sft;
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

typedef struct {
  uint16_t tap_kc;
  uint16_t hold_kc;
  td_state_t state;
} th_t;

static th_t tap_hold_table[] = {
  [TD_C_LPRN] = { KC_C, KC_LPRN, 0},
  [TD_R_RPRN] = { KC_R, KC_RPRN, 0},
  [TD_MINS_ENT] = { KC_MINS, KC_ENT, 0},
};

void tap_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
  th_t *entry = (th_t*)user_data;

  entry->state = cur_dance(state);
  if (entry->state == SINGLE_HOLD) {
    register_code(entry->hold_kc);
  } else {
    register_code(entry->tap_kc);
  }
}

void tap_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
  th_t *entry = (th_t*)user_data;

  if (entry->state == SINGLE_HOLD) {
    unregister_code(entry->hold_kc);
  } else {
    unregister_code(entry->tap_kc);
  }
}


#define ACTION_TAP_HOLD(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset, entry) { \
    .fn = { user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset }, \
    .user_data = (void *)&tap_hold_table[entry],                                      \
   }

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Shift, twice for Caps Lock
  [TD_SFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, sft_finished, sft_reset, 180),
  // only works for hardwired dvorak. would have to do advanced funcs to return the right KC in all settings.
  // c -> ( , r -> )
  [TD_C_LPRN] = ACTION_TAP_HOLD(NULL, tap_hold_finished, tap_hold_reset, TD_C_LPRN),
  [TD_R_RPRN] = ACTION_TAP_HOLD(NULL, tap_hold_finished, tap_hold_reset, TD_R_RPRN),
  // - -> ENT
  // [TD_MINS_ENT] = ACTION_TAP_HOLD(NULL, tap_hold_finished, tap_hold_reset, TD_MINS_ENT),
  [TD_MINS_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_ENT),
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
#ifdef DEBUG
  debug_enable=true;
#endif
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
