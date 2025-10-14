#include <algorithm>
#include <cctype>
#include <iostream>

int main(int argc, char *argv[]) {

  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return 0;
  }

  for (int i = 1; i < argc; i++) {

    std::string myString = argv[i];

    std::transform(myString.begin(), myString.end(), myString.begin(),
                   ::toupper);
    std::cout << myString;
  }
  std::cout << "\n";

  return 0;
}
