#include "easyfind.hpp"

int main()
{
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    try {
        std::vector<int>::const_iterator elem = easyfind(v, 20);
        std::cout << "Found: " << elem[0] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::const_iterator elem = easyfind(v, 1);
        std::cout << "Found: " << elem[0] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}