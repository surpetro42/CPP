#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
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
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm (const PresidentialPardonForm &);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &);
	~PresidentialPardonForm();

	void	execute(Bureaucrat const & executor) const;
};