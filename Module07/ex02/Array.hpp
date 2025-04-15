#pragma once

#include <iostream>

template <class T>
class Array
{
    private:
    T *_data;
    unsigned int _size;
    public:
    Array();
    Array(unsigned int n);
    Array(const Array &copy);
    Array& operator=(const Array &copy);
    T& operator[](unsigned int n);
    const T& operator[](unsigned int n) const;
    unsigned int size() const;
    ~Array();
};

#include "Array.tpp"