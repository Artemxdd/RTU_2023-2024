#include "LargeUnsignedInt.h"

void LargeUnsignedInt::setValue(std::string number) {
    largeValue temporaryNumber;

    if (number.size() == 0) {
        temporaryNumber.push_back(0);
        this->value = temporaryNumber;
    }

    // Remove characters which are not digits
    for (std::string::iterator it = number.begin(); it != number.end(); it++)
        if (std::isdigit(*it))
            temporaryNumber.push_back(*it - '0');

    int indexOfFirstDigit{ 0 };

    for (int index{ 0 }; index < temporaryNumber.size(); index++) {

        if (temporaryNumber[index] != 0) {
            indexOfFirstDigit = index;
            break;
        }
        else if (index == (temporaryNumber.size() - 1)) indexOfFirstDigit = index;

    }

    // Removing unnecessary zeros
    temporaryNumber.erase(temporaryNumber.begin(), temporaryNumber.begin() + indexOfFirstDigit);
    this->value = temporaryNumber;
}

largeValue LargeUnsignedInt::addZerosToEnd(largeValue number, int numberOfZeros) {

    if (numberOfZeros == 0) return number;

    while (numberOfZeros > 0) {
        number.push_back(0);
        numberOfZeros--;
    }

    return number;
}

largeValue LargeUnsignedInt::addZerosToBeginning(largeValue number, int numberOfZeros) {

    if (numberOfZeros == 0) return number;

    while (numberOfZeros > 0) {
        number.insert(number.begin(), 0);
        numberOfZeros--;
    }

    return number;
}

largeValue LargeUnsignedInt::deleteZerosFromBeginning(largeValue number) {

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

int LargeUnsignedInt::compareNumbers(const std::string& firstNumber, const std::string& secondNumber) {
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

largeValue LargeUnsignedInt::distributeNumberAcrossCells(largeValue number) {

    for (int index{ 0 }; index < number.size(); index++) {

        if (number[index] > 9) {
            number.insert(number.begin() + index + 1, number[index] % 10);
            number[index] /= 10;
        }

    }

    return number;
}

int LargeUnsignedInt::countNumberOfSubtractions(largeValue minuend, const largeValue& subtrahend) {
    int numberOfSubtractions{ 0 };

    while (compareNumbers(toString(minuend), toString(subtrahend)) >= 0) {

        if (compareNumbers(toString(minuend), toString(subtrahend)) == 0) {
            numberOfSubtractions++;
            break;
        }

        minuend = fromString(calculateDifference(toString(minuend), toString(subtrahend)));
        numberOfSubtractions++;
    }

    return numberOfSubtractions;
}

std::string LargeUnsignedInt::calculateSum(const std::string& firstSummand, const std::string& secondSummand) {
    largeValue summand1{ fromString(firstSummand) }, summand2{ fromString(secondSummand) }, sum;
    int biggerNumber{ compareNumbers(toString(summand1), toString(summand2)) };

    if (biggerNumber == 1) summand2 = addZerosToBeginning(summand2, summand1.size() - summand2.size());
    else if (biggerNumber == -1) summand1 = addZerosToBeginning(summand1, summand2.size() - summand1.size());

    int carry{ 0 };

    for (auto index{ summand1.size() - 1 }; index >= 0 && index <= summand1.size() - 1; index--) {
        sum.insert(sum.begin(), (summand1[index] + summand2[index] + carry) % 10);
        carry = (summand1[index] + summand2[index] + carry) / 10;
    }

    if (carry != 0) sum.insert(sum.begin(), carry);

    return toString(sum);
}

std::string LargeUnsignedInt::calculateDifference(const std::string& minuend, const std::string& subtrahend) {
    int biggerNumber{ compareNumbers(minuend, subtrahend) };

    if ((biggerNumber == 0) || (biggerNumber == -1)) return "0";

    largeValue copyOfMinuend{ fromString(minuend) }, copyOfSubtrahend{ fromString(subtrahend) }, difference;
    copyOfSubtrahend = addZerosToBeginning(copyOfSubtrahend, copyOfMinuend.size() - copyOfSubtrahend.size());

    int numberOfZeros{ 0 };

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

    return toString(deleteZerosFromBeginning(difference));
}

std::string LargeUnsignedInt::calculateProduct(const largeValue& multiplicand, const int& multiplier) {
    largeValue product;
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

std::string LargeUnsignedInt::calculateProduct(const std::string& multiplicand, const std::string& multiplier) {

    if ((multiplicand[0] == '0') || (multiplier[0] == '0')) return "0";

    largeValue copyOfMultiplicand{ fromString(multiplicand) },
        copyOfMultiplier{ fromString(multiplier) },
        sum{ 0 }, product;
    auto numberOfZeros{ copyOfMultiplier.size() - 1 };

    for (auto digit{ copyOfMultiplier.begin() }; digit < copyOfMultiplier.end(); digit++) {
        product = fromString(calculateProduct(copyOfMultiplicand, *digit));
        product = addZerosToEnd(product, numberOfZeros--);
        sum = fromString(calculateSum(toString(product), toString(sum)));
    }

    return toString(sum);
}

std::string LargeUnsignedInt::calculateQuotient(const std::string& dividend, const std::string& divisor) {

    if ((dividend[0] == '0') || (divisor[0] == '0')) return "0";
    else if (compareNumbers(dividend, divisor) == 0) return "1";

    largeValue copyOfDivisor1, copyOfDivisor2{ fromString(divisor) },
        quotient, copyOfDividend{ fromString(dividend) };
    auto numberOfZeros{ 0 };
    int numberOfSubtractions{ 0 };

    if (copyOfDividend.size() != copyOfDivisor1.size()) numberOfZeros = copyOfDividend.size() - copyOfDivisor1.size() - 1;

    while (numberOfZeros >= 0) {
        copyOfDivisor1 = addZerosToEnd(copyOfDivisor2, numberOfZeros);
        numberOfSubtractions = countNumberOfSubtractions(copyOfDividend, copyOfDivisor1);
        quotient.push_back(numberOfSubtractions);

        if (numberOfSubtractions > 9) quotient = distributeNumberAcrossCells(quotient);

        copyOfDividend = fromString(calculateDifference(toString(copyOfDividend), calculateProduct(copyOfDivisor1, numberOfSubtractions)));

        if (numberOfZeros == 0) break;
        numberOfZeros--;
    }

    return toString(quotient);
}

largeValue LargeUnsignedInt::fromString(const std::string& numberAsString) {
    largeValue number;

    for (const char& currentChar : numberAsString)
        if (std::isdigit(currentChar))
            number.push_back(currentChar - '0');

    return number;
}

std::string LargeUnsignedInt::toString(const largeValue& number) {
    std::string numberAsString{ "" };

    for (const int& currentInt : number)
        if (currentInt >= 0 && currentInt <= 9)
            numberAsString += currentInt + '0';

    return numberAsString;
}

LargeUnsignedInt::LargeUnsignedInt(const std::string& numberAsString) {
    setValue(numberAsString);
}

std::string LargeUnsignedInt::toString() {
    return toString(this->value);
}

void LargeUnsignedInt::operator=(const std::string& numberAsString) {
    setValue(numberAsString);
}

LargeUnsignedInt LargeUnsignedInt::operator+(const LargeUnsignedInt& largeUnsignedInt) {
    LargeUnsignedInt temporaryLargePosInt{ calculateSum(toString(this->value),
        toString(largeUnsignedInt.value)) };
    return temporaryLargePosInt;
}

LargeUnsignedInt LargeUnsignedInt::operator-(const LargeUnsignedInt& largeUnsignedInt) {
    LargeUnsignedInt temporaryLargePosInt{ calculateDifference(toString(this->value),
        toString(largeUnsignedInt.value)) };
    return temporaryLargePosInt;
}

LargeUnsignedInt LargeUnsignedInt::operator*(const LargeUnsignedInt& largeUnsignedInt) {
    LargeUnsignedInt temporaryLargePosInt{ calculateProduct(toString(this->value),
        toString(largeUnsignedInt.value)) };
    return temporaryLargePosInt;
}

LargeUnsignedInt LargeUnsignedInt::operator/(const LargeUnsignedInt& largeUnsignedInt) {
    LargeUnsignedInt temporaryLargePosInt{ calculateQuotient(toString(this->value),
        toString(largeUnsignedInt.value)) };
    return temporaryLargePosInt;
}

bool LargeUnsignedInt::operator==(const LargeUnsignedInt& largeUnsignedInt) {

    if (compareNumbers(toString(this->value),
        toString(largeUnsignedInt.value)) == 0) return true;

    return false;

}

bool LargeUnsignedInt::operator>(const LargeUnsignedInt& largeUnsignedInt) {

    if (compareNumbers(toString(this->value),
        toString(largeUnsignedInt.value)) == 1) return true;

    return false;

}

bool LargeUnsignedInt::operator<(const LargeUnsignedInt& largeUnsignedInt) {

    if (compareNumbers(toString(this->value),
        toString(largeUnsignedInt.value)) == -1) return true;

    return false;

}