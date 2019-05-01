#include QMK_KEYBOARD_H
#include "backlight.h"
#include "rgblight.h"

#define BL 0 
#define FN 1
#define MAINT 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │ Esc │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  [  │  ]  │  `  │BkSpc│
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┤
  │ Tab │  '  │  ,  │  .  │  P  │  Y  │  F  │  G  │  C  │  R  │  L  │  ?  │  +  │     \     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴───────────┤
  │Ctrl │  A  │  O  │  E  │  U  │  I  │  D  │  H  │  T  │  N  │  S  │  _  │      Enter      │
  ├─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼───────────┬─────┤
  │   Shift   │  :  │  Q  │  J  │  K  │  X  │  B  │  M  │  W  │  V  │  Z  │   Shift   │ FN  │
  ├─────┬─────┼─────┼─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┼─────┼─────┬─────┼─────┤
  │█████│ Alt │ Gui │                     Space                     │ Gui │ Alt │█████│█████│
  └─────┴─────┴─────┴───────────────────────────────────────────────┴─────┴─────┴─────┴─────┘
  */
	[ BL ] = LAYOUT_60_hhkb(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_LBRC, KC_RBRC, KC_GRV, KC_BSPC, 
    KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_EQL, KC_BSLS, 
    KC_LCTL, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_ENT, 
    KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_LSFT, TT( FN ), 
    KC_LALT, KC_LGUI, KC_SPC, KC_LGUI, KC_LALT
  ),
  /*
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │     │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │     │ Del │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┤
  │ Tab │     │     │     │     │     │     │     │     │     │     │     │     │     \     │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴───────────┤
  │Ctrl │  ◂  │  ▾  │  ▴  │  ▸  │     │     │     │     │     │     │     │      Enter      │
  ├─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼───────────┬─────┤
  │   Shift   │ Ply │ VoD │ VoU │ Mut │ Prv │ Nxt │     │     │     │     │   Shift   │ FN  │
  ├─────┬─────┼─────┼─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┼─────┼─────┬─────┼─────┤
  │█████│ Alt │ Gui │                     MAINT                     │ Gui │ Alt │█████│█████│
  └─────┴─────┴─────┴───────────────────────────────────────────────┴─────┴─────┴─────┴─────┘
  */
	[ FN ] = LAYOUT_60_hhkb(
    KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_DEL, 
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, 
    KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, 
    KC_TRNS, KC_MPLY, KC_VOLD, KC__VOLUP, KC_MUTE, KC_MPRV, KC_MFFD, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, MO( MAINT ), KC_TRNS, KC_TRNS
  ),
  /*
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │RESET│ BL  │     │     │     │     │     │     │     │     │     │     │     │     │ Del │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┤
  │ Tab │     │     │     │     │     │     │     │     │     │     │     │     │           │
  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴───────────┤
  │Ctrl │     │     │     │     │     │     │     │     │     │     │     │      Enter      │
  ├─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼───────────┬─────┤
  │   Shift   │     │     │     │     │     │     │     │     │     │     │   Shift   │ FN  │
  ├─────┬─────┼─────┼─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┼─────┼─────┬─────┼─────┤
  │█████│ Alt │ Gui │                     MAINT                     │ Gui │ Alt │█████│█████│
  └─────┴─────┴─────┴───────────────────────────────────────────────┴─────┴─────┴─────┴─────┘
  */
	[ MAINT ] = LAYOUT_60_hhkb(
    RESET, TO( BL ), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, LGUI(KC_F8), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO
  ),
};

const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 10, 5, 5};


void keyboard_post_init_user(void) {
  backlight_enable();
  backlight_level( 15 );
  rgblight_enable();
  // rgblight_setrgb( 0x58, 0x00, 0x93 );
  // rgblight_sethsv( 276, 255, 148 );
  rgblight_sethsv( 274, 212, 82 );
  rgblight_mode( RGBLIGHT_MODE_BREATHING + 1 );
};
