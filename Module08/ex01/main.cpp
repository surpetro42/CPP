#include "Span.hpp"

int main()
{
    std::vector<int> v;
    Span s(5);

    s.addNumber(10);
    s.addNumber(20);
    s.addNumber(30);
    s.addNumber(10);
    s.addNumber(20);
    
    std::cout << s.shortestSpan() << std::endl;
    std::cout << s.longestSpan() << std::endl;
    return (0);
}