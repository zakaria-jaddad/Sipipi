#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
  this->_inventoryIndex = 0;
  for (int i = 0; i < 4; i++)
    this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) { *this = other; }

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  if (this == &other)
    return *this;

  for (int i = 0; i < this->_inventoryIndex; i++) {
    delete this->_inventory[i];
  }
  for (int i = 0; i < other._inventoryIndex; i++) {
    this->_inventory[i] = other._inventory[i]->clone();
  }
  this->_inventoryIndex = other._inventoryIndex;

  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < this->_inventoryIndex; i++) {
    delete this->_inventory[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {

  if (this->_inventoryIndex > 3)
    return;
  if (m == NULL)
    return;
  this->_inventory[this->_inventoryIndex++] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type) {

  for (int i = 0; i < this->_inventoryIndex; i++) {
    if (this->_inventory[i]->getType() == type)
      return this->_inventory[i]->clone();
  }
  return 0;
}
