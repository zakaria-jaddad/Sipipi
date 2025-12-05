#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
private:
  AMateria *_inventory[4];
  std::string _name;

public:
  Character();
  Character(const std::string &name);
  Character(const Character &other);
  Character &operator=(const Character &other);
  ~Character();

  void setName(std::string name);
  virtual std::string const &getName() const;

  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif // !__CHARACTER_HPP__
