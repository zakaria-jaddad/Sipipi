#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {

  ClapTrap ct("Mbarek");
  ScavTrap st1("Lmaati");

  std::cout << "ClapTrap Attributes" << std::endl;
  std::cout << "ClapTrap Name " << ct.getName() << std::endl;
  std::cout << "ClapTrap Health " << ct.getHealth() << std::endl;
  std::cout << "ClapTrap Energy " << ct.getEnergy() << std::endl;
  std::cout << "ClapTrap Damage " << ct.getDamage() << std::endl;

  std::cout << "ScavTrap Attributes" << std::endl;
  std::cout << "ScavTrap Name " << st1.getName() << std::endl;
  std::cout << "ScavTrap Health " << st1.getHealth() << std::endl;
  std::cout << "ScavTrap Energy " << st1.getEnergy() << std::endl;
  std::cout << "ScavTrap Damage " << st1.getDamage() << std::endl;

  st1.attack("Mbarek");
  ct.takeDamage(st1.getDamage());

  ScavTrap st2("Billal");

  for (int i = 0; i < 4; i++) {
    st2.attack("Mbarek");
    st1.takeDamage(st2.getDamage());
  }

  // for (int i = 0; i < 55; i++)
  //   st1.beRepaired(80);

  std::cout << "ScavTrap " << st1.getName() << " Has: " << st1.getHealth()
            << " Health and " << st1.getEnergy() << " Energy" << std::endl;

  st1.guardGate();

  FragTrap ft("Lhbaboul");

  std::cout << "FragTrap Attributes" << std::endl;
  std::cout << "ScavTrap Name " << ft.getName() << std::endl;
  std::cout << "ScavTrap Health " << ft.getHealth() << std::endl;
  std::cout << "ScavTrap Energy " << ft.getEnergy() << std::endl;
  std::cout << "ScavTrap Damage " << ft.getDamage() << std::endl;

  ft.attack(st1.getName());
  st1.takeDamage(ft.getDamage());

  std::cout << "FragTrap " << ft.getName() << " Has: " << ft.getHealth()
            << " Health and " << ft.getEnergy() << " Energy" << std::endl;

  ft.highFivesGuys();

  return 0;
}
