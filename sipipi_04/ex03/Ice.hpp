#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice &other);
  Ice &operator=(const Ice &other);
  ~Ice();

  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif // !__ICE_HPP_
