#ifndef CONFIG_MTOURNE_H
#define CONFIG_MTOURNE_H

#include "../../config.h"

#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION
#define MANUFACTURER    QMK
#define PRODUCT         HHKB QMK mtourne
#define DESCRIPTION     HHKB on QMK Firmware with mtourne keymap

// Increase "Tap" detection window.
// this what governs LT() macro and spacebar tap
#undef TAPPING_TERM
#define TAPPING_TERM 300

// each key can now have their own tapping_term
// spc fn is set to 200 (mtourne.h)
#define TAPPING_TERM_PER_KEY

// if sending space+key within the tapping term it should register correctly.
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

// mousekey settings

// When one of the mouse movement buttons is pressed this setting is
// used to define the delay between that button press and the mouse
// cursor moving. Some people find that small movements are impossible
// if this setting is too low, while settings that are too high feel
// sluggish.
#define MOUSEKEY_DELAY          30
// When a movement key is held down this specifies how long to wait
// between each movement report. Lower settings will translate into an
// effectively higher mouse speed.
#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_MAX_SPEED      6
// How long (ms) to reach max speed
#define MOUSEKEY_TIME_TO_MAX    20

// wheel settings
#define MOUSEKEY_WHEEL_TIME_TO_MAX  255
#define MOUSEKEY_WHEEL_MAX_SPEED    1

// NOTE 2020-08-01 - dunno what that means below.
// I want ctrl and alt from the util layer to stick
// but ideally I'll have an easy way to reset them

// Tapping this number of times holds the key until tapped once again
// or ESC (customized esc to remove stickies)
#define ONESHOT_TAP_TOGGLE 3
// HOLD control, alt, shift 1 secs.
#define ONESHOT_TIMEOUT 1000

#endif
