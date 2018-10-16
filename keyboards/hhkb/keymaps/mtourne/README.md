# QMK Keyboard Firmware for HHKB

## Deploy

build:
`make hhkb:mtourne`

deploy:
`make hkkb:mtourne:dfu`

## Modifications

### Dev layer

**When holding Space**

    * qwer `ijkl` movement keys
    * wasd-style mouse keys
    * (B qwer) inserts a space
    * (N qwer) backspace
    * (M qwer) Del

**Option .. future**

    * use cluster TYGH - between arrow and mouse keys
    * for something more useful than pgup pgdown / mouse wheel up down
      * H backspace ?

    * (TODO) left of "vi-htns" have move left by a word,
    * (TODO) backspace -> del
    * (TODO) ` -> ESC
    * (TODO) ' -> control-' (I use control-' to pull console )
    * (TODO) m -> alt-m (spacemacs menu in emacs mode)

### Media

TODO: see blakedietz
Maybe use dvorak-; (Z) long press for media access.

### TODO

    * Hardwired dvorak for use with US qwerty layout
