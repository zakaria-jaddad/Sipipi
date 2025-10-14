#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

private:
  Contact contacts[8];
  static int index;

public:
  PhoneBook();
  void addContact(Contact &contact);
  void displayContacts(void) const;
};

#endif // !PHONEBOOK_HPP
