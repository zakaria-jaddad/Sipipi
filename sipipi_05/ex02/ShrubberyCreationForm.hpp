#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public AForm {

public:
  ShrubberyCreationForm(const std::string name, const int gradeToSign,
                        const int gradeToExecute);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();

  void execute(Bureaucrat const &exec) const;
};

#endif // SHRUBBERY_CREATION_FORM_HPP
