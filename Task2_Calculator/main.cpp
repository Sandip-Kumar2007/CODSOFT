#include <iostream>
#include <limits>

double getDouble(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        double x;
        if (std::cin >> x) return x;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number.\n";
    }
}

int getChoice() {
    while (true) {
        std::cout << "\nChoose operation:\n"
                     "1) Addition (+)\n"
                     "2) Subtraction (-)\n"
                     "3) Multiplication (*)\n"
                     "4) Division (/)\n"
                     "5) Exit\n"
                     "Enter choice (1-5): ";
        int c;
        if (std::cin >> c && c >= 1 && c <= 5) return c;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please choose 1-5.\n";
    }
}

int main() {
    std::cout << "=== Simple Calculator ===\n";
    while (true) {
        int choice = getChoice();
        if (choice == 5) break;

        double a = getDouble("Enter first number: ");
        double b = getDouble("Enter second number: ");

        switch (choice) {
            case 1: std::cout << "Result: " << (a + b) << "\n"; break;
            case 2: std::cout << "Result: " << (a - b) << "\n"; break;
            case 3: std::cout << "Result: " << (a * b) << "\n"; break;
            case 4:
                if (b == 0.0) std::cout << "Error: Division by zero!\n";
                else std::cout << "Result: " << (a / b) << "\n";
                break;
        }
    }
    std::cout << "Goodbye!\n";
    return 0;
}
