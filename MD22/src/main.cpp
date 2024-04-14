#include <iostream>
#include "BinUInt.h"

int main() {
  size_t begin{ 0 }, end{ 0 }, tmp{ 0 };
  std::cout << "Enter begin number! Begin = "; std::cin >> begin;
  std::cout << "Enter end number! End = "; std::cin >> end;

  BinUInt binUInt{ 0 };

  // A
  std::cout << "A:\n";
  while (tmp <= end) {
    binUInt = tmp;
    if (binUInt.countNumberOfOnes() >= 3)
      std::cout << tmp << " = " << binUInt.toString() << "\n";
    tmp++;
  }
  std::cout << "----------------------\n";

  // B
  std::cout << "B:\n";
  tmp = begin;
  while (tmp <= end) {
    binUInt = tmp;
    if (binUInt.countNumberOfOnes() == 3)
      std::cout << tmp << " = " << binUInt.toString() << "\n";
    tmp++;
  }
  std::cout << "----------------------\n";

  // C
  std::cout << "C:\n";
  tmp = begin;
  while (tmp <= end) {
    binUInt = tmp;
    if (binUInt.calculateLongestChaneOfOnes() >= 3)
      std::cout << tmp << " = " << binUInt.toString() << "\n";
    tmp++;
  }
  std::cout << "----------------------\n";

  // D
  std::cout << "D:\n";
  tmp = begin;
  while (tmp <= end) {
    binUInt = tmp;
    if (binUInt.calculateLongestChaneOfOnes() == 3)
      std::cout << tmp << " = " << binUInt.toString() << "\n";
    tmp++;
  }
  std::cout << "----------------------\n";
} 
