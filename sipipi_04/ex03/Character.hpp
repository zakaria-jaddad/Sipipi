#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
private:
  std::string _name;
  AMateria *_inventory[4];

public:
  Character();
  Character(std::string &name);
  Character(const Character &other);
  Character &operator=(const Character &other);

  virtual std::string const &getName() const;
  virtual void equip(AMateria *m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter &target);
};

#endif // !__CHARACTER_HPP__
