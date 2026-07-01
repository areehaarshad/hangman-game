#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm> // For std::find

using namespace std;

// Function to get a random word from a predefined list
string getRandomWord() {
    vector<string> words = {"apple", "banana", "programming", "hangman", "keyboard", "computer", "laptop", "project"};
    int index = rand() % words.size(); // Get a random index
    return words[index];
}

// Function to display the current state of the guessed word
void displayWord(const string &word, const vector<bool> &guessed) {
    for (size_t i = 0; i < word.length(); i++) {
        if (guessed[i]) {
            cout << word[i] << " "; // Show the guessed letter
        } else {
            cout << "_ "; // Show an underscore for unguessed letters
        }
    }
    cout << endl;
}

int main() {
    srand(time(0)); // Seed the random number generator

    string word = getRandomWord(); // Random word to guess
    int maxAttempts = 6;           // Maximum allowed incorrect guesses
    int incorrectGuesses = 0;      // Count of incorrect guesses
    vector<bool> guessed(word.length(), false); // Track guessed letters
    vector<char> wrongGuesses;                  // Store wrong guesses

    cout << "Welcome to Hangman!" << endl;
    cout << "Guess the word by entering one letter at a time." << endl;
    cout << "You have " << maxAttempts << " incorrect attempts. Good luck!" << endl;

    // Main game loop
    while (incorrectGuesses < maxAttempts) {
        cout << "\nWord to guess: ";
        displayWord(word, guessed);

        cout << "Wrong guesses: ";
        for (char c : wrongGuesses) {
            cout << c << " ";
        }
        cout << endl;

        cout << "Enter your guess: ";
        char guess;
        cin >> guess;

        // Convert to lowercase for case-insensitive comparison
        guess = tolower(guess);

        bool correct = false;
        for (size_t i = 0; i < word.length(); i++) {
            if (tolower(word[i]) == guess && !guessed[i]) { // Match and not already guessed
                guessed[i] = true;
                correct = true;
            }
        }

        if (correct) {
            cout << "Good guess!" << endl;
        } else {
            // Check if the letter has already been guessed as wrong
            if (find(wrongGuesses.begin(), wrongGuesses.end(), guess) == wrongGuesses.end()) {
                wrongGuesses.push_back(guess); // Add to wrong guesses
                incorrectGuesses++;
                cout << "Wrong guess! Attempts left: " << maxAttempts - incorrectGuesses << endl;
            } else {
                cout << "You already guessed that letter!" << endl;
            }
        }

        // Check if the word is fully guessed
        bool wordGuessed = true;
        for (bool g : guessed) {
            if (!g) {
                wordGuessed = false;
                break;
            }
        }

        if (wordGuessed) {
            cout << "\nCongratulations! You guessed the word: " << word << endl;
            break;
        }
    }

    // If the user runs out of attempts
    if (incorrectGuesses == maxAttempts) {
        cout << "\nGame over! The correct word was: " << word << endl;
    }

    return 0;
}
