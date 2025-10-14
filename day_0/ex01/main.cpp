#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void) {
  PhoneBook phone;

  Contact c("                           ", "Jaddad", "Bouyssaiiiiiiiiiiii",
            "1234567890", "afdlsfj");

  phone.addContact(c);
  phone.addContact(c);
  phone.addContact(c);
  phone.addContact(c);
  phone.addContact(c);
  phone.addContact(c);
  phone.addContact(c);

  phone.displayContacts();

  return 0;
}
