#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
    {
        this->_stack = copy._stack;
    }
    return *this;
}

RPN::~RPN() {};

int RPN::arithmetic_operation(const std::string &operatro)
{
    if(_stack.size() < 2)
        throw std::runtime_error("Error: bad input");
    int upper = _stack.top();
        _stack.pop();
    int lower = _stack.top();
        _stack.pop();
    
    if (operatro == "+")
        return lower + upper;
    if (operatro == "-")
        return lower - upper;
    if (operatro == "*")
        return lower * upper;
    if (operatro == "/")
    {
        if (upper == 0)
        {
            std::cout << "Error: division by zero\n";
            return 0;
        }
        return lower / upper;
    }
    std::cout << "Error: unknown operator => " << operatro << std::endl;
    return 0;
}

void RPN::assign(const std::string &expression)
{
    char *elem;
    long nb;
    int res;

    char *exprCopy = new char[expression.size() + 1];
    std::strcpy(exprCopy, expression.c_str());

    elem = strtok(exprCopy, " ");
    while (elem != NULL)
    {
        std::string token = elem;

        if (token.find_first_not_of("0123456789") == std::string::npos)
        {
            nb = std::strtol(token.c_str(), NULL, 10);
            if (nb > INT_MAX)
                std::cout << "The number exceeds INT_MAX or is negative" << std::endl;
            _stack.push(nb);
        }
        else if (token.length() == 1 && std::string("+-*/").find(token) != std::string::npos)
        {
            try
            {
                res = arithmetic_operation(token);
                _stack.push(res);
            }
            catch (const std::exception &)
            {
                delete[] exprCopy;
                return;
            }
        }
        else
        {
            std::cerr << "Error: invalid token => " << token << std::endl;
            delete[] exprCopy;
            return;
        }

        elem = strtok(NULL, " ");
    }
    if (_stack.size() == 1)
    {
        std::cout << "Result: " << _stack.top() << std::endl;
    }
    else
    {
        std::cout << "Error: invalid expression" << std::endl;
    }

    delete[] exprCopy;
}
