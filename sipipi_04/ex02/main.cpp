#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {

  Animal *animalArray[10];
  for (int i = 0; i < 10; i++) {
    if (i < 5)
      animalArray[i] = new Dog();
    else
      animalArray[i] = new Cat();
  }
  for (int i = 0; i < 10; i++) {
    delete animalArray[i];
  }
  return 0;
  /*

     - What is an abstract class (Interfaces)
        An Interface or an Abstract class describes te behavior of capabilities
     of a C++ class without committing to a particular implementation of that
     class

      - What is the purpose of an **abstract class**
        To provide te Desired base class Form which will be inherited by other
     classes in the class hierarchy


      - Abstract classes cannot be used to instantiate objects and serves only
     as **interfaces**

      - A class is made abstract by declaring _at least one_ of it's function as
     pure virtual function

      This is an example of a pure virtual function

      ```cpp
       // pure virtual function
          virtual int foo() = 0;
      ```

      All classes that inherite from the interface should override to the pure
     virtual methods


     ----------

     Types of Polymorphism:
     - Compile Time Polymorphism: Method Overloading
      -> for example 2 methods with the same name but with 2 different
        signatures int add(int x, int y); double add(double x, double y);

     - Run Time Polymorphism: Method Overriding
      -> for example an object that  inherites from a base class that has the
    same method names.


    ## Functions Overriding using Virtual Functions
    -   Virtual functions ensure theat the correct function is called for an
    object regardless of the type of reference (or pointer) used for function
    call.

    Virtual methods ensure for the copmpiler that the methods will be overridden
    in the derived classes
  */
}
