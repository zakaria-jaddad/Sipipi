#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
private:
  const std::string _name;
  int _grade;

public:
  Bureaucrat();
  Bureaucrat(const std::string name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();
  const std::string getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {

  public:
    GradeTooHighException();
    ~GradeTooHighException() throw();

    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {

  public:
    GradeTooLowException();
    ~GradeTooLowException() throw();
    const char *what() const throw();
  };

  void signForm(AForm &f);
  void executeForm(AForm const &form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
#endif // BUREAUCRAT_HPP
