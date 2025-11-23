#include "Cat.hpp"

Cat::Cat() {
  std::cout << "Cat Default Constructor Called" << std::endl;
  this->type = "Cat";
}

Cat::~Cat() { std::cout << "Cat Destructor Called" << std::endl; }

Cat::Cat(const Cat &other) { this->type = other.getType(); }

Cat &Cat::operator=(const Cat &other) {
  if (this == &other)
    return *this;
  this->type = other.getType();
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Cat Makes Meowing Sound" << std::endl;
}
