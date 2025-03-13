#include "Harl.hpp"

int main()
{
	Harl obj;
	std::string input;
	std::cout << "You can enter -> DEBUG, INFO, WARNING, ERROR" << std::endl;
	std::cout << "Each of these commands introduces a message to you:" << std::endl;
	std::cin >> input;
	obj.complain(input);
	return 0;
}