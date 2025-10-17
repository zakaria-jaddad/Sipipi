#include "main.hpp"

int main(void) {

  std::string userInput;
  PhoneBook phony;

  while (true) {
    std::cout << "--> ";
    std::getline(std::cin, userInput);
    if (std::cin.eof())
      exit(1);
    if (userInput == "ADD") {
      std::string phoneNumber;
      std::string firstName = getUserData("User First Name: ");
      std::string lastName = getUserData("User Last Name: ");
      std::string nickname = getUserData("User Nickname: ");
      while (isAllDigits((phoneNumber = getUserData("User Phone Number: "))) ==
             false)
        ;
      std::string darkestSecret = getUserData("User Darkest Secret: ");

      Contact userContact(firstName, lastName, nickname, phoneNumber,
                          darkestSecret);

      phony.addContact(userContact);

      std::cout << "Contact Saved\n";
      std::cout << userContact.getContactInfo() << "\n";

    } else if (userInput == "SEARCH") {

      phony.displayContacts();

      int userIndex = getUserIndex();

      Contact c = phony.getContact(userIndex);
      if (c.isEmptyContact() == true)
        std::cout << "Contact Not Found\n";
      else {
        std::cout << "First Name: " << c.getFirstName() << "\n";
        std::cout << "Last Name: " << c.getLastName() << "\n";
        std::cout << "Nickname: " << c.getNickname() << "\n";
        std::cout << "Phone number: " << c.getPhoneNumber() << "\n";
        std::cout << "Darkest secret: " << c.getDarkestSecret() << "\n";
      }

    } else if (userInput == "EXIT") {
      exit(0);
    }
  }

  return 0;
}
