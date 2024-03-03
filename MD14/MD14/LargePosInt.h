#pragma once

#include <vector>
#include <string>

// Large positive int
class LargePosInt {
private:
	std::vector<int> largePositiveInt;

	std::vector<int> addZerosToEnd(std::vector<int> number, int numberOfZeros);
	std::vector<int> addZerosToBeginning(std::vector<int> number, int numberOfZeros);
	std::vector<int> deleteZerosFromBeginning(std::vector<int> number);
	int compareNumbers(const std::string& firstNumber, const std::string& secondNumber);
	std::vector<int> distributeNumberAcrossCells(std::vector<int> number);
	int countNumberOfSubtractions(std::vector<int> minuend, const std::vector<int>& subtrahend);

	std::vector<int> fromString(const std::string& number);
	std::string toString(const std::vector<int>& number);
	void setLargePositiveInt(const std::string& number);
	std::vector<int> getLargePositiveInt();

	std::string calculateSumOfTwoNumbers(const std::string& firstSummand, const std::string& secondSummand);
	std::string calculateDifferenceOfTwoNumbers(const std::string& minuend, const std::string& subtrahend);
	std::string calculateProductOfTwoNumbers(const std::string& multiplicand, const std::string& multiplier);
	std::string calculateProductOfTwoNumbers(const std::vector<int>& multiplicand, const int& multiplier);
	std::string calculateQuotientOfTwoNumbers(const std::string& dividend, const std::string& divisor);

public:
	LargePosInt(const std::string& numberAsString);

	std::string toString();

	void operator=(const std::string& numberAsString);
	LargePosInt operator+(const LargePosInt& largePosInt);
	LargePosInt operator-(const LargePosInt& largePosInt);
	LargePosInt operator*(const LargePosInt& largePosInt);
	LargePosInt operator/(const LargePosInt& largePosInt);
	bool operator==(const LargePosInt& largePosInt);
	bool operator>(const LargePosInt& largePosInt);
	bool operator<(const LargePosInt& largePosInt);
};

