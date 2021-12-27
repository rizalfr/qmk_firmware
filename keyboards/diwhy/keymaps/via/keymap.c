#include "kb.h"
#include "print.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_all(
		KC_CAPS, RESET, KC_ASTR, KC_MINS,
		KC_7, KC_8, KC_9,
		KC_4, KC_5, KC_6, KC_PLUS,
		KC_1, KC_2, KC_3,
		KC_0, KC_DOT, KC_ENT),

	[1] = LAYOUT_all(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS),
};

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    #ifdef CONSOLE_ENABLE
        print("led_update_user\n");
        uprintf("led_state.caps_lock: %d\n", led_state.caps_lock);
    #endif
    if(res) {
        // writePin sets the pin high for 1 and low for 0.
        // In this example the pins are inverted, setting
        // it low/0 turns it on, and high/1 turns the LED off.
        // This behavior depends on whether the LED is between the pin
        // and VCC or the pin and GND.
        // writePin(B0, !led_state.num_lock);
        writePin(B5, !led_state.caps_lock);
        // writePin(B2, !led_state.scroll_lock);
        // writePin(B3, !led_state.compose);
        // writePin(B4, !led_state.kana);
    }
    return res;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
