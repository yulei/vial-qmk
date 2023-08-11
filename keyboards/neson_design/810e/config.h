/**
 * Copyright 2023 astro
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

#define BOARD_OTG_NOVBUSSENS 1
#define STM32_HSECLK 16000000U

/* key matrix size */
#define MATRIX_ROWS         5
#define MATRIX_COLS         18
#define MATRIX_ROW_PINS     {C13, C14, A6, A7, A5}
#define MATRIX_COL_PINS     {B7, B5, B4, B3, A15, A8, B15, B14, B13, B12, B10, B2, B1, B0, A4, A3, A2, A1}

#define RGB_MATRIX_LED_COUNT    96

#define IS31FL3729_LED_BEGIN    0
#define IS31FL3729_LED_TOTAL    90

#define IS31FL3236_LED_BEGIN    90
#define IS31FL3236_LED_TOTAL    6

//rgb light setting
#define RGBLED_NUM          96
#define RGB_DI_PIN          B6
//#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP   8
#define RGBLIGHT_SAT_STEP   8
#define RGBLIGHT_VAL_STEP   8

#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_STATIC_PATTERNS
