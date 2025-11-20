#include <iostream>

int main(int argc, char *argv[]) {

  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return 0;
  }

  for (int i = 1; i < argc; i++) {

    std::string myString = argv[i];

    for (int j = 0; j < int(myString.size()); j++) {
      if (std::islower(myString[j])) {
        std::cout << char(std::toupper(myString[j]));
        continue;
      }
      std::cout << myString[j];
    }
  }
  std::cout << "\n";

  return 0;
}
