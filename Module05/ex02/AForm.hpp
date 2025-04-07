#pragma once

#include "Bureaucrat.hpp"
#include <cstdlib>

class Bureaucrat;

class AForm
{
protected:
	void	checkexecute(const Bureaucrat &) const;
private:
	
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

	const std::string _name;
	bool              _issigned;
	const int         _signgrade;
	const int         _executegrade;

public:

	AForm();
	AForm(const std::string &, int, int);
	AForm (const AForm &copy);
	AForm& operator=(const AForm &);
	virtual ~AForm();

	const std::string&	getName() const;
	bool				getisSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

	void    	   		checking(const int grade);
	void				beSigned(const Bureaucrat& bureaucrat);
	virtual void		execute(Bureaucrat const & executor) const = 0;
};

std::ostream&	operator<<(std::ostream &os, const AForm &Aform);