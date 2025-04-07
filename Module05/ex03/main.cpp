#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        Bureaucrat jim("Jim", 150);

        Intern someRandomIntern;

        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* robot = someRandomIntern.makeForm("robotomy request", "Marvin");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur");
        AForm* unknown = someRandomIntern.makeForm("unknown form", "Nobody");

        jim.signForm(*shrub);

        bob.signForm(*shrub);
        bob.signForm(*robot);
        bob.signForm(*pardon);

        jim.executeForm(*shrub);

        bob.executeForm(*shrub);
        bob.executeForm(*robot);
        bob.executeForm(*pardon);

        delete shrub;
        delete robot;
        delete pardon;
        delete unknown;

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
