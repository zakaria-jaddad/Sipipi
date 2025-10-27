#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
  this->name = name;
  this->w = NULL;
}

void HumanB::setWeapon(Weapon &newWeapon) { this->w = &newWeapon; }

void HumanB::attack(void) {
  // <name> attacks with their <weapon type>
  std::cout << this->name << "attacks with their" << this->w->getType() << "\n";
}
