#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "ArithmeticalOperationsWithTwoNumbers.h"

class RebusSolver {
private:
    std::string firstOperand, secondOperand, result;
    char operation;
    std::vector<std::vector<int>> variations;
    std::vector<int> temporaryVariation, 
        digits{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::set<char> letters;
    std::vector<std::map<char, int>> answers;

public:
    RebusSolver(const std::string& operandOne, const char& operationSymbol, const std::string& operandTwo,
        const std::string& arithmeticalResult);

    void setValues(const std::string& operandOne, const char& operationSymbol, const std::string& operandTwo,
        const std::string& arithmeticalResult);

    void solveRebus();

    void showResults();

private:
    void generateVariations(const int numberOfGroupedDigits, int index = 0);

    void swap(int& firstValue, int& secondValue);

    std::string replaceLetterByDigit(std::string string, const char& letter, const int& digit);
};

