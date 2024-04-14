#include <iostream>
#include <vector>

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

void multiply(digits& result, const int& multiplier) {
    int carry{ 0 }, currentDigitIndex{ 0 };

    for (currentDigitIndex; result[currentDigitIndex] >= 0; currentDigitIndex++) {
        result[currentDigitIndex] = result[currentDigitIndex] * multiplier + carry;
        carry = result[currentDigitIndex] / 10;
        result[currentDigitIndex] %= 10;
    }

    while (carry) {
        result[currentDigitIndex++] = carry % 10;
        carry /= 10;
    }

    result[currentDigitIndex] = -1;
}

void add(digits& result, const int& index, const int& firstSummand, const int& secondSummand) {
    result[index] += firstSummand + secondSummand;
    result[index + 1] += (result[index] / 10);
    result[index] %= 10;
}

void subtract(digits& result, digits& largerNumber, const int& lengthOfLargerNumber, const digits& smallerNumber) {

    for (int index{ 0 }; index < lengthOfLargerNumber; index++) {

        if (index < lengthOfLargerNumber - 1) {
            largerNumber[index + 1]--;
            result[index] += 10 + largerNumber[index];
        }
        else result[index] += largerNumber[index];

        result[index] -= smallerNumber[index];

        if (result[index] / 10 > 0) {
            result[index + 1]++;
            result[index] %= 10;
        }
    }

    result[lengthOfLargerNumber] = -1;
}

void countPower(digits& result, const int& base, const int& exponent) {
    result[0] = 1;
    result[1] = -1;

    for (int numberOfIteration{ 1 }; numberOfIteration <= exponent; numberOfIteration++) multiply(result, base);

}

void countFactorial(digits& result, int N) {
    result[0] = 1;
    result[1] = -1;

    for (int currentNumber{ 2 }; currentNumber <= N; currentNumber++) multiply(result, currentNumber);

}

void countSum(digits& result, const digits& powerOfThree, digits powerOfTwo) {
    int sizeOfPowerOfThree{ countLength(powerOfThree) },
        sizeOfPowerOfTwo{ countLength(powerOfTwo) },
        sizeOfResult{ sizeOfPowerOfThree + 1 };

    for (int index{ sizeOfPowerOfTwo }; index < sizeOfPowerOfThree; index++) powerOfTwo[index] = 0;

    for (int index{ 0 }; index < sizeOfResult; index++) add(result, index, powerOfThree[index], powerOfTwo[index]);

    result[sizeOfResult - 1] = -1;
}

void countDifference(digits& result, digits powerOfThree, digits powerOfTwo) {
    int sizeOfPowerOfThree{ countLength(powerOfThree) };

    for (int index{ countLength(powerOfTwo) }; index < sizeOfPowerOfThree; index++) powerOfTwo[index] = 0;

    powerOfTwo[sizeOfPowerOfThree] = -1;

    subtract(result, powerOfThree, sizeOfPowerOfThree, powerOfTwo);
}

void countProduct(digits& result, digits& powerOfThree, digits& powerOfTwo) {
    int sizeOfPowerOfThree{ countLength(powerOfThree) }, sizeOfPowerOfTwo{ countLength(powerOfTwo) },
        sizeOfResult{ sizeOfPowerOfThree + sizeOfPowerOfTwo };

    for (int index1{ 0 }; index1 < sizeOfPowerOfThree; index1++) {

        for (int index2{ 0 }; index2 < sizeOfPowerOfTwo; index2++)
            result[index1 + index2] += powerOfThree[index1] * powerOfTwo[index2];

    }

    for (int index{ 0 }; index < sizeOfResult - 1; index++) {
        result[index + 1] += result[index] / 10;
        result[index] %= 10;
    }

    while (result[sizeOfResult] == 0) sizeOfResult--;

    result[sizeOfResult + 1] = -1;
}

int main() {
    int N{ 1 }, sizeOfNumbers{ 10'000 };
    std::cout << "Enter N! N = ";
    std::cin >> N;
    std::cout << "\n\n";

    digits powerOfThree(sizeOfNumbers), powerOfTwo(sizeOfNumbers),
        factorial(sizeOfNumbers), sum(sizeOfNumbers), difference(sizeOfNumbers), product(sizeOfNumbers);

    countPower(powerOfThree, 3, N);
    countPower(powerOfTwo, 2, N);
    countFactorial(factorial, N);
    countSum(sum, powerOfThree, powerOfTwo);
    countDifference(difference, powerOfThree, powerOfTwo);
    countProduct(product, powerOfThree, powerOfTwo);

    std::cout << N << "! = " << toString(factorial) << "\n\n";
    std::cout << "3^" << N << " + 2^" << N << " = " << toString(sum) << "\n\n";
    std::cout << "3^" << N << " - 2^" << N << " = " << toString(difference) << "\n\n";
    std::cout << "3^" << N << " * 2^" << N << " = " << toString(product) << "\n";
}