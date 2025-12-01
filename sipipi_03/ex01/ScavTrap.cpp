#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {

  this->_name = "Default ScavTrap Name";
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

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "ScavTrap Copy Constructor Called" << std::endl;
  ScavTrap::operator=(other);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "ScavTrap Copy Assignment Operator Called" << std::endl;
  if (this != &other)
    ClapTrap::operator=(other);
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor Called" << std::endl;
}

void ScavTrap::guardGate(void) const {

  std::cout << this->_name << " Now in Gate Keeping Mode" << std::endl;
}
