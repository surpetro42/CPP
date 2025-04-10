#include "Base.hpp"

Base* generate() {
    int r = rand() % 3;
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}

void    identify (Base *p)
{
    
    if (dynamic_cast<A*>(p))
        std::cout << "class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "class C" << std::endl;
    else
        std::cout << "does not match A, B, or C classes" << std::endl;
}

void    identify (Base &p)
{
    try
    {
        void(dynamic_cast<A&>(p));
        std::cout << "class A" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        void(dynamic_cast<B&>(p));
        std::cout << "class B" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        void(dynamic_cast<C&>(p));
        std::cout << "class C" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    srand(time(0));
    Base *cls = generate();
    identify(cls);
    identify(*cls);
    delete cls;
    return 0;
}