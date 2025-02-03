#include <cstddef>
#include <iostream>
#include <string>

class PhoneBook
{
public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
};

int	input_AddSerchExit(std::string command)
{
	if (command == "ADD")
		return 1;
	else if (command == "SEARCH")
		return 2;
	else if (command == "SEARCH")
		return 3;
	else
	{
		std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		return 0;
	}
}

bool isValidName(const std::string &name)
{
	if (name.empty() && std::isdigit(name[0]))
            return false;
    return true;
}

std::string initialization_contact_validation(int landmark)
{
	std::string data;

	std::cin >> data;
	while(1)
	{
		if (landmark == 1 && isValidName(data))
			return data;
		else if(landmark == 2 && !isValidName(data))
			return data;
		else
			return "";
	}
	return "";
}

void initialization_contact(PhoneBook *phonepook)
{
	std::cout << "Enter first_name" << std::endl;
	while (1)
	{
		phonepook->first_name = initialization_contact_validation(1);
		if (phonepook->first_name != "" || !std::isdigit(phonepook->first_name[0]))
			break ;
	}
	std::cout << "Enter last_name" << std::endl;
	phonepook->last_name = initialization_contact_validation(1);
	std::cout << "Enter nickname" << std::endl;
	phonepook->nickname = initialization_contact_validation(1);
	std::cout << "Enter phone_number" << std::endl;
	phonepook->phone_number = initialization_contact_validation(2);
}

int	main()
{
	PhoneBook phonepook[8];
	std::string command;

	std::cout << "Entering ADD, SEARCH and EXIT. " << std::endl;
    std::cin >> command;
	
	while (1)
	{
		if (input_AddSerchExit(command) == 1)
			initialization_contact(phonepook);
		else
			break;
	}
	return 0;
}