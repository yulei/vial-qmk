/**
 * abelx.h
<<<<<<< HEAD
=======
 * 
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

#include "quantum.h"

<<<<<<< HEAD
#define DEF_PIN(port, pin) (((port) << 8) | pin)
#define GET_PORT(pp) (((pp) >> 8) & 0xFF)
#define GET_PIN(pp) ((pp) & 0xFF)

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

#define MATRIX_ROW_PINS { \
    DEF_PIN(TCA6424_PORT2, 7), \
    DEF_PIN(TCA6424_PORT2, 6), \
    DEF_PIN(TCA6424_PORT2, 0), \
    DEF_PIN(TCA6424_PORT2, 2), \
    DEF_PIN(TCA6424_PORT2, 4), \
    DEF_PIN(TCA6424_PORT2, 5) }

#define MATRIX_COL_PINS { \
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
=======
>>>>>>> upstream/vial

#define LAYOUT_tkl_iso( \
    K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,          K013, K014, K015, \
  \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113,          K114, K115, K116, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212,                K214, K215, K216, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, \
	K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,                      K413, \
	K500, K501, K502,                   K506,             K509, K510, K511, K512,                K513, K514, K515\
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013, K014, K015}, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113, K114, K115}, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212, KC_NO, K214, K116}, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  K312,  K313, K215, K216}, \
	{ K400,  K401,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  K412, KC_NO, K413,KC_NO}, \
	{ K500,  K501,  K502, KC_NO, KC_NO, KC_NO,  K506,  K509,  K510,  K511,  K512,  K513,  K514, KC_NO, K515,KC_NO}, \
}

#define LAYOUT_tkl_ansi( \
    K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,          K013, K014, K015, \
  \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113,          K114, K115, K116, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,          K214, K215, K216, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313, \
	K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411,       K412,                K413, \
	K500, K501, K502,                   K506,             K509, K510, K511, K512,                K513, K514, K515\
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013, K014, K015}, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113, K114, K115}, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213, K214, K116}, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311, KC_NO,  K313, K215, K216}, \
	{ K400, KC_NO,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  K412, KC_NO, K413,KC_NO}, \
	{ K500,  K501,  K502, KC_NO, KC_NO, KC_NO,  K506,  K509,  K510,  K511,  K512,  K513,  K514, KC_NO, K515,KC_NO}, \
}

<<<<<<< HEAD
#define LAYOUT_all( \
    K000,       K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,          K013, K014, K015, \
  \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113,          K114, K115, K116, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,          K214, K215, K216, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, \
	K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411,       K412,                K413, \
	K500, K501, K502,                   K506,             K509, K510, K511, K512,                K513, K514, K515\
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013, K014, K015}, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113, K114, K115}, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213, K214, K116}, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  K312,  K313, K215, K216}, \
	{ K400,  K401,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  K412, KC_NO, K413,KC_NO}, \
	{ K500,  K501,  K502, KC_NO, KC_NO, KC_NO,  K506,  K509,  K510,  K511,  K512,  K513,  K514, KC_NO, K515,KC_NO}, \
}

=======
>>>>>>> upstream/vial
void set_pin(uint16_t pin);
void clear_pin(uint16_t pin);
uint8_t read_pin(uint16_t pin);
