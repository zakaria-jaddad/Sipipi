#include <iostream>

int main(void) {

  std::string myString = "HI THIS IS BRAIN";
  std::string *stringPTR = &myString;
  std::string &stringREF = myString;

  //
  std::cout << &myString << "\n";
  std::cout << stringPTR << "\n";
  std::cout << &stringREF << "\n";

  //
  std::cout << myString << "\n";
  std::cout << *stringPTR << "\n";
  std::cout << stringREF << "\n";
  return 0;
}
