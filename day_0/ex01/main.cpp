#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

bool isAllWhiteSpaces(std::string str) {
  if (str.empty())
    return true;

  for (char c : str) {
    if (!isspace(c)) {
      return false;
    }
  }
  return true;
}
bool isAllDigits(std::string str) {
  for (char c : str) {
    if (!isdigit(c)) {
      return false;
    }
  }
  return true;
}

std::string trim(std::string str) {

  size_t first = str.find_first_not_of(" \t\v\n");
  if (first == std::string::npos)
    return (str);
  size_t last = str.find_first_not_of(" \t\v\n");
  if (last == std::string::npos)
    last = str.length() - 1;
  return str.substr(first, last - first + 1);
}

std::string getUserData(std::string prompt) {

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

int main(void) {

  std::string userInput;
  PhoneBook phony;

  while (true) {
    std::cout << "--> ";
    std::getline(std::cin, userInput);
    if (std::cin.eof())
      exit(1);
    if (userInput == "ADD") {
      std::string firstName = getUserData("User First Name: ");
      std::string lastName = getUserData("User Last Name: ");
      std::string nickname = getUserData("User Nickname: ");
      std::string phoneNumber = getUserData("User Phone NUmber: ");
      while (isAllDigits(phoneNumber) == false)
        std::string phoneNumber = getUserData("User Phone NUmber: ");
      std::string darkestSecret = getUserData("User Darkest Secret: ");

      Contact userContact(firstName, lastName, nickname, phoneNumber,
                          darkestSecret);

      phony.addContact(userContact);

      std::cout << "Contact have been added\n";

    } else if (userInput == "SEARCH") {
      phony.displayContacts();
    } else if (userInput == "EXIT") {
      exit(0);
    }
  }

  return 0;
}
