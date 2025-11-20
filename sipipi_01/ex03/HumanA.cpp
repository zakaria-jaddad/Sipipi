#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &w) : w(w) { this->name = name; }

void HumanA::attack(void) {
  std::cout << this->name << " attacks with their " << this->w.getType()
            << "\n";
}
