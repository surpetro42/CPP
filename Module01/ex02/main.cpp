#include <ios>
#include <iostream>
#include <iomanip>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << std::setw(20) << std::left << "str address" << std::setw(30) << std::left << &str << std::endl;
	std::cout << std::setw(20) << std::left << "stringPTR address" << stringPTR << std::setw(30) << std::left << std::endl;
	std::cout << std::setw(20) << std::left << "stringPTR address" << &stringREF << std::setw(30) << std::left << std::endl;

	std::cout << std::setw(20) << std::left << "str value" << str << std::setw(30) << std::left << std::endl;
	std::cout << std::setw(20) << std::left << "stringPTR value" << *stringPTR << std::setw(30) << std::left << std::endl;
	std::cout << std::setw(20) << std::left << "stringREF value" << stringREF << std::setw(30) << std::left << std::endl;
}