/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:27:28 by sbouabid          #+#    #+#             */
/*   Updated: 2024/10/02 14:40:31 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


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

bool	checkTimeIfValid(st TimeLine)
{
	checkTimeIfValid_st	time;

	time.s_year = TimeLine.substr(0, 4);
	time.s_month = TimeLine.substr(5, 2);
	time.s_day = TimeLine.substr(8, 2);
	if (TimeLine[4] !='-' || TimeLine[7] != '-')
	{
		std::cout << "Error: Time not valid" << std::endl;
		return false;
	}
	if (!(TimeLine[6] >= '0' && TimeLine[6] <= '9') || !(TimeLine[9] >= '0' && TimeLine[9] <= '9') )
	{
		std::cout << "Error: Time not valid" << std::endl;
		return false;
	}
	std::stringstream ss_year(time.s_year);
	std::stringstream ss_month(time.s_month);
	std::stringstream ss_day(time.s_day);
	ss_year >> time.year;
	ss_month >> time.month;
	ss_day >> time.day;
	if (ss_year.fail() || ss_month.fail() || ss_day.fail())
	{
		std::cout << "Error: Time not valid" << std::endl;
		return false;
	}
	if ((time.year < 2009 || time.year > 2022 || time.day > 31 || time.month > 12))
	{
		std::cout << "Error: Time not valid" << std::endl;
		return false;
	}
	if (time.day < 1 || time.month < 1)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	return true;
}

bool	checkValueIfValid(st value, st line)
{
	double caster;
	std::stringstream ss(value);
	if (value[0] != ' ')
	{
		std::cout << "Error: bad input => "<< line << std::endl;
		return false;
	}
	if (value[1] == '-')
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	int i = 1;
	while (value[i])
	{
		if (!(value[i] > '0' && value[i] < '9'))
		{
			if (value[i] == '.' && value[i+1] != '.')
			{
				break;
			}
			else {
				std::cout << "Error: bad input => "<< line << std::endl;
				return false;
			}
		}
		i++;
	}

	ss >> caster;
	if (caster > 2147483647)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	if (caster < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (ss.fail())
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool	parsLine(st line, st& key, st& value)
{
	if (line[11] != '|' || line[10] != ' ')
	{
		std::cout << "Error: bad input => "<< line << std::endl;
		return  false;
	}
	std::size_t pipePos = line.find('|');
	if (pipePos != st::npos) {
		key = line.substr(0, pipePos - 1);
		value = line.substr(pipePos + 1);
		std::stringstream stm(value);
		pipePos = value.find('|');
		if (pipePos != st::npos)
		{
			std::cout << "Error: bad input => "<< line << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "Error: bad input => "<< line << std::endl;
		return false;
	}
	if (!checkTimeIfValid(key))
		return false;
	if (!checkValueIfValid(value, line))
		return false;
	return true;
}

void	findPriceInData(std::map<st, double>& Data, st& key, st& value)
{
	double val;

	std::stringstream ss(value);
	ss >> val;
	std::map<st, double>::iterator it = Data.lower_bound(key);
	if (it->first != key && it != Data.begin())
	{
		it--;
	}
	val *= it->second;
	std::cout << it->first << " =>" << value<< " = " << val << std::endl;
}

void	readDataFromInputFile(std::ifstream& File, std::map<st, double>& Data)
{
	st	line;
	st	key;
	st	value;
	std::getline(File, line);
	if (line != "date | value")
	{
		std::cout << "Error: Input File" << std::endl;
		return;
	}
	while (std::getline(File, line)) {
		if (parsLine(line, key, value))
		{
			findPriceInData(Data, key, value);
		}
	}
}

void	BitcoinExchange(st file)
{
	std::ifstream	File1;
	std::ifstream	File2;
	std::map<st, double> Data;
	File1.open("data.csv");
	if (!File1.is_open())
	{
		std::cout << "Error: could not open data.csv ." << std::endl;
		return ;
	}
	readDataFromFileCSV(File1, Data);
	File1.close();
	File2.open(file);
	if (!File2.is_open())
	{
		std::cout << "Error: could not open " + file + " ." << std::endl;
		return ;
	}
	readDataFromInputFile(File2, Data);
	File2.close();
	return ;
}
