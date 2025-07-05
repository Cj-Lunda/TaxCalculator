// tax_calculator.cpp
#include "tax_calculator.h"
#include <iostream>
#include <iomanip>
#include <sstream>
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
    oss.imbue(locale("en_US.UTF-8"));
    oss << fixed << setprecision(2) << money;
    return "$" + oss.str();
}

double findPercentage(double rate, double income) {
    return income * (rate / 100);
}

void totalString(double total) {
    cout << "Total Tax : " << moneyFormat(total) << endl;
}

void taxCalculator(double income) {
    double remainingIncome = income;
    double tax = 0.0;

    cout << left << setw(COL1_WIDTH) << "Income Tax Rate"
         << left << setw(COL2_WIDTH) << "Income"
         << left << setw(COL3_WIDTH) << "Tax" << endl;

    cout << string(COL1_WIDTH + COL2_WIDTH + 14, '-') << endl;

    if (income <= firstRateMax) {
        tax = findPercentage(10.5, remainingIncome);
        cout << left << setw(COL1_WIDTH) << rateOne
             << left << setw(COL2_WIDTH) << moneyFormat(remainingIncome)
             << left << setw(COL3_WIDTH) << moneyFormat(tax) << endl;
    }
    else if (income <= secondRateMax) {
        remainingIncome = income - firstRateMax;
        tax = 1638 + findPercentage(17.5, remainingIncome);
        cout << left << setw(COL1_WIDTH) << rateOne
             << left << setw(COL2_WIDTH) << moneyFormat(firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(1638) << endl;

        cout << left << setw(COL1_WIDTH) << rateTwo
             << left << setw(COL2_WIDTH) << moneyFormat(remainingIncome)
             << left << setw(COL3_WIDTH) << moneyFormat(tax - 1638) << endl;
    }
    else if (income <= thirdRateMax) {
        remainingIncome = income - secondRateMax;
        tax = 8270 + findPercentage(30, remainingIncome);

        cout << left << setw(COL1_WIDTH) << rateOne
             << left << setw(COL2_WIDTH) << moneyFormat(firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(1638) << endl;

        cout << left << setw(COL1_WIDTH) << rateTwo
             << left << setw(COL2_WIDTH) << moneyFormat(secondRateMax - firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(6632) << endl;

        cout << left << setw(COL1_WIDTH) << rateThree
             << left << setw(COL2_WIDTH) << moneyFormat(remainingIncome)
             << left << setw(COL3_WIDTH) << moneyFormat(tax - 8270) << endl;
    }
    else if (income <= fourthRateMax) {
        remainingIncome = income - thirdRateMax;
        tax = 15650 + findPercentage(33, remainingIncome);

        cout << left << setw(COL1_WIDTH) << rateOne
             << left << setw(COL2_WIDTH) << moneyFormat(firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(1638) << endl;

        cout << left << setw(COL1_WIDTH) << rateTwo
             << left << setw(COL2_WIDTH) << moneyFormat(secondRateMax - firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(6632) << endl;

        cout << left << setw(COL1_WIDTH) << rateThree
             << left << setw(COL2_WIDTH) << moneyFormat(thirdRateMax - secondRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(7380) << endl;

        cout << left << setw(COL1_WIDTH) << rateFour
             << left << setw(COL2_WIDTH) << moneyFormat(remainingIncome)
             << left << setw(COL3_WIDTH) << moneyFormat(tax - 15650) << endl;
    }
    else {
        remainingIncome = income - fourthRateMax;
        tax = 49227 + findPercentage(39, remainingIncome);

        cout << left << setw(COL1_WIDTH) << rateOne
             << left << setw(COL2_WIDTH) << moneyFormat(firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(1638) << endl;

        cout << left << setw(COL1_WIDTH) << rateTwo
             << left << setw(COL2_WIDTH) << moneyFormat(secondRateMax - firstRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(6632) << endl;

        cout << left << setw(COL1_WIDTH) << rateThree
             << left << setw(COL2_WIDTH) << moneyFormat(thirdRateMax - secondRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(7380) << endl;

        cout << left << setw(COL1_WIDTH) << rateFour
             << left << setw(COL2_WIDTH) << moneyFormat(fourthRateMax - thirdRateMax)
             << left << setw(COL3_WIDTH) << moneyFormat(33627) << endl;

        cout << left << setw(COL1_WIDTH) << rateFive
             << left << setw(COL2_WIDTH) << moneyFormat(remainingIncome)
             << left << setw(COL3_WIDTH) << moneyFormat(tax - 49227) << endl;
    }

    totalString(tax);
}