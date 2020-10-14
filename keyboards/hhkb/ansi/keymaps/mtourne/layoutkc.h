// kc shorthand

#ifndef LAYOUTKC_H
#define LAYOUTKC_H

#include QMK_KEYBOARD_H

#define LAYOUT_kc(							\
    _k31, _k30, _k00, _k10, _k11, _k20, _k21, _k40, _k41, _k60, _k61, _k70, _k71, _k50, _k51, \
    _k32, _k01, _k02, _k13, _k12, _k23, _k22, _k42, _k43, _k62, _k63, _k73, _k72, _k52, \
    _k33, _k04, _k03, _k14, _k15, _k24, _k25, _k45, _k44, _k65, _k64, _k74, _k53,	\
    _k34, _k05, _k06, _k07, _k16, _k17, _k26, _k46, _k66, _k76, _k75, _k55, _k54,	\
         _k35, _k36,           _k37,                _k57, _k56)		\
{									\
    { KC_##_k00, KC_##_k01, KC_##_k02, KC_##_k03, KC_##_k04, KC_##_k05, KC_##_k06, KC_##_k07   }, \
    { KC_##_k10, KC_##_k11, KC_##_k12, KC_##_k13, KC_##_k14, KC_##_k15, KC_##_k16, KC_##_k17   }, \
    { KC_##_k20, KC_##_k21, KC_##_k22, KC_##_k23, KC_##_k24, KC_##_k25, KC_##_k26, KC_NO }, \
    { KC_##_k30, KC_##_k31, KC_##_k32, KC_##_k33, KC_##_k34, KC_##_k35, KC_##_k36, KC_##_k37   }, \
    { KC_##_k40, KC_##_k41, KC_##_k42, KC_##_k43, KC_##_k44, KC_##_k45, KC_##_k46, KC_NO }, \
    { KC_##_k50, KC_##_k51, KC_##_k52, KC_##_k53, KC_##_k54, KC_##_k55, KC_##_k56, KC_##_k57   }, \
    { KC_##_k60, KC_##_k61, KC_##_k62, KC_##_k63, KC_##_k64, KC_##_k65, KC_##_k66, KC_NO }, \
    { KC_##_k70, KC_##_k71, KC_##_k72, KC_##_k73, KC_##_k74, KC_##_k75, KC_##_k76, KC_NO } \
}

// add the KC_ because of LAYOUT_kc KC_ macro adding */
#define KC_____  KC_TRNS
#define KC_xxxx  KC_NO

#endif
