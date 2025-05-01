#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <cctype>

static bool isNumber(const std::string &str)
{
    for (std::size_t j = 0; j < str.length(); ++j)
    {
        if (!std::isdigit(str[j]))
            return false;
    }
    return !str.empty();
}

int main(int argc, char **argv)
{
    if (argc > 1 && argc <= 3000)
    {
        try
        {
            PmergeMe obj;
            std::vector<std::string> argvelem;

            for (int i = 1; i < argc; ++i)
            {
                if (isNumber(argv[i]))
                    argvelem.push_back(argv[i]);
                else
                {
                    std::cerr << "Error: invalid input '" << argv[i] << "'" << std::endl;
                    return 1;
                }
            }

            obj.initialize(argvelem);
            obj.sort();
        }
        catch (const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
            return 1;
        }
    }
    else
    {
        std::cerr << "ERROR: bad input" << std::endl;
    }

    return 0;
}
