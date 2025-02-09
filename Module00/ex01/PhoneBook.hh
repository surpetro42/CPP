#ifndef PHONEBOOK_HH
#define PHONEBOOK_HH

#include <cstddef>
#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook
{
public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
};

bool	isEOF(void);
int		input_AddSerchExit(std::string command);
bool	isValidName(const std::string &name, int landmark);
void	initialization_contact(PhoneBook &phonepook);
void	print(const PhoneBook &PhoneBook);
void	search_print_phonebook(PhoneBook *PhoneBook);

#endif