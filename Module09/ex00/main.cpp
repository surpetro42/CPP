#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        BitcoinExchange btc;
        btc.processDataFile("data.csv");
        btc.processInputFile(argv[1]);
    }
    else
    {
        std::cout << "Error: invalid numbers of argument" << std::endl;
        return (1);
    }

    return (0);
}