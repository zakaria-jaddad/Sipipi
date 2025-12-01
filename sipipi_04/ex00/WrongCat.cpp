
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  std::cout << "WrongCat Default Constructor Called" << std::endl;
  this->type = "WrongCat";
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat Destructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "WrongCat Copy Constructor Called" << std::endl;
  this->getType() = other.getType();
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "WrongCat Assignment Operator Called" << std::endl;
  if (this == &other)
    return *this;
  WrongAnimal::operator=(other);
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "WrongCat Makes Meowing Sound" << std::endl;
}
