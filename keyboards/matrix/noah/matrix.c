/**
 * matrix.c
 */

#include "quantum.h"
#include "matrix.h"

/**
 * seems the A9 pin can's work in input pull high,
 * thus have to implement the custom matrix scan.
 */
static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

void matrix_init_custom(void)
{
    for (int i = 0; i < MATRIX_COLS; i++) {
        setPinOutput(col_pins[i]);
        writePinLow(col_pins[i]);
    }

    for (int j = 0; j < MATRIX_ROWS; j++) {
        setPinInputLow(row_pins[j]);
    }
}

bool matrix_scan_custom(matrix_row_t current_matrix[])
{
    bool changed = false;
    for (int col = 0; col < MATRIX_COLS; col++) {
        // Select col and wait for col selecton to stabilize
        writePinHigh(col_pins[col]);

        matrix_io_delay();

        // For each row...
        for(uint8_t row = 0; row < MATRIX_ROWS; row++) {
            // Store last value of row prior to reading
            matrix_row_t last_row_value = current_matrix[row];

            // Check row pin state
            if (readPin(row_pins[row])) {
                // Pin HI, set col bit
                current_matrix[row] |= (1 << col);
            } else {
                // Pin LOW, clear col bit
                current_matrix[row] &= ~(1 << col);
            }

            // Determine if the matrix changed state
            if ((last_row_value != current_matrix[row]) && !(changed)) {
                changed = true;
            }
        }
        // Unselect col
        writePinLow(col_pins[col]);
    }
    return changed;
}
