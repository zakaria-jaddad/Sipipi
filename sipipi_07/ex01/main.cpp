#include "iter.hpp"
#include <iostream>
#include <string>

int main(void) {
  std::cout << "--- TEST 1: Array of non-const ints ---" << std::endl;
  int intArray[5] = {0, 1, 2, 3, 4};
  size_t intLength = 5;

  std::cout << "Original: ";
  ::iter(intArray, intLength, printElement<int>);
  std::cout << std::endl;

  std::cout << "Incrementing..." << std::endl;
  ::iter(intArray, intLength, incrementElement<int>);

  std::cout << "Modified: ";
  ::iter(intArray, intLength, printElement<int>);
  std::cout << std::endl;

  std::cout << "--- TEST 2: Array of const std::string ---" << std::endl;
  const std::string strArray[2] = {"Hello", "World"};
  size_t strLength = 2;

  std::cout << "Strings: ";
  ::iter(strArray, strLength, printElement<std::string>);
  std::cout << std::endl;

  return 0;
}
