# Embedded System Projects

This repository contains a collection of embedded system projects I developed solo during my faculty course. While each team was supposed to pick **one** project, I challenged myself to complete **all three** individually: Alarm Clock, Sorting Algorithm, and Searching Algorithm. 💪

These projects were developed and tested using the **ATmega32 microcontroller**, with simulations likely running on **Proteus**. Full source code and hardware driver implementations are included for each.

---

## 📁 Projects Included

### 1. Alarm Clock
> A digital alarm clock that displays time in HH:MM:SS AM/PM format, lets the user adjust current and alarm times, and triggers a buzzer + LED when alarm time is reached.

- Displays time on LCD.
- Set/update time and alarm using keypad.
- Buzzer and red LED activate on alarm time.
- User can silence alarm manually.
- Custom drivers for LCD, keypad, buzzer, etc.

📂 Directory: `/AlarmClock`

---

### 2. Sorting Algorithm
> Sorts a list of user-input numbers (via keypad) and displays the sorted list on both an LCD and four 7-segment displays, one number at a time.

- Input up to 4-digit numbers.
- Sorted output on LCD.
- Then sequentially displayed (1/sec) on 7-segments.
- Implemented bubble or insertion sort manually.

📂 Directory: `/SortingAlgorithm`

---

### 3. Searching Algorithm
> Allows user to input a list of numbers and search for a specific value. Displays matching positions on a 7-segment and LEDs (binary form).

- Input list via keypad (max length: 16).
- Search for a number and get all matching positions.
- Results shown as:
  - Index on 7-segment
  - Binary representation on 4 LEDs

📂 Directory: `/SearchingAlgorithm`

---

## 📑 Extra Files

- `projects ideas.pdf`: Original task description from the course instructor.
- `.pdsprj` files: Project workspace files for Proteus (or similar).

---

## 🛠️ Notes

- All hardware components use **modular drivers** — no logic stuffed in `main.c`.
- These projects were tested and verified on real hardware during course evaluations.
- They showcase basic embedded programming, hardware interfacing, and C-based MCU development.

---

## 🚀 How to Run (Optional for Simulators)

You can use:
- **Proteus** for simulation (if available).
- Flash the `.hex` files to an actual **ATmega32** board.
- Check source code comments for pin mappings.

---

## License

This repo is licensed under the [MIT License](LICENSE).

---

**Made with 100% caffeine and curiosity** by Ziad Gamal 🇪🇬
