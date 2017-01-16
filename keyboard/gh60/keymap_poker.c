#include "keymap_common.h"
#include "bootloader.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP(
        ESC,    1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSLS, GRV,VOLU, \
              TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,BSPC,VOLD, \
             CAPS,        A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,QUOT, ENT,MUTE, \
             LSFT,        Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,RSFT,  UP, FN0, \
             LCTL,LGUI,LALT,                SPC,          RALT,RGUI,RCTL,LEFT,DOWN,RGHT),
    /* 1: FN */
    KEYMAP(
        TRNS,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12,TRNS,TRNS,TRNS, \
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
             TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
             TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, FN2,TRNS,TRNS, FN0, \
             TRNS,TRNS,TRNS,                TRNS,         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS), 
    /* 2: ReProgram */
    KEYMAP(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
             TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
             TRNS,      FN3,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
             TRNS,TRNS,TRNS,                TRNS,         TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),
};

enum function_id {
    TEENSY_KEY,
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TOGGLE(1),        // to Fn overlay
    [1] = ACTION_LAYER_MOMENTARY(2),     // toggle arrow overlay
    [2] = ACTION_FUNCTION(TEENSY_KEY),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{    
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(50);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
};
