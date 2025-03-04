#include "PhoneBook.hpp"


int main()
{
	PhoneBook PhoneBook;
	std::string string;

	while (1)
	{
		std::cout << "Entering: ADD, SEARCH and EXIT. " << std::endl;
		std::getline(std::cin, string);
		size_t found = string.find(' ');
		if (found != std::string::npos)
			std::cout << "Invalid number of arguments." << std::endl;
		else if (string == "ADD")
		{
			PhoneBook.addContact();
			std::cin.ignore();
		}
		else if (string == "SEARCH")
		{
			PhoneBook.searchContact();
			std::cin.ignore();
		}
		else if (string == "EXIT")
			return 1;
		else if (std::cin.eof())
			return 0;
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
	}
	return 0;
}
