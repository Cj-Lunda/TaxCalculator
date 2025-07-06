// tax_calculator.h

#ifndef TAX_CALCULATOR_H
#define TAX_CALCULATOR_H

#include <string>

/**
 * @brief Formats a monetary value as a currency string.
 * 
 * @param money The amount to format.
 * @return A formatted currency string with two decimal places and a dollar sign.
 */
std::string moneyFormat(double money);

/**
 * @brief Calculates the tax amount for a given rate and income.
 * 
 * @param rate The tax rate in percent (e.g., 17.5 for 17.5%).
 * @param income The income amount to apply the tax rate to.
 * @return The calculated tax amount.
 */
double findPercentage(double rate, double income);

/**
 * @brief Prints the total tax amount in currency format.
 * 
 * @param total The total tax to display.
 */
void totalString(double total);

/**
 * @brief Calculates and displays tax details based on income.
 * 
 * Computes and prints the applicable tax brackets, amounts, and total tax for the given income.
 * 
 * @param income The total income to calculate tax on.
 */
void taxCalculator(double income);

// Global tax rate descriptions (extern)

/**
 * @brief Description for the first tax bracket (up to $15,600).
 */
extern const std::string rateOne;

/**
 * @brief Description for the second tax bracket (over $15,600 up to $53,500).
 */
extern const std::string rateTwo;

/**
 * @brief Description for the third tax bracket (over $53,500 up to $78,100).
 */
extern const std::string rateThree;

/**
 * @brief Description for the fourth tax bracket (over $78,100 up to $180,000).
 */
extern const std::string rateFour;

/**
 * @brief Description for the fifth tax bracket (over $180,000).
 */
extern const std::string rateFive;

#endif // TAX_CALCULATOR_H
