#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _STICKY 1
#define _LOWER  2
#define _RAISE  3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define STICKY TG(_STICKY)

/* Keycodes for our `STICKY` layer of modifiers */
#define S_LWR  OSL(_LOWER)
#define S_RSE  OSL(_RAISE)
#define S_LCTL OSM(MOD_LCTL)
#define S_LSFT OSM(MOD_LSFT)
#define S_LGUI OSM(MOD_LGUI)
#define S_LALT OSM(MOD_LALT)

// Unicode map as seen here : https://beta.docs.qmk.fm/using-qmk/software-features/feature_unicode#unicode-map
// Note: `UNICODEMAP_ENABLE = yes` needs to be in your `rules.mk` file!
enum unicode_names {
  CHCK,
  CROS,
  DAGG,
  DDAG,
  IPCT,
  BULL,
  FING,
  REFR,
  ELIP,
  INBG,
  ENDA,
  EMDA,
  SM_A,
  SM_B,
  SM_C,
  SM_D,
  SM_E,
  SM_F,
  SM_G,
  SM_H,
  SM_I,
  SM_J,
  SM_K,
  SM_L,
  SM_M,
  SM_N,
  SM_O,
  SM_P,
  SM_Q,
  SM_R,
  SM_S,
  SM_T,
  SM_U,
  SM_V,
  SM_W,
  SM_X,
  SM_Y,
  SM_Z
};

const uint32_t PROGMEM unicode_map[] = {
  [CHCK] = 0x2713, // ✓
  [CROS] = 0x2717, // ✗
  [DAGG] = 0x2020, // †
  [DDAG] = 0x2021, // ‡
  [IPCT] = 0x00B7, // ·
  [BULL] = 0x2022, // •
  [FING] = 0x261E, // ☞
  [REFR] = 0x203B, // ※
  [ELIP] = 0x2026, // …
  [INBG] = 0x203D, // ‽
  [ENDA] = 0x2013, // –
  [EMDA] = 0x2014, // —
  [SM_A] = 0x1D43, // ᵃ
  [SM_B] = 0x1D47, // ᵇ
  [SM_C] = 0x1D9C, // ᶜ
  [SM_D] = 0x1D48, // ᵈ
  [SM_E] = 0x1D49, // ᵉ
  [SM_F] = 0x1DA0, // ᶠ
  [SM_G] = 0x1D4D, // ᵍ
  [SM_H] = 0x02B0, // ʰ
  [SM_I] = 0x1DA6, // ᶦ
  [SM_J] = 0x02B2, // ʲ
  [SM_K] = 0x1D4F, // ᵏ
  [SM_L] = 0x02E1, // ˡ
  [SM_M] = 0x1D50, // ᵐ
  [SM_N] = 0x207F, // ⁿ
  [SM_O] = 0x1D52, // ᵒ
  [SM_P] = 0x1D56, // ᵖ
  [SM_Q] = 0x1D60, // ᵠ
  [SM_R] = 0x02B3, // ʳ
  [SM_S] = 0x02E2, // ˢ
  [SM_T] = 0x1D57, // ᵗ
  [SM_U] = 0x1D58, // ᵘ
  [SM_V] = 0x1D5B, // ᵛ
  [SM_W] = 0x02B7, // ʷ
  [SM_X] = 0x02E3, // ˣ
  [SM_Y] = 0x02B8, // ʸ
  [SM_Z] = 0x1DBB, // ᶻ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 ,-----------------------------------------------------.  ,-----------------------------------------------------.
 | Tab    |   Q    |   W    |   E    |   R    |   T    |  |   Y    |   U    |   I    |   O    |   P    | Bksp   |
 |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
 | Ctrl   |   A    |   S    |   D    |   F    |   G    |  |   H    |   J    |   K    |   L    |   ;    |  "     |
 |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
 | Shift  |   Z    |   X    |   C    |   V    |   B    |  |   N    |   M    |   ,    |   .    |   /    | Enter  |
 |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
 | Clear  | Sticky | Alt    | GUI    | Lower  | Space  |  | Space  | Raise  | Home   | PgDn   | PgUp   | End    |
 `-----------------------------------------------------'  `-----------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_CLEAR,STICKY,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,     KC_SPC,  RAISE,   KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Sticky
 ,-----------------------------------------------------.  ,-----------------------------------------------------.
 |        |        |        |        |        |        |  |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
 | S Ctl  |        |        |        |        |        |  |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
 | S Shft |        |        |        |        |        |  |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
 |        |        | S Alt  | S LGUI |        |        |  |        |        |        |        |        |        |
 `-----------------------------------------------------'  `-----------------------------------------------------'
 */

[_STICKY] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  S_LCTL,  _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  S_LSFT,  _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  _______, _______, S_LALT,  S_LGUI,  S_LWR,   _______,    _______, S_RSE,   _______, _______, _______, _______
),
/* Lower
 ,-----------------------------------------------------.  ,-----------------------------------------------------.
 | Esc    |   1    |   2    |   3    |   4    |   5    |  |   6    |   7    |   8    |   9    |   0    |        |
 |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
 |   `    |  F1    |  F2    |  F3    |  F4    |  F5    |  | Left   | Down   | Up     | Right  | UC_LNX |  \     |
 |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
 |        |  F6    |  F7    |  F8    |  F9    |  F10   |  |  F11   |  F12   |        |        | UC_MAC |        |
 |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |  |        |        |        |        |        | Reset |
 `-----------------------------------------------------'  `-----------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,UC_M_LN, KC_BSLS,
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,     KC_F11,  KC_F12,  _______, _______, UC_M_MA, _______,
  _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, RESET
),

/* Raise
 ,-----------------------------------------------------.  ,-----------------------------------------------------.
 | Esc    |   !    |   @    |   #    |   $    |   %    |  |   ^    |   &    |   *    |   (    |   )    |        |
 |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
 |   ~    |   ✓    |   †    |   ·    |   ☞    |   …    |  |   –    |   -    |   =    |   {    |   }    |  |     |
 |--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
 |        |   ✗    |   ‡    |   •    |   ※    |   ‽    |  |   —    |   _    |   +    |   [    |   ]    |        |
 |--------+--------+--------+--------+-----  -+--------|  |--------+--------+--------+--------+--------+--------|
 |        |        |        |        |        |        |  |        |        | Audio  | Click  | Mu Tog | Mu Mod |
 `-----------------------------------------------------'  `-----------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  KC_TILD, X(CHCK), X(DAGG), X(IPCT), X(FING), X(ELIP),    X(ENDA), KC_MINUS,KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE,
  _______, X(CROS), X(DDAG), X(BULL), X(REFR), X(INBG),    X(EMDA), KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, _______,
  _______, _______, _______, _______, _______, _______,    _______, _______, AU_TOG,  CK_TOGG, MU_TOG,  MU_MOD
),


};

void eeconfig_init_user(void) {
    set_unicode_input_mode(UC_LNX);
}

// Taken from here https://www.reddit.com/r/olkb/comments/d8jhx8/qmk_clearing_locked_oneshot_mods/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_CLEAR && record->event.pressed) {
        bool rc = true;
        uint8_t mods = 0;
        if ((mods = get_oneshot_mods()) && !has_oneshot_mods_timed_out()) {
            clear_oneshot_mods();
            unregister_mods(mods);
            rc = false;
        }
        if ((mods = get_oneshot_locked_mods())) {
            clear_oneshot_locked_mods();
            unregister_mods(mods);
            rc = false;
        }
        if (is_oneshot_layer_active()) {
            layer_clear();
            rc = false;
        }
        return rc;
    }
    return true;
}
