#include <iostream>

using namespace std;

int fillArrayWithSuitableNumbers(int array[], int numberToDecompose) {
    int currentNumber = 1, indexInArray = 0;

    while (currentNumber * currentNumber * currentNumber <= numberToDecompose) {
        array[indexInArray] = currentNumber * currentNumber * currentNumber;
        currentNumber++;
        indexInArray++;
    }

    return indexInArray + 1;
}

int theShortestCombination[1000000]{};
int sizeOfTheShortestCombination = 9999999;

void showCombination(int result[], int cnt) {

    for (int index = cnt - 1; index >= 0; index--) cout << cbrt(result[index]) << "\t";

    if (cnt < sizeOfTheShortestCombination) {

        for (int index = 0; index < sizeOfTheShortestCombination; index++) {
            theShortestCombination[index] = 0;
        }

        for (int index = 0; index < cnt; index++) {
            theShortestCombination[index] = result[index];
        }

    }

    cout << "\n";
}

int MAX_RESULT_LENGTH;

bool combineSum(int numbersForCombinations[], int amountOfNumbersForCombinations, int sum) {
    static int* result = new int[MAX_RESULT_LENGTH] {};
    static int resultCnt = 0;

    if (amountOfNumbersForCombinations == 0) {
        if (sum == 0) showCombination(result, resultCnt);
        return sum == 0;
    }

    result[resultCnt++] = numbersForCombinations[amountOfNumbersForCombinations - 1];
    bool found1 = combineSum(numbersForCombinations, amountOfNumbersForCombinations - 1, sum - numbersForCombinations[amountOfNumbersForCombinations - 1]);
    result[--resultCnt] = 0;
    bool found2 = combineSum(numbersForCombinations, amountOfNumbersForCombinations - 1, sum);
    return found1 || found2;
}

int main() {
    int N;
    cout << "N = ";
    cin >> N;

    int* numbersForCombinations = new int[N / 2];
    int sizeOfNumbersForCombinations = fillArrayWithSuitableNumbers(numbersForCombinations, N);
    MAX_RESULT_LENGTH = sizeOfNumbersForCombinations;

    if (!combineSum(numbersForCombinations, sizeOfNumbersForCombinations, N)) cout << "there is no solve." << "\n";
    
    cout << "The shortest combination:" << "\n";

    for (int index = 0; index < sizeOfTheShortestCombination; index++) {
        cout << theShortestCombination[index] << "\t";
    }
}