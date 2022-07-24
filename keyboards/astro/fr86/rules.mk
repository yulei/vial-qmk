
# MCU name
MCU = STM32F401

# Bootloader selection
#BOOTLOADER = stm32-dfu
BOOTLOADER = tinyuf2

MCU_LDSCRIPT = STM32F401xC

CUSTOM_MATRIX = lite
SRC += analog.c ec_matrix.c

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
#KEYBOARD_SHARED_EP = yes