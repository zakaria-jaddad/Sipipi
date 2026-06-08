
#include "RPN.hpp"

int main(int argc, char *argv[]) {

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0]
              << " <inverted Polish mathematical expression>" << std::endl;
    return 1;
  }

  RPN rpn(argv[1]);
  rpn.calculate();
  return 0;
}
