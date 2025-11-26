
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {

  this->_name = "Default DiamondTrap";
  this->_health = 100;
  this->_energy = 50;
  this->_damage = 20;
  std::cout << "DiamondTrap Name Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name) {

  this->_health = 100;
  this->_energy = 50;
  this->_damage = 20;
  std::cout << "DiamondTrap " << name << " Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : FragTrap(other), ScavTrap(other) {
  std::cout << "DiamondTrap Copy Constructor Called" << std::endl;
  DiamondTrap::operator=(other);
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "DiamondTrap Copy Assignment Operator Called" << std::endl;
  if (this != &other) {
    FragTrap::operator=(other);
    ClapTrap::operator=(other);
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap Destructor Called" << std::endl;
}

void DiamondTrap::guardGate(void) const {

  std::cout << this->_name << " Now in Gate Keeping Mode" << std::endl;
}
