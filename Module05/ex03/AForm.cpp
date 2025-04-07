#include "AForm.hpp"

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form Not signed exception";
}
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

AForm::AForm() : _name(""), _signgrade(5), _executegrade(5)
{
    _issigned = false;
    std::cout << "The default constructor From was called." << std::endl;
}

AForm::~AForm()
{
    std::cout << "The default destructor From was called." << std::endl;
}

void    AForm::checking(const int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const std::string &name, int signgrade, int executegrade)
    :   _name(name),
        _issigned(false),
        _signgrade(signgrade),
        _executegrade(executegrade)
{
    checking(_signgrade);
    checking(_executegrade);
}

AForm::AForm (const AForm &copy)
    :   _name(copy._name),
        _issigned(copy._issigned),
        _signgrade(copy._signgrade),
        _executegrade(copy._executegrade)
{
    std::cout << "AForm Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &copy)
{
    if(this != &copy)
    {
        this->_issigned = copy._issigned;
    }
    std::cout << "The Aform overload constructor has been called" << std::endl;
    return *this;
}

const   std::string& AForm::getName() const
{
    return _name;
}

bool    AForm::getisSigned() const
{
    return _issigned;
}

int     AForm::getSignGrade() const
{
    return _signgrade;
}

int     AForm::getExecGrade() const
{
    return _executegrade;
}

void    AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signgrade)
        throw AForm::GradeTooLowException();
    _issigned = true;
    std::cout << "The beSigned method was called" << std::endl;
}

void	AForm::checkexecute(Bureaucrat const &obj) const
{
    if (this->getisSigned() != true)
        throw AForm::FormNotSignedException();
    if (this->_executegrade < obj.getGrade())
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &os, const AForm &Aform)
{
    return os << "AForm " << Aform.getName() << std::endl
              << "IsSigned" << Aform.getisSigned() << std::endl
              << "Signgrade" << Aform.getSignGrade() << std::endl
              << "Executegrade" << Aform.getExecGrade();
}