#pragma once

#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> largeNumber;

class ArithmeticalOperationsWithTwoNumbers {
    const int SIZE_OF_VECTOR = 1000;
    largeNumber firstNumber, secondNumber, sum, difference, product, quotient, remainderOfQuotient, decimalQuotient;

public:
    ArithmeticalOperationsWithTwoNumbers(std::string numberOne, std::string numberTwo);

    std::string getSumAsString();
    std::string getDifferenceAsString();
    std::string getProductAsString();
    std::string getQuotientAsString();

    void showAllInfo();

private:
    largeNumber fromString(const std::string& string);

    std::string toString(const largeNumber& number);

    int compareNumbers(const largeNumber& firstNumber, const largeNumber& secondNumber);

    largeNumber addZerosToBeginning(largeNumber number, int numberOfZeros);

    largeNumber addZerosToEnd(largeNumber number, int numberOfZeros);

    largeNumber deleteZerosFromBeginning(largeNumber number);

    largeNumber distributeNumberAcrossCells(largeNumber number);

    largeNumber countSum(largeNumber firstNumber, largeNumber secondNumber);

    largeNumber countDifference(largeNumber minuend, largeNumber subtrahend);

    int countNumberOfSubtractions(largeNumber minuend, const largeNumber& subtrahend);

    largeNumber countProduct(const largeNumber& multiplicand, const int& multiplier);

    largeNumber countProduct(const largeNumber& multiplicand, const largeNumber& multiplier);

    largeNumber countQuotient(largeNumber dividend, const largeNumber& divisor, largeNumber& remainder);

    largeNumber countDecimalQuotient(const largeNumber& dividend, const largeNumber& divisor);
};