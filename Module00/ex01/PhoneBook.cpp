#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contacts_count(0) {}

void	PhoneBook::addContact()
{
	static int index = 0;
	contacts[index % 8].initialization_contact();
	if (_contacts_count < 7)
		_contacts_count++;
	index++;
}

void	PhoneBook::searchContact() const
{
	int index = 0;
    std::cout << std::right << "Index" << "|"
		<< std::setw(15) << std::right << "First Name" << "|"
		<< std::setw(15) << std::right << "Last Name" << "|"
		<< std::setw(15) << std::right << "Nickname"
		<< std::endl;
    for(int i = 0; i <= _contacts_count ; i++)
        contacts[i].print(i);

	std::cout << "Enter the index of the contact you want to search for (0-7): ";
	if (!(std::cin >> index))
	{
		if (std::cin.eof())
			exit(1);
    	std::cout << "Invalid input! Please enter a number." << std::endl;
		std::cin.clear();
		std::cin.ignore();
		return;
	}
   if (index < 0 || index >= 8 || contacts[index].getFirstName().empty())
	{
        std::cout << "Invalid index or empty contact at this index." << std::endl;
        return;
    }
    else
	    contacts[index].print_index();
}