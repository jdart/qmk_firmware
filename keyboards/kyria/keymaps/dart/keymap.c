
#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLEMAK 4
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#undef TAPPING_TERM
#define TAPPING_TERM 320
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

#define HOMEC_A LALT_T(KC_A)
#define HOMEC_R LGUI_T(KC_R)
#define HOMEC_S LSFT_T(KC_S)
#define HOMEC_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOMEC_N RCTL_T(KC_N)
#define HOMEC_E RSFT_T(KC_E)
#define HOMEC_I RGUI_T(KC_I)
#define HOMEC_O LALT_T(KC_O)

#define HOMEQ_A LALT_T(KC_A)
#define HOMEQ_S LGUI_T(KC_S)
#define HOMEQ_D LSFT_T(KC_D)
#define HOMEQ_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOMEQ_J RCTL_T(KC_J)
#define HOMEQ_K RSFT_T(KC_K)
#define HOMEQ_L RGUI_T(KC_L)
#define HOMEQ_SC LALT_T(KC_SCLN)


#define RAISE_BK LT(_RAISE, KC_BSPC)
#define LOWER_TB LT(_LOWER, KC_TAB)
#define LOWER_ESC LT(_LOWER, KC_ESC)
#define RAISE_ENT LT(_RAISE, KC_ENT)


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
      _______, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P     , KC_MINS  ,
      _______, HOMEQ_A, HOMEQ_S, HOMEQ_D, HOMEQ_F, KC_G   ,                                                      KC_H   , HOMEQ_J, HOMEQ_K, HOMEQ_L, HOMEQ_SC , KC_QUOT  ,
      _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , TG(_ADJUST), KC_LSFT ,      KC_LSFT  , TG(_ADJUST),  KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH  , KC_BSLASH,
                                 _______ , KC_DEL ,_______, RAISE_BK   , LOWER_TB,      LOWER_ESC, RAISE_ENT  ,  KC_SPC , _______, _______
    ),

    [_COLEMAK] = LAYOUT(
      _______, KC_Q   , KC_W    , KC_F   , KC_P   , KC_B  ,                                                    KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN , KC_MINS  ,
      _______, HOMEC_A, HOMEC_R , HOMEC_S, HOMEC_T, KC_G  ,                                                    KC_M   , HOMEC_N, HOMEC_E, HOMEC_I, HOMEC_O , KC_QUOT  ,
      _______, KC_Z   , KC_X    , KC_C   , KC_D   , KC_V  , TG(_ADJUST), KC_LSFT ,     KC_LSFT  , TG(_ADJUST), KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH , KC_BSLASH,
                                 _______ , KC_DEL ,_______, RAISE_BK   , LOWER_TB,     LOWER_ESC, RAISE_ENT  , KC_SPC , _______, _______
    ),

    [_LOWER] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                     _______ , KC_QUOT, KC_BSLS, _______, _______, KC_BSLS,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS , KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_AMPR , KC_EQL , KC_COMM, KC_DOT , KC_SLSH, KC_MINS,
                                 _______, _______, _______, KC_SCLN, KC_EQL ,  KC_EQL,  KC_SCLN, _______, _______, _______
    ),

    [_RAISE] = LAYOUT(
      _______, _______, KC_7  , KC_8  , KC_9   , _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, KC_4  , KC_5  , KC_6   , _______,                                     KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
      _______, KC_0   , KC_1  , KC_2  , KC_3   , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
      _______, _______, KC_F7  , KC_F8 , KC_F9 , KC_F10 ,                                     _______, _______, KC_BTN1, KC_BTN2, _______, _______,
      _______, _______, KC_F4  , KC_F5 , KC_F6 , KC_F11 ,                                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
      _______, _______, KC_F1  , KC_F2 , KC_F3 , KC_F12, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                _______,_______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};
