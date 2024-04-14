#include <iostream>
#include <cstdint>
#include <bitset>

int main() {
  uint16_t num1{ 0 }, num2{ 0 }, res1{ 0 }, res2{ 0 }, res3{ 0 };

  do {
    std::cout << "Enter first number! a = "; std::cin >> num1;
  } while (num1 > 15);
  do {
    std::cout << "Enter second number! b = "; std::cin >> num2;
  } while (num2 > 15);

  res1 = num2 << 4 | num1;
  res2 = (num2 & 0b1100) << 4 | (num1 & 0b1100) << 2 | (num2 & 0b11) << 2 | num1 & 0b11;
  for (uint8_t i{ 0 }; i <= 3; i++)
    res3 |= (num1 & 1 << i) << i | (num2 & 1 << i) << i + 1;

  std::cout << "A: c = " << std::bitset<8>{ res1 } << " = " << res1 << "\n";
  std::cout << "B: c = " << std::bitset<8>{ res2 } << " = " << res2 << "\n";
  std::cout << "C: c = " << std::bitset<8>{ res3 } << " = " << res3 << "\n";
} 
