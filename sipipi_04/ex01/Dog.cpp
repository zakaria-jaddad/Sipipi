#include "Dog.hpp"

Dog::Dog() : Animal() {
  std::cout << "Dog Default Constructor Called" << std::endl;
  this->type = "Dog";
  this->brain = new Brain();
}

Dog::~Dog() { 
  std::cout << "Dog Destructor Called" << std::endl; 
  delete this->brain;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog Copy Constructor Called" << std::endl;
  *this = other;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog Assignment Operator Called" << std::endl;
  if (this == &other)
    return *this;
  Animal::operator=(other);
  this->brain = new Brain();
  for (int i = 0; i < 100; i++) {
    this->brain->ideas[i] = other.brain->ideas[i];
  }
  return *this;
}

void Dog::makeSound() const {
  std::cout << "Dog Makes Barking Sound" << std::endl;
}
