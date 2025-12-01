#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat Default Constructor Called" << std::endl;
  this->type = "Cat";
}

Cat::~Cat() { std::cout << "Cat Destructor Called" << std::endl; }

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat Copy Constructor Called" << std::endl;
  this->getType() = other.getType();
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat Assignment Operator Called" << std::endl;
  if (this == &other)
    return *this;
  Animal::operator=(other);
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Cat Makes Meowing Sound" << std::endl;
}
