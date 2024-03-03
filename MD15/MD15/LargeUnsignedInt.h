#pragma once

#include <vector>
#include <string>

typedef std::vector<char> largeValue;

class LargeUnsignedInt {
public:
	LargeUnsignedInt(const std::string& numberAsString);
	std::string toString();

	void operator=(const std::string& numberAsString);
	LargeUnsignedInt operator+(const LargeUnsignedInt& largePosInt);
	LargeUnsignedInt operator-(const LargeUnsignedInt& largePosInt);
	LargeUnsignedInt operator*(const LargeUnsignedInt& largePosInt);
	LargeUnsignedInt operator/(const LargeUnsignedInt& largePosInt);
	bool operator==(const LargeUnsignedInt& largePosInt);
	bool operator>(const LargeUnsignedInt& largePosInt);
	bool operator<(const LargeUnsignedInt& largePosInt);

private:
	largeValue value;

	largeValue addZerosToEnd(largeValue number, int numberOfZeros);
	largeValue addZerosToBeginning(largeValue number, int numberOfZeros);
	largeValue deleteZerosFromBeginning(largeValue number);
	int compareNumbers(const std::string& firstNumber, const std::string& secondNumber);
	largeValue distributeNumberAcrossCells(largeValue number);
	int countNumberOfSubtractions(largeValue minuend, const largeValue& subtrahend);

	largeValue fromString(const std::string& number);
	std::string toString(const largeValue& number);
	void setValue(std::string number);

	std::string calculateSum(const std::string& firstSummand, const std::string& secondSummand);
	std::string calculateDifference(const std::string& minuend, const std::string& subtrahend);
	std::string calculateProduct(const largeValue& multiplicand, const int& multiplier);
	std::string calculateProduct(const std::string& multiplicand, const std::string& multiplier);
	std::string calculateQuotient(const std::string& dividend, const std::string& divisor);
};

