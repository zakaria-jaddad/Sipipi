
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
  std::cout << "WrongAnimal Default Constructor Called" << std::endl;
  this->type = "Default Wrong Animal Type";
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal Destructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
  this->type = other.getType();
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "WrongAnimal Assignment Operator Called" << std::endl;
  if (this == &other)
    return *this;
  this->type = other.getType();
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal Makes A Sound" << std::endl;
}

std::string WrongAnimal::getType() const { return this->type; }
