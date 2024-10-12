/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:51:41 by sbouabid          #+#    #+#             */
/*   Updated: 2024/10/12 15:44:34 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

Pmergeme::Pmergeme()
	: saver(-1)
{
	std::cout << "Constructor Called" << std::endl;
}

void	Pmergeme::fullArr(int ac, char **av)
{
	std::string	value;
	n = ac - 1;
	for (int i = 1 ; i < ac; i++)
	{
		value = av[i];
		arr1.push_back(value);
	}
}

bool	Pmergeme::checkIfValidNumber(std::string nbr)
{
	for (int i = 0; i < nbr.length(); i++)
	{
		if (i == 0 && nbr[i] == '+')
			i++;
		if (std::isdigit(nbr[i]) == 0)
			return false;
	}
	return true;
}

void	Pmergeme::convertToInt()
{
	int newValue;
	for (int i = 0; i < n ; i++)
	{
		std::stringstream ss(arr1[i]);
		ss >> newValue;
		vec.push_back(newValue);
	}
}

void	Pmergeme::mergeInsertVector()
{
	std::vector<std::pair<int, int> > pairVec;
	int x;
	if (n % 2 != 0)
	{
		x = n - 1;
		saver = *(vec.end() - 1);
	}
	else {
		x = n;
	}
	for (int i = 0; i < x ; i+= 2)
	{
		std::pair<int, int> Pair;
		Pair.first = vec[i];
		Pair.second = vec[i+1];
		pairVec.push_back(Pair);
	}
	for (int i = 0; i < x / 2 ; i++)
	{
		if (pairVec[i].first < pairVec[i].second)
			std::swap(pairVec[i].first, pairVec[i].second);
	}
	std::sort(pairVec.begin(), pairVec.end());
	for (int i = 0; i < x / 2 ; i++)
	{
		std::cout << pairVec[i].first << std::endl;
	}
}

void	Pmergeme::startParsing()
{
	for (int i = 0; i < arr1.size(); i++)
	{
		if (!checkIfValidNumber(arr1[i]))
		{
			throw std::runtime_error("invalid argument");
		}
	}
	convertToInt();
	mergeInsertVector();
}
