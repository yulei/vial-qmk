/**
 * config.h
 *
 */

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID  0x4D58   // MX
#define PRODUCT_ID 0x20AD   // 8XV2.0 Additional
#define DEVICE_VER 0x0001
#define MANUFACTURER MATRIX
#define PRODUCT 8XV2.0 Additional
#define DESCRIPTION Matrix 8XV2.0 Additional keyboard

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 16


#define UNUSED_PINS


#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE    5

// i2c setting
<<<<<<< HEAD
#define USE_I2CV1
#define I2C1_SCL 8
#define I2C1_SDA 9
=======
#define I2C1_SCL_PIN B8
#define I2C1_SDA_PIN B9
>>>>>>> upstream/vial
#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

// rgb light setting
#define RGB_DI_PIN B4     // reserved for future
#define RGBLED_NUM 16
#define RGBLIGHT_ANIMATIONS

#define EFFECTS_LED_NUM 4

#define DRIVER_ADDR_1 0b1110100
#define DRIVER_COUNT 1
#define DRIVER_LED_TOTAL (RGBLED_NUM+EFFECTS_LED_NUM)

#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP FALSE

#define VIAL_INSECURE
#define VIAL_KEYBOARD_UID {0xFD, 0x18, 0xB5, 0x4A, 0x99, 0x22, 0x34, 0xC9}
