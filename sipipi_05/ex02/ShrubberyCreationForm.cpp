#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137) {
  this->_target = "Default Target";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", 145, 137) {
  this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {
  this->_target = other._target;
};

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    this->_target = other._target;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::formAction() const {
  const std::string targetFilename = this->_target + "_shrubbery";
  std::ofstream targetFile(targetFilename.c_str());
  if (targetFile.is_open() == false) {
    std::cerr << "Error: Unable to open file." << std::endl;
    return;
  }
  targetFile << "       _-_" << std::endl;
  targetFile << "    /~~   ~~\\" << std::endl;
  targetFile << " /~~         ~~\\" << std::endl;
  targetFile << "{               }" << std::endl;
  targetFile << " \\  _-     -_  /" << std::endl;
  targetFile << "   ~  \\\\ //  ~" << std::endl;
  targetFile << "_- -   | | _- _" << std::endl;
  targetFile << "  _ -  | |   -_" << std::endl;
  targetFile << "      // \\\\" << std::endl;
  targetFile.close();
  return;
}
