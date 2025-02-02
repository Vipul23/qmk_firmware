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
// #include "keychron_common.h"
// clang-format off

enum layers{
    WIN_BASE,
    WIN_FN,
    WIN_PFN,
    OSL_COLOR
};

enum extra_keycodes{
	RM_TOGG_NE = SAFE_RANGE,
    RM_NEXT_NE, 
    RM_PREV_NE, 
    RM_VALU_NE, 
    RM_VALD_NE, 
    RM_HUEU_NE, 
    RM_HUED_NE, 
    RM_SATU_NE, 
    RM_SATD_NE, 
    RM_SPDU_NE, 
    RM_SPDD_NE,
    MIC_VOLD, 
    MIC_VOLU,
    MIC_MUTE,
    OS_SLEP,
    RED0,
	RED5,
	RED10,
	RED15,
	ORNG21,
	ORNG26,
	ORNG31,
	ORNG36,
	YLLW43,
	YLLW53,
	YLLW63,
	YLLW73,
	GRN85,
	GRN95,
	GRN105,
	GRN115,
	CYAN127,
	CYAN132,
	CYAN137,
	CYAN142,
	AZRE148,
	AZRE153,
	AZRE158,
	AZRE163,
	BLUE169,
	BLUE172,
	BLUE175,
	BLUE178,
	VILT180,
	VILT185,
	VILT190,
	VILT195,
	MGTA201,
	MGTA206,
	MGTA211,
	MGTA217,
	ROSE222,
	ROSE230,
	ROSE238,
	ROSE245
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_BRID,    KC_BRIU,    KC_TASK,    KC_FLXP,    RM_VALD_NE,    RM_VALU_NE,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,   KC_VOLD,     KC_VOLU,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_82(
        _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,    KC_F12,  _______,            RM_TOGG_NE,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RM_TOGG_NE,  RM_NEXT_NE,  RM_VALU_NE,  RM_HUEU_NE,  RM_SATU_NE,  RM_SPDU_NE,  _______,  _______,  _______,  _______,  OSL(OSL_COLOR),  _______,    _______,  _______,            _______,
        _______,  RM_PREV_NE,  RM_VALD_NE,  RM_HUED_NE,  RM_SATD_NE,  RM_SPDD_NE,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            KC_END,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                MO(WIN_PFN),  _______,    _______,  _______,  _______,  _______),
    
    [WIN_PFN] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            RM_TOGG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),

    [OSL_COLOR] = LAYOUT_ansi_82(
        TG(WIN_BASE),  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,   RED0,     ORNG21,   YLLW43,   GRN85,    CYAN127,  AZRE148,  BLUE169,  VILT180,  MGTA201,  ROSE222,  _______,    _______,  _______,            _______,
        _______,   RED5,     ORNG26,   YLLW53,   GRN95,    CYAN132,  AZRE153,  BLUE172,  VILT185,  MGTA206,  ROSE230,  _______,    _______,  _______,            _______,
        _______,   RED10,    ORNG31,   YLLW63,   GRN105,   CYAN137,  AZRE158,  BLUE175,  VILT190,  MGTA211,  ROSE238,  _______,              _______,            _______,
        _______,             RED15,    ORNG36,   YLLW73,   GRN115,   CYAN142,  AZRE163,  BLUE178,  VILT195,  MGTA217,  ROSE245,              _______,  _______,
        _______,   _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),   
};


bool rgb_matrix_indicators_user(void) {

    uint8_t layer = biton32(layer_state);
	
	switch (layer) {
        case 1:
            // 
            if (get_highest_layer(layer_state) > 0) {
                uint8_t layer = get_highest_layer(layer_state);
                int led_min = 0;
                int led_max = 1717;

                for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                        uint8_t index = g_led_config.matrix_co[row][col];

                        if (index >= led_min && index < led_max && index != NO_LED &&
                        keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                            rgb_matrix_set_color(index, 77, 0, 255);
                        }
                    }
                }
            }
            break;

        case 2:

            if (get_highest_layer(layer_state) > 0) {
                uint8_t layer = get_highest_layer(layer_state);
                int led_min = 0;
                int led_max = 1717;

                for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                        uint8_t index = g_led_config.matrix_co[row][col];

                        if (index >= led_min && index < led_max && index != NO_LED &&
                        keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                            rgb_matrix_set_color(index, 215, 0, 255);
                        }
                    }
                }
            }
            break;

        case 4:
            rgb_matrix_set_color_all(0, 0, 0);
            

            if (get_highest_layer(layer_state) > 0) {
                uint8_t layer = get_highest_layer(layer_state);
                int led_min = 0;
                int led_max = 1717;

                for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                        uint8_t index = g_led_config.matrix_co[row][col];

                        if (index >= led_min && index < led_max && index != NO_LED &&
                        keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                            rgb_matrix_set_color(index, 0, 255, 0);
                        }
                    }
                }
            }

            rgb_matrix_set_color(0, 255, 0, 0);
            break;
        
        case 3:
            rgb_matrix_set_color_all(0, 0, 0); // rest of keys blank/black
            rgb_matrix_set_color(16, 255, 0, 0); // RED0 true red, 1
            rgb_matrix_set_color(31, 255, 68, 0); // RED5, Q
            rgb_matrix_set_color(46, 255, 111, 0); // RED10, A
            rgb_matrix_set_color(60, 255, 179, 0); // RED15 red orange, Z
            rgb_matrix_set_color(17, 204, 204, 0); // ORNG21 true orange, 2
            rgb_matrix_set_color(32, 255, 205, 0); // ORNG26, W
            rgb_matrix_set_color(47, 255, 217, 0); // ORNG31, S
            rgb_matrix_set_color(61, 255, 230, 0); // ORNG36, X
            rgb_matrix_set_color(18, 255, 255, 0); // YLLW43 true yellow, 3
            rgb_matrix_set_color(33, 196, 255, 0); // YLLW53, E
            rgb_matrix_set_color(48, 154, 255, 0); // YLLW63, D
            rgb_matrix_set_color(62, 111, 255, 0); // YLLW73, C
            rgb_matrix_set_color(19, 0, 255, 0); // GRN85 true green, 4
            rgb_matrix_set_color(34, 0, 255, 50); // GRN95, R
            rgb_matrix_set_color(49, 0, 255, 75); // GRN105, F
            rgb_matrix_set_color(63, 0, 255, 120); // GRN115, V
            rgb_matrix_set_color(20, 0, 255, 255); // CYAN127 true cyan, 5
            rgb_matrix_set_color(35, 0, 213, 255); // CYAN132, T
            rgb_matrix_set_color(50, 0, 196, 255); // CYAN137, G
            rgb_matrix_set_color(64, 0, 154, 255); // CYAN142, B
            rgb_matrix_set_color(21, 0, 128, 255); // AZRE148 true azure, 6
            rgb_matrix_set_color(36, 0, 102, 255); // AZRE153, Y
            rgb_matrix_set_color(51, 0, 77, 255); // AZRE158, H
            rgb_matrix_set_color(65, 0, 60, 255); // AZRE163, N
            rgb_matrix_set_color(22, 0, 0, 255); // BLUE169 true blue, 7
            rgb_matrix_set_color(37, 43, 0, 255); // BLUE172, U
            rgb_matrix_set_color(52, 60, 0, 255); // BLUE175, J
            rgb_matrix_set_color(66, 77, 0, 255); // BLUE178, M
            rgb_matrix_set_color(23, 127, 0, 255); // VILT180 true violet, 8
            rgb_matrix_set_color(38, 171, 0, 255); // VILT185, I
            rgb_matrix_set_color(53, 200, 0, 255); // VILT190, K
            rgb_matrix_set_color(67, 215, 0, 255); // VILT195, <
            rgb_matrix_set_color(24, 255, 0, 255); // MGTA201 true magenta, 9
            rgb_matrix_set_color(39, 255, 0, 240); // MGTA206, O
            rgb_matrix_set_color(54, 255, 0, 220); // MGTA211, L
            rgb_matrix_set_color(68, 255, 0, 200); // MGTA217, >
            rgb_matrix_set_color(25, 255, 0, 127); // ROSE222 true rose, 0
            rgb_matrix_set_color(40, 255, 0, 111); // ROSE230, P
            rgb_matrix_set_color(55, 255, 0, 70); // ROSE238, :
            rgb_matrix_set_color(69, 255, 0, 26); // ROSE245, ?
            rgb_matrix_set_color(0, 255, 0, 0); // ESC red

            break;
    }
    return true;
}

// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// Replace with function home
// const key_override_t home_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_HOME, KC_END);
const key_override_t alt_f4_key_override = ko_make_basic(MOD_MASK_ALT, KC_FLXP, LALT( KC_F4 ));
// const key_override_t volume_down_encoder_override = ko_make_basic(MOD_MASK_ALT, KC_VOLD_EN, LALT( KC_F4 ));
// const key_override_t volume_up_encoder_override = ko_make_basic(MOD_MASK_ALT, KC_VOLU_EN, LALT( KC_F4 ));
// const key_override_t volume_mute_encoder_override = ko_make_basic(MOD_MASK_ALT, KC_MUTE_EN, LALT( KC_F4 ));

// This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
//     // &delete_key_override,
//     // &home_key_override,
//     &alt_f4_key_override,
//     NULL // Null terminate the array of overrides!
// };

const key_override_t *key_overrides[] = {
	&alt_f4_key_override
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = { ENCODER_CCW_CW(RM_VALD_NE, RM_VALU_NE)},
    [WIN_PFN] = { ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    [OSL_COLOR]   = { ENCODER_CCW_CW(RM_VALD_NE, RM_VALU_NE)}
};
#endif // ENCODER_MAP_ENABLE
