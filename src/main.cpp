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
    cout << "Type your income (no spaces or commas): ";
    cin >> income;

    cout << '\n';
    taxCalculator(income);

    return 0;
}
