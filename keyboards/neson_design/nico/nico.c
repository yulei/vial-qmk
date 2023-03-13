/**
 * @file nico.c
 *
    Copyright 2022 astro

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

#include "nico.h"
#ifdef RGBLIGHT_ENABLE
void rgblight_call_driver(LED_TYPE *start_led, uint8_t num_leds)
{
    start_led[2].r = start_led[0].r;
    start_led[2].g = start_led[0].g;
    start_led[2].b = start_led[0].b;

    start_led[3].r = start_led[1].r;
    start_led[3].g = start_led[1].g;
    start_led[3].b = start_led[1].b;

    uint8_t tmp = start_led[4].g;
    start_led[4].g = start_led[4].r;
    start_led[4].r = tmp;
    ws2812_setleds(start_led, RGBLED_NUM);
}
#endif