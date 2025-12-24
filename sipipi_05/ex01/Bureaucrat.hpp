#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include "Form.hpp"
#include <exception>
#include <iostream>
#include <ostream>
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
  void signForm(Form &f);

  class GradeTooHighException : public std::exception {
  private:
    std::string message;

  public:
    GradeTooHighException(const std::string &msg) : message(msg) {}
    ~GradeTooHighException() throw() {}

    virtual const char *what() const throw() { return this->message.c_str(); }
  };

  class GradeTooLowException : public std::exception {
  private:
    std::string message;

  public:
    GradeTooLowException(const std::string &msg) : message(msg) {}
    ~GradeTooLowException() throw() {}
    virtual const char *what() const throw() { return this->message.c_str(); }
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
#endif // __BUREAUCRAT_HPP__
