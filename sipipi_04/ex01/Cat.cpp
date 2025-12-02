#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat Default Constructor Called" << std::endl;
  this->type = "Cat";
  this->brain = new Brain();
}

Cat::~Cat() { 
  std::cout << "Cat Destructor Called" << std::endl; 
  delete this->brain;
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat Copy Constructor Called" << std::endl;
  *this = other;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat Assignment Operator Called" << std::endl;
  if (this == &other)
    return *this;
  Animal::operator=(other);
  this->brain = new Brain();
  for (int i = 0; i < 100; i++) {
    this->brain->ideas[i] = other.brain->ideas[i];
  }
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Cat Makes Meowing Sound" << std::endl;
}
