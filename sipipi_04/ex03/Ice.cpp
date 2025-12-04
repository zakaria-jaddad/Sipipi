#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice &other) : AMateria(other) {
}

Ice &Ice::operator=(const Ice &other) {
  if (this == &other)
    return *this;
  AMateria::operator=(other);
  return *this;
}

Ice::~Ice() {  }

AMateria *Ice::clone() const {

  AMateria *amateria_ptr = new Ice;
  amateria_ptr->setType(this->getType());
  return amateria_ptr;
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
