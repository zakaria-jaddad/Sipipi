#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _gradeToSign(1), _gradeToExecute(1) {
  this->_isSigned = false;
}

AForm::AForm(const std::string name, const int gradeToSign,
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

AForm::AForm(const AForm &other)
    : _name(other.getName()), _gradeToSign(other.getGradeToSign()),
      _gradeToExecute(other.getGradeToExecute()) {
  this->_isSigned = other.getIsSigned();
}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    this->_isSigned = other._isSigned;
  }
  return *this;
}

AForm::~AForm() {}

const std::string AForm::getName() const { return this->_name; }

bool AForm::getIsSigned() const { return this->_isSigned; }

int AForm::getGradeToSign() const { return this->_gradeToSign; }

int AForm::getGradeToExecute() const { return this->_gradeToExecute; }

std::ostream &operator<<(std::ostream &os, const AForm &f) {
  os << "Form Name: " << f.getName()
     << ", Signed: " << (f.getIsSigned() ? "Yes" : "No")
     << ", Grade to Sign: " << f.getGradeToSign()
     << ", Grade to Execute: " << f.getGradeToExecute();
  return os;
}

void AForm::beSigned(Bureaucrat &b) {
  if (b.getGrade() <= this->_gradeToSign) {
    this->_isSigned = true;
    return;
  }
  throw GradeTooLowException();
}

// Start Of Exceptions Implementations GradeTooHighException

AForm::GradeTooHighException::GradeTooHighException() {}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Form GradeTooHighException";
}

// End Of Exceptions Implementations GradeTooHighException

// Start Exceptions Implementations GradeTooLowException

AForm::GradeTooLowException::GradeTooLowException() {}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Form GradeTooLowException";
}

// End Exceptions Implementations GradeTooLowException

// Start Exceptions Implementations NotSignedException

AForm::NotSignedException::NotSignedException() {}

AForm::NotSignedException::~NotSignedException() throw() {}

const char *AForm::NotSignedException::what() const throw() {
  return "Form NotSignedException";
}

// End Exceptions Implementations NotSignedException

void AForm::execute(Bureaucrat const &executor) const {
  if (!this->_isSigned) {
    throw AForm::NotSignedException();
  }

  if (executor.getGrade() > this->_gradeToExecute) {
    throw AForm::GradeTooLowException();
  }
  this->formAction();
}
