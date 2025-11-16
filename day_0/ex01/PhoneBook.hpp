#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {

private:
  Contact contacts[8];
  int index;

public:
  PhoneBook();
  void addContact(Contact &contact);
  void displayContacts(void) const;
  Contact getContact(int index);
};

#endif // !PHONEBOOK_HPP
