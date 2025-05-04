#ifndef RGB_LAYERS_H
#define RGB_LAYERS_H

#include QMK_KEYBOARD_H // Includes necessary QMK headers like rgb_matrix.h, datastructures, etc.

// Declare the ledmap array defined in rgb_layers.c
// RGB_MATRIX_LED_COUNT should be defined via rgb_matrix.h included by QMK_KEYBOARD_H
extern const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3];

// Declare functions defined in rgb_layers.c that might be needed elsewhere or are QMK callbacks
void keyboard_post_init_user(void);
bool rgb_matrix_indicators_user(void);
void set_layer_color(int layer); // Declare even if currently internal, for potential future use or clarity

#endif // RGB_LAYERS_H
