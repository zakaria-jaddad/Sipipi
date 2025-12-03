#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include "ICharacter.hpp"
#include <iostream>

class AMateria {
protected:
  std::string type;

public:
  AMateria();
  AMateria(std::string const &type);
  AMateria(const AMateria &other);
  AMateria &operator=(const AMateria &other);
  ~AMateria();
  std::string const &getType() const;
  void setType(const std::string &type);
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif // !__AMATERIA_HPP__
