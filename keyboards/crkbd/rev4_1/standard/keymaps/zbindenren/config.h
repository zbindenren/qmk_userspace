#pragma once

#define SPLIT_LAYER_STATE_ENABLE
#define COMBO_COUNT 2

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ General Tapping ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#define CHORDAL_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD

// ━━━━━━━━━━━━━━━━━━━━━━ Make Keyboard Immediately Ready ━━━━━━━━━━━━━━━━━━━━━━
#undef USB_SUSPEND_WAKEUP_DELAY
#define USB_SUSPEND_WAKEUP_DELAY 0

// ━━━━━━━━━━━━━━━━━━━ Boot Magic Upper Left On Both Halves ━━━━━━━━━━━━━━━━━━━━
#define BOOTMAGIC_ROW 0
#undef  BOOTMAGIC_COLUMN
#define BOOTMAGIC_COLUMN 0
#define BOOTMAGIC_ROW_RIGHT 4
#undef  BOOTMAGIC_COLUMN_RIGHT
#define BOOTMAGIC_COLUMN_RIGHT 5

// ━━━━━━━━━━━━━━━━━━━━━━━ Disable LEDS After 2 Minutes ━━━━━━━━━━━━━━━━━━━━━━━━
#define RGB_MATRIX_TIMEOUT 120000
#define RGB_MATRIX_STARTUP_SPD 60

// ━━━━━━━━━━━━━━━━━━━━━━ Disable All RGB Matrix Effects  ━━━━━━━━━━━━━━━━━━━━━━
#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_SOLID_COLOR
