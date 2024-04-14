#pragma once

#include <vector>
#include <string>
#include <bitset>
#include <stdint.h>

// Binary unsigned int
class BinUInt {
public:
  BinUInt(unsigned int number);
  void operator=(unsigned int number);

  std::string toString();

  size_t countNumberOfOnes();
  size_t calculateLongestChaneOfOnes();

private:
  std::vector<bool> binNum_;

  void defineBinNum(unsigned int number);
};