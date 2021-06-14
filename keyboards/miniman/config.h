/* Copyright 2019
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */

#define VENDOR_ID       0x1209
#define PRODUCT_ID      0xA1E5
#define DEVICE_VER      0x0008
#define MANUFACTURER    bowoekren
#define PRODUCT         miniman
#define DESCRIPTION     miniman

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define QMK_ESC_OUTPUT F6 // usually COL
#define QMK_ESC_INPUT F1 // usually ROW
#define VIAL_KEYBOARD_UID {0x69, 0x06, 0xBC, 0x51, 0xE6, 0x98, 0x54, 0x46}
// #define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
// #define VIAL_UNLOCK_COMBO_COLS { 1, 10 }
