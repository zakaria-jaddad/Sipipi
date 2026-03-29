#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main(void) {

  Data *jihad = new Data("Jihad", 18, 2);

  uintptr_t jihadAddress = Serializer::serialize(jihad);

  std::cout << "Jihad's address: " << jihadAddress << std::endl;

  Data *deserializedJihadAddress = Serializer::deserialize(jihadAddress);

  std::cout << "Jihad's name: " << deserializedJihadAddress->name << std::endl;
  std::cout << "Jihad's age: " << deserializedJihadAddress->age << std::endl;
  std::cout << "Jihad's level: " << deserializedJihadAddress->level
            << std::endl;

  if (jihad == deserializedJihadAddress) {
    std::cout << "SUCCESS: The pointers are strictly equal!" << std::endl;
  } else {
    std::cout << "FAILURE: The pointers do not match!" << std::endl;
  }
  delete jihad;
  return 0;
}
