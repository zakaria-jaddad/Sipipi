#include "Animal.hpp"

Animal::Animal() {
  std::cout << "Animal Default Constructor Called" << std::endl;
  this->type = "Default Animal Type";
}

Animal::~Animal() { std::cout << "Animal Destructor Called" << std::endl; }

Animal::Animal(const Animal &other) {
  std::cout << "Animal Copy Constructor Called" << std::endl;
  this->type = other.getType();
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal Assignment Operator Called" << std::endl;
  if (this == &other)
    return *this;
  this->type = other.getType();
  return *this;
}

std::string Animal::getType() const { return this->type; }
