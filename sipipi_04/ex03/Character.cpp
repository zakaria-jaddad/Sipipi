#include "Character.hpp"

Character::Character() {
  this->_name = "Default Character Name";
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = NULL;
  }
}

Character::Character(std::string &name) {
  this->_name = name;
  for (int i = 0; i < 4; i++) {
    this->_inventory[i] = NULL;
  }
}

Character::Character(const Character &other) { *this = other; }

Character
