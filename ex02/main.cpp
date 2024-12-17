/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 09:31:17 by sbouabid          #+#    #+#             */
/*   Updated: 2024/12/11 10:36:29 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: the program must take one argument." << std::endl;
		return 1;
	}
	else if (ac ==2)
	{
		std::cerr << "Error: you can sort one number." << std::endl;
		return 1;
	}
	try {
		PmergeMe algo(av);
		algo.run();
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}