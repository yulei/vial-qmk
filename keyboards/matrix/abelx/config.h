/**
 * config.h
 *
<<<<<<< HEAD
=======
 * Copyright 2020 astro <yuleiz@gmail.com>
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
>>>>>>> upstream/vial
 */

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID  0x4D58   // MX
#define PRODUCT_ID 0xAB87   // abelx keyboard
#define DEVICE_VER 0x0001
#define MANUFACTURER MATRIX
<<<<<<< HEAD
#define PRODUCT Matrix ABELX
#define DESCRIPTION Matrix abelx keyboard
=======
#define PRODUCT ABELX
>>>>>>> upstream/vial

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 16

<<<<<<< HEAD
=======
#define DEF_PIN(port, pin) (((port) << 8) | pin)
#define GET_PORT(pp) (((pp) >> 8) & 0xFF)
#define GET_PIN(pp) ((pp) & 0xFF)

#define CUSTOM_MATRIX_ROW_PINS { \
    DEF_PIN(TCA6424_PORT2, 7), \
    DEF_PIN(TCA6424_PORT2, 6), \
    DEF_PIN(TCA6424_PORT2, 0), \
    DEF_PIN(TCA6424_PORT2, 2), \
    DEF_PIN(TCA6424_PORT2, 4), \
    DEF_PIN(TCA6424_PORT2, 5) }

#define CUSTOM_MATRIX_COL_PINS { \
    DEF_PIN(TCA6424_PORT2, 1), \
    DEF_PIN(TCA6424_PORT1, 7), \
    DEF_PIN(TCA6424_PORT1, 6), \
    DEF_PIN(TCA6424_PORT1, 5), \
    DEF_PIN(TCA6424_PORT1, 4), \
    DEF_PIN(TCA6424_PORT1, 3), \
    DEF_PIN(TCA6424_PORT1, 2), \
    DEF_PIN(TCA6424_PORT1, 1), \
    DEF_PIN(TCA6424_PORT1, 0), \
    DEF_PIN(TCA6424_PORT0, 7), \
    DEF_PIN(TCA6424_PORT0, 6), \
    DEF_PIN(TCA6424_PORT0, 5), \
    DEF_PIN(TCA6424_PORT0, 4), \
    DEF_PIN(TCA6424_PORT0, 3), \
    DEF_PIN(TCA6424_PORT0, 2), \
    DEF_PIN(TCA6424_PORT0, 1) }

#define ROW1_MASK 0x80
#define ROW2_MASK 0x40
#define ROW3_MASK 0x01
#define ROW4_MASK 0x04
#define ROW5_MASK 0x10
#define ROW6_MASK 0x20
#define ROW_PORT TCA6424_PORT2

#define COL1_MASK 0x02
#define COL2_MASK 0x80
#define COL3_MASK 0x40
#define COL4_MASK 0x20
#define COL5_MASK 0x10
#define COL6_MASK 0x08
#define COL7_MASK 0x04
#define COL8_MASK 0x02
#define COL9_MASK 0x01
#define COL10_MASK 0x80
#define COL11_MASK 0x40
#define COL12_MASK 0x20
#define COL13_MASK 0x10
#define COL14_MASK 0x08
#define COL15_MASK 0x04
#define COL16_MASK 0x02
>>>>>>> upstream/vial

#define UNUSED_PINS

#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE    5

// i2c setting
#define USE_I2CV1
#define I2C1_SCL 8
#define I2C1_SDA 9
#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2

<<<<<<< HEAD
#define FOR_ME  0

// rgb light setting
#if FOR_ME
#define RGBLED_NUM 11
#else
#define RGBLED_NUM 4
#endif
#define RGB_DI_PIN B4
#define RGBLIGHT_ANIMATIONS

#define EFFECTS_LED_NUM RGBLED_NUM

#define AW9523B_RGB_NUM 4

#define DRIVER_LED_TOTAL 11
#define IS31FL3236_ADDR 0x78
#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP FALSE

#define VIAL_INSECURE
#define VIAL_KEYBOARD_UID {0xFD, 0x18, 0xB5, 0x4A, 0x99, 0x22, 0x34, 0xCA}
=======

// rgb light setting
#define RGBLED_NUM 9
#define RGB_DI_PIN B4
#define RGBLIGHT_ANIMATIONS

#define AW9523B_RGB_NUM 4

#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP FALSE
>>>>>>> upstream/vial
