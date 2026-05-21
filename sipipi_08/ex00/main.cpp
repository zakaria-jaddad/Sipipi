#include "easyfind.hpp"
#include <iostream>
#include <set>
#include <vector>

int main(void) {

  std::vector<int> arr(5);
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;
  arr[3] = 4;
  arr[4] = 5;

  std::cout << easyfind(arr, 99) << std::endl;

  std::cout << easyfind(arr, 5) << std::endl;

  std::set<int> s;
  s.insert(3);
  s.insert(1);
  s.insert(2);
  std::cout << easyfind(s, 1) << std::endl;

  return 0;
}
