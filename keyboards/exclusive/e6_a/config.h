/**
 * config.h
 *
 */
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4154      //AT
#define PRODUCT_ID      0x4541      //E6
#define DEVICE_VER      0x0062
#define MANUFACTURER    astro
#define PRODUCT         e6 simple

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14
/* key matrix pins */
#define MATRIX_ROW_PINS { F0, E6, C7, F5, F4}
#define MATRIX_COL_PINS { F7, B0, C6, B6, B5, B4, D7, D6, D4, D5, D3, D2, D1, D0}
#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW

//rgb light setting
#define RGBLED_NUM      10
#define RGB_DI_PIN      F1
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#define LED_CAPS_LOCK_PIN F6

#define VIAL_INSECURE
#define VIAL_KEYBOARD_UID {0xB5, 0xD0, 0xB9, 0x3A, 0xB8, 0x1F, 0xCA, 0x7C}