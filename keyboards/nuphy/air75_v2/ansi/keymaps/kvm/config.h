// kvm keymap: tap/hold tuning. A keymap-level config.h is applied after the board's own
// (builddefs/build_keyboard.mk), so the board defaults and the default keymap stay untouched.
// #pragma once: QMK includes this file twice (config.h chain and QMK_KEYMAP_CONFIG_H).
#pragma once

// How long Caps Lock must be held to count as Ctrl. QMK's default is 200.
#define TAPPING_TERM 170

// Decide "hold" as soon as another key is tapped while Caps Lock is held, even before
// TAPPING_TERM: a fast nested Ctrl+C (Caps down, C down, C up, Caps up) is Ctrl+C.
// A roll where Caps Lock is released first still counts as a tap (layout switch).
#define PERMISSIVE_HOLD
