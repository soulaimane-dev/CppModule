/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:51:44 by sbouabid          #+#    #+#             */
/*   Updated: 2024/10/14 07:59:12 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Pmergeme {
	private:
		std::vector<std::string> arr1;
		std::vector<int> vec;
		int	saver;
		int	n;
		bool	checkIfValidNumber(std::string nbr);
		void	convertToInt();
		void	mergeInsertVector();
		void	FordJohnsonVector(std::vector<std::pair<int, int> > &pairVec);
	public:
		Pmergeme();
		void	fullArr(int ac, char **av);
		void	startParsing();
};


#endif
