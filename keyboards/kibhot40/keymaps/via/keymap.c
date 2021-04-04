#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _FN,
  _FN2,
};
#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT( \
        KC_ESC,    KC_Q, KC_W, KC_E, KC_R, KC_T,       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,  \
        KC_TAB,    KC_A, KC_S, KC_D, KC_F, KC_G,       KC_H, KC_J, KC_K, KC_L, KC_QUOT,      KC_ENTER, \
        KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B,       KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLSH, KC_RSHIFT, \
                   KC_LWIN, KC_LALT, KC_SPACE,         MO(_FN), MO(_FN2),                   KC_RWIN, KC_RCTL \
    ),

    [_FN] = LAYOUT( \
        KC_GRV,  ______, ______, ______, ______, ______,                KC_PSCR, KC_HOME, KC_UP, KC_END, ______, KC_BSPC, KC_DEL,  \
        KC_CAPS, ______, ______, ______, ______, ______,                ______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGUP,      ______, \
        ______,  ______, ______, KC_MUTE, KC_VOLD, KC_VOLU,       ______, ______, ______, ______, KC_PGDN, ______, \
        ______, ______, ______,                    ______, ______,                   ______, ______ \
    ),

    [_FN2] = LAYOUT( \
        ______,  KC_1, KC_2, KC_3, KC_4, KC_5,    KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,  \
        KC_F1,   KC_F2, KC_F3, KC_F4, KC_F5,      KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, \
        ______,  ______, ______, ______, ______, ______,      ______, ______, ______, ______, ______, ______, \
        ______, ______, ______,                   ______, ______,                   ______, ______ \
    )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_F12);
        } else {
            tap_code(KC_F11);
        }
    }
}
