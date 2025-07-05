// main.cpp
#include <iostream>
#include "tax_calculator.h"

using namespace std;

int main() {
    double income;
    cout << "Type your income (no spaces or commas): ";
    cin >> income;

    cout << '\n';
    taxCalculator(income);

    return 0;
}