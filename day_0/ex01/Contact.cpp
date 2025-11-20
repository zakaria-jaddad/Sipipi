#include "Contact.hpp"

static void printFormatString(std::string str) {

  ;
  int size = str.size();
  if (size > 10) {
    std::cout << std::setw(10) << (str.substr(0, 9) + ".");
    return;
  }
  std::cout << std::setw(10) << str;
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

Contact::Contact() {
  this->firstName = "";
  this->lastName = "";
  this->nickname = "";
  this->phoneNumber = "";
  this->darkestSecret = "";
}

void Contact::displayContactInfo(void) const {
  std::string pipe = "|";
  printFormatString(this->firstName);
  std::cout << pipe;
  printFormatString(this->lastName);
  std::cout << pipe;
  printFormatString(nickname);
  std::cout << pipe;
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
