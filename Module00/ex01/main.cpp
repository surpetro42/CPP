#include "PhoneBook.hh"

int	main()
{
	PhoneBook phonepook[8];
	std::string command;
	int	i = 0;
	
	while (1)
	{
		std::cout << "Entering ADD, SEARCH and EXIT. " << std::endl;
    	std::cin >> command;
		if (input_AddSerchExit(command) == 1)
		{
			initialization_contact(phonepook[i]);
			i++;
			if (i % 8 == 0)
				i = 0;
		}
		else if (input_AddSerchExit(command) == 2)
			search_print_phonebook(phonepook);
		else if (input_AddSerchExit(command) == 3)
			break;
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		std::cout << i << std::endl;
		if (isEOF()) {
			break ;
		}
	}
	return 0;
}