#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat Name") {
  this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
  else
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name) {
  this->_grade = other.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->_grade = other.getGrade();
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::incrementGrade() {
  if (this->_grade <= 1)
    throw GradeTooHighException();
  this->_grade = this->_grade - 1;
}

void Bureaucrat::decrementGrade() {
  if (this->_grade >= 150)
    throw GradeTooLowException();
  this->_grade = this->_grade + 1;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
  // <name>, bureaucrat grade <grade>.
  os << b.getName() << ", bureaucrat grade " << b.getGrade();
  return os;
}

// Start Of Exceptions Implementations GradeTooHighException

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "GradeTooHighException";
}

// End Of Exceptions Implementations GradeTooHighException

// Start Exceptions Implementations GradeTooLowException

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "GradeTooLowException";
}

// End Exceptions Implementations GradeTooLowException

void Bureaucrat::signForm(Form &f) {
  try {
    f.beSigned(*this);
    // <bureaucrat> signed <form>
    std::cout << this->_name << " signed " << f.getName() << std::endl;
  } catch (std::exception &e) {
    // <bureaucrat> couldn’t sign <form> because <reason>.
    std::cerr << this->_name << " couldn't sign " << f.getName() << " because "
              << e.what() << std::endl;
  }
}
