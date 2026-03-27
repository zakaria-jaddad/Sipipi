#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib> // for srand()
#include <ctime>   // for time()
#include <iostream>

int main() {
  // Seed the random number generator for the RobotomyRequestForm
  std::srand(std::time(NULL));

  std::cout << "\n========================================================"
            << std::endl;
  std::cout << "               CREATING BUREAUCRATS" << std::endl;
  std::cout << "========================================================"
            << std::endl;

  // Grade 1: The CEO, can sign and execute everything
  Bureaucrat ceo("Hermes", 1);

  // Grade 50: Middle management.
  // - Can sign/execute Shrubbery (145/137)
  // - Can sign Robotomy (72) but CANNOT execute it (45)
  // - Cannot sign/execute Presidential (25/5)
  Bureaucrat manager("Bob", 50);

  // Grade 150: The Intern, can't do anything
  Bureaucrat intern("Zoidberg", 150);

  std::cout << ceo << std::endl;
  std::cout << manager << std::endl;
  std::cout << intern << std::endl;

  std::cout << "\n========================================================"
            << std::endl;
  std::cout << "               TEST 1: SHRUBBERY CREATION" << std::endl;
  std::cout << "========================================================"
            << std::endl;
  ShrubberyCreationForm shrub("Garden");

  // Intern tries to sign (Fails: 150 > 145)
  intern.signForm(shrub);

  // Manager signs (Succeeds: 50 <= 145)
  manager.signForm(shrub);

  // Manager executes (Succeeds: 50 <= 137) -> Check your folder for
  // Garden_shrubbery!
  manager.executeForm(shrub);

  std::cout << "\n========================================================"
            << std::endl;
  std::cout << "               TEST 2: ROBOTOMY REQUEST" << std::endl;
  std::cout << "========================================================"
            << std::endl;
  RobotomyRequestForm robot("Bender");

  // Manager tries to execute before it's signed (Fails)
  manager.executeForm(robot);

  // Manager signs (Succeeds: 50 <= 72)
  manager.signForm(robot);

  // Manager tries to execute (Fails: 50 is not <= 45)
  manager.executeForm(robot);

  // CEO executes (Succeeds: 1 <= 45) -> 50% chance to hear drilling!
  ceo.executeForm(robot);

  // Let's have the CEO execute it a few more times to show the 50% randomness
  std::cout << "--- CEO executes robotomy 3 more times to test randomness ---"
            << std::endl;
  ceo.executeForm(robot);
  ceo.executeForm(robot);
  ceo.executeForm(robot);

  std::cout << "\n========================================================"
            << std::endl;
  std::cout << "             TEST 3: PRESIDENTIAL PARDON" << std::endl;
  std::cout << "========================================================"
            << std::endl;
  PresidentialPardonForm pardon("Arthur Dent");

  // Manager tries to sign (Fails: 50 > 25)
  manager.signForm(pardon);

  // CEO signs (Succeeds: 1 <= 25)
  ceo.signForm(pardon);

  // CEO executes (Succeeds: 1 <= 5) -> "Arthur Dent has been pardoned..."
  ceo.executeForm(pardon);

  std::cout << "\n========================================================"
            << std::endl;
  std::cout << "                     END OF TESTS" << std::endl;
  std::cout << "========================================================"
            << std::endl;

  return 0;
}
