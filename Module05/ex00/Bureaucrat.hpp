#pragma once

#include <iostream>
// #include <>

class Bureaucrat
{
private:
    const std::string _name;
    int      _grade;
public:
    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };

    Bureaucrat();
    Bureaucrat(const std::string &, int);
    Bureaucrat (const Bureaucrat &copy);
    Bureaucrat& operator=(const Bureaucrat &);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void increment();
    void decrement();
};