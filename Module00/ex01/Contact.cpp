#include "PhoneBook.hpp"

const std::string& Contact::getFirstName() const
{
	return first_name;
}

const std::string& Contact::getLastName() const
{
	return last_name;
}

const std::string& Contact::getNickname() const
{
	return nickname;
}

const std::string& Contact::getPhoneNumber() const
{
	return phone_number;
}

int	Contact::inspect(std::string str, int i) const
{
	if(str[0] == '\0')
		return 0;
	if(i == 0)
	{
		for(int i = 0; str[i]; ++i)
		{
			if(!(std::isalpha(str[i])))
				return 0;
		}
	}
	if(i == 1)
	{
		for(int i = 0; str[i]; ++i)
		{
			if(!(std::isdigit(str[i])))
				return 0;
		}
	}
	return 1;
}

bool Contact::isValidName(const std::string &name, int landmark) const
{
	if (name.empty() && landmark == 1 && std::isdigit(name[0]))
        return false;		
    return true;
}

std::string Contact::initialization_contact_validation(int landmark) const
{
	std::string data;
	std::getline(std::cin, data);
	
	size_t found = data.find(' ');
	if (found == std::string::npos && isValidName(data, landmark))
        return data;
	return "";
}

int	Contact::inspect(std::string str) const
{
	if (str.empty())
		return 0;
	for(size_t i = 0; str[i]; ++i)
	{
		if(!(std::isalpha(str[i])))
			return 0;
	}
	return 1;
}

void Contact::initialization_contact()
{
	std::cout << "Enter first_name" << std::endl;
	while (1)
	{
		first_name = initialization_contact_validation(1);
		if (std::cin.eof())
			exit(1);
		if (inspect(first_name, 0) == 1)
			break ;
		std::cout << "Your input first_name is incorrect, please try again " << std::endl;
	}
	std::cout << "Enter last_name" << std::endl;
	while (1)
	{	
		last_name = initialization_contact_validation(1);
		if (std::cin.eof())
			exit(1);
		if (inspect(last_name, 0) == 1)
			break ;
		std::cout << "Your input last_name is incorrect, please try again " << std::endl;
	}
	std::cout << "Enter nickname" << std::endl;
	while (1)
	{
		nickname = initialization_contact_validation(1);
		if (std::cin.eof())
			exit(1);
		if (inspect(nickname, 0) == 1)
			break ;
		std::cout << "Your input nickname is incorrect, please try again " << std::endl;
	}
	std::cout << "Enter phone_number" << std::endl;
	while (1)
	{		
		phone_number = initialization_contact_validation(2);
		if (std::cin.eof())
			exit(1);
		if (inspect(phone_number, 1) == 1)
			break ;
		std::cout << "Your input phone_number is incorrect, please try again " << std::endl;
	}
	std::cout << "Enter darkestSecret" << std::endl;
	std::cin >> darkestSecret;
	std::cout << std::string(60, '-') << std::endl;
}


void	Contact::print_index() const
{
    if (first_name.empty())
        return;
	std::cout << std::string(60, '-') << std::endl;
    std::cout << "first_name:      " << first_name << std::endl;
    std::cout << "last_name:       " << last_name << std::endl;
    std::cout << "nickname:        " << nickname << std::endl;
    std::cout << "phone_number:    " << phone_number << std::endl;
    std::cout << "darkestSecret:    " << darkestSecret << std::endl;
}

void	Contact::print(int index) const
{
    if (first_name.empty())
        return;
	std::cout << std::string(60, '-') << std::endl;
    std::cout << std::setw(6) << std::right << index
              << std::setw(15) << std::right << (first_name.length() > 10 ? first_name.substr(0, 9) + "." : first_name) << "|"
              << std::setw(15) << std::right << (last_name.length() > 10 ? last_name.substr(0, 9) + "." : last_name) << "|"
              << std::setw(15) << std::right << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << "|"
              << std::endl;
}

