#ifndef CONFIG_MTOURNE_H
#define CONFIG_MTOURNE_H

#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION
#define MANUFACTURER    QMK
#define PRODUCT         chimera ortho mt
#define DESCRIPTION     chimera ortho mt layout

// Increase "Tap" detection window.
// this what governs LT() macro and spacebar tap
// XX: maybe 250?
#undef TAPPING_TERM
#define TAPPING_TERM 270

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

// I want ctrl and alt from the util layer to stick
// but ideally I'll have an easy way to reset them
#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
// 4.5 secs.
#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 3000

// this might help with holding down ctl on the LLCTL layer?
// a: it does hit the next key held but doesnt come back up to default layer
// #define STRICT_LAYER_RELEASE

#endif
