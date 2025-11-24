#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {

public:
  ScavTrap();
  ScavTrap(std::string name);
  ~ScavTrap();

  void guardGate(void) const;
};
#endif
