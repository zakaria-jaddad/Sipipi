#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base *generate(void) {
  int random = std::rand() % 3;
  if (random == 0) {
    std::cout << "Generated: A" << std::endl;
    return new A();
  } else if (random == 1) {
    std::cout << "Generated: B" << std::endl;
    return new B();
  } else {
    std::cout << "Generated: C" << std::endl;
    return new C();
  }
}

void identify(Base *p) {
  if (p == NULL)
    return;
  if (dynamic_cast<A *>(p) != NULL) {
    std::cout << "Pointer p of type: A" << std::endl;
    return;
  }
  if (dynamic_cast<B *>(p) != NULL) {
    std::cout << "Pointer p of type: B" << std::endl;
    return;
  }
  if (dynamic_cast<C *>(p) != NULL) {
    std::cout << "Pointer p of type: C" << std::endl;
    return;
  }
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "Reference p of type: A" << std::endl;
    return;
  } catch (std::exception &e) {
  }

  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "Reference p of type: B" << std::endl;
    return;
  } catch (std::exception &e) {
  }

  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "Reference p of type: C" << std::endl;
    return;
  } catch (std::exception &e) {
  }
}

int main() {
  std::srand(std::time(NULL));

  std::cout << "--- Test 1 ---" << std::endl;
  Base *obj1 = generate();
  identify(obj1);
  identify(*obj1);
  delete obj1;

  std::cout << "--- Test 2 ---" << std::endl;
  Base *obj2 = generate();
  identify(obj2);
  identify(*obj2);
  delete obj2;

  std::cout << "--- Test 3 ---" << std::endl;
  Base *obj3 = generate();
  identify(obj3);
  identify(*obj3);
  delete obj3;

  return 0;
}
