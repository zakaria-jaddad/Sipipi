#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {

  this->_name = "Default DiamondTrap Name";
  this->_health = FragTrap::_health;
  this->_energy = ScavTrap::_energy;
  this->_damage = FragTrap::_damage;
  std::cout << "DiamondTrap Name Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {

  this->_name = name;
  this->_health = FragTrap::_health;
  this->_energy = ScavTrap::_energy;
  this->_damage = FragTrap::_damage;
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
    ScavTrap::operator=(other);
    this->_name = other.getName();
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap Destructor Called" << std::endl;
}

void DiamondTrap::whoAmI() {
  std::cout
      << "=================================================================="
      << std::endl;

  std::cout << "DiamondTrap Name: | " << this->_name << " | ClapTrap Name | "
            << ClapTrap::_name << std::endl;

  std::cout
      << "=================================================================="
      << std::endl;
}
