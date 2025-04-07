#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

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

    std::string getName() const;
    int getGrade() const;

    void increment();
    void decrement();

    void signForm(Form &obj);
};