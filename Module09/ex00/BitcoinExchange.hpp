#pragma once

#include <iostream>
#include <exception>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <map>

class BitcoinExchange
{
private:
    std::map<std::string, float> _exchangeRates;
public:
    BitcoinExchange ();
    BitcoinExchange (const BitcoinExchange &);
    BitcoinExchange& operator=(const BitcoinExchange &);
    ~BitcoinExchange ();

    // void loadDatabase(const std::string& filename);
    // float getRateForDate(const std::string& date) const;

    void processInputFile(const std::string& filename);
};