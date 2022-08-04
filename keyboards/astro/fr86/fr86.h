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

#pragma once

#include "quantum.h"

#define LAYOUT_tkl_ansi_tsangan( \
    K601,       K602, K603, K604, K605, K606, K607, K608, K609, K610, K611, K612, K613,          K614, K615, K616, \
  \
    K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114,          K115, K116, K117, \
    K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214,          K215, K216, K217, \
    K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312,       K314, \
    K414,       K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413,                K415, \
    K501, K502, K503,                   K507,                         K511, K512, K513,          K514, K515, K516 \
) { \
    {K601,KC_NO, K602, K603, K604, K605, K606, K607, K608, K609,KC_NO< K610, K612, K613, K614, K616}, \
    {K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K611, K113, K114, K615, K117}, \
    {K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K112, K213, K115, K116, K217}, \
    {K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K212,KC_NO, K214,KC_NO, K415}, \
    {KC_NO,K414, K403, K404, K405, K407, K408, K409, K410, K411, K412, K312, K413, K314, K215, K516}, \
    {K501, K502,KC_NO, K503, K406,KC_NO, K507,KC_NO,KC_NO,KC_NO, K511, K512, K513, K514, K216, K515}  \
}

#define LAYOUT_all( \
    K601,       K602, K603, K604, K605, K606, K607, K608, K609, K610, K611, K612, K613,          K614, K615, K616, \
  \
    K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114,          K115, K116, K117, \
    K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214,          K215, K216, K217, \
    K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, \
    K401, K414, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K413,                K415, \
    K501, K502, K503,             K506, K507,                   K510, K511, K512, K513,          K514, K515, K516 \
) { \
    {K601,KC_NO, K602, K603, K604, K605, K606, K607, K608, K609,KC_NO, K610, K612, K613, K614, K616}, \
    {K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K611, K113, K114, K615, K117}, \
    {K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K112, K213, K115, K116, K217}, \
    {K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K212, K313, K214, K315, K415}, \
    {K401, K414, K403, K404, K405, K407, K408, K409, K410, K411, K412, K312, K413, K314, K215, K516}, \
    {K501, K502, K402, K503, K406, K506, K507,KC_NO, K510,KC_NO, K511, K512, K513, K514, K216, K515}  \
}
