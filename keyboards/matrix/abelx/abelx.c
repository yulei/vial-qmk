/**
 * abelx.c
 */

#include "abelx.h"
#include "tca6424.h"
#include "aw9523b.h"
#include "is31fl3236.h"
#include "rgb_effects.h"

#define FOR_ME  1
void set_pin(uint16_t pin)
{
    uint8_t data = tca6424_read_port(GET_PORT(pin));
    data |= ( 1 << GET_PIN(pin));
    tca6424_write_port(GET_PORT(pin), data);
}

void clear_pin(uint16_t pin)
{
    uint8_t data = tca6424_read_port(GET_PORT(pin));
    data &= ~( 1 << GET_PIN(pin));
    tca6424_write_port(GET_PORT(pin), data);
}

uint8_t read_pin(uint16_t pin)
{
    uint8_t data = tca6424_read_port(GET_PORT(pin));
    return (data & (1<<GET_PIN(pin))) ? 1 : 0;
}


#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#include "i2c_master.h"

extern rgblight_config_t rgblight_config;

LED_TYPE top_leds[RGBLED_NUM];
#if FOR_ME
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, OUT_36, OUT_35, OUT_34},
    {0, OUT_33, OUT_32, OUT_31},
    {0, OUT_30, OUT_29, OUT_28},
    {0, OUT_27, OUT_26, OUT_25},
    {0, OUT_24, OUT_23, OUT_22},
    {0, OUT_21, OUT_20, OUT_19},
    {0, OUT_18, OUT_17, OUT_16},
};
#else
const aw9523b_led g_aw9523b_leds[AW9523B_RGB_NUM] = {
    {AW9523B_P12_PWM, AW9523B_P11_PWM, AW9523B_P10_PWM},
    {AW9523B_P01_PWM, AW9523B_P00_PWM, AW9523B_P13_PWM},
    {AW9523B_P04_PWM, AW9523B_P03_PWM, AW9523B_P02_PWM},
    {AW9523B_P07_PWM, AW9523B_P06_PWM, AW9523B_P05_PWM},
};
#endif
void rgblight_call_driver(LED_TYPE *start_led, uint8_t num_leds)
{
    for (int i = 0; i < num_leds; i++) {
        #if FOR_ME
        IS31FL3236_set_color(i, start_led[i].r, start_led[i].g, start_led[i].b);
        #else
        aw9523b_set_color(i, start_led[i].r, start_led[i].g, start_led[i].b);
        #endif
    }

    //ws2812_setleds(top_leds, RGBLED_NUM);
    ws2812_setleds(start_led, num_leds);
}

void effects_set_color(uint8_t index, uint8_t hue, uint8_t sat, uint8_t val)
{
    HSV hsv = {hue, sat, val};
    RGB rgb = hsv_to_rgb(hsv);
    top_leds[index].r = rgb.r;
    top_leds[index].g = rgb.g;
    top_leds[index].b = rgb.b;
}

void effects_set_color_all(uint8_t hue, uint8_t sat, uint8_t val)
{
    HSV hsv = {hue, sat, val};
    RGB rgb = hsv_to_rgb(hsv);
    for (int i = 0; i < RGBLED_NUM; i++) {
        top_leds[i].r = rgb.r;
        top_leds[i].g = rgb.g;
        top_leds[i].b = rgb.b;
    }
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record)
{
    if (record->event.pressed) {
        switch(keycode) {
            case KC_F13:
                rgb_effects_toggle();
                return false;
            case KC_F14:
                rgb_effects_inc_mode();
                return false;
            case KC_F15:
                rgb_effects_inc_hue();
                return false;
            case KC_F16:
                rgb_effects_inc_sat();
                return false;
            case KC_F17:
                rgb_effects_inc_val();
                return false;
            case KC_F18:
                rgb_effects_dec_hue();
                return false;
            case KC_F19:
                rgb_effects_dec_sat();
                return false;
            case KC_F20:
                rgb_effects_dec_val();
                return false;
            case KC_F21:
                rgb_effects_inc_speed();
                return false;
            case KC_F22:
                rgb_effects_dec_speed();
                return false;
            default:
                break;
        }
    }
    return process_record_user(keycode, record);
}

#endif

static uint16_t caps_lock_pin = DEF_PIN(TCA6424_PORT2, 3);
static uint16_t scroll_lock_pin = DEF_PIN(TCA6424_PORT0, 0);

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        led_state.caps_lock ? set_pin(caps_lock_pin) : clear_pin(caps_lock_pin);
        led_state.scroll_lock ? set_pin(scroll_lock_pin) : clear_pin(scroll_lock_pin);
    }
    return res;
}

#define REBOOT_MAGIC 0x41544B42
void shutdown_user(void)
{
    // set the magic number for resetting to the bootloader
    *(uint32_t *)(&(RTCD1.rtc->BKP0R)) = REBOOT_MAGIC;
}

__attribute__((weak))
void matrix_init_user(void) { }

void matrix_init_kb(void) {
#ifdef RGBLIGHT_ENABLE
    #if FOR_ME
    IS31FL3236_init(IS31FL3236_ADDR);
    #else
    aw9523b_init(AW9523B_ADDR);
    #endif
    rgb_effects_init();
#endif
    matrix_init_user();
}


__attribute__((weak))
void matrix_scan_user(void) { }

void matrix_scan_kb(void) {
#ifdef RGBLIGHT_ENABLE
    #if FOR_ME
    IS31FL3236_update_pwm_buffers(IS31FL3236_ADDR);
    #else
    aw9523b_update_pwm_buffers(AW9523B_ADDR);
    #endif
    rgb_effects_task();
#endif
    matrix_scan_user();
}
