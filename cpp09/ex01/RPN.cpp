/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 14:08:35 by sbouabid          #+#    #+#             */
/*   Updated: 2024/10/05 15:40:38 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	ReversePolishNotation(st &str)
{
	int	i = 0;
	int value = 0;
	std::stack<int> arr;
	while (str[i]) {
		if (std::isspace(str[i]))
		{
			i++;
			continue;
		}
		if (std::isdigit(str[i]))
		{
			value = str[i] - '0';
			arr.push(value);
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (arr.size() < 2)
			{
				std::cerr << "Error: Not enough operands." << std::endl;
				return;
			}

			int value1 = arr.top();
			arr.pop();
			int value2 = arr.top();
			arr.pop();

			if (str[i] == '+')
			{
				arr.push(value1 + value2);
			}
			else if (str[i] == '-')
			{
				arr.push(value2 - value1);
			}
			else if (str[i] == '*')
			{
				arr.push(value1 * value2);
			}
			else if (str[i] == '/')
			{
				if (value1 == 0)
				{
					std::cerr << "Error: Division by zero." << std::endl;
					return;
				}
				arr.push(value2 / value1);
			}
		}
		else {
			std::cerr << "Error: You can only enter numbers and operators {+ - * /}." << std::endl;
			return;
		}
		i++;
	}
	if (arr.size() > 1)
	{
		std::cerr << "Error: You must enter another operator."<< std::endl;
		return;
	}
	std::cout << arr.top() << std::endl;
}
