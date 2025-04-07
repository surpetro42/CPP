#pragma once

#include "AForm.hpp"

class RobotomyRequestForm :public AForm
{
private:

    std::string _target;
    
    class FormNotSignedException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};

public:
    RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm (const RobotomyRequestForm &);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &);
    ~RobotomyRequestForm();

    void		execute(Bureaucrat const & executor) const;
};