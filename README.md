# LCD Lyrics Display

An Arduino project that scrolls song lyrics across a **16x2 LCD 1602 screen** with a typewriter typing animation.
Currently loaded with **"Love Me Not (Remix)"** by **Ravyn Lenae ft. Rex Orange County**.



---

## How It Works

- Lyrics are split into words and packed into 16-character lines
- Long lyrics auto-page across multiple screens
- Each screen types out character by character with a configurable speed
- Display time is split evenly across screens so nothing rushes

---

## Hardware Required

| Component | Details |
|---|---|
| Arduino (any) | Uno, Nano, Mega, etc. |
| LCD 1602 | 16 columns x 2 rows |
| 10kΩ Potentiometer | For contrast adjustment |
| Jumper wires | — |
| Breadboard | Optional |

---

##  Wiring

| LCD Pin | Arduino Pin |
|---|---|
| RS | 12 |
| EN | 11 |
| D4 | 5 |
| D5 | 4 |
| D6 | 3 |
| D7 | 2 |
| VSS | GND |
| VDD | 5V |
| V0 | Potentiometer middle pin |
| A (backlight+) | 5V |
| K (backlight−) | GND |

---

## Dependencies

- [`LiquidCrystal`](https://www.arduino.cc/en/Reference/LiquidCrystal) — built into the Arduino IDE, no install needed

---

## Getting Started

1. Clone or download this repo
2. Open `lcd-lyrics.ino` in the Arduino IDE
3. Wire up your LCD (see table above)
4. Upload to your Arduino
5. Enjoy the show

---

## Customization

### Change typing speed
In each `showLyric()` call, the third argument controls typing speed in milliseconds per character:

```cpp
showLyric("Your lyric here", 3000, 60); // 60ms per character
```

| Feel | Speed |
|---|---|
| Snappy | `30ms` |
| Natural | `60ms` |
| Dramatic | `100ms` |

### Add your own lyrics
Replace or add lines in `loop()`:

```cpp
void loop() {
  showLyric("Your lyric here", 3000, 60);
  showLyric("Another line", 3000, 60);
}
```

The second argument is how long (in ms) the lyric stays on screen total.

---

