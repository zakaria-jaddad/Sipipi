#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {
  std::cout << "Ice Default Constructor Called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
  std::cout << "Ice Copy Constructor Called" << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
  std::cout << "Ice Assignment Operator Called" << std::endl;
  if (this == &other)
    return *this;
  AMateria::operator=(other);
  return *this;
}

Ice::~Ice() { std::cout << "Ice Default Destructor Called" << std::endl; }

AMateria *Ice::clone() const {

  AMateria *amateria_ptr = new Ice;
  amateria_ptr->setType(this->getType());
  return amateria_ptr;
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
