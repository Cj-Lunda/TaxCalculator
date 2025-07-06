#include <gtest/gtest.h>
#include "tax_calculator.h"  // You'll need to refactor your functions into this header.

TEST(TaxCalculatorTest, TestFindPercentage) {
    EXPECT_NEAR(findPercentage(10.0, 1000.0), 100.0, 1);
    EXPECT_NEAR(findPercentage(0.0, 500.0), 0.0, 1);
    EXPECT_NEAR(findPercentage(13.5, 530.0), 71.55, 1);
    EXPECT_NEAR(findPercentage(55, 20), 11, 1);
    EXPECT_NEAR(findPercentage(55, 20), 11, 1);
    EXPECT_NEAR(findPercentage(33, 209), 68.97, 1);
}

TEST(TaxCalculatorTest, TestMoneyFormat) {
    EXPECT_EQ(moneyFormat(1000.0), "$1,000.00");
    EXPECT_EQ(moneyFormat(1234.56), "$1,234.56");
    EXPECT_EQ(moneyFormat(1344), "$1,344.00");
    EXPECT_EQ(moneyFormat(12.55), "$12.55");
    EXPECT_EQ(moneyFormat(125994.65), "$125,994.65");
    EXPECT_EQ(moneyFormat(1679433906), "$1,679,433,906.00");
    EXPECT_EQ(moneyFormat(1.65), "$1.65");
}


