#include "tax_calculator.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <locale>

using namespace std;

// Tax brackets
const double firstRateMax = 15600;
const double secondRateMax = 53500;
const double thirdRateMax = 78100;
const double fourthRateMax = 180000;

// Global tax rate strings
const string rateOne = "below $15,600.00,                      tax:10.50% ";
const string rateTwo = "Over $15,600.00 and below $53,500.00,  tax:17.50%";
const string rateThree = "Over $53,500.00 and below $78,100.00,  tax:30.00%";
const string rateFour = "Over $78,100.00 and below $180,000.00, tax:33.00%";
const string rateFive = "Over 180,000.00,                       tax:39%";

const int COL1_WIDTH = 55;
const int COL2_WIDTH = 50;
const int COL3_WIDTH = 28;

string moneyFormat(double money) {
    ostringstream oss;
    oss.imbue(locale(""));
    oss << fixed << setprecision(2) << money;
    string numStr = oss.str();

    size_t dotPos = numStr.find('.');
    string intPart = numStr.substr(0, dotPos);
    string decPart = numStr.substr(dotPos);

    string result;
    int count = 0;
    for (auto it = intPart.rbegin(); it != intPart.rend(); ++it) {
        if (count && count % 3 == 0)
            result.insert(0, ",");
        result.insert(0, 1, *it);
        count++;
    }
    result += decPart;
    return "$" + result;
}

double findPercentage(double rate, double income) {
    double result = income * (rate / 100);
    result = round(result * 100.0) / 100.0;
    return result;
}

void totalString(double total) {
    cout << "Total Tax : " << moneyFormat(total) << endl;
}

void taxCalculator(double income) {
    double remainingIncome = income;
    double tax = 0.0;
    double total = 0.0;

    cout << left << setw(COL1_WIDTH) << "Income Tax Rate"
         << left << setw(COL2_WIDTH) << "Income"
         << left << setw(COL3_WIDTH) << "Tax" << endl;

    cout << string(COL1_WIDTH + COL2_WIDTH + 14, '-') << endl;

    if (income <= firstRateMax) {
        tax = findPercentage(10.5, remainingIncome);
        cout << left << setw(COL1_WIDTH) << rateOne
             << left << setw(COL2_WIDTH) << moneyFormat(remainingIncome)
             << left << setw(COL3_WIDTH) << moneyFormat(tax) << endl;
        total += tax;
    }
    else if (income <= secondRateMax) {
        remainingIncome = income - firstRateMax;
        tax = findPercentage(17.5, remainingIncome);

        cout << left << setw(COL1_WIDTH) << rateOne
             << left << setw(COL2_WIDTH) << moneyFormat(firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(1638) << endl;

        cout << left << setw(COL1_WIDTH) << rateTwo
             << left << setw(COL2_WIDTH) << moneyFormat(remainingIncome)
             << left << setw(COL3_WIDTH) << moneyFormat(tax) << endl;

        total = 1638 + tax;
    }
    else if (income <= thirdRateMax) {
        remainingIncome = income - secondRateMax;
        tax = findPercentage(30, remainingIncome);

        cout << left << setw(COL1_WIDTH) << rateOne
             << left << setw(COL2_WIDTH) << moneyFormat(firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(1638) << endl;

        cout << left << setw(COL1_WIDTH) << rateTwo
             << left << setw(COL2_WIDTH) << moneyFormat(secondRateMax - firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(6632.5) << endl;

        cout << left << setw(COL1_WIDTH) << rateThree
             << left << setw(COL2_WIDTH) << moneyFormat(remainingIncome)
             << left << setw(COL3_WIDTH) << moneyFormat(tax) << endl;

        total = 1638 + 6632.5 + tax;
    }
    else if (income <= fourthRateMax) {
        remainingIncome = income - thirdRateMax;
        tax = findPercentage(33, remainingIncome);

        cout << left << setw(COL1_WIDTH) << rateOne
             << left << setw(COL2_WIDTH) << moneyFormat(firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(1638) << endl;

        cout << left << setw(COL1_WIDTH) << rateTwo
             << left << setw(COL2_WIDTH) << moneyFormat(secondRateMax - firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(6632.5) << endl;

        cout << left << setw(COL1_WIDTH) << rateThree
             << left << setw(COL2_WIDTH) << moneyFormat(thirdRateMax - secondRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(7380) << endl;

        cout << left << setw(COL1_WIDTH) << rateFour
             << left << setw(COL2_WIDTH) << moneyFormat(remainingIncome)
             << left << setw(COL3_WIDTH) << moneyFormat(tax) << endl;

        total = 1638 + 6632.5 + 7380 + tax;
    }
    else {
        remainingIncome = income - fourthRateMax;
        tax = findPercentage(39, remainingIncome);

        cout << left << setw(COL1_WIDTH) << rateOne
             << left << setw(COL2_WIDTH) << moneyFormat(firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(1638) << endl;

        cout << left << setw(COL1_WIDTH) << rateTwo
             << left << setw(COL2_WIDTH) << moneyFormat(secondRateMax - firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(6632.5) << endl;

        cout << left << setw(COL1_WIDTH) << rateThree
             << left << setw(COL2_WIDTH) << moneyFormat(thirdRateMax - secondRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(7380) << endl;

        cout << left << setw(COL1_WIDTH) << rateFour
             << left << setw(COL2_WIDTH) << moneyFormat(fourthRateMax - thirdRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(33627) << endl;

        cout << left << setw(COL1_WIDTH) << rateFive
             << left << setw(COL2_WIDTH) << moneyFormat(remainingIncome)
             << left << setw(COL3_WIDTH) << moneyFormat(tax) << endl;

        total = 1638 + 6632.5 + 7380 + 33627 + tax;
    }

    cout << '\n';
    totalString(total);
}
