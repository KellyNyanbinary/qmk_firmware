// From https://docs.qmk.fm/#/feature_rgb_matrix?id=custom-rgb-matrix-effects 
// With help from drashna#0343 and filterpaper#2878 on the QMK Discord server.

// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(trans_flag_effect)
RGB_MATRIX_EFFECT(orange_effect)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// Trans flag colors. 
HSV lightBlue = {.h = 140, .s = 165, .v = 255 };
HSV pink = {.h = 0, .s = 200, .v = 255 };
HSV white = {.h = 0, .s = 0, .v = 255 };

HSV black = {.h = 0, .s = 0, .v = 0 };

// Trans flag effect.
static bool trans_flag_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB rgb; // initialize rgb 
        
        if ((g_led_config.point[i].y >= 8 && g_led_config.point[i].y < 16) || g_led_config.point[i].y >= 64) {
            lightBlue.v = rgb_matrix_get_val();
            rgb = rgb_matrix_hsv_to_rgb(lightBlue);
        } else if ((g_led_config.point[i].y >= 16 && g_led_config.point[i].y < 32) || (g_led_config.point[i].y >= 48 && g_led_config.point[i].y < 64)) {
            pink.v = rgb_matrix_get_val();
            rgb = rgb_matrix_hsv_to_rgb(pink);
        } else if (g_led_config.point[i].y >= 32 && g_led_config.point[i].y < 48) {
            white.v = rgb_matrix_get_val();
            rgb = rgb_matrix_hsv_to_rgb(white);
        } else {
        	rgb = rgb_matrix_hsv_to_rgb(black);
        }

        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

// Orange colors.
HSV orange = {.h = 5, .s = 255, .v = 255 }; 

// Orange effect.
static bool orange_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB rgb; // initialize rgb 

        orange.v = rgb_matrix_get_val();
        rgb = rgb_matrix_hsv_to_rgb(orange);

        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
