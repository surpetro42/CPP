#include "Harl.hpp"

int	inspect(std::string input)
{
	if(input == "DEBUG")
		return 1;
	if(input == "INFO")
		return 2;
	if(input == "WARNING")
		return 3;
	if(input == "ERROR")
		return 4;
	return 0;
}

int main(int argc, char **argv)
{
	(void)argc;
	int	indx;

	if(argv[1])
	{
		indx = inspect(argv[1]);
		switch (indx)
		{
			case 1:
				debug();
			case 2:
				info();
			case 3:
				warning();
			case 4:
				error();
				break;
			default:
				std::cout << "Error input!" << std::endl;
		}
	}
	else
		std::cout << "Аbsence input!" << std::endl;
	return 0;
}