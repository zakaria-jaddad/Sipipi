#include "RPN.hpp"

RPN::RPN(const std::string expression) { this->expression = expression; }

RPN::RPN(const RPN &other) {
  this->expression = other.expression;
  this->notationStack = other.notationStack;
}

RPN &RPN::operator=(const RPN &other) {
  if (this == &other) {
    return *this;
  }
  this->expression = other.expression;
  this->notationStack = other.notationStack;
  return *this;
}

RPN::~RPN() {}

bool RPN::calculate() {
  // RPN "1 2 * 2 / 2 * 2 4 - +"
  std::istringstream polishNotation(this->expression);
  std::string tok;

  while (polishNotation >> tok) {
    if (isSingleDigit(tok)) {
      this->notationStack.push(tok[0] - '0');
    }
    else if (isOperator(tok)) {
      if (this->notationStack.size() < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
      }

      int operand_2 = this->notationStack.top();
      this->notationStack.pop();

      int operand_1 = this->notationStack.top();
      this->notationStack.pop();

      int result;
      switch (tok[0]) {
      case '+':
        result = operand_1 + operand_2;
        break;
      case '*':
        result = operand_1 * operand_2;
        break;
      case '-':
        result = operand_1 - operand_2;
        break;
      case '/':
        if (operand_2 == 0) {
          std::cerr << "Error" << std::endl;
          return 1;
        }
        result = operand_1 / operand_2;
        break;
      }
      this->notationStack.push(result);
    }
    else {
      std::cerr << "Error" << std::endl;
      return 1;
    }
  }

  if (this->notationStack.size() != 1) {
    std::cerr << "Error" << std::endl;
    return 1;
  }
  std::cout << this->notationStack.top() << std::endl;
  return 0;
}

/* -- private member functions -- */

bool RPN::isOperator(const std::string &tok) {
  return tok.size() == 1 &&
         (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/');
}

bool RPN::isSingleDigit(const std::string &tok) {
  return tok.size() == 1 && std::isdigit(static_cast<unsigned char>(tok[0]));
}
