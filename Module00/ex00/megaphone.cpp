/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:28:46 by surpetro          #+#    #+#             */
/*   Updated: 2025/01/30 15:28:47 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

void	TuUpperCaase(std::string &str)
{
	for(size_t i = 0; i < str.length(); i++)
		str[i] = toupper(static_cast<unsigned char>(str[i]));
}

int main()
{
	std::string str;
	std::getline(std::cin, str);
	TuUpperCaase(str);
	std::cout << str << std::endl;
	return 0;
}