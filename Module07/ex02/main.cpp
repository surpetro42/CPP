#include "Array.hpp"
#include "Array.tpp"

int main()
{
    Array<int> arr(5);

    for (unsigned int i = 0; i < arr.size(); ++i)
        arr[i] = i * 10;

    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    Array<int> copy(arr);
    copy[0] = 999;

    std::cout << "Original: " << arr[0] << std::endl;
    std::cout << "Copy: " << copy[0] << std::endl;

    return 0;
}
