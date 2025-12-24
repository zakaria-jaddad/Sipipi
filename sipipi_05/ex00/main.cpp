#include "Bureaucrat.hpp"

int main() {

  Bureaucrat b1("Youssef Talai", 2);
  std::cout << b1.getName() << ", Grade: " << b1.getGrade() << std::endl;
  try {
    Bureaucrat b2(" Jihad Aimarah ", 0);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    Bureaucrat b3("Charlie", 151);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
