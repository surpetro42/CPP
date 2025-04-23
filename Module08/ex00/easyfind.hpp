#pragma once

#include <iostream>
#include <algorithm> 
#include <vector>

template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
    typename T::const_iterator elem = std::find(container.begin(), container.end(), value);
    if (elem == container.end())
    {
        throw std::runtime_error("Value not found in container");
    }
    return elem;
}