#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat b("Jihad", 50);
    Form f("Jihads Form", 30, 20);

    std::cout << b << std::endl;
    std::cout << f << std::endl;

    b.signForm(f);
    std::cout << f << std::endl;

    Bureaucrat c("foo", 20);
    c.signForm(f);
    std::cout << f << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  try {
    Form f("My Form", 10, 10);
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
