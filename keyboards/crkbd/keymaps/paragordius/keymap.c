#include QMK_KEYBOARD_H


extern uint8_t is_master;

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

/* Main `LOWER` and `RAISE` buttons are one-shot */
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define S_LWR  OSL(_LOWER)
#define S_RSE  OSL(_RAISE)
#define STICKY TG(_STICKY)

/* Keycodes for our `STICKY` layer of modifiers */
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

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_ENT, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_SPC,     KC_SPC,   RAISE, KC_LALT \
                                      //`--------------------------'  `--------------------------'

  ),

  [_STICKY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       S_LCTL, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       S_LSFT, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           S_LGUI, S_LWR,   _______,    _______,   S_RSE,  S_LALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, UC_M_LN, KC_BSLS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                       KC_F11,  KC_F12,   KC_F13, STICKY, UC_M_MA, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TILD, X(CHCK), X(DAGG), X(IPCT), X(FING), X(ELIP),                      X(ENDA), KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, X(CROS), X(DDAG), X(BULL), X(REFR), X(INBG),                      X(EMDA), KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
const char *read_timelog(void);

char mods_str[21] = {};

const char *oneshot_mods_status(uint8_t mods, uint8_t locked_mods) {
  snprintf(mods_str, sizeof(mods_str), " ");
  if (layer_state_is(_STICKY)) {
    char ctrl_status = ' ';
    char shft_status = ' ';
    char lgui_status = ' ';
    char lalt_status = ' ';
    // If there are active mods, denote them with lowercase
    if (mods & MOD_MASK_CTRL) {
      ctrl_status = 'c';
    }
    if (mods & MOD_MASK_SHIFT) {
      shft_status = 's';
    }
    if (mods & MOD_MASK_GUI) {
      lgui_status = 'm';
    }
    if (mods & MOD_MASK_ALT) {
      lalt_status = 'a';
    }
    // And if there are active locked mods, denote those with uppercase
    if (locked_mods & MOD_MASK_CTRL) {
      ctrl_status = 'C';
    }
    if (locked_mods & MOD_MASK_SHIFT) {
      shft_status = 'S';
    }
    if (locked_mods & MOD_MASK_GUI) {
      lgui_status = 'm';
    }
    if (locked_mods & MOD_MASK_ALT) {
      lalt_status = 'A';
    }
    snprintf(mods_str, sizeof(mods_str), "Mods:[%c] [%c] [%c] [%c]", ctrl_status, shft_status, lgui_status, lalt_status);
  }
  return mods_str;
}

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    // This is what is writing the sticky keys status line
    matrix_write_ln(matrix, oneshot_mods_status(get_oneshot_mods(), get_oneshot_locked_mods()));
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
    // Taken from here https://www.reddit.com/r/olkb/comments/d8jhx8/qmk_clearing_locked_oneshot_mods/
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
  return true;
}
