#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat  obj("Napoleon", 22);
    Form        form("Important Document", 10, 20);
    obj.decrement();
    form.beSigned(obj);
    return 0;
}