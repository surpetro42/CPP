#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
private:
    std::vector<int> _nbr;
    unsigned int _N;
public:
    Span ();
    Span (const Span &);
    Span operator=(const Span &);
    Span (unsigned int);
    ~Span ();

    void    addNumber(unsigned int n);
    void    addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int    longestSpan();
    int    shortestSpan();

};
