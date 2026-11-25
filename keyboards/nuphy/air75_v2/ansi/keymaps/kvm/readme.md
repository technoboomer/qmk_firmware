# kvm keymap — NuPhy Air75 V2

The `default` keymap plus a few personal changes. Everything else (side lights, sleep, game
mode, SOCD, debounce, Fn+M settings, Caps Word on double Shift) is the stock firmware.

## Caps Lock: tap = next input layout, hold = Left Ctrl

The keyboard does it alone; nothing to install on the computer.

| Connection mode | Caps Lock tap sends | Host setting |
|---|---|---|
| Mac (`MAC_BASE`) | Caps Lock | macOS: System Settings → Keyboard → Input Sources → Edit… → "Use the Caps Lock key to switch to and from ABC" |
| Win / Linux (`WIN_BASE`) | Left Alt+Shift (sent by the keyboard; the tap key is `KC_F13`, which never leaves the keyboard) | Windows: default "Between input languages" hotkey = Left Alt+Shift |

Tuning: `get_tapping_term()` in `keymap.c` gives Caps Lock 170 ms (the board default is 200); `config.h` sets
`PERMISSIVE_HOLD` — a key tapped while Caps Lock is held means Ctrl, so a fast `Ctrl+C` works; Caps Lock released
before the next key means tap — layout switch.

- Caps Lock state is never toggled on Windows (nothing to undo, no Caps Lock "off" hacks needed).
- `Fn+Caps` is the real Caps Lock (also what the side-light Caps indicator and the Caps Word light look for).
- Win+Space instead of Alt+Shift: one line in `process_record_user` in `keymap.c`.

## Fn layer (both Mac and Win), on keys that were transparent before

| Fn + | Sends |
|---|---|
| `H` `J` `K` `L` | ← ↓ ↑ → |
| `U` / `O` | Home / End |
| `P` / `N` | Page Up / Page Down |
| `;` / `'` | previous / next tab (Win: Ctrl+Tab, Ctrl+Shift+Tab; Mac: Cmd+Shift+[ / ]) |
| `Backspace` | Delete |

Holding `Fn+Shift` still opens the `Fn+M` settings layer; everything else on Fn is unchanged.

## Build and flash

```sh
qmk compile -kb nuphy/air75_v2/ansi -km kvm      # -> nuphy_air75_v2_ansi_kvm.bin
# keyboard: Fn+M+Esc for 3 s (keys flash white), then
dfu-util -a 0 -d 0483:DF11 -s 0x08000000:leave -D nuphy_air75_v2_ansi_kvm.bin
```

The GitHub workflow `.github/workflows/kvm-keymap.yml` builds the same `.bin` on every push to the `kvm/keymap` branch.

VIA works with this keymap (`VIA_ENABLE`); a key remapped to `KC_F13` would send the layout-switch macro.
