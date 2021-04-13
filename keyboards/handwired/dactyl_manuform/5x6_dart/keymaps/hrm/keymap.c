/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#undef TAPPING_TERM
#define TAPPING_TERM 320
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Left-hand home row mods
#define HOME_A LALT_T(KC_A)
#define HOME_S LGUI_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L RGUI_T(KC_L)
#define HOME_SCLN LALT_T(KC_SCLN)


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

enum custom_keycodes {
    IDE_TEST = SAFE_RANGE,
    IDE_TESTD,
    SPEC_LEFT,
    SPEC_RIGHT,
    PSS_NEXT,
    PSS_PREV,
    PSS_FOCUS
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    switch (keycode) {
        case KC_EQL:
            if ((get_mods() & MOD_MASK_GUI)) {
                return false;
            }
            break;
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
            SEND_STRING(SS_DOWN(X_ROPT) SS_DOWN(X_LCMD) SS_TAP(X_LEFT) SS_UP(X_ROPT) SS_UP(X_LCMD)); // opt cmd left
            }
            break;
        case SPEC_RIGHT:
            if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_ROPT) SS_DOWN(X_LCMD) SS_TAP(X_RIGHT) SS_UP(X_ROPT) SS_UP(X_LCMD)); // opt cmd right
            }
            break;
        case PSS_NEXT:
            if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_ROPT) SS_DOWN(X_LCMD) SS_TAP(X_DOWN) SS_UP(X_ROPT) SS_UP(X_LCMD)); //opt cmd down
            }
            break;
        case PSS_PREV:
            if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_ROPT) SS_DOWN(X_LCMD) SS_TAP(X_UP) SS_UP(X_ROPT) SS_UP(X_LCMD)); // opt cmd up
            }
            break;
        case PSS_FOCUS: if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LCMD) SS_TAP(X_F12) SS_UP(X_LSFT) SS_UP(X_LCMD)); // shift cmd f12
            }
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//   [_QWERTY] = LAYOUT_5x6_dart(
//      KC_EQUAL , KC_1  , KC_2    , KC_3  , KC_4  , KC_5 ,            KC_6  , KC_7   , KC_8  , KC_9   , KC_0  , KC_MINUS,
//      KC_TAB   , KC_Q  , KC_W    , KC_E  , KC_R  , KC_T ,            KC_Y  , KC_U   , KC_I  , KC_O   , KC_P  , KC_BSLASH,
//      KC_ESC   , KC_A  , KC_S    , KC_D  , KC_F  , KC_G ,            KC_H  , KC_J   , KC_K  , KC_L   ,KC_SCLN, KC_QUOT,
//      KC_LSHIFT, KC_Z  , KC_X    , KC_C  , KC_V  , KC_B ,            KC_N  , KC_M   ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSHIFT,
//      IDE_TESTD,IDE_TEST,RAISE   , KC_GRV,                                           KC_LBRC, KC_RBRC,PSS_PREV,PSS_NEXT,
//                                          KC_BSPC, LOWER   ,         KC_RCMD  , KC_SPC ,
//                                          KC_DEL , RAISE   ,         KC_RCTL  , KC_ENT ,
//                                          KC_TAB , KC_LCMD ,         KC_ROPT  , KC_ESC
//   ),

  [_QWERTY] = LAYOUT_5x6_dart(
     KC_ESC   , KC_1  , KC_2    , KC_3  , KC_4  , KC_5 ,            KC_6   , KC_7   , KC_8   , KC_9   , KC_0     , KC_MINUS,
     KC_EQUAL , KC_Q  , KC_W    , KC_E  , KC_R  , KC_T ,            KC_Y   , KC_U   , KC_I   , KC_O   , KC_P     , KC_BSLASH,
     KC_TAB   , HOME_A, HOME_S  , HOME_D, HOME_F, KC_G ,            KC_H   , HOME_J , HOME_K , HOME_L , HOME_SCLN, KC_QUOT,
     KC_LSHIFT, KC_Z  , KC_X    , KC_C  , KC_V  , KC_B ,            KC_N   , KC_M   ,KC_COMM , KC_DOT ,KC_SLSH   , KC_RSHIFT ,
     IDE_TESTD,IDE_TEST,RAISE   , KC_GRV,                                            KC_LBRC , KC_RBRC,PSS_PREV  , PSS_NEXT,
                                         KC_DEL,  KC_BSPC,          KC_SPC, RAISE   ,
                                         KC_TAB , LOWER  ,          KC_ENT, KC_ESC  ,
                                         KC_LCTL, TG(_RAISE)  ,     KC_ESC, KC_LCTL
  ),

  [_LOWER] = LAYOUT_5x6_dart(
     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
     _______,_______,_______,_______,_______,_______,                        _______,SPEC_LEFT,SPEC_RIGHT,_______,_______,KC_MINUS,
     _______,_______,_______,_______,_______,_______,                        KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,_______,_______,
     _______,_______,_______,_______,_______,_______,                        KC_ESC,KC_ESC ,KC_TAB,KC_END ,_______,_______,
     KC_TRNS,_______,_______,_______,                                            _______,_______,_______,_______,
                                             _______,KC_PSCR,            KC_TRNS,_______,
                                             _______,KC_TRNS,            KC_TRNS,_______,
                                             _______,KC_TRNS,            KC_TRNS,KC_TRNS
  ),

  [_RAISE] = LAYOUT_5x6_dart(
       KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
       _______,_______,_______,KC_LBRC,KC_RBRC,_______,                        _______,KC_MS_BTN1,KC_MS_BTN2 ,KC_SLCK,_______,_______,
       KC_ESC ,_______,_______,KC_LCBR,KC_RCBR,_______,                        KC_MS_LEFT,KC_MS_DOWN,KC_MS_UP,KC_MS_RIGHT,_______,_______,
       _______,_______,_______,KC_LPRN,KC_RPRN,_______,                        _______,KC_MS_WH_DOWN,KC_MS_WH_UP,_______,_______,_______,
       _______,_______,_______,_______,                                                        _______,_______,_______,_______,
                                               KC_ACL0,_______,             KC_EQL ,_______,
                                               KC_ACL1,_______,             _______,_______,
                                               KC_ACL2,KC_TRNS,         _______,_______
  ),
};
