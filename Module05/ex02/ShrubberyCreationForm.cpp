#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    std::cout << "The default constructor ShrubberyCreationForm was called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "The default destructor ShrubberyCreationForm was called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : _target(target) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
    {
        this->_target = copy._target;
    }
    return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    this->checkexecute(executor);
    std::ofstream file(std::string(this->_target + "_shrubbery").c_str());
    file << TREE;
    file.close();
}