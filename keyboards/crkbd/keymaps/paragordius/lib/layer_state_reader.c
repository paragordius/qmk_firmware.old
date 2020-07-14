#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define L_BASE 0
#define L_STICKY 2
#define L_LOWER 4
#define L_RAISE 8
#define L_LOWER_STICKY 6
#define L_RAISE_STICKY 10
#define L_STICKY_STICKY 12
#define L_CLEAR 14

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_RAISE:
  case L_RAISE_STICKY:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
  case L_LOWER_STICKY:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_STICKY:
  case L_STICKY_STICKY:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Sticky");
    break;
  case L_CLEAR:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Clear!");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
