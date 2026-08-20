#include <iostream>
using namespace std;

// 1. Har operation ke liye alag function banaya
void showMenu() {
    cout << "\n=== ADVANCED CALCULATOR ===" << endl;
    cout << "1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n4. Division (/)\n5. Exit\n";
    cout << "Enter your choice (1-5): ";
}

double add(double num1, double num2) { return num1 + num2; }
double subtract(double num1, double num2) { return num1 - num2; }
double multiply(double num1, double num2) { return num1 * num2; }

// Edge case handle karne wala function (Zero se divide hone par error bachana)
void divide(double num1, double num2) {
    if (num2 == 0) {
        cout << "Error: Division by zero is not allowed!" << endl;
    } else {
        cout << "Result: " << num1 / num2 << endl;
    }
}

int main() {
    int choice;
    double n1, n2;

    // Infinite loop lagaya taaki calculator tab tak chale jab tak user band na kare
    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 5) {
            cout << "Thank you for using the professional calculator! Exiting..." << endl;
            break; // Loop se bahar nikalne ke liye
        }

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice! Please try again." << endl;
            continue;
        }

        cout << "Enter two numbers: ";
        cin >> n1 >> n2;

        switch (choice) {
            case 1: cout << "Result: " << add(n1, n2) << endl; break;
            case 2: cout << "Result: " << subtract(n1, n2) << endl; break;
            case 3: cout << "Result: " << multiply(n1, n2) << endl; break;
            case 4: divide(n1, n2); break;
        }
    }
    return 0;
}
