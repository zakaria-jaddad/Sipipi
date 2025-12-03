
#include "Cure.hpp"
#include "AMateria.hpp"
#include <ostream>

Cure::Cure() : AMateria("ice") {
  std::cout << "Cure Default Constructor Called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
  std::cout << "Cure Copy Constructor Called" << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
  std::cout << "Cure Assignment Operator Called" << std::endl;
  if (this == &other)
    return *this;
  AMateria::operator=(other);
  return *this;
}

Cure::~Cure() { std::cout << "Cure Default Destructor Called" << std::endl; }

AMateria *Cure::clone() const {

  AMateria *amateria_ptr = new Cure;
  amateria_ptr->setType(this->getType());
  return amateria_ptr;
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "\'s wounds" << std::endl;
}
