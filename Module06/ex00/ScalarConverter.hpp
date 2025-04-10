#pragma once

#include <cstdlib> 
#include "iostream"

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter & operator=(const ScalarConverter &);
    ~ScalarConverter();

    static void convert(const std::string& literal);
};