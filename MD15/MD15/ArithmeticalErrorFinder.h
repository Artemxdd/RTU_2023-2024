#pragma once

#include "LargeUnsignedInt.h"
#include <set>

typedef std::string str;

class ArithmeticalErrorFinder {
public:
	bool checkIfThereIsExtraDigit(const str& summand1, const str& summand2, const str& sum, 
		std::vector<str>& results);

	bool checkIfThereIsWrongDigit(const str& summand1, const str& summand2, const str& sum, 
		std::vector<str>& results);

	bool checkIfThereIsMissingDigit(const str& summand1, const str& summand2, const str& sum,
		std::vector<str>& results);

	bool checkIfThereAreTwoDigitsInRowInWrongOrder(const str& summand1, const str& summand2, const str& sum,
		std::vector<str>& results);

	bool checkIfThereAreTwoWrongDigits(const str& summand1, const str& summand2, const str& sum,
		std::vector<str>& results);

	bool checkIfThereIsTheMostSuitableFix(const str& summand1, const str& summand2, const str& sum,
		str& theMostSuitableFix);

private:
	std::string makeSumAsString(const str& summand1, const str& summand2, const str& sum);

	int compareCalculatedAndEnteredSum(const str& summand1, const str& summand2, const str& sum);
};

