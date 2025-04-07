#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1); // high rank bureaucrat
        Bureaucrat jim("Jim", 150); // low rank bureaucrat

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Marvin");
        PresidentialPardonForm pardon("Arthur");

        // Try signing with low rank (should fail)
        jim.signForm(shrub);

        // Sign with high rank
        bob.signForm(shrub);
        bob.signForm(robot);
        bob.signForm(pardon);

        // Try executing with low rank (should fail)
        jim.executeForm(shrub);

        // Execute with high rank
        bob.executeForm(shrub);
        bob.executeForm(robot);
        bob.executeForm(pardon);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
