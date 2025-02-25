/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:28:46 by surpetro          #+#    #+#             */
/*   Updated: 2025/02/24 13:19:18 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

void	TuUpperCaase(std::string &str)
{
	for(size_t i = 0; i < str.length(); i++)
		str[i] = toupper((str[i]));
}

int main()
{
	std::string str;
	std::cout << "Еnter the text:" << std::endl;
	std::getline(std::cin, str);
	TuUpperCaase(str);
	std::cout << "<< Your text is in capital letters >>" << std::endl;
	std::cout << "\" " << str << " \"" <<  std::endl;
	return 0;
}