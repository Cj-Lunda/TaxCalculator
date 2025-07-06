// main.cpp

#include <iostream>
#include "tax_calculator.h"

using namespace std;

/**
 * @brief The main entry point of the Tax Calculator program.
 * 
 * Prompts the user to enter their income, then calls the
 * taxCalculator function to calculate and display the tax.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    double income;
    cout << "Using tax rates of 01 April 2025 - 31 March 2026 \n";
    cout << "Type your income (no spaces or commas): ";
    cout << "\n";
    cin >> income;

    cout << '\n';
    income = (income - floor(income) <= 0.5) ? floor(income) : floor(income) + 1; 
    taxCalculator(income);

    return 0;
}
