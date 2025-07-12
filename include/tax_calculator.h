#ifndef TAX_CALCULATOR_H
#define TAX_CALCULATOR_H

#include <string>

std::string moneyFormat(double money);
double findPercentage(double rate, double income);
void totalString(double total);
void taxCalculator(double income);

// Global tax rate descriptions
extern const std::string rateOne;
extern const std::string rateTwo;
extern const std::string rateThree;
extern const std::string rateFour;
extern const std::string rateFive;

#endif // TAX_CALCULATOR_H
