#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
  this->_name = "Default";
  this->_health = 10;
  this->_energy = 10;
  this->_damage = 0;
  std::cout << "ClapTrap Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {

  this->_name = name;
  this->_health = 10;
  this->_energy = 10;
  this->_damage = 0;
  std::cout << "ClapTrap " << name << " Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  std::cout << "ClapTrap Copy Constructor Called" << std::endl;
  this->_name = other.getName();
  this->_health = other.getHealth();
  this->_energy = other.getEnergy();
  this->_damage = other.getDamage();
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap Destructor Called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "Copy Assignment Operator Called" << std::endl;
  if (this == &other)
    return *this;
  this->_name = other.getName();
  this->_health = other.getHealth();
  this->_energy = other.getEnergy();
  this->_damage = other.getDamage();
  return *this;
}

std::string ClapTrap::getName(void) const { return this->_name; }

unsigned int ClapTrap::getHealth(void) const { return this->_health; }

unsigned int ClapTrap::getEnergy(void) const { return this->_energy; }

unsigned int ClapTrap::getDamage(void) const { return this->_damage; }

void ClapTrap::attack(const std::string &target) {
  if (this->_energy - 1 <= 0) {
    std::cout << "ClapTrap " << this->_name << " Has No Energy Left"
              << std::endl;
    return;
  }
  if (this->_health == 0) {
    std::cout << "ClapTrap " << this->_name << " Has No Health Left"
              << std::endl;
    return;
  }
  std::cout << "ClapTrap " << this->_name << " Attacked " << target
            << std::endl;
  this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount) {

  if (amount > this->_health)
    this->_health = amount;
  this->_health -= amount;
  std::cout << "ClapTrap " << this->_name << " Lost " << amount
            << " Health Now Has " << this->_health << std::endl;
  ;
}

void ClapTrap::beRepaired(unsigned int amount) {

  if (int(this->_energy) - 1 < 0) {
    std::cout << "ClapTrap " << this->_name << " Has No Energy Left"
              << std::endl;
    return;
  }
  this->_health += amount;
  std::cout << "ClapTrap " << this->_name << " Now Has " << this->_health
            << " Points" << std::endl;
  this->_energy--;
}
