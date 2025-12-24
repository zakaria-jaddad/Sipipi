#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() { this->type = "Default AMateria Type"; }

AMateria::AMateria(std::string const &type) { this->type = type; }

AMateria::AMateria(const AMateria &other) {
  if (this != &other)
    *this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
  if (this == &other)
    return *this;
  return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return this->type; }

void AMateria::setType(const std::string &type) { this->type = type; }

void AMateria::use(ICharacter &target) {
  std::cout << "AMateria Uses " << this->type << " To " << target.getName()
            << std::endl;
}
