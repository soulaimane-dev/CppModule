/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:38:40 by sbouabid          #+#    #+#             */
/*   Updated: 2024/07/24 09:30:44 by sbouabid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat(Cat &other)
{
	*this = other;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return  *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}

std::string	Cat::getType() const
{
	return this->type;
}
