#include "Zombie.hpp"

void Zombie::announce(void) {

  std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name) { this->name = name; }

Zombie::Zombie(void) {};

Zombie::~Zombie(void) { std::cout << this->name << " destroyed\n"; }
