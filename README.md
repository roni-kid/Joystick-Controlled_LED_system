# Joystick-Controlled LED System

A simple Arduino UNO project that uses an analog joystick to control 4 LEDs based on direction — Up, Down, Left, and Right.

## How It Works

An analog joystick module is essentially two potentiometers stacked at 90 degrees — one for the X-axis, one for the Y-axis. Each gives an analog reading between 0–1023 (10-bit ADC), with the resting position sitting around 512.

Pushing the stick in a direction shifts one axis's reading away from center. By checking which side of center each axis lands on, and comparing it against threshold values, the sketch determines the direction and lights the matching LED.

A dead zone (thresholds set above and below center) prevents false triggers from natural drift when the joystick is idle.

## Components

- Arduino UNO
- Analog joystick module (VRx, VRy, SW pins)
- 4x LEDs
- 4x 220Ω resistors
- Breadboard + jumper wires

## Wiring

| Joystick Pin | Arduino Pin |
|---|---|
| VRx | A0 |
| VRy | A1 |
| SW | D2 (unused in this version) |
| GND | GND |
| +5V | 5V |

| LED | Direction | Arduino Pin |
|---|---|---|
| LED 1 | Up | D8 |
| LED 2 | Down | D9 |
| LED 3 | Left | D10 |
| LED 4 | Right | D11 |

Each LED: anode → pin through 220Ω resistor, cathode → GND.

## Notes

- If Up/Down or Left/Right appear swapped, your joystick module may have X/Y wired differently — swap `VRX_PIN`/`VRY_PIN` or flip the threshold comparisons.
- Threshold values (300/700) can be tuned depending on your specific joystick's drift and range.

## Author

Built as a personal side project outside of coursework — Level 100 Computer Engineering student at GCTU.
