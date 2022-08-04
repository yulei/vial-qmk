/**
    Copyright 2022 by astro

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

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4543  //EC 
#define PRODUCT_ID      0x6672  //fr
#define DEVICE_VER      0x0001
#define MANUFACTURER    astro
#define PRODUCT         fr86

/* key matrix size */
#define MATRIX_ROWS         6
#define MATRIX_COLS         16

#ifdef V2
#define MATRIX_ROW_PINS     { C7, C6, B15, B14, B13, B12 }

#define L_MASK              0x08
#define R_MASK              0x10
#define MATRIX_COL_CHANNELS { L_MASK|2, L_MASK|1, L_MASK|0, L_MASK|3, L_MASK|5, L_MASK|7, L_MASK|6, L_MASK|4, \
                            R_MASK|2, R_MASK|1, R_MASK|0, R_MASK|3, R_MASK|5, R_MASK|7, R_MASK|6, R_MASK|4}

#define LEFT_EN_PIN     A6
#define RIGHT_EN_PIN    A5
#define COL_A_PIN       C5
#define COL_B_PIN       C4
#define COL_C_PIN       A7

#define DISCHARGE_PIN   C3
#define KEY_PIN         A2

#define LED_CAPS_LOCK_PIN       C8
#define LED_SCROLL_LOCK_PIN     C9
#define LED_NUM_LOCK_PIN        C12

#define FEE_PAGE_SIZE           0x4000
#define FEE_PAGE_COUNT          1
#define FEE_PAGE_BASE_ADDRESS   0x800C000
#else
#define MATRIX_ROW_PINS     { B2, B10, B12, B13, B14, B15 }

#define L_MASK          0x08
#define R_MASK          0x10
#define MATRIX_COL_CHANNELS { L_MASK|4, L_MASK|6, L_MASK|7, L_MASK|5, L_MASK|3, L_MASK|0, L_MASK|1, L_MASK|2, \
                            R_MASK|4, R_MASK|6, R_MASK|7, R_MASK|5, R_MASK|3, R_MASK|0, R_MASK|1, R_MASK|2}

#define LEFT_EN_PIN     C5
#define RIGHT_EN_PIN    C4
#define COL_A_PIN       A7
#define COL_B_PIN       A6
#define COL_C_PIN       A5

#define DISCHARGE_PIN   A4
#define KEY_PIN         A2

#define LED_CAPS_LOCK_PIN       B1
#define LED_SCROLL_LOCK_PIN     B0
#define LED_NUM_LOCK_PIN        C6 
#endif

#define LOW_THRESHOLD   550
#define HIGH_THRESHOLD  650

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW
/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

#define STM32_HSECLK 16000000
