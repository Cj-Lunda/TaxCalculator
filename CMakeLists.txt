cmake_minimum_required(VERSION 3.10)
project(TaxCalculator)

set(CMAKE_CXX_STANDARD 17)

# Add the include directory for headers
include_directories(include)

# Add source files for the main application
add_executable(TaxCalculatorApp
    src/main.cpp
    src/tax_calculator.cpp
)

# Add include directory for the application target
target_include_directories(TaxCalculatorApp PRIVATE include)

# Enable testing
enable_testing()

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(TaxCalculatorTests
    tests/TaxCalculatorTest.cpp
    src/tax_calculator.cpp
)

# Add include directory for the test target
target_include_directories(TaxCalculatorTests PRIVATE include)

# Link GoogleTest libraries
target_link_libraries(TaxCalculatorTests gtest gtest_main)

# Register the test
add_test(NAME TaxCalculatorTests COMMAND TaxCalculatorTests)
