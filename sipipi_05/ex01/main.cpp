#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat b("Alice", 50);
    Form f("TopSecret", 30, 20);

    std::cout << b << std::endl;
    std::cout << f << std::endl;

    b.signForm(f);
    std::cout << f << std::endl;

    Bureaucrat c("Bob", 20);
    c.signForm(f);
    std::cout << f << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }


  Form f("My Form", 10, 10);

  return 0;
}
