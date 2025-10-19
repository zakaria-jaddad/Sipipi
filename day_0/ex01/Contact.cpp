#include "Contact.hpp"
#include <string>

Contact::Contact(std::string firstName, std::string lastName,
                 std::string nickname, std::string phoneNumber,
                 std::string darkestSecret) {
  this->firstName = firstName;
  this->lastName = lastName;
  this->nickname = nickname;
  this->phoneNumber = phoneNumber;
  this->darkestSecret = darkestSecret;
}

Contact::Contact() {
  this->firstName = "";
  this->lastName = "";
  this->nickname = "";
  this->phoneNumber = "";
  this->darkestSecret = "";
}

std::string Contact::getContactInfo(void) const {
  std::string pipe = "|";
  return formatString(this->firstName) + pipe + formatString(this->lastName) +
         pipe + formatString(nickname) + pipe;
}

bool Contact::isEmptyContact(void) const {
  if (this->firstName == "")
    return true;
  return false;
}

std::string Contact::getFirstName() const { return firstName; }

std::string Contact::getLastName() const { return lastName; }

std::string Contact::getNickname() const { return nickname; }

std::string Contact::getPhoneNumber() const { return phoneNumber; }

std::string Contact::getDarkestSecret() const { return darkestSecret; }
