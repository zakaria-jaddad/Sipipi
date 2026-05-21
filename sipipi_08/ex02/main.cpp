#include "MutantStack.hpp"
#include <iostream>

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);

  std::cout << mstack.top() << std::endl;

  mstack.pop();
  std::cout << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  std::cout << *it << std::endl;
  std::cout << *ite << std::endl;

  ++it;
  --it;

  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }

  MutantStack<int> my_stack;
  my_stack.push(1);
  my_stack.push(2);
  my_stack.push(3);
  my_stack.push(4);
  my_stack.push(5);

  for (MutantStack<int>::iterator it = my_stack.begin(); it != my_stack.end();
       it++) {
    std::cout << "--" << std::endl;
    std::cout << *it << std::endl;
    std::cout << "--" << std::endl;
  }
  return 0;
}
