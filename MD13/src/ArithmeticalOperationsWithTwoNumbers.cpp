#include "ArithmeticalOperationsWithTwoNumbers.h"

ArithmeticalOperationsWithTwoNumbers::ArithmeticalOperationsWithTwoNumbers(std::string numberOne, std::string numberTwo) {
    firstNumber.reserve(SIZE_OF_VECTOR);
    secondNumber.reserve(SIZE_OF_VECTOR);
    sum.reserve(SIZE_OF_VECTOR);
    difference.reserve(SIZE_OF_VECTOR);
    product.reserve(SIZE_OF_VECTOR);
    quotient.reserve(SIZE_OF_VECTOR);
    remainderOfQuotient.reserve(SIZE_OF_VECTOR);
    decimalQuotient.reserve(SIZE_OF_VECTOR);

    firstNumber = fromString(numberOne);
    secondNumber = fromString(numberTwo);
    //sum = countSum(firstNumber, secondNumber);
    //product = countProduct(firstNumber, secondNumber);
    //quotient = countQuotient(firstNumber, secondNumber, remainderOfQuotient);
    //decimalQuotient = countDecimalQuotient(firstNumber, secondNumber);

    //if (compareNumbers(firstNumber, secondNumber) == 1) {
    //    difference = countDifference(firstNumber, secondNumber);
    //}
}

std::string ArithmeticalOperationsWithTwoNumbers::getSumAsString() {
    return toString(countSum(firstNumber, secondNumber));
}

std::string ArithmeticalOperationsWithTwoNumbers::getDifferenceAsString() {

    if (compareNumbers(firstNumber, secondNumber) == 1) return toString(countDifference(firstNumber, secondNumber));
    
    return "";
}

std::string ArithmeticalOperationsWithTwoNumbers::getProductAsString() {
    return toString(countProduct(firstNumber, secondNumber));
}

std::string ArithmeticalOperationsWithTwoNumbers::getQuotientAsString() {
    largeNumber remainder;
    largeNumber quotient{ countQuotient(firstNumber, secondNumber, remainder) };

    if (remainder.size() == 0) return toString(quotient);

    return "";
}

void ArithmeticalOperationsWithTwoNumbers::showAllInfo() {

    if (compareNumbers(firstNumber, secondNumber) >= 0) {
        std::cout << "First number = " << toString(firstNumber) << "\n" <<
            "Second number = " << toString(secondNumber) << "\n" <<
            "Sum = " << toString(sum) << "\n" <<
            "Difference = " << toString(difference) << "\n" <<
            "Product = " << toString(product) << "\n";

        if (remainderOfQuotient.empty()) std::cout << "Quotient = " << toString(quotient) << "\n";
        else std::cout << "Quotient = " << toString(quotient) << ":" << toString(remainderOfQuotient) << "\n";

        std::cout << "Decimal quotient = " << toString(decimalQuotient) << "\n";
    }
    else {
        std::cout << "First number = " << toString(firstNumber) << "\n" <<
            "Second number = " << toString(secondNumber) << "\n" <<
            "Sum = " << toString(sum) << "\n" <<
            "Difference = First number should be bigger than second number\n" <<
            "Product = " << toString(product) << "\n" <<
            "Quotient = First number should be bigger than second number\n" <<
            "Decimal quotient = First number should be bigger than second number\n";
    }

}

largeNumber ArithmeticalOperationsWithTwoNumbers::fromString(const std::string& string) {
    largeNumber number;
    number.reserve(SIZE_OF_VECTOR);

    for (const char& currentChar : string) {

        if (std::isdigit(currentChar)) number.push_back(currentChar - '0');

    }

    return number;
}

std::string ArithmeticalOperationsWithTwoNumbers::toString(const largeNumber& number) {
    std::string result{ "" };

    for (auto digit{ number.begin() }; digit < number.end(); digit++) {

        if (*digit == -1) result += ".";
        else result += *digit + '0';

    }

    return result;
}

int ArithmeticalOperationsWithTwoNumbers::compareNumbers(const largeNumber& firstNumber, const largeNumber& secondNumber) {

    if (firstNumber.size() > secondNumber.size()) return 1;
    else if (firstNumber.size() < secondNumber.size()) return -1;
    else {

        for (int index{ 0 }; index < firstNumber.size(); index++) {

            if (firstNumber[index] > secondNumber[index]) return 1;
            else if (firstNumber[index] < secondNumber[index]) return -1;

        }

        return 0;
    }
}

largeNumber ArithmeticalOperationsWithTwoNumbers::addZerosToBeginning(largeNumber number, int numberOfZeros) {

    if (numberOfZeros == 0) return number;

    while (numberOfZeros > 0) {
        number.insert(number.begin(), 0);
        numberOfZeros--;
    }

    return number;
}

largeNumber ArithmeticalOperationsWithTwoNumbers::addZerosToEnd(largeNumber number, int numberOfZeros) {

    if (numberOfZeros == 0) return number;

    while (numberOfZeros > 0) {
        number.push_back(0);
        numberOfZeros--;
    }

    return number;
}

largeNumber ArithmeticalOperationsWithTwoNumbers::deleteZerosFromBeginning(largeNumber number) {

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

largeNumber ArithmeticalOperationsWithTwoNumbers::distributeNumberAcrossCells(largeNumber number) {

    for (int index{ 0 }; index < number.size(); index++) {

        if (number[index] > 9) {
            number.insert(number.begin() + index + 1, number[index] % 10);
            number[index] /= 10;
        }

    }

    return number;
}

largeNumber ArithmeticalOperationsWithTwoNumbers::countSum(largeNumber firstNumber, largeNumber secondNumber) {
    largeNumber sum;
    sum.reserve(SIZE_OF_VECTOR);
    int biggerNumber{ compareNumbers(firstNumber, secondNumber) };

    if (biggerNumber == 1)
        secondNumber = addZerosToBeginning(secondNumber, firstNumber.size() - secondNumber.size());
    else if (biggerNumber == -1)
        firstNumber = addZerosToBeginning(firstNumber, secondNumber.size() - firstNumber.size());

    int carry{ 0 };

    for (auto index{ firstNumber.size() - 1 }; index >= 0 && index <= firstNumber.size() - 1; index--) {
        sum.insert(sum.begin(), (firstNumber[index] + secondNumber[index] + carry) % 10);
        carry = (firstNumber[index] + secondNumber[index] + carry) / 10;
    }

    if (carry != 0) sum.insert(sum.begin(), carry);

    return sum;
}

largeNumber ArithmeticalOperationsWithTwoNumbers::countDifference(largeNumber minuend, largeNumber subtrahend) {
    largeNumber difference;
    difference.reserve(SIZE_OF_VECTOR);
    int numberOfZeros{ 0 };

    subtrahend = addZerosToBeginning(subtrahend, minuend.size() - subtrahend.size());

    for (auto index{ minuend.size() - 1 }; index >= 0 && index <= minuend.size() - 1; index--) {

        if (minuend[index] - subtrahend[index] >= 0)
            difference.insert(difference.begin(), minuend[index] - subtrahend[index]);
        else {

            if (minuend[index - 1] == 0) {
                numberOfZeros = 1;

                while (minuend[index - numberOfZeros] == 0) minuend[index - numberOfZeros++] = 9;

                minuend[index - numberOfZeros]--;
            }
            else minuend[index - 1]--;

            difference.insert(difference.begin(), 10 + minuend[index] - subtrahend[index]);
        }

    }

    return deleteZerosFromBeginning(difference);
}

int ArithmeticalOperationsWithTwoNumbers::countNumberOfSubtractions(largeNumber minuend, const largeNumber& subtrahend) {
    int numberOfSubtractions{ 0 };

    while (compareNumbers(minuend, subtrahend) >= 0) {

        if (compareNumbers(minuend, subtrahend) == 0) {
            numberOfSubtractions++;
            break;
        }

        minuend = countDifference(minuend, subtrahend);
        numberOfSubtractions++;
    }

    return numberOfSubtractions;
}

largeNumber ArithmeticalOperationsWithTwoNumbers::countProduct(const largeNumber& multiplicand, const int& multiplier) {
    largeNumber product;
    product.reserve(SIZE_OF_VECTOR);
    int carry{ 0 };

    for (auto digit{ multiplicand.rbegin() }; digit < multiplicand.rend(); digit++) {
        product.insert(product.begin(), (*digit * multiplier + carry) % 10);
        carry = (*digit * multiplier + carry) / 10;
    }

    while (carry) {
        product.insert(product.begin(), carry % 10);
        carry /= 10;
    }

    return product;
}

largeNumber ArithmeticalOperationsWithTwoNumbers::countProduct(const largeNumber& multiplicand, const largeNumber& multiplier) {
    auto numberOfZeros{ multiplier.size() - 1 };
    largeNumber sum, product;
    sum.reserve(SIZE_OF_VECTOR);
    product.reserve(SIZE_OF_VECTOR);

    for (auto digit{ multiplier.begin() }; digit < multiplier.end(); digit++) {
        product = countProduct(multiplicand, *digit);
        product = addZerosToEnd(product, numberOfZeros--);
        sum = countSum(product, sum);
    }

    return sum;
}

largeNumber ArithmeticalOperationsWithTwoNumbers::countQuotient(largeNumber dividend, const largeNumber& divisor, largeNumber& remainder) {
    largeNumber copyOfDivisor, quotient;
    copyOfDivisor.reserve(SIZE_OF_VECTOR);
    quotient.reserve(SIZE_OF_VECTOR);
    auto numberOfZeros{ 0 };
    int numberOfSubtractions{ 0 }, numberOfZerosAtBeginning{ 0 };

    if ((divisor.size() == 1) && (divisor[0] == 0)) return dividend;

    for (auto digit : dividend) {

        if (digit != 0) break;

        numberOfZerosAtBeginning++;
    }

    dividend = deleteZerosFromBeginning(dividend);

    if (dividend.size() != divisor.size()) numberOfZeros = dividend.size() - divisor.size() - 1;

    while (numberOfZeros >= 0) {
        copyOfDivisor = addZerosToEnd(divisor, numberOfZeros);
        numberOfSubtractions = countNumberOfSubtractions(dividend, copyOfDivisor);
        quotient.push_back(numberOfSubtractions);

        if (numberOfSubtractions > 9) quotient = distributeNumberAcrossCells(quotient);

        dividend = countDifference(dividend, countProduct(copyOfDivisor, numberOfSubtractions));

        if (numberOfZeros == 0) break;
        numberOfZeros--;
    }

    remainder = dividend;
    quotient = addZerosToBeginning(quotient, numberOfZerosAtBeginning);

    return quotient;
}

largeNumber ArithmeticalOperationsWithTwoNumbers::countDecimalQuotient(const largeNumber& dividend, const largeNumber& divisor) {
    largeNumber quotient, remainderOfDivision;
    quotient.reserve(SIZE_OF_VECTOR);
    remainderOfDivision.reserve(SIZE_OF_VECTOR);
    quotient = countQuotient(dividend, divisor, remainderOfDivision);

    if (remainderOfDivision.empty()) return quotient;

    quotient.push_back(-1);
    int numberOfDigitsAfterDecimalPoint{ 1 }, numberOfSubtractions{ 0 };

    while (numberOfDigitsAfterDecimalPoint <= 50 && !remainderOfDivision.empty()) {
        remainderOfDivision = addZerosToEnd(remainderOfDivision, 1);
        numberOfSubtractions = countNumberOfSubtractions(remainderOfDivision, divisor);
        quotient.push_back(numberOfSubtractions);
        remainderOfDivision = countDifference(remainderOfDivision, countProduct(divisor, numberOfSubtractions));
        numberOfDigitsAfterDecimalPoint++;
    }

    return quotient;
}