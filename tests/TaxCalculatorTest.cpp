#include <gtest/gtest.h>
#include "tax_calculator.h"  // You'll need to refactor your functions into this header.

TEST(TaxCalculatorTest, TestFindPercentage) {
    EXPECT_NEAR(findPercentage(10.0, 1000.0), 100.0, 0.01);
    EXPECT_NEAR(findPercentage(0.0, 500.0), 0.0, 0.01);
}

TEST(TaxCalculatorTest, TestMoneyFormat) {
    EXPECT_EQ(moneyFormat(1000.0), "$1000.00");
    EXPECT_EQ(moneyFormat(1234.56), "$1234.56");
}

TEST(TaxCalculatorTest, TestTotalString) {
    testing::internal::CaptureStdout();
    totalString(5000.0);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("$5000.00"), std::string::npos);
}
