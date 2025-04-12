#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cerrno>
#include <climits>
#include <cstdlib>


ScalarConverter::ScalarConverter()
{
	std::cout << "The default constructor is called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << "Calling the copy constructor." << std::endl;
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	std::cout << "Calling an operator overload." << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "The default destructor is called." << std::endl;
}

//-------------------------------------------------------------------

bool checkPoint(const std::string &literal)
{
	size_t pos = literal.find('.');
	int count = 0;
	if (pos == std::string::npos || pos + 1 >= literal.length())
		return false;
	for (size_t i = pos + 1; i < literal.length(); ++i)
	{
		if (literal[i] != '0')
		{
			if (!std::isdigit(literal[i]))
				return false;
		}
		else 
		{
			for (size_t buff = i; buff < literal.length(); ++buff)
				if (!(literal[buff] == '0'))
					count++;
			if (count == 0)
				return false;
		}
	}
	return true;
}

void	printChar(const std::string &literal, char *end)
{
	int nb = static_cast<int>(std::strtod(literal.c_str(), &end));
	if (nb && nb >= 32 && nb < 127)
	{
		std::cout << "char: ";
		char res = static_cast<char>(nb);
		if (res < 0 || end[0] != '\0')
			std::cout << "impossible" << std::endl;
		else
			std::cout << "\'" << res << "\'" << std::endl;
	}
	else if (!nb && literal.length() == 1)
	{
		bool condition = checkPoint(literal);
		std::cout << "char: " << "\'" << static_cast<char>(literal[0]) << "\'" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << (condition ? "" : ".0") << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << (condition ? "" : ".0") << std::endl;
		exit(0);
	}
	else if ((nb >= 0 && nb < 32) || nb == 127)
	{
		std::cout << "char: " << "Non displayable!" << std::endl;
		return;
	}
	else
		std::cout << "char: " << "impossible" << std::endl;
}

void	printInt(const std::string &literal, char *end)
{
	long res = static_cast<long>(std::strtod(literal.c_str(), &end));
	if (end[0] != '\0')
		res = 0;
	if (!(res > INT_MAX || res < INT_MIN))
		std::cout << "int: " << res << std::endl;
	else 
		std::cout << "int: impossible" << std::endl;
}

void printFloat(const std::string &literal, char *end)
{
	bool condition = checkPoint(literal);
	float res = static_cast<float>(std::strtod(literal.c_str(), &end));
	if (end[0] != '\0')
		res = 0;
	std::cout << "float: " << res << (condition ? "" : ".0") << "f" << std::endl;
}

void printDouble(const std::string &literal, char *end)
{
	bool condition = checkPoint(literal);
	double res = std::strtod(literal.c_str(), &end);
	if (end[0] != '\0')
		res = 0;
	std::cout << "double: " << res << (condition ? "" : ".0") << std::endl;
}











bool isNan(const std::string &s) {
	return s == "nan" || s == "nanf";
}

bool isInf(const std::string &s) {
	return s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff";
}

bool isFloatLiteral(const std::string &s) {
	return s.find('f') != std::string::npos;
}

bool NanInf(const std::string &literal)
{
	if (isNan(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}
	if (isInf(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return true;
	}
	return false;
}

void	printCharIntFloatDouble(const std::string &literal, char *end)
{
	double res = std::strtod(literal.c_str(), &end);

	if (!end)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;	
	}

	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return;
	}

	if (res >= 32 && res < 127)
		std::cout << "char: '" << static_cast<char>(res) << "'" << std::endl;
	else if (res < 32 && res == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	if (res >= INT_MIN && res <= INT_MAX)
		std::cout << "int: " << static_cast<int>(res) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
	std::cout << "float: " << static_cast<float>(res);
	if (res == static_cast<int>(res)) std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(res);
	if (res == static_cast<int>(res)) std::cout << ".0" << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	char *end = NULL;
	if (NanInf(literal))
		return;
	else
	{
		printCharIntFloatDouble(literal, end);
	}
}