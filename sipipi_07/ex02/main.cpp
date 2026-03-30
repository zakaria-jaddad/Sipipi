#include "Array.hpp"
#include <exception>
#include <iostream>

int main(void) {

  Array<int> arr(20);
  std::cout << "Array size: " << arr.size() << std::endl;
  for (unsigned int i = 0; i < arr.size(); i++) {
    try {
      std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  try {
    int a = arr[80];
    std::cout << a << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
