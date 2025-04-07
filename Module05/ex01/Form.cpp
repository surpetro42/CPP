#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

Form::Form() : _name(""), _signgrade(5), _executegrade(5)
{
    _issigned = false;
    std::cout << "The default constructor From was called." << std::endl;
}

Form::~Form()
{
    std::cout << "The default destructor From was called." << std::endl;
}

void    Form::checking(const int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Form::Form(const std::string &name, int signgrade, int executegrade)
    :   _name(name),
        _issigned(false),
        _signgrade(signgrade),
        _executegrade(executegrade)
{
    checking(_signgrade);
    checking(_executegrade);
}

Form::Form (const Form &copy)
    :   _name(copy._name),
        _issigned(copy._issigned),
        _signgrade(copy._signgrade),
        _executegrade(copy._executegrade)
{
    std::cout << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &copy)
{
    if(this != &copy)
    {
        this->_issigned = copy._issigned;
    }
    std::cout << "The form overload constructor has been called" << std::endl;
    return *this;
}

const   std::string& Form::getName() const
{
    return _name;
}
bool    Form::isSigned() const
{
    return _issigned;
}
int     Form::getSignGrade() const
{
    return _signgrade;
}
int     Form::getExecGrade() const
{
    return _executegrade;
}

void    Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signgrade)
        throw Form::GradeTooLowException();
    _issigned = true;
    std::cout << "The beSigned method was called" << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Form &form)
{
    return os << "Form " << form.getName() << std::endl
              << "IsSigned" << form.isSigned() << std::endl
              << "Signgrade" << form.getSignGrade() << std::endl
              << "Executegrade" << form.getExecGrade();
}
