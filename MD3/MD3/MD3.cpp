#include <iostream>

typedef unsigned long long int largeInt;

using namespace std;

void getPrimeNumbers(bool numbersFrom0ToN[], largeInt size) {

    for (largeInt index{ 2 }; index <= size; index++)
        numbersFrom0ToN[index] = true;

    largeInt i{ 4 };

    for (largeInt index1{ 2 }; index1 <= size; index1++) {
        i = index1 * index1;

        if (numbersFrom0ToN[index1]) {

            while (i < size) {
                numbersFrom0ToN[i] = false;
                i += index1;
            }

        }

    }

}

bool isPrimeNumber(largeInt number) {

    if (number > 1) {

        for (largeInt i{ 2 }; i < number; i++) {

            if (number % i == 0)
                return false;

        }

        return true;
    }

    return false;
}

largeInt getIDFromHASH(largeInt HASH, bool primeNumbers[], largeInt size) {

    for (largeInt ID{ 2 }; ID <= size; ID++) {

        if (primeNumbers[ID]) {

            if (HASH % ID == 0) {

                if (isPrimeNumber(HASH / ID))
                    return HASH / ID;

            }

        }

    }

    return 1;
}

int main() {
    largeInt HASH{ 2 };
    cout << "Enter HASH! HASH = ";
    cin >> HASH;

    bool* primeNumbers = new bool[1'000'000'000 + 1];
    getPrimeNumbers(primeNumbers, 1'000'000'000);

    largeInt ID = getIDFromHASH(HASH, primeNumbers, 1'000'000'000);

    if (ID == 1)
        cout << "HASH is incorrect, there is no user!";
    else
        cout << "HASH = " << HASH << " -> ID = " << ID;

}