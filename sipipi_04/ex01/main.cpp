#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {

  Animal* animalArray[10];
  for (int i = 0; i < 10; i++) {
    if (i < 5) {
      animalArray[i] = new Dog();
    } else {
      animalArray[i] = new Cat();
    }
  }
  for (int i = 0; i < 10; i++) {
    delete animalArray[i];
  }
  return 0;
}