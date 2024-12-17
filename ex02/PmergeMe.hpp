/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:31:25 by sbouabid          #+#    #+#             */
/*   Updated: 2024/12/10 17:39:40 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <sstream>
#include <cctype>
#include <deque>
#include <utility>


typedef std::string st;

class	PmergeMe
{
	private:
		int	saver;
		std::vector<st> vecString;
		std::vector<int> vec;
		std::deque<int> deq;

		void mergeVector(std::vector<std::pair<int, int> >& vec, int left, int mid, int right);
		void mergeSortVector(std::vector<std::pair<int, int> >& vec, int left, int right);
	public:
		PmergeMe();
		PmergeMe(char **line);
		// PmergeMe(const PmergeMe &old);
		// PmergeMe&	operator=(const PmergeMe &other);
		// ~PmergeMe();

		void	run();
		void	startParsing();
		void	sortVector();
		// void	sortDeque();


		void	recursivFordJonsonVictor(std::vector<std::pair<int, int> >& vecPair);
		void	mergePairs(std::vector<std::pair<int, int> >& left, std::vector<std::pair<int, int> >& right, std::vector<std::pair<int, int> >& result);

};

#endif