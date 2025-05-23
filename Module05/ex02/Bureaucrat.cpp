#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::increment()
{
    if(_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrement()
{
    if(_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

Bureaucrat::Bureaucrat ()
{
    std::cout << "The default constructor was called." << std::endl;
}

Bureaucrat::Bureaucrat (const std::string &name, int grade) : _name(name)
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();
    _grade = grade;
};

Bureaucrat::Bureaucrat (const Bureaucrat &copy) : _grade(copy._grade)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
    {
        this->_grade = copy._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "The default destructor was called." << std::endl;
}

void Bureaucrat::signForm(AForm &obj)
{
    try
    {
        obj.beSigned(*this);
        std::cout << _name << " signed " << obj.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn’t sign " << obj.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) const
{
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << this->getName() << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
