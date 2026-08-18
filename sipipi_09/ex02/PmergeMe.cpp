#include "PmergeMe.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <ctime>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <string.h>
#include <utility>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
  this->my_vector = other.my_vector;
  this->my_deque = other.my_deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this == &other)
    return *this;
  this->my_vector = other.my_vector;
  this->my_deque = other.my_deque;
  return *this;
}

PmergeMe::~PmergeMe() {}

bool comparePairs(std::pair<int, int> a, std::pair<int, int> b) {
  return a.first < b.first;
}

bool PmergeMe::isAllDigits(const std::string s) {
  for (size_t i = 0; i < s.size(); i++) {
    if (!std::isdigit(s[i])) {
      return false;
    }
  }
  return true;
}

bool PmergeMe::parseAndFill(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error: No numbers provided." << std::endl;
    return false;
  }
  for (int i = 1; i < argc; i++) {
    if (isAllDigits(argv[i]) == false) {
      std::cerr << "Invalid Number" << std::endl;
      return false;
    }
    if (strlen(argv[i]) > 10) {
      std::cerr << "Number Too Big" << std::endl;
      return false;
    }

    long val = std::atol(argv[i]);
    if (val > std::numeric_limits<int>::max() || val < 0) {
      std::cerr << "Number Too Big" << std::endl;
      return false;
    }
    my_vector.push_back(val);
    my_deque.push_back(val);
  }
  return true;
}

void PmergeMe::printMyVector() const {
  for (size_t i = 0; i < my_vector.size(); i++) {
    std::cout << my_vector[i] << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::printMyDeque() const {
  for (size_t i = 0; i < my_deque.size(); i++) {
    std::cout << my_deque[i] << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::startCounter() { this->_start = clock(); }

void PmergeMe::stopCounter() { this->_end = clock(); }

void PmergeMe::printMyVectorTime() {
  double seconds =
      static_cast<double>(this->_end - this->_start) / CLOCKS_PER_SEC;

  double elapsed = seconds * 1000000;

  std::cout << "Time to process a range of " << my_vector.size()
            << " elements with std::vector : " << std::fixed
            << std::setprecision(5) << elapsed << " us" << std::endl;
}

void PmergeMe::printMyDequeTime() {
  double seconds =
      static_cast<double>(this->_end - this->_start) / CLOCKS_PER_SEC;

  double elapsed = seconds * 1000000;

  std::cout << "Time to process a range of " << my_deque.size()
            << " elements with std::deque : " << std::fixed
            << std::setprecision(5) << elapsed << " us" << std::endl;
}

void PmergeMe::sortMyVector() {
  int straggler = -1;
  std::vector<std::pair<int, int> > pairs;
  if (this->my_vector.size() % 2 != 0) {
    straggler = this->my_vector[this->my_vector.size() - 1];
    this->my_vector.pop_back();
  }
  for (size_t i = 0; i < my_vector.size(); i += 2) {
    int first = my_vector[i];
    int second = my_vector[i + 1];
    if (first < second) {
      std::swap(first, second);
    }
    pairs.push_back(std::make_pair(first, second));
  }

  // sort pairs
  std::sort(pairs.begin(), pairs.end(), comparePairs);

  // main chain and pend
  std::vector<int> mainChain;
  std::vector<int> pend;

  for (size_t i = 0; i < pairs.size(); i++) {
    mainChain.push_back(pairs[i].first);
    pend.push_back(pairs[i].second);
  }

  // remove the first element from the pend and insert it at the biggining of
  // the mainChain
  mainChain.insert(mainChain.begin(), pend[0]);

  // generate the sequance.
  std::vector<int> jacob;
  jacob.push_back(0);
  jacob.push_back(1);
  while (static_cast<size_t>(jacob.back()) < pend.size()) {
    int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
    jacob.push_back(next);
  }

  // insertion order
  std::vector<int> insertionOrder;
  size_t last = 1;
  for (size_t i = 2; i < jacob.size(); i++) {

    size_t end = std::min(jacob[i], static_cast<int>(pend.size()));

    for (size_t j = end; j > last; j--) {
      insertionOrder.push_back(j - 1);
    }
    last = end;
    if (last == pend.size())
      break;
  }
  for (size_t j = pend.size(); j > last; j--) {
    insertionOrder.push_back(j - 1);
  }

  // iterating over insertionOrder and inserting numbers
  for (size_t i = 0; i < insertionOrder.size(); i++) {
    int pos = insertionOrder[i];
    int elementToInsert = pend[pos];
    std::vector<int>::iterator it =
        std::lower_bound(mainChain.begin(), mainChain.end(), elementToInsert);
    mainChain.insert(it, elementToInsert);
  }

  if (straggler != -1) {
    std::vector<int>::iterator it =
        std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
    mainChain.insert(it, straggler);
  }

  my_vector = mainChain;
}

void PmergeMe::sortMyDeque() {
  int straggler = -1;
  std::deque<std::pair<int, int> > pairs;
  if (this->my_deque.size() % 2 != 0) {
    straggler = this->my_deque[this->my_deque.size() - 1];
    this->my_deque.pop_back();
  }
  for (size_t i = 0; i < my_deque.size(); i += 2) {
    int first = my_deque[i];
    int second = my_deque[i + 1];
    if (first < second) {
      std::swap(first, second);
    }
    pairs.push_back(std::make_pair(first, second));
  }

  // sort pairs
  std::sort(pairs.begin(), pairs.end(), comparePairs);

  // main chain and pend
  std::deque<int> mainChain;
  std::deque<int> pend;

  for (size_t i = 0; i < pairs.size(); i++) {
    mainChain.push_back(pairs[i].first);
    pend.push_back(pairs[i].second);
  }

  // remove the first element from the pend and insert it at the biggining of
  // the mainChain
  mainChain.insert(mainChain.begin(), pend[0]);

  // generate the sequance.
  std::deque<int> jacob;
  jacob.push_back(0);
  jacob.push_back(1);
  while (static_cast<size_t>(jacob.back()) < pend.size()) {
    int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
    jacob.push_back(next);
  }

  // insertion order
  std::deque<int> insertionOrder;
  size_t last = 1;
  for (size_t i = 2; i < jacob.size(); i++) {

    size_t end = std::min(jacob[i], static_cast<int>(pend.size()));

    for (size_t j = end; j > last; j--) {
      insertionOrder.push_back(j - 1);
    }
    last = end;
    if (last == pend.size())
      break;
  }
  for (size_t j = pend.size(); j > last; j--) {
    insertionOrder.push_back(j - 1);
  }

  // iterating over insertionOrder and inserting numbers
  for (size_t i = 0; i < insertionOrder.size(); i++) {
    int pos = insertionOrder[i];
    int elementToInsert = pend[pos];
    std::deque<int>::iterator it =
        std::lower_bound(mainChain.begin(), mainChain.end(), elementToInsert);
    mainChain.insert(it, elementToInsert);
  }

  if (straggler != -1) {
    std::deque<int>::iterator it =
        std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
    mainChain.insert(it, straggler);
  }

  my_deque = mainChain;
}
