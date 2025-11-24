#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {

  this->_name = "Default ScavTrap";
  this->_health = 100;
  this->_energy = 50;
  this->_damage = 20;
  std::cout << "ScavTrap Name Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

  this->_health = 100;
  this->_energy = 50;
  this->_damage = 20;
  std::cout << "ScavTrap " << name << " Constructor Called" << std::endl;
}
ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor Called" << std::endl;
}

void ScavTrap::guardGate(void) const {

  std::cout << this->_name << " Now in Gate Keeping Mode" << std::endl;
}
