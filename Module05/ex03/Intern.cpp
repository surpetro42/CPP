#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern ()
{
    std::cout << "The default constructor Intern was called." << std::endl;   
}

Intern::Intern (const Intern &copy)
{
    *this = copy;
    std::cout << "Intern Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
    if (this != &copy)
        *this = copy;
    return *this;
}

Intern::~Intern ()
{
    std::cout << "The default destructor Intern was called." << std::endl;
}

AForm* Intern::makeForm(std::string const& name, std::string const& target)
{
    int i = 0;
    std::string arr[]= {"presidential pardon", "robotomy request", "shrubbery creation", NULL};

    while(arr[i] != name && arr[i] != "NULL")
        i++;

    switch (i)
    {
    case 1:
        return (new PresidentialPardonForm(target));
        break;
    case 2:
        return (new RobotomyRequestForm(target));
        break;
    case 3:
        return (new ShrubberyCreationForm(target));
        break;
    default:
        std::cout << "your input request is incorrect" << std::endl;
        std::cout << "It should " << arr[0] << " or " << arr[1] << " or " << arr[2] << std::endl;
        return NULL;
    }
}