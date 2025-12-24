#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _gradeToSign(1), _gradeToExecute(1) {
  this->isSigned = false;
}

Form::Form(const std::string name, const int gradeToSign,
           const int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  this->isSigned = false;
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw GradeTooHighException("Grade is too high");
  }
  if (gradeToSign > 150 || gradeToExecute > 150) {
    throw GradeTooLowException("Grade is too low");
  }
}

Form::Form(const Form &other)
    : _name(other.getName()), _gradeToSign(other.getGradeToSign()),
      _gradeToExecute(other.getGradeToExecute()) {
  this->isSigned = other.getIsSigned();
}

Form &Form::operator=(const Form &other) {
  if (this != &other) {
    this->isSigned = other.isSigned;
  }
  return *this;
}

Form::~Form() {}

const std::string Form::getName() const { return this->_name; }

bool Form::getIsSigned() const { return this->isSigned; }

const int Form::getGradeToSign() const { return this->_gradeToSign; }

const int Form::getGradeToExecute() const { return this->_gradeToExecute; }

std::ostream &operator<<(std::ostream &os, const Form &f) {
  os << "Form Name: " << f.getName()
     << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
     << ", Grade to Sign: " << f.getGradeToSign()
     << ", Grade to Execute: " << f.getGradeToExecute();
  return os;
}

void Form::beSigned(Bureaucrat &b) {
  if (b.getGrade() <= this->_gradeToSign) {
    this->isSigned = true;
    return;
  }
  throw GradeTooLowException("Grade Too Low");
}
