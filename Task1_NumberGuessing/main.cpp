#include <iostream>
#include <random>
#include <limits>
#include <string>

int getInt(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        int x;
        if (std::cin >> x) return x;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer.\n";
    }
}

bool askYesNo(const std::string& prompt) {
    while (true) {
        std::cout << prompt << " (y/n): ";
        std::string s;
        if (std::cin >> s) {
            if (s == "y" || s == "Y") return true;
            if (s == "n" || s == "N") return false;
        }
        std::cout << "Please enter y or n.\n";
    }
}

int main() {
    std::cout << "=== Number Guessing Game ===\n";
    std::random_device rd;
    std::mt19937 gen(rd());

    do {
        int low = 1, high = 100;
        std::uniform_int_distribution<> dist(low, high);
        int secret = dist(gen);
        int attempts = 0;

        std::cout << "I picked a number between " << low << " and " << high << ". Try to guess it!\n";

        while (true) {
            int guess = getInt("Your guess: ");
            ++attempts;

            if (guess < secret) {
                std::cout << "Too low!\n";
            } else if (guess > secret) {
                std::cout << "Too high!\n";
            } else {
                std::cout << "Correct! You guessed it in " << attempts << " attempts.\n";
                break;
            }
        }
    } while (askYesNo("Play again"));

    std::cout << "Thanks for playing!\n";
    return 0;
}
