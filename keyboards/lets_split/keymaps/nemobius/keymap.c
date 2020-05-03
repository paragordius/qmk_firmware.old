#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

/* Main `LOWER` and `RAISE` buttons are tap toggle */
#define LOWER   TT(_LOWER)
#define RAISE   TT(_RAISE)
#define TAPPING_TOGGLE 2
/* Corner `LWR_OS` and `RAS_OS` are the same, but are one-shot instead of tap toggle */
#define LWR_OS  OSM(_LOWER)
#define RAS_OS  OSM(_RAISE)
#define ONESHOT_TAP_TOGGLE 2

// Unicode map as seen here : https://beta.docs.qmk.fm/using-qmk/software-features/feature_unicode#unicode-map
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
  EMDA
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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RasOS| LwrOS| Alt  | GUI  |Lower |    Space    |Raise | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
  RAS_OS,  LWR_OS,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_HOME, KC_PGDN, KC_PGUP, KC_END \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   ✓  |   †  |   ·  |   ☞  |   …  |   –  |   -  |   =  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   ✗  |   ‡  |   •  |   ※  |   ‽  |   —  |   _  |   +  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  KC_TILD, X(CHCK), X(DAGG), X(IPCT), X(FING), X(ELIP), X(ENDA), KC_MINUS,KC_EQL,  KC_LCBR, KC_LCBR, KC_PIPE, \
  _______, X(CROS), X(DDAG), X(BULL), X(REFR), X(INBG), X(EMDA), KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  | Left | Down |  Up  |Right |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 | F11  | F12  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, KC_BSLS, \
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

};
