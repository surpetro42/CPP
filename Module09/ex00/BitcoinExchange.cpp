#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange()
{
    std::cout << "The default constructor is called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
    std::cout << "The copy constructor is called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    std::cout << "The copy operator is overloaded." << std::endl;
    if (this != &copy)
    {
        this->_exchangeRates = copy._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "The destructor constructor is called" << std::endl;
}

std::list<std::string> split(const std::string &str, char delimiter)
{
    std::list<std::string> result;
    std::string temp;

    for (std::size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] == delimiter)
        {
            result.push_back(temp);
            temp.clear();
        }
        else
        {
            temp += str[i];
        }
    }
    result.push_back(temp);
    return result;
}

bool BitcoinExchange::isValidDateFormat(const std::string &date)
{
    return date.size() == 10 &&
           date[4] == '-' && date[7] == '-' &&
           std::isdigit(date[0]) && std::isdigit(date[1]) &&
           std::isdigit(date[2]) && std::isdigit(date[3]) &&
           std::isdigit(date[5]) && std::isdigit(date[6]) &&
           std::isdigit(date[8]) && std::isdigit(date[9]);
}

bool is_leap_year(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool is_valid_day(int year, int month, int day)
{
    const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && is_leap_year(year))
    {
        return day >= 1 && day <= 29;
    }
    return day >= 1 && day <= days_in_month[month];
}

bool valid_data(std::list<std::string> &result)
{
    int index = 0;
    std::list<DateParts> yars;
    DateParts d;
    for (std::list<std::string>::iterator it = result.begin(); it != result.end(); ++it, ++index)
    {
        if (index % 2 == 0)
        {
            std::list<std::string> stringyars = split(*it, '-');
            std::list<std::string>::iterator sit = stringyars.begin();
            if (stringyars.size() == 3)
            {
                d.year = atoi(sit->c_str()); ++sit;
                d.month = atoi(sit->c_str()); ++sit;
                d.day = atoi(sit->c_str());
                if (d.year < 2009 || d.year > 9999)
                    return false;
                if (d.month < 1 || d.month > 12)
                    return false;
                if (!is_valid_day(d.year, d.month, d.day))
                    return false;
                yars.push_back(d);
            }
        }
    }
    return true;
}

void BitcoinExchange::processInputFile(const std::string &filenameTxt)
{
    try
    {
        std::ifstream file(filenameTxt.c_str());
        if (!file.is_open())
            throw std::ios_base::failure("Error: could not open file.");

        std::string line;
        if (!std::getline(file, line) || line != "date | value")
            throw std::ios_base::failure("Error: invalid header format");

        while (std::getline(file, line))
        {
            std::list<std::string> tokens = split(line, '|');
            if (valid_data(tokens))
            {
                if (tokens.size() == 2)
                {
                    std::list<std::string>::iterator it = tokens.begin();
                    std::string date = *it;
                    ++it;
                    std::string valueStr = *it;

                    date.erase(date.find_last_not_of(" \t") + 1);
                    valueStr.erase(0, valueStr.find_first_not_of(" \t"));

                    if (valueStr.find_first_not_of("0123456789.") != std::string::npos)
                    {
                        std::cout << "Error: bad input => " << line << std::endl;
                        continue;
                    }

                    float value = std::atof(valueStr.c_str());
                    if (!isValidDateFormat(date))
                    {
                        std::cout << "Error: bad input => " << line << std::endl;
                        continue;
                    }

                    if (value < 0)
                    {
                        std::cout << "Error: not a positive number." << std::endl;
                        continue;
                    }

                    if (value > 1000)
                    {
                        std::cout << "Error: too large a number." << std::endl;
                        continue;
                    }

                    std::map<std::string, float>::const_iterator itRate = _exchangeRates.lower_bound(date);
                    if (itRate == _exchangeRates.end() || itRate->first != date)
                    {
                        if (itRate == _exchangeRates.begin())
                        {
                            std::cout << "Error: no earlier date found." << std::endl;
                            continue;
                        }
                        --itRate;
                    }
                    float rate = itRate->second;
                    float result = rate * value;
                    std::cout << date << " => " << value << " = " << result << std::endl;
                }
            }
            else
            {
                std::cout << "--------Error: bad input => " << line << std::endl;
            }
        }
        file.close();
    }
    catch (const std::ios_base::failure &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void BitcoinExchange::processDataFile(const std::string &filenameCsv)
{
    try
    {
        std::ifstream file(filenameCsv.c_str());
        if (!file.is_open())
            throw std::ios_base::failure("Error: could not open file.");

        std::string line;
        while (std::getline(file, line))
        {
            std::list<std::string> result = split(line, ',');
            if (result.size() == 2)
                _exchangeRates[result.front()] = atof(result.back().c_str());
        }

        std::cout << "File opened successfully." << std::endl;
        file.close();
    }
    catch (const std::ios_base::failure &e)
    {
        std::cout << e.what() << std::endl;
    }
}
