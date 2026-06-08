#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {

  PmergeMe algo;
  if (algo.parseAndFill(argc, argv) == false)
    return EXIT_FAILURE;

  std::cout << "Before:  ";
  algo.printMyVector();
  algo.startCounter();
  algo.sortMyVector();
  std::cout << "After:   ";
  algo.printMyVector();
  algo.stopCounter();
  algo.printMyVectorTime();

  algo.startCounter();
  algo.sortMyDeque();
  algo.stopCounter();
  algo.printMyDequeTime();

  return EXIT_SUCCESS;
}
