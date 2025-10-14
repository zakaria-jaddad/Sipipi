#include "Contact.hpp"
#include <string>

static std::string formatString(std::string str) {

  if (str.size() <= 10) {

    for (int i = 0; i < 10 - int(str.size()); i++) {
      str += " ";
    }
    return str;
  }

  return str.substr(0, 9) + ".";
}

Contact::Contact(std::string firstName, std::string lastName,
                 std::string nickname, std::string phoneNumber,
                 std::string darkestSecret) {
  this->firstName = firstName;
  this->lastName = lastName;
  this->nickname = nickname;
  this->phoneNumber = phoneNumber;
  this->darkestSecret = darkestSecret;
}

std::string Contact::displayContact(void) const {
  std::string pipe = "|";
  return formatString(this->firstName) + pipe + formatString(this->lastName) +
         pipe + formatString(nickname) + pipe + formatString(phoneNumber) +
         pipe;
}
