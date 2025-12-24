#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>

class Bureaucrat;

class Form {
private:
  const std::string _name;
  bool isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  Form();
  Form(const std::string name, const int gradeToSign, const int gradeToExecute);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();
  const std::string getName() const;
  bool getIsSigned() const;
  const int getGradeToSign() const;
  const int getGradeToExecute() const;
  void beSigned(Bureaucrat &b);

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

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif // !__FORM_HPP_
