#include "Weapon.hpp"

Weapon::Weapon(std::string type) { this->type = type; }

Weapon::Weapon(void) { this->type = ""; }

const std::string &Weapon::getType(void) { return this->type; }

void Weapon::setType(std::string newType) { this->type = newType; }
