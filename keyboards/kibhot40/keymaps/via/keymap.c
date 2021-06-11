#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _FN,
  _FN2,
};
#define ______ KC_TRNS
// Tap Dance declarations
typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    ESC_TAB_CTRL
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        return TD_DOUBLE_TAP;
    } else {
        return TD_NONE;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'

}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void x_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_ESC); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTRL); break;
        case TD_DOUBLE_TAP: register_code(KC_TAB); break;
        case TD_NONE: break;
    }
}

void x_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_ESC); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTRL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_TAB); break;
        case TD_NONE: break;
    }
    xtap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [ESC_TAB_CTRL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT( \
        KC_TAB,    KC_Q, KC_W, KC_E, KC_R, KC_T,       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,  \
        TD(ESC_TAB_CTRL),    KC_A, KC_S, KC_D, KC_F, KC_G,       KC_H, KC_J, KC_K, KC_L, KC_QUOT,      KC_ENTER, \
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

