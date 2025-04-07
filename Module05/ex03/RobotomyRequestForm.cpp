#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    std::cout << "The default constructor RobotomyRequestForm was called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "The default destructor RobotomyRequestForm was called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : _target(target) {}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this != &copy)
    {
        this->_target = copy._target;
    }
    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    this->checkexecute(executor);
    if (rand() % 2)
        std::cout << this->_target << " has been robotomized successfully." << std::endl; 
    else
        std::cout << this->_target << " Robotomy failed." << std::endl;
}