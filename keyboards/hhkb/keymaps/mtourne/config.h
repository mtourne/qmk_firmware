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
// XX (mtourne): is this what governs LT() macro
// and spacebar tap?
#undef TAPPING_TERM
#define TAPPING_TERM 200

// if sending space+key within the tapping term it should register correctly.
#define PERMISSIVE_HOLD

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
#define MOUSEKEY_WHEEL_DELAY    0

#endif
