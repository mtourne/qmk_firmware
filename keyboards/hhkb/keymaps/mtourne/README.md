# QMK Keyboard Firmware for HHKB

## Deploy

build:
`make hhkb:mtourne`

deploy:
`make hkkb:mtourne:dfu`

## Modifications

### HHKB Layer

Regular HHKB

**plus**

    * QWE: Play / prev / next
    * Z: QWERTY
    * X: Hardwired Dvorak (to be used with os-QWERTY)

### Dev layer

**When holding Space**

    * qwer `ijkl` movement keys
    * wasd-style mouse keys
    * (B qwer) inserts a space
    * (N qwer) backspace
    * (M qwer) Del
    * ` -> ESC

**Option .. future**

    * use cluster TYGH - between arrow and mouse keys
    for something more useful than pgup pgdown / mouse wheel up down
