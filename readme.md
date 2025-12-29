
# 🎮 TacTokToe

TacTokToe is a console-based strategy game inspired by Tic-Tac-Toe, written in **C**. Instead of winning by lines, players earn **scores** based on a hidden bonus matrix. After all turns are played, the player (or bot) with the higher total score wins.

This project is designed as a learning-focused game that demonstrates:
- 2D arrays
- Input validation
- Random number generation
- Turn-based game logic
- Simple AI behavior

---

## ⚠️ Important Notice

This README documentation and markup were generated and refined with the assistance of a generative AI system.
The game logic and implementation decisions remain user-directed and educational in nature.


## 📦 Features

### Game Modes
- **Single Player**: Human vs Computer
- **Bot Mode**: Computer vs Computer (auto-play)
- **Multiplayer**: *Coming soon*

### Core Mechanics
- 3×3 board
- Each cell has a hidden bonus value between **-2.0 and +2.0** (step 0.5)
- Players take turns claiming empty cells
- Final score = sum of bonus values of owned cells
- Higher score wins

---

## 🧠 Game Logic Overview

### Board Representation
- `matrixposition[3][3]`
  - `-1` → empty cell
  - `0`  → Player / Bot A
  - `1`  → Bot / Player B

- `matrixbonus[3][3]`
  - Random floating-point values in range:
    ```
    -2, -1.5, -1, -0.5, 0, 0.5, 1, 1.5, 2
    ```

### Turn Flow (Single Player)
1. Player selects a valid empty cell
2. Computer selects a random empty cell
3. Board is displayed
4. Repeat for 3 rounds
5. Scores are calculated and compared

---

## ▶️ How to Play

### Compile
```bash
gcc main.c -o tactoktoe
```

### Run
```bash
./tactoktoe
```

### Menu Options
- `1` → Single Player
- `0` → Bot vs Bot
- `2` → Multiplayer (not yet implemented)

### Input Format
When prompted:
```
Enter Row Column (0-2)
```
Example:
```
1 2
```

---

## 🧮 Scoring System

After all turns:
- Each owned cell contributes its bonus value
- Scores are summed per player

Example output:
```
Human Score: 1.50
Bot Score: -0.50
PLAYER Wins!
```

---

## 🤖 Bot Behavior

- Bots choose **random empty cells**
- Random seed is initialized once at program start
- Bot vs Bot mode includes delays to visualize turns

---

## 📁 Project Structure

```
main.c        # Game source code
README.md     # Documentation (this file)
```

---

## ⚠️ Known Limitations

- No win detection by rows/columns (score-based only)
- Multiplayer mode not implemented yet
- Board uses numeric values (no X/O symbols)
- No persistent game state or replay

---

## 🚀 Future Improvements

Planned upgrades:
- Multiplayer support
- Smarter AI using bonus matrix heuristics
- Symbol-based board display (X / O)
- Early win detection
- Configurable board size
- Cleaner UI rendering

---

## 🛠 Technical Notes

- `srand(time(NULL))` is called **once** in `main`
- Input validation prevents out-of-bounds access
- Random bonus values are generated at game start
- Uses standard C libraries only

---

## 📜 License

This project is for educational and personal use. Feel free to modify and expand it.

---

## 🙌 Credits

Developed as a learning project in C.

Have fun experimenting and extending TacTokToe!
