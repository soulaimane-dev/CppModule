/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:27:28 by sbouabid          #+#    #+#             */
/*   Updated: 2024/10/01 16:22:28 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>
#include <sstream>
#include <string>

void	readDataFromFileCSV(std::ifstream& File, std::map<st, double>& Data)
{
	st	key;
	st	value;
	st	line;
	double	caster;

	std::getline(File, line);
	while (std::getline(File, line))
	{
		std::size_t commaPos = line.find(',');
		if (commaPos != st::npos) {
			key = line.substr(0, commaPos);
			value = line.substr(commaPos + 1);
			std::stringstream stm(value);
			stm >> caster;
			Data.insert(std::make_pair(key, caster));
		}
	}
}

void	readDataFromInputFile(std::ifstream& File, std::map<st, double>& Data)
{
	st	key;
	st	value;
}

bool	BitcoinExchange(st file)
{
	std::ifstream	File1;
	std::ifstream	File2;
	std::map<st, double> Data;
	File1.open("data.csv");
	if (!File1.is_open())
	{
		std::cout << "Error: could not open data.csv ." << std::endl;
		return false;
	}
	readDataFromFileCSV(File1, Data);
	File1.close();
	File2.open(file);
	if (!File2.is_open())
	{
		std::cout << "Error: could not open " + file + " ." << std::endl;
		return false;
	}
	readDataFromInputFile(File2, Data);
	File2.close();
	return true;
}
