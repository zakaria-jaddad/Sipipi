#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

static inline std::string formatString(std::string str) {

  int size = str.size();
  if (size <= 10) {

    for (int i = 0; i < 10 - int(size); i++) {
      str += " ";
    }
    return str;
  }

  return str.substr(0, 9) + ".";
}

class Contact {

private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;

public:
  Contact(void);
  Contact(std::string firstName, std::string lastName, std::string nickname,
          std::string phoneNumber, std::string darkestSecret);

  std::string getContactInfo(void) const;
  bool isEmptyContact(void) const;
};

#endif // !PHONEBOOK_HPP
