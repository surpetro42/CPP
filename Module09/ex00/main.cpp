#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        BitcoinExchange bitcoin;
        bitcoin.processInputFile(argv[1]);
    }
    else
    {
        std::cout << "Error: invalid numbers of argument" << std::endl;
        return (1);
    }

    return (0);
}