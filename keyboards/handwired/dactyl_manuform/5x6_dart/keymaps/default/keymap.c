/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

enum custom_keycodes {
    IDE_TEST,
    IDE_TESTD,
    SPEC_LEFT,
    SPEC_RIGHT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    switch (keycode) {
    case IDE_TEST:
        if (record->event.pressed) {
           SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) "R" SS_UP(X_LCTL) SS_UP(X_LSFT)); // ctrl shift r
        }
        break;
    case IDE_TESTD:
        if (record->event.pressed) {
           SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) "D" SS_UP(X_LCTL) SS_UP(X_LSFT)); // ctrl shift d
        }
        break;
    case SPEC_LEFT:
        if (record->event.pressed) {
           SEND_STRING(SS_DOWN(X_ROPT) SS_DOWN(X_LCMD) SS_TAP(X_LEFT) SS_UP(X_ROPT) SS_UP(X_LCMD)); // ctrl shift d
        }
        break;
    case SPEC_RIGHT:
        if (record->event.pressed) {
           SEND_STRING(SS_DOWN(X_ROPT) SS_DOWN(X_LCMD) SS_TAP(X_RIGHT) SS_UP(X_ROPT) SS_UP(X_LCMD)); // ctrl shift d
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6_dart(
     KC_EQUAL , KC_1  , KC_2    , KC_3  , KC_4  , KC_5 ,            KC_6  , KC_7   , KC_8  , KC_9   , KC_0  , KC_MINUS,
     KC_TAB   , KC_Q  , KC_W    , KC_E  , KC_R  , KC_T ,            KC_Y  , KC_U   , KC_I  , KC_O   , KC_P  , KC_BSLASH,
     KC_ESC   , KC_A  , KC_S    , KC_D  , KC_F  , KC_G ,            KC_H  , KC_J   , KC_K  , KC_L   ,KC_SCLN, KC_QUOT,
     KC_LSHIFT, KC_Z  , KC_X    , KC_C  , KC_V  , KC_B ,            KC_N  , KC_M   ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSHIFT,
     RAISE    , KC_GRV,IDE_TESTD,IDE_TEST,                                          KC_LBRC, KC_RBRC,KC_X   , LOWER,
                                         KC_BSPC, LOWER   ,         KC_RCMD  , KC_SPC ,
                                         KC_DEL , KC_LCTL ,         KC_RCTL  , KC_ENT ,
                                         KC_BSPC, KC_LCMD ,         KC_ROPT  , KC_RCMD
  ),

  [_LOWER] = LAYOUT_5x6_dart(
     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,KC_VOLU,KC_VOLD,_______,_______,_______,
     _______,_______,_______,_______,_______,KC_LPRN,                        KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,_______,_______,
     _______,_______,_______,_______,_______,_______,                        SPEC_LEFT,SPEC_RIGHT,KC_PGDN,KC_END ,_______,_______,
     _______,_______,_______,_______,                                                        _______,_______,_______,_______,
                                             _______,KC_PSCR,            KC_TRNS,_______,
                                             _______,KC_TRNS,            KC_TRNS,_______,
                                             _______,KC_TRNS,            KC_TRNS,KC_TRNS



  ),

  [_RAISE] = LAYOUT_5x6_dart(
       KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
       _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE,
       _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
       _______,_______,_______,_______,                                                        _______,_______,_______,_______,
                                               _______,_______,            KC_EQL ,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),
};
