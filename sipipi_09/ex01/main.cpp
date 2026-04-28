#include <cctype>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <stack>

static bool isOperator(const std::string &tok) {
  return tok.size() == 1 &&
         (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/');
}

static bool isSingleDigit(const std::string &tok) {
  return tok.size() == 1 && std::isdigit(static_cast<unsigned char>(tok[0]));
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0]
              << " <inverted Polish mathematical expression>" << std::endl;
    return 1;
  }

  std::stack<ssize_t> notationStack;

  // RPN "1 2 * 2 / 2 * 2 4 - +"
  std::istringstream polishNotation(argv[1]);
  std::string tok;

  // Process each token in the RPN expression
  while (polishNotation >> tok) {
    if (isSingleDigit(tok)) {
      notationStack.push(tok[0] - '0');
    } else if (isOperator(tok)) {
      if (notationStack.size() < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
      }

      ssize_t operand_2 = notationStack.top();
      notationStack.pop();

      ssize_t operand_1 = notationStack.top();
      notationStack.pop();

      ssize_t result;
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
      notationStack.push(result);
    } else {
      std::cerr << "Error" << std::endl;
      return 1;
    }
  }

  if (notationStack.size() != 1) {
    std::cerr << "Error" << std::endl;
    return 1;
  }
  std::cout << notationStack.top() << std::endl;
  return 0;
}
