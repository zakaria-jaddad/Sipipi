#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <ostream>
#include <vector>

class PmergeMe {
private:
  std::vector<int> my_vector;
  std::deque<int> my_deque;
  clock_t _start;
  clock_t _end;
  bool isAllDigits(const std::string s);

public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();
  bool parseAndFill(int argc, char **argv);
  void printMyVector() const;
  void printMyDeque() const;
  void startCounter();
  void stopCounter();
  void sortMyVector();
  void sortMyDeque();
  void printMyVectorTime();
  void printMyDequeTime();
};

#endif
