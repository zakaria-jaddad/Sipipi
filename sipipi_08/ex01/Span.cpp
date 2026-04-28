#include "Span.hpp"
#include <limits>
#include <algorithm>

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _N = other._N;
    _numbers = other._numbers;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
  if (_numbers.size() >= _N) {
    throw std::out_of_range("Cannot add more numbers, capacity reached.");
  }
  _numbers.push_back(number);
}

int Span::shortestSpan() const {
  if (_numbers.size() <= 1) {
    throw std::logic_error("Not enough numbers to find a span.");
  }
  std::vector<int> temp = _numbers;
  std::sort(temp.begin(), temp.end());
  int shortest = std::numeric_limits<int>::max();
  for (size_t i = 1; i < temp.size(); i++) {
    int span = temp[i] - temp[i - 1];
    if (span < shortest) {
      shortest = span;
    }
  }
  return shortest;
}

int Span::longestSpan() const {
  if (_numbers.size() <= 1) {
    throw std::logic_error("Not enough numbers to find a span.");
  }
  std::vector<int> temp = _numbers;
  std::sort(temp.begin(), temp.end());
  int longest = temp[temp.size() - 1] - temp[0];
  return longest;
}
