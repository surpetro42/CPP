#include "Harl.hpp"

int main()
{
	std::string input;

	std::cout << "You can enter -> DEBUG, INFO, WARNING, ERROR" << std::endl;
	std::cout << "Each of these commands introduces a message to you:" << std::endl;
	std::cin >> input;
	if (input == "DEBUG")
		debug();
	if (input == "INFO")
		info();
	if (input == "WARNING")
		warning();
	if (input == "ERROR")
		error();
	return 0;
}