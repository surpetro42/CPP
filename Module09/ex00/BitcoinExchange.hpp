#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>


class BitcoinExchange
{
private:
    std::map<std::string, float> _exchangeRates;
public:
    BitcoinExchange ();
    BitcoinExchange (const BitcoinExchange &);
    BitcoinExchange& operator=(const BitcoinExchange &);
    ~BitcoinExchange ();

    bool isValidDateFormat(const std::string& date);
    void processInputFile(const std::string& filenameTxt);
    void processDataFile(const std::string& filenameCsv);
};