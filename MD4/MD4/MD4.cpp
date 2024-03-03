#include <iostream>
#include <string>

using namespace std;

int collectThreeDigitNumber(int firstDigit, int secondDigit, int thirdDigit) {
	return firstDigit * pow(10, 2) + secondDigit * 10 + thirdDigit;
}

int collectFiveDigitNumber(int firstDigit, int secondDigit, int thirdDigit, int fourthDigit, int fifthDigit) {
	return firstDigit * pow(10, 4) + secondDigit * pow(10, 3) + thirdDigit * pow(10, 2) + fourthDigit * 10 + fifthDigit;
}

string collectResult(int firstNumber, int secondNumber, int resultNumber, char mathematicalOperation) {
	return to_string(firstNumber) + mathematicalOperation + to_string(secondNumber) + " = " + to_string(resultNumber);
}

string solveFirstRebus() {

	for (int aDigit = 0; aDigit <= 9; aDigit++) {

		for (int bDigit = 0; bDigit <= 9; bDigit++) {

			if (bDigit == aDigit) continue;

			for (int cDigit = 0; cDigit <= 9; cDigit++) {

				if (cDigit == bDigit || cDigit == aDigit) continue;

				int firstNumber = collectFiveDigitNumber(aDigit, bDigit, aDigit, bDigit, aDigit);
				int secondNumber = collectFiveDigitNumber(cDigit, bDigit, cDigit, bDigit, cDigit);
				int resultNumber = cDigit * pow(10, 5) + bDigit * pow(10, 4) + cDigit * pow(10, 3) + bDigit * pow(10, 2) +
					cDigit * 10 + bDigit;

				if (firstNumber + secondNumber == resultNumber) return collectResult(firstNumber, secondNumber, resultNumber, '+');
			}

		}

	}

	return "There is no solve";
}

string solveSecondRebus() {

	for (int aDigit = 0; aDigit <= 9; aDigit++) {

		for (int bDigit = 0; bDigit <= 9; bDigit++) {

			if (bDigit == aDigit) continue;

			for (int cDigit = 0; cDigit <= 9; cDigit++) {

				if (cDigit == bDigit || cDigit == aDigit) continue;

				for (int dDigit = 0; dDigit <= 9; dDigit++) {

					if (dDigit == cDigit || dDigit == bDigit || dDigit == aDigit) continue;

					int firstNumber = collectThreeDigitNumber(aDigit, bDigit, cDigit);
					int secondNumber = collectThreeDigitNumber(bDigit, cDigit, aDigit);
					int resultNumber = aDigit * pow(10, 5) + dDigit * pow(10, 4) + dDigit * pow(10, 3) + bDigit * pow(10, 2) +
						dDigit * 10 + cDigit;;

					if (firstNumber * secondNumber == resultNumber) return collectResult(firstNumber, secondNumber, resultNumber, '*');

				}

			}

		}

	}

	return "There is no solve";
}

string solveThirdRebus() {

	for (int aDigit = 0; aDigit <= 9; aDigit++) {

		for (int bDigit = 0; bDigit <= 9; bDigit++) {

			if (bDigit == aDigit) continue;

			for (int cDigit = 0; cDigit <= 9; cDigit++) {

				if (cDigit == bDigit || cDigit == aDigit) continue;

				for (int dDigit = 0; dDigit <= 9; dDigit++) {

					if (dDigit == cDigit || dDigit == bDigit || dDigit == aDigit) continue;

					for (int eDigit = 0; eDigit <= 9; eDigit++) {

						if (eDigit == dDigit || eDigit == cDigit || eDigit == bDigit || eDigit == aDigit) continue;

						int firstNumber = collectThreeDigitNumber(aDigit, bDigit, bDigit);
						int secondNumber = cDigit * 10 + aDigit;
						int resultNumber = collectFiveDigitNumber(dDigit, eDigit, eDigit, eDigit, eDigit);

						if (firstNumber * secondNumber == resultNumber) return collectResult(firstNumber, secondNumber, resultNumber, '*');

					}

				}

			}

		}

	}

	return "There is no solve";
}

string solveFourthRebus() {

	for (int aDigit = 0; aDigit <= 9; aDigit++) {

		for (int bDigit = 0; bDigit <= 9; bDigit++) {

			if (bDigit == aDigit) continue;

			for (int cDigit = 0; cDigit <= 9; cDigit++) {

				if (cDigit == bDigit || cDigit == aDigit) continue;

				for (int unknown1 = 0; unknown1 <= 9; unknown1++) {

					for (int unknown2 = 0; unknown2 <= 9; unknown2++) {

						for (int unknown3 = 0; unknown3 <= 9; unknown3++) {

							for (int unknown4 = 0; unknown4 <= 9; unknown4++) {

								for (int unknown5 = 0; unknown5 <= 9; unknown5++) {

									int firstNumber = aDigit * pow(10, 3) + unknown1 * pow(10, 2) + unknown2 * 10 + aDigit;
									int secondNumber = collectThreeDigitNumber(bDigit, unknown3, bDigit);
									int resultNumber = cDigit * pow(10, 5) + unknown4 * pow(10, 4) + cDigit * pow(10, 3) +
										cDigit * pow(10, 2) + unknown5 * 10 + cDigit;

									if (firstNumber * secondNumber == resultNumber)
										return collectResult(firstNumber, secondNumber, resultNumber, '*');

								}

							}

						}

					}

				}

			}

		}

	}

	return "There is no solve";
}

int main() {
	cout << "ABABA + CBCBC = CBCBCB -> " << solveFirstRebus() << endl;
	cout << "ABC * BCA = ADDBDC -> " << solveSecondRebus() << endl;
	cout << "ABB * CA = DEEEE -> " << solveThirdRebus() << endl;
	cout << "A**A * B*B = C*CC*C -> " << solveFourthRebus() << endl;
}