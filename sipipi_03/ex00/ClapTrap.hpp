#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap {
private:
  std::string _name;
  int _health;
  int _energy;
  int _damage;

public:
  ClapTrap();

  // std::string getName() const;
  // int getHealth() const;
  // int getEnergy() const;
  // int getDamage() const;
  // void setName(const std::string &name);
  // void setHealth(int health);
  // void setEnergy(int energy);
  // void setDamage(int damage);

  //
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};
#endif // !__CLAPTRAP_HPP__
