#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0xD772
#define PRODUCT_ID      0x0003
#define DEVICE_VER      0x0001
#define MANUFACTURER    dayatz
#define PRODUCT         KibHot40
#define DESCRIPTION     40% hotswap

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 13

/* key matrix pins */
#define MATRIX_ROW_PINS { B1, B2, B10, A0 }
#define MATRIX_COL_PINS { A6, A7, B0, A4, B11, B9, B8, A9, A10, A15, B3, B4, B5 }
#define UNUSED_PINS

/* bootloader (first top leftmost key)  */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

#define RGBLIGHT_ANIMATIONS
#define RGB_DI_PIN B15
#define RGBLED_NUM 16
#define WS2812_SPI SPID2

#define I2C1_SCL 6
#define I2C1_SDA 7

#define TAP_CODE_DELAY 10 // Need this delay for some keys like VOLD/VOLU to work
#define ENCODERS_PAD_A { A3 }
#define ENCODERS_PAD_B { A5 }

#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 32
#define EEPROM_START_ADDRESS
#define FEE_MCU_FLASH_SIZE                              \
({                                                      \
    uint16_t (*flash_size) = (uint16_t*)(0x1FFFF7E0);   \
    *flash_size;                                        \
})

#define VIAL_KEYBOARD_UID {0xF9, 0xBE, 0xEC, 0x03, 0x85, 0xCE, 0xAC, 0x9D}
#define VIAL_ENCODER_DEFAULT { KC_F12, KC_F11, KC_C, KC_D, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
#define VIAL_ENCODER_KEYCODE_DELAY 10
