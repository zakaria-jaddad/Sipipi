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
  void addNumbers(const std::vector<int> &numbers);

private:
  unsigned int _N;
  std::vector<int> _numbers;
};

#endif
