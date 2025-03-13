#pragma once

#include <iostream>
#include <cctype>
#include <fstream>
#include <regex>
#include <string>


class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	void	complain(const std::string &);
};
