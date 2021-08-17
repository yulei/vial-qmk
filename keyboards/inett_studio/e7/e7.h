/**
  * @file e7.h
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
#pragma once

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define LAYOUT_default( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K00A, K00B, K00C, K00D, K00E,     K00F, K010, K011, \
    K100,   K101,  K102, K103, K104, K105, K106, K107, K108, K109, K10A, K10B, K10C,    K10D,     K10E, K10F, K110, \
    K200,       K201, K202, K203, K204, K205, K206, K207, K208, K209, K20A, K20B,       K20D,\
    K300,       K302, K303, K304, K305, K306, K307, K308, K309, K30A, K30B,       K30C, K30D,           K30E, \
    K400,       K401, K402,                   K406,                         K409, K40A, K40B,     K40C, K40D, K40E \
) \
{ \
    { K000,  K001, K002,  K003,  K004, K005,  K006,  K007,  K008,  K009, K00A, K00B,  K00C, K00D, K00F, K010}, \
    { K100,  K101, K102,  K103,  K104, K105,  K106,  K107,  K108,  K109, K10A, K10B,  K10C, K10D, K10E, K011}, \
    { K200,  K201, K202,  K203,  K204, K205,  K206,  K207,  K208,  K209, K20A, K20B, KC_NO, K20D, K10F, K110}, \
    { K300, KC_NO, K302,  K303,  K304, K305,  K306,  K307,  K308,  K309, K30A, K30B,  K30C, K30D, K30E, K40C}, \
    { K400,  K401, K402, KC_NO, KC_NO, K406, KC_NO, KC_NO, KC_NO, KC_NO, K409, K40A,  K40B, K00E, K40D, K40E}, \
}
