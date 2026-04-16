#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; };

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isPseudoLiteral(const std::string &s) {
  return (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" ||
          s == "+inff" || s == "-inff");
}

static bool isChar(const std::string &s) {
  return (s.length() == 1 && !std::isdigit(s[0]));
}

void ScalarConverter::convert(const std::string str) {
  double value = 0.0;
  bool isImpossible = false;

  if (isChar(str)) {
    value = static_cast<double>(str[0]);
  } else {
    char *endptr;
    value = std::strtod(str.c_str(), &endptr);

    if (endptr == str.c_str() && isPseudoLiteral(str) == false) {
      isImpossible = true;
    }
    if (*endptr != '\0' && *endptr != 'f') {
      isImpossible = true;
    }
  }

  // char
  std::cout << "char: ";
  if (isImpossible || isPseudoLiteral(str) ||
      value < std::numeric_limits<char>::min() ||
      value > std::numeric_limits<char>::max()) {
    std::cout << "impossible" << std::endl;
  } else {
    char c = static_cast<char>(value);
    if (std::isprint(c))
      std::cout << "'" << c << "'" << std::endl;
    else
      std::cout << "Non displayable" << std::endl;
  }

  // int
  std::cout << "int: ";
  if (isImpossible || isPseudoLiteral(str) ||
      value < std::numeric_limits<int>::min() ||
      value > std::numeric_limits<int>::max()) {
    std::cout << "impossible" << std::endl;
  } else {
    std::cout << static_cast<int>(value) << std::endl;
  }

  // float
  std::cout << "float: ";
  if (isImpossible) {
    std::cout << "impossible" << std::endl;
  } else {
    float f = static_cast<float>(value);
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
  }

  // double
  std::cout << "double: ";
  if (isImpossible) {
    std::cout << "impossible" << std::endl;
  } else {
    std::cout << std::fixed << std::setprecision(1) << value << std::endl;
  }
}
