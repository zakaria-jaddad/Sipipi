#include "ClapTrap.hpp"

int main(void) {

  ClapTrap ct1("Mbarek");
  ClapTrap ct2("Lmaati");

  // Robots has no damage now
  ct1.attack("Lmaati");
  ct2.takeDamage(2);

  ct2.attack("Mbarek");
  ct1.takeDamage(3);

  ct2.attack("Mbarek");
  ct1.takeDamage(5);

  for (int i = 0; i < 10; i++) {
    ct1.attack("Lmaati");
  }
  ct1.beRepaired(5);
  ct1.attack("Lmaati");

  return 0;
}
