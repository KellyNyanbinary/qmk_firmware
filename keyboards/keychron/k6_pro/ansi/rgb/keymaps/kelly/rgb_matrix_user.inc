// From https://docs.qmk.fm/#/feature_rgb_matrix?id=custom-rgb-matrix-effects 

// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(trans_flag)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static bool trans_flag(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        if (g_led_config.point[i].y < 16) {
            rgb_matrix_set_color(i, 0x5B, 0xCE, 0xFA);
        } else if (g_led_config.point[i].y < 32) {
            rgb_matrix_set_color(i, 0xFF, 0x56, 0x56);
        } else if (g_led_config.point[i].y < 48) {
            rgb_matrix_set_color(i, 0xFF, 0xFF, 0xFF);
        } else if (g_led_config.point[i].y < 64) {
            rgb_matrix_set_color(i, 0xFF, 0x56, 0x56);
        } else {
            rgb_matrix_set_color(i, 0x5B, 0xCE, 0xFA);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS