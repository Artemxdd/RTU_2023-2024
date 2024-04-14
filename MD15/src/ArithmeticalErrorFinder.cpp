#include "ArithmeticalErrorFinder.h"

bool ArithmeticalErrorFinder::checkIfThereIsExtraDigit(const str& summand1, const str& summand2, 
	const str& sum, std::vector<str>& results) {
	int resultOfComparingNumbers{ compareCalculatedAndEnteredSum(summand1, summand2, sum) };

	if (resultOfComparingNumbers == 0) return false;

	std::vector<std::string> temporaryResults;

	if (resultOfComparingNumbers == 1) {	// error in summands
		std::string copyOfFirstSummand{ summand1 }, copyOfSecondSummand{ summand2 };

		for (int index{ 0 }; index < summand1.size(); index++) {
			copyOfFirstSummand = summand1;
			copyOfFirstSummand.erase(copyOfFirstSummand.begin() + index);

			if (compareCalculatedAndEnteredSum(copyOfFirstSummand, summand2, sum) == 0)
				temporaryResults.push_back(makeSumAsString(copyOfFirstSummand, summand2, sum));

		}

		for (int index{ 0 }; index < summand2.size(); index++) {
			copyOfSecondSummand = summand2;
			copyOfSecondSummand.erase(copyOfSecondSummand.begin() + index);

			if (compareCalculatedAndEnteredSum(summand1, copyOfSecondSummand, sum) == 0)
				temporaryResults.push_back(makeSumAsString(summand1, copyOfSecondSummand, sum));

		}

	}
	else {	// error in sum
		std::string copyOfSum{ sum };

		for (int index{ 0 }; index < sum.size(); index++) {
			copyOfSum = sum;
			copyOfSum.erase(copyOfSum.begin() + index);

			if (compareCalculatedAndEnteredSum(summand1, summand2, copyOfSum) == 0)
				temporaryResults.push_back(makeSumAsString(summand1, summand2, copyOfSum));

		}
	}

	if (temporaryResults.size() == 0) return false;

	for (auto& temporaryResult : temporaryResults) results.push_back(temporaryResult);
	
	return true;
}

bool ArithmeticalErrorFinder::checkIfThereIsWrongDigit(const str& summand1, const str& summand2, 
	const str& sum, std::vector<str>& results) {

	if (compareCalculatedAndEnteredSum(summand1, summand2, sum) == 0) return false;

	std::string copyOfFirstSummand{ "" }, copyOfSecondSummand{ "" }, copyOfSum{ "" };
	std::vector<std::string> temporaryResults;

	for (int index{ 0 }; index < summand1.size(); index++) {
		copyOfFirstSummand = summand1;

		for (int digit{ 0 }; digit <= 9; digit++) {
			copyOfFirstSummand[index] = digit + '0';

			if (compareCalculatedAndEnteredSum(copyOfFirstSummand, summand2, sum) == 0)
				temporaryResults.push_back(makeSumAsString(copyOfFirstSummand, summand2, sum));

		}

	}

	for (int index{ 0 }; index < summand2.size(); index++) {
		copyOfSecondSummand = summand2;

		for (int digit{ 0 }; digit <= 9; digit++) {
			copyOfSecondSummand[index] = digit + '0';

			if (compareCalculatedAndEnteredSum(summand1, copyOfSecondSummand, sum) == 0)
				temporaryResults.push_back(makeSumAsString(summand1, copyOfSecondSummand, sum));

		}

	}

	for (int index{ 0 }; index < sum.size(); index++) {
		copyOfSum = sum;

		for (int digit{ 0 }; digit <= 9; digit++) {
			copyOfSum[index] = digit + '0';

			if (compareCalculatedAndEnteredSum(summand1, summand2, copyOfSum) == 0)
				temporaryResults.push_back(makeSumAsString(summand1, summand2, copyOfSum));

		}

	}

	if (temporaryResults.size() == 0) return false;

	for (auto& temporaryResult : temporaryResults) results.push_back(temporaryResult);

	return true;
}

bool ArithmeticalErrorFinder::checkIfThereIsMissingDigit(const str& summand1, const str& summand2, 
	const str& sum, std::vector<str>& results) {
	int resultOfComparingNumbers{ compareCalculatedAndEnteredSum(summand1, summand2, sum) };

	if (resultOfComparingNumbers == 0) return false;

	std::vector<std::string> temporaryResults;

	if (resultOfComparingNumbers == 1) {	// error in sum
		std::string copyOfSum{ sum };

		for (int index{ 0 }; index <= sum.size(); index++) {
			copyOfSum = sum;
			copyOfSum.insert(copyOfSum.begin() + index, 0 + '0');

			for (int digit{ 0 }; digit <= 9; digit++) {
				copyOfSum[index] = digit + '0';

				if (compareCalculatedAndEnteredSum(summand1, summand2, copyOfSum) == 0)
					temporaryResults.push_back(makeSumAsString(summand1, summand2, copyOfSum));

			}

			copyOfSum.erase(copyOfSum.begin() + index);
		}

	}
	else {	// error in summands
		std::string copyOfFirstSummand{ "" }, copyOfSecondSummand{ "" };

		for (int index{ 0 }; index <= summand1.size(); index++) {
			copyOfFirstSummand = summand1;
			copyOfFirstSummand.insert(copyOfFirstSummand.begin() + index, 0 + '0');

			for (int digit{ 0 }; digit <= 9; digit++) {
				copyOfFirstSummand[index] = digit + '0';

				if (compareCalculatedAndEnteredSum(copyOfFirstSummand, summand2, sum) == 0)
					temporaryResults.push_back(makeSumAsString(copyOfFirstSummand, summand2, sum));

			}

			copyOfFirstSummand.erase(copyOfFirstSummand.begin() + index);
		}

		for (int index{ 0 }; index <= summand2.size(); index++) {
			copyOfSecondSummand = summand2;
			copyOfSecondSummand.insert(copyOfSecondSummand.begin() + index, 0 + '0');

			for (int digit{ 0 }; digit <= 9; digit++) {
				copyOfSecondSummand[index] = digit + '0';

				if (compareCalculatedAndEnteredSum(summand1, copyOfSecondSummand, sum) == 0)
					temporaryResults.push_back(makeSumAsString(summand1, copyOfSecondSummand, sum));

			}

			copyOfSecondSummand.erase(copyOfSecondSummand.begin() + index);
		}

	}

	if (temporaryResults.size() == 0) return false;

	for (auto& temporaryResult : temporaryResults) results.push_back(temporaryResult);

	return true;
}

bool ArithmeticalErrorFinder::checkIfThereAreTwoDigitsInRowInWrongOrder(const str& summand1, const str& summand2,
	const str& sum, std::vector<str>& results) {

	if (compareCalculatedAndEnteredSum(summand1, summand2, sum) == 0) return false;

	std::set<std::string> temporaryResults;
	std::string copyOfFirstSummand, copyOfSecondSummand, copyOfSum;

	for (int index1{ 0 }; index1 < summand1.size() - 1; index1++) {
		
		for (int index2{ index1 + 1 }; index2 < summand1.size(); index2++) {
			copyOfFirstSummand = summand1;
			std::swap(copyOfFirstSummand[index1], copyOfFirstSummand[index2]);

			if (compareCalculatedAndEnteredSum(copyOfFirstSummand, summand2, sum) == 0)
				temporaryResults.insert(makeSumAsString(copyOfFirstSummand, summand2, sum));

		}

	}

	for (int index1{ 0 }; index1 < summand2.size() - 1; index1++) {

		for (int index2{ index1 + 1 }; index2 < summand2.size(); index2++) {
			copyOfSecondSummand = summand2;
			std::swap(copyOfSecondSummand[index1], copyOfSecondSummand[index2]);

			if (compareCalculatedAndEnteredSum(summand1, copyOfSecondSummand, sum) == 0)
				temporaryResults.insert(makeSumAsString(summand1, copyOfSecondSummand, sum));

		}

	}

	for (int index1{ 0 }; index1 < sum.size() - 1; index1++) {

		for (int index2{ index1 + 1 }; index2 < sum.size(); index2++) {
			copyOfSum = sum;
			std::swap(copyOfSum[index1], copyOfSum[index2]);

			if (compareCalculatedAndEnteredSum(summand1, summand2, copyOfSum) == 0)
				temporaryResults.insert(makeSumAsString(summand1, summand2, copyOfSum));

		}

	}

	if (temporaryResults.size() == 0) return false;

	for (auto& temporaryResult : temporaryResults) results.push_back(temporaryResult);

	return true;
}

bool ArithmeticalErrorFinder::checkIfThereAreTwoWrongDigits(const str& summand1, const str& summand2,
	const str& sum, std::vector<str>& results) {

	if (compareCalculatedAndEnteredSum(summand1, summand2, sum) == 0) return false;

	std::set<std::string> temporaryResults;
	std::string temporaryString{ summand1 + summand2 + sum }, copyOfFirstSummand, copyOfSecondSummand, copyOfSum;

	for (int index1{ 0 }; index1 < temporaryString.size() - 1; index1++) {

		for (int index2{ index1 + 1 }; index2 < temporaryString.size(); index2++) {
			temporaryString = summand1 + summand2 + sum;

			for (int digit1{ 0 }; digit1 <= 9; digit1++) {
				
				for (int digit2{ 0 }; digit2 <= 9; digit2++) {
					temporaryString[index1] = digit1 + '0';
					temporaryString[index2] = digit2 + '0';

					copyOfFirstSummand = temporaryString.substr(0, (size_t)summand1.size());
					copyOfSecondSummand = temporaryString.substr((size_t)summand1.size(), (size_t)summand2.size());
					copyOfSum = temporaryString.substr((size_t)(summand1.size() + summand2.size()), (size_t)sum.size());

					if (compareCalculatedAndEnteredSum(copyOfFirstSummand, copyOfSecondSummand, copyOfSum) == 0)
						temporaryResults.insert(makeSumAsString(copyOfFirstSummand, copyOfSecondSummand, copyOfSum));

				}

			}

		}

	}

	if (temporaryResults.size() == 0) return false;

	for (auto& temporaryResult : temporaryResults) results.push_back(temporaryResult);

	return true;
}

bool ArithmeticalErrorFinder::checkIfThereIsTheMostSuitableFix(const str& summand1, const str& summand2, 
	const str& sum, str& theMostSuitableFix) {
	std::vector<std::string> results;

	if (checkIfThereIsWrongDigit(summand1, summand2, sum, results)) {}
	else if (checkIfThereIsMissingDigit(summand1, summand2, sum, results)) {}
	else if (checkIfThereIsExtraDigit(summand1, summand2, sum, results)) {}
	else if (checkIfThereAreTwoDigitsInRowInWrongOrder(summand1, summand2, sum, results)) {}
	else if (checkIfThereAreTwoWrongDigits(summand1, summand2, sum, results)) {}

	if (results.size() != 0) {
		theMostSuitableFix = results[0];
		return true;
	}

	return false;
}

std::string ArithmeticalErrorFinder::makeSumAsString(const str& summand1, const str& summand2, const str& sum) {
	return summand1 + " + " + summand2 + " = " + sum;
}

int ArithmeticalErrorFinder::compareCalculatedAndEnteredSum(const str& summand1, const str& summand2, 
	const str& sum) {
	LargeUnsignedInt firstSummand{ summand1 }, secondSummand{ summand2 }, 
		calculatedSum{ firstSummand + secondSummand }, enteredSum{ sum };

	if (calculatedSum == enteredSum) return 0;
	if (calculatedSum > enteredSum) return 1;

	return -1;
}
