/**
 * config.h
 *
 */

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID  0x4D58   // MX
#define PRODUCT_ID 0xAB87   // abelx keyboard
#define DEVICE_VER 0x0001
#define MANUFACTURER MATRIX
#define PRODUCT Matrix ABELX
#define DESCRIPTION Matrix abelx keyboard

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 16


#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE    5

// i2c setting
#define USE_I2CV1
#define I2C1_SCL 8
#define I2C1_SDA 9
#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2


// rgb light setting
#define RGBLED_NUM 4
#define RGB_DI_PIN B4
#define RGBLIGHT_ANIMATIONS
#define EFFECTS_LED_NUM RGBLED_NUM

#define AW9523B_RGB_NUM 4

#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP FALSE

#define VIAL_INSECURE
#define VIAL_KEYBOARD_UID {0xFD, 0x18, 0xB5, 0x4A, 0x99, 0x22, 0x34, 0xCA}
