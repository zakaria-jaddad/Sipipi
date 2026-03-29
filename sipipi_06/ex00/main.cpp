#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {

  if (argc != 2) {
    return EXIT_FAILURE;
  }
  std::string str(argv[1]);
  ScalarConverter::convert(str);
  return 0;
}
