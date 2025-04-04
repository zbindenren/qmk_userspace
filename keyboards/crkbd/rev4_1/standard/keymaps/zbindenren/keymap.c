/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include "i18n.h"
#include "rgb_matrix.h"

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ Keymap ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           CH_Z,           KC_U,           KC_I,           KC_O,           KC_P,           CH_UE,
    CW_TOGG,        MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LSFT, KC_D),MT(MOD_LCTL, KC_F),ALL_T(KC_G),                                    ALL_T(KC_H),    MT(MOD_LCTL, KC_J),MT(MOD_LSFT, KC_K),MT(MOD_LALT, KC_L),MT(MOD_LGUI, CH_OE),CH_AE,
    KC_DELETE,      CH_Y,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         CH_MINS,        KC_DELETE,
                                    KC_TRANSPARENT, LT(3,KC_BSPC),  LT(1,KC_ESCAPE),                                LT(4,KC_ENTER), LT(3,KC_SPACE), KC_TRANSPARENT
  ),

    [1] = LAYOUT_split_3x6_3(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_LLCK,
    KC_NO,          KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_NO,                                          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,                                          KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_INSERT,      KC_DELETE,
                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_ENTER,       KC_SPACE,       KC_TRANSPARENT
  ),

    [2] = LAYOUT_split_3x6_3(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_KP_PLUS,     KC_7,           KC_8,           KC_9,           KC_KP_ASTERISK, QK_LLCK,
    KC_NO,          KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_HYPR,                                        KC_KP_EQUAL,    KC_4,           KC_5,           KC_6,           KC_SPACE,       KC_BSPC,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,                                          KC_KP_MINUS,    KC_1,           KC_2,           KC_3,           KC_KP_SLASH,    KC_DELETE,
                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 TD(DANCE_0),    KC_0,           KC_TRANSPARENT
  ),

    [3] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, CH_TILD,        CH_AT,          CH_PERC,        CH_LESS,        CH_MORE,                                        CH_DLR,         CH_LCBR,        CH_RCBR,        CH_PAST,        CH_AMPR,        CH_SCLN,
    KC_TRANSPARENT, CH_CARR,        CH_HASH,        CH_QST,         CH_DQOT,        CH_GRV,                                         CH_SLSH,        CH_LPRN,        CH_RPRN,        CH_EQL,         CH_EXLM,        CH_PLUS,
    KC_TRANSPARENT, CH_DIER,        KC_NO,          CH_BSLS,        CH_QUOT,        KC_NO,                                          CH_PIPE,        CH_LBRC,        CH_RBRC,        CH_COLN,        CH_MINS,        KC_NO,
                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
    [4] = LAYOUT_split_3x6_3(
    QK_LLCK,        KC_KP_PLUS,     KC_7,           KC_8,           KC_9,           KC_KP_ASTERISK,                                 KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_BSPC,        KC_KP_EQUAL,    KC_4,           KC_5,           KC_6,           KC_SPACE,                                       KC_HYPR,        KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_LEFT_ALT,    KC_LEFT_GUI,    KC_NO,
    KC_DELETE,      KC_KP_MINUS,    KC_1,           KC_2,           KC_3,           KC_KP_SLASH,                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                    KC_TRANSPARENT, KC_0,           TD(DANCE_1),                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ Tap Dance ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LCTL, KC_F):
            return TAPPING_TERM -65;
        case MT(MOD_LCTL, KC_J):
            return TAPPING_TERM -65;
        case LT(3,KC_SPACE):
            return TAPPING_TERM -50;
        default:
            return TAPPING_TERM;
    }
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ Chordal Hold ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#ifdef CHORDAL_HOLD
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
        case KC_SPACE:
            return false;
    }
    return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ Layer Colors ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


// Color definitions (H,S,V)
#define LC_XXX       0,   0,   0
#define LC_WHI       0,   0, 255
#define LC_RED       0, 255, 255
#define LC_BLU     170, 255, 255
#define LC_CYA     200, 255, 255
#define LC_GRE      74, 255, 255
#define LC_YEL      41, 255, 255

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_WHI}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_WHI}, {LC_CYA}, {LC_CYA}, {LC_WHI}, {LC_CYA}, {LC_CYA}, {LC_WHI}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_WHI}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_WHI}, {LC_CYA}, {LC_CYA}, {LC_WHI}, {LC_CYA}, {LC_CYA}, {LC_WHI}, {LC_CYA}, {LC_XXX}, {LC_CYA}, {LC_WHI}, {LC_XXX}, {LC_XXX} },

    [1] = { {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_WHI}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX} },

    [2] = { {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX} },

    [3] = { {LC_XXX}, {LC_XXX}, {LC_GRE}, {LC_BLU}, {LC_BLU}, {LC_GRE}, {LC_GRE}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_YEL}, {LC_YEL}, {LC_YEL}, {LC_BLU}, {LC_BLU}, {LC_BLU}, {LC_XXX}, {LC_XXX}, {LC_BLU}, {LC_BLU}, {LC_BLU}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX} },

    [4] = { {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_XXX}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_WHI}, {LC_XXX}, {LC_WHI}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_CYA}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX}, {LC_XXX} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  switch (get_highest_layer(layer_state | default_layer_state)) {
    case 0: set_layer_color(0); break;
    case 1: set_layer_color(1); break;
    case 2: set_layer_color(2); break;
    case 3: set_layer_color(3); break;
    case 4: set_layer_color(4); break;
    default:
      if (rgb_matrix_get_flags() == LED_FLAG_NONE)
        rgb_matrix_set_color_all(0, 0, 0);
      break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_MODE_PLAIN:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
