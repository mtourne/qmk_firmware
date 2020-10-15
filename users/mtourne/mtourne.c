#include QMK_KEYBOARD_H
#include "mtourne.h"

// short tap for spc_fn
// long tapping term for everyone else
uint16_t mtourne_get_tapping_term(uint16_t keycode) {
   switch (keycode) {

     // SPACE FUNCTION
   case KC_SPC_FN:
#ifdef VERBOSE_DEBUG
         dprint("spc fn tapping term!\n");
#endif
         return TAPPING_TERM_SPC_FN;

   // MODIFIERS
   case LCTL_T(KC_Z):
   case RCTL_T(KC_SLASH):
   case LALT_T(KC_C):
   case RALT_T(KC_COMM):
   case LGUI_T(KC_V):
#ifdef VERBOSE_DEBUG
         dprint("MODS tapping term!\n");
#endif
         return TAPPING_TERM_IN_KEEB_MODS;

   case RGUI_T(KC_M):
     #ifdef VERBOSE_DEBUG
         dprint("MODS tapping term + 50 for M key!\n");
     #endif
         return TAPPING_TERM_IN_KEEB_MODS + 50;

   // MOUSE
   // XXX how to make any MOU(*) automatically TAPPING_TERM_MOUSE_KEY
   case MOU(KC_F):
   case MOU(KC_U):
#ifdef VERBOSE_DEBUG
         dprint("mouse tapping term!\n");
#endif
        return TAPPING_TERM_MOUSE_KEY;

   default:

     return TAPPING_TERM;
   }
}

// SHIFT CAPSLOCK
#define DEBOUNCE_CAPS_DELAY 100
static bool caps_lock = false;

// ALTAB
static bool is_alt_tab_active = false;
static uint16_t alt_tab_timer = 0;

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

// TODO introduce "always-letter", that works for soft dvorak or hard dvorak
bool mtourne_process_record_user(uint16_t keycode, keyrecord_t *record) {
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

  // Permanent layer switch
  case QWERTY:
     if (record->event.pressed) {
         dprint("peristent set layer to _QWERTY.");
         set_single_persistent_default_layer(_QWERTY);
     }
     return false;
     break;
  case DVORAK:
     if (record->event.pressed) {
         dprint("peristent set layer to _DVORAK.");
         set_single_persistent_default_layer(_DVORAK);
     }
     return false;
     break;

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

// ALTAB
void matrix_scan_altab(void) {
if (is_alt_tab_active) {
  if (timer_elapsed(alt_tab_timer) > ALT_TAB_HOLD_DURATION) {
    unregister_code(get_alt_key());
    is_alt_tab_active = false;
  }
 }
}


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


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Shift, twice for Caps Lock
  [TD_SFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, sft_finished, sft_reset, 180),
};
