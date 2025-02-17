#include "ex04.hpp"


int main()
{
	std::string s1;
	std::string s2;
	std::string stringfile;
	std::string filename;

	std::cout << "inputting string s1 -> ";
	std::cin >> s1;

	std::cout << "inputting string s2 -> ";
	std::cin >> s2;

	std::cout << "inputting filename -> ";
	std::cin >> filename;

	std::ifstream inputFile(filename);
	if (!inputFile)
	{
		std::cerr << "Error when opening the file for reading!" << std::endl;
		return 1;
	}

	std::ofstream outputFile(filename + ".replace");
	if (!outputFile)
	{
		std::cerr << "Error when creating a file for recording!" << std::endl;
		return 1;
	}

    while (std::getline(inputFile, stringfile))
	{
		size_t position = stringfile.find(s1);
		if(position == std::string::npos)
		{
			std::cerr << "The word was not found." << std::endl;
			inputFile.close();
    		outputFile.close();
			return 1;
		}
		s2 = stringfile.substr(0, position) + s2 + stringfile.substr(position + s1.length());
        outputFile << s2 << std::endl;
    }
	inputFile.close();
    outputFile.close();
	std::cout << "The file has been successfully processed and saved as " << filename << ".replace" << std::endl;
	return 0;
}