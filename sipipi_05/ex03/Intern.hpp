#ifndef INTERN
#define INTERN

#include "AForm.hpp"

class Intern {
public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  AForm *makeForm(const std::string formName, const std::string formTarget);
};

#endif // !INTERN
