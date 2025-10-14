#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {

private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;

public:
  Contact(std::string firstName, std::string lastName, std::string nickname,
          std::string phoneNumber, std::string darkestSecret);

  std::string displayContact(void) const;
};

#endif // !PHONEBOOK_HPP
