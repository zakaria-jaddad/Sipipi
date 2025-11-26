#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {

  this->_name = "Default FragTrap";
  this->_health = 100;
  this->_energy = 100;
  this->_damage = 30;
  std::cout << "FragTrap Name Constructor Called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {

  this->_health = 100;
  this->_energy = 100;
  this->_damage = 30;
  std::cout << "FragTrap " << name << " Constructor Called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "FragTrap Copy Constructor Called" << std::endl;
  FragTrap::operator=(other);
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "FragTrap Copy Assignment Operator Called" << std::endl;
  if (this != &other)
    ClapTrap::operator=(other);
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap Destructor Called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << this->_name << " High-Five Time!" << std::endl;
}
