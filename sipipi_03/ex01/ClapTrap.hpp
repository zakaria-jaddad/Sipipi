#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap {
protected:
  std::string _name;
  unsigned int _health;
  unsigned int _energy;
  unsigned int _damage;

public:
  ClapTrap(void);
  ClapTrap(std::string name);
  ~ClapTrap();

  ClapTrap &operator=(const ClapTrap &other);

  std::string getName(void) const;
  unsigned int getHealth(void) const;
  unsigned int getEnergy(void) const;
  unsigned int getDamage(void) const;

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};
#endif // !__CLAPTRAP_HPP__
