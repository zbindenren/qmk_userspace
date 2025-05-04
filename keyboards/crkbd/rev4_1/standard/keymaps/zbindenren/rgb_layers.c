#include "rgb_matrix.h"
#include QMK_KEYBOARD_H

// Color definitions (H,S,V)
#define LC_XXX 0, 0, 0
#define LC_WHI 0, 0, 255
#define LC_MAN 200, 255, 255

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = {{LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_XXX}, {LC_XXX}},

    [1] = {{LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_MAN}, {LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_MAN}, {LC_WHI}, {LC_WHI}, {LC_MAN}, {LC_WHI}, {LC_WHI}, {LC_MAN}, {LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_MAN}, {LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_MAN}, {LC_WHI}, {LC_WHI}, {LC_MAN}, {LC_WHI}, {LC_WHI}, {LC_MAN}, {LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_MAN}, {LC_XXX}, {LC_XXX}},

    [2] = {{LC_XXX}, {LC_XXX}, {LC_WHI}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}},

    [3] = {{LC_XXX}, {LC_XXX}, {LC_WHI}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_WHI}, {LC_WHI}, {LC_WHI}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}},

    [4] = {{LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_WHI}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_XXX}},

    [5] = {{LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_XXX}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_WHI}, {LC_XXX}, {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_MAN}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}},
};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        case 5:
            set_layer_color(5);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}
