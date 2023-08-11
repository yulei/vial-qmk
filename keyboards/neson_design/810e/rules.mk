
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes		# Enable keyboard RGB underglow
NO_USB_STARTUP_CHECK = yes
#RGBLIGHT_DRIVER = custom

SRC += is31fl3236.c is31fl3729.c

QUANTUM_LIB_SRC += i2c_master.c
