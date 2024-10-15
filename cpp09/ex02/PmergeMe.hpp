/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:51:44 by sbouabid          #+#    #+#             */
/*   Updated: 2024/10/15 10:24:55 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <iomanip>

class Pmergeme {
	private:
		std::clock_t start;
		std::clock_t end;
		std::vector<std::string> arr1;
		std::vector<int> vec;
		std::deque<int> deq;
		int	saver;
		int	n;

		double	durationVector;
		double	durationDeque;
		bool	checkIfValidNumber(std::string nbr);
		void	convertToInt();

		void	mergeInsertVector();
		void	FordJohnsonVector(std::vector<std::pair<int, int> > &pairVec);

		void	mergeInsertDeque();
		void	FordJohnsonDeque(std::deque<std::pair<int, int> > &pairDeq);

		void	printAllDetails();
	public:
		Pmergeme();
		~Pmergeme();
		Pmergeme(Pmergeme const &other);
		Pmergeme& operator=(Pmergeme const &other);
		void	fullArr(int ac, char **av);
		void	startParsing();
};


#endif
