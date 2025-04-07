#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:

    const std::string _name;
    int      _grade;
    
    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };

public:
    
    Bureaucrat();
    Bureaucrat(const std::string &, int);
    Bureaucrat (const Bureaucrat &copy);
    Bureaucrat& operator=(const Bureaucrat &);
    ~Bureaucrat();

    const std::string &getName() const;
    int         getGrade() const;   

    void        increment();
    void        decrement();

    void        signForm(AForm &obj);
    void        executeForm(AForm const &form) const;
};