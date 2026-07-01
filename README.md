# Hangman Game

A classic console-based Hangman word-guessing game built in C++.

## Features
- Randomly selects a word from a predefined word list each round
- Tracks correct and incorrect letter guesses
- Case-insensitive letter matching
- Displays word progress with underscores for unguessed letters
- Limited to 6 incorrect attempts before game over
- Prevents duplicate wrong guesses from being counted twice

## How It Works
1. The program randomly picks a secret word.
2. The player guesses one letter at a time.
3. Correct letters are revealed in their position in the word.
4. Incorrect letters reduce the player's remaining attempts.
5. The game ends when the player either guesses the full word (win) or runs out of attempts (lose).

## How to Run

```bash
g++ hangman.cpp -o hangman
./hangman
```

On Windows (using g++/MinGW):
```bash
g++ hangman.cpp -o hangman.exe
hangman.exe
```

## Concepts Used
- Vectors (`std::vector`) for tracking guessed letters and wrong guesses
- `std::find` from `<algorithm>` to prevent duplicate wrong guesses
- Random number generation with `rand()` and `srand(time(0))`
- String and character manipulation

## Author
Areeha Arshad — B.Sc. Software Engineering, University of Management and Technology (UMT), Lahore

## Course
Programming Fundamentals — Project Phase 02
