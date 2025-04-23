#include "Span.hpp"

Span::Span() {};

Span::Span (const Span &copy)
{
    *this = copy;
}

Span Span::operator=(const Span &copy)
{
    if(this != &copy)
    {

    }
    return *this;
}
Span::Span (unsigned int N) : _N(N) {}

Span::~Span () {};

void    Span::addNumber(unsigned int n)
{
    if (_nbr.size() >= _N)
        throw std::overflow_error("The number exceeds _N");
    _nbr.push_back(n);
}
void    Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + _nbr.size() > _N)
        throw std::overflow_error("The number exceeds _N");
    _nbr.insert(_nbr.end(), begin, end);
}

int    Span::longestSpan()
{
    int max;
    int min;
    if (_nbr.size() < 2)
        throw std::logic_error("Not enough numbers to find a span!");
        
    max = *std::max_element(_nbr.begin(), _nbr.end());
    min = *std::min_element(_nbr.begin(), _nbr.end());
    
    return (max - min);
}
int    Span::shortestSpan()
{
    int shortelem;
    int span;
    if (_nbr.size() < 2)
        throw std::logic_error("Not enough numbers to find a span!");

    std::sort(_nbr.begin(), _nbr.end());
    shortelem = std::numeric_limits<int>::max();
    for (size_t i = 0; i < _nbr.size() - 1; ++i)
    {
        span = _nbr[i + 1] - _nbr[i];
        if (span < shortelem)
            shortelem = span;
    }
    return (shortelem);
}
