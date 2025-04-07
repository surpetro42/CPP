#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    std::cout << "The default constructor PresidentialPardonForm was called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "The default destructor PresidentialPardonForm was called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm (const PresidentialPardonForm &copy): AForm(copy), _target(copy._target) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : _target(target) {}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if (this != &copy)
    {
        this->_target = copy._target;
    }
    return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    this->checkexecute(executor);
    std::cout << this->_target << " Has been pardoned by Zaphod Beeblebrox." << std::endl; 
}
