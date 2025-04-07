#pragma once

#define TREE "\
      *      \n\
     ***     \n\
    *****    \n\
   *******   \n\
  *********  \n\
 *********** \n\
     |||     \n\
     |||     \n"

#include "AForm.hpp"

class ShrubberyCreationForm :public AForm
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
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm (const ShrubberyCreationForm &);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
    ~ShrubberyCreationForm();

    void		execute(Bureaucrat const & executor) const;
};