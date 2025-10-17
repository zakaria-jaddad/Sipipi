#include "PhoneBook.hpp"
#include "Contact.hpp"

int PhoneBook::index = 0;

PhoneBook::PhoneBook() {}

void PhoneBook::addContact(Contact &contact) {

  this->contacts[this->index % 8] = contact;
  this->index = (this->index + 1) % 8;
}

void PhoneBook::displayContacts(void) const {
  if (this->contacts[0].isEmptyContact() == false)
    std::cout << "index     |first name|last name |nickname  |\n";
  for (int i = 0; i < 8; i++) {
    if (this->contacts[i].isEmptyContact() == true)
      return;
    std::cout << i << +"         |" + this->contacts[i].getContactInfo()
              << "\n";
  }
}

Contact PhoneBook::getContact(int index) { return this->contacts[index]; }
