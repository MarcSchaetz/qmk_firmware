#include QMK_KEYBOARD_H
#include "keymap_german.h"


extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1

/*
 * ┌────┬────┐┌───┬───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │ F1 │ F2 ││ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │      │ 7 │ 8 │ 9 │ 0 │ ß │ ´ │DEL│   │   │
 * ├────┼────┤├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘    ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
 * │ F3 │ F4 ││ TAB │ Q │ W │ E │ R │ T │      │ Z │ U │ I │ O │ P │ Ü │ + │  #  │   │
 * ├────┼────┤├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐     └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │ F5 │ F6 ││ CAPS │ A │ S │ D │ F │ G │      │ H │ J │ K │ L │ Ö │ Ä │        │   │
 * ├────┼────┤├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐    └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │ F7 │ F8 ││ LSHIFT │ Y │ X │ C │ V │ B │      │ N │ M │ , │ . │ - │      │ ↑ │   │
 * ├────┼────┤├─────┬──┴┬──┴──┬┴──┬┴───┴───┤      ├───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │ F9 │ F10││LCTRL│   │ LOS │ALT│  SPACE │      │   MOD1   │AGR│ROS│CTR│ ← │ ↓ │ → │
 * └────┴────┘└─────┴───┴─────┴───┴────────┘      └──────────┴───┴───┴───┴───┴───┴───┘
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
/*ROW 1*/    KC_F1, KC_F2,  /**/ KC_GESC, DE_1,     DE_2,    DE_3,    DE_4,   DE_5,     DE_6,     DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_DEL,  KC_BSPC, KC_HOME,
/*ROW 2*/    KC_F3, KC_F4,  /**/ KC_TAB,  DE_Q,     DE_W,    DE_E,    DE_R,   DE_T,     DE_Z,     DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA, DE_PLUS, DE_HASH, KC_END,
/*ROW 3*/    KC_F5, KC_F6,  /**/ KC_CAPS, DE_A,     DE_S,    DE_D,    DE_F,   DE_G,     DE_H,     DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA, KC_ENT,  KC_PGUP,
/*ROW 4*/    KC_F7, KC_F8,  /**/ KC_LSFT, DE_Y,     DE_X,    DE_C,    DE_V,   DE_B,     DE_N,     DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT, KC_UP,   KC_PGDN,
/*ROW 5*/    KC_F9, KC_F10, /**/ KC_LCTL, MO(_FN1), KC_LGUI, KC_LALT, KC_SPC, MO(_FN1), MO(_FN1), KC_ALGR, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),

/*
 * ┌────┬────┐┌───┬───┬───┬───┬───┬───┬───┐      ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │    │    ││   │F1 │F2 │F3 │F4 │F5 │F6 │      │F7 │F8 │F9 │F10│F11│F12│   │   │   │
 * ├────┼────┤├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘    ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
 * │    │    ││  ^  │ < │ > │ [ │ ] │   │      │   │   │   │   │   │   │   │     │   │
 * ├────┼────┤├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐     └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │    │    ││      │   │   │ { │ } │ \ │      │ ← │ ↓ │ ↑ │ → │   │   │        │   │
 * ├────┼────┤├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐    └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │    │    ││        │ | │   │BSP│DEL│   │      │   │   │   │   │   │      │   │   │
 * ├────┼────┤├─────┬──┴┬──┴──┬┴──┬┴───┴───┤      ├───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    ││     │   │     │   │        │      │          │   │   │   │   │   │   │
 * └────┴────┘└─────┴───┴─────┴───┴────────┘      └──────────┴───┴───┴───┴───┴───┴───┘
 */
  [_FN1] = LAYOUT_65_with_macro(
/*ROW 1*/   _______, _______, /**/ KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,
/*ROW 2*/   _______, _______, /**/ DE_CIRC, DE_LABK, DE_RABK, DE_LBRC, DE_RBRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
/*ROW 3*/   _______, _______, /**/ _______, _______, _______, DE_LCBR, DE_RCBR, DE_BSLS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, _______,
/*ROW 4*/   _______, _______, /**/ _______, DE_PIPE, _______, KC_BSPC, KC_DEL,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
/*ROW 5*/   _______, _______, /**/ _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
