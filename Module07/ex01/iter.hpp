#pragma once

#include <iostream>

template <typename T>
void print(const T &x)
{
    std::cout << x << std::endl; 
}

template <typename T, typename F>
void iter(T *arr, size_t len, F print)
{
    for (size_t i = 0; i < len; ++i)
        print(arr[i]);
}

template <typename T, typename F>
void iter(const T *arr, size_t len, const F print)
{
    for (size_t i = 0; i < len; ++i)
        print(arr[i]);
}
