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

enum custom_keycodes {
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ Keymap ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           CH_Z,           KC_U,           KC_I,           KC_O,           KC_P,           CH_UE,
    CW_TOGG,        MT(MOD_LCTL, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LSFT, KC_D),MT(MOD_LGUI, KC_F),ALL_T(KC_G),                                    ALL_T(KC_H),    MT(MOD_RGUI, KC_J),MT(MOD_LSFT, KC_K),MT(MOD_LALT, KC_L),MT(MOD_RCTL, CH_OE),CH_AE,
    KC_DELETE,      CH_Y,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         CH_MINS,        KC_DELETE,
                                    KC_TRANSPARENT, LT(2,KC_BSPC),  LT(4,KC_ESCAPE),                                LT(5,KC_ENTER), LT(2,KC_SPACE), KC_TRANSPARENT
  ),

    [1] = LAYOUT_split_3x6_3(
    KC_TAB,         KC_Q,           KC_W,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_CTRL,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_RIGHT_CTRL,  KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_GUI,   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                    KC_TRANSPARENT, LT(3,KC_BSPC),  KC_TRANSPARENT,                                 KC_TRANSPARENT, LT(3,KC_SPACE), KC_TRANSPARENT
  ),

    [2] = LAYOUT_split_3x6_3(
    KC_NO,          ST_MACRO_0,     RALT(KC_G),     CH_PERC,        CH_LESS,        CH_MORE,                                        CH_DLR,         RALT(KC_8),     RALT(KC_9),     CH_PAST,        CH_AMPR,        CH_SCLN,
    KC_NO,          ST_MACRO_1,     CH_HASH,        CH_QST,         CH_DQOT,        CH_QUOT,                                        CH_SLSH,        CH_LPRN,        CH_RPRN,        CH_EQL,         CH_EXLM,        CH_PLUS,
    KC_NO,          CH_DIER,        KC_NO,          RALT(LSFT(KC_7)),ST_MACRO_2,     CH_GRV,                                         CH_PIPE,        RALT(KC_5),     RALT(KC_6),     CH_COLN,        CH_MINS,        KC_NO,
                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

    [3] = LAYOUT_split_3x6_3(
    KC_NO,          CH_TILD,        CH_AT,          CH_PERC,        CH_LESS,        CH_MORE,                                        CH_DLR,         CH_LCBR,        CH_RCBR,        CH_PAST,        CH_AMPR,        CH_SCLN,
    KC_NO,          CH_CARR,        CH_HASH,        CH_QST,         CH_DQOT,        CH_QUOT,                                        CH_SLSH,        CH_LPRN,        CH_RPRN,        CH_EQL,         CH_EXLM,        CH_PLUS,
    KC_NO,          CH_DIER,        KC_NO,          CH_BSLS,        CH_GRV,         KC_NO,                                          CH_PIPE,        CH_LBRC,        CH_RBRC,        CH_COLN,        CH_MINS,        KC_NO,
                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
    [4] = LAYOUT_split_3x6_3(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_LLCK,
    KC_NO,          KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_HYPR,                                        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,                                          KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_NO,          KC_NO,
                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
    [5] = LAYOUT_split_3x6_3(
    QK_LLCK,        KC_KP_PLUS,     KC_7,           KC_8,           KC_9,           KC_KP_ASTERISK,                                 KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_BSPC,        KC_KP_EQUAL,    KC_4,           KC_5,           KC_6,           KC_SPACE,                                       KC_HYPR,        KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_LEFT_ALT,    KC_LEFT_GUI,    KC_NO,
    KC_NO,          KC_KP_MINUS,    KC_1,           KC_2,           KC_3,           KC_KP_SLASH,                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
                                    KC_TRANSPARENT, KC_0,           TD(DANCE_0),                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
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

 // ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ Combos ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
const uint16_t PROGMEM combo0[] = { KC_P, CH_UE, KC_O, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_TAB, KC_Q, KC_W, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TO(1)),
    COMBO(combo1, TO(0)),
};

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_RALT(SS_TAP(X_N))SS_DELAY(50)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL)SS_DELAY(50)  SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_EQUAL))SS_DELAY(50)  SS_TAP(X_SPACE));
    }
    break;

    case RGB_MODE_PLAIN:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case CH_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
