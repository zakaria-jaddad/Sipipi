#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <iostream>

class WrongAnimal {
protected:
  std::string type;

public:
  WrongAnimal();
  virtual ~WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  WrongAnimal &operator=(const WrongAnimal &other);
  void makeSound() const;
  std::string getType() const;
};

#endif // !__WRONGANIMAL_HPP__
