#ifndef FORM_HPP
#define FORM_HPP

#include <fstream>
#include <iostream>

class Bureaucrat;

class AForm {
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  AForm();
  AForm(const std::string name, const int gradeToSign,
        const int gradeToExecute);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();
  const std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  void beSigned(Bureaucrat &b);

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

  class NotSignedException : public std::exception {
  public:
    NotSignedException();
    ~NotSignedException() throw();
    const char *what() const throw();
  };

  virtual void formAction() const = 0;
  void execute(Bureaucrat const &exec) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif // !FORM_HPP
