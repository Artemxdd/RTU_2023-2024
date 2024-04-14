#include "BinUInt.h"

BinUInt::BinUInt(unsigned int number) {
  defineBinNum(number);
}

void BinUInt::operator=(unsigned int number) {
  this->binNum_.clear();
  defineBinNum(number);
}

std::string BinUInt::toString() {
  std::string binNum;
  for (auto it : this->binNum_) {
    if (it) 
      binNum += "1";
    else
      binNum += "0";
  }
  return binNum;
}

size_t BinUInt::countNumberOfOnes() {
  size_t count{ 0 };
  for (auto it : this->binNum_) {
    if (it)
      count++;
  }
  return count;
}

size_t BinUInt::calculateLongestChaneOfOnes(){
  size_t maxCount{ 0 }, count{ 0 };
  for (auto it : this->binNum_) {
    if (it)
      count++;
    else {
      if (count > maxCount)
        maxCount = count;
      count = 0;
    }
  }
  if (count > maxCount)
    maxCount = count;

  return maxCount;
}

void BinUInt::defineBinNum(unsigned int number) {
  // Splitting into bits
  std::vector<bool> tmpBinNum;
  do {
    tmpBinNum.push_back(number % 2);
    number = number >> 1;
  } while (number > 0);

  // Reversing
  for (auto it{ tmpBinNum.rbegin() }; it != tmpBinNum.rend(); it++)
    this->binNum_.push_back(*it);
}
