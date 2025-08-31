#include <iostream>
#include <array>
#include <limits>
#include <string>

using Board = std::array<char, 9>;

void printBoard(const Board& b) {
    std::cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        std::cout << " " << b[i]   << " | " << b[i+1] << " | " << b[i+2] << "\n";
        if (i < 6) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

bool isWin(const Board& b, char p) {
    const int w[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // cols
        {0,4,8}, {2,4,6}           // diags
    };
    for (auto &line : w) {
        if (b[line[0]] == p && b[line[1]] == p && b[line[2]] == p) return true;
    }
    return false;
}

bool isDraw(const Board& b) {
    for (char c : b) if (c == ' ') return false;
    return true;
}

int getMove(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        int x;
        if (std::cin >> x && x >= 1 && x <= 9) return x;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number between 1 and 9.\n";
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
    std::cout << "=== Tic-Tac-Toe (2 Players) ===\n";
    do {
        Board b{};
        b.fill(' ');
        char player = 'X';

        std::cout << "Positions are numbered 1..9 as:\n"
                     " 1 | 2 | 3 \n"
                     "---+---+---\n"
                     " 4 | 5 | 6 \n"
                     "---+---+---\n"
                     " 7 | 8 | 9 \n";
        printBoard(b);

        while (true) {
            int pos = getMove(std::string("Player ") + player + ", choose position (1-9): ");
            int idx = pos - 1;
            if (b[idx] != ' ') {
                std::cout << "That spot is taken. Try another.\n";
                continue;
            }
            b[idx] = player;
            printBoard(b);

            if (isWin(b, player)) {
                std::cout << "Player " << player << " wins!\n";
                break;
            }
            if (isDraw(b)) {
                std::cout << "It's a draw.\n";
                break;
            }
            player = (player == 'X') ? 'O' : 'X';
        }
    } while (askYesNo("Play again"));

    std::cout << "Thanks for playing!\n";
    return 0;
}
