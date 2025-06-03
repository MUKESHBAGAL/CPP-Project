#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayChoices() {
    cout << "\nRock, Paper, Scissors Game Start \n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    cout << "Enter your choice: ";
}

string getChoiceName(int choice) {
    switch (choice) {
        case 1: return "Rock";
        case 2: return "Paper";
        case 3: return "Scissors";
        default: return "Invalid";
    }
}

void determineWinner(int playerChoice, int computerChoice) {
    cout << "You chose: " << getChoiceName(playerChoice) << "\n";
    cout << "Computer chose: " << getChoiceName(computerChoice) << "\n";

    if (playerChoice == computerChoice) {
        cout << "It's a tie!\n";
    } else if ((playerChoice == 1 && computerChoice == 3) || 
               (playerChoice == 2 && computerChoice == 1) || 
               (playerChoice == 3 && computerChoice == 2)) {
        cout << "You win!\n";
    } else {
        cout << "Computer wins!\n";
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    int playerChoice, computerChoice;
    char playAgain;

    do {
        displayChoices();
        cin >> playerChoice;

        // Validate player's choice
        if (playerChoice < 1 || playerChoice > 3) {
            cout << "Invalid choice! Please enter 1, 2, or 3.\n";
            continue;
        }

        computerChoice = (rand() % 3) + 1; // Random number between 1 and 3
        determineWinner(playerChoice, computerChoice);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (tolower(playAgain) == 'y');

    cout << "Thanks for playing! Goodbye!\n";

    return 0;
}

