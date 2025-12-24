#include "Character.hpp"

Character::Character() {
  this->_name = "Default Character Name";
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = NULL;
  }
}

Character::Character(const std::string &name) {
  this->_name = name;
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = NULL;
  }
}

Character::Character(const Character &other) {
  this->_name = other._name;
  for (int i = 0; i < 4; i++) {
    if (other._inventory[i] != NULL)
      this->_inventory[i] = other._inventory[i]->clone();
    else
      this->_inventory[i] = NULL;
  }
}

Character &Character::operator=(const Character &other) {
  if (this == &other)
    return *this;

  this->_name = other._name;

  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] != NULL) {
      delete this->_inventory[i];
      this->_inventory[i] = NULL;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (other._inventory[i] != NULL)
      this->_inventory[i] = other._inventory[i]->clone();
  }

  return *this;
}

Character::~Character() {
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] != NULL)
      delete this->_inventory[i];
  }
}

std::string const &Character::getName() const { return this->_name; }

void Character::setName(std::string name) { this->_name = name; }

void Character::equip(AMateria *m) {
  if (m == NULL)
    return;
  for (int i = 0; i < 4; i++) {
    if (this->_inventory[i] == NULL) {
      this->_inventory[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx > 3 || idx < 0)
    return;
  if (this->_inventory[idx] == NULL)
    return;

  this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || idx > 3)
    return;
  if (this->_inventory[idx] == NULL)
    return;

  this->_inventory[idx]->use(target);
}
