/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:51:41 by sbouabid          #+#    #+#             */
/*   Updated: 2024/10/15 10:33:22 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

Pmergeme::Pmergeme()
	: saver(-1), durationVector(0), durationDeque(0) {}

Pmergeme::~Pmergeme() {}

Pmergeme::Pmergeme(Pmergeme const &other)
{
	*this = other;
}

Pmergeme&	Pmergeme::operator=(const Pmergeme &other)
{
	if (this != &other)
	{
		saver = other.saver;
		durationVector = other.durationVector;
		durationDeque = other.durationDeque;
		start = other.start;
		end = other.end;
		n = other.n;
		vec = other.vec;
		arr1 = other.arr1;
		deq = other.deq;
	}
	return *this;
}
/* start of temp functions */

void	Pmergeme::printAllDetails()
{
	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
		if (i == vec.size() - 1)
			std::cout << std::endl;
	}
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << durationVector << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << durationDeque << " us" << std::endl;
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
	for (size_t i = 0; i < nbr.length(); i++)
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
		deq.push_back(newValue);
	}
}

/*end of temp functions*/

/*start of Ford Johnson Vector*/
void	Pmergeme::FordJohnsonVector(std::vector<std::pair<int, int> > &pairVec)
{
	vec.clear();
	vec.push_back(pairVec[0].second);
	for (size_t i = 0; i < pairVec.size(); i++)
	{
		vec.push_back(pairVec[i].first);
	}
	for (size_t i = 1; i < pairVec.size(); i++)
	{
		std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), pairVec[i].second);
		vec.insert(it, pairVec[i].second);
	}
	if (saver != -1)
	{
		std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), saver);
		vec.insert(it, saver);
	}
	pairVec.clear();
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
	FordJohnsonVector(pairVec);
}
/*end of Ford Johnson Vector*/

/*start of Ford Johnson Deque*/
void	Pmergeme::FordJohnsonDeque(std::deque<std::pair<int, int> > &pairDeq)
{
	deq.clear();
	deq.push_back(pairDeq[0].second);
	for (size_t i = 0; i < pairDeq.size(); i++)
	{
		deq.push_back(pairDeq[i].first);
	}
	for (size_t i = 1; i < pairDeq.size(); i++)
	{
		std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.end(), pairDeq[i].second);
		deq.insert(it, pairDeq[i].second);
	}
	if (saver != -1)
	{
		std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.end(), saver);
		deq.insert(it, saver);
	}
	pairDeq.clear();
}

void	Pmergeme::mergeInsertDeque()
{
	std::deque<std::pair<int, int> > pairDeq;
	int x;
	if (n % 2 != 0)
	{
		x = n - 1;
		saver = *(deq.end() - 1);
	}
	else {
		x = n;
	}
	for (int i = 0; i < x ; i+= 2)
	{
		std::pair<int, int> Pair;
		Pair.first = vec[i];
		Pair.second = vec[i+1];
		pairDeq.push_back(Pair);
	}
	for (int i = 0; i < x / 2 ; i++)
	{
		if (pairDeq[i].first < pairDeq[i].second)
			std::swap(pairDeq[i].first, pairDeq[i].second);
	}
	std::sort(pairDeq.begin(), pairDeq.end());
	FordJohnsonDeque(pairDeq);
}
/*end of Ford Johnson Deque*/

void	Pmergeme::startParsing()
{
	for (size_t i = 0; i < arr1.size(); i++)
	{
		if (!checkIfValidNumber(arr1[i]))
		{
			throw std::runtime_error("invalid argument");
		}
	}
	convertToInt();
	if (vec.size() == 1)
	{
		std::cerr << "You can't sort one number" << std::endl;
		return;
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
		if (i == vec.size() - 1)
			std::cout << std::endl;
	}
	start = std::clock();
	mergeInsertVector();
	end = std::clock();
	durationVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

	start = std::clock();
	mergeInsertDeque();
	end = std::clock();
	durationDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	printAllDetails();
}
