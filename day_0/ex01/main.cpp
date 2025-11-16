#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cctype>
#include <cstdlib>

static bool isAllWhiteSpaces(std::string str) {
  if (str.empty())
    return true;

  for (int i = 0; i < int(str.size()); i++) {
    if (!std::isspace(char(str[i]))) {
      return false;
    }
  }
  return true;
}

static bool isAllDigits(std::string str) {
  for (int i = 0; i < int(str.size()); i++) {
    //:: scopre resolution
    if (!std::isdigit(char(str[i]))) {
      return false;
    }
  }
  return true;
}

static bool isAllPrintable(std::string str) {

  if (str.empty())
    return false;
  for (int i = 0; i < int(str.size()); i++) {
    if (!std::isprint(char(str[i]))) {
      return false;
    }
  }
  return true;
}

static bool isAllAlpha(std::string str) {

  if (str.empty())
    return false;
  for (int i = 0; i < int(str.size()); i++) {
    if (!std::isalpha(char(str[i]))) {
      return false;
    }
  }
  return true;
}

static std::string trim(std::string s) {
  const std::string ws = " \t\v\n\r\f";
  size_t first = s.find_first_not_of(ws);
  if (first == std::string::npos)
    return "";
  size_t last = s.find_last_not_of(ws);
  return s.substr(first, last - first + 1);
}

static std::string getUserData(std::string prompt) {

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

static int getUserIndex() {
  std::string userIndex;
  while (true) {
    std::cout << "User Index: ";
    std::getline(std::cin, userIndex);
    if (std::cin.eof())
      exit(1);

    userIndex = trim(userIndex);

    if (isAllDigits(userIndex) == false) {
      std::cout << "Please enter only digits 0 <-> 7\n";
      continue;
    }

    int idx = std::atoi(userIndex.c_str());
    if (idx >= 0 && idx <= 7) {
      return idx;
    }

    std::cout << "Number must be between 0 and 7.\n";
  }
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
      std::string phoneNumber;
      std::string firstName;
      std::string lastName;
      std::string darkestSecret;
      while (isAllAlpha((firstName = getUserData("User First Name: "))) ==
             false)
        ;
      while (isAllAlpha((lastName = getUserData("User Last Name: "))) == false)
        ;
      std::string nickname = getUserData("User Nickname: ");
      while (isAllDigits((phoneNumber = getUserData("User Phone Number: "))) ==
             false)
        ;

      while (isAllPrintable((darkestSecret = getUserData(
                                 "User Darkest Secret: "))) == false)
        ;
      ;
      Contact userContact(firstName, lastName, nickname, phoneNumber,
                          darkestSecret);
      phony.addContact(userContact);
      std::cout << "Contact Saved\n";

    } else if (userInput == "SEARCH") {

      phony.displayContacts();

      int userIndex = getUserIndex();

      Contact c = phony.getContact(userIndex);
      if (c.isEmptyContact() == true)
        std::cout << "Contact Not Found\n";
      else {
        std::cout << "First Name: " << c.getFirstName() << "\n";
        std::cout << "Last Name: " << c.getLastName() << "\n";
        std::cout << "Nickname: " << c.getNickname() << "\n";
        std::cout << "Phone number: " << c.getPhoneNumber() << "\n";
        std::cout << "Darkest secret: " << c.getDarkestSecret() << "\n";
      }

    } else if (userInput == "EXIT") {
      exit(0);
    }
  }

  return 0;
}
