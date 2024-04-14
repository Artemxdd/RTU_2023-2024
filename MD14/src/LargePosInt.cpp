#include "LargePosInt.h"

std::string LargePosInt::toString() {
    return toString(getLargePositiveInt());
}

std::vector<int> LargePosInt::getLargePositiveInt() {
    return largePositiveInt;
}

void LargePosInt::setLargePositiveInt(const std::string& number) {
    this->largePositiveInt = fromString(number);
}

std::vector<int> LargePosInt::addZerosToEnd(std::vector<int> number, int numberOfZeros) {

    if (numberOfZeros == 0) return number;

    while (numberOfZeros > 0) {
        number.push_back(0);
        numberOfZeros--;
    }

    return number;
}

std::vector<int> LargePosInt::addZerosToBeginning(std::vector<int> number, int numberOfZeros) {

    if (numberOfZeros == 0) return number;

    while (numberOfZeros > 0) {
        number.insert(number.begin(), 0);
        numberOfZeros--;
    }

    return number;
}

std::vector<int> LargePosInt::deleteZerosFromBeginning(std::vector<int> number) {

    if (number.empty() || number[0] != 0) return number;
    else {
        int numberOfZeros{ 0 };

        for (auto digit{ number.begin() }; digit < number.end(); digit++) {

            if (*digit == 0) numberOfZeros++;
            else break;

        }

        number.erase(number.begin(), number.begin() + numberOfZeros);

        return number;
    }
}

int LargePosInt::compareNumbers(const std::string& firstNumber, const std::string& secondNumber) {
    bool isFirstNumberZero{ true }, isSecondNumberZero{ true };

    for (auto currentChar : firstNumber) if (currentChar != '0') isFirstNumberZero = false;
    for (auto currentChar : secondNumber) if (currentChar != '0') isSecondNumberZero = false;

    if (isFirstNumberZero && isSecondNumberZero) return 0;
    else if (isFirstNumberZero && !isSecondNumberZero) return -1;
    else if (!isFirstNumberZero && isSecondNumberZero) return 1;

    if (firstNumber.size() > secondNumber.size()) return 1;
    else if (firstNumber.size() < secondNumber.size()) return -1;
    else {

        for (int index{ 0 }; index < firstNumber.size(); index++) {

            if (isdigit(firstNumber[index]) && isdigit(secondNumber[index])) {

                if (firstNumber[index] > secondNumber[index]) return 1;
                else if (firstNumber[index] < secondNumber[index]) return -1;

            }

        }

        return 0;
    }
}

std::vector<int> LargePosInt::distributeNumberAcrossCells(std::vector<int> number) {
    for (int index{ 0 }; index < number.size(); index++) {

        if (number[index] > 9) {
            number.insert(number.begin() + index + 1, number[index] % 10);
            number[index] /= 10;
        }

    }

    return number;
}

int LargePosInt::countNumberOfSubtractions(std::vector<int> minuend, const std::vector<int>& subtrahend) {
    int numberOfSubtractions{ 0 };

    while (compareNumbers(toString(minuend), toString(subtrahend)) >= 0) {

        if (compareNumbers(toString(minuend), toString(subtrahend)) == 0) {
            numberOfSubtractions++;
            break;
        }

        minuend = fromString(calculateDifferenceOfTwoNumbers(toString(minuend), toString(subtrahend)));
        numberOfSubtractions++;
    }

    return numberOfSubtractions;
}

std::string LargePosInt::calculateSumOfTwoNumbers(const std::string& firstSummand, const std::string& secondSummand) {
    std::string copyOfFirstSummand{ firstSummand }, copyOfSecondSummand{ secondSummand };
    std::vector<int> summand1{ fromString(copyOfFirstSummand) }, summand2{ fromString(copyOfSecondSummand) }, sum;
    int biggerNumber{ compareNumbers(toString(summand1), toString(summand2)) };

    if (biggerNumber == 1)
        summand2 = addZerosToBeginning(summand2, summand1.size() - summand2.size());
    else if (biggerNumber == -1)
        summand1 = addZerosToBeginning(summand1, summand2.size() - summand1.size());

    int carry{ 0 };

    for (auto index{ summand1.size() - 1 }; index >= 0 && index <= summand1.size() - 1; index--) {
        sum.insert(sum.begin(), (summand1[index] + summand2[index] + carry) % 10);
        carry = (summand1[index] + summand2[index] + carry) / 10;
    }

    if (carry != 0) sum.insert(sum.begin(), carry);

    return toString(sum);
}

std::string LargePosInt::calculateDifferenceOfTwoNumbers(const std::string& minuend, const std::string& subtrahend) {
    int biggerNumber{ compareNumbers(minuend, subtrahend) };

    if (biggerNumber == 0) return "0";

    std::vector<int> copyOfMinuend, copyOfSubtrahend, difference;

    if (biggerNumber == 1) {
        copyOfMinuend = fromString(minuend);
        copyOfSubtrahend = fromString(subtrahend);
    }
    else {
        copyOfMinuend = fromString(subtrahend);
        copyOfSubtrahend = fromString(minuend);
    }

    int numberOfZeros{ 0 };

    copyOfSubtrahend = addZerosToBeginning(copyOfSubtrahend, copyOfMinuend.size() - copyOfSubtrahend.size());

    for (auto index{ copyOfMinuend.size() - 1 }; index >= 0 && index <= copyOfMinuend.size() - 1; index--) {

        if (copyOfMinuend[index] - copyOfSubtrahend[index] >= 0)
            difference.insert(difference.begin(), copyOfMinuend[index] - copyOfSubtrahend[index]);
        else {

            if (copyOfMinuend[index - 1] == 0) {
                numberOfZeros = 1;

                while (copyOfMinuend[index - numberOfZeros] == 0) copyOfMinuend[index - numberOfZeros++] = 9;

                copyOfMinuend[index - numberOfZeros]--;
            }
            else copyOfMinuend[index - 1]--;

            difference.insert(difference.begin(), 10 + copyOfMinuend[index] - copyOfSubtrahend[index]);
        }

    }

    return toString(difference);
}

std::string LargePosInt::calculateProductOfTwoNumbers(const std::vector<int>& multiplicand, const int& multiplier) {
    std::vector<int> product;
    int carry{ 0 };

    for (auto digit{ multiplicand.rbegin() }; digit < multiplicand.rend(); digit++) {
        product.insert(product.begin(), (*digit * multiplier + carry) % 10);
        carry = (*digit * multiplier + carry) / 10;
    }

    while (carry) {
        product.insert(product.begin(), carry % 10);
        carry /= 10;
    }

    return toString(product);
}

std::string LargePosInt::calculateProductOfTwoNumbers(const std::string& multiplicand, const std::string& multiplier) {

    if ((multiplicand.size() == 1) && (multiplicand[0] == 0)) return "0";

    std::vector<int> copyOfMultiplicand{ fromString(multiplicand) },
        copyOfMultiplier{ fromString(multiplier) },
        sum, product;
    auto numberOfZeros{ copyOfMultiplier.size() - 1 };

    for (auto digit{ copyOfMultiplier.begin() }; digit < copyOfMultiplier.end(); digit++) {
        product = fromString(calculateProductOfTwoNumbers(copyOfMultiplicand, *digit));
        product = addZerosToEnd(product, numberOfZeros--);
        sum = fromString(calculateSumOfTwoNumbers(toString(product), toString(sum)));
    }

    return toString(sum);
}

std::string LargePosInt::calculateQuotientOfTwoNumbers(const std::string& dividend, const std::string& divisor) {
    std::vector<int> copyOfDivisor1, copyOfDivisor2{ fromString(divisor) },
        quotient, copyOfDividend{ fromString(dividend) };
    auto numberOfZeros{ 0 };
    int numberOfSubtractions{ 0 }, numberOfZerosAtBeginning{ 0 };

    if ((copyOfDivisor1.size() == 1) && (copyOfDivisor1[0] == 0)) return toString(copyOfDividend);

    for (auto digit : copyOfDividend) {

        if (digit != 0) break;

        numberOfZerosAtBeginning++;
    }

    copyOfDividend = deleteZerosFromBeginning(copyOfDividend);

    if (copyOfDividend.size() != copyOfDivisor1.size()) numberOfZeros = copyOfDividend.size() - copyOfDivisor1.size() - 1;

    while (numberOfZeros >= 0) {
        copyOfDivisor1 = addZerosToEnd(copyOfDivisor2, numberOfZeros);
        numberOfSubtractions = countNumberOfSubtractions(copyOfDividend, copyOfDivisor1);
        quotient.push_back(numberOfSubtractions);

        if (numberOfSubtractions > 9) quotient = distributeNumberAcrossCells(quotient);

        copyOfDividend = fromString(calculateDifferenceOfTwoNumbers(toString(copyOfDividend), calculateProductOfTwoNumbers(copyOfDivisor1, numberOfSubtractions)));

        if (numberOfZeros == 0) break;
        numberOfZeros--;
    }

    quotient = addZerosToBeginning(quotient, numberOfZerosAtBeginning);

    return toString(quotient);
}

LargePosInt::LargePosInt(const std::string& numberAsString) {
    setLargePositiveInt(numberAsString);
}

std::vector<int> LargePosInt::fromString(const std::string& numberAsString) {
    std::vector<int> number;

    for (const char& currentChar : numberAsString) {

        if (std::isdigit(currentChar)) number.push_back(currentChar - '0');
        else if (currentChar == '.') number.push_back(-1);

    }

    return number;
}

std::string LargePosInt::toString(const std::vector<int>& number) {
    std::string numberAsString{ "" };

    for (auto currentInt : number) {

        if (currentInt >= 0 && currentInt <= 9) numberAsString += currentInt + '0';
        else if (currentInt == -1) numberAsString += currentInt + '/';

    }

    return numberAsString;
}

void LargePosInt::operator=(const std::string& numberAsString) {
    setLargePositiveInt(numberAsString);
}

LargePosInt LargePosInt::operator+(const LargePosInt& largePosInt) {
    LargePosInt temporaryLargePosInt{ calculateSumOfTwoNumbers(toString(getLargePositiveInt()),
        toString(largePosInt.largePositiveInt)) };
    return temporaryLargePosInt;
}

LargePosInt LargePosInt::operator-(const LargePosInt& largePosInt) {
    LargePosInt temporaryLargePosInt{ calculateDifferenceOfTwoNumbers(toString(getLargePositiveInt()),
        toString(largePosInt.largePositiveInt)) };
    return temporaryLargePosInt;
}

LargePosInt LargePosInt::operator*(const LargePosInt& largePosInt) {
    LargePosInt temporaryLargePosInt{ calculateProductOfTwoNumbers(toString(getLargePositiveInt()),
        toString(largePosInt.largePositiveInt)) };
    return temporaryLargePosInt;
}

LargePosInt LargePosInt::operator/(const LargePosInt& largePosInt) {
    LargePosInt temporaryLargePosInt{ calculateQuotientOfTwoNumbers(toString(getLargePositiveInt()),
        toString(largePosInt.largePositiveInt)) };
    return temporaryLargePosInt;
}

bool LargePosInt::operator==(const LargePosInt& largePosInt) {

    if (compareNumbers(toString(getLargePositiveInt()), 
        toString(largePosInt.largePositiveInt)) == 0) return true;

    return false;

}

bool LargePosInt::operator>(const LargePosInt& largePosInt) {
    
    if (compareNumbers(toString(getLargePositiveInt()),
        toString(largePosInt.largePositiveInt)) == 1) return true;

    return false;

}

bool LargePosInt::operator<(const LargePosInt& largePosInt) {
    
    if (compareNumbers(toString(getLargePositiveInt()),
        toString(largePosInt.largePositiveInt)) == -1) return true;

    return false;

}