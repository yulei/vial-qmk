/**
 * config.h
 *
    Copyright 2022 astro

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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4E65   //'Ne'
#define PRODUCT_ID      0x6E65   //'nc'
#define DEVICE_VER      0x0001
#define MANUFACTURER    Neson Design
#define PRODUCT         Nico

/* key matrix size */
#define MATRIX_ROWS     5
#define MATRIX_COLS     17
#define MATRIX_ROW_PINS { F0, E6, F5, F4, F1}
#define MATRIX_COL_PINS { C7, C6, B6, B5, B4, D7, D6, D4, D5, D3, D2, B7, B3, B2, B1, F6, F7 }
#define DIODE_DIRECTION COL2ROW

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


//rgb light setting
#define RGBLED_NUM          5
#define RGB_DI_PIN          B0
#define RGBLIGHT_HUE_STEP   8
#define RGBLIGHT_SAT_STEP   8
#define RGBLIGHT_VAL_STEP   8

//#define USB_SUSPEND_WAKEUP_DELAY 1000

#define LED_CAPS_LOCK_PIN   E2
