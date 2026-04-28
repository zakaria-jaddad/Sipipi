#include "Span.hpp"
#include <iostream>
#include <limits>

int main()
{
  Span sp = Span(10);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::vector<int> numbers(5);
  numbers[0] = 1;
  numbers[1] = 2;
  numbers[2] = 3;
  numbers[3] = 4;
  numbers[4] = 5; 
  sp.addNumbers(numbers);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;



  return 0;
}