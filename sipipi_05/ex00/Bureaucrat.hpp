#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

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
  private:
    std::string _msg;

  public:
    GradeTooHighException(const std::string &msg) : _msg(msg) {}
    virtual const char *what() const throw() { return _msg.c_str(); }
  };

  class GradeTooLowException : public std::exception {
  private:
    std::string _msg;

  public:
    GradeTooLowException(const std::string &msg) : _msg(msg) {}
    virtual const char *what() const throw() { return _msg.c_str(); }
  };
};
#endif // __BUREAUCRAT_HPP__
