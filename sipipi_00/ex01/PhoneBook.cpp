#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>

PhoneBook::PhoneBook() { this->index = 0; }

void PhoneBook::addContact(Contact &contact) {

  this->contacts[this->index % 8] = contact;
  this->index = (this->index + 1) % 8;
}

void PhoneBook::displayContacts(void) const {
  std::cout << "index     |first name|last name |nickname  |\n";
  for (int i = 0; i < 8; i++) {
    if (this->contacts[i].isEmptyContact() == false) {
      std::cout << std::setw(10) << i << "|";
      this->contacts[i].displayContactInfo();
      std::cout << "\n";
    }
  }
}

Contact PhoneBook::getContact(int index) { return this->contacts[index]; }
