# Basys3 Reaction Timer

A reaction time measurement game for the Digilent Basys3 (XC7A35T-1CPG236C).

## Game Flow

| State | Display | Description |
|-------|---------|-------------|
| **IDLE** | Rolling circle (`.` spins across digits) | Waiting for start |
| **Press center** → | Fade in/out animation | 750ms intro |
| **TRIGGERED** | Rolling circle (fast) | Random countdown 2–5s |
| Countdown ends → | "GO" | Press center to react |
| **MEASURING** | "GO" constant | Latency being measured |
| Press center → | "OK." → latency | Result shown |
| **MEASURED** | latency ↔ AVG ↔ average | Cycles every few seconds |

### Navigation (MEASURED only)
- **Up** / **Down** — scroll through history (LEDs show position)
- **Left** — return to IDLE
- Center does nothing in MEASURED

After 3s of inactivity in history view, auto-returns to the live cycle.

## IO Mapping

| Pin | Signal | Notes |
|-----|--------|-------|
| W5  | `clk`  | 100 MHz |
| T17 | `rst`  | Active-high (inverted internally) |
| N17 | `btn_center` | Start / react |
| T18 | `btn_up`     | History up |
| U17 | `btn_down`   | History down |
| W19 | `btn_left`   | Return to IDLE |
| U2–W4 | `an[3:0]` | 7-seg anodes (active low) |
| W7–U7 | `seg[6:0]` | 7-seg segments (active low) |
| V7  | `seg[7]`  | DP |
| J2  | `buzz`    | Buzzer (PMOD JA3) |
| U16–L1 | `led[15:0]` | History position bargraph (led[7:0]) |

## Module Tests

Each module has a dedicated testbench with edge cases:

| Testbench | Module | What it tests |
|-----------|--------|---------------|
| `tb_state` | FSM | Normal cycle through all 6 states, INIT auto-advance, halt → SPAM, halt ignored in non-TRIGGERED, rapid pulses |
| `tb_generic_counter` | Counter | Count to MAX-1, wrap-around, `en` gating, reset |
| `tb_generic_counter_oneshot` | Counter (ONESHOT) | Stop at MAX-1, hold value, `en` gating, reset |
| `tb_generic_countdown_counter` | Countdown | Load at zero, count to zero, done stays high, reload, reset |
| `tb_lfsr` | LFSR | Output range [MIN, MAX), value changes over time, `en` gating, reset |
| `tb_seven_seg` | 7-seg driver | Zero brightness, full brightness, DP control, segment passthrough |
| `tb_buzzer` | Buzzer | Reset, PWM generation, tune completion, play-while-playing ignored |
| `tb_debounce_counter` | Debounce | Stable press/release, glitch rejection, bouncy press/release, rapid presses |
| `tb_top_basys3` | Full system | IDLE idle, press center → INIT/TRIGGERED, countdown → MEASURING, center → MEASURED, latency capture, history scroll up/down, left → IDLE, timeout, memory |

Run a single test:
```sh
just test tb_top_basys3              # full system integration
just test tb_state                   # FSM only
```

Run module tests individually (each needs the right include path):
```sh
# Basic modules (self-contained in ./src/)
just test tb_seven_seg
just test tb_buzzer
just test tb_debounce_counter

# FSM
just test tb_state

# Generic modules (need /home/b83c/hw/asic/asic/src/)
verilator --binary --build -j -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND -Wno-IMPLICIT \
  -I./src -I/home/b83c/hw/asic/asic/src --top-module tb_generic_counter \
  -o tb_generic_counter ./tests/tb_generic_counter.sv \
  /home/b83c/hw/asic/asic/src/generic_counter.sv && ./obj_dir/tb_generic_counter
```

View waveform:
```sh
just surfer waveform.fst
```

## Architecture

```
top_basys3
 ├── debounce_counter ×4   — ms_tick-gated debounce (10ms)
 ├── generic_counter       — 1ms tick generator
 ├── generic_counter       — Latency counter (oneshot, 5s timeout)
 ├── lfsr                 — Random delay 2–5s
 ├── generic_countdown_counter — Random countdown
 ├── state                — FSM (edge-triggered)
 ├── anim_ctrl            — Display patterns per state
 ├── seven_seg            — 7-segment driver with PWM
 └── buzzer               — Melody player (5 tunes)
```

## Building

### Simulation
```sh
just test tb_top_basys3     # run tests (sccache + verilator)
just surfer waveform.fst    # view waveform
```

### Bitstream (Vivado)
```sh
just build                  # batch build
just upload                 # program via openFPGALoader
```

Or open `vivado-project-files/reaction_meter_xzy/reaction_meter_xzy.xpr` in Vivado GUI.

## Tunes

| Latency | Tune |
|---------|------|
| <200ms  | Victory (C5 E5 G5 C6) |
| <300ms  | Good (G4 C5 E5) |
| <400ms  | Average (C4 E4 G4) |
| ≥400ms  | Slow (C4 A4 F4) |
| Timeout | Sad (A2 C3 E3) |

## Notes
- Debounce: 10ms counter-based (gated by `ms_tick`, not raw cycles)
- FSM: rising-edge triggered (`bi_rise`) — no level-triggered hold logic
- All modules use `always @(posedge clk)` style
