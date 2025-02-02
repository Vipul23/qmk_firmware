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

#include "quantum.h"

#ifdef DIP_SWITCH_ENABLE

bool dip_switch_update_kb(uint8_t index, bool active) {
    if (!dip_switch_update_user(index, active)) {
        return false;
    }
    if (index == 0) {
        default_layer_set(1UL << (active ? 2 : 0));
    }
    return true;
}

#endif

enum rgb_keycodes { RM_TOGG_NE = SAFE_RANGE, RM_NEXT_NE, RM_PREV_NE, RM_VALU_NE, RM_VALD_NE, RM_HUEU_NE, RM_HUED_NE, RM_SATU_NE, 
    RM_SATD_NE, RM_SPDU_NE, RM_SPDD_NE, MIC_VOLD, MIC_VOLU, MIC_MUTE, OS_SLEP, RED0, RED5, RED10, RED15, ORNG21, ORNG26, 
    ORNG31, ORNG36, YLLW43, YLLW53, YLLW63, YLLW73, GRN85, GRN95, GRN105, GRN115, CYAN127, CYAN132, CYAN137, CYAN142, 
    AZRE148, AZRE153, AZRE158, AZRE163, BLUE169, BLUE172, BLUE175, BLUE178, VILT180, VILT185, VILT190, VILT195, MGTA201, 
    MGTA206, MGTA211, MGTA217, ROSE222, ROSE230, ROSE238, ROSE245 
};

#if defined(RGB_MATRIX_ENABLE) && defined(CAPS_LOCK_LED_INDEX)

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) { return false; }
    switch (keycode) {
#ifdef RGB_MATRIX_ENABLE
        case QK_RGB_MATRIX_TOGGLE:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                    } break;
                }
            }
            if (!rgb_matrix_is_enabled()) {
                rgb_matrix_set_flags(LED_FLAG_ALL);
                rgb_matrix_enable();
            }
            return false;
#endif
    }
    return process_record_user(keycode, record);
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RM_TOGG_NE:
            if (record->event.pressed) {
                // rgb_matrix_set_color_all(0, 0, 0);
                rgb_matrix_toggle_noeeprom();
            }
            return false;
        case RM_NEXT_NE:
            if (record->event.pressed) {
                rgb_matrix_step_noeeprom();
            }
            return false;
        case RM_PREV_NE:
            if (record->event.pressed) {
                rgb_matrix_step_reverse_noeeprom();
            }
            return false;
        case RM_VALU_NE:
            if (record->event.pressed) {
                rgb_matrix_increase_val_noeeprom();
            }
            return false;
        case RM_VALD_NE:
            if (record->event.pressed) {
                rgb_matrix_decrease_val_noeeprom();
            }
            return false;
        case RM_HUEU_NE:
            if (record->event.pressed) {
                rgb_matrix_increase_hue_noeeprom();
            }
            return false;
        case RM_HUED_NE:
            if (record->event.pressed) {
                rgb_matrix_decrease_hue_noeeprom();
            }
            return false;
        case RM_SATU_NE:
            if (record->event.pressed) {
                rgb_matrix_increase_sat_noeeprom();
            }
            return false;
        case RM_SATD_NE:
            if (record->event.pressed) {
                rgb_matrix_decrease_sat_noeeprom();
            }
            return false;
        case RM_SPDU_NE:
            if (record->event.pressed) {
                rgb_matrix_increase_speed_noeeprom();
            }
            return false;
        case RM_SPDD_NE:
            if (record->event.pressed) {
                rgb_matrix_decrease_speed_noeeprom();
            }
            return false;

        //	RED0,
        case RED0:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);             // set mode
                rgb_matrix_sethsv_noeeprom(0, 255, 255); // set HSV
            } else {
            }
            return false;

        //	RED5,
        case RED5:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);             // set mode
                rgb_matrix_sethsv_noeeprom(5, 255, 255); // set HSV
            } else {
            }
            return false;

        //	RED10,
        case RED10:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);              // set mode
                rgb_matrix_sethsv_noeeprom(10, 255, 255); // set HSV
            } else {
            }
            return false;

        //	RED15,
        case RED15:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);              // set mode
                rgb_matrix_sethsv_noeeprom(15, 255, 255); // set HSV
            } else {
            }
            return false;

        //	ORNG21,
        case ORNG21:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);              // set mode
                rgb_matrix_sethsv_noeeprom(21, 255, 255); // set HSV
            } else {
            }
            return false;

        //	ORNG26,
        case ORNG26:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);              // set mode
                rgb_matrix_sethsv_noeeprom(26, 255, 255); // set HSV
            } else {
            }
            return false;

        //	ORNG31,
        case ORNG31:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);              // set mode
                rgb_matrix_sethsv_noeeprom(31, 255, 255); // set HSV
            } else {
            }
            return false;

        //	ORNG36,
        case ORNG36:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);              // set mode
                rgb_matrix_sethsv_noeeprom(36, 255, 255); // set HSV
            } else {
            }
            return false;

        //	YLLW43,
        case YLLW43:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);              // set mode
                rgb_matrix_sethsv_noeeprom(43, 255, 255); // set HSV
            } else {
            }
            return false;

        //	YLLW53,
        case YLLW53:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);              // set mode
                rgb_matrix_sethsv_noeeprom(53, 255, 255); // set HSV
            } else {
            }
            return false;

        //	YLLW63,
        case YLLW63:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);              // set mode
                rgb_matrix_sethsv_noeeprom(63, 255, 255); // set HSV
            } else {
            }
            return false;

        //	YLLW73,
        case YLLW73:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);              // set mode
                rgb_matrix_sethsv_noeeprom(73, 255, 255); // set HSV
            } else {
            }
            return false;

        //	GRN85,
        case GRN85:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);              // set mode
                rgb_matrix_sethsv_noeeprom(85, 255, 255); // set HSV
            } else {
            }
            return false;

        //	GRN95,
        case GRN95:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);              // set mode
                rgb_matrix_sethsv_noeeprom(95, 255, 255); // set HSV
            } else {
            }
            return false;

        //	GRN105,
        case GRN105:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(105, 255, 255); // set HSV
            } else {
            }
            return false;

        //	GRN115,
        case GRN115:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(115, 255, 255); // set HSV
            } else {
            }
            return false;

        //	CYAN127,
        case CYAN127:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(127, 255, 255); // set HSV
            } else {
            }
            return false;

        //	CYAN132,
        case CYAN132:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(132, 255, 255); // set HSV
            } else {
            }
            return false;

        //	CYAN137,
        case CYAN137:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(137, 255, 255); // set HSV
            } else {
            }
            return false;

        //	CYAN142,
        case CYAN142:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(142, 255, 255); // set HSV
            } else {
            }
            return false;

        //	AZRE148,
        case AZRE148:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(148, 255, 255); // set HSV
            } else {
            }
            return false;

        //	AZRE153,
        case AZRE153:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(153, 255, 255); // set HSV
            } else {
            }
            return false;

        //	AZRE158,
        case AZRE158:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(158, 255, 255); // set HSV
            } else {
            }
            return false;

        //	AZRE163,
        case AZRE163:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(163, 255, 255); // set HSV
            } else {
            }
            return false;

        //	BLUE169,
        case BLUE169:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(169, 255, 255); // set HSV
            } else {
            }
            return false;

        //	BLUE172,
        case BLUE172:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(172, 255, 255); // set HSV
            } else {
            }
            return false;

        //	BLUE175,
        case BLUE175:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(175, 255, 255); // set HSV
            } else {
            }
            return false;

        //	BLUE178,
        case BLUE178:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(178, 255, 255); // set HSV
            } else {
            }
            return false;

        //	VILT180,
        case VILT180:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(180, 255, 255); // set HSV
            } else {
            }
            return false;

        //	VILT185,
        case VILT185:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(185, 255, 255); // set HSV
            } else {
            }
            return false;

        //	VILT190,
        case VILT190:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(190, 255, 255); // set HSV
            } else {
            }
            return false;

        //	VILT195,
        case VILT195:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(195, 255, 255); // set HSV
            } else {
            }
            return false;

        //	MGTA201,
        case MGTA201:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(201, 255, 255); // set HSV
            } else {
            }
            return false;

        //	MGTA206,
        case MGTA206:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(206, 255, 255); // set HSV
            } else {
            }
            return false;

        //	MGTA211,
        case MGTA211:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(211, 255, 255); // set HSV
            } else {
            }
            return false;

        //	MGTA217,
        case MGTA217:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(217, 255, 255); // set HSV
            } else {
            }
            return false;

        //	ROSE222,
        case ROSE222:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(222, 255, 255); // set HSV
            } else {
            }
            return false;

        //	ROSE230,
        case ROSE230:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(230, 255, 255); // set HSV
            } else {
            }
            return false;

        //	ROSE238,
        case ROSE238:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(238, 255, 255); // set HSV
            } else {
            }
            return false;

        //	ROSE245,
        case ROSE245:
            if (record->event.pressed) {
                rgb_matrix_mode_noeeprom(1);               // set mode
                rgb_matrix_sethsv_noeeprom(245, 255, 255); // set HSV
            } else {
            }
            return false;

        // Mic Volume Down
        case MIC_VOLD:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_F22));      
            } else {
            }
            return false;

        // Mic Volume Up
        case MIC_VOLU:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_F21)); 
            } else {
            }
            return false;

        // Mic Mute
        case MIC_MUTE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_F20));    
            } else {
            }
            return false;
        // Sleep
        case OS_SLEP:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_F18));    
            } else {
            }
            return false;
    }
    #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif
    return true;
}

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) { return false; }
    // RGB_MATRIX_INDICATOR_SET_COLOR(index, red, green, blue);

    uint8_t caps_lock_leds[] = CAPS_LOCK_LED_INDEX;
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(caps_lock_leds[0], 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(caps_lock_leds[1], 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(caps_lock_leds[2], 255, 255, 255);
        RGB_MATRIX_INDICATOR_SET_COLOR(caps_lock_leds[3], 255, 255, 255);
    } else {
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(caps_lock_leds[0], 0, 0, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(caps_lock_leds[1], 0, 0, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(caps_lock_leds[2], 0, 0, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(caps_lock_leds[3], 0, 0, 0);
        }
    }
    return true;
}

#endif // CAPS_LOCK_LED_INDEX
