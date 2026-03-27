#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string formName,
                        const std::string formTarget) {
  AForm *form = NULL;
  std::string formNames[3] = {"shrubbery creation", "robotomy request",
                              "presidential pardon"};
  for (int i = 0; i < 3; i++) {
    if (formName == formNames[i]) {
      switch (i) {
      case 0:
        form = new ShrubberyCreationForm(formTarget);
        break;
      case 1:
        form = new RobotomyRequestForm(formTarget);
        break;
      case 2:
        form = new PresidentialPardonForm(formTarget);
        break;
      }
      std::cout << "Intern creates " << formName << std::endl;
      return form;
    }
  }
  std::cout << "Intern cannot create " << formName
            << " because it is not a valid form name." << std::endl;
  return NULL;
}
