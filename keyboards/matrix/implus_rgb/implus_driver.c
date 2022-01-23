
/**
 * implus_driver.c
 * Copyright 2021 astro <yuleiz@gmail.com>
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

#include "rgb_matrix.h"
#include "is31fl3236.h"
#include "is31fl3731_imp.h"
#include "ws2812.h"
#include "i2c_master.h"

#define DRIVER_0_ADDR       0x50
#define DRIVER_1_ADDR       0x7E
#define DRIVER_2_ADDR       0x78

static void driver_init(void);
static void driver_set_color(int index, uint8_t r, uint8_t g, uint8_t b);
static void driver_set_color_all(uint8_t r, uint8_t g, uint8_t b);
static void driver_flush(void);

static LED_TYPE scroll_led = {0,0,0};
static bool scroll_led_dirty = true;
static void scroll_led_set(uint8_t r, uint8_t g, uint8_t b)
{
    scroll_led.r = g >> 2;
    scroll_led.g = r >> 2;
    scroll_led.b = b >> 2;
    //scroll_led.r = g;
    //scroll_led.g = r;
    //scroll_led.b = b;
    scroll_led_dirty = true;
}

const rgb_matrix_driver_t rgb_matrix_driver = {
    .init = driver_init,
    .set_color = driver_set_color,
    .set_color_all = driver_set_color_all,
    .flush = driver_flush,
};

static void driver_init(void)
{
    i2c_init();

    IS31FL3733_init(DRIVER_0_ADDR, 0);
    for (int i = 0; i < 64; i++) {
        bool enabled = true;
        IS31FL3733_set_led_control_register(i, enabled, enabled, enabled);
    }
    IS31FL3733_update_led_control_registers(DRIVER_0_ADDR, 0);

    IS31FL3236_init(DRIVER_1_ADDR, 0);
    IS31FL3236_init(DRIVER_2_ADDR, 1);

    IS31FL3731_init(IS31FL3731_ADDR);
    for (int i = 0; i < 13; i++) {
        bool enabled = true;
        IS31FL3731_set_led_control_register(i, enabled, enabled, enabled);
    }
    IS31FL3731_update_led_control_registers(IS31FL3731_ADDR, 0);
}

HSV rgb2hsv(RGB rgb)
{
    HSV hsv;
    uint8_t rgbMin, rgbMax;

    rgbMin = rgb.r < rgb.g ? (rgb.r < rgb.b ? rgb.r : rgb.b) : (rgb.g < rgb.b ? rgb.g : rgb.b);
    rgbMax = rgb.r > rgb.g ? (rgb.r > rgb.b ? rgb.r : rgb.b) : (rgb.g > rgb.b ? rgb.g : rgb.b);

    hsv.v = rgbMax;
    if (hsv.v == 0)
    {
        hsv.h = 0;
        hsv.s = 0;
        return hsv;
    }

    uint16_t tmp = 255*(rgbMax - rgbMin);
    hsv.s = (uint8_t)(tmp / hsv.v);
    if (hsv.s == 0)
    {
        hsv.h = 0;
        return hsv;
    }

    if (rgbMax == rgb.r)
        hsv.h = 0 + 43 * (rgb.g - rgb.b) / (rgbMax - rgbMin);
    else if (rgbMax == rgb.g)
        hsv.h = 85 + 43 * (rgb.b - rgb.r) / (rgbMax - rgbMin);
    else
        hsv.h = 171 + 43 * (rgb.r - rgb.g) / (rgbMax - rgbMin);

    return hsv;
}

RGB tune_color(uint8_t r, uint8_t g, uint8_t b)
{
    RGB in = {.r=r, .g=g, .b=b};
    HSV tmp = rgb2hsv(in);
    uint16_t s = tmp.s*229;
    tmp.s = (uint8_t)(s/255);
    return hsv_to_rgb(tmp);
}
static void driver_set_color(int index, uint8_t r, uint8_t g, uint8_t b)
{
    is31_led led = g_is31_leds[index];
    switch(led.driver) {
        case 0: {
            //RGB adjust = tune_color(r,g,b);
            //IS31FL3733_set_color(index, adjust.r, adjust.g, adjust.b);
            IS31FL3733_set_color(index, r, g, b);
        }
            break;
        case 1:
        case 2: {
            //RGB adjust = tune_color(r,g,b);
            //IS31FL3236_set_color(index, adjust.r, adjust.g, adjust.b);
            IS31FL3236_set_color(index, r, g, b);
        }
            break;
        case 3:
            scroll_led_set(r, g, b);
            break;
        default:
            break;
    }
}

static void driver_set_color_all(uint8_t r, uint8_t g, uint8_t b)
{
    for( int i = 0; i < DRIVER_LED_TOTAL; i++) {
        driver_set_color(i, r, g, b);
    }
}

extern void scroll_setleds(LED_TYPE *ledarray, uint16_t number_of_leds);
static void driver_flush(void)
{
    IS31FL3733_update_pwm_buffers(DRIVER_0_ADDR, 0);
    IS31FL3236_update_pwm_buffers(DRIVER_1_ADDR, 0);
    IS31FL3236_update_pwm_buffers(DRIVER_2_ADDR, 1);
    if (scroll_led_dirty) {
        scroll_setleds(&scroll_led, 1);
        scroll_led_dirty = false;
    }
}


#define CAPS_LED_INDEX 32

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);

    if (rgb_matrix_is_enabled()) return res;

    if (res) {
        if (led_state.caps_lock) {
            rgb_matrix_set_color(CAPS_LED_INDEX, 0xFF, 0xFF, 0xFF);
            driver_flush();
        } else {
            rgb_matrix_set_color(CAPS_LED_INDEX, 0, 0, 0);
            driver_flush();
        }
    }
    return res;
}