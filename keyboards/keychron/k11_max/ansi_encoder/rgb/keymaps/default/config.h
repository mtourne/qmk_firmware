#ifndef CONFIG_H
#define CONFIG_H

// Increase "Tap" detection window.
// this what governs LT() macro and spacebar tap (300ms works well).
#undef TAPPING_TERM
// 200 is the default for QMK
#define TAPPING_TERM 200

// here we can customize each key
// see get_tapping_term() isn keymap.c
// GRV_ESC functionality gets 175ms
// SPACE FN gets 300ms.
#define TAPPING_TERM_PER_KEY

// This makes tap and hold keys (like Layer Tap) work better for fast
// typists, or for high TAPPING_TERM settings.

// If you press a dual-role key, tap another key (press and release)
// and then release the dual-role key, all within the tapping term, by
// default the dual-role key will perform its tap action. If the
// PERMISSIVE_HOLD option is enabled, the dual-role key will perform
// its hold action instead.

// if sending space+key within the tapping term it should register correctly.
#define PERMISSIVE_HOLD

#endif
