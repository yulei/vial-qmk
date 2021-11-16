/**
 * config.h
 *
  Copyright 2021 astro <yuleiz@gmail.com>
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4D58
#define PRODUCT_ID      0x494D
#define DEVICE_VER      0x0001
#define MANUFACTURER    Matrix Lab
#define PRODUCT         IM Plus

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15
#define MATRIX_ROW_PINS { E6, F0, F1, F4, F6, F5}
#define MATRIX_COL_PINS { F7, C7, C6, B6, B5, B4, D7, D6, D4, D5, D3, D2, B3, B1, B2}
#define UNUSED_PINS
#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

#define SCROLL_DI_PIN       B0
//rgb light setting
#define RGBLED_NUM          7
#define RGB_DI_PIN          B7
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP   8
#define RGBLIGHT_SAT_STEP   8
#define RGBLIGHT_VAL_STEP   8

#define DRIVER_LED_TOTAL    89
#define DRIVER_COUNT        1

#define VIAL_INSECURE
#define VIAL_KEYBOARD_UID {0xBF, 0x6D, 0x15, 0xA1, 0xB0, 0x07, 0xE7, 0x20}

//#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 64
//#define RGB_MATRIX_TYPING_HEATMAP
//#define RGB_MATRIX_KEYPRESSES