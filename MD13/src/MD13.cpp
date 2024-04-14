#include <iostream>
#include "RebusSolver.h"

int main() {
    std::string firstOperand, secondOperand, result;
    char operation;

    std::cout << "firstOperand = "; std::cin >> firstOperand;
    std::cout << "operation = "; std::cin >> operation;
    std::cout << "secondOperand = "; std::cin >> secondOperand;
    std::cout << "result = "; std::cin >> result;

    RebusSolver rebus(firstOperand, operation, secondOperand, result);
    rebus.solveRebus();
    rebus.showResults();
}