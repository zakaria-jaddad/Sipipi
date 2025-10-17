#ifndef MAIN_HPP
#define MAIN_HPP

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

static inline bool isAllWhiteSpaces(std::string str) {
  if (str.empty())
    return true;

  for (char c : str) {
    if (!isspace(c)) {
      return false;
    }
  }
  return true;
}

static inline bool isAllDigits(std::string str) {
  for (char c : str) {
    if (!::isdigit(c)) {
      return false;
    }
  }
  return true;
}

static inline std::string trim(std::string s) {
  const std::string ws = " \t\v\n\r\f";
  size_t first = s.find_first_not_of(ws);
  if (first == std::string::npos)
    return "";
  size_t last = s.find_last_not_of(ws);
  return s.substr(first, last - first + 1);
}
static inline std::string getUserData(std::string prompt) {

  std::string userData;

  for (; true;) {
    std::cout << prompt;
    std::getline(std::cin, userData);
    if (std::cin.eof())
      exit(1);
    if (isAllWhiteSpaces(userData) == false)
      break;
  }

  return trim(userData);
}

static inline int getUserIndex() {
  std::string userIndex;
  while (true) {
    std::cout << "User Index: ";
    std::getline(std::cin, userIndex);
    if (std::cin.eof())
      exit(1);

    userIndex = trim(userIndex);

    if (isAllDigits(userIndex) == false) {
      std::cout << "Please enter only digits (0-7).\n";
      continue;
    }

    int idx = std::stoi(userIndex);
    if (idx >= 0 && idx <= 9) {
      return idx;
    }

    std::cout << "Number must be between 0 and 7.\n";
  }
}

#endif // !MAIN_HPP
