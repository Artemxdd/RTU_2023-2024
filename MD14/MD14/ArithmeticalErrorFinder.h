#pragma once

#include "LargePosInt.h"

class ArithmeticalErrorFinder {
public:
	bool checkIfThereIsExtraDigit(std::string firstSummand, std::string secondSummand, std::string sum, 
		std::vector<std::string>& results);

	bool checkIfThereIsWrongDigit(std::string firstSummand, std::string secondSummand, std::string sum,
		std::vector<std::string>& results);

	bool checkIfThereIsMissingDigit(std::string firstSummand, std::string secondSummand, std::string sum,
		std::vector<std::string>& results);

private:
	std::string makeSumAsString(std::string firstSummand, std::string secondSummand, std::string sum);

	int compareCalculatedAndEnteredSum(const std::string& firstSummand, const std::string& secondSummand,
		const std::string& sum);
};

