#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };
    const std::string _name;
    bool              _issigned;
    const int         _signgrade;
    const int         _executegrade;
public:

    Form();
    Form(const std::string &, int, int);
    Form (const Form &copy);
    Form& operator=(const Form &);
    Form& operator<<(const Form &);
    ~Form();

    const   std::string& getName() const;
    bool    isSigned() const;
    int     getSignGrade() const;
    int     getExecGrade() const;

    void    beSigned(const Bureaucrat& bureaucrat);
    void    checking(const int grade);
};

std::ostream& operator<<(std::ostream &os, const Form &form);