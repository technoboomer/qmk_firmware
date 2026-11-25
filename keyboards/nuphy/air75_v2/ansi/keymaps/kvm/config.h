// kvm keymap: tap/hold tuning. A keymap-level config.h is applied after the board's own
// (builddefs/build_keyboard.mk), so the board defaults and the default keymap stay untouched.
// #pragma once: QMK includes this file twice (config.h chain and QMK_KEYMAP_CONFIG_H).
#pragma once

// Decide "hold" as soon as another key is tapped while Caps Lock is held, even before the
// tapping term: a fast nested Ctrl+C (Caps down, C down, C up, Caps up) is Ctrl+C.
// A roll where Caps Lock is released first still counts as a tap (layout switch).
#define PERMISSIVE_HOLD

// The tapping term itself is per key, in keymap.c (get_tapping_term): this QMK version takes
// the board-wide TAPPING_TERM from keyboard.json ("tapping.term": 200) and redefining it
// here would not compile.
