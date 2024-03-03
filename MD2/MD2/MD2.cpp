#include <iostream>
#include <vector>

using namespace std;

void getPrimeNumbersInTheRangeFrom2ToN(vector<unsigned int>& numbersFrom2ToN) {
    unsigned int sizeOfArray = numbersFrom2ToN.size();

    for (unsigned int index1 = 0; index1 <= sizeOfArray - 1; index1++)
        numbersFrom2ToN.at(index1) = index1;

    for (unsigned int index1 = 2; index1 * index1 <= sizeOfArray - 1; index1++) {

        if (numbersFrom2ToN.at(index1) != 0) {

            for (unsigned int index2 = index1 * index1; index2 <= sizeOfArray - 1; index2 += index1)
                numbersFrom2ToN.at(index2) = 0;

        }

    }

}

unsigned int getAmountOfPrimeNumbers(vector<unsigned int>& numbersFrom2ToN) {
    unsigned int amountOfPrimeNumbers = 0;

    for (unsigned int index = 2; index <= numbersFrom2ToN.size() - 1; index++) {

        if (numbersFrom2ToN.at(index) != 0)
            amountOfPrimeNumbers++;

    }

    return amountOfPrimeNumbers;
}

unsigned int getMaxPrimeNumber(vector<unsigned int>& numbersFrom2ToN) {

    for (unsigned int index = numbersFrom2ToN.size() - 1; index >= 2; index--) {

        if (numbersFrom2ToN.at(index) != 0)
            return index;

    }

    return 0;
}

int main() {
    unsigned int N{ 2 };

    do {
        cout << "Enter N! N = ";
        cin >> N;
    } while (N < 2);

    vector<unsigned int> numbersFrom2ToN{};
    numbersFrom2ToN.resize(N + 1);

    getPrimeNumbersInTheRangeFrom2ToN(numbersFrom2ToN);

    unsigned int amountOfPrimeNumbers = getAmountOfPrimeNumbers(numbersFrom2ToN);
    unsigned int maxPrimeNumber = getMaxPrimeNumber(numbersFrom2ToN);

    cout << "N = " << N << " -> amount = " << amountOfPrimeNumbers << ", max = " << maxPrimeNumber;
}