#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

private:
  std::string name;
  Weapon *w;

public:
  void attack(void);
  HumanB(std::string name);
  void setWeapon(Weapon &Weapon);
};

#endif // !HUMANB_HPP
