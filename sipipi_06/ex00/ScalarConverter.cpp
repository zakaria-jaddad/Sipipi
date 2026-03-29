#include "ScalarConverter.hpp"
#include <iomanip>

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
    // strtod converts string to double. endptr points to the first invalid char
    // (like 'f' in 42.0f)
    value = std::strtod(str.c_str(), &endptr);

    // If it failed to convert anything and isn't a pseudo literal, it's an
    // invalid input
    if (endptr == str.c_str() && !isPseudoLiteral(str)) {
      isImpossible = true;
    }
  }

  // 2. Print Char
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

  // 3. Print Int
  std::cout << "int: ";
  if (isImpossible || isPseudoLiteral(str) ||
      value < std::numeric_limits<int>::min() ||
      value > std::numeric_limits<int>::max()) {
    std::cout << "impossible" << std::endl;
  } else {
    std::cout << static_cast<int>(value) << std::endl;
  }

  // 4. Print Float
  std::cout << "float: ";
  if (isImpossible) {
    std::cout << "impossible" << std::endl;
  } else {
    float f = static_cast<float>(value);
    // Force .0 if it's a whole number (like 42.0f)
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
  }

  // 5. Print Double
  std::cout << "double: ";
  if (isImpossible) {
    std::cout << "impossible" << std::endl;
  } else {
    std::cout << std::fixed << std::setprecision(1) << value << std::endl;
  }
}
