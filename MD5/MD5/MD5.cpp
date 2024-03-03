#include <iostream>

using namespace std;

void printFibonacciNumbers(int amountOfNumbers, int currentNumber = 1, int previousNumber = 0, int previousNumberOfPreviousNumber = 0) {

    if (amountOfNumbers < 1) return;

    cout << currentNumber << "\t";
    printFibonacciNumbers(amountOfNumbers - 1, previousNumber + currentNumber, currentNumber, previousNumber);
}

int getFibonacciNumber(int number, int currentNumber = 1, int previousNumber = 0, int previousNumberOfPreviousNumber = 0) {
    
    if (number <= 1) return currentNumber;

    getFibonacciNumber(number - 1, previousNumber + currentNumber, currentNumber, previousNumber);
}

int getSumOfDigits(int number, int sum = 0) {

    if (number <= 0) return sum;

    getSumOfDigits(number / 10, sum += number % 10);
}

int isNumberEqualsTo2OfPower(const int number, int power = 0) {

    if (pow(2, power) == number) return power;
    if (pow(2, power) > number) return -1;

    isNumberEqualsTo2OfPower(number, power + 1);
}

int main() {
    cout << "1.\t"; printFibonacciNumbers(10); cout << endl;
    cout << "2.\t" << getFibonacciNumber(6) << endl;
    cout << "3.\t" << getSumOfDigits(258) << endl;

    int isNumberEqualsTo2OfPowerFunctionResult = isNumberEqualsTo2OfPower(256);
    cout << "4.\t";

    if (isNumberEqualsTo2OfPowerFunctionResult > 0) cout << isNumberEqualsTo2OfPowerFunctionResult;
    else cout << "There is no power of 2 to get this number";
}