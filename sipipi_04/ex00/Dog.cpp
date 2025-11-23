#include "Dog.hpp"

Dog::Dog() {
  std::cout << "Dog Default Constructor Called" << std::endl;
  this->type = "Dog";
}

Dog::~Dog() { std::cout << "Dog Destructor Called" << std::endl; }

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog Copy Constructor Called" << std::endl;
  this->getType() = other.getType();
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog Assignment Operator Called" << std::endl;
  if (this == &other)
    return *this;
  Animal::operator=(other);
  return *this;
}

void Dog::makeSound() const {
  std::cout << "Dog Makes Barking Sound" << std::endl;
}
