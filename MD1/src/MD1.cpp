#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct paymentVariant {
	unsigned long long int sumOfTwo;
	unsigned long long int sumOfFive;
	unsigned long long int sumOfNine;
	unsigned long long int cntOfCoins;
};

vector<paymentVariant> allPaymentVariants{};

bool algorithm(const int sum) {
	if (sum < 2) return false;

	unsigned long long int 
		cntOfVariants{ 0 }, 
		cntOfTwo{ 0 }, cntOfFive{ 0 }, cntOfNine{ 0 };

	for (unsigned long long int sumOfTwo{ 0 }; sumOfTwo <= sum; sumOfTwo += 2) {

		for (unsigned long long int sumOfFive{ 0 }; sumOfFive <= sum; sumOfFive += 5) {

			if (sumOfTwo + sumOfFive > sum) continue;

			for (unsigned long long int sumOfNine{ 0 }; sumOfNine <= sum - sumOfTwo - sumOfFive; sumOfNine += 9) {

				if (sumOfTwo + sumOfFive + sumOfNine == sum) {
					cntOfTwo = sumOfTwo / 2;
					cntOfFive = sumOfFive / 5;
					cntOfNine = sumOfNine / 9;
					paymentVariant paymentVar{ sumOfTwo, sumOfFive, sumOfNine, cntOfTwo + cntOfFive + cntOfNine };
					allPaymentVariants.push_back(paymentVar);
					cntOfVariants++;
				}

			}

		}

	}

	unsigned long long int minCntOfCoins{ 9999999999999999999 };
	long long int minCntOfCoinsId{ -1 };

	for (unsigned long long int id{ 0 }; id < allPaymentVariants.size(); id++) {

		if (allPaymentVariants.at(id).cntOfCoins < minCntOfCoins) {
			minCntOfCoins = allPaymentVariants.at(id).cntOfCoins;
			minCntOfCoinsId = id;
		}

	}

	cntOfTwo = allPaymentVariants.at(minCntOfCoinsId).sumOfTwo / 2;
	cntOfFive = allPaymentVariants.at(minCntOfCoinsId).sumOfFive / 5;
	cntOfNine = allPaymentVariants.at(minCntOfCoinsId).sumOfNine / 9;

	cout << "sum = " << sum << " -> " << cntOfVariants << " variant(s), optimal " <<
		"2*" + to_string(cntOfTwo) + " + 5*" + to_string(cntOfFive) + " + 9*" + to_string(cntOfNine);
	return true;
}

int main() {
    unsigned long long int sum{};
	cout << "Enter sum (sum > 1): ";
	cin >> sum;

	if (!algorithm(sum))
		cout << "Incorrect sum!";

	return 0;
}