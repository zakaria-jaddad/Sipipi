#include "Cure.hpp"
#include "AMateria.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other) : AMateria(other) {}

Cure &Cure::operator=(const Cure &other) {
  if (this == &other)
    return *this;
  AMateria::operator=(other);
  return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const {

  AMateria *amateria_ptr = new Cure;
  amateria_ptr->setType(this->getType());
  return amateria_ptr;
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
