#include "ArithmeticalErrorFinder.h"

bool ArithmeticalErrorFinder::checkIfThereIsExtraDigit(std::string firstSummand, std::string secondSummand, std::string sum,
	std::vector<std::string>& results) {
	int resultOfComparingNumbers{ compareCalculatedAndEnteredSum(firstSummand, secondSummand, sum) };

	if (resultOfComparingNumbers == 0) return false;

	std::vector<std::string> temporaryResults;

	if (resultOfComparingNumbers == 1) {	// error in summands
		std::string copyOfFirstSummand{ firstSummand }, copyOfSecondSummand{ secondSummand };

		for (int index{ 0 }; index < firstSummand.size(); index++) {
			copyOfFirstSummand = firstSummand;
			copyOfFirstSummand.erase(copyOfFirstSummand.begin() + index);

			if (compareCalculatedAndEnteredSum(copyOfFirstSummand, secondSummand, sum) == 0)
				temporaryResults.push_back(makeSumAsString(copyOfFirstSummand, secondSummand, sum));

		}

		for (int index{ 0 }; index < secondSummand.size(); index++) {
			copyOfSecondSummand = secondSummand;
			copyOfSecondSummand.erase(copyOfSecondSummand.begin() + index);

			if (compareCalculatedAndEnteredSum(firstSummand, copyOfSecondSummand, sum) == 0)
				temporaryResults.push_back(makeSumAsString(firstSummand, copyOfSecondSummand, sum));

		}

	}
	else {	// error in sum
		std::string copyOfSum{ sum };

		for (int index{ 0 }; index < sum.size(); index++) {
			copyOfSum = sum;
			copyOfSum.erase(copyOfSum.begin() + index);

			if (compareCalculatedAndEnteredSum(firstSummand, secondSummand, copyOfSum) == 0)
				temporaryResults.push_back(makeSumAsString(firstSummand, secondSummand, copyOfSum));

		}
	}

	if (temporaryResults.size() == 0) return false;

	for (auto temporaryResult : temporaryResults) results.push_back(temporaryResult);
	
	return true;
}

bool ArithmeticalErrorFinder::checkIfThereIsWrongDigit(std::string firstSummand, std::string secondSummand, std::string sum,
	std::vector<std::string>& results) {

	if (compareCalculatedAndEnteredSum(firstSummand, secondSummand, sum) == 0) return false;

	std::string copyOfFirstSummand{ "" }, copyOfSecondSummand{ "" }, copyOfSum{ "" };
	std::vector<std::string> temporaryResults;

	for (int index{ 0 }; index < firstSummand.size(); index++) {
		copyOfFirstSummand = firstSummand;

		for (int digit{ 0 }; digit <= 9; digit++) {
			copyOfFirstSummand[index] = digit + '0';

			if (compareCalculatedAndEnteredSum(copyOfFirstSummand, secondSummand, sum) == 0)
				temporaryResults.push_back(makeSumAsString(copyOfFirstSummand, secondSummand, sum));

		}

	}

	for (int index{ 0 }; index < secondSummand.size(); index++) {
		copyOfSecondSummand = secondSummand;

		for (int digit{ 0 }; digit <= 9; digit++) {
			copyOfSecondSummand[index] = digit + '0';

			if (compareCalculatedAndEnteredSum(firstSummand, copyOfSecondSummand, sum) == 0)
				temporaryResults.push_back(makeSumAsString(firstSummand, copyOfSecondSummand, sum));

		}

	}

	for (int index{ 0 }; index < sum.size(); index++) {
		copyOfSum = sum;

		for (int digit{ 0 }; digit <= 9; digit++) {
			copyOfSum[index] = digit + '0';

			if (compareCalculatedAndEnteredSum(firstSummand, secondSummand, copyOfSum) == 0)
				temporaryResults.push_back(makeSumAsString(firstSummand, secondSummand, copyOfSum));

		}

	}

	if (temporaryResults.size() == 0) return false;

	for (auto temporaryResult : temporaryResults) results.push_back(temporaryResult);

	return true;
}

bool ArithmeticalErrorFinder::checkIfThereIsMissingDigit(std::string firstSummand, std::string secondSummand, std::string sum,
	std::vector<std::string>& results) {
	int resultOfComparingNumbers{ compareCalculatedAndEnteredSum(firstSummand, secondSummand, sum) };

	if (resultOfComparingNumbers == 0) return false;

	std::vector<std::string> temporaryResults;

	if (resultOfComparingNumbers == 1) {	// error in sum
		std::string copyOfSum{ sum };

		for (int index{ 0 }; index <= sum.size(); index++) {
			copyOfSum = sum;
			copyOfSum.insert(copyOfSum.begin() + index, 0 + '0');

			for (int digit{ 0 }; digit <= 9; digit++) {
				copyOfSum[index] = digit + '0';

				if (compareCalculatedAndEnteredSum(firstSummand, secondSummand, copyOfSum) == 0)
					temporaryResults.push_back(makeSumAsString(firstSummand, secondSummand, copyOfSum));

			}

			copyOfSum.erase(copyOfSum.begin() + index);
		}

	}
	else {	// error in summands
		std::string copyOfFirstSummand{ "" }, copyOfSecondSummand{ "" };

		for (int index{ 0 }; index <= firstSummand.size(); index++) {
			copyOfFirstSummand = firstSummand;
			copyOfFirstSummand.insert(copyOfFirstSummand.begin() + index, 0 + '0');

			for (int digit{ 0 }; digit <= 9; digit++) {
				copyOfFirstSummand[index] = digit + '0';

				if (compareCalculatedAndEnteredSum(copyOfFirstSummand, secondSummand, sum) == 0)
					temporaryResults.push_back(makeSumAsString(copyOfFirstSummand, secondSummand, sum));

			}

			copyOfFirstSummand.erase(copyOfFirstSummand.begin() + index);
		}

		for (int index{ 0 }; index <= secondSummand.size(); index++) {
			copyOfSecondSummand = secondSummand;
			copyOfSecondSummand.insert(copyOfSecondSummand.begin() + index, 0 + '0');

			for (int digit{ 0 }; digit <= 9; digit++) {
				copyOfSecondSummand[index] = digit + '0';

				if (compareCalculatedAndEnteredSum(firstSummand, copyOfSecondSummand, sum) == 0)
					temporaryResults.push_back(makeSumAsString(firstSummand, copyOfSecondSummand, sum));

			}

			copyOfSecondSummand.erase(copyOfSecondSummand.begin() + index);
		}

	}

	if (temporaryResults.size() == 0) return false;

	for (auto temporaryResult : temporaryResults) results.push_back(temporaryResult);

	return true;
}

std::string ArithmeticalErrorFinder::makeSumAsString(std::string firstSummand, std::string secondSummand, std::string sum) {
	return firstSummand + " + " + secondSummand + " = " + sum;
}

int ArithmeticalErrorFinder::compareCalculatedAndEnteredSum(const std::string& firstSummand, const std::string& secondSummand, 
	const std::string& sum) {
	LargePosInt summand1{ firstSummand }, summand2{ secondSummand }, 
		calculatedSum{ summand1 + summand2 }, enteredSum{ sum };

	if (calculatedSum == enteredSum) return 0;
	if (calculatedSum > enteredSum) return 1;

	return -1;
}
