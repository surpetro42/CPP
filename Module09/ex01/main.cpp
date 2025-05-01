#include "RPN.hpp"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        RPN calc;
        calc.assign(argv[1]);
    }
    else
    {
        std::cout << "Error input!" << std::endl;
    }
    return (0);
}