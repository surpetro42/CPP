#include "ex04.hpp"


#include "ex04.hpp"


#include "ex04.hpp"

int main()
{
    std::string s1, s2, filename;

    std::cout << "Input string s1 -> ";
    std::cin >> s1;
    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty!" << std::endl;
        return 1;
    }

    std::cout << "Input string s2 -> ";
    std::cin >> s2;

    std::cout << "Input filename -> ";
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
        std::cerr << "Error when creating the output file!" << std::endl;
        inputFile.close();
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "The file has been successfully processed and saved as " << filename << ".replace" << std::endl;
    return 0;
}
