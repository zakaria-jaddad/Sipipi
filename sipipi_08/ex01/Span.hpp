#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>

class Span {
public:
  Span(unsigned int N);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();
  void addNumber(int number);
  int shortestSpan() const;
  int longestSpan() const;
  void addNumbers(const std::vector<int> &numbers) {
    if (_numbers.size() + numbers.size() > _N) {
      throw std::out_of_range("Cannot add more numbers, capacity will be exceeded.");
    }
    _numbers.insert(_numbers.end(), numbers.begin(), numbers.end());
  }

private:
  unsigned int _N;
  std::vector<int> _numbers;
};

#endif
