#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &);
    Intern &operator=(const Intern &);
    ~Intern();

    AForm* makeForm(std::string const& name, std::string const& target);
};