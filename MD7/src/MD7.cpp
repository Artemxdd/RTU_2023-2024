#include <iostream>

void showCoins(int coins[], int numberOfCoins) {

    for (int index = 0; index < numberOfCoins; index++) std::cout << coins[index] << "\t";

    std::cout << "\n";
}

void paymentOfAmount(int coinValues[], int numberOfEachCoinValues[], int sum, int currentCoinIndex, int coins[], int numberOfCoins) {

    if (sum == 0) {
        showCoins(coins, numberOfCoins);
        return;
    }

    for (int index = currentCoinIndex; index >= 0; index--) {

        if (numberOfEachCoinValues[index] > 0 && sum >= coinValues[index]) {
            numberOfEachCoinValues[index]--;
            coins[numberOfCoins++] = coinValues[index];
            paymentOfAmount(coinValues, numberOfEachCoinValues, sum - coinValues[index], index, coins, numberOfCoins);
            numberOfEachCoinValues[index]++;
            coins[--numberOfCoins] = 0;
        }

    }

}

int main() {
    int numberOfCoinValues = 0;
    std::cout << "number of coin values: ";
    std::cin >> numberOfCoinValues;
    int* coinValues = new int[numberOfCoinValues] {0};
    std::cout << "coin values: ";

    for (int index = 0; index < numberOfCoinValues; index++) std::cin >> coinValues[index];

    int* numberOfEachCoinValues = new int[numberOfCoinValues] {0};
    std::cout << "number of each coin values: ";

    for (int index = 0; index < numberOfCoinValues; index++) std::cin >> numberOfEachCoinValues[index];

    int sum = 543;
    std::cout << "sum: ";
    std::cin >> sum;

    int* coins = new int[sum];
    paymentOfAmount(coinValues, numberOfEachCoinValues, sum, numberOfCoinValues - 1, coins, 0);

    delete[] coinValues;
    delete[] numberOfEachCoinValues;
    delete[] coins;
}