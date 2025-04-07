#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat obj("Napoleon", 4);
    obj.decrement();
    std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return 0;
}