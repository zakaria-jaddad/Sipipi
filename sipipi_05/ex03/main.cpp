#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(std::time(NULL));

  std::cout << "========================================================"
            << std::endl;
  std::cout << "               TESTING INTERN FORM CREATION" << std::endl;
  std::cout << "========================================================"
            << std::endl;

  Intern someRandomIntern;
  Bureaucrat boss("The Boss", 1); // Grade 1 to easily test execution

  AForm *rrf;
  AForm *scf;
  AForm *ppf;
  AForm *unknown;

  std::cout << "\n--- Intern tries to create valid forms ---" << std::endl;
  scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");
  ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

  std::cout << "\n--- Intern tries to create an invalid form ---" << std::endl;
  unknown = someRandomIntern.makeForm("time travel request", "TARDIS");

  std::cout << "\n========================================================"
            << std::endl;
  std::cout << "               TESTING EXECUTING CREATED FORMS" << std::endl;
  std::cout << "========================================================"
            << std::endl;

  if (scf) {
    boss.signForm(*scf);
    boss.executeForm(*scf);
    delete scf; // MUST DELETE!
  }

  std::cout << "---------------------------------" << std::endl;

  if (rrf) {
    boss.signForm(*rrf);
    boss.executeForm(*rrf);
    delete rrf; // MUST DELETE!
  }

  std::cout << "---------------------------------" << std::endl;

  if (ppf) {
    boss.signForm(*ppf);
    boss.executeForm(*ppf);
    delete ppf; // MUST DELETE!
  }

  // unknown is NULL, so we don't need to delete it or execute it,
  // but it's good practice to show we handle the NULL case safely.
  if (unknown) {
    delete unknown;
  }

  std::cout << "\n========================================================"
            << std::endl;
  std::cout << "                     END OF TESTS" << std::endl;
  std::cout << "========================================================"
            << std::endl;

  return 0;
}
