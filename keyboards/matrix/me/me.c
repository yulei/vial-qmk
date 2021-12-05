/**
 * me.c
 *
  Copyright 2021 astro 
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

#include "me.h"
#include "is31fl3236.h"
#include "rgb_effects.h"

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, OUT_36, OUT_35, OUT_34},
    {0, OUT_33, OUT_32, OUT_31},
    {0, OUT_30, OUT_29, OUT_28},
    {0, OUT_27, OUT_26, OUT_25},
    {0, OUT_24, OUT_23, OUT_22},
    {0, OUT_21, OUT_20, OUT_19},
    {0, OUT_18, OUT_17, OUT_16},
    {0, OUT_15, OUT_14, OUT_13},
    {0, OUT_12, OUT_11, OUT_10},
    {0, OUT_9, OUT_8, OUT_7},
    {0, OUT_6, OUT_5, OUT_4},
    {0, OUT_3, OUT_2, OUT_1},
};

void effects_set_color(uint8_t index, uint8_t hue, uint8_t sat, uint8_t val)
{
    if (index >= DRIVER_LED_TOTAL || !IS31FL3236_available()) return;

    HSV hsv = {hue, sat, val};
    RGB rgb = hsv_to_rgb(hsv);
    IS31FL3236_set_color(index, rgb.r, rgb.g, rgb.b);
}

void effects_set_color_all(uint8_t hue, uint8_t sat, uint8_t val)
{
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
      effects_set_color(i, hue, sat, val);
    }
}

static bool top_led = true;
bool process_record_kb(uint16_t keycode, keyrecord_t *record)
{
    if (top_led || !IS31FL3236_available()) return process_record_user(keycode, record);

    if (record->event.pressed) {
        switch(keycode) {
            case KC_F13:
                top_led = !top_led;
                return false;
            case RGB_TOG:
                rgb_effects_toggle();
                return false;
            case RGB_MODE_FORWARD:
                rgb_effects_inc_mode();
                return false;
            case RGB_MODE_REVERSE:
                rgb_effects_dec_mode();
                return false;
            case RGB_HUI:
                rgb_effects_inc_hue();
                return false;
            case RGB_HUD:
                rgb_effects_dec_hue();
                return false;
            case RGB_SAI:
                rgb_effects_inc_sat();
                return false;
            case RGB_SAD:
                rgb_effects_dec_sat();
                return false;
            case RGB_VAI:
                rgb_effects_inc_val();
                return false;
            case RGB_VAD:
                rgb_effects_dec_val();
                return false;
            case RGB_SPI:
                rgb_effects_inc_speed();
                return false;
            case RGB_SPD:
                rgb_effects_dec_speed();
                return false;
            default:
                break;
        }
    }
    return process_record_user(keycode, record);
}


void matrix_init_kb(void)
{
    IS31FL3236_init(IS31FL3236_ADDR);
    if (IS31FL3236_available()) {
        rgb_effects_init();
    }

    matrix_init_user();
}

void housekeeping_task_kb(void)
{
    if (IS31FL3236_available()) {
        rgb_effects_task();
        IS31FL3236_update_pwm_buffers(IS31FL3236_ADDR);
    }
    housekeeping_task_user();
}
