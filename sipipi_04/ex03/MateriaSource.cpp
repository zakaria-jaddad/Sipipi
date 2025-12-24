#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++)
    this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
  for (int i = 0; i < 4; i++)
    this->_inventory[i] = NULL;
  *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  if (this == &other)
    return *this;

  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] != NULL) {
      delete this->_inventory[i];
      this->_inventory[i] = NULL;
    }
  }

  for (int i = 0; i < 4; i++) {
    if (other._inventory[i] != NULL) {
      this->_inventory[i] = other._inventory[i]->clone();
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] != NULL)
      delete this->_inventory[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  if (m == NULL)
    return;
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] == NULL) {
      this->_inventory[i] = m;
      return;
    }
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] != NULL) {
      if (this->_inventory[i]->getType() == type)
        return this->_inventory[i]->clone();
    }
  }
  return 0;
}
