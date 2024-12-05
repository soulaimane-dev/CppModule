/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:59:46 by sbouabid          #+#    #+#             */
/*   Updated: 2024/12/05 15:55:58 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <stdexcept>


ReversePolishNotation::ReversePolishNotation() {}

ReversePolishNotation::ReversePolishNotation(st line)
{
	this->line = line;
}


void	ReversePolishNotation::rpn()
{
	int	i = 0;

	if (line == "")
	{
		throw std::runtime_error("empty argument");
	}

	while (line[i]) {
		if (std::isdigit(line[i]) && std::isdigit(line[i+1]))
		{
			throw std::runtime_error("find more than one number without leaving a space between them");
		}
		i++;
	}
}