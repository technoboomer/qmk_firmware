/*
Copyright 2023 @ Nuphy <https://nuphy.com/>

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
#include "layer_names.h"

// Caps Lock: tap = switch input layout, hold = Left Ctrl (config.h: PERMISSIVE_HOLD; get_tapping_term: 170 ms).
// The keyboard alone does it; no software on the host:
//  - MAC_BASE: the tap sends Caps Lock. macOS has a checkbox for exactly this key
//    ("Use the Caps Lock key to switch to and from ABC", System Settings > Keyboard > Input Sources).
//  - WIN_BASE: the tap sends KC_F13, which never leaves the keyboard: process_record_user turns it
//    into the Windows default language hotkey Left Alt+Shift (no Caps Lock state ever toggles).
#define CAPS_CTL_MAC LCTL_T(KC_CAPS)
#define CAPS_CTL_WIN LCTL_T(KC_F13)

// Fn layer additions (rows that were transparent in the default keymap):
// arrows on the home row, Home/End above, PgUp/PgDn nearby, previous/next tab, Delete on Backspace.
#define FN_PREV_TAB_MAC LSG(KC_LBRC)                   // Cmd+Shift+[  (Safari, Chrome, Finder)
#define FN_NEXT_TAB_MAC LSG(KC_RBRC)                   // Cmd+Shift+]
#define FN_PREV_TAB_WIN LCTL(KC_TAB)                   // Ctrl+Tab
#define FN_NEXT_TAB_WIN (QK_LCTL | QK_LSFT | KC_TAB)   // Ctrl+Shift+Tab

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// layer Mac
[MAC_BASE] = LAYOUT_75_ansi(
    KC_ESC,     KC_BRID,   KC_BRIU,     TASK,       SEARCH,     MAC_VOICE,   MAC_DND,   KC_MPRV,     KC_MPLY,     KC_MNXT,   KC_MUTE,    KC_VOLD,    KC_VOLU,     PRT_AREA,   KC_INS,     KC_DEL,
    KC_GRV,     KC_1,      KC_2,        KC_3,       KC_4,       KC_5,        KC_6,      KC_7,        KC_8,        KC_9,      KC_0,       KC_MINS,    KC_EQL,                  KC_BSPC,    KC_PGUP,
    KC_TAB,     KC_Q,      KC_W,        KC_E,       KC_R,       KC_T,        KC_Y,      KC_U,        KC_I,        KC_O,      KC_P,       KC_LBRC,    KC_RBRC,                 KC_BSLS,    KC_PGDN,
    CAPS_CTL_MAC, KC_A,    KC_S,        KC_D,       KC_F,       KC_G,        KC_H,      KC_J,        KC_K,        KC_L,      KC_SCLN,    KC_QUOT,                             KC_ENT,     KC_HOME,
    KC_LSFT,               KC_Z,        KC_X,       KC_C,       KC_V,        KC_B,      KC_N,        KC_M,        KC_COMM,   KC_DOT,     KC_SLSH,                 KC_RSFT,    KC_UP,      KC_END,
    KC_LCTL,    KC_LALT,   KC_LGUI,                                          KC_SPC,                              KC_RGUI,   MO(1),      KC_RCTL,                 KC_LEFT,    KC_DOWN,    KC_RGHT),

// layer Mac Fn
[MAC_FN] = LAYOUT_75_ansi(
    LOCK_SCR,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,       KC_F6,     KC_F7,       KC_F8,       KC_F9,     KC_F10,     KC_F11,     KC_F12,      PRT_SCR,    _______,    _______,
    _______,    LNK_BLE1,   LNK_BLE2,   LNK_BLE3,   LNK_RF,     _______,     _______,   _______,     _______,     _______,   _______,    _______,    KC_DEL,                  _______,    _______,
    LINK_PREV,    _______,    _______,    _______,    _______,    _______,     _______,   KC_HOME,     _______,     KC_END,    KC_PGUP,     DEV_RESET,  SLEEP_MODE,              BAT_SHOW,   _______,
    KC_CAPS,    _______,    _______,    _______,    _______,    _______,     KC_LEFT,   KC_DOWN,     KC_UP,       KC_RGHT,   FN_PREV_TAB_MAC, FN_NEXT_TAB_MAC,                  _______,    _______,
    MO(4),                _______,    _______,    RGB_TEST,   _______,     BAT_NUM,   KC_PGDN,     MO(4),       RM_SPDD,   RM_SPDU,    _______,                 MO(4),    RM_VALU,    _______,
    _______,    _______,    _______,                                         _______,                             _______,   MO(1),      _______,                 RM_NEXT,    RM_VALD,    RM_HUEU),

// layer win
[WIN_BASE] = LAYOUT_75_ansi(
    KC_ESC,     KC_F1,     KC_F2,       KC_F3,      KC_F4,      KC_F5,       KC_F6,     KC_F7,       KC_F8,       KC_F9,     KC_F10,     KC_F11,     KC_F12,      KC_PSCR,    KC_INS,     KC_DEL,
    KC_GRV,     KC_1,      KC_2,        KC_3,       KC_4,       KC_5,        KC_6,      KC_7,        KC_8,        KC_9,      KC_0,       KC_MINS,    KC_EQL,                  KC_BSPC,    KC_PGUP,
    KC_TAB,     KC_Q,      KC_W,        KC_E,       KC_R,       KC_T,        KC_Y,      KC_U,        KC_I,        KC_O,      KC_P,       KC_LBRC,    KC_RBRC,                 KC_BSLS,    KC_PGDN,
    CAPS_CTL_WIN, KC_A,    KC_S,        KC_D,       KC_F,       KC_G,        KC_H,      KC_J,        KC_K,        KC_L,      KC_SCLN,    KC_QUOT,                             KC_ENT,     KC_HOME,
    KC_LSFT,               KC_Z,        KC_X,       KC_C,       KC_V,        KC_B,      KC_N,        KC_M,        KC_COMM,   KC_DOT,     KC_SLSH,                 KC_RSFT,    KC_UP,      KC_END,
    KC_LCTL,    KC_LGUI,   KC_LALT,                                          KC_SPC,                              KC_RALT,   MO(3),      KC_RCTL,                 KC_LEFT,    KC_DOWN,    KC_RGHT),

// layer win Fn
[WIN_FN] = LAYOUT_75_ansi(
    LOCK_SCR,    KC_BRID,    KC_BRIU,    KC_CALC,    SEARCH,     _______,     MAC_DND,   KC_MPRV,     KC_MPLY,     KC_MNXT,   KC_MUTE,    KC_VOLD,    KC_VOLU,     PRT_AREA,    _______,    _______,
    _______,    LNK_BLE1,   LNK_BLE2,   LNK_BLE3,   LNK_RF,     _______,     _______,   _______,     _______,     _______,   _______,    _______,    KC_DEL,                  _______,    _______,
    LINK_PREV,    _______,    _______,    _______,    _______,    _______,     _______,   KC_HOME,     _______,     KC_END,    KC_PGUP,     DEV_RESET,  SLEEP_MODE,              BAT_SHOW,   _______,
    KC_CAPS,    _______,    _______,    _______,    _______,    _______,     KC_LEFT,   KC_DOWN,     KC_UP,       KC_RGHT,   FN_PREV_TAB_WIN, FN_NEXT_TAB_WIN,                  _______,    _______,
    MO(4),                _______,    _______,    RGB_TEST,   _______,     BAT_NUM,   KC_PGDN,     MO(4),       RM_SPDD,   RM_SPDU,    _______,                 MO(4),    RM_VALU,    _______,
    _______,    _______,    _______,                                         _______,                             _______,   MO(3),      _______,                 RM_NEXT,    RM_VALD,    RM_HUEU),

// layer 4
[M_LAYER] = LAYOUT_75_ansi(
    QK_REBOOT,  DB_TOGG,    RF_DFU,     _______,    _______,    _______,     _______,   _______,     _______,     _______,   _______,    DEBOUNCE_D,  DEBOUNCE_I, _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,     _______,   _______,     _______,     _______,   _______,    SLEEP_D,     SLEEP_I,                _______,    _______,
    _______,    _______,    MACWIN_TG,    _______,    _______,    _______,     _______,   _______,     _______,     SIDE_1,    _______,    _______,     SLEEP_NOW,              _______,    _______,
    CAPS_WORD,  AWAKE_TG,    _______,    DEBOUNCE_T, FROW_SWAP,    GAME_MODE,   _______,   _______,     SOCD_TOG,    _______,   _______,    _______,                             _______,    _______,
    _______,                _______,    _______,    _______,    _______,     _______,   NUMLOCK_IND, _______,     SIDE_SPD,  SIDE_SPI,   _______,                 _______,    SIDE_VAI,   _______,
    _______,    _______,    _______,                                         _______,                             _______,   MO(4),      _______,                 SIDE_MOD,   SIDE_VAD,   SIDE_HUI)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_F13:
            // Caps Lock tap on WIN_BASE (see CAPS_CTL_WIN above): Left Alt+Shift, the Windows
            // default "Between input languages" hotkey. Prefer Win+Space? Use:
            //   SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(50) SS_TAP(X_SPC) SS_DELAY(50) SS_UP(X_LGUI));
            if (record->event.pressed) {
                // The pauses matter: sent back-to-back (0 ms between reports), Windows does not
                // recognise the Alt+Shift language hotkey. 50 ms steps read like a human key press.
                SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_DOWN(X_LSFT) SS_DELAY(50) SS_UP(X_LSFT) SS_DELAY(50) SS_UP(X_LALT));
            }
            return false;
        default:
            return true;
    }
}

// Caps Lock counts as Ctrl after 170 ms (the board-wide default in keyboard.json is 200).
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CAPS_CTL_MAC:
        case CAPS_CTL_WIN:
            return 170;
        default:
            return TAPPING_TERM;
    }
}
