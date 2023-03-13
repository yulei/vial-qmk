/**
 * s73.c
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

#include "s73.h"

#define REBOOT_MAGIC 0x41544B42
void shutdown_user(void)
{
    // set the magic number for resetting to the bootloader
    *(uint32_t *)(&(RTCD1.rtc->BKP0R)) = REBOOT_MAGIC;
}

void bootloader_jump(void) {
    shutdown_user();
    NVIC_SystemReset();
}
