#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <stack>

class RPN {
private:
  RPN();
  bool isOperator(const std::string &tok);
  bool isSingleDigit(const std::string &tok);
  std::stack<int> notationStack;
  std::string expression;

public:
  RPN(const std::string expression);
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  ~RPN();
  bool calculate();
};

#endif // !RPN_HPP
