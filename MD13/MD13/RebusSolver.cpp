#include "RebusSolver.h"

RebusSolver::RebusSolver(const std::string& operandOne, const char& operationSymbol, const std::string& operandTwo,
    const std::string& arithmeticalResult) {
    setValues(operandOne, operationSymbol, operandTwo, arithmeticalResult);
}

void RebusSolver::setValues(const std::string& operandOne, const char& operationSymbol, const std::string& operandTwo,
    const std::string& arithmeticalResult) {

    for (const char& currentChar : operandOne) letters.insert(currentChar);
    for (const char& currentChar : operandTwo) letters.insert(currentChar);
    for (const char& currentChar : arithmeticalResult) letters.insert(currentChar);

    if (letters.size() > 10) RebusSolver::~RebusSolver();

    firstOperand = operandOne;
    operation = operationSymbol;
    secondOperand = operandTwo;
    result = arithmeticalResult;

    for (int index{ 0 }; index < letters.size(); index++) temporaryVariation.push_back(0);
}

void RebusSolver::solveRebus() {
    generateVariations(letters.size());
    std::map<char, int> letter_digit;
    int digit{ 0 };

    for (auto variation : variations) {

        for (const char& letter : letters) letter_digit[letter] = variation[digit++];

        std::string operand1{ firstOperand },
            operand2{ secondOperand },
            res{ result };

        for (const char& letter : letters) {
            operand1 = replaceLetterByDigit(operand1, letter, letter_digit[letter]);
            operand2 = replaceLetterByDigit(operand2, letter, letter_digit[letter]);
            res = replaceLetterByDigit(res, letter, letter_digit[letter]);
        }

        ArithmeticalOperationsWithTwoNumbers arithmetics(operand1, operand2);
        std::string resultOfArithmetics{ "" };

        if (operation == '+') resultOfArithmetics = arithmetics.getSumAsString();
        else if (operation == '-') resultOfArithmetics = arithmetics.getDifferenceAsString();
        else if (operation == '*') resultOfArithmetics = arithmetics.getProductAsString();
        else resultOfArithmetics = arithmetics.getQuotientAsString();

        if (res == resultOfArithmetics) answers.push_back(letter_digit);

        digit = 0;
    }
}

void RebusSolver::showResults() {

    if (answers.empty()) {
        std::cout << firstOperand << " " << operation << " " << secondOperand << " = " << result <<
            " -> There are no answers";
        return;
    }

    for (auto answer : answers) {
        std::string ans{ "" },
            operand1{ firstOperand },
            operand2{ secondOperand },
            res{ result };

        for (auto letter_digit : answer) {
            operand1 = replaceLetterByDigit(operand1, letter_digit.first, letter_digit.second);
            operand2 = replaceLetterByDigit(operand2, letter_digit.first, letter_digit.second);
            res = replaceLetterByDigit(res, letter_digit.first, letter_digit.second);
        }

        ans += operand1 + " " + operation + " " + operand2 + " = " + res;
        std::cout << firstOperand << " " << operation << " " << secondOperand << " = " << result <<
            " -> " << ans << "\n";
    }

}

void RebusSolver::generateVariations(const int numberOfGroupedDigits, int index) {

    if (index >= numberOfGroupedDigits) variations.push_back(temporaryVariation);
    else {

        for (int i{ index }; i < 10; i++) {
            temporaryVariation[index] = digits[i];
            swap(digits[i], digits[index]);
            generateVariations(numberOfGroupedDigits, index + 1);
            swap(digits[i], digits[index]);
        }

    }

}

void RebusSolver::swap(int& firstValue, int& secondValue) {
    int temporaryValue{ firstValue };
    firstValue = secondValue;
    secondValue = temporaryValue;
}

std::string RebusSolver::replaceLetterByDigit(std::string string, const char& letter, const int& digit) {

    for (char& currentChar : string)
        if (currentChar == letter) currentChar = digit + '0';

    return string;
}