#include <iostream>
#include <string>

unsigned int calculateSumOfDigits(const std::string& str) {
    unsigned int sumOfDigits = 0;

    for (const char& currentChar : str) {

        if (isdigit(currentChar)) sumOfDigits += currentChar - '0';

    }

    return sumOfDigits;
}

void reduceNumbersTo3Digits(std::string& str) {
    unsigned int numberOfDigitsInNumber = 0;

    for (char& currentChar : str) {

        if (numberOfDigitsInNumber == 3) {

            if (isdigit(currentChar)) currentChar = ' ';
            else numberOfDigitsInNumber = 0;

        } else {

            if (isdigit(currentChar)) numberOfDigitsInNumber++;
            else numberOfDigitsInNumber = 0;

        }

    }
}

unsigned int countAmountOfNumbers(const std::string& str) {
    unsigned int amountOfNumbers = 0;

    for (unsigned int index = 0; str[index]; index++) {

        if (isdigit(str[index]) && !isdigit(str[index + 1])) amountOfNumbers++;

    }

    return amountOfNumbers;
}

unsigned int calculateSumOfNumbers(const std::string& str) {
    unsigned int sumOfNumbers = 0, numberOfDigitsInNumber = 0,
        firstDigit = 0, secondDigit = 0, thirdDigit = 0;

    for (unsigned int index = 0; str[index]; index++) {

        if (isdigit(str[index])) {
            numberOfDigitsInNumber++; 

            if (numberOfDigitsInNumber == 1) firstDigit = str[index] - '0';
            else if (numberOfDigitsInNumber == 2) secondDigit = str[index] - '0';
            else thirdDigit = str[index] - '0';

            if (str[index + 1] == 0) {

                if (numberOfDigitsInNumber == 1) sumOfNumbers += firstDigit;
                else if (numberOfDigitsInNumber == 2) sumOfNumbers += firstDigit * 10 + secondDigit;
                else sumOfNumbers += firstDigit * 100 + secondDigit * 10 + thirdDigit;

            }
        }

        if (!isdigit(str[index])) {

            if (numberOfDigitsInNumber == 1) sumOfNumbers += firstDigit;
            else if (numberOfDigitsInNumber == 2) sumOfNumbers += firstDigit * 10 + secondDigit;
            else if (numberOfDigitsInNumber == 3) sumOfNumbers += firstDigit * 100 + secondDigit * 10 + thirdDigit;

            firstDigit = 0, secondDigit = 0, thirdDigit = 0, numberOfDigitsInNumber = 0;
        }

    }

    return sumOfNumbers;
}

int main() {
    std::string str = "";
    std::cout << "Enter string! String = ";
    std::getline(std::cin, str);

    std::cout << "Sum of digits: " << calculateSumOfDigits(str) << "\n";
    reduceNumbersTo3Digits(str);
    std::cout << "Reduced numbers: " << str << "\n";
    std::cout << "Amount of numbers: " << countAmountOfNumbers(str) << "\n";
    std::cout << "Sum of numbers: " << calculateSumOfNumbers(str) << "\n";
}