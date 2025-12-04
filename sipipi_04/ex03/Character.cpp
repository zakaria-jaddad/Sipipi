#include "Character.hpp"

Character::Character() {
  this->_name = "Default Character Name";
  this->_currentIndex = 0;
  this->_currentUnequippedIndex = 0;
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = NULL;
    this->_unequippedInventory[i] = NULL;
  }
}

Character::Character(std::string &name) {
  this->_name = name;
  this->_currentIndex = 0;
  this->_currentUnequippedIndex = 0;
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = NULL;
    this->_unequippedInventory[i] = NULL;
  }
}

Character::Character(const Character &other) { *this = other; }

Character &Character::operator=(const Character &other) {
  if (this == &other)
    return *this;
  this->_name = other._name;
  for (int i = 0; i < this->_currentIndex; i++) {
    delete this->_inventory[i];
  }
  this->_currentIndex = other._currentIndex;
  this->_currentUnequippedIndex = other._currentUnequippedIndex;
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = other._inventory[i]->clone();
    this->_unequippedInventory[i] = other._unequippedInventory[i];
  }
}

Character::~Character() {

  for (int i = 0; i < this->_currentIndex; i++) {
    delete this->_inventory[i];
  }
  for (int i = 0; i < this->_currentUnequippedIndex; i++) {
    delete this->_unequippedInventory[i];
  }
}

std::string const &Character::getName() const { return this->_name; }

void Character::setName(std::string name) { this->_name = name; }

void Character::equip(AMateria *m) {
  if (m == NULL)
    return;
  if (this->_currentIndex > 3)
    return;

  this->_inventory[this->_currentIndex++] = m;
}

void Character::unequip(int idx) {
  if (idx > 3 || idx < 0)
    return;
  if (this->_inventory[idx] == NULL)
    return;

  if (this->_currentUnequippedIndex > 3)
    return;
  this->_unequippedInventory[this->_currentUnequippedIndex++] =
      this->_inventory[idx];
  this->_inventory[idx] = NULL;
}
