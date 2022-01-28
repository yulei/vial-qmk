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

#define FOR_ME 0
#if FOR_ME
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
    if (!IS31FL3236_available()) return process_record_user(keycode, record);
    if (top_led && (record->event.pressed && keycode != KC_F13)) return process_record_user(keycode, record);

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

#else
#include "i2c_master.h"
#include "led/issi/is31fl3731.h"
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    // full
    {0, C1_9,   C3_10,  C4_10},
    {0, C1_10,  C2_10,  C4_11},
    {0, C1_11,  C2_11,  C3_11},
    {0, C1_12,  C2_12,  C3_12},
    {0, C1_13,  C2_13,  C3_13},
    {0, C1_14,  C2_14,  C3_14},
    {0, C1_15,  C2_15,  C3_15},
    {0, C1_16,  C2_16,  C3_16},


    {0, C9_9,   C8_9,   C7_9},
    {0, C9_10,  C8_10,  C7_10},
    {0, C9_11,  C8_11,  C7_11},
    {0, C9_12,  C8_12,  C7_12},
    {0, C9_13,  C8_13,  C7_13},
    {0, C9_14,  C8_14,  C7_14},
    {0, C9_15,  C8_15,  C6_14},
    {0, C9_16,  C7_15,  C6_15},

    {0, C1_1,   C3_2,   C4_2},
    {0, C1_2,   C2_2,   C4_3},
    {0, C1_3,   C2_3,   C3_3},
    {0, C1_4,   C2_4,   C3_4},
    {0, C1_5,   C2_5,   C3_5},
    {0, C1_6,   C2_6,   C3_6},
    {0, C1_7,   C2_7,   C3_7},
    {0, C1_8,   C2_8,   C3_8},

    {0, C9_1,   C8_1,   C7_1},
    {0, C9_2,   C8_2,   C7_2},
    {0, C9_3,   C8_3,   C7_3},
    {0, C9_4,   C8_4,   C7_4},
    {0, C9_5,   C8_5,   C7_5},
    {0, C9_6,   C8_6,   C7_6},
    {0, C9_7,   C8_7,   C6_6},
    {0, C9_8,   C7_7,   C6_7},

#if 0
    {0, C1_9,   C3_10,  C4_10},
    {0, C1_10,  C2_10,  C4_11},
    {0, C1_11,  C2_11,  C3_11},
    {0, C1_12,  C2_12,  C3_12},
    {0, C1_13,  C2_13,  C3_13},
    {0, C1_14,  C2_14,  C3_14},
    {0, C1_15,  C2_15,  C3_15},
    {0, C1_16,  C2_16,  C3_16},

    {0, C9_9,   C8_9,   C7_9},
    {0, C9_10,  C8_10,  C7_10},
    {0, C9_11,  C8_11,  C7_11},
    {0, C9_12,  C8_12,  C7_12},
    {0, C9_13,  C8_13,  C7_13},
#endif
//    {0, C9_14,  C8_14,  C7_14},
//    {0, C9_15,  C8_15,  C6_14},
//    {0, C9_16,  C7_15,  C6_15},
};

void rgblight_call_driver(LED_TYPE *start_led, uint8_t num_leds)
{
    for (int i = 0; i < num_leds; i++) {
        IS31FL3731_set_color(i, start_led[i].r, start_led[i].g, start_led[i].b);
    }

    ws2812_setleds(start_led, num_leds);
}

#endif


void matrix_init_kb(void)
{
    #if FOR_ME
    IS31FL3236_init(IS31FL3236_ADDR);
    if (IS31FL3236_available()) {
        rgb_effects_init();
    }
    #else
    i2c_init();
    IS31FL3731_init(IS31FL3731_ADDR);
    for (int index = 0; index < DRIVER_LED_TOTAL; index++) {
        bool enabled = true;
        IS31FL3731_set_led_control_register(index, enabled, enabled, enabled);
    }
    IS31FL3731_update_led_control_registers(IS31FL3731_ADDR, 0);
    #endif

    matrix_init_user();
}

void housekeeping_task_kb(void)
{
    #if FOR_ME
    if (IS31FL3236_available()) {
        rgb_effects_task();
        IS31FL3236_update_pwm_buffers(IS31FL3236_ADDR);
    }
    #else
        IS31FL3731_update_pwm_buffers(IS31FL3731_ADDR, 0);
    #endif
    housekeeping_task_user();
}
