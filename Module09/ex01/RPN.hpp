#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cstring>
#include <climits>


class RPN
{
private:
    std::stack<int> _stack;

public:
    RPN ();
    RPN (const RPN &);
    RPN& operator=(const RPN &);
    ~RPN ();
    
    void assign(const std::string &expression);
    int arithmetic_operation(const std::string &operatro);
};
