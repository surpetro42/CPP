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
	return 0;
}

bool isValidName(const std::string &name, int landmark)
{
	if (landmark == 1 && name.empty() && std::isdigit(name[0]))
        return false;		
    return true;
}

std::string initialization_contact_validation(int landmark)
{
	std::string data;

	std::cin >> data;
	while(1)
	{
		if (isValidName(data, landmark))
			return data;
		else
			return "";
	}
	return "";
}

void initialization_contact(PhoneBook phonepook)
{
	std::cout << "Enter first_name" << std::endl;
	while (1)
	{
		phonepook.first_name = initialization_contact_validation(1);
		if (std::isalpha(phonepook.first_name[0]))
			break ;
		std::cout << "Your input first_name is incorrect, please try again " << std::endl;
	}
	std::cout << "Enter last_name" << std::endl;
	while (1)
	{
		phonepook.last_name = initialization_contact_validation(1);
		if (std::isalpha(phonepook.last_name[0]))
			break ;
		std::cout << "Your input last_name is incorrect, please try again " << std::endl;
	}
	std::cout << "Enter nickname" << std::endl;
	while (1)
	{
		phonepook.nickname = initialization_contact_validation(1);
		if (std::isalpha(phonepook.nickname[0]))
			break ;
		std::cout << "Your input nickname is incorrect, please try again " << std::endl;
	}
	std::cout << "Enter phone_number" << std::endl;
	while (1)
	{
		phonepook.phone_number = initialization_contact_validation(2);
		if (std::isdigit(phonepook.phone_number[0]))
			break ;
		std::cout << "Your input phone_number is incorrect, please try again " << std::endl;
	}
	std::cout << "-------------------------------------------" << std::endl;
}

void search_print_phonebook(PhoneBook *PhoneBook)
{
	int i = 0;

	std::cout << "first_name" << std::string(10, ' ') << "last_name" << std::string(10, ' ');
	std::cout << "nickname" << std::string(10, ' ') << "phone_number" << std::endl;
	std::cout << PhoneBook->first_name[i] << std::string(10, ' ') << PhoneBook->last_name[i] << std::string(10, ' ');
	std::cout << PhoneBook->nickname[i] << std::string(10, ' ') << PhoneBook->phone_number[i] << std::endl;
}

int	main()
{
	PhoneBook phonepook[8];
	std::string command;
	int	i = 0;

	std::cout << "Entering ADD, SEARCH and EXIT. " << std::endl;
	
	while (1)
	{
    	std::cin >> command;
		if (input_AddSerchExit(command) == 1)
			initialization_contact(phonepook[i]);
		else if (input_AddSerchExit(command) == 2)
			search_print_phonebook(phonepook);
		else if (input_AddSerchExit(command) == 3)
			std::cout << "EXXXXXIIIIIIIIIIITTTTTTTTTTTTTT" << std::endl;
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		i++;
		if (i % 8 == 0)
			i = 0;
	}
	return 0;
}