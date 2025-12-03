#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(const Cure &other);
  Cure &operator=(const Cure &other);
  ~Cure();

  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif // !__CURE_HPP__
