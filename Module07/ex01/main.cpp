#include "iter.hpp"

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    ::iter(arr, sizeof(arr) / sizeof(arr[0]), print<int>);
    return (0);
}   