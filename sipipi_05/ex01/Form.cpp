#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _gradeToSign(1), _gradeToExecute(1) {
  this->_isSigned = false;
}

Form::Form(const std::string name, const int gradeToSign,
           const int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  this->_isSigned = false;
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw GradeTooHighException();
  }
  if (gradeToSign > 150 || gradeToExecute > 150) {
    throw GradeTooLowException();
  }
}

Form::Form(const Form &other)
    : _name(other.getName()), _gradeToSign(other.getGradeToSign()),
      _gradeToExecute(other.getGradeToExecute()) {
  this->_isSigned = other.getIsSigned();
}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    this->_isSigned = other._isSigned;
  }
  return *this;
}

Form::~Form() {}

const std::string Form::getName() const { return this->_name; }

bool Form::getIsSigned() const { return this->_isSigned; }

int Form::getGradeToSign() const { return this->_gradeToSign; }

int Form::getGradeToExecute() const { return this->_gradeToExecute; }

std::ostream &operator<<(std::ostream &os, const Form &f) {
  os << "Form Name: " << f.getName()
     << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
     << ", Grade to Sign: " << f.getGradeToSign()
     << ", Grade to Execute: " << f.getGradeToExecute();
  return os;
}

void Form::beSigned(Bureaucrat &b) {
  if (b.getGrade() <= this->_gradeToSign) {
    this->_isSigned = true;
    return;
  }
  throw GradeTooLowException();
}

// Start Of Exceptions Implementations GradeTooHighException

Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Form::GradeTooHighException::what() const throw() {
  return "Form GradeTooHighException";
}

// End Of Exceptions Implementations GradeTooHighException

// Start Exceptions Implementations GradeTooLowException

Form::GradeTooLowException::GradeTooLowException() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Form::GradeTooLowException::what() const throw() {
  return "Form GradeTooLowException";
}

// End Exceptions Implementations GradeTooLowException
