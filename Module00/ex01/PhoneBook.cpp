#include "PhoneBook.hh"
#include <string>

bool isEOF(void)
{
	if (std::cin.eof())
		return (true);
	return (false);
}

int	input_AddSerchExit(std::string command)
{
	if (command == "ADD")
		return 1;
	else if (command == "SEARCH")
		return 2;
	else if (command == "EXIT")
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

int	inspect(std::string str)
{
	for(int i = 0; str[i]; ++i)
	{
		if(!(std::isalpha(str[i])))
			return 0;
	}
	return 1;
}

void initialization_contact(PhoneBook &phonepook)
{
	std::cout << "Enter first_name" << std::endl;
	while (1)
	{
		phonepook.first_name = initialization_contact_validation(1);
		if (inspect(phonepook.first_name) == 1)
			break ;
		std::cout << "Your input first_name is incorrect, please try again " << std::endl;
	}
	std::cout << "Enter last_name" << std::endl;
	while (1)
	{
		phonepook.last_name = initialization_contact_validation(1);
		if (inspect(phonepook.last_name) == 1)
			break ;
		std::cout << "Your input last_name is incorrect, please try again " << std::endl;
	}
	std::cout << "Enter nickname" << std::endl;
	while (1)
	{
		phonepook.nickname = initialization_contact_validation(1);
		if (inspect(phonepook.nickname) == 1)
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

void print(const PhoneBook &PhoneBook)
{
	if (PhoneBook.first_name.empty())
		return;
    std::cout << std::setw(15) << std::left << PhoneBook.first_name
              << std::setw(15) << std::left << PhoneBook.last_name
              << std::setw(15) << std::left << PhoneBook.nickname
              << std::setw(15) << std::left << PhoneBook.phone_number
              << std::endl;
}

void search_print_phonebook(PhoneBook *PhoneBook)
{
	if (PhoneBook->first_name.empty())
	{
		std::cout << "Empty Phonebook " << std::endl;
		return ;
	}
    std::cout << std::setw(15) << std::left << "First Name"
              << std::setw(15) << std::left << "Last Name"
              << std::setw(15) << std::left << "Nickname"
              << std::setw(15) << std::left << "Phone Number"
              << std::endl;

	std::cout << std::string(60, '-') << std::endl;

    for (int i = 0; i < 8; ++i)
        print(PhoneBook[i]);
}

