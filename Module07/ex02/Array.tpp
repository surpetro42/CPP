#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &copy) : _data(new T[copy._size]), _size(copy._size)
{
    for(unsigned int i = 0; i < _size; ++i)
        _data[i] = copy._data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &copy)
{
    if(this != &copy)
    {
        delete[] _data;
        _size = copy._size;
        _data = new T[_size];
        for(unsigned int i = 0; i < _size; ++i)
            _data[i] = copy._data[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
    if(n >= _size)
        throw std::out_of_range("Index out of bounds");
    return _data[n];
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const
{
    if(n >= _size)
        throw std::out_of_range("Index out of bounds");
    return _data[n];
}

template <typename T>
unsigned int Array<T>::size() const {return _size;}

template <typename T>
Array<T>::~Array() {delete[] _data;}
