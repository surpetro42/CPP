 #include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange ()
{
    std::cout << "The default constructor is called" << std::endl;
}

BitcoinExchange::BitcoinExchange (const BitcoinExchange &copy)
{
    *this = copy;
    std::cout << "The copy constructor is called" << std::endl;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    std::cout << "The copy operator is overloaded." << std::endl;
    if(this != &copy)
    {
        this->_exchangeRates = copy._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange ()
{
    std::cout << "The destructor constructor is called" << std::endl;   
}

// void loadDatabase(const std::string& filename);
// float getRateForDate(const std::string& date) const;

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::string temp;

    for (std::size_t i = 0; i < str.length(); ++i) {
        if (str[i] == delimiter) {
            result.push_back(temp);
            temp.clear();
        } else {
            temp += str[i];
        }
    }
    result.push_back(temp);
    return result;
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
    try {
        std::vector<std::string> result;
        std::string line;

        std::ifstream file(filename.c_str());
        if (!file.is_open())
            throw std::ios_base::failure("Error: could not open file.");
        while (std::getline(file, line))
        {
            result = split(line, ',');
            if (result.size() == 2)
                _exchangeRates[result[0]] = atof(result[1].c_str());
        }
        for (std::map<std::string, float>::iterator it = _exchangeRates.begin(); it != _exchangeRates.end(); ++it) {
            std::cout << "Date: " << it->first << " - Rate: " << it->second << std::endl;
        }
        std::cout << "File opened successfully." << std::endl;
        file.close(); 
    } catch (const std::ios_base::failure& e) {
        std::cout << e.what() << std::endl;
    }
}
