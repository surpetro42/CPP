#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstddef>
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkestSecret;
public:
	const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getNickname() const;
    const std::string& getPhoneNumber() const;

	void		initialization_contact();
	int			inspect(std::string) const;
	bool		isValidName(const std::string &, int) const;
	std::string	initialization_contact_validation(int) const;
	int			inspect(std::string str, int) const;
	void		print_index() const;
	void		print(int) const;
};

class PhoneBook
{
private:
	Contact contacts[8];
	int		_contacts_count;
public:
	PhoneBook ();
	void addContact();
	void searchContact() const; 
};


#endif