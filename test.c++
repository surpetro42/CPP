#include <iostream>
#include <string>

class PhoneBook
{
public:
    std::string index;
    std::string name;
    std::string last_name;
    std::string nickname;

    void Print_data();
};

void PhoneBook::Print_data()
{
    std::cout << index << std::string(10, ' ') << name << std::string(10, ' ');
    std::cout << last_name << std::string(10, ' ') << nickname << std::endl;
}

int inspect(const PhoneBook &Contact)
{
    int count = 0;
    if (!Contact.index.empty() && std::isdigit(Contact.index[0]))
        count++;
    if (!Contact.name.empty() && std::none_of(Contact.name.begin(), Contact.name.end(), ::isdigit))
        count++;
    if (!Contact.last_name.empty() && std::none_of(Contact.last_name.begin(), Contact.last_name.end(), ::isdigit))
        count++;
    if (!Contact.nickname.empty() && std::none_of(Contact.nickname.begin(), Contact.nickname.end(), ::isdigit))
        count++;
    
    return (count == 4) ? 1 : 0;
}

int main()
{
    const int size = 8;
    PhoneBook Contacts[size];

    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter data for contact " << i + 1 << ":" << std::endl;
        std::cout << "Enter index: ";
        std::getline(std::cin, Contacts[i].index);
        std::cout << "Enter first name: ";
        std::getline(std::cin, Contacts[i].name);
        std::cout << "Enter last name: ";
        std::getline(std::cin, Contacts[i].last_name);
        std::cout << "Enter nickname: ";
        std::getline(std::cin, Contacts[i].nickname);
        
        if (inspect(Contacts[i]) == 0)
        {
            std::cout << "ERROR input" << std::endl;
            i--;
        }
    }
    std::cout << "\nPhoneBook Data:\n";
    for (int i = 0; i < size; i++)
        Contacts[i].Print_data();
    return 0;
}
