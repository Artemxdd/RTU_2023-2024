#include <iostream>
#include <vector>
#include <string>

typedef std::vector<int> digits;

int countLength(const digits& digits) {
    int length{ 0 };

    while (digits[length] >= 0) length++;

    return length;
}

std::string toString(const digits& digits) {
    std::string result{ "" };

    for (int index{ countLength(digits) - 1 }; index >= 0; index--) {
        result += digits[index] + '0';

        if (index % 3 == 0 && index != 0) result += ' ';

    }

    return result;
}

void fromString(const std::string& string, digits& digits) {
    int indexOfDigits = 0;

    for (int indexOfString = string.length() - 1; indexOfString >= 0; indexOfString--) {
        if (string[indexOfString] == ' ') continue;
        digits[indexOfDigits++] = string[indexOfString] - '0';
    }

    digits[indexOfDigits] = -1;
}

int compareNumbers(const digits& firstNumber, const digits& secondNumber) {
    int lengthA{ countLength(firstNumber) }, lengthB{ countLength(secondNumber) };

    if (lengthA > lengthB) return 1;
    else if (lengthA < lengthB) return -1;
    else {

        for (int index{ lengthA - 1 }; index >= 0; index--) {

            if (firstNumber[index] > secondNumber[index]) return 1;
            else if (firstNumber[index] < secondNumber[index]) return -1;

        }

        return 0;
    }
}

digits multiplyTenPow(digits number, const int& exponent) {

    if (exponent == 0) return number;

    int sizeOfNumber{ countLength(number) },
        sizeOfProduct{ sizeOfNumber + exponent + 1 };

    for (int index{ sizeOfNumber - 1 }; index >= 0; index--) 
        number[index + exponent] = number[index];

    for (int index{ 0 }; index < exponent; index++)
        number[index] = 0;

    number[sizeOfProduct - 1] = -1;

    return number;
}

digits countProduct(const digits& multiplicand, const int& multiplier);

int countNumberOfSubtractions(const digits& minuend, const digits& subtrahend) {
    int numberOfSubtractions{ 1 };
    digits copyOfSubtrahend{ subtrahend };

    while (compareNumbers(minuend, copyOfSubtrahend) >= 0) {
        if (compareNumbers(minuend, copyOfSubtrahend) == 0) {
            numberOfSubtractions++;
            break;
        }
        copyOfSubtrahend = countProduct(subtrahend, numberOfSubtractions++);
    }

    numberOfSubtractions -= 2;
    return numberOfSubtractions;
}

digits countSum(digits firstSummand, digits secondSummand) {
    int sizeOfFirstSummand{ countLength(firstSummand) },
        sizeOfSecondSummand{ countLength(secondSummand) },
        sizeOfSum{ 0 },
        biggerNumber{ compareNumbers(firstSummand, secondSummand) };

    if (biggerNumber == 1) { 
        secondSummand[sizeOfSecondSummand] = 0;
        sizeOfSum = sizeOfFirstSummand + 1; 
    }
    else if (biggerNumber == -1) { 
        firstSummand[sizeOfFirstSummand] = 0;
        sizeOfSum = sizeOfSecondSummand + 1; 
    }
    else sizeOfSum = sizeOfFirstSummand + 1;

    digits localSum(sizeOfSum + 1);
    localSum[sizeOfSum] = 0;

    for (int index{ 0 }; index < sizeOfSum; index++) {
        localSum[index] += firstSummand[index] + secondSummand[index];
        localSum[index + 1] += (localSum[index] / 10);
        localSum[index] %= 10;
    }

    localSum[sizeOfSum - 1] = -1;

    return localSum;
}

digits countDifference(digits minuend, digits subtrahend) {
    int sizeOfMinuend{ countLength(minuend) },
        sizeOfSubtrahend{ countLength(subtrahend) },
        numberOfZeros{ 0 };

    subtrahend[sizeOfSubtrahend] = 0;

    for (int index{ 0 }; index < sizeOfMinuend; index++) {

        if (minuend[index] - subtrahend[index] >= 0) minuend[index] = minuend[index] - subtrahend[index];
        else {

            if (minuend[index + 1] == 0) {
                numberOfZeros = 1;

                while (minuend[index + numberOfZeros] == 0) minuend[index + numberOfZeros++] = 9;

                minuend[index + numberOfZeros]--;
            }
            else minuend[index + 1]--;

            minuend[index] = 10 + minuend[index] - subtrahend[index];
        }

    }

    while (minuend[sizeOfMinuend - 1] == 0) {
        if (sizeOfMinuend == 1) break;
        sizeOfMinuend--;
    }

    minuend[sizeOfMinuend] = -1;

    return minuend;
}

digits countProduct(const digits& multiplicand, const int& multiplier) {
    digits product(1001);
    product[0] = 1;
    product[1] = -1;
    int carry{ 0 }, currentDigitIndex{ 0 };

    for (currentDigitIndex; multiplicand[currentDigitIndex] >= 0; currentDigitIndex++) {
        product[currentDigitIndex] = multiplicand[currentDigitIndex] * multiplier + carry;
        carry = product[currentDigitIndex] / 10;
        product[currentDigitIndex] %= 10;
    }

    while (carry) {
        product[currentDigitIndex++] = carry % 10;
        carry /= 10;
    }

    product[currentDigitIndex] = -1;

    return product;
}

digits countProduct(const digits& multiplicand, const digits& multiplier) {
    int sizeOfMultiplier{ countLength(multiplier) },
        sizeOfProduct{ countLength(multiplicand) + sizeOfMultiplier },
        exponentOf10{ sizeOfMultiplier - 1 };
    digits sum(1001), localProduct(sizeOfProduct);
    sum[0] = -1;

    for (int index{ sizeOfMultiplier - 1 }; index >= 0; index--) {
        localProduct = countProduct(multiplicand, multiplier[index]);
        localProduct = multiplyTenPow(localProduct, exponentOf10--);
        sum = countSum(sum, localProduct);
    }

    return sum;
}

digits countQuotient(digits dividend, const digits& divisor, digits& remainder) {
    digits copyOfDivisor(1001), localQuotient(1001);
    int exponentOf10{ countLength(dividend) - countLength(divisor) - 1 }, indexOfQuotient{ exponentOf10 }, indexOfMinus1{ exponentOf10 + 1 };

    while (exponentOf10 >= 0) {
        copyOfDivisor = multiplyTenPow(divisor, exponentOf10--);
        localQuotient[indexOfQuotient] = countNumberOfSubtractions(dividend, copyOfDivisor);
        dividend = countDifference(dividend, countProduct(copyOfDivisor, localQuotient[indexOfQuotient--]));
    }

    localQuotient[indexOfMinus1] = -1;
    remainder = dividend;

    int sizeOfQuotient{ countLength(localQuotient) };
    localQuotient[indexOfMinus1] = 0;

    for (int index{ 0 }; index < sizeOfQuotient; index++) {
        localQuotient[index + 1] += localQuotient[index] / 10;
        localQuotient[index] %= 10;
    }

    while (localQuotient[sizeOfQuotient] == 0) sizeOfQuotient--;

    localQuotient[sizeOfQuotient + 1] = -1;
    return localQuotient;
}

int main() {
    std::string numberOne{ "" }, numberTwo{ "" };
    std::cout << "Number 1 = ";
    std::getline(std::cin, numberOne);
    std::cout << "Number 2 = ";
    std::getline(std::cin, numberTwo);
    std::cout << "\n";

    digits firstNumber(1001), secondNumber(1001), sum(1001), difference(1001), product(1001), quotient(1001), remainder(1001);
    sum[0] = -1, difference[0] = -1, product[0] = 1, product[1] = -1, quotient[0] = -1, remainder[0] = -1;

    fromString(numberOne, firstNumber);
    fromString(numberTwo, secondNumber);

    sum = countSum(firstNumber, secondNumber);
    difference = countDifference(firstNumber, secondNumber);
    product = countProduct(firstNumber, secondNumber);
    quotient = countQuotient(firstNumber, secondNumber, remainder);

    std::cout << "Sum: " << toString(sum) << "\n";
    std::cout << "Difference: " << toString(difference) << "\n";
    std::cout << "Product: " << toString(product) << "\n";
    std::cout << "Quotient: " << toString(quotient) << " : " << toString(remainder) << "\n";
}