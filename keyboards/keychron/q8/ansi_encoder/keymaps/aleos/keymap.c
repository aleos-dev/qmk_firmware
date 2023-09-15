/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// clang-format off

enum layers{
    MAC_BASE,
    WIN_BASE,
    _FN_M,
    _FN1,
    _FN2
};
/*
-----------------------------------------
CHANGES MADE:
-----------------------------------------

1. QK_CAPS_WORD_TOGGLE Activation:
- Keycode: CW_TOGG
- To enable: Add "CAPS_WORD_ENABLE = yes" to rules.mk

2. Shift Key Modifications:
- Left Shift: Replaced with SC_LSPO (Left Shift, Parenthesis Open)
- Right Shift: Replaced with SC_RSPC (Right Shift, Parenthesis Close)
- Note: Add "COMMAND_ENABLE = no" to rules.mk

3. Custom Key:
- CAPS_V2: Alias for RCTL_T(KC_ESC)

4. GRAVE_ESCAE

5. Q + W COMBO
- Alias for ALT + F4

-----------------------------------------
*/


enum custom_keycodes {
    ALT_F4 = SAFE_RANGE,

    // ... more custom keycodes
};

#define COMBO_COUNT 1

// Define the qw_combo
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};

// Define what our combo does
combo_t key_combos[COMBO_COUNT] = {
    [0] = COMBO(qw_combo, ALT_F4)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_F4:
            if (record->event.pressed) {
                // when keycode ALT_F4 is pressed
                SEND_STRING(SS_LALT(SS_TAP(X_F4)));
            }
            break;
    }
    return true;
}

#define CAPS_V2 RCTL_T(KC_ESC)


#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_69(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPT,  KC_LCMD,           KC_SPC,           MO(_FN_M), MO(_FN2),         KC_SPC,            KC_RCMD,            KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_69(
        QK_GESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        CAPS_V2, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,                        KC_HOME,
        SC_LSPO,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  SC_RSPC, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,           KC_SPC,           MO(_FN1), MO(_FN2),         KC_SPC,            KC_RALT,            KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN_M] = LAYOUT_ansi_69(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_NO,   KC_NO,   RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD,           KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_FN1] = LAYOUT_ansi_69(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        CW_TOGG, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD,           KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [_FN2] = LAYOUT_ansi_69(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______,  _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD,           KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN_M]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN1]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN2]   = {ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE

