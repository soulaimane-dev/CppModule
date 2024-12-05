/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:59:49 by sbouabid          #+#    #+#             */
/*   Updated: 2024/12/05 15:52:15 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN
#define RPN

#include <iostream>
#include <stack>

typedef std::string st;

class	ReversePolishNotation
{
	private:
		st	line;
		std::stack<int> stack;
	public:
		ReversePolishNotation();
		ReversePolishNotation(st line);
		// ~ReversePolishNotation();
		void	rpn();

};


#endif