#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "The default constructor is called." << std::endl;
}

ScalarConverter::ScalarConverter (const ScalarConverter &copy)
{
	std::cout << "Calling the copy constructor." << std::endl;
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	std::cout << "Calling an operator overload." << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter ()
{
	std::cout << "The default destructor is called." << std::endl;
}

//-------------------------------------------------------------------

bool checkPoint(const std::string& literal)
{
	size_t pos = literal.find('.');

	if (pos == std::string::npos)
		return false;
	for(size_t i = pos + 1; i <= literal.length(); ++i)
	{
		if (!(std::isdigit(literal[i])))
			return false;
	}
	return true;
}

void printChar(const std::string& literal ,char *end)
{
	int nb = static_cast<int>(std::strtod(literal.c_str(), &end));
	std::cout << "char: ";
	if (nb > 32 && nb < 127)
	{
		char res = static_cast<char>(nb);
		if (res < 0 || end[0] != '\0')
			std::cout << "impossible " << std::endl;
		else
			std::cout  << "\'" << res << "\'" << std::endl;
	}
	else
		std::cout << "Non displayable" << std::endl;
}

void printInt(const std::string& literal, char *end)
{
	int res = static_cast<int>(std::strtod(literal.c_str(), &end));
	if (end[0] != '\0')
		res = 0;
	std::cout << "int: " << res << std::endl;
}

void    printFloat(const std::string& literal, char *end)
{
	bool condition = checkPoint(literal);
	float res = static_cast<float>(std::strtod(literal.c_str(), &end));
	if (end[0] != '\0')
		res = 0;
	std::cout << "float: " << res << (condition ? "" : ".0") << "f" << std::endl;
}

void    printDouble(const std::string& literal, char *end)
{
	bool condition = checkPoint(literal);
	double res = std::strtod(literal.c_str(), &end); 
	if (end[0] != '\0')
		res = 0;
	std::cout << "double: " << res << (condition ? "" : ".0") << std::endl;
}

void printNan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

bool    checkNan(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf")
		return true;
	return false;
}

void ScalarConverter::convert(const std::string& literal)
{
	char *end = NULL;
	if (checkNan(literal))
		printNan();
	else
	{
		printChar(literal, end);
		printInt(literal, end);
		printFloat(literal, end);
		printDouble(literal, end);
	}
}