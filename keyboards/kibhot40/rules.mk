MCU_FAMILY = STM32
MCU_SERIES = STM32F1xx
MCU_STARTUP = stm32f1xx
MCU  = cortex-m3
ARMV = 7

# GENERIC STM32F103C8T6 board - stm32duino bootloader
OPT_DEFS = -DCORTEX_VTOR_INIT=0x2000
MCU_LDSCRIPT = STM32F103x8_stm32duino_bootloader
BOARD = GENERIC_STM32_F103

DFU_ARGS = -d 6b62:0000 -R
DFU_SUFFIX_ARGS = -v 6b62 -p 0000

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = lite	# Device can be switched into bootloader mode without pressing the reset button on the PCB
MOUSEKEY_ENABLE = no    # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes   # Audio control and System control(+450)
CONSOLE_ENABLE = no    # Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
SLEEP_LED_ENABLE = yes  # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes       # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no   # Enable keyboard backlight functionality
AUDIO_ENABLE = no
RGBLIGHT_ENABLE = yes
WS2812_DRIVER = spi
OLED_DRIVER_ENABLE = yes
ENCODER_ENABLE = yes
# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
