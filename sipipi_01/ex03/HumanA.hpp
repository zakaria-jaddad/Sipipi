#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
  std::string name;
  Weapon &w;

public:
  void attack(void);
  HumanA(std::string name, Weapon &w);
};

#endif // !HUMANA_HPP
