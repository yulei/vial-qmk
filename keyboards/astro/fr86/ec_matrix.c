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
#include "quantum.h"
#include "matrix.h"
#include "analog.h"
#include "debug.h"

/* matrix state(1:on, 0:off) */
extern matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
extern matrix_row_t matrix[MATRIX_ROWS];      // debounced values

#define WAIT_DISCHARGE()
#define WAIT_CHARGE()
#define COL_A_MASK  0x01
#define COL_B_MASK  0x02
#define COL_C_MASK  0x04

// pin connections
const uint32_t  ec_row_pins[]     = MATRIX_ROW_PINS;
const uint32_t  ec_col_channels[] = MATRIX_COL_CHANNELS;

static inline void discharge_capacitor(void)
{
    setPinOutput(DISCHARGE_PIN);
}

static inline void charge_capacitor(uint8_t row)
{
    setPinInput(DISCHARGE_PIN);
    writePinHigh(ec_row_pins[row]);
}

static inline void clear_all_rows(void)
{
    for (int row = 0; row < MATRIX_ROWS; row++) {
        writePinLow(ec_row_pins[row]);
    }
}

static void ec_matrix_init(void)
{
    for (int row = 0; row < MATRIX_ROWS; row++) {
        setPinOutput(ec_row_pins[row]);
        writePinLow(ec_row_pins[row]);
    }

    setPinOutput(COL_A_PIN);
    writePinLow(COL_A_PIN);
    setPinOutput(COL_B_PIN);
    writePinLow(COL_B_PIN);
    setPinOutput(COL_C_PIN);
    writePinLow(COL_C_PIN);

    setPinOutput(DISCHARGE_PIN);
    writePinLow(DISCHARGE_PIN);

    setPinOutput(LEFT_EN_PIN);
    writePinHigh(LEFT_EN_PIN);
    setPinOutput(RIGHT_EN_PIN);
    writePinHigh(RIGHT_EN_PIN);
}

static uint16_t ec_matrix_sense_key(uint8_t row, uint8_t col)
{
    uint16_t value = 0;

    discharge_capacitor();
    uint32_t  channel = ec_col_channels[col];
    writePin(LEFT_EN_PIN,  (channel&L_MASK) ? 0 : 1);
    writePin(RIGHT_EN_PIN, (channel&R_MASK) ? 0 : 1);

    writePin(COL_A_PIN, (channel&COL_A_MASK) ? 1 : 0);
    writePin(COL_B_PIN, (channel&COL_B_MASK) ? 1 : 0);
    writePin(COL_C_PIN, (channel&COL_C_MASK) ? 1 : 0);
 
    clear_all_rows();

    WAIT_DISCHARGE();

    // chSysLock();
    ATOMIC_BLOCK_FORCEON {
        charge_capacitor(row);

        WAIT_CHARGE();
        value = analogReadPin(KEY_PIN);
    }
    // chSysUnlock();

    return value;
}

static bool ec_matrix_update(matrix_row_t* current_row, uint8_t row, uint8_t col, uint16_t value)
{
    bool pressed = (*current_row >> col) & 1;

    // press to release
    if (pressed && (value < LOW_THRESHOLD)) {
        *current_row &= ~(1 << col);
        return true;
    }

    // release to press
    if ((!pressed) && (value > HIGH_THRESHOLD)) {
        *current_row |= (1 << col);
        return true;
    }

    return false;
}

bool ec_matrix_scan(matrix_row_t current_matrix[])
{
    bool changed = false;
    for (int col = 0; col < MATRIX_COLS; col++) {
        for (int row = 0; row < MATRIX_ROWS; row++) {
            uint16_t value = ec_matrix_sense_key(row, col);
            changed |= ec_matrix_update(&current_matrix[row], row, col, value);
        }
    }

    return changed;
}

void matrix_init_custom(void) {
    ec_matrix_init();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    return ec_matrix_scan(current_matrix);
}
