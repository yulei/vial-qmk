
/**
 * config.h
 *
    Copyright 2023 astro

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

#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS {C14,C13,C15,A8,B2,A7} 
#define MATRIX_COL_PINS {B1,B0,C5,B10,B12,B13,B14,B15,C6,C7,C8,C9,A3,A2,A1}  

#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE    5

#define STM32_HSECLK 16000000

#define FEE_PAGE_SIZE            0x4000
#define FEE_PAGE_COUNT           1
#define FEE_PAGE_BASE_ADDRESS    0x800C000

#define LED_CAPS_LOCK_PIN        A10

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE
