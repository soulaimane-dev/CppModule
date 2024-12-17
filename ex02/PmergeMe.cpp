/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:31:23 by sbouabid          #+#    #+#             */
/*   Updated: 2024/12/11 10:53:00 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **line)
{
	saver = -1;
	int i = 1;

	while (line[i]) {
		st str = line[i];
		vecString.push_back(str);
		i++;
	}
}

void	PmergeMe::run()
{
	startParsing();
	sortVector();
}

void	PmergeMe::startParsing()
{
	std::vector<st>::iterator it = vecString.begin();
	while (it != vecString.end()) {
		int i = 0;
		st str = *it;
		while (str[i]) {
			if (std::isdigit(str[i]))
				i++;
			else
				throw std::runtime_error("The program should take numbers, not strings.");
		}
		it++;
	}
	it = vecString.begin();
	while (it != vecString.end()) {
		int caster;
		std::stringstream ss(*it);
		ss >> caster;
		if (ss.fail())
		{
			throw std::runtime_error("Enter a number in the range of integer");
		}
		vec.push_back(caster);
		deq.push_back(caster);
		it++;
	}
}



