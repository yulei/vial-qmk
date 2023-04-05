/**
 * matrix.c
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

#include "quantum.h"
#include "matrix.h"
#include "SEGGER_RTT.h"

static pin_t main_col_pins[MATRIX_COLS] = MATRIX_COL_PINS;
static pin_t main_row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;

#define AUX_MATRIX_COLS 4
#define AUX_MATRIX_ROWS 3
#define AUX_MATRIX_COL_PINS {B6,B5,B4,B3}
#define AUX_MATRIX_ROW_PINS {B9,B8,B7}

static pin_t aux_col_pins[AUX_MATRIX_COLS] = AUX_MATRIX_COL_PINS;
static pin_t aux_row_pins[AUX_MATRIX_ROWS] = AUX_MATRIX_ROW_PINS;

// It's a 8421 encoder
#define KNOB_PIN_COUNT  4
#define KNOB_DEBOUNCE   20

typedef struct knob_8421{
        pin_t pins[KNOB_PIN_COUNT];
        pin_t com;
        uint8_t last;
        uint8_t current;
        bool    debounce;
        uint32_t ticks;
        keypos_t cw;
        keypos_t ccw;
} knob_8421_t;

knob_8421_t left_knob = {
    .pins = {A15, C11, C10, C12},
    .com = D2,
    .last = 0,
    .current = 0,
    .debounce = false,
    .ticks = 0,
    .cw = {0,5},
    .ccw = {1,5},
};

knob_8421_t right_knob = {
    .pins = {C0, C2, C1, C3},
    .com = A0,
    .last = 0,
    .current = 0,
    .debounce = false,
    .ticks = 0,
    .cw = {13,2},
    .ccw = {14,5},
};

static uint8_t knob_scan(knob_8421_t *knob)
{
    uint8_t data = 0;
    //writePinLow(com);
    //matrix_io_delay();
    for (int i = 0; i < KNOB_PIN_COUNT; i++) {
        if (readPin(knob->pins[i]) == 0) {
            data |= (1<<i);
        }
    }

    if (data != knob->current) {
        knob->current = data;
        knob->debounce = true;
        knob->ticks = timer_read32();
    } else {
        if (knob->debounce) {
            if (timer_elapsed32(knob->ticks) > KNOB_DEBOUNCE) {
                knob->debounce = false;
                if (knob->last != knob->current) {
                    SEGGER_RTT_printf(0, "Matrix scan: last=%x, current=%x\n", knob->last, knob->current);
                    return true;
                }
            }
        }
    }
    
    //writePinHigh(com);
    return false;
}

static void knob_init(knob_8421_t *knob)
{
    setPinOutput(knob->com);
    writePinLow(knob->com);
    for (int i = 0; i < KNOB_PIN_COUNT; i++) {
        setPinInputHigh(knob->pins[i]);
    }
    wait_ms(100);
    for (int i = 0; i < KNOB_PIN_COUNT; i++) {
        if (readPin(knob->pins[i]) == 0) {
            knob->last |= (1<<i);
        }
    }
    knob->current = knob->last;
    knob->ticks = timer_read32();
}

static void knob_tap_key(knob_8421_t *knob)
{
    keyevent_t evt = {.pressed = true };
    if ((knob->current > knob->last) || ((knob->last-knob->current)>2)) {
        evt.key = knob->cw;
    } else {
        evt.key = knob->ccw;
    }
    evt.time = timer_read();
    action_exec(evt);

    evt.pressed = false;
    evt.time = timer_read();
    action_exec(evt);
    knob->last = knob->current;
}

void matrix_init_custom(void)
{
    // init main matrix
    for (int col = 0; col < MATRIX_COLS; col++) {
        setPinInputHigh(main_col_pins[col]);
    }

    for (int row = 0; row < MATRIX_ROWS; row++) {
        setPinOutput(main_row_pins[row]);
        writePinHigh(main_row_pins[row]);
    }

    // init aux matrix
    for (int col = 0; col < AUX_MATRIX_COLS; col++) {
        setPinInputHigh(aux_col_pins[col]);
    }

    for (int row = 0; row < AUX_MATRIX_ROWS; row++) {
        setPinOutput(aux_row_pins[row]);
        writePinHigh(aux_row_pins[row]);
    }

    knob_init(&left_knob);
    knob_init(&right_knob);
    SEGGER_RTT_printf(0, "Matrix Init: left knob=%x, right knob=%x\n", left_knob.last, right_knob.last);
}


bool matrix_scan_custom(matrix_row_t current_matrix[])
{
    bool changed = false;
    // scan main matrix
    for (int row = 0; row < MATRIX_ROWS-1; row++) {
        writePinLow(main_row_pins[row]);
        matrix_io_delay();
        matrix_row_t last_row_value    = current_matrix[row];
        matrix_row_t current_row_value = last_row_value;
        for (int col = 0; col < MATRIX_COLS; col++) {
            if (readPin(main_col_pins[col])) {
                current_row_value &= ~(1<<col);
            } else {
                current_row_value |= (1<<col);
            }
            if (last_row_value != current_row_value) {
                current_matrix[row] = current_row_value;
                changed = true;
            }
        }
        writePinHigh(main_row_pins[row]);
    }
    // scan aux matrix
    matrix_row_t last_row_value    = current_matrix[MATRIX_ROWS-1];
    matrix_row_t current_row_value = last_row_value;
    for (int row = 0; row < AUX_MATRIX_ROWS; row++) {
        writePinLow(aux_row_pins[row]);
        matrix_io_delay();
        for (int col = 0; col < AUX_MATRIX_COLS; col++) {
            if (readPin(aux_col_pins[col])) {
                current_row_value &= ~(1<<(row*AUX_MATRIX_COLS + col + 2));
            } else {
                current_row_value |=  (1<<(row*AUX_MATRIX_COLS + col + 2));
            }
            if (last_row_value != current_row_value) {
                current_matrix[MATRIX_ROWS-1] = current_row_value;
                changed = true;
            }
        }
        writePinHigh(aux_row_pins[row]);
    }

    if (knob_scan(&left_knob)){
        SEGGER_RTT_printf(0, "Knob scan: left\n");
        knob_tap_key(&left_knob);
    }

    if (knob_scan(&right_knob)){
        SEGGER_RTT_printf(0, "Knob scan: right\n");
        knob_tap_key(&right_knob);
    }
    return changed;
}
