/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:51:36 by sbouabid          #+#    #+#             */
/*   Updated: 2024/10/12 12:14:15 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Error" << std::endl;
	}
	else {
		Pmergeme pm;
		try {
			pm.fullArr(ac, av);
			pm.startParsing();
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
}
