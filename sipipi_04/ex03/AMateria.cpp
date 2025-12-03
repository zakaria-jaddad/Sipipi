#include "AMateria.hpp"

AMateria::AMateria() { this->type = "Default AMateria Type"; }

AMateria::AMateria(std::string const &type) {
  std::cout << "AMateria Default Constructor Called" << std::endl;
  this->type = type;
}

AMateria::AMateria(const AMateria &other) {
  std::cout << "AMateria Copy Constructor Called" << std::endl;
  if (this != &other)
    *this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
  std::cout << "AMateria Assignment Operator Called" << std::endl;
  if (this == &other)
    return *this;
  this->type = other.getType();
  return *this;
}

AMateria::~AMateria() {
  std::cout << "Default AMateria Destructor Called" << std::endl;
}

std::string const &AMateria::getType() const { return this->type; }

void AMateria::setType(const std::string &type) { this->type = type; }

void AMateria::use(ICharacter &target) {
  std::cout << "AMateria Uses " << this->type << " To " << target.getName()
            << std::endl;
}
